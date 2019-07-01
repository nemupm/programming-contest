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

void solve(int caseIndex, int N, int K, vector<char>& votes) {
    vector<int> sum(N+1, 0); // sum of "a-b"
    REP(i,1,N+1) {
        sum[i] = sum[i-1] + (votes[i] == 'A' ? 1 : -1);
    }

    // calculate 2^i
    vector<ll> costs(N+1);
    costs[0] = 1;
    REP(i,1,N+1) costs[i] = (ll)costs[i-1] * (ll)2 % MOD;

    ll answer = 0;
    int minSum = sum[N];
    int lastBPosition = votes[N] == 'B' ? N : -1;
    RREP(i,0,N) {
        if (sum[i] - minSum > K) {
            assert(lastBPosition != -1 && lastBPosition == i+1);
            answer = (answer + (ll)costs[lastBPosition]) % MOD;
            minSum += 2;
            lastBPosition = -1;
        }
        minSum = min(sum[i], minSum);
        if (votes[i] == 'B') lastBPosition = i;
    }

    stringstream ss;
    ss << answer << '\n';
    cout << "Case #" << caseIndex << ": " << ss.str();

    return;
}

signed main() {
    int T;
    cin >> T;

    REP(i,1,T+1) {
        int N, K;
        cin >> N >> K;
        vector<char> votes(N+1);
        REP(i,1,N+1) cin >> votes[i];
        solve(i, N, K, votes);
    }

    return 0;
}