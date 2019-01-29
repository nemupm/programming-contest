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

const int MAX_N = 100000;
int N;
int a[MAX_N], b[MAX_N], c[MAX_N];
int dp[MAX_N][3]; // 最大の幸福度のdp。その日にA,B,Cをしたかどうかで3通り

int solve() {
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];
    REP(i,1,N) {
        dp[i][0] = max(dp[i-1][1] + a[i], dp[i-1][2] + a[i]);
        dp[i][1] = max(dp[i-1][0] + b[i], dp[i-1][2] + b[i]);
        dp[i][2] = max(dp[i-1][0] + c[i], dp[i-1][1] + c[i]);
    }
    return max(max(dp[N-1][0], dp[N-1][1]), dp[N-1][2]);
}

signed main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    REP(i,0,N) cin >> a[i] >> b[i] >> c[i];
    cout << solve() << "\n";
    return 0;
}
