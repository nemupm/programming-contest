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
