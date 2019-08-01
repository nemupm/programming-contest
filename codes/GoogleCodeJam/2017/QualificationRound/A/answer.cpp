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
#define RREP(i,x,y) for(int i=(int)(x);i>(int)(y);i--)
#define all(x) (x).begin(),(x).end()

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

typedef long long ll;

using namespace std;

int T;
string S;
int K;

string solve() {
    int ans = 0;
    REP(i, 0, S.length()-K+1){
        if(S[i] == '-'){
            ans++;
            REP(j, i, i+K){
                S[j] = S[j] == '-' ? '+' : '-';
            }
        }
    }
    REP(i,0,S.length()) if(S[i] == '-') return "IMPOSSIBLE";
    return to_string(ans);
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> T;
    getline(cin, S);
    REP(i,0,T){
        cin >> S >> K;
        printf("Case #%d: %s\n",i+1,solve().c_str());
    }
    return 0;
}
