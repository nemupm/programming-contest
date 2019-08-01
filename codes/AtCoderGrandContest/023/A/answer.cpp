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

#define REP(i,x,y) for(ll i=(ll)(x);i<(ll)(y);i++)
#define RREP(i,x,y) for(ll i=(ll)(x);i>=(ll)(y);i--)
#define all(x) (x).begin(),(x).end()

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

typedef long long ll;

using namespace std;

const ll MAX_N = 200000;
ll N;
ll A[MAX_N];
ll sums[MAX_N];
map<ll, ll> cmb;

ll solve() {
    ll answer = 0;

    ll sum = 0;
    sums[0] = 0;
    REP(i,0,N) {
        sum += A[i];
        sums[i] = sum;
    }

    cmb.clear();
    cmb[0] = 1;
    REP(i,0,N) {
        ll key = sums[i];
        if(cmb.count(key) == 0) cmb[key] = 0;
        cmb[key]++;
    }

    for (map<ll, ll>::iterator it = cmb.begin(); it != cmb.end(); ++it){
        ll key = it->first;
        ll cnt = it->second;

        eprintf("key: %d, cnt: %d\n", key, cnt);

        if (cnt <= 1) continue;

        answer += cnt * (cnt - 1) / 2;
    }

    return answer;
}

signed main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    REP(i,0,N) cin >> A[i];
    cout << solve() << "\n";
}
