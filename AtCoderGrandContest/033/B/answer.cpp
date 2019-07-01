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

bool solve(int H, int W, int N, int Sr, int Sc, string& S, string& T) {
    // i回目(0..N-1)の行動終了時点でleft <= right の位置に駒があれば後手が勝てる
    int left = 1, right = W;

    RREP(i,0,N) {
        // 後手は範囲を広げようとする
        if (T[i] == 'R') {
            left = max(1, left-1);
        } else if (T[i] == 'L') {
            right = min(W, right+1);
        }

        // 先手は範囲を縮めようとする
        if (S[i] == 'L') {
            left++;
        } else if (S[i] == 'R') {
            right--;
        }

        if (left > right) return false;
    }
    if (left > Sc || right < Sc) return false;

    // i回目(0..N-1)でtop <= bottom の位置に駒があれば後手が勝てる
    int top = 1, bottom = H;

    RREP(i,0,N) {
        // 後手は範囲を広げようとする
        if (T[i] == 'U') {
            bottom = min(H, bottom+1);
        } else if (T[i] == 'D') {
            top = max(1, top-1);
        }

        // 先手は範囲を縮めようとする
        if (S[i] == 'D') {
            bottom--;
        } else if (S[i] == 'U') {
            top++;
        }

        if (top > bottom) return false;
    }
    if (top > Sr || bottom < Sr) return false;

    return true;
}

signed main() {
    int H, W, N, Sr, Sc;
    cin >> H >> W >> N >> Sr >> Sc;
    string S, T;
    cin >> S >> T;

    cout << (solve(H, W, N, Sr, Sc, S, T) ? "YES" : "NO") << '\n';

    return 0;
}

