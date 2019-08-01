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

ll getGameScore(int l, int r, bool isTaroTurn, vector<vector<vector<ll>>>& dp, vector<int>& a) { // l <= i <= r
    if (dp[isTaroTurn ? 0 : 1][l][r] != LONG_LONG_MAX) return dp[isTaroTurn ? 0 : 1][l][r];

    if (isTaroTurn) {
        ll score = max(getGameScore(l+1, r, false, dp, a) + a[l], getGameScore(l, r-1, false, dp, a) + a[r]);
        dp[0][l][r] = score;
        return score;
    } else {
        ll score = min(getGameScore(l+1, r, true, dp, a) - a[l], getGameScore(l, r-1, true, dp, a) - a[r]);
        dp[1][l][r] = score;
        return score;
    }
}

void solve(int N, vector<int>& a) {
    vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(N, vector<ll>(N, LONG_LONG_MAX)));
    REP(i,0,N) {
        dp[0][i][i] = a[i];
        dp[1][i][i] = -a[i];
    }

	ll answer = getGameScore(0, N-1, true, dp, a);
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
