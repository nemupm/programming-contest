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

void solve(int caseIndex, int W) {
    ll R1, R2, R3, R4, R5, R6;
    cout << 210 << '\n';

    ll feedback;
    cin >> feedback;
    // R4 * 2^52 + R5 * 2^42 + R6 * 2^35
    R4 = feedback / (1LL << 52);
    R5 = (feedback - R4 * (1LL << 52)) / (1LL << 42);
    R6 = (feedback - R4 * (1LL << 52) - R5 * (1LL << 42)) / (1LL << 35);

    cout << 48 << '\n';
    cin >> feedback;
    // R1 * 2^48 + R2 * 2^24 + R3 * 2^16 + R4 * 2^12 + R5 * 2^9 + R6 * 2^8
    R1 = feedback / (1LL << 48);
    R2 = (feedback - R1 * (1LL << 48)) / (1LL << 24);
    R3 = (feedback - R1 * (1LL << 48) - R2 * (1LL << 24) - R4 * (1LL << 12) - R5 * (1LL << 9) - R6 * (1LL << 8)) / (1LL << 16);

    REP(i,2,W) {
        cout << 1LL << '\n';
        cin >> feedback;
    }

    cout << R1 << " " << R2 << " " << R3 << " " << R4 << " " << R5 << " " << R6 << '\n';
    cin >> feedback;

    if (feedback == -1) exit(0);

    return;
}

signed main() {
    int T, W;
    cin >> T >> W;

    REP(i,1,T+1) {
        solve(i, W);
    }

    return 0;
}
