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
int N;
int a[MAX_N];

bool solve() {
    int oddCnt = 0;
    int multi2Cnt = 0; // not multiple of 4
    int multi4Cnt = 0;
    REP(i, 0, N){
        if(a[i] % 4 == 0){
            multi4Cnt++;
        }else if(a[i] % 2 == 0){
            multi2Cnt++;
        }else{
            oddCnt++;
        }
    }
    return (oddCnt <= multi4Cnt || oddCnt == multi4Cnt + 1 && multi2Cnt == 0);
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    REP(i, 0, N) cin >> a[i];
    cout << (solve() ? "Yes" : "No") << "\n";
    return 0;
}
