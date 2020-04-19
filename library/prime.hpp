class Sieve {
    long long n_;
    vector<long long> sieve_, primes_;

public:
    explicit Sieve(long long n=1): n_(n), sieve_(n + 1) {
        sieve_[0] = sieve_[1] = -1;
        for (long long i = 2; i <= n; ++i) {
            if (sieve_[i]) continue;
            primes_.push_back(i);
            sieve_[i] = i;
            for (long long j = i*i; j <= n; j += i) {
                if (!sieve_[j]) sieve_[j] = i;
            }
        }
    }
    bool isPrime(long long x) {
        assert (n_ * n_ >= x);
        if (n_ >= x) {
            return sieve_[x] == x;
        } else {
            for (const auto prime : primes_) {
                if (x % prime == 0) return false;
            }
            return true;
        }
    }
    vector<long long> getPrimes() {
        return primes_;
    }
    vector<pair<long long, int>> getPrimeFactorList(long long x) {
        assert (n_ * n_ >= x);
        vector<long long> factorList;
        if (isPrime(x)) {
            factorList.emplace_back(x);
            x /= x;
        }
        while (x != 1) {
            factorList.push_back(sieve_[x]);
            x /= sieve_[x];
        }
        if (factorList.empty()) return {};
        vector<pair<long long, int>> res(1, pair<long long, int>(factorList[0], 0));
        for (long long p : factorList) {
            if (res.back().first == p) {
                res.back().second++;
            } else {
                res.emplace_back(p, 1);
            }
        }
        return res;
    }
};
