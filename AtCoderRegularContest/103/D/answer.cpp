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

const int MAX_N = 1000;
int N;
ll X[MAX_N];
ll Y[MAX_N];

void solve() {
    int mod2 = (abs(X[0]) + abs(Y[0])) % 2;
    REP(i,0,N) {
        if (mod2 != (abs(X[i]) + abs(Y[i])) % 2) {
            cout << "-1" << "\n";
            return;
        }
    }

    const int M = 32;
    int m = mod2 == 1 ? M : M + 1;
    ll d[M+1];
    cout << m << "\n";
    REP(i,0,M) {
        d[M-i-1] = pow(2,i);
        cout << d[M-i-1];
        if (i != M-1) cout << " ";
    }
    if (mod2 == 0) {
        d[M] = 1;
        cout << " 1\n";
    } else {
        cout << "\n";
    }

    REP(i,0,N) {
        ll x = X[i], y = Y[i];
        REP(j,0,m) {
            ll L, R, U, D;
            L = abs(x - d[j]) + abs(y);
            R = abs(x + d[j]) + abs(y);
            U = abs(x) + abs(y + d[j]);
            D = abs(x) + abs(y - d[j]);
            if (min(min(min(L,R),U),D) == L) {
                x = x - d[j];
                cout << "L";
            } else if (min(min(min(L,R),U),D) == R) {
                x = x + d[j];
                cout << "R";
            } else if (min(min(min(L,R),U),D) == U) {
                y = y + d[j];
                cout << "U";
            } else {
                y = y - d[j];
                cout << "D";
            }
        }
        cout << "\n";
    }

    return;
}

signed main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    REP(i,0,N) {
        cin >> X[i];
        cin >> Y[i];
    }
    solve();
    return 0;
}

