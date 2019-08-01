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
#define RREP(i,x,y) for(int i=(int)(x);i>=(int)(y);i--)
#define all(x) (x).begin(),(x).end()

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

typedef long long ll;

using namespace std;

const int MAX_N = 100000;
const ll MOD = 1000000000 + 7;

int n;
int a[MAX_N];
int _a[MAX_N];
int F[MAX_N];

// k!
ll factorial(int i){
    if(F[i]){
        return F[i];
    }

    ll f = 1;
    REP(l, 1, i+1) f = (1ll * f * l) % MOD;
    F[i] = f;
    return f;
}

int extgcd(int a, int b, int &x, int &y) {
    for (int u = y = 1, v = x = 0; a;) {
        int q = b / a;
        swap(x -= q * u, u);
        swap(y -= q * v, v);
        b -= q*a; swap(b, a);
    }
    return b;
}

int invmod(int a, int m) {
    int x, y;
    if (extgcd(a, m, x, y) == 1) return (x + m) % m;
    else return 0; // unsolvable
}

// the number of combinations to create groups(each group has just i people) from j people.
int combination(int _n ,int _r){
    // nCr = n!/(n-r)!r!
    ll combination = 1;

    combination = factorial(_n);
    combination *= invmod(_n - _r, MOD);
    combination %= MOD;
    combination *= invmod(_r, MOD);
    combination %= MOD;

    return combination;
}

void solve() {
    ll ans = 1;
    int both_sides_num = 0;
    int two_num = 0;
    int left_pos = -1;
    int right_pos = -1;
    sort(_a[0].begin(), _a[0].end());
    REP(i,0,n-1){
        if(_a[i] == _a[i+1]){
            two_num = _a[i];
            break;
        }
    }
    REP(i,0,n){
        if(left_pos == -1){
            if(a[i] == two_num) left_pos = i;
        }else{
            if(a[i] == two_num) right_pos = i;
            break;
        }
    }
    //n+1Ck - {left_pos + (n + 1 - right_pos)}C(k-1)
    REP(k, 1, n+2){
        ans = combination(n+1, k) - combination((left_pos - right_pos + n + 1), k-1);
        cout << ans << "\n";
    }
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    REP(i, 0, n){
        cin >> a[i];
        cin >> _a[i];
    }
    return 0;
}
