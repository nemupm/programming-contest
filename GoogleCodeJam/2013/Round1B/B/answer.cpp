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

int T;
int N, X, Y;

// N(2N-1)

string solve() {
    REP(n, 0, 10000) {
        int x, y; // top and right of big triangle

    }
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> T;
    REP(i,0,T){
        cin >> N >> X >> Y;
        printf("Case #%d: %s\n",i+1,solve().c_str());
    }
    return 0;
}
