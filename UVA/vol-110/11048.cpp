/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11048
  Name: Automatic Correction of Misspellings
  Problem: https://onlinejudge.org/external/110/11048.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

#define NAN 1073741824

struct Node {
    int id;
    Node* childs[26];
    Node(): id(NAN) {
        memset(childs, 0, sizeof(childs));
    }
    ~Node() {
        for (int i=0; i<26; i++)
            if (childs[i])
                delete childs[i];
    }
};

Node* root;
int insertWord(const char str[], int nid) {
    Node *cur = root;
    for (int i=0; str[i]; i++) {
        int ch = str[i]-'a';
        if (!cur->childs[ch])
            cur->childs[ch] = new Node();
        cur = cur->childs[ch];
    }
    if (cur->id == NAN)
        cur->id = nid;

    return cur->id;
}

int findWord(const char str[], Node *cur=root) {
    if (!cur) return NAN;
    for (int i=0; str[i]; i++) {
        cur = cur->childs[str[i]-'a'];
        if (!cur) return NAN;
    }
    return cur->id;
}

int findFuzzy(const char str[]) {
    int bid = NAN;
    Node *cur = root;
    for (int i=0; cur; i++) {
        // missing
        for (int j=0; j<26; j++)
            bid = min(bid, findWord(str+i, cur->childs[j]));

        if (!str[i]) break;

        // too much
        bid = min(bid, findWord(str+i+1, cur));

        // letter is wrong
        for (int j=0; j<26; j++)
            if ('a'+j != str[i])
                bid = min(bid, findWord(str+i+1, cur->childs[j]));

        // swap adjacent
        if (str[i+1]) {
            Node *cur2 = cur->childs[str[i+1]-'a'];
            if (cur2)
                bid = min(bid, findWord(str+i+2, cur2->childs[str[i]-'a']));
        }

        cur = cur->childs[str[i]-'a'];
    }
    return bid;
}


char words[10017][31];
int main() {
    root = new Node();

    int n, q;
    char word[100];
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%s", words[i]);
        insertWord(words[i], i);
    }

    scanf("%d", &q);
    for (int i=0; i<q; i++) {
        scanf("%s", word);
        int id = findWord(word);
        if (id != NAN) printf("%s is correct\n", word);
        else {
            id = findFuzzy(word);
            if (id != NAN)
                 printf("%s is a misspelling of %s\n", word, words[id]);
            else printf("%s is unknown\n", word);
        }
    }
}
