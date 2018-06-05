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

const int MAX_N = 3 * 100000;
string S;
int N;
int number[MAX_N]; // the number of people turning to the leader from the point of i th position.

void solve() {
    int count = 0;
    REP(i,1,S.length()) {
        if (S[i] == 'W') count++;
    }
    number[0] = count;
//    printf("%d\n", number[0]);
    REP(i,1,S.length()) {
        int diff = 0;
        diff += (S[i-1] == 'E' ? 1 : 0) + (S[i] == 'W' ? -1 : 0);
        number[i] = number[i-1] + diff;
//        printf("%d\n", number[i]);
    }
    int max = *max_element(number, number + N);
    printf("%d\n", N - 1 - max);
    return;
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> S;
    solve();
    return 0;
}
