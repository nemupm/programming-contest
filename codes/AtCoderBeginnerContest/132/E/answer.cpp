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

void solve(int N, int M, int S, int T, vector<int>& u, vector<int>& v) {
    vector<vector<int>> edges(N+1);
    REP(i,1,M+1) {
        edges[u[i]].emplace_back(v[i]);
    }

    vector<vector<int>> dp(N+1, vector<int>(3, INT_MAX));

    dp[S][0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > queue;
    queue.push({0, S});

    while (queue.size() > 0) {
        const auto pair = queue.top();
        int currentVertex = pair.second;
        int distance = pair.first;
        queue.pop();

        for (const auto nextVertex : edges[currentVertex]) {
            if (dp[nextVertex][(distance+1)%3] > distance+1) {
                dp[nextVertex][(distance+1)%3] = distance + 1;
                queue.push({distance + 1, nextVertex});
            }
        }
    }

	int answer = dp[T][0] == INT_MAX ? -1 : dp[T][0] / 3;
	stringstream ss;
	ss << answer;
	cout << ss.str() << '\n';

    return;
}

signed main() {
    int N, M, S, T;
    cin >> N >> M;
    
    vector<int> u(M+1), v(M+1);
    REP(i,1,M+1) cin >> u[i] >> v[i];

    cin >> S >> T;
    
    solve(N, M, S, T, u, v);
    
    return 0;
}

