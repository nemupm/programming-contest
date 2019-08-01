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

const int MAX_HW = 100 * 100;
int N, H, W;
int a[MAX_HW];

bool solve() {
    int cnt = 0;
    int color = 0;
    REP(y, 0, H){
        string line = "";
        REP(x, 0, W) {
            if(a[color] <= cnt){
                color++;
                cnt = 0;
            }
            string space = (line == "") ? "" : " ";
            if(y % 2 == 0){
                line = line + space + to_string(color+1);
            }else{
                line = to_string(color+1) + space + line;
            }
            cnt++;
        }
        cout << line << "\n";
    }
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> H >> W;
    cin >> N;
    REP(i, 0, N){
        cin >> a[i];
    }
    solve();
    return 0;
}
