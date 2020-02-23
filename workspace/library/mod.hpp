long long modPow(long long a, long long x, long long p) {
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

long long modInverse(long long a, long long p) {
    //calculates the modular multiplicative of a mod m.
    //(assuming p is prime).
    return modPow(a, p-2, p);
}

long long modFactorial(long long a, long long p) {
    long long fact = 1;
    for (long long i=2; i<=a; i++) {
        fact *= i;
        fact %= p;
    }
    return fact;
}

struct combination {
    void preprocess(long long max_n, long long p) {
        factorials_ = vector<ll>(max_n+1, 1);
        inverse_factorials_ = vector<ll>(max_n+1, 1);
        for (long long i=1; i<max_n+1; i++) {
            factorials_[i] = factorials_[i-1] * i;
            factorials_[i] %= p;
        }
        inverse_factorials_[max_n] = modPow(factorials_[max_n],  p-2, p);
        for (long long i=max_n-1; i>=1; i--) {
            inverse_factorials_[i] = inverse_factorials_[i+1] * (i+1);
            inverse_factorials_[i] %= MOD;
        }

        _is_preprocessed = true;
    }

    long long combination_with_preprocessing(long long n, long long k, long long p) {
        if (!_is_preprocessed) assert(false);

        long long result = factorials_[n];
        result *= inverse_factorials_[k];
        result %= p;
        result *= inverse_factorials_[n-k];
        result %= p;
        return result;
    }

    static long long combination_without_preprocessing(long long n, long long k, long long p) {
        // calculates C(n,k) mod p (assuming p is prime).
        long long numerator = 1; // n * (n-1) * ... * (n-k+1)
        for (int i=0; i<k; i++) {
            numerator = (numerator * (n-i) ) % p;
        }

        long long denominator = 1; // k!
        for (int i=1; i<=k; i++) {
            denominator = (denominator * i) % p;
        }
        // numerator / denominator mod p.
        return ( numerator* modInverse(denominator,p) ) % p;
    }

private:
    vector<ll> factorials_, inverse_factorials_;
    bool _is_preprocessed = false;
};

