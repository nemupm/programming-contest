#include "bits/stdc++.h"

#define REP(i,x,y) for(int i=(x);i<(y);i++)
#define RREP(i,x,y) for(int i=(y)-1;i>=(x);i--)
#define all(x) (x).begin(),(x).end()
// #define int long long

using namespace std;

// conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define dump(x)  cerr << #x << " = " << (x) << endl
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl
#else
#define eprintf(...) 42
#define dump(x) 42
#define debug(x) 42
#endif

typedef long long ll;

const ll MOD = 1e9 + 7;

ll getMinimumCost(int l, int r, vector<ll>& sum, vector<vector<ll>>& dp) { // [l, r)
    if (dp[l][r] != -1) return dp[l][r];

    assert(l+2<=r);
    vector<ll> candidates;
    REP(i,l+1,r) {
        candidates.emplace_back(getMinimumCost(l, i, sum, dp) + getMinimumCost(i, r, sum, dp) + sum[r] - sum[l]);
    }
    dp[l][r] = *min_element(candidates.begin(), candidates.end());
    return dp[l][r];
}

void solve(int N, vector<int>& a) {
    vector<vector<ll>> dp(N, vector<ll>(N+1, -1));
    REP(i,0,N) {
        dp[i][i+1] = 0;
    }

    vector<ll> sum(N+1);
    sum[0] = 0;
    REP(i,1,N+1) sum[i] = sum[i-1] + a[i-1];

	ll answer = getMinimumCost(0, N, sum, dp);
	stringstream ss;
	ss << answer;
	cout << ss.str() << '\n';

    return;
}

signed main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    REP(i,0,N) cin >> A[i];
    
    solve(N, A);
    
    return 0;
}

