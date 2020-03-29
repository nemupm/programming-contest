namespace mod {
    long long pow(long long a, long long x, long long p) {
        long long res = 1;
        while(x > 0) {
            if( x % 2 != 0) {
                res = (res * a) % p;
            }
            a = (a * a) % p;
            x /= 2;
        }
        return res;
    }

    long long inverse(long long a, long long p) {
        //calculates the modular multiplicative of a mod m.
        //(assuming p is prime).
        return pow(a, p-2, p);
    }

    long long factorial(long long a, long long p) {
        long long fact = 1;
        for (long long i=2; i<=a; i++) {
            fact *= i;
            fact %= p;
        }
        return fact;
    }
}

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
