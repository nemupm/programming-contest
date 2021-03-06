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

void solve(int R, int G, int B, int N) {
    int answer = 0;
    for (int i=0; i<=N/R; i++) {
        for (int j=0; j<=N/G; j++) {
            if (i*R+j*G > N) break;
            if ((N - i*R - j*G) % B == 0) answer++;
        }
    }

    cout << answer << '\n';

    return;
}

signed main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    
    solve(R, G, B, N);
    
    return 0;
}

