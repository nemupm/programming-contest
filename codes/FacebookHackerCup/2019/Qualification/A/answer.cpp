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

void solve(int caseIndex, string& L) {
    int N = L.size();
    int countB = count(all(L), 'B');
    bool answer = N-1 > countB && 2*countB+1 >= N;

    stringstream ss;
    ss << (answer ? 'Y' : 'N');

    cout << "Case #" << caseIndex << ": " << ss.str() << '\n';

    return;
}

signed main() {
    int T;
    string L;
    cin >> T;

    REP(i,1,T+1) {
        cin >> L;
        solve(i, L);
    }

    return 0;
}