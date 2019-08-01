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
#include <set>
#include "boost/tuple/tuple.hpp"

#define REP(i,x,y) for(int i=(int)(x);i<(int)(y);i++)
#define RREP(i,x,y) for(int i=(int)(x);i>(int)(y);i--)
#define all(x) (x).begin(),(x).end()

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

#include <boost/multiprecision/cpp_int.hpp>

typedef boost::multiprecision::cpp_int ll;

using namespace std;

const int MAX_N = 100;
int T;
int A, N;
int MOTE[MAX_N];

string solve() {
    int ans = 0; // operations
    int ans_when_remove = N;
    int armin = A;

    if (armin == 1) return to_string(N);

    sort(MOTE, MOTE + N);

    REP(i, 0, N) {
        ans_when_remove = min(ans_when_remove, ans + N - i);
        if (MOTE[i] < armin) {
            armin += MOTE[i];
        } else {
            while (armin <= MOTE[i]) {
                armin += armin - 1;
                ans++; // add
            }
            armin += MOTE[i];
        }
    }
    return to_string(min(ans, ans_when_remove));
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> T;
    REP(i,0,T){
        cin >> A >> N;
        REP(j, 0, N) cin >> MOTE[j];
        printf("Case #%d: %s\n",i+1,solve().c_str());
    }
    return 0;
}
