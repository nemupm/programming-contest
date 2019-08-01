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

const int MAX_N = 1e5;
const ll MOD = 1e9 + 7;
int N;
vector<int> A(MAX_N);

int solve() {
    vector<int> sum(N+1);
    {
        int s = 0;
        REP(i, 0, N+1) {
            sum[i] = s;
            s += A[i];
        }
    }

    int answer = 0, left = 0, right = 0;
    while (right < N+1) {
        // sum[0] == 0
        int diff = sum[right] - sum[left];
        if (diff == N) {
            left++;
            right++;
            answer++;
        } else if (diff > N) {
            left++;
        } else {
            right++;
        }
    }
    return answer;
}

signed main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    REP(i,0,N) {
        cin >> A[i];
    }
    cout << solve() << "\n";
    return 0;
}
