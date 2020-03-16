#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define rrep(i,x,y) for(ll i=(ll)(y)-1;i>=(x);i--)
#define all(x) (x).begin(),(x).end()
#define dump(x)  cerr << #x << " = " << (x) << endl
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl
//#define int long long

typedef long long ll;
const ll MOD = 1e9 + 7;
const long double EPS = 1e-10;

struct Point {
    ll x, y;
    Point(ll x, ll y) : x(x), y(y) {}
    Point() = default;
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    rep(ti,1,T+1) {
        int N;
        cin >> N;
        vector<Point> points(N);
        rep(i,0,N) cin >> points[i].x >> points[i].y;
        printf("Case #%lld:\n", ti);

        rep(i,0,N) {
            vector<long double> angles;
            rep(j,0,N) {
                if (i == j) continue;
                const ll dx = points[j].x - points[i].x, dy = points[j].y - points[i].y;
                long double radian = atan2(dy, dx);
                if (radian < 0) radian += 2 * M_PI;
                angles.emplace_back(radian);
                angles.emplace_back(radian + 2 * M_PI);
                angles.emplace_back(radian + 4 * M_PI);
            }
            sort(all(angles));
            assert(angles.size() == 3 * N - 3);

            int answer = N-1;
            rep(j,0,N-1) {
                answer = min<int>(answer, distance(lower_bound(all(angles),angles[j]+EPS),lower_bound(all(angles),angles[j]+M_PI - EPS)));
                answer = min<int>(answer, distance(lower_bound(all(angles),angles[j]+M_PI+EPS),lower_bound(all(angles),angles[j]+2*M_PI - EPS)));
            }
            assert(answer >= 0);
            cout << answer << "\n";
        }
    }
    return 0;
}

