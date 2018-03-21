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
#include <regex>

#define FOR(i,x,y) for(int i=(x);i<(y);i++)
#define RFOR(i,x,y) for(int i=(y)-1;i>=(x);i--)
#define REP(i,x) for(int i=0;i<(x);i++)
#define RREP(i,x) for(int i=(x)-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()
// #define int long long

#define M_PI 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193;

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

using namespace std;

int T;
int N, K;

double solve(vector< pair<double, double> > rh,
             vector< pair< double, pair<double,double> > > rh2) {
    double answer = 0;
//    sort(rh.begin(),rh.end(), greater< pair<double,double> >());
//    double max_r = rh[0].first;
//    double top = max_r * max_r;
//    answer += top;

    vector<double> rv; // radius vector
    double side = 0;
    sort(rh2.begin(),rh2.end(), greater< pair< double, pair<double,double> > >());
    double min_r = rh2[K-1].second.first; double min_h = rh2[K-1].second.second;
    double min_side = rh2[K-1].first;
    REP(i,K){
        side += rh2[i].first;
        rv.push_back(rh2[i].second.first);
    }
    answer += side;

    sort(rv.begin(),rv.end(),greater< double >());
    double max_diff = 0;
    FOR(i,K,N){
        double diff = 0;
        double r = rh2[i].second.first;
        double h = rh2[i].second.second;
        if(rv[0] < r){
            diff = r * r - rv[0] * rv[0] + rh2[i].first - min_side;
            if(diff > max_diff) max_diff = diff;
        }
    }
    answer += rv[0] * rv[0] + max_diff;

    answer *= M_PI;

    return answer;
}

signed main() {
    // to shorten execution time for iostream
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> T;
    REP(i,T){
        vector< pair<double, double> > rh;
        vector< pair<double, pair<double,double> > > rh2;
        cin >> N >> K;
        REP(j,N){
            double r,h;
            cin >> r >> h;
            eprintf("r:%f,h:%f\n",r,h);
            rh.push_back(pair<double, double>(r, h));
            rh2.push_back(pair< double, pair<double,double> >(2.0 * r * h,pair<double,double>(r,h)));
        }
        printf("Case #%d: %.8f\n",i+1,solve(rh,rh2));
    }
    return 0;
}
