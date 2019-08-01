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

void dfs(int k, int color, unordered_map<int, unordered_map<int, int> >& links, vector<int>& colors) {
    if (colors[k] != -1) return;
    colors[k] = color;

    for (const auto link : links[k]) {
        if (link.second % 2 == 0) {
            dfs(link.first, color, links, colors);
        } else {
            dfs(link.first, 1 - color, links, colors);
        }
    }
}

void solve(const int N, unordered_map<int, unordered_map<int, int> >& links) {
    vector<int> colors(N+1,-1);
    REP(i,1,N+1) {
        dfs(i, 0, links, colors);
    }

    REP(i,1,N+1) {
        cout << colors[i] << '\n';
    }

    return;
}

signed main() {
    int N;
    cin >> N;
    unordered_map<int, unordered_map<int, int> > links;
    REP(i,0,N-1) {
        int u,v,w;
        cin >> u >> v >> w;
        links[u][v] = w;
        links[v][u] = w;
    }
    solve(N, links);
    
    return 0;
}

