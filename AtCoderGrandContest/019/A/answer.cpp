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
#include <regex>

#define FOR(i,x,y) for(int i=(x);i<(y);i++)
#define RFOR(i,x,y) for(int i=(y)-1;i>=(x);i--)
#define REP(i,x) for(int i=0;i<(x);i++)
#define RREP(i,x) for(int i=(x)-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()
#define int long long

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

using namespace std;

const int MAX_N = 100000;
ll Q,H,S,D;
ll N;

ll solve() {
    pair<int, int> ar[] = {pair<int, int>(Q * 8, 0), pair<int, int>(H * 4, 1), pair<int, int>(S * 2, 2), pair<int, int>(D, 3)};

    sort(ar, ar+4);
//    REP(i,4) cout << ar[i].first << "\n";
//    REP(i,4) cout << ar[i].second << "\n";
    if(ar[0].second == 3){
        return (N % 2) * ar[1].first / 2 + (N - N % 2) / 2 * ar[0].first;
    }else{
        return ar[0].first / 2 * N ;
    }
}

signed main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> Q >> H >> S >> D >> N;
    cout << solve() << "\n";
}
