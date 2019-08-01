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

typedef boost::tuple<int,int,int> triple_t;
bool my_compare(const triple_t& arg1, const triple_t& arg2)
{
    return arg1.get<0>() < arg2.get<0>()
           || arg1.get<0>() == arg2.get<0>() && arg1.get<1>() < arg2.get<1>()
           || arg1.get<0>() == arg2.get<0>() && arg1.get<1>() == arg2.get<1>() && arg1.get<2>() < arg2.get<2>();
    return false;
}

int T;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > level_two; // level_two_stars, level
vector<triple_t> level_one; // -level_two_stars, level_one_stars, level
set<int> cleared_two; // level
set<int> cleared_one; // level

string solve() {
    int ans = 0;
    int current_stars = 0;
    while(level_two.size() > 0) {
        int stars = level_two.top().first;
        int level = level_two.top().second;
        eprintf("[two_level] stars: %d level: %d\n", stars, level);
        if(stars <= current_stars) {
            ans++;
            if(cleared_one.count(level) == 1) {
                current_stars += 1;
            }else {
                current_stars += 2;
            }
            level_two.pop();
            cleared_two.insert(level);
            cleared_one.insert(level);
            eprintf("[solved!] current_stars: %d ans: %d\n", current_stars, ans);
        } else {
            bool found = false;
            REP(i, 0, level_one.size()) {
                int stars = get<1>(level_one[i]);
                int level = get<2>(level_one[i]);
                eprintf("[one_level] stars: %d, two-rating-stars: %d, level: %d\n", stars, -get<0>(level_one[i]), level);
                if(stars <= current_stars && cleared_one.count(level) == 0) {
                    ans++;
                    current_stars += 1;
                    cleared_one.insert(level);
                    eprintf("[solved!] current_stars: %d ans: %d\n", current_stars, ans);
                    found = true;
                    break;
                }
            }
            if(!found) return "Too Bad";
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
        int N;
        cin >> N;
        level_one.clear();
        level_two = priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >();
        cleared_one.clear();
        cleared_two.clear();
        REP(l,0,N){
            int stars_one;
            int stars_two;
            cin >> stars_one;
            cin >> stars_two;
            level_one.push_back(boost::make_tuple(-stars_two, stars_one, l));
            level_two.push(make_pair(stars_two, l));
        }
        sort(level_one.begin(), level_one.end(), my_compare);
        printf("Case #%d: %s\n",i+1,solve().c_str());
    }
    return 0;
}
