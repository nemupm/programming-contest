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

map<ll, int> memo; // number of snacks, number of people
const int MAX_N = 100;
int N;
ll x;
ll A[MAX_N];

int solve() {
    int answer = 0;
    int j = 0;
    sort(A, A+N);
    REP(i,0,N) {
        if (x < A[i]) break;
        x -= A[i];
        answer++;
        j=i;
    }
    if (x == 0) return answer;
    else {
        REP(i,0,j+1) {
            REP(k,j+1,N) {
                if (x + A[i] == A[k]) return answer;
            }
        }
        return max(0,answer-1);
    }
}

signed main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> x;
    REP(i,0,N) cin >> A[i];
    cout << solve() << "\n";
    return 0;
}

