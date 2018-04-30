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
int N, L;
vector<int> C;

int check_count_to_add(double number, double unit) {
    double small_number = number - (int)number;
    double count = (0.5 - small_number) / unit;
    return (int)count + 1;
}

string solve() {
    if (N == 2 || N == 4 || N == 5 || N == 10 || N == 25 || N == 50 || N == 100) {
        return "100";
    }

    int remaining_people = N;
    REP(i,0,L) remaining_people -= C[i];

    vector<int> rounded_up_numbers;
    REP(i,0,N) {
        double percent = 100.0 * i / N;
        double small_number = percent - (int)percent;
        if(small_number >= 0.5) rounded_up_numbers.push_back(i);
    }

    vector<pair<int, int> > number_of_people_to_be_added;
    int size = number_of_people_to_be_added.size();
    REP(i,0,L) {
        int nearest_number = lower_bound(all(rounded_up_numbers), C[i]) - rounded_up_numbers.begin();
        if (nearest_number == size) continue; // not found
        if (nearest_number != C[i]) number_of_people_to_be_added.push_back(make_pair(nearest_number - C[i], i));
    }
    sort(all(number_of_people_to_be_added));

    // add remaining people to already picked languages
    for(auto el : number_of_people_to_be_added) {
        int number = el.first;
        int index = el.second;

        if (number > remaining_people) break;

        C[index] += number;
        remaining_people -= number;
    }

    // add remaining people to languages not picked yet (by min)
    int min = lower_bound(all(rounded_up_numbers), 0) - rounded_up_numbers.begin();
    if (min != size) {
        while (remaining_people >= min) {
            C.push_back(min);
            remaining_people -= min;
        }
    }

    // add remaining people to languages not picked yet (all the remaining people)
    if (remaining_people > 0) C.push_back(remaining_people);

    // calculate answer
    int answer = 0;
    for(auto el : C) {
        double percent = 100.0 * el / N;
        answer += round(percent);
    }

    return to_string(answer);
}

int main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> T;
    REP(i,0,T){
        cin >> N >> L;
        REP(j,0,L) {
            int l;
            cin >> l;
            C.push_back(l);
        }
        printf("Case #%d: %s\n",i+1,solve().c_str());
    }
    return 0;
}
