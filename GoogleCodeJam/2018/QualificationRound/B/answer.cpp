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
#define RREP(i,x,y) for(int i=(int)(x-1);i>=(int)(y);i--)
#define all(x) (x).begin(),(x).end()

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

typedef long long ll;

using namespace std;

int T;
int N;
const int MAX_N = 100000;
int V[MAX_N];
int V_ODD[MAX_N];
int V_EVEN[MAX_N];

string solve() {
    sort(V_ODD, V_ODD + (N - N / 2));
    sort(V_EVEN, V_EVEN + N / 2);
    REP(i, 0, N) {
        if (i % 2 == 0) {
            V[i] = V_ODD[i / 2];
        } else {
            V[i] = V_EVEN[i / 2];
        }
    }
    REP(i, 0, N) {
        eprintf("%d\n", V[i]);
    }
    REP(i, 0, N-1) {
        if (V[i] > V[i+1]) {
            return to_string(i);
        }
    }

    return "OK";
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> T;
    REP(i,0,T){
        cin >> N;
        REP(i, 0, N / 2) {
            cin >> V_ODD[i] >> V_EVEN[i];
        }
        if (N % 2 == 1) {
            cin >> V_ODD[N - N / 2 - 1];
        }
        printf("Case #%d: %s\n",i+1,solve().c_str());
    }
    return 0;
}
