#include <math.h>
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
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

	void init() {
		sign = size = 0;
		cells = new CellType[capacity = 100];
		memset(cells, 0, 4*CellSize);
	}

	int setSize(int sz, bool cp = true) {
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
		init();
		sign = o.sign;
		setSize(o.size, 0);
		for (int i=0; i<size; i++)
			cells[i] = o.cells[i];
	}

	~BigInt() {
		if (capacity >= 0)
			delete [] cells;
	}

	public:
	void setZero() {
		sign = size = cells[0] = 0;
	}
	void setOne() {
		sign = size = cells[0] = 1;
	}
	bool isZero() {
		return sign==0;
	}
	
	BigInt& operator=(const BigInt &o) {
		sign = o.sign;
		size = o.size;
		for (int i=0; i<size; i++)
			cells[i] = o.cells[i];
		return *this;
	}

	BigInt& operator+= (BigInt o) {
		if (!o.sign) return *this;
		if (!sign) sign = o.sign;

		for (int i=size; i<o.size+1; i++)
			cells[i] = 0;

		setSize(max(size, o.size)+1);
		for (int i=0; i<o.size; i++)
			if ( (cells[i] += o.cells[i]) >= MAX_C ) {
				cells[i] -= MAX_C;
				cells[i+1]++;
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


char s1[10016], s2[117];
BigInt DP[10017][103];
int main(){
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s%s", s1, s2);
		int l1=strlen(s1), l2=strlen(s2);

		if (l1 < l2) puts("0");
		else {
			for (int i=0; i<l1; i++) {
				DP[i][0].setOne();
				for (int j=0; j<l2; j++) {
					DP[i+1][j+1] = DP[i][j+1];
					if (s1[i] == s2[j])
						DP[i+1][j+1] += DP[i][j];
				}
			}

			cout << DP[l1][l2] << endl;
		}
	}
}
