/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10669
  Name: Three powers
  Problem: https://onlinejudge.org/external/106/10669.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

class BigInt {
    typedef int CellType;
    const static int CellSize = sizeof(CellType);
    const static int MAX_C = 10000;
    const static int MAX_D = 4;

    int capacity, size, sign;
    CellType *cells;

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
            else size = 0;

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
    // ---------------------------------------------------------------------
    BigInt& operator=(const BigInt& o) {
        if ((sign = o.sign)) {
            setSize(o.size, 0);
            memcpy(cells, o.cells, o.size*CellSize);
        }
        else size=0;
        return *this;
    }
    // ---------------------------------------------------------------------

    BigInt& operator*= (int x) {
        sign *= sgn(x);
        if (!sign) {
            size=sign=0;
            return *this;
        }
        if (x<0) x = -x;

        int cr = 0;
        for (int i=0; i < size; i++) {
            cells[i] = cells[i] * x + cr;
            cr = cells[i] / MAX_C;
            cells[i] %= MAX_C;
        }

        if (cr) {
            int ex = (countDigits(cr)+MAX_D-1)/MAX_D, sz=size;
            setSize(size + ex);
            size = sz;
            for (; cr; cr /= MAX_C)
                cells[size++] = cr % MAX_C;
        }

        return autoSize();
    }
    BigInt operator* (const BigInt &o) const {
        if (sign*o.sign == 0)
            return *new BigInt(0);
        if (o.size == 1)
            return *new BigInt(*this) *= o.cells[0];
        if (size == 1)
            return *new BigInt(o) *= cells[0];

        BigInt r(*this);
        r.setSize(r.size + o.size + 1, 0);
        for (int i=0; i<size; i++)
            for (int j=0; j<o.size; j++) {
                r.cells[i+j] += cells[i]*o.cells[j];
                r.cells[i+j+1] += r.cells[i+j] / MAX_C;
                r.cells[i+j] %= MAX_C;
            }
        return r.autoSize();
    }
    BigInt& operator*= (const BigInt &o) {
        if (!(sign *= o.sign)) {
            size = 0;
            return *this;
        }
        if (o.size == 1)
            return *this *= o.cells[0];
        return *this = *this * o;
    }

    BigInt operator* (int x) const { return *new BigInt(*this) *= x; }

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


bool powseen[10][10000];
BigInt pmemo[10][10000];
BigInt pow(int a, int b) {
    if (!b) return BigInt(1);
    if (b==1 || a<=1)
        return BigInt(a);

    if (a<10 && b<10000 && powseen[a][b])
        return pmemo[a][b];

    BigInt c = pow(a, b>>1);
    c *= c;
    if (b&1) c *= a;

    if (a<10 && b<10000) {
        powseen[a][b] = 1;
        pmemo[a][b] = c;
    }
    return c;
}


int main(){
    unsigned long long n;
    while (scanf("%llu", &n)==1 && n) {
        if (--n == 0)
            puts("{ }");
        else {
            printf("{ ");
            bool frst = 1;
            for (int i=0; n; i++, n>>=1)
                if (n & 1) {
                    if (frst) frst = 0;
                    else printf(", ");
                    cout << pow(3, i);
                }
            printf(" }\n");
        }
    }
}
