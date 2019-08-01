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

struct NodeInformation {
    int height;
    vector<int> parents; // parents[height] = node number //including the node itself //root node's height = 0
    vector<pair<int, int>> distance; // distance[i(color number)] = pair<count, sum of distance of i'th color>
    int distanceSum = 0;
};

void dfs(int number, int previousNumber, int height, vector<unordered_map<int, pair<int, int>>>& edges, vector<NodeInformation>& info) {
    info[number].parents = info[previousNumber].parents;
    info[number].parents[height] = number;

    int color = edges[previousNumber][number].first;
    int distance = edges[previousNumber][number].second;
    info[number].distance = info[previousNumber].distance;
    info[number].distance[color] = {info[previousNumber].distance[color].first + 1, info[previousNumber].distance[color].second + distance};

    info[number].distanceSum = info[previousNumber].distanceSum + distance;

    info[number].height = height;

    for(const auto child : edges[number]) {
        if (child.first == previousNumber) continue;

        dfs(child.first, number, height+1, edges, info);
    }
}

int searchNearestCommonParent(int u, int v, vector<NodeInformation>& info) {
    if (info[u].height > info[v].height) {
        swap(u, v);
    }
    // assert(info[u].height <= info[v].height);

    int l=0, r=info[u].height+1;
    while(l+1<r) {
        int mid = (l+r) / 2;
        if (info[u].parents[mid] == info[v].parents[mid]) l=mid;
        else r=mid;
    }
    return l;
}

int getDistanceToRoot(int node, vector<NodeInformation>& info, int x, int y) {
    int distance = info[node].distanceSum;
    distance -= info[node].distance[x].second;
    distance += info[node].distance[x].first * y;
    return distance;
}

void solve(int N, int Q, vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d, vector<int>& x, vector<int>& y, vector<int>& u, vector<int>& v) {
    vector<NodeInformation> info(N+1);
    vector<unordered_map<int, pair<int, int>>> edges(N+1);

    REP(i,1,N) {
        edges[a[i]][b[i]] = {c[i], d[i]};
        edges[b[i]][a[i]] = {c[i], d[i]};
    }
    REP(i,0,N+1) {
        info[i].parents = vector<int>(N);
        info[i].distance = vector<pair<int,int>>(N);
    }

    dfs(1, 0, 0, edges, info);

    stringstream ss;
    REP(i,0,Q) {
        int commonParent = searchNearestCommonParent(u[i], v[i], info);

        int answer = getDistanceToRoot(u[i], info, x[i], y[i]) + getDistanceToRoot(v[i], info, x[i], y[i]) - 2 * getDistanceToRoot(commonParent, info, x[i], y[i]);
        ss << answer << '\n';
    }
    cout << ss.str();

    return;
}

signed main() {
    int N, Q;
    cin >> N >> Q;
    
    vector<int> a(N), b(N), c(N), d(N);
    REP(i,1,N) cin >> a[i] >> b[i] >> c[i] >> d[i];

    vector<int> x(Q), y(Q), u(Q), v(Q);
    REP(i,0,Q) cin >> x[i] >> y[i] >> u[i] >> v[i];

    solve(N, Q, a, b, c, d, x, y, u, v);

    return 0;
}

