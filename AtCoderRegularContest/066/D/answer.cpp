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
const ll MOD = pow(10,9) + 7;
int A[MAX_N];
int N;

int solve() {
    ll ans = 1;
    sort(A, A + N);
    if(N % 2 == 1){
        REP(i,0,N){
            eprintf("i=%d,A[i]=%d\n",i,A[i]);
            if(A[i] != ((i + 1) / 2) * 2) return 0;
        }
    }else{
        REP(i,0,N){
            eprintf("i=%d,A[i]=%d\n",i,A[i]);
            if(A[i] != (i / 2) * 2 + 1) return 0;
        }
    }
    REP(i,0,N/2){
        ans *= 2;
        ans %= MOD;
    }
    return ans;
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    REP(i, 0, N) cin >> A[i];
    cout << solve() << "\n";
    return 0;
}
