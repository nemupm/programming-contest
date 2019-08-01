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
const ll MOD = 1000000000 + 7;

ll F[MAX_N+1];
int N, M;

// k!
void factorial(){
    F[0] = 1;
    F[1] = 1;
    REP(i, 2, MAX_N+1){
        F[i] = F[i-1] * i % MOD;
        eprintf("F[%d]=%d\n",i,F[i]);
    }
}

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

int combination(int _n ,int _r){
    if(F[0] != 1) factorial();

    // nCr = n!/(n-r)!r!
    ll combination = 1;

    combination = F[_n];
    combination *= invmod(F[_n - _r], MOD);
    combination %= MOD;
    combination *= invmod(F[_r], MOD);
    combination %= MOD;

    return combination;
}

ll solve() {
    factorial();
    if(max(N - M, M - N) == 0) return (((F[N] % MOD) * (F[M] % MOD)) % MOD * 2) % MOD;
    if(max(N - M, M - N) == 1) return ((F[N] % MOD) * (F[M] % MOD))% MOD;
    else return 0;
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    cout << solve() << "\n";
    return 0;
}
