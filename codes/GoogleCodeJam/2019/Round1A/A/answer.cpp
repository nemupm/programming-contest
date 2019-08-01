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

bool search(int count, vector<vector<bool> >& visited, int R, int C, pair<int, int> prev, stringstream& ss) {
    int& prevR = prev.first;
    int& prevC = prev.second;

    if (count == R * C) {
        return true;
    }
    REP(r,0,R) {
        REP(c,0,C) {
            if (visited[r][c] || r == prevR || c == prevC || r - c == prevR - prevC || r + c == prevR + prevC) {
                continue;
            }
            visited[r][c] = true;
            bool routeFound = search(count+1, visited, R, C, make_pair(r,c), ss );
            if (routeFound) {
                ss << r+1 << " " << c+1 << '\n';
                return true;
            }
            visited[r][c] = false;
        }
    }
    return false;
}

void solve(int caseIndex, int R, int C) {
    vector<vector<bool> > visited(R, vector<bool>(C, false));

    stringstream ss;

    bool routeFound = search(0, visited, R, C, make_pair(-1,-1), ss);

    if (routeFound) {
        cout << "Case #" << caseIndex << ": " << "POSSIBLE" << '\n' << ss.str();
    } else {
        cout << "Case #" << caseIndex << ": " << "IMPOSSIBLE" << '\n';
    }

    return;
}

signed main() {
    int T;
    cin >> T;
    
    REP(i,1,T+1) {
        int R, C;
        cin >> R >> C;
        solve(i, R, C);
    }

    return 0;
}

