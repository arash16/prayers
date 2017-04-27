#include <math.h>
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <sstream>
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

			if (cells) delete [] cells;
			cells = ncells;
		}
		if (!cp)
			 memset(cells, 0, capacity*CellSize);
		else memset(cells+size, 0, (capacity-size)*CellSize);
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
		if (sign != o.sign) {
			o.sign *= -1;
			operator-=(o);
			o.sign *= -1;
			return *this;
		}

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
	BigInt& operator+= (int x) { return *this += *new BigInt(x); } //TODO: optimize
	BigInt operator+ (int x) const { return *new BigInt(*this) += x; }
	BigInt operator+ (BigInt& o) const { return *new BigInt(*this) += o; }

	// ---------------------------------------------------------------------
	
	BigInt& operator-= (BigInt& o) {
		if (!o.sign) return *this;
		if (!sign) sign = -o.sign;
		if (sign != o.sign) {
			o.sign *= -1;
			operator+=(o);
			o.sign *= -1;
			return *this;
		}

		if (*this == o) {
			sign = size = 0;
			return *this;
		}
		if (!o.numLess(*this))
			return *this = -(o - *this);

		for (int i=0; i<size; i++) {
			if (i < o.size)
				cells[i] -= o.cells[i];
			if (cells[i] < 0) {
				cells[i] += MAX_C;
				--cells[i+1];
			}
		}
		return autoSize();
	}
	BigInt& operator-= (int x) { return *this -= *new BigInt(x); }
	BigInt operator- (int x) const { return *new BigInt(*this) -= x; }
	BigInt operator- (BigInt& o) const { return *new BigInt(*this) -= o; }
	BigInt operator-() { BigInt tmp(*this); tmp.sign *= -1; return tmp; }

	// ---------------------------------------------------------------------

	BigInt& operator*= (int x) {
		sign *= sgn(x);
		if (!sign) {
			size = 0;
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

		BigInt r;
		r.setSize(size + o.size + 1, 0);
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
	
	BigInt& operator/= (int den) { 
		int t = 0;
		for (int i=size-1; i>=0; --i) {
			t = t*MAX_C + cells[i];
			cells[i] = t / den;
			t -= cells[i] * den;
		}
		return autoSize();
	}
	BigInt operator/ (int den) const { return *new BigInt(*this) *= den; }
	
	int operator% (int den) const {
		int r = 0;
		for (int i = size-1; i>=0; --i)
			r = (r * MAX_C + cells[i]) % den;
		return r;
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
BigInt operator*(int m, BigInt &n) { return n * m; }
BigInt operator+(int m, BigInt &n) { return n + m; }
BigInt operator-(int m, BigInt &n) { return -n + m; }

// tostring, input from char

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

BigInt pow(int a, BigInt b) {
	if (b.getSize() <= 1) 
		return pow(a, b.getCell(0));

	bool has2 = b % 2;
	b /= 2;
	BigInt c = pow(a, b);
	c *= c;
	if (b%2) c*= a;

	return c;
}


BigInt DP[2001];
int main(){
	BigInt c(1);
	for (int i=1; i<2001; i++) {
		DP[i] = DP[i-1];
		DP[i] += c;
		c += DP[i];
	}
	
	int n;
	while (scanf("%d", &n)==1 && n)
		cout << DP[n] << endl;
}
