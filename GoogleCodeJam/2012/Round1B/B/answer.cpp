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

const int MAX_N = 100;
const int MAX_M = 100;
const int MAX_H = 10000;
int H; // height
int N; // x
int M; // y
double dp[MAX_N][MAX_M][MAX_H+1]; // minimum seconds to go to map(x,y)
int floor_h[MAX_N][MAX_M]; // floor height
int ceiling_h[MAX_N][MAX_M]; // ceiling height
ll MAX_NUM = MAX_H * MAX_N * MAX_M * 100;

string solve() {
    // init
    map<int, queue< pair<int, int> > > search_queue;
    pair<int,int> dsts[4] = {make_pair(1,0),make_pair(0,1),make_pair(-1,0),make_pair(0,-1)};
    REP(n,0,N){
        REP(m,0,M){
            REP(h,0,H+1){
                dp[n][m][h] = MAX_NUM;
            }
        }
    }

    // add start position
    dp[0][0][H] = 0.0;
    search_queue[H].push(make_pair(0, 0));

    // move before dropping
    while(search_queue[H].size() > 0) {
        pair<int,int> current = search_queue[H].front();
        search_queue[H].pop();
        int current_bottom = max(floor_h[current.first][current.second], H);
        int current_top = ceiling_h[current.first][current.second];
//        eprintf("current top/bottom: (%d,%d)\n", current_top, current_bottom);
        for(auto dst : dsts) {
            pair<int,int> destination = make_pair(current.first + dst.first, current.second + dst.second);

            // continue if not able to move to destination
            if(destination.first < 0 || destination.first >= N || destination.second < 0 || destination.second >= M) {
                continue;
            }
            int destination_bottom = max(floor_h[destination.first][destination.second], H);
            int destination_top = ceiling_h[destination.first][destination.second];
//            eprintf("destination top/bottom: (%d,%d)\n", destination_top, destination_bottom);
            if(current_top - destination_bottom < 50 || destination_top - current_bottom < 50 || destination_top - destination_bottom < 50) {
                continue;
            }

            // update dp and queue
            if(dp[destination.first][destination.second][H] > 0) {
                dp[destination.first][destination.second][H] = 0.0;
                search_queue[H].push(make_pair(destination.first, destination.second));
            }

            // return if destination is goal
            if(destination.first == N - 1 && destination.second == M - 1) {
                return to_string(dp[destination.first][destination.second][H]);
            }
        }
    }

    // start while dropping
    RREP(h,H,-1){
        REP(n,0,N){
            REP(m,0,M){
                if(dp[n][m][h] != MAX_NUM){
                    search_queue[h].push(make_pair(n,m));
                    if(h > 0 && dp[n][m][h-1] > dp[n][m][h] + 0.1){
                        dp[n][m][h-1] = dp[n][m][h] + 0.1;
                    }
                }
            }
        }
        eprintf("--height: %d--", h);
        while(search_queue[h].size() > 0){
            pair<int,int> current = search_queue[h].front();
            search_queue[h].pop();
            int current_bottom = max(floor_h[current.first][current.second], h);
            int current_top = ceiling_h[current.first][current.second];
//            eprintf("current top/bottom: (%d,%d)\n", current_top, current_bottom);
            for(auto dst : dsts) {
                pair<int,int> destination = make_pair(current.first + dst.first, current.second + dst.second);

                // continue if not able to move to destination
                if(destination.first < 0 || destination.first >= N || destination.second < 0 || destination.second >= M) {
                    continue;
                }
                int destination_bottom = max(floor_h[destination.first][destination.second], h);
                int destination_top = ceiling_h[destination.first][destination.second];
//                eprintf("destination top/bottom: (%d,%d)\n", destination_top, destination_bottom);
                if(current_top - destination_bottom < 50 || destination_top - current_bottom < 50 || destination_top - destination_bottom < 50) {
                    continue;
                }

                // update dp and queue
                float time_to_spend = h - floor_h[current.first][current.second] >= 20 ? 1.0 : 10.0;
                int after_height = max((int)(h - time_to_spend * 10), 0);
                if(dp[destination.first][destination.second][after_height] > dp[current.first][current.second][h] + time_to_spend) {
                    dp[destination.first][destination.second][after_height] = dp[current.first][current.second][h] + time_to_spend;
                }

                // return if destination is goal
                if(destination.first == N - 1 && destination.second == M - 1) {
                    return to_string(dp[destination.first][destination.second][after_height]);
                }
            }
        }
    }

    // move after dropping completed (water height = 0)
    REP(n,0,N){
        REP(m,0,M){
            if(dp[n][m][0] != MAX_NUM){
                search_queue[0].push(make_pair(n,m));
            }
        }
    }
    while(search_queue[0].size() > 0) {
        pair<int,int> current = search_queue[0].front();
        search_queue[0].pop();
        int current_bottom = max(floor_h[current.first][current.second], 0);
        int current_top = ceiling_h[current.first][current.second];
//        eprintf("current top/bottom: (%d,%d)\n", current_top, current_bottom);
        for(auto dst : dsts) {
            pair<int,int> destination = make_pair(current.first + dst.first, current.second + dst.second);

            // continue if not able to move to destination
            if(destination.first < 0 || destination.first >= N || destination.second < 0 || destination.second >= M) {
                continue;
            }
            int destination_bottom = max(floor_h[destination.first][destination.second], 0);
            int destination_top = ceiling_h[destination.first][destination.second];
//            eprintf("destination top/bottom: (%d,%d)\n", destination_top, destination_bottom);
            if(current_top - destination_bottom < 50 || destination_top - current_bottom < 50 || destination_top - destination_bottom < 50) {
                continue;
            }

            // update dp and queue
            float time_to_spend = 10.0;
            int after_height = 0;
            if(dp[destination.first][destination.second][after_height] > dp[current.first][current.second][0] + time_to_spend) {
                dp[destination.first][destination.second][after_height] = dp[current.first][current.second][0] + time_to_spend;
                search_queue[0].push(make_pair(destination.first, destination.second));
            }

            // return if destination is goal
            if(destination.first == N - 1 && destination.second == M - 1) {
                return to_string(dp[destination.first][destination.second][0]);
            }
        }
    }

    RREP(h,1,-1) {
        eprintf("--%d--\n",h);
        REP(n,0,N){
            REP(m,0,M){
                eprintf("(%d,%d)=%f ",n,m,dp[n][m][h]);
            }
            eprintf("\n");
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
        cin >> H >> N >> M;
        REP(n,0,N){
            REP(m,0,M){
                cin >> ceiling_h[n][m];
            }
        }
        REP(n,0,N){
            REP(m,0,M){
                cin >> floor_h[n][m];
            }
        }
        printf("Case #%d: %s\n",i+1,solve().c_str());
    }
    return 0;
}