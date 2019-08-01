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

string str;

int solve() {
    int ans, half;
    bool flag;
    REP(i, 1, str.length()){
        flag = true;
        if((str.length() - i) % 2 == 1) continue;
        half = (str.length() - i) / 2;
        REP(j, 0, half){
            if(str[j] != str[j + half]){
                flag = false;
                break;
            }
        }
        if(flag){
            ans = str.length() - i;
            break;
        }
    }
    return ans;
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> str;
    cout << solve() << "\n";
    return 0;
}
