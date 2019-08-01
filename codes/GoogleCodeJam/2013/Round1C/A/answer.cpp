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

bool is_consonants(const char c) {
    const char vowels[5] = { 'a', 'e', 'i', 'o', 'u' };
    const char *result = find(begin(vowels), end(vowels), c);
    if (result != end(vowels)) {
        return false;
    } else {
        return true;
    }
}

string solve(string L, int n) {
    vector<int> consonants_position;
    int consecutive_number = 0;
    RREP(i, L.length()-1, 0) {
        if (is_consonants(L[i])) {
            consecutive_number++;
        } else {
            consecutive_number = 0;
        }
        if (consecutive_number >= n) {
            consonants_position.push_back(i);
        }
    }

    sort(consonants_position.begin(), consonants_position.end());

    ll answer = 0;
    int left = 0;
    for (auto consonants_left : consonants_position) {
        eprintf("left: %d, consonants_left: %d\n", left, consonants_left);
        answer += (consonants_left - left + 1) * (L.length() - (consonants_left + n) + 1);
        left = consonants_left + 1;
    }

    return to_string(answer);
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> T;
    REP(i,0,T){
        string L;
        int n;
        cin >> L >> n;
        printf("Case #%d: %s\n",i+1,solve(L, n).c_str());
    }
    return 0;
}
