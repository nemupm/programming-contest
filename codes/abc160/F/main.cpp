#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define rrep(i,x,y) for(ll i=(ll)(y)-1;i>=(x);i--)
#define all(x) (x).begin(),(x).end()
#ifdef LOCAL
#define dump(x)  cerr << #x << " = " << (x) << endl
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl
#define dassert(...) assert(__VA_ARGS__)
#else
#define dump(x)
#define debug(x)
#define dassert(...)
#endif
//#define int long long

typedef long long ll;
const ll MOD = 1e9 + 7;
const long double EPS = 1e-8;

namespace mod {
    long long pow(long long a, long long x, long long p) {
        long long res = 1;
        while(x > 0) {
            if( x % 2 != 0) {
                res = (res * a) % p;
            }
            a = (a * a) % p;
            x /= 2;
        }
        return res;
    }

    long long inverse(long long a, long long p) {
        //calculates the modular multiplicative of a mod m.
        //(assuming p is prime).
        return pow(a, p-2, p);
    }

    long long factorial(long long a, long long p) {
        long long fact = 1;
        for (long long i=2; i<=a; i++) {
            fact *= i;
            fact %= p;
        }
        return fact;
    }
}

struct combination {
    combination(long long max_n, long long p) : _mod(p) {
        factorials_ = std::vector<long long>(max_n+1, 1);
        inverse_factorials_ = std::vector<long long>(max_n+1, 1);
        for (long long i=1; i<max_n+1; i++) {
            factorials_[i] = factorials_[i-1] * i;
            factorials_[i] %= p;
        }
        inverse_factorials_[max_n] = mod::pow(factorials_[max_n],  p-2, p);
        for (long long i=max_n-1; i>=1; i--) {
            inverse_factorials_[i] = inverse_factorials_[i+1] * (i+1);
            inverse_factorials_[i] %= p;
        }
    }

    long long operator()(long long n, long long k) {
        long long result = factorials_[n];
        result *= inverse_factorials_[k];
        result %= _mod;
        result *= inverse_factorials_[n-k];
        result %= _mod;
        return result;
    }

private:
    std::vector<long long> factorials_, inverse_factorials_;
    long long _mod;
};

combination comb(1e6, MOD);

// Omni directional tree dp
struct DP {
    ll numCase, numVertex;
    DP (ll numCase = 1, ll numVertex = 0) : numCase(numCase), numVertex(numVertex) {}

    DP & operator+=(const DP & dp) {
        numVertex += dp.numVertex;
        numCase *= dp.numCase;
        numCase %= MOD;
        numCase *= comb(numVertex, dp.numVertex);
        numCase %= MOD;
        return *this;
    }
    DP operator-(const DP & dp) const {
        DP res(*this);
        res.numCase *= mod::inverse(dp.numCase, MOD);
        res.numCase %= MOD;
        res.numCase *= mod::inverse(comb(res.numVertex, dp.numVertex), MOD);
        res.numCase %= MOD;
        res.numVertex -= dp.numVertex;
        return res;
    }
    DP addRoot () const {
        return DP(numCase, numVertex + 1);
    }
};

DP dfsForward (
        const int parent,
        const int root,
        vector<vector<int>> & edges,
        vector<unordered_map<int, DP>> & dp) {
    DP res;
    for (const int child : edges[root]) {
        if (child == parent) continue;
        dp[root][child] = dfsForward(root, child, edges, dp);
        res += dp[root][child];
    }
    return res.addRoot();
}

void dfsBackward (
        const int parent,
        const int root,
        vector<vector<int>> & edges,
        vector<unordered_map<int, DP>> & dp,
        vector<DP> & vdp) {
    for (const int child : edges[root]) {
        if (child == -1) continue;
        vdp[root] += dp[root][child];
    }
    for (const int child : edges[root]) {
        if (child == parent) continue;
        dp[child][root] = (vdp[root] - dp[root][child]).addRoot();
        dfsBackward(root, child, edges, dp, vdp);
    }
}

void solve(long long N, std::vector<long long> a, std::vector<long long> b) {
    vector<vector<int>> edges(N+1);
    rep(i,0,N-1) {
        edges[a[i]].emplace_back(b[i]);
        edges[b[i]].emplace_back(a[i]);
    }
    vector<unordered_map<int, DP>> dp(N+1); // dp[from][to] = DP
    dfsForward(-1, 1, edges, dp);

    vector<DP> vdp(N+1); // dp[vertex index] = DP
    dfsBackward(-1, 1, edges, dp, vdp);
    rep(k,1,N+1) {
        cout << vdp[k].numCase << endl;
    }
}

signed main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    long long N;
    scanf("%lld",&N);
    std::vector<long long> a(N-1);
    std::vector<long long> b(N-1);
    for(int i = 0 ; i < N-1 ; i++){
        scanf("%lld",&a[i]);
        scanf("%lld",&b[i]);
    }
    solve(N, std::move(a), std::move(b));
    return 0;
}
