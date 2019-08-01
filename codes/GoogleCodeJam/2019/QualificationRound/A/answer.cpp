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

void solve(int caseIndex, string& N) {
    string A, B;

    int zeroCount = count(all(N), '0');

    if (zeroCount == N.length() - 1 && N[0] == '1') { // ex) 1000000
        A += '5';
        B += '5';
        REP(i,0,N.length()-2) {
            A += '0';
            B += '0';
        }
    } else {
        bool reverse = true;
        REP(i,0,N.length()) {
            if (N[i] == '4') {
                A += '2';
                B += '2';
            } else if (N[i] == '5') {
                A += '2';
                B += '3';
            } else if (N[i] == '0') {
                A += '0';
                B += '0';
            } else if (reverse) {
                A += '1';
                B += N[i] - 1;
                reverse = !reverse;
            } else {
                B += '1';
                A += N[i] - 1;
                reverse = !reverse;
            }
        }
        REP(i,0,A.length()) {
            if (A[i] != '0') {
                A.erase(0, i);
                break;
            }
        }
        REP(i,0,B.length()) {
            if (B[i] != '0') {
                B.erase(0, i);
                break;
            }
        }
    }

	stringstream ss;
    ss << A << ' ' << B;

	cout << "Case #" << caseIndex << ": " << ss.str() << '\n';

    return;
}

signed main() {
    int T;
    string N;
    cin >> T;
    
    REP(i,1,T+1) {
        cin >> N;
        solve(i, N);
    }

    return 0;
}

