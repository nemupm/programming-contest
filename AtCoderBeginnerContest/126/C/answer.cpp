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

const ll MOD = 1e9 + 7;

void solve(int N, int K) {
    double answer = 0;
    unordered_map<int, int> counts;
    REP(n,1,N+1) {
        if (K <= n) {
            answer += 1.0;
            continue;
        }
        int count = ceil(log((double)K/n) / log(2.0));
        counts[count]++;
    }

    for (const auto count : counts) {
        answer += count.second * pow(1.0 / 2, count.first);
    }

    answer /= (double)N;

    cout << setprecision(12) << answer << '\n';

    return;
}

signed main() {
    int N, K;
    cin >> N >> K;
    
    solve(N, K);
    
    return 0;
}

