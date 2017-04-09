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
#define RREP(i,x,y) for(int i=(int)(x-1);i>=(int)(y);i--)
#define all(x) (x).begin(),(x).end()

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

typedef long long ll;

using namespace std;

int T;
string N;

string solve() {
    string ans;
    bool tidy = true;
    int maxIndex = 0;
    REP(i, 0, N.length()){
        int current = (char)N[i] - '0';
        int next = (char)N[min(i+1,(int)N.length()-1)] - '0';
        eprintf("%d,%d\n",current,next);
        if(current > next){
            tidy = false;
            break;
        }else if(current < next){
            maxIndex = i+1;
        }
    }
    if(tidy) return N;
    REP(i, 0, N.length()){
        int current = (char)N[i] - '0';
        if(i < maxIndex) ans += to_string(current);
        else if(i == maxIndex){
            if(i == N.length()-1) ans += to_string(current);
            else if(current-1 > 0) ans += to_string(current-1);
        }else{
            ans += "9";
        }
    }
    return ans;
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> T;
    REP(i,0,T){
        cin >> N;
        eprintf("N: %s\n", N.c_str());
        printf("Case #%d: %s\n",i+1,solve().c_str());
    }
    return 0;
}
