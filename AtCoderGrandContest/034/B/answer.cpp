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

ll solve(string& S) {
    ll answer = 0;

    int left = 0;

    while(left < S.size()-1) {
        if (S[left] != 'A' && !(S[left] == 'B' && S[left+1] == 'C')) {
            left++;
            continue;
        }

        int right = left;

        while (right < S.size()) {
            if (S[right] == 'A') right++;
            else if (right < S.size() - 1 && S[right] == 'B' && S[right+1] == 'C') right += 2;
            else break;
        }

        right--;

//        debug(S.substr(left, right-left+1));

        int i = right, countOfBC = 0;
        while (left <= i) {
            if (S[i] == 'A') {
                answer += countOfBC;
                i--;
            } else if (left < i && S[i-1] == 'B' && S[i] == 'C') {
                countOfBC++;
                i -= 2;
            } else {
                i--;
            }
        }

        left = right+1;
    }

    return answer;
}

signed main() {
    string S;
    cin >> S;

    ll answer = solve(S);

    cout << answer << '\n';
    
    return 0;
}

