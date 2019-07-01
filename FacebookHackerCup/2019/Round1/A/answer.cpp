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

struct Requirement {
    int X=0, Y=0, Z=0;
};

class Dikstra {
public:
    Dikstra(int N, unordered_map<int, unordered_map<int, int>> edges)
        : nodes_(vector<int>(N, INT_MAX)), edges_(edges) {}

    int findShortestPath(int source, int destination) {
        return findShortestPathImpl(source, destination);
    }
private:
    vector<int> nodes_;
    unordered_map<int, unordered_map<int, int>> edges_;

    int findShortestPathImpl(int source, int destination) {
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> queue;
        nodes_[source] = 0;
        queue.push({0, source});
        while (queue.size() > 0) {
            int target = queue.top().second;
            int distanceFromSourceToTarget = queue.top().first;
            queue.pop();
            for (const auto pair : edges_[target]) {
                int nextTarget = pair.first;
                int distance = pair.second;
                int update = distance + distanceFromSourceToTarget;
                if (update < nodes_[nextTarget]) {
                    nodes_[nextTarget] = update;
                    queue.push({update, nextTarget});
                }
            }
        }
        return nodes_[destination];
    }
};

void solve(int caseIndex, int N, int M, vector<Requirement>& requirements) {
    unordered_map<int, unordered_map<int, int>> edges;

    REP(i,0,M) {
        edges[requirements[i].X][requirements[i].Y] = requirements[i].Z;
        edges[requirements[i].Y][requirements[i].X] = requirements[i].Z;
    }

    bool answer = true;
    REP(i,0,M) {
        Dikstra dikstra(N+1, edges);
        int shortestDistance = dikstra.findShortestPath(requirements[i].X, requirements[i].Y);
        debug(shortestDistance);
        answer = shortestDistance == requirements[i].Z;
        if (!answer) break;
    }

    stringstream ss;
    if (answer) {
        REP(i,1,N+1) {
            if (edges[i].size() == 0) {
                if (i == 1) {
                    edges[i][2] = 1000000;
                    edges[2][i] = 1000000;
                }
                else {
                    edges[i][1] = 1000000;
                    edges[1][i] = 1000000;
                }
            }
        }

        int edgeCount = 0;
        REP(i,1,N+1) {
            edgeCount += edges[i].size();
        }
        edgeCount /= 2;

        ss << edgeCount << '\n';
        REP(i,1,N+1) {
            int source = i;
            for (const auto pair : edges[i]) {
                int target = pair.first;
                int distance = pair.second;

                if (source > target) continue;

                ss << source << " " << target << " " << distance << '\n';
            }
        }
    } else {
        ss << "Impossible" << '\n';
    }

    cout << "Case #" << caseIndex << ": " << ss.str();

    return;
}

signed main() {
    int T;
    cin >> T;

    REP(i,1,T+1) {
        int N, M;
        cin >> N >> M;
        vector<Requirement> requirements(M);
        REP(i,0,M) cin >> requirements[i].X >> requirements[i].Y >> requirements[i].Z;
        solve(i, N, M, requirements);
    }

    return 0;
}