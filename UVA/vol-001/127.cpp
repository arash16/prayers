#include <stdio.h>

class FastStack {
    int data[60], sz;
    public:
        FastStack():sz(0) {}
        void clear() { sz=0; }
        bool empty() { return !sz; }
        void push(int x) { data[sz++] = x; }
        int pop() { return data[--sz]; }
        int top() { return data[sz-1]; }
        int size() { return sz; }
};

void swap(FastStack* &a, FastStack* &b) {
    FastStack *t = a; a = b; b = t;
}

// ----------------------------------------------------------------------

bool match[52][52];
FastStack *stacks[54];
int meld(int ind) {
    FastStack *cs = stacks[ind];
    int cur =  cs->top(),
        bind = ind;

    while (1) {
        while (ind>2 && match[stacks[ind-3]->top()][cur]) {
            stacks[ind-3]->push(cs->pop());
            int c = 0;
            for (int k = 2; k>=0; --k) {
                c += meld(ind-k-c-1);
                if (c) swap(stacks[ind-k-c], stacks[ind-k]);
            }
            ind -= c;
            if (cs->empty())
                return bind-ind+1;
            cur = cs->top();
        }

        if (ind>0 && match[stacks[ind-1]->top()][cur]) {
            stacks[ind-1]->push(cs->pop());
            int c = meld(ind-1);
            if (c) {
                swap(stacks[ind-c], stacks[ind]);
                ind -= c;
            }
            if (cs->empty())
                return bind-ind+1;
            cur = cs->top();
        }
        else break;
    }
    return bind-ind;
}



int vals[200];
char sord[] = "CDHS", ford[] = "A23456789TJQK";
int main() {
    for (int i=0; i<4; ++i)
        vals[sord[i]] = 13*i;
    for (int i=0; i<13; ++i)
        vals[ford[i]] = i;

    for (int i=0; i<52; ++i)
        for (int j=0; j<=i; ++j)
            if (i%13==j%13 || i/13==j/13)
                match[i][j]=match[j][i]=1;

    for (int i=0; i<54; ++i)
        stacks[i] = new FastStack();

    char line[156];
    while (fread(line, 1, 156, stdin) == 156) {
        int sz = 0;
        for (int i=0; i<52; ++i) {
            stacks[sz++]->clear();
            stacks[sz-1]->push(vals[line[3*i]] + vals[line[3*i+1]]);
            sz -= meld(sz-1);
        }
        printf("%d pile%s remaining:", sz, sz==1?"":"s");
        for (int i=0; i<sz; ++i)
            printf(" %d", stacks[i]->size());
        putchar('\n');
    }
}
