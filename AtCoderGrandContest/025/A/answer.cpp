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

int N;

int sum(int a, int b) {
    int sum = 0;

    string as = to_string(a);
    string bs = to_string(b);

    REP(i,0,as.length()) {
        sum += as[i] - '0';
    }

    REP(i,0,bs.length()) {
        sum += bs[i] - '0';
    }

    return sum;
}

void solve() {
    int answer = 10000;

    REP(i,1,N/2+1) {
        int a = i;
        int b = N - i;

        answer = min(sum(a, b), answer);
    }

    printf("%d\n", answer);
    return;
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    solve();
    return 0;
}
