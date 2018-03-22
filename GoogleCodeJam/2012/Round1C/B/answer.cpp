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
#include <set>
#include "boost/tuple/tuple.hpp"

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

const int MAX_A = 10;
const int MAX_N = 2;
double D; // distance
int N;
int A;
double Ti[MAX_N];
double Xi[MAX_N];
double Ai[MAX_A]; // accelerations

void solve() {
    if(N == 1){
        // D == 0.5 * a * t^2
        REP(i,0,A){
            printf("%f\n", pow(2 * D / Ai[i], 0.50));
        }
    } else {
        // D == x0 + (t / (t0 + t1)) * (x1 - x0)
        double time_of_other_car = (D - Xi[0]) * (Ti[0] + Ti[1]) / (Xi[1] - Xi[0]);
        REP(i,0,A){
            // D == 0.5 * a * t^2
            double time_if_no_brake = pow(2 * D / Ai[i], 0.50);
            // if catch up with the other car
            if(time_if_no_brake < time_of_other_car) {
                printf("%f\n", time_of_other_car);
            } else {
                printf("%f\n", time_if_no_brake);
            }
        }
    }
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    REP(i,0,T){
        cin >> D >> N >> A;
        REP(n,0,N) cin >> Ti[n] >> Xi[n];
        REP(a,0,A) cin >> Ai[a];
        printf("Case #%d:\n",i+1);
        solve();
    }
    return 0;
}
