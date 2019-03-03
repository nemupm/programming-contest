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

class BIT
{
public:
    vector<int> bit;
    int M;

    BIT(int M):
            bit(vector<int>(M+1, 0)), M(M) {}

    int sum(int i) {
        if (!i) return 0;
        return bit[i] + sum(i-(i&-i));
    }

    void add(int i, int x) {
        if (i > M) return;
        bit[i] += x;
        add(i+(i&-i), x);
    }
};

ll solve() {
    BIT bit(N);
    vector<ll> factorial(N+1);

    ll answer = 0;

    // calculate factorials
    {
        ll f = 1;
        REP(i, 1, N+1) {
            f *= i;
            f %= MOD;
            factorial[i] = f;
        }
    }

    REP(i,0,N) {
//        printf("i=%d, A[i]=%d: %d * %lld\n",i, A[i], ((A[i]-1) - bit.sum(A[i]-1)), factorial[N-i-1]);
        answer += ((A[i]-1) - bit.sum(A[i]-1)) * factorial[N-i-1];
        answer %= MOD;
        bit.add(A[i], 1);
    }

    answer += 1;

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
