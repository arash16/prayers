#include <stdio.h>
#include <iostream>
using namespace std;

template<class Int>
struct Triple {
    Int d, x, y;
    Triple(Int q, Int w, Int e) : d(q), x(w), y(e) {}
};

template<class Int>
Int mod(Int x, Int y) {
    return ((x%y)+y)%y;
}

template<class Int>
Triple<Int> egcd(Int a, Int b) {
    if (!b) return Triple<Int>(a, 1, 0);
    Triple<Int> q = egcd(b, mod(a, b));
    return Triple<Int>(q.d, q.y, q.x - a/b * q.y);
}


int main(){
    long long int a, b;
    while (cin>>a>>b) {
        auto res = egcd(a, b);
        printf("%lld %lld %lld\n", res.x, res.y, res.d);
    }
}
