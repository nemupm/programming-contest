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

void solve(int N, vector<int>& d) {
    int answer = 0;
    vector<int> counts(1e5+1, 0);
    REP(i,0,N) {
        counts[d[i]]++;
    }

    int abc = 0;
    int arc = N;
    REP(k,2,1e5+1) {
        abc += counts[k-1];
        arc -= counts[k-1];
//        cout << abc << '\n';
//        cout << arc << '\n';
        if (abc == arc) answer++;
        else if (abc > arc) break;
    }

	stringstream ss;
    ss << answer;
	cout << ss.str() << '\n';

    return;
}

signed main() {
    int N;
    cin >> N;

    vector<int> A(N);
    REP(i,0,N) cin >> A[i];

    solve(N, A);

    return 0;
}

