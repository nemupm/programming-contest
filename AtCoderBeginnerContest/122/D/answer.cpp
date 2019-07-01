#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>

#define REP(i,x,y) for(int i=(x);i<(y);i++)
#define RREP(i,x,y) for(int i=(y)-1;i>=(x);i--)
#define all(x) (x).begin(),(x).end()
// #define int long long

using namespace std;

// conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define dump(x)  cerr << #x << " = " << (x) << endl
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl
#else
#define eprintf(...) 42
#define dump(x) 42
#define debug(x) 42
#endif

typedef long long ll;

const int MAX_N = 100;
const ll MOD = 1e9 + 7;







bool isValid(std::string& key) {
    return key.find("AGC") == std::string::npos &&
                              key.find("ACG") == std::string::npos &&
                                                 key.find("GAC") == std::string::npos &&
                                                                    key.find("AGGC") == std::string::npos &&
                                                                                        key.find("AGTC") == std::string::npos &&
                                                                                                            key.find("AGGC") == std::string::npos &&
                                                                                                                                key.find("ATGC") == std::string::npos;
}

ll solve(int N) {
    std::vector<std::unordered_map<std::string, ll> > dp(N);
    std::string characters = "AGCT";
    for (const char& c : characters) {
        std::string key("TTT");
        key.push_back(c);
        dp[0][key] = 1;
    }
    for (int i = 0; i < N-1; i++) {
        for (const auto& pair : dp[i]) {
            const std::string& key = pair.first;
            ll value = pair.second;
            for (const char& c : characters) {
                std::string nextKey(key.substr(1, 3) + c);
                if( isValid(nextKey) ) {
                    dp[i+1][nextKey] += value;
                    dp[i+1][nextKey] %= MOD;
                }
            }
        }
    }

    ll answer = 0;
    for (const auto& pair : dp[N-1]) {
        answer += pair.second;
        answer %= MOD;
    }

    return answer;
}

signed main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    cout << solve(N) << "\n";
    return 0;
}
