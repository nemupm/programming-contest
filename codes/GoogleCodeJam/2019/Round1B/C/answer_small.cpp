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

void solve(int caseIndex, int N, int K, vector<int>& C, vector<int>& D) {
    ll answer = 0;

    REP(l,0,N) {
        int maxC = C[l];
        int maxD = D[l];
        REP(r,l,N) {
            maxC = max(C[r], maxC);
            maxD = max(D[r], maxD);
            if (abs(maxC - maxD) <= K) answer++;
        }
    }

    cout << "Case #" << caseIndex << ": " << answer << '\n';

    return;
}

signed main() {
    int T;
    cin >> T;

    REP(i,1,T+1) {
        int N, K;
        cin >> N >> K;
        vector<int> C(N), D(N);
        REP(j,0,N) cin >> C[j];
        REP(j,0,N) cin >> D[j];
        solve(i, N, K, C, D);
    }

    return 0;
}
