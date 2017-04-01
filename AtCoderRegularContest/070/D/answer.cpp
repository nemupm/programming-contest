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
#define RREP(i,x,y) for(int i=(int)(x-1);i>=(int)(y);i--)
#define all(x) (x).begin(),(x).end()

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

typedef long long ll;

using namespace std;

int N, K;
const int MAX_N = 400;
const int MAX_K = 400;
int a[MAX_N+1];
// REP(i,1,N+1) dp[j][k]:
// If k can be created with numbers until j without i, true.

int solve() {
    int ans = N;
    REP(i, 1, N+1) {
        if(a[i] >= K){
            ans--;
            continue;
        }
        bool dp[MAX_N+1][MAX_K+1];
        fill(dp[0], dp[0] + (MAX_N+1) * (MAX_K+1), false);
        REP(j, 0, N+1) {
            dp[j][0] = true;
            if(j == 0) continue;
            if(i == j){
                REP(k, 0, K) dp[j][k] = dp[j-1][k];
            }else{
                REP(k, 0, K){
                    if(dp[j-1][k]){
                        // not use j
                        dp[j][k] = true;
                        // use j
                        if(k + a[j] < K){
                            dp[j][k+a[j]] = true;
                        }
                    }
                }
            }
        }
        REP(k, K-a[i], K){
            if(dp[N][k]){
                ans--;
                break;
            }
        }
        REP(j, 1, N+1){
            REP(k, 0, K){
                if(dp[j][k]) eprintf("i=%d,j=%d,k=%d: true\n",i,j,k);
            }
        }
    }
    return ans;
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> K;
    REP(i,1,N+1){
        cin >> a[i];
    }
    cout << solve() << "\n";
    return 0;
}
