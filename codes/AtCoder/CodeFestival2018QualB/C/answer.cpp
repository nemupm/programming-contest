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

const int MAX_N = 1000;
int N;

void solve() {
    char cake[MAX_N][MAX_N];
    set<pair<int, int> > filled;
    int rest[5] = {0, 2, 4, 1, 3};
    REP(y,0,N) {
        REP(x,0,N) {
            if (x % 5 == rest[y % 5]) {
                cake[x][y] = 'X';
                filled.insert(make_pair(x,y));
                filled.insert(make_pair(x+1,y));
                filled.insert(make_pair(x,y+1));
                filled.insert(make_pair(x-1,y));
                filled.insert(make_pair(x,y-1));
            }
            else {
                cake[x][y] = '.';
            }
        }
    }
    REP(y,0,N) {
        REP(x,0,N) {
            if (filled.find(make_pair(x, y)) == filled.end()) {
                cake[x][y] = 'X';
                filled.insert(make_pair(x,y));
                filled.insert(make_pair(x+1,y));
                filled.insert(make_pair(x,y+1));
                filled.insert(make_pair(x-1,y));
                filled.insert(make_pair(x,y-1));
            }
        }
    }
    REP(y,0,N) {
        REP(x,0,N) {
            cout << cake[x][y];
        }
        cout << '\n';
    }
    return;
}

signed main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    solve();
    return 0;
}

