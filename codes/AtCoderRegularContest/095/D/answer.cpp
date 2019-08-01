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

const int MAX_N = 100000;
int N;
int A[MAX_N];

void solve() {
    sort(A, A + N);

    int large = A[N-1];
    int small = A[0];
    int min_diff = large;

    REP(i, 0, N-1) {
        int diff = abs(large - 2 * A[i]);
        if (diff <= min_diff) {
            min_diff = diff;
            small = A[i];
        }
    }
    printf("%d %d\n", large, small);
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    REP(i, 0, N){
        cin >> A[i];
    }
    solve();
    return 0;
}
