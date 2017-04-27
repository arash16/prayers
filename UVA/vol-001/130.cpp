#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;

#define Iter list<int>::iterator

list<int> q;
void advance(Iter &it) {
    it++;
    if (it == q.end())
        it = q.begin();
}


int main(){
    int n, k;
    while (cin>>n>>k && (n||k)) {
        if (n==1) puts("1");
        else {
            q.clear();
            for (int i=0; i<n; i++)
                q.push_back(i);

            Iter it = q.end(); it--;
            while (q.size()>1) {
                for (int i=0; i<k; i++)
                    advance(it);

                Iter dest = it;
                for (int i=0; i<k; i++) {
                    advance(dest);
                    if (dest == it)
                        advance(dest);
                }

                *it = *dest;
                q.erase(dest);
            }

            cout << (n-(*q.begin()))%n + 1 << endl;
        }
    }
}
