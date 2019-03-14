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

const int MAX_N = 800;

ll solve(int N, vector<ll>& v1, vector<ll>& v2) {
    ll answer = 0;
    sort(v1.begin(), v1.begin() + N);
    sort(v2.begin(), v2.begin() + N, greater<int>());
    REP(i,0,N) {
//        eprintf("%d, %d\n", v1[i], v2[i]);
        answer += v1[i] * v2[i];
    }
    return answer;
}

signed main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    int C;
    cin >> C;
    REP(i,1,T+1){
        int N;
        vector<ll> v1(MAX_N), v2(MAX_N);

        cin >> N;
        REP(j,0,N) cin >> v1[j];
        REP(j,0,N) cin >> v2[j];
        cout << "Case #" << i << ": " << solve(N, v1, v2) << "\n";
    }
    return 0;
}

