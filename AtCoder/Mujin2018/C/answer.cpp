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

const int MAX_N = 2 * 1000;
int N, M;
char S[MAX_N][MAX_N];
int MEM[MAX_N][MAX_N][4];

ll solve() {
    for (auto )
    // number of places to left
    REP(i,0,N) {
        int n = 0;
        REP(j,0,M) {
            if (S[i][j] == '.') {
                MEM[i][j][0] = n;
                n++;
            } else {
                n = 0;
            }
        }
    }
    // number of places to right
    REP(i,0,N) {
        int n = 0;
        RREP(j,0,M) {
            if (S[i][j] == '.') {
                MEM[i][j][1] = n;
                n++;
            } else {
                n = 0;
            }
        }
    }
    // number of places to top
    REP(j,0,M) {
        int n = 0;
        REP(i,0,N) {
            if (S[i][j] == '.') {
                MEM[i][j][2] = n;
                n++;
            } else {
                n = 0;
            }
        }
    }
    // number of places to bottom
    REP(j,0,M) {
        int n = 0;
        RREP(i,0,N) {
            if (S[i][j] == '.') {
                MEM[i][j][3] = n;
                n++;
            } else {
                n = 0;
            }
        }
    }

    REP(i,0,N) REP(j,0,M) eprintf("(%d, %d)left right top bottom = %d, %d, %d, %d\n", i, j, MEM[i][j][0],MEM[i][j][1],MEM[i][j][2],MEM[i][j][3]);

    ll answer = 0;
    REP(i,0,N) {
        REP(j,0,M) {
            if (S[i][j] == '#') continue;
            answer +=
                    MEM[i][j][0] * MEM[i][j][3]
                    + MEM[i][j][1] * MEM[i][j][2]
                    + MEM[i][j][2] * MEM[i][j][0]
                    + MEM[i][j][3] * MEM[i][j][1];
        }
    }
    return answer;
}

signed main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    REP(i,0,N) REP(j,0,M) cin >> S[i][j];
    cout << solve() << "\n";
    return 0;
}

