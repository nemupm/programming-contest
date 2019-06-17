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

// LCS Longest common subsequence
void solve(string& s, string& t) {
    vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));

    REP(i,1,s.size()+1) {
        REP(j,1,t.size()+1) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    string answer = "";
    int l = s.size(), r = t.size(), len = dp[s.size()][t.size()];
    while (len > 0) {
        while (max(dp[l-1][r], dp[l][r-1]) == len) {
            if (dp[l-1][r] == len) l--;
            else r--;
        }
        answer = s[l-1] + answer;
        len--;
        l--; r--;
    }

	stringstream ss;
    ss << answer;
	cout << ss.str() << '\n';

    return;
}

signed main() {
    string s, t;
    cin >> s >> t;

//    vector<int> w(N);
//    vector<int> v(N);
//    REP(i,0,N) {
//        cin >> w[i];
//        cin >> v[i];
//    }

    solve(s, t);
    
    return 0;
}

