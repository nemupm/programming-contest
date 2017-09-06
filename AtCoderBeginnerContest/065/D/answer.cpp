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

#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define REP(i,x,y) for(int i=(int)(x);i<(int)(y);i++)
#define RREP(i,x,y) for(int i=(int)(x);i>=(int)(y);i--)
#define all(x) (x).begin(),(x).end()
//#define int long long

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

typedef long long ll;

using namespace std;

const int MAX_N = 100000;
int N;
int X[MAX_N], Y[MAX_N];
vector< pair<int, int> > xis, yis; // <coordinate, index>

typedef int Weight;
struct Edge {
    int src, dst;
    Weight weight;
    Edge(int src, int dst, Weight weight) :
            src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
    return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
           e.src != f.src ? e.src < f.src : e.dst < f.dst;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

Graph makeGraph(){
    Graph graph(N);
    sort(all(xis));
    sort(all(yis));

    REP(i, 0, N-1){
        int src_x = xis[i].first;
        int src_index = xis[i].second;
        int dst_x = xis[i+1].first;
        int dst_index = xis[i+1].second;
        Edge edge_src = Edge(src_index, dst_index, dst_x - src_x);
        graph[src_index].push_back(edge_src);
        Edge edge_dst = Edge(dst_index, src_index, dst_x - src_x);
        graph[dst_index].push_back(edge_dst);
    }

    REP(i, 0, N-1){
        int src_y = yis[i].first;
        int src_index = yis[i].second;
        int dst_y = yis[i+1].first;
        int dst_index = yis[i+1].second;
        Edge edge_src = Edge(src_index, dst_index, dst_y - src_y);
        graph[src_index].push_back(edge_src);
        Edge edge_dst = Edge(dst_index, src_index, dst_y - src_y);
        graph[dst_index].push_back(edge_dst);
    }
    return graph;
}

pair<Weight, Edges> minimumSpanningTree(const Graph &g, int r = 0) {
    int n = g.size();
    Edges T;
    Weight total = 0;

    vector<bool> visited(n);
    priority_queue<Edge> Q;
    Q.push( Edge(-1, r, 0) );
    while (!Q.empty()) {
        Edge e = Q.top(); Q.pop();
        if (visited[e.dst]) continue;
        T.push_back(e);
        total += e.weight;
        visited[e.dst] = true;
        FOR(f, g[e.dst]) if (!visited[f->dst]) Q.push(*f);
    }
    return pair<Weight, Edges>(total, T);
}

int solve() {
    Graph g = makeGraph();
    return minimumSpanningTree(g).first;
}

signed main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    REP(i, 0, N){
        cin >> X[i] >> Y[i];
        xis.push_back(make_pair(X[i], i));
        yis.push_back(make_pair(Y[i], i));
    }
    cout << solve() << "\n";
    return 0;
}
