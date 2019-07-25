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

struct Queue {
    Queue() {}
    Queue(int N) : s(vector<int>(N)), last(0) {}
    vector<int> s;
    int last;
};

void simulate(int N, vector<int>& A, Queue& queue) {
    unordered_map<int, int> positions; // <number, position>
    unordered_map<int, int> numbers; // <position, number>
    REP(i,0,queue.last) {
        positions[queue.s[i]] = i;
        numbers[i] = queue.s[i];
    }
    for (const int a : A) {
//        cout << "a:" << a << '\n';
        if (positions.find(a) != positions.end() && numbers[positions[a]] == a && positions[a] < queue.last) {
            queue.last = positions[a];
        } else {
            queue.s[queue.last] = a;
            positions[a] = queue.last;
            numbers[queue.last] = a;
            queue.last++;
        }
//        REP(i,0,queue.last) {
//            cout << queue.s[i] << " ";
//        }
//        cout << "\n";
    }
}

vector<int> generateDistanceListToNextIndex(int N, vector<int>& A) {
    vector<int> list(N);
    unordered_map<int, int> previousIndex; // <number, index>

    REP(i,0,N) {
        if (previousIndex.find(A[i]) != previousIndex.end()) {
            list[i] = (i + N - previousIndex[A[i]]) % N;
        }
        previousIndex[A[i]] = i;
    }

    REP(i,0,N) {
        if (list[i] == 0) list[i] = N;
    }

    return list;
}

void solve(int N, int K, vector<int>& A) {
    Queue queue(N);

    if (K > 1) {
        const auto distanceListToNextIndex = generateDistanceListToNextIndex(N, A);

        int cycle = 0, operations = 0, currentIndex = 0;
        while (K > 1) {

        }
    }

    while (count < K) {
        simulate(N, A, queue);
        count++;
        if (queue.last == 0) break;
    }

    stringstream ss;
    REP(i,0,queue.last-1) {
        ss << queue.s[i] << " ";
    }
    if (queue.last != 0) ss << queue.s[queue.last-1];
	cout << ss.str() << '\n';
    return;
}

signed main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> A(N);
    REP(i,0,N) cin >> A[i];
    
    solve(N, K, A);
    
    return 0;
}

