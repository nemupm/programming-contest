#include "bits/stdc++.h"

#define REP(i,x,y) for(int i=(x);i<(y);i++)
#define RREP(i,x,y) for(int i=(y)-1;i>=(x);i--)
#define all(x) (x).begin(),(x).end()
#define int long long

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

long long modPow(long a, long x, long p) {
    //calculates a^x mod p in logarithmic time.
    long res = 1;
    while(x > 0) {
        if( x % 2 != 0) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        x /= 2;
    }
    return res;
}

long modInverse(long a, long p) {
    //calculates the modular multiplicative of a mod m.
    //(assuming p is prime).
    return modPow(a, p-2, p);
}
ll combination(long n, long k) {
    ll p = MOD;
// calculates C(n,k) mod p (assuming p is prime).

    long numerator = 1; // n * (n-1) * ... * (n-k+1)
    for (int i=0; i<k; i++) {
        numerator = (numerator * (n-i) ) % p;
    }

    long denominator = 1; // k!
    for (int i=1; i<=k; i++) {
        denominator = (denominator * i) % p;
    }

    // numerator / denominator mod p.
    return ( numerator* modInverse(denominator,p) ) % p;
}

void solve(int N, int K) {

    REP(i,1,K+1) {
        ll answer = 0;
        answer = combination(K-1,i-1) * combination(N-K-1,i) % MOD;
        answer = (answer + ((2 * combination(K-1,i-1)) % MOD) * combination(N-K-1,i-1) % MOD) % MOD;
        if (i-2 >= 0) answer = (answer + (combination(K-1,i-1) * combination(N-K-1,i-2)) % MOD) % MOD;
        cout << answer << '\n';
    }

//	stringstream ss;
//    ss << answer;

    return;
}

signed main() {
    int N, K;
    cin >> N >> K;
    
//    vector<int> A(N);
//    REP(i,0,N) cin >> A[i];
    
    solve(N, K);
    
    return 0;
}

