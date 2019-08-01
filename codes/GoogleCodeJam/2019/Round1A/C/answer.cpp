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

void solve(int caseIndex, int N, vector<string>& W) {
    unordered_map<int, unordered_map<string, int> > suffixes;

    for (const auto& w : W) {
        string suffix = "";
        RREP(i,0,w.size()) {
            suffix += w[i];
            suffixes[suffix.size()][suffix]++;
        }
    }

    int answer = 0;

    RREP(i,1,51) {
        for (const auto &pair : suffixes[i]) {
            const string& suffix = pair.first;
            int count = pair.second;

            if (count <= 1) continue;

            RREP(i,1,suffix.size()+1) {
                string key = suffix.substr(0,i);
                suffixes[key.size()][key] -= 2;
            }

            answer += 2;
        }
    }

	stringstream ss;
    ss << answer;

	cout << "Case #" << caseIndex << ": " << ss.str() << '\n';

    return;
}

signed main() {
    int T;
    cin >> T;
    
    REP(i,1,T+1) {
        int N;
        cin >> N;
        vector<string> W(N);
        REP(i,0,N) cin >> W[i];
        solve(i, N, W);
    }

    return 0;
}

