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

bool solve(int N, int A, int B, int C, int D, string& S) {
    for (const auto pair : {make_pair(A, C), make_pair(B, D)}) {
        int left = pair.first - 1;
        int right = pair.second - 1;
        for (int i=left; i<right; i++) {
            if (S[i] == '#' && S[i+1] == '#') return false;
        }
    }
    if (D < C) {
        for (int i=B-1; i<=D-1; i++) {
            if (S[i-1] == '.' && S[i] == '.' && S[i+1] == '.') return true;
        }
        return false;
    }

    return true;
}

signed main() {
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;

    string S;
    cin >> S;

    bool answer = solve(N, A, B, C, D, S);

    cout << (answer ? "Yes" : "No") << '\n';
    
    return 0;
}

