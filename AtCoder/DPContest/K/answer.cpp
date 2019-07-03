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

void solve(int N, int K, vector<int>& A) {
    vector<vector<bool>> dp(2, vector<bool>(K)); // dp[0: Taro, 1: Jiro][k] =  true: Taro wins
    dp[0][0] = false;
    dp[1][0] = true;
    REP(k,1,K+1) {
        // Taro
        for (const auto a : A) {
            if (k-a >= 0 && dp[1][k-a]) {
                dp[0][k] = true;
                break;
            }
            dp[0][k] = false;
        }
        // Jiro
        for (const auto a : A) {
            if (k-a >= 0 && !dp[0][k-a]) {
                dp[1][k] = false;
                break;
            }
            dp[1][k] = true;
        }
    }

	string answer = dp[0][K] ? "First" : "Second";
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

