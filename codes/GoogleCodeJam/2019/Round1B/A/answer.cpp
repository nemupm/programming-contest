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

void solve(int caseIndex, int P, int Q, vector<int>& X, vector<int>& Y, vector<char>& D) {
    vector<int> xAxis(Q+2, 0);
    vector<int> yAxis(Q+2, 0);

    REP(i,0,P) {
        if (D[i] == 'N') { // y > yi
            yAxis[Y[i]+1]++;
        } else if (D[i] == 'E') { // x > xi
            xAxis[X[i]+1]++;
        } else if (D[i] == 'S') { // y < yi
            yAxis[Y[i]]--;
        } else { // x < xi
            xAxis[X[i]]--;
        }
    }

    int maxX = -P, maxY = -P;
    int x = 0, y = 0;
    REP(i,0,Q+1) {
        x += xAxis[i];
        y += yAxis[i];
        maxX = max(maxX, x);
        maxY = max(maxY, y);
    }
    x = y = 0;
    int answerX = 0, answerY = 0;
    REP(i,0,Q+1) {
        x += xAxis[i];
        if (x == maxX) {
            answerX = i;
            break;
        }
    }
    REP(i,0,Q+1) {
        y += yAxis[i];
        if (y == maxY) {
            answerY = i;
            break;
        }
    }

    cout << "Case #" << caseIndex << ": " << answerX << " " << answerY << '\n';

    return;
}

signed main() {
    int T;
    cin >> T;
    
    REP(i,1,T+1) {
        int P, Q;
        cin >> P >> Q;
        vector<int> X(P), Y(P);
        vector<char> D(P);
        REP(j,0,P) cin >> X[j] >> Y[j] >> D[j];
        solve(i, P, Q, X, Y, D);
    }

    return 0;
}

