/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 230
  Name: Borrowers
  Problem: https://onlinejudge.org/external/2/230.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int n;
struct Book {
    string title, author;
    bool operator < (const Book &o) const {
        return author != o.author
            ? author < o.author
            : title < o.title;
    }
} books[10043];
bool inlib[10043], intab[10043];

void readTitle(string &s) {
    cin.ignore(1, '"');
    getline(cin, s, '"');
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (n=0; cin.peek()=='"'; ++n) {
        readTitle(books[n].title);
        cin.ignore(10, ' '); cin.ignore(10, ' ');
        getline(cin, books[n].author);
        inlib[n] = 1;
    }
    cin.ignore(100, '\n');
    sort(books, books+n);

    unordered_map<string, int> ids;
    for (int i=0; i<n; ++i)
        ids[books[i].title] = i;

    string cm, title;
    while (cin >> cm && cm!="END") {
        if (cm == "SHELVE") {
            for (int i=0, j; i<n; ++i)
                if (intab[i]) {
                    cout << "Put \"" << books[i].title;
                    for (j=i-1; j>=0 && !inlib[j]; --j);
                    if (j < 0)
                        cout << "\" first\n";
                    else
                        cout << "\" after \"" << books[j].title << "\"\n";

                    intab[i] = 0;
                    inlib[i] = 1;
                }
            cout << "END\n";
        }
        else {
            readTitle(title);
            int id = ids[title];
            intab[id] = cm == "RETURN";
            inlib[id] = 0;
        }
    }
}
