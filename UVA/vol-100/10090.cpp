/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10090
  Name: Marbles
  Problem: https://onlinejudge.org/external/100/10090.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


struct Triple {
    long long d, x, y;
    Triple( long long q, long long w, long long e ) : d( q ), x( w ), y( e ) {}
};

Triple egcd( long long a, long long b ) {
    if( !b ) return Triple( a, 1, 0 );
    Triple q = egcd( b, a % b );
    return Triple( q.d, q.y, q.x - a / b * q.y );
}

Triple ldioph( long long a, long long b, long long c ) {
    Triple t = egcd( a, b );
    if( c % t.d ) return Triple( 0, 0, 0 );
    t.x *= c / t.d;
    t.y *= c / t.d;
    return t;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    long long n, a, b, c, d;
    while (cin >> n && n>0) {
        cin >> c >> a >> d >> b;
        Triple t = ldioph(a, b, n);
        if (!t.d) cout << "failed\n";
        else {
            long long
                lo = ceil(-double(t.x*t.d) / b),
                x1 = t.x + lo * b / t.d,
                y1 = t.y - lo * a / t.d,

                hi = floor(double(t.y*t.d) / a),
                x2 = t.x + hi * b / t.d,
                y2 = t.y - hi * a / t.d;

            if (lo > hi)
                cout << "failed\n";
            else if (x1*c + y1*d < x2*c + y2*d)
                cout << x1 << ' ' << y1 << '\n';
            else
                cout << x2 << ' ' << y2 << '\n';
        }
    }
}
