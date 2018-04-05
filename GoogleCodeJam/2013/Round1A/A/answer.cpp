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

bool can_paint(ll r, ll t, ll n) {
    return n * (2 * r + 2 * n - 1) <= t;
}

string solve(ll r, ll t) {
    ll low = 0;
    ll high = 10000000000000;
    while(low < high) {
//        printf("%lld, %lld\n", low, high);
        ll mid = (low + high) / 2;
        if (low == mid) {
            return low.str();
        } else if (can_paint(r, t, mid)) {
            low = mid;
        } else {
            high = mid;
        }
    }
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> T;
    REP(i,0,T){
        ll r, t;
        cin >> r >> t;
//        printf("%lld, %lld\n", r, t);
        printf("Case #%d: %s\n",i+1,solve(r, t).c_str());
    }
    return 0;
}
