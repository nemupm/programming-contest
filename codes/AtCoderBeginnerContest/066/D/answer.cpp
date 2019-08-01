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
#define int long long

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

typedef long long ll;

using namespace std;

const int MAX_N = 100001;
const ll MOD = 1000000000 + 7;

int n;
int a[MAX_N];
int _a[MAX_N];
ll F[MAX_N];

// k!
void factorial(){
    F[0] = 1;
    F[1] = 1;
    REP(i, 2, n+2){
        F[i] = F[i-1] * i % MOD;
        eprintf("F[%d]=%d\n",i,F[i]);
    }
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

int combination(int _n ,int _r){
    if(F[0] != 1) factorial();

    // nCr = n!/(n-r)!r!
    ll combination = 1;

    combination = F[_n];
    combination *= invmod(F[_n - _r], MOD);
    combination %= MOD;
    combination *= invmod(F[_r], MOD);
    combination %= MOD;

    return combination;
}

string solve() {
    string ans = "";
    ll cmb = 1;
    int both_sides_num = 0;
    int two_num = -1;
    int left_pos = -1;
    int right_pos = -1;
    sort(begin(_a), begin(_a) + n + 1);
    REP(i,0,n){
        if(_a[i] == _a[i+1]){
            two_num = _a[i];
            break;
        }
    }
    REP(i,0,n+1){
        if(left_pos == -1){
            if(a[i] == two_num) left_pos = i;
        }else{
            if(a[i] == two_num){
                right_pos = i;
                break;
            }
        }
    }
    // n+1Ck - both_sides_numC(k-1)
    both_sides_num = left_pos - right_pos + n;
    eprintf("leftpos:%d, rightpos:%d\n",left_pos, right_pos);
    eprintf("both_sides_num: %d\n", both_sides_num);
    REP(k, 1, n+2){
        if(k == 1){
            cmb = n;
        }else if(k == n+1){
            cmb = 1;
        }else if(both_sides_num == 0){
            cmb = combination(n+1, k);
        }else if(both_sides_num >= k - 1){
            cmb = combination(n+1, k) - combination(both_sides_num, k-1);
        }else{
            cmb = combination(n+1, k);
        }
//        if(k != n+1) {
            ans += to_string(cmb) + "\n";
//        }else{
//            ans += to_string(cmb);
//        }
    }
    return ans;
}

signed main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    F[0] = -1;

    cin >> n;
    REP(i, 0, n+1){
        cin >> a[i];
        _a[i] = a[i];
    }
    cout << solve() << "\n";
    return 0;
}
