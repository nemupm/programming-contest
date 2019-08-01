#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>

#define REP(i,x,y) for(int i=(int)(x);i<(int)(y);i++)
#define RREP(i,x,y) for(int i=(int)(x);i>=(int)(y);i--)
#define all(x) (x).begin(),(x).end()

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

typedef long long ll;

using namespace std;

const int MAX_N = 26 * 26;
int T;
int N, L;
string W[MAX_N];

string solve() {
    if (L == 1) return "-";

    map<char, vector<char> > tree;
    REP(i,0,N) tree[W[i][0]].push_back(W[i][1]);

    int size = -1;
    char candidate11, candidate21;
    vector<char> candidate12, candidate22;

    for (map<char, vector<char> >::iterator it = tree.begin(); it != tree.end(); ++it){
        sort(all(it->second));
        if (size == -1) {
            size = it->second.size();
            candidate11 = it->first;
            candidate12 = it->second;
            eprintf("size: %d\n", size);
        } else {
            candidate21 = it->first;
            candidate22 = it->second;

            vector<char> diff1, diff2;
            set_difference(all(candidate12), all(candidate22), back_inserter(diff1));
            set_difference(all(candidate22), all(candidate12), back_inserter(diff2));
            if (diff1.size() != 0) {
                eprintf("--1\n");
                eprintf("%c\n", diff1[0]);
                eprintf("%c\n", candidate21);
                return (string() + candidate21) + diff1[0];
            } else if (diff2.size() != 0) {
                eprintf("--2\n");
                eprintf("%c\n", diff2[0]);
                eprintf("%c\n", candidate21);
                return (string() + candidate11) + diff2[0];
            }
        }
    }
    return "-";
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> T;
    REP(i,0,T){
        cin >> N >> L;
        REP(j,0,N) cin >> W[j];
        printf("Case #%d: %s\n",i+1,solve().c_str());
    }
    return 0;
}
