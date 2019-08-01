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

void solve(int H, int W, vector<vector<bool>>& walls) {
    vector<ll> previousRow(W+1, 0), currentRow(W+1, 0);
    previousRow[1] = 1;

    REP(i,1,H+1) {
        REP(j,1,W+1) {
            if (walls[i][j]) {
                currentRow[j] = 0;
                continue;
            }
            currentRow[j] = (previousRow[j] + currentRow[j-1]) % MOD;
        }
        previousRow = currentRow;
    }
    ll answer = currentRow.back();

	stringstream ss;
    ss << answer;
	cout << ss.str() << '\n';

    return;
}

signed main() {
    int H, W;
    cin >> H >> W;

    vector<vector<bool>> walls(H+1, vector<bool>(W+1, false));
    REP(i,1,H+1) {
        REP(j,1,W+1) {
            char c;
            cin >> c;
            if (c == '#') walls[i][j] = true;
        }
    }

    solve(H, W, walls);
    
    return 0;
}

