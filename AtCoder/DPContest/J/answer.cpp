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

double getExpectedValue(int N, int i, int j, int k, vector<vector<vector<double>>>& memo) {
    if (i == 0 && j == 0 && k == 0 || i+j+k > N || i<0 || j<0 || k<0) return 0.0;
    if (memo[i][j][k] > 0) return memo[i][j][k];

    double value = N;
    value += i * getExpectedValue(N, i-1, j, k, memo);
    value += j * getExpectedValue(N, i+1, j-1, k, memo);
    value += k * getExpectedValue(N, i, j+1, k-1, memo);
    value /= (i+j+k);

    memo[i][j][k] = value;

    return value;
}

void solve(int N, vector<int>& A) {
    // dp[i][j][k]: 1, 2, 3
    // dp[i][j][k] = i / N * dp[i-1][j][k] + j / N * dp[i+1][j-1][k] + k / N * dp[i][j+1][k-1] + (N-i-j-k) / N * dp[i][j][k] + 1
    // dp[i][j][k] = 1 / (i+j+k) * {i*dp[i-1][j][k] + j*dp[i+1][j-1][k] + k*dp[i][j+1][k-1] + N}

    vector<vector<vector<double>>> memo(N+1, vector<vector<double>>(N+1, vector<double>(N+1, -1)));

	double answer = getExpectedValue(N, count(all(A), 1), count(all(A), 2), count(all(A), 3), memo);
	stringstream ss;
	ss << setprecision(10) << answer;
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

