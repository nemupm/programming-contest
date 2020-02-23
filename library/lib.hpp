#include "./mod.hpp"

long long getGcd(long long a, long long b) {
    if (a < b) swap(a, b);
    long long r = a % b;
    while(r!=0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

long long getLcm(long long a, long long b) {
    return a * b / getGcd(a, b);
}

ll floor(ll a, ll b) {
    if (abs(a) % abs(b) == 0) return a / b;
    if ((a > 0 && b > 0) || (a < 0 && b < 0)) return a / b;
    else return a / b - 1;
}

ll ceil(ll a, ll b) {
    if (abs(a) % abs(b) == 0) return a / b;
    if ((a > 0 && b > 0) || (a < 0 && b < 0)) return a / b + 1;
    else return a / b;
}
