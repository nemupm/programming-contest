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

#define REP(i,x,y) for(int i=(int)(x);i<(int)(y);i++)
#define RREP(i,x,y) for(int i=(int)(x);i>(int)(y);i--)
#define all(x) (x).begin(),(x).end()

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

typedef long long ll;

using namespace std;

const int MAX_N = 2 * 100000;

void solve() {
    int answer = 0;
    UnionFind uf(N+1);
    REP(i,0,M) {
        uf.unionSet(x[i], y[i]);
    }
    REP(i,0,N) {
        if(uf.findSet(p[i], i+1)) answer++;
    }
    cout << answer << "\n";
    return;
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    REP(i,0,N) cin >> p[i];
    REP(i,0,M) {
        cin >> x[i] >> y[i];
    }
    solve();
    return 0;
}
