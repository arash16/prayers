/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10483
  Name: The Sum Equals the Product
  Problem: https://onlinejudge.org/external/104/10483.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

bool Sa[26001], Sb[26001];
void _printABs() {
    int dm = 10000;
    for (int a=1; a+a+a<=25600; ++a)
        for (int b=a; a+b+b<=25600; ++b) if (a*b != dm) {
            int c = (a+b)*dm / (a*b-dm),
                s = a+b+c;

            if (c>=b && s<=25600 && s*dm==a*b*c)
                Sa[a] = Sb[b] = 1;
        }

    cout << "int AA[] = { ";
    for (int i=0; i<=25600; ++i)
        if (Sa[i]) cout << i << ", ";
    cout << "\n};\nint BB[] = { ";
    for (int i=0; i<=25600; ++i)
        if (Sb[i]) cout << i << ", ";
    cout << "\n};";
}

int AA[] = {
    2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
    24, 25, 26, 28, 29, 30, 32, 33, 34, 35, 36, 40, 41, 42, 43, 44, 45, 46, 48,
    50, 51, 52, 54, 55, 56, 58, 59, 60, 63, 65, 66, 68, 69, 70, 71, 72, 74, 75,
    76, 80, 81, 82, 84, 85, 88, 90, 91, 94, 96, 98, 100, 105, 107, 110, 120, 121,
    125, 136, 140, 150
};
int BB[] = {
    101, 102, 104, 105, 108, 110, 111, 116, 120, 121, 124, 125, 130, 132, 135,
    136, 138, 140, 144, 145, 147, 150, 156, 160, 162, 166, 170, 172, 175, 176,
    178, 180, 185, 195, 200, 204, 205, 208, 210, 212, 216, 220, 225, 228, 240,
    246, 250, 254, 255, 260, 270, 275, 279, 280, 288, 300, 304, 308, 317, 319,
    325, 339, 340, 345, 348, 350, 360, 366, 375, 380, 395, 400, 406, 408, 410,
    414, 416, 417, 420, 425, 434, 436, 440, 445, 450, 468, 475, 480, 485, 500,
    513, 515, 516, 520, 525, 526, 532, 536, 540, 550, 552, 565, 570, 580, 600,
    604, 605, 620, 624, 625, 630, 637, 650, 660, 672, 700, 708, 740, 750, 760,
    800, 803, 825, 875, 900, 916, 939, 975, 1000, 1036, 1050, 1080, 1100, 1101,
    1120, 1125, 1177, 1200, 1202, 1212, 1250, 1256, 1300, 1324, 1335, 1350, 1375,
    1398, 1400, 1404, 1420, 1435, 1500, 1505, 1539, 1590, 1620, 1625, 1675, 1750,
    1770, 1800, 1808, 1840, 1875, 1879, 1924, 1990, 2000, 2100, 2175, 2200, 2250,
    2310, 2312, 2400, 2401, 2500, 2503, 2625, 2696, 2750, 2802, 2900, 3000, 3125,
    3126, 3250, 3275, 3300, 3500, 3604, 3750, 3752, 4000, 4065, 4500, 5000, 7000,
    7050, 7440, 7500, 7501, 8050, 8280, 9100, 9880, 10000, 2813, 202, 112
};

struct Triplet {
    int a, b, c;
    int sum() const { return a+b+c; }
    bool operator < (const Triplet &o) const {
        int s1 = sum(), s2 = o.sum();
        if (s1 != s2) return s1 < s2;
        if (a != o.a) return a < o.a;
        if (b != o.b) return b < o.b;
        return c < o.c;
    }
} TR[360];
int TRn;

void generateAll() {
    int dm = 10000;
    for (int i=(sizeof(AA)>>2)-1; i>=0; --i) {
        int a = AA[i];
        for (int j=(sizeof(BB)>>2)-1; j>=0; --j) {
            int b = BB[j];
            if (b>=a && a*b != dm) {
                int c = (a+b)*dm / (a*b-dm),
                    s = a+b+c;

                if (c>=b && s<=25600 && s*dm==a*b*c) {
                    TR[TRn].a = a;
                    TR[TRn].b = b;
                    TR[TRn].c = c;
                    ++TRn;
                }
            }
        }
    }
    sort(TR, TR+TRn);
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    generateAll();
    int la, lb, ra, rb;
    char ch;
    while (cin >> la>>ch>>lb >> ra>>ch>>rb) {
        int l = la*100+lb,
            r = ra*100+rb;

        for (int i=0; i<TRn; ++i) {
            int s = TR[i].sum();
            if (s>=l && s<=r)
            printf("%.02f = %.02f + %.02f + %.02f = %.02f * %.02f * %.02f\n",
                (TR[i].a+TR[i].b+TR[i].c)/100.0,
                TR[i].a/100.0,
                TR[i].b/100.0,
                TR[i].c/100.0,
                TR[i].a/100.0,
                TR[i].b/100.0,
                TR[i].c/100.0
            );
        }
    }
}
