#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>
#include <set>

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

const int MAX_H = 500;
const int MAX_W = 500;
int H, W;
int a[MAX_W][MAX_H];

string solve() {
    string answer = "";
    bool wip = false;
    int pre_x = 0;
    int pre_y = 0;
    int count = 0;
    REP(y,0,H) {
        if (y % 2 == 0) {
            REP(x,0,W) {
                if (x == 0 && y == 0) {
                    if (a[x][y] % 2 == 1) wip = !wip;
                    continue;
                }
                if (wip) {
                    count++;
                    answer += to_string(pre_y + 1) + " " + to_string(pre_x + 1) + " " + to_string(y + 1) + " " + to_string(x + 1) + "\n";
                }
                if (a[x][y] % 2 == 1) {
                    wip = !wip;
                }
                pre_x = x;
                pre_y = y;
            }
        } else {
            RREP(x,0,W) {
                if (wip) {
                    count++;
                    answer += to_string(pre_y + 1) + " " + to_string(pre_x + 1) + " " + to_string(y + 1) + " " + to_string(x + 1) + "\n";
                }
                if (a[x][y] % 2 == 1) {
                    wip = !wip;
                }
                pre_x = x;
                pre_y = y;
            }
        }
    }
    answer = to_string(count) + "\n" + answer;
    return answer;
}

signed main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> H >> W;
    REP(y,0,H) REP(x,0,W) cin >> a[x][y];
    cout << solve();
    return 0;
}

