// #include "mod.hpp"

namespace mod {
    struct combination {
        combination(long long max_n, long long p) : _mod(p) {
            factorials_ = std::vector<long long>(max_n+1, 1);
            inverse_factorials_ = std::vector<long long>(max_n+1, 1);
            for (long long i=1; i<max_n+1; i++) {
                factorials_[i] = factorials_[i-1] * i;
                factorials_[i] %= p;
            }
            inverse_factorials_[max_n] = mod::pow(factorials_[max_n],  p-2, p);
            for (long long i=max_n-1; i>=1; i--) {
                inverse_factorials_[i] = inverse_factorials_[i+1] * (i+1);
                inverse_factorials_[i] %= p;
            }
        }

        long long operator()(long long n, long long k) {
            long long result = factorials_[n];
            result *= inverse_factorials_[k];
            result %= _mod;
            result *= inverse_factorials_[n-k];
            result %= _mod;
            return result;
        }

    private:
        std::vector<long long> factorials_, inverse_factorials_;
        long long _mod;
    };
}

long long combination(long long n, long long k) {
    long long numerator = 1; // n * (n-1) * ... * (n-k+1)
    for (int i=0; i<k; i++) {
        numerator = numerator * (n-i);
    }

    long long denominator = 1; // k!
    for (int i=1; i<=k; i++) {
        denominator = denominator * i;
    }
    
    return numerator / denominator;
}
