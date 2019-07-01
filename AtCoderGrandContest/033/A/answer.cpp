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

const int MAX_N = 100000;

int solve(vector<vector<bool> >& grids, const int H, const int W) {
    vector<vector<int> > distances(H, vector<int>(W, INT_MAX));
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > que;
    REP(i,0,H) {
        REP(j,0,W) {
            if (grids[i][j]) {
                distances[i][j] = 0;
                que.push({0, {i, j}});
            }
        }
    }
    vector<vector<int> > didjs{{-1,0}, {+1, 0}, {0, -1}, {0, +1}};
    int answer = 0;
    while (!que.empty()) {
        auto el = que.top();
        que.pop();
        int distance = el.first;
        int i = el.second.first, j = el.second.second;
        for (const auto didj : didjs) {
            int di = didj[0];
            int dj = didj[1];
            if (i+di < 0 || i+di >= H || j+dj < 0 || j+dj >= W) continue;
            if (!grids[i+di][j+dj] && distances[i+di][j+dj] > distance+1) {
                distances[i+di][j+dj] = distance+1;
                que.push({distance+1, {i+di, j+dj}});
            }
        }
    }

    REP(i,0,H) {
        REP(j,0,W) {
            answer = max(distances[i][j], answer);
        }
    }

    return answer;
}

signed main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;
    vector<vector<bool> > grids(H, vector<bool>(W, false));
    REP(i,0,H) {
        REP(j,0,W) {
            char grid;
            cin >> grid;
            grids[i][j] = grid == '#';
        }
    }
    cout << solve(grids, H, W) << "\n";
    return 0;
}

