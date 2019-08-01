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

const int MAX_N = 200000;
int N;
int X[MAX_N];
int Y[MAX_N];

void solve() {
    sort(Y, Y + N);

    int small_median = Y[N / 2 - 1];
    int large_median = Y[N / 2];

    REP(i, 0, N) {
        if (X[i] <= small_median) printf("%d\n", large_median);
        else printf("%d\n", small_median);
    }
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    REP(i, 0, N){
        cin >> X[i];
        Y[i] = X[i];
    }
    solve();
    return 0;
}
