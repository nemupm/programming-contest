#include "bits/stdc++.h"

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

const ll MOD = 1e9 + 7;
const int DAYS = 100;

void solve(int caseIndex) {
    vector<pair<int, int>> nums;
    int maxCandidate;
    REP(i,1,DAYS + 1) {
        int ithDay;
        cin >> ithDay;
        assert(ithDay == i);

        if (i == 96) {
            sort(nums.begin(), nums.end());
            REP(j,0,5) {
                maxCandidate = j;
                if (nums[j].first> nums[0].first + j) {
                    break;
                }
            }
        }

        if (i <= 90) {
            cout << i % 15 + 1 << " " << i << '\n';
        } else if (i <= 95) {
            int P = 0, V = i % 5 + 16;
            int num, token;
            cout << V << " " << P << '\n';
            cin >> num;
            assert(num != -1);
            REP(j,0,num) {
                cin >> token;
                assert(token != -1);
            }
            nums.push_back({num, -V});
        } else if (i <= 99) {
            cout << -nums[(i-96)%(max(maxCandidate-1,1)) + 1].second << " " << i << '\n';
        } else if (i == 100) {
            cout << -nums[0].second << " " << i << '\n';
        } else {
            assert(false);
        }
    }

    return;
}

signed main() {
    int T;
    cin >> T;

    REP(i,1,T+1) {
        solve(i);
    }

    return 0;
}
