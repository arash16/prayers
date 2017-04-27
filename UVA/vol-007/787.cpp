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
            else size = 0;
            memset(ncells+size, 0, (capacity-size)*CellSize);

            if (cells) delete [] cells;
            cells = ncells;
        }
        return size = sz;
    }

    BigInt& autoSize() {
        while (size>0 && !cells[size-1])
            size--;
        if (!size) sign=0;
        return *this;
    }

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


    private:
    bool numLess(const BigInt &o) const {
        if (size != o.size)
            return size < o.size;
        for (int i=size-1; i>=0; i--)
            if (cells[i] != o.cells[i])
                return cells[i] < o.cells[i];
        return false;
    }

    public:
    bool operator <  (const BigInt &o) const {
        return sign==o.sign ? (sign>0 ? numLess(o) : o.numLess(*this)) : sign < o.sign;
    }
    bool operator >  (const BigInt &o) const { return  (o  < *this); }



    BigInt& operator=(const BigInt& o) {
        if ((sign = o.sign)) {
            setSize(o.size, 0);
            memcpy(cells, o.cells, o.size*CellSize);
        }
        else size=0;
        return *this;
    }

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



int main(){
    int n, X[200];
    while (cin>>X[0]) {
        int imxm=X[0];
        for (n=1; cin>>X[n] && X[n]!=-999999; n++)
            imxm = max(imxm, X[n]);

        BigInt mxm(imxm);
        for (int i=0; i<n; i++)
            if (X[i]) {
                int s=i, ncc=0, fn=-1, ln=-1;
                for (; i<n && X[i]; i++)
                    if (X[i] < 0) {
                        ncc++;
                        ln = i;
                        if (fn == -1)
                            fn = i;
                    }

                if (ncc&1) {
                    BigInt m1(X[s]);
                    for (int j=s+1; j<ln; j++)
                        m1 *= X[j];

                    if (m1 > mxm)
                        mxm = m1;

                    BigInt m2(X[fn+1]);
                    for (int j=fn+2; j<i; j++)
                        m2 *= X[j];

                    if (m2 > mxm)
                        mxm = m2;
                }
                else {
                    BigInt m(X[s]);
                    for (int j=s+1; j<i; j++)
                        m *= X[j];

                    if (m > mxm)
                        mxm = m;
                }
            }

        cout << mxm << endl;
    }
}
