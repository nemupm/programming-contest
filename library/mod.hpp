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

    long long MOD = 1e9+7;

    struct mint {
        long long x;
        mint(long long x = 0) : x((x%MOD+MOD)%MOD){}
        mint operator-() const { return mint(-x);}
        mint& operator+=(const mint a) {
            if ((x += a.x) >= MOD) x -= MOD;
            return *this;
        }
        mint& operator-=(const mint a) {
            if ((x += MOD-a.x) >= MOD) x -= MOD;
            return *this;
        }
        mint& operator*=(const mint a) {
            (x *= a.x) %= MOD; return *this;
        }
        mint operator+(const mint a) const { return mint(*this) += a;}
        mint operator-(const mint a) const { return mint(*this) -= a;}
        mint operator*(const mint a) const { return mint(*this) *= a;}
        mint pow(long long t) const {
            if (!t) return 1;
            mint a = pow(t>>1);
            a *= a;
            if (t&1) a *= *this;
            return a;
        }

        // for prime mod
        mint inv() const { return pow(MOD-2);}
        mint& operator/=(const mint a) { return *this *= a.inv();}
        mint operator/(const mint a) const { return mint(*this) /= a;}
    };
    std::istream& operator>>(std::istream& is, const mint& a) { return is >> a.x;}
    std::ostream& operator<<(std::ostream& os, const mint& a) { return os << a.x;}
}
