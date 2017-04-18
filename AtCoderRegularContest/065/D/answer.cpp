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
#include <regex>

#define FOR(i,x,y) for(int i=(x);i<(y);i++)
#define RFOR(i,x,y) for(int i=(y)-1;i>=(x);i--)
#define REP(i,x) for(int i=0;i<(x);i++)
#define RREP(i,x) for(int i=(x)-1;i>=0;i--)
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

using namespace std;

const int MAX = 100000;
int N,K,L;
int p[MAX],q[MAX],r[MAX],s[MAX];

struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) { }
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};

void solve() {
    UnionFind roads(N);
    UnionFind rails(N);
    REP(i,K){
        roads.unionSet(p[i]-1,q[i]-1);
    }
    REP(i,L){
        rails.unionSet(r[i]-1,s[i]-1);
    }
    map<pair<int,int>,int> towns;
    REP(i,N){
        int road,rail;
        road = roads.root(i);
        rail = rails.root(i);
        if(towns.count(pair<int,int>(road,rail))) towns[pair<int,int>(road,rail)] += 1;
        else towns[pair<int,int>(road,rail)] = 0;
    }
    REP(i,N){
        int road,rail;
        road = roads.root(i);
        rail = rails.root(i);
        cout << towns[pair<int,int>(road,rail)] + 1;
        if(i < N-1) cout << " ";
    }
    cout << "\n";
}

signed main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> K >> L;
    REP(i,K) cin >> p[i] >> q[i];
    REP(i,L) cin >> r[i] >> s[i];
    solve();
    return 0;
}
