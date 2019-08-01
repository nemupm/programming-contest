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
const int MAX_N = 5000;
const int MAX_K = 5000;
int a[MAX_N+1];

// fact: If x is necessary, y(>x) is necessary.
// proof:
//  x is necessary, so [K-x,K) can be created without x.
//  If The group creating [K-x,K)
//   case1. do not include y:
//    It means [K-x,K) can be created without y.
//    And [K-y,K) includes [K-x,K).
//    Therefore y is necessary.
//   case2. include y:
//    Replacing y with x decreases the number by (y - x).
//    It means [K-x-(y-x),K-(y-x)) = [K-y,K-y+x) is generated.
//    [K-y,K) includes [K-y,K-y+x).
//    Therefore y is necessary.
//  Therefore y is necessary.

bool isNecessary(int i){
    if(a[i] >= K){
        return true;
    }
    eprintf("i=%d\n",i);
    bool dp[MAX_N+1][MAX_K+1];
    fill(dp[0], dp[0] + (MAX_N+1) * (MAX_K+1), false);
    REP(j, 0, N+1) {
        dp[j][0] = true;
        if(j == 0) continue;
        else if(i == j){
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
            return true;
        }
    }
    REP(j, 1, N+1){
        REP(k, 0, K){
            if(dp[j][k]) eprintf("i=%d,j=%d,k=%d: true\n",i,j,k);
        }
    }
    return false;
}

// returning i means a[1],a[2],...,a[i-1] is not necessary and the others are necessary.
int minNecessaryNumber(){
    int l = 1, r = N;
    while(r - l >= 1){
        eprintf("l=%d,r=%d\n",l,r);
        int i = (l + r) / 2;
        eprintf("i=%d\n",i);
        if(isNecessary(i)){
            if(i == 1) return 1;
            else if(!isNecessary(i-1)) return i;
            else r = i;
        }
        else{
            l = i + 1;
        }
    }
    if(isNecessary(r)) return r;
    else return r+1;
}

int solve() {
    sort(a+1,a+N+1);
    return minNecessaryNumber() - 1;
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
