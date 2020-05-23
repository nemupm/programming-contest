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

    template <long long MOD>
    struct Int {
        long long x;
        Int(long long x = 0) : x((x % MOD + MOD) % MOD){}
        Int operator-() const { return Int<MOD>(-x);}
        Int& operator+=(const Int<MOD> a) {
            if ((x += a.x) >= MOD) x -= MOD;
            return *this;
        }
        Int& operator-=(const Int<MOD> a) {
            if ((x += MOD-a.x) >= MOD) x -= MOD;
            return *this;
        }
        Int& operator*=(const Int<MOD> a) {
            (x *= a.x) %= MOD; return *this;
        }
        Int operator+(const Int<MOD> a) const { return Int<MOD>(*this) += a;}
        Int operator-(const Int<MOD> a) const { return Int<MOD>(*this) -= a;}
        Int operator*(const Int<MOD> a) const { return Int<MOD>(*this) *= a;}
        Int pow(long long t) const {
            if (!t) return 1;
            Int<MOD> a = pow(t >> 1);
            a *= a;
            if (t&1) a *= *this;
            return a;
        }

        Int inv() const { return pow(MOD - 2);}
        Int& operator/=(const Int<MOD> a) { return *this *= a.inv();}
        Int operator/(const Int<MOD> a) const { return Int<MOD>(*this) /= a;}
    };
}
std::istream& operator>>(std::istream& is, const mod::Int<MOD>& a) { return is >> a.x;}
std::ostream& operator<<(std::ostream& os, const mod::Int<MOD>& a) { return os << a.x;}