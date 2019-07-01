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

void solve(string S) {
    int former = stoi(S.substr(0, 2)), latter = stoi(S.substr(2, 2));

    if (former > 12 || former == 0) { // former == YY
        if (latter > 12 || latter == 0) { // latter == YY
            cout << "NA" << '\n';
        } else {
            cout << "YYMM" << '\n';
        }
    } else { // former == YY or MM
        if (latter > 12 || latter == 0) { // latter == YY
            cout << "MMYY" << '\n';
        } else {
            cout << "AMBIGUOUS" << '\n';
        }
    }

    return;
}

signed main() {
    string S;
    cin >> S;
    
    solve(S);
    
    return 0;
}

