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

const int MAX_N = 50;
int N, P;
int A[MAX_N];

ll solve() {
    int even = 0, odd = 0;
    ll answer = 0;
    REP(i, 0, N){
        if(A[i] % 2 == 0) even += 1;
        else odd += 1;
    }
    if(odd == 0){
        if(P == 0) answer = pow(2, even);
        else answer = 0;
    }else {
        answer = pow(2, even) * pow(2, odd - 1);
    }
    return answer;
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> P;
    REP(i,0,N) cin >> A[i];
    cout << solve() << "\n";
    return 0;
}

