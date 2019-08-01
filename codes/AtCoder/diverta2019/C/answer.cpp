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

void solve(int N, vector<string>& S) {
    int answer = 0;
    for (const string& s : S) {
        string::size_type pos = s.find("AB");
        while (pos != string::npos) {
            answer++;
            pos = s.find("AB", pos + 2);
        }
    }

    int countOfHeadBTailA = 0, countOfHeadB = 0, countOfTailA = 0;

    for (const string& s : S) {
        if (s.front() == 'B' && s.back() == 'A') countOfHeadBTailA++;
        else if (s.front() == 'B') countOfHeadB++;
        else if (s.back() == 'A') countOfTailA++;
    }

    if (countOfHeadBTailA > 0) {
        answer += countOfHeadBTailA - 1;
        countOfHeadBTailA = 0;
        if (countOfTailA > 0) {
            answer++;
            countOfTailA--;
        }
        if (countOfHeadB > 0) {
            answer++;
            countOfHeadB--;
        }
    }
    answer += min(countOfHeadB, countOfTailA);
    countOfHeadB = countOfTailA = 0;

    cout << answer << '\n';

    return;
}

signed main() {
    int N;
    cin >> N;
    vector<string> S(N);
    REP(i,0,N) cin >> S[i];
    
    solve(N, S);
    
    return 0;
}

