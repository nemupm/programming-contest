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
const int MAX_PROGRAM = 500;

struct Node {
    Node *R, *P, *S;
    bool all = false;
};

string search(string answer, Node* node, int count) {
    if (count >= MAX_PROGRAM) return "";
    if (node->all) return "";
    if (node->R && node->P) {
        return search(answer + "P", node->P, ++count);
    } else if (node->S && node->R) {
        return search(answer + "R", node->R, ++count);
    } else if (node->P && node->S) {
        return search(answer + "S", node->S, ++count);
    } else if (node->R) {
        return answer + "P";
    } else if (node->S) {
        return answer + "R";
    } else if (node->P) {
        return answer + "S";
    }
    assert(false);
}

void solve(int caseIndex, int A, vector<string>& C) {
    REP(i,0,A) {
        while (C[i].size() < MAX_PROGRAM) C[i] += C[i];
    }

    Node* root = new Node();

    for(const string& program : C) {
        Node* node = root;
        for(const char c : program) {
            if (node->all) break;
            if (c == 'R') {
                if (!node->R) node->R = new Node();
                if (node->R && node->P && node->S) node->all = true;
                node = node->R;
            } else if (c == 'P') {
                if (!node->P) node->P = new Node();
                if (node->R && node->P && node->S) node->all = true;
                node = node->P;
            } else {
                if (!node->S) node->S = new Node();
                if (node->R && node->P && node->S) node->all = true;
                node = node->S;
            }
        }
    }

    Node* node = root;
    string answer = search("", node, 0);

    cout << "Case #" << caseIndex << ": " << (answer.empty() ? "IMPOSSIBLE" : answer) << '\n';

    return;
}

signed main() {
    int T;
    cin >> T;
    
    REP(i,1,T+1) {
        int A;
        cin >> A;
        vector<string> C(A);
        REP(i,0,A) cin >> C[i];
        solve(i, A, C);
    }

    return 0;
}

