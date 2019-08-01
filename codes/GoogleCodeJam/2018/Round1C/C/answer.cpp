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

const int MAX_N = 100000;
int T, N;
ll W[MAX_N];
int IMPOSSIBLE = -1;

string solve() {
    int answer = 0;

    ll dp[2][N]; // dp[0: prev, 1: current number of ants][used until (i-1)-th ant] = minimum sum weights | IMPOSSIBLE

    REP(i,0,N) {
        dp[0][i] = W[i];
    }

    int prev_min_j = 0;
    REP(i,1,N) { // n = number of ants to be stacked - 1
        eprintf("--i: %d--\n", i);
        bool flag = true;
        ll min_sum = dp[0][prev_min_j];
        REP(j,prev_min_j+1,N) { // j >= prev_min_j >= i
            if (dp[0][j-1] != IMPOSSIBLE) min_sum = min(min_sum, dp[0][j-1]);
            if (min_sum <= W[j] * 6) {
                eprintf("j = %d\n",j);
                eprintf("W[j] = %d\n",W[j]);
                eprintf("dp[%d][%d] = %d <= %d = W[%d] * 6\n", i-1, prev_min_j, dp[0][prev_min_j], W[j] * 6, j);
                dp[1][j] = min_sum + W[j];
                answer = i;
                if(flag) prev_min_j = j;
                flag = false;
            } else {
                dp[1][j] = IMPOSSIBLE;
            }
        }
        if(flag) break;
        REP(i,0,N) dp[0][i] = dp[1][i];
    }

    return to_string(answer + 1);
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> T;
    REP(i,0,T){
        cin >> N;
        REP(j,0,N) cin >> W[j];
        printf("Case #%d: %s\n",i+1,solve().c_str());
    }
    return 0;
}
