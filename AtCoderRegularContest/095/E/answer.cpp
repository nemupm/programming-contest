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

const string characters = "abcdefghijklmnopqrstuvwxyz";
const int MAX_H = 12;
const int MAX_W = 12;
int H, W;
string S[MAX_H];
map<char, int> h[MAX_H];
map<char, int> w[MAX_W];
vector<string> h_stats;
vector<string> w_stats;

string solve() {
    REP(i, 0, H) {
        REP(j, 0, characters.length()) {
            h[i][characters[j]] = 0;
        }
    }
    REP(i, 0, W) {
        REP(j, 0, characters.length()) {
            w[i][characters[j]] = 0;
        }
    }
    REP(i, 0, H) {
        REP(j, 0, S[i].length()) {
            h[i][S[i][j]]++;
            w[j][S[i][j]]++;
        }
    }
    REP(i, 0, H) {
        string str = "";
        REP(j, 0, characters.length()) {
            str += to_string(h[i][characters[j]]);
        }
        h_stats.push_back(str);
    }
    REP(i, 0, W) {
        string str = "";
        REP(j, 0, characters.length()) {
            str += to_string(h[i][characters[j]]);
        }
        w_stats.push_back(str);
    }

    sort(h_stats.begin(), h_stats.end());
    sort(w_stats.begin(), w_stats.end());

    REP(i, 0, H) eprintf("H: %s\n", h_stats[i].c_str());
    REP(i, 0, W) eprintf("W: %s\n", w_stats[i].c_str());

    int h_middle = -1, w_middle = -1;
    REP(i, 0, H-1) {
        if (h_stats[i] != h_stats[i+1]) {
            if (h_middle != -1 || H % 2 == 0) {
                eprintf("h_stats[i]: %s\n", h_stats[i].c_str());
                eprintf("h_stats[i+1]: %s\n", h_stats[i+1].c_str());
                return "NO";
            }
            h_middle = i;
        } else {
            i++;
        }
    }
    REP(i, 0, W-1) {
        if (w_stats[i] != w_stats[i+1]) {
            if (w_middle != -1 || W % 2 == 0) {
                eprintf("w_stats[i]: %s\n", w_stats[i].c_str());
                eprintf("w_stats[i+1]: %s\n", w_stats[i+1].c_str());
                return "NO";
            }
            w_middle = i;
        } else {
            i++;
        }
    }

    if (h_middle != -1) {
        bool flag = W % 2 == 0 ? true : false;
        REP(i, 0, W) {
            int count = h_stats[h_middle][i] - '0';
            if (count % 2 != 0) {
                if (flag) return "NO";
                flag = true;
            }
        }
    }
    if (w_middle != -1) {
        bool flag = H % 2 == 0 ? true : false;
        REP(i, 0, H) {
            int count = w_stats[w_middle][i] - '0';
            if (count % 2 != 0) {
                if (flag) return "NO";
                flag = true;
            }
        }
    }

    return "YES";
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> H >> W;
    REP(i, 0, H){
        cin >> S[i];
    }
    cout << solve() << "\n";
    return 0;
}
