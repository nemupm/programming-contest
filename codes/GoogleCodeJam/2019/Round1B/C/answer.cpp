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

class SegmentTree {
public:
    SegmentTree(const vector<int>& values)
        : _n(values.size()), _nodes(values.size() * 4, INT_MAX) {
        _height = (int)ceil(log2(_n)) + 1;
        for (int index = 0; index < _n; index++) {
            _nodes[pow(2,_height-1) + index - 1] = values[index];
        }
        initialize(0);
    }

    int query(const int a, const int b) const { // [a,b)
        assert(a < b);
        return queryRecursively(a,b,0,0,pow(2,_height-1));
    }

    void update(const int i, const int value) {
        updateRecursively(pow(2,_height-1) + i, value);
    }

private:
    vector<int> _nodes;
    int _n = 0;
    int _height = 0;

    int initialize(const int index) {
        if (index >= _nodes.size()) return INT_MAX;

        if (pow(2,_height) <= index) return _nodes[index];
        _nodes[index] = min(min(initialize(2*index+1), initialize(2*index+2)), _nodes[index]);
        return _nodes[index];
    }

    // query: [a,b)
    // current node: i
    // current node's range: [l,r)
    int queryRecursively(const int a, const int b, const int i, const int l, const int r) const {
        if (b <= l || r <= a) return INT_MAX;
        if (a <= l && r <= b) return _nodes[i];

        return min(
                queryRecursively(a,b,2*i+1,l,(l+r)/2),
                queryRecursively(a,b,2*i+2,(l+r)/2,r)
        );
    }

    void updateRecursively(const int i, const int value) {
        if (value > _nodes[i]) return;
        _nodes[i] = value;

        if (i == 0) return;
        update((i-1)/2, value);
    }
};

void solve(int caseIndex, int N, int K, vector<int>& C, vector<int>& D) {
    ll answer = 0;
    SegmentTree segTreeC(C), segTreeD(D);

    REP(i,0,N) {
        if (C[i] - D[i] > K) continue;

        // Case: C is enough large
        // find [l,r) where C[i] is max and C[i] - <max D in [l,r)> >= -K
        int left, right, lLeft, lRight, rLeft, rRight;

        left = 0, right = i+1;
        while (left + 1 < right) {
            int mid = (left + right - 1) / 2;
            int cMax = segTreeC.query(mid, i+1);
            int cMaxInLeft = segTreeC.query(mid, i);
            int dMax = segTreeD.query(mid, i+1);
            if ((mid == i || cMaxInLeft > C[i]) && cMax == C[i] && cMax - dMax <= K) {
                right = mid + 1;
            } else {
                left = mid + 1;
            }
        }
        lLeft = left;
        left = i, right = N;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            int cMax = segTreeC.query(i, mid+1);
            int dMax = segTreeD.query(i, mid+1);
            if (cMax == C[i] && cMax - dMax <= K) {
                left = mid;
            } else {
                right = mid;
            }
        }
        rRight = left + 1;

        answer += (i - lLeft + 1) * (rRight - i);

        // Case: C is too large
        // find [lRight,rLeft) where C[i] is max and C[i] - <max D in [l,r)> > K
        if (D[i] - C[i] > K) {
            left = lLeft, right = i+1;
            while (left + 1 < right) {
                int mid = (left + right - 1) / 2;
                int dMax = segTreeD.query(mid, i+1);
                if (dMax - C[i] > K) {
                    right = mid+1;
                } else {
                    left = mid+1;
                }
            }
            lRight = left;
            left = i, right = rRight;
            while (left + 1 < right) {
                int mid = (left + right) / 2;
                int dMax = segTreeD.query(i, mid+1);
                if (dMax - C[i] > K) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            rLeft = right;

            answer -= (i - lRight + 1) * (rLeft - i);
        }
    }

    cout << "Case #" << caseIndex << ": " << answer << '\n';

    return;
}

signed main() {
    int T;
    cin >> T;

    REP(i,1,T+1) {
        int N, K;
        cin >> N >> K;
        vector<int> C(N), D(N);
        REP(j,0,N) {
            cin >> C[j];
            // reverse sign for SegmentTree
            C[j] *= -1;
        }
        REP(j,0,N) {
            cin >> D[j];
            // reverse sign for SegmentTree
            D[j] *= -1;
        }
        solve(i, N, K, C, D);
    }

    return 0;
}
