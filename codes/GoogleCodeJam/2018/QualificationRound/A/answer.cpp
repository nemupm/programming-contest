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

int T;
int D;
string P;

int calc_damage() {
    int d = 0;
    int power = 1;
    REP(i, 0, P.length()){
        if(P[i] == 'C'){
            power *= 2;
        } else {
            d += power;
        }
    }
    eprintf("%s,%d\n", P.c_str(), d);
    return d;
}

string solve() {
    int ans = 0;
    while(calc_damage() > D) {
        bool impossible = true;
        RREP(i, P.length()-1, 1) {
            if (P[i] == 'S' && P[i-1] == 'C') {
                P.replace(i, 1, "C");
                P.replace(i-1, 1, "S");
                ans++;
                impossible = false;
                break;
            }
        }
        if (impossible) {
            return "IMPOSSIBLE";
        }
    }
    return to_string(ans);
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> T;
    REP(i,0,T){
        P = "";
        cin >> D >> P;
        printf("Case #%d: %s\n",i+1,solve().c_str());
    }
    return 0;
}
