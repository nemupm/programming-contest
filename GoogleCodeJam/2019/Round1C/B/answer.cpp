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
const int SET_NUM = 119;

void solve(int caseIndex, int F) {
    string answer = "";
    vector<bool> sets(SET_NUM, true);
    int f = 0;
    REP(i,0,5) {
        map<char,int> count;
        for (const char c : "ABCDE") {
            count[c] = 0;
        }
        string feedback;
        vector<char> feedbackSets(SET_NUM, 'F');
        REP(j,0,SET_NUM) {
            if (!sets[j]) continue;
            cout << 5*j+1+i << '\n';
            char feedbackChar;
            cin >> feedbackChar;
            feedbackSets[j] = feedbackChar;
            feedback += feedbackChar;
            f++;
            count[feedback.back()]++;
        }
        int minCount = INT_MAX;
        char missingChar;
//        cerr << "===" << i << "---" << '\n';
        for (const char c : "ABCDE") {
//            cerr << c << ":" << count[c] << ":" << minCount << '\n';
            if (!c || answer.find(c) != string::npos) continue;
            minCount = min(count[c], minCount);
        }
//        cerr << "i:" << i << '\n';
//        cerr << "minCount:" << minCount << '\n';
        for (const char c : "ABCDE") {
            if (answer.find(c) != string::npos) continue;
            if (minCount == count[c]) {
                missingChar = c;
                break;
            }
        }
        answer += missingChar;
//        cerr << missingChar << '\n';

        REP(j,0,SET_NUM) {
            if (feedbackSets[j] != missingChar) sets[j] = false;
        }
    }

    while (f < F) {
        string feedback;
        cout << 1 << '\n';
        cin >> feedback;
        f++;
    }

//    cerr << answer << '\n';
    cout << answer << '\n';

    string result;

    cin >> result;
//    cerr << result << '\n';

    if (result == "N") {
        exit(0);
    }

    return;
}

signed main() {
    int T, F;
    cin >> T >> F;

    REP(i,1,T+1) {
        solve(i, F);
    }

    return 0;
}
