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

const int MAX_W = 100;
int T;
int R, C, H, V;
int CHIPS[MAX_W];
char W[MAX_W][MAX_W];

string solve() {
    int ALL_CHIPS = 0;
    REP(y, 0, R) ALL_CHIPS += CHIPS[y];
    if (ALL_CHIPS % ((H+1) * (V+1)) != 0) return "IMPOSSIBLE";

    int chips_by_cell = ALL_CHIPS / (H+1) / (V+1);
    int chips_by_line = ALL_CHIPS / (H+1);
    eprintf("chips_by_cell: %d, chips_by_line: %d\n", chips_by_cell, chips_by_line);

    vector<int> h; // devided by h rows
    vector<int> v; // devided by v columns

    // decide h
    int chips = 0;
    REP(y, 0, R) {
        chips += CHIPS[y];

        if (chips == chips_by_line) {
            eprintf("devided by row %d ~ %d\n", y, y+1);
            h.push_back(y);
            chips = 0;

            if (h.size() == H) break;
        } else if (chips > chips_by_line) {
            return "IMPOSSIBLE";
        }
    }

    // check all cells
    int CELLS[V+1][H+1];
    fill(CELLS[0], CELLS[0] + (V+1) * (H+1), 0);

    int xth = 0;
    REP(x, 0, C) {
        int yth = 0;
        REP(y, 0, R) {
            if (W[x][y] == '@') CELLS[xth][yth]++;

            if (y == h[yth]) yth++;
        }

        bool flag = true;
        REP(y, 0, H + 1) {
            if (CELLS[xth][y] > chips_by_cell) return "IMPOSSIBLE";
            if (CELLS[xth][y] < chips_by_cell) {
                flag = false;
                break;
            }
        }

        if (flag) {
            eprintf("devided by column %d ~ %d\n", x, x+1);
            xth++;
        }
    }

    REP(x, 0, V+1) {
        REP(y, 0, H+1) {
            if (CELLS[x][y] != chips_by_cell) return "IMPOSSIBLE";
            eprintf("CELL[%d][%d]: %d\n", x, y, CELLS[x][y]);
        }
    }

    return "POSSIBLE";
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> T;
    REP(i,0,T){
        cin >> R >> C >> H >> V;
        fill(CHIPS, CHIPS + R, 0);
        REP(y, 0, R) {
            CHIPS[y] = 0;
            REP(x, 0, C) {
                cin >> W[x][y];
                if (W[x][y] == '@') CHIPS[y]++;
            }
        }
        printf("Case #%d: %s\n",i+1,solve().c_str());
    }
    return 0;
}
