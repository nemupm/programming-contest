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

void solve(int N, int K, vector<int>& a) {
    vector<vector<ll>> dp(N+1, vector<ll>(K+1, 0));

    dp[0][0] = 1;

    REP(i, 1, N+1) {
        vector<ll> prevDpSum(K+1, 0);
        prevDpSum[0] = dp[i-1][0];
        REP(k, 1, K+1) {
            prevDpSum[k] = (prevDpSum[k-1] + dp[i-1][k]) % MOD;
        }

        REP(k, 0, K+1) {
            // If i th child receive j candies, it means k-j candies already used.
            // => dp[i][k] = dp[i-1][max(0,k-a[i-1])] + ... + dp[i-1][k]
//            REP(j, 0, min(a[i-1]+1, k+1)) {
//                dp[i][k] = (dp[i][k] + dp[i-1][k-j]) % MOD;
//            }
            dp[i][k] = prevDpSum[k];
            if (k>a[i-1]) dp[i][k] = (dp[i][k] - prevDpSum[k-a[i-1]-1] + MOD) % MOD;
        }
    }

	ll answer = dp[N][K];
	stringstream ss;
	ss << answer;
	cout << ss.str() << '\n';

    return;
}

signed main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> A(N);
    REP(i,0,N) cin >> A[i];
    
    solve(N, K, A);
    
    return 0;
}

