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

const int MOD = 1e9 + 7;
const int MAX_N = 1000;
int N;
int A,B,C,D;

int F[MAX_N+1];
int P[MAX_N+1][MAX_N+1];
int K[MAX_N+1][MAX_N+1];

// k!
int factorial(int i){
    if(F[i]){
        return F[i];
    }

    int f = 1;
    REP(l, 1, i+1) f = (1ll * f * l) % MOD;
    F[i] = f;
    return f;
}

// a x + b y = gcd(a, b)
//int extgcd(int a, int b, int &x, int &y) {
//    int g = a; x = 1; y = 0;
//    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
//    return g;
//}
int extgcd(int a, int b, int &x, int &y) {
    for (int u = y = 1, v = x = 0; a;) {
        int q = b / a;
        swap(x -= q * u, u);
        swap(y -= q * v, v);
        b -= q*a; swap(b, a);
    }
    return b;
}

int invmod(int a, int m) {
    int x, y;
    if (extgcd(a, m, x, y) == 1) return (x + m) % m;
    else return 0; // unsolvable
}

// the number of combinations to create groups(each group has just i people) from j people.
int combination(int i,int j,int k){
    // combination = nPr / (i!)^k / k!
    int combination = 1;

    // nPr
    int n = N - (j - i * k);
    int r = i * k;
    if(P[n][r]) combination = P[n][r];
    else {
        RREP(l, n, n - r) {
            combination = (1ll * combination * l) % MOD;
        }
        P[n][r] = combination;
    }

    // (i!)^k
    int ik = 1;
    int ii = factorial(i);
    if(K[i][k]) ik = K[i][k];
    else {
        REP(l, 0, k) {
            ik = (1ll * ik * invmod(ii, MOD)) % MOD;
        }
        K[i][k] = ik;
    }
    combination = (1ll * combination * ik) % MOD;

    // k!
    combination = (1ll * combination * invmod(factorial(k), MOD)) % MOD;

    eprintf("combination: %d (N,i,j,k: %d,%d,%d,%d)\n",combination,N,i,j,k);

    return combination;
}

int solve() {
    // dp[i][j]: the number of combinations with these conditions.
    //   1. the number of people of all groups is less than i.
    //   2. the total number of people of all groups is j.
    int dp[N+1][N+1];
    fill(dp[0], dp[0] + (N+1)*(N+1), 0);
    REP(i,0,A) dp[i][0] = 1;

    // all groups must have more than A people.
    REP(i,A,N+1){
        REP(j,0,N+1){
            // k: the number of groups whose number of people is i.
            dp[i][j] += dp[i-1][j]; // this is equivalent to the case k == 0;
            if(i > B) continue;
            REP(k,C,D+1){
                if(0 > j - i * k) break;
                eprintf("--dp[i-1][j-i*k]: %d\n",dp[i-1][j-i*k]);
                dp[i][j] = (dp[i][j] + 1ll * dp[i-1][j-i*k] * combination(i,j,k)) % MOD;
            }
            eprintf("dp[%d][%d]: %d\n",i,j,dp[i][j]);
        }
    }
    return dp[N][N];
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> A >> B >> C >> D;
    eprintf("N,A,B,C,D: %d,%d,%d,%d,%d\n",N,A,B,C,D);
    cout << solve() << "\n";
    return 0;
}
