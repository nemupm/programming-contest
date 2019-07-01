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

void solve(int N, int M, vector<int>& S, vector<int>& T) {
    ll answer = 0;

    REP(i,0,N) {
        REP(j,0,M) {
            int s = i, t = j;
            while (true) {
                if (S[i] != T[i]) {
                    answer = (answer + s - i) % MOD;
                    break;
                }
                s++; t++;
                if (s >= N || t >= M) {
                    answer = (answer + s - i) % MOD;
                    break;
                }
            }
        }
    }

	stringstream ss;
	ss << answer;

	cout << ss.str() << '\n';

    return;
}

signed main() {
    int N, M;
    cin >> N >> M;

    vector<int> S(N), T(M);
    REP(i,0,N) cin >> S[i];
    REP(i,0,M) cin >> T[i];

    solve(N, M, S, T);
    
    return 0;
}

