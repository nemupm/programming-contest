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

void solve(int N, int W,vector<int>& w, vector<int>& v) {
    vector<vector<ll>> dp(N+1, vector<ll>(1e3 * 100+1, 1e11+1)); // dp[product 1..i][value <= j] = min of weight

    REP(j,1,dp[0].size()) dp[0][j] = 1e11+1;
    REP(i,0,N+1) dp[i][0] = 0;

    REP(i,1,N+1) {
        REP(j,1,dp[i].size()) {
            if (j >= v[i-1]) {
                dp[i][j] = min(dp[i-1][j-v[i-1]] + w[i-1], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
//            cout << i << " " << j << " " << dp[i][j] << '\n';
        }
    }

	stringstream ss;
    ll answer = 0;
    REP(j,0,dp[N].size()) if (dp[N][j] <= W) answer = j;
    ss << answer;
	cout << ss.str() << '\n';

    return;
}

signed main() {
    int N, W;
    cin >> N >> W;
    
    vector<int> w(N);
    vector<int> v(N);
    REP(i,0,N) {
        cin >> w[i];
        cin >> v[i];
    }

    solve(N, W, w, v);
    
    return 0;
}

