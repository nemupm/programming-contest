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

signed main(){
    ll N, M, X;
    cin >> N >> M >> X;
    vector<ll> H(N);
    rep(i,0,N) cin >> H[i];
    vector<unordered_map<int,ll>> distances(N+1);
    rep(i,0,M) {
        ll a, b, t;
        cin >> a >> b >> t;
        distances[a][b] = t;
        distances[b][a] = t;
    }
    vector<ll> dp(N+1, LLONG_MAX);
    priority_queue<pair<ll, int>, vector<pair<ll,int>>, greater<pair<ll,int>> > que;
    que.push({0, 1});
    dp[1] = 0;
    while(!que.empty()) {
        const int & current = que.top().second;
        que.pop();
        const int & height = (X >= dp[current]) ? (X - dp[current]) : 0;
        for (const auto & p : distances[current]) {
            const int next = p.first;
            const int distance = p.second;
            if (distance > H[current]) continue;
            ll cost;
            if (height > distance && height - distance > H[next]) {
                cost = distance + (height - distance - H[next]);
            } else if (height > distance) {
                cost = distance;
            } else {
                cost = distance + (distance - height);
            }
            if (dp[next] > dp[current] + cost) {
                dp[next] = dp[current] + cost;
                que.push({dp[next], next});
            }
        }
    }
    if (dp[N] == LLONG_MAX) {
        cout << -1 << endl;
        return 0;
    }
    ll answer = dp[N];
    if (X >= dp[N]) {
        answer += H[N] - (X - dp[N]);
    } else {
        answer += H[N];
    }
    cout << answer << endl;
    return 0;
}
