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

const ll MAX_N = 3 * 1000000;
ll N, A, B, K;
ll ncr[MAX_N];

const ll MOD_N = 998244353;

ll gcd(ll a, ll b) {
    return b != 0 ? gcd(b, a % b) : a;
}

ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll g = a; x = 1; y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}

ll modinv(ll a, ll m) {
    ll x, y;
    if (extgcd(a, m, x, y) == 1) {
        return (x + m) % m;
    } else {
        return 0;
    } // unsolvable
}

// nCr mod m = modc(n,r,m)
ll modc(ll a, ll b, ll m) {
    ll c = 1;
    REP(i, 0, b) {
        c = c * (a - i) % m;
        c = c * modinv(i + 1, m) % m;
    }
    return c;
}

void solve() {
    // K = A * a + B * b, 0 <= a,b <= N
    // answer = N C a + N C b

    ll answer = 0;

    // nCr   = (n-r+1)/r * nC(r-1)
    ncr[0] = 1;
    REP(i,1,N+1) {
        ncr[i] = ((N - i + 1) * modinv(i, MOD_N) % MOD_N) * ncr[i-1] % MOD_N;
    }

    REP(a,0,N+1) {
        if (K - A * a < 0 || (K - A * a) % B != 0) continue;

        ll b = (K - A * a) / B;

        answer += ncr[a] * ncr[b] % MOD_N;
        answer %= MOD_N;
    }

    printf("%lld\n", answer);

    return;
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> A >> B >> K;
    solve();
    return 0;
}
