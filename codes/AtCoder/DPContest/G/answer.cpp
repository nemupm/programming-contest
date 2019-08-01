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

int findLongestPath(int currentVertex, unordered_map<int, vector<int>>& edges, vector<int>& memo) {
    if (memo[currentVertex] != -1) return memo[currentVertex];

    int longestPath = 0;
    for (const int destination : edges[currentVertex]) {
        longestPath = max(longestPath, findLongestPath(destination, edges, memo) + 1);
    }
    memo[currentVertex] = longestPath;
    return longestPath;
}

void solve(int N, int M, unordered_map<int, vector<int>>& edges) {
    vector<int> memo(N+1, -1); // longest path from i vertex

    int answer = 0;
    REP(i,1,N+1) {
        answer = max(answer, findLongestPath(i, edges, memo));
    }

	stringstream ss;
    ss << answer;
	cout << ss.str() << '\n';

    return;
}

signed main() {
    int N, M;
    cin >> N >> M;

    unordered_map<int, vector<int>> edges;
    REP(i,0,M) {
        int s, t;
        cin >> s >> t;
        edges[s].emplace_back(t);
    }

    solve(N, M, edges);
    
    return 0;
}

