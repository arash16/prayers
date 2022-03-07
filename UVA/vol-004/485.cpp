/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 485
  Name: Pascal's Triangle of Death
  Problem: https://onlinejudge.org/external/4/485.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

class BigInt {
    typedef int CellType;
    const static int CellSize = sizeof(CellType);
    const static int MAX_C = 10000;
    const static int MAX_D = 4;
    CellType *cells;
    int capacity, size, sign;

    int sgn(int x) {
        return x<0 ? -1 : x>0 ? 1 : 0;
    }

    int countDigits(int x) {
        if (!x) return 0;
        if (x < 0) x = -x;
        return floor(log10(x)) + 1;
    }

    void init() {
        sign = size = 0;
        cells = new CellType[capacity = 4];
        memset(cells, 0, 4*CellSize);
    }

    int setSize(int sz, bool cp = true) {
        if (sz > capacity) {
            CellType* ncells = new CellType[capacity = sz + 16];
            if (cp && size)
                memcpy(ncells, cells, size*CellSize);

            if (cells) delete [] cells;
            cells = ncells;
        }
        if (!cp)
             memset(cells, 0, capacity*CellSize);
        else memset(cells+sz, 0, (capacity-sz)*CellSize);
        return size = sz;
    }

    BigInt& autoSize() {
        while (size>0 && !cells[size-1])
            size--;
        if (!size) sign=0;
        return *this;
    }

    // ---------------------------------------------------------------------

    public:
    BigInt() { init(); }
    BigInt(int x) {
        init();
        sign = sgn(x); x*=sign;
        for (size=0; x; size++) {
            cells[size] = x % MAX_C;
            x /= MAX_C;
        }
    }

    BigInt(const char s[]) {
        while (s[0]==' ' || s[0]=='\n' || s[0]=='\t') s++;
        sign = 1;
        if (s[0] == '+') s++;
        if (s[0] == '-') { sign=-1; s++; }
        while (s[0]=='0') s++;
        if (!s[0]) { init(); return; }

        int len = strlen(s);
        size = (len+3)/MAX_D;
        cells = new CellType[capacity = size+16];
        for (int i=len-1; i>=0; i-=MAX_D) {
            int rc = 0;
            for (int k=i-MAX_D+1; k<=i; k++) {
                if (k<0 || s[k]=='-' || s[k]=='+') continue;
                rc = rc*10 + s[k] - '0';
            }
            cells[(len-i-1) / MAX_D] = rc;
        }
        for (int i=size; i<capacity; i++) cells[i] = 0;
        autoSize();
    }

    BigInt(const BigInt& o): cells(0), capacity(0) {
        sign = o.sign;
        setSize(o.size, 0);
        for (int i=0; i<size; i++)
            cells[i] = o.cells[i];
    }

    ~BigInt() {
        if (capacity >= 0)
            delete [] cells;
    }

    int getSize() { return size; }
    int getCell(int i) { return cells[i]; }
    bool isZero() { return !sign; }
    BigInt& setOne() { sign=size=cells[0]=1; return *this; }
    // ---------------------------------------------------------------------
    private:
    bool numLess(const BigInt &o) const {
        if (size != o.size)
            return size < o.size;
        for (int i=size-1; i>=0; i--)
            if (cells[i] != o.cells[i])
                return cells[i] < o.cells[i];
        return false;
    }
    bool numEq(const BigInt &o) const {
        if (size!=o.size)
            return false;
        for (int i=size-1; i>=0; i--)
            if (cells[i] != o.cells[i])
                return false;
        return true;
    }

    public:
    bool operator <  (const BigInt &o) const {
        return sign==o.sign ? (sign>0 ? numLess(o) : o.numLess(*this)) : sign < o.sign;
    }
    bool operator == (const BigInt &o) const { return sign==o.sign && numEq(o); }
    bool operator != (const BigInt &o) const { return !(*this == o); }
    bool operator <= (const BigInt &o) const { return !(o  < *this); }
    bool operator >  (const BigInt &o) const { return  (o  < *this); }
    bool operator >= (const BigInt &o) const { return !(*this <  o); }
    // ---------------------------------------------------------------------
    BigInt& operator=(const BigInt& o) {
        if ((sign = o.sign)) {
            setSize(o.size, 0);
            memcpy(cells, o.cells, o.size*CellSize);
        }
        else size=0;
        return *this;
    }

    BigInt& operator+= (BigInt o) {
        if (!o.sign) return *this;
        if (!sign) sign = o.sign;

        int osz = size;
        setSize(max(size, o.size)+1);
        for (int i=osz; i<o.size+1; i++)
            cells[i] = 0;

        for (int i=0; i<size; i++) {
            if (i < o.size)
                cells[i] += o.cells[i];
            if (cells[i] >= MAX_C) {
                cells[i] -= MAX_C;
                ++cells[i+1];
            }
        }
        return autoSize();
    }
    // ---------------------------------------------------------------------
    friend std::ostream& operator<< (std::ostream& stream, const BigInt& bs) {
        if (!bs.sign)
            stream << 0;
        else {
            if (bs.sign < 0) stream << '-';
            stream << bs.cells[bs.size-1];
            for (int i=bs.size-2; i>=0; i--)
                stream << setfill('0') << setw(MAX_D) << bs.cells[i];
        }
        return stream;
    }
};


char BUF[1000000];
int main() {
    cout.rdbuf()->pubsetbuf(BUF, 1000000);
    ios_base::sync_with_stdio(0);cin.tie(0);


    BigInt DP[300];
    for (int i=0; i<300; ++i) {
        cout << 1;
        DP[i].setOne();
        for (int j=i-1; j>0; --j) {
            DP[j] += DP[j-1];
            cout << ' ' << DP[j];

            if (DP[j].getSize() >= 16) i=300;
        }
        if (i) cout << " 1\n";
        else cout << '\n';
    }
}
