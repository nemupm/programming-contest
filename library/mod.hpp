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
    struct mint {
        long long x;
        mint(long long x = 0) : x((x%MOD+MOD)%MOD){}
        mint operator-() const { return mint<MOD>(-x);}
        mint& operator+=(const mint<MOD> a) {
            if ((x += a.x) >= MOD) x -= MOD;
            return *this;
        }
        mint& operator-=(const mint<MOD> a) {
            if ((x += MOD-a.x) >= MOD) x -= MOD;
            return *this;
        }
        mint& operator*=(const mint<MOD> a) {
            (x *= a.x) %= MOD; return *this;
        }
        mint operator+(const mint<MOD> a) const { return mint<MOD>(*this) += a;}
        mint operator-(const mint<MOD> a) const { return mint<MOD>(*this) -= a;}
        mint operator*(const mint<MOD> a) const { return mint<MOD>(*this) *= a;}
        mint pow(long long t) const {
            if (!t) return 1;
            mint<MOD> a = pow(t>>1);
            a *= a;
            if (t&1) a *= *this;
            return a;
        }

        mint inv() const { return pow(MOD-2);}
        mint& operator/=(const mint<MOD> a) { return *this *= a.inv();}
        mint operator/(const mint<MOD> a) const { return mint<MOD>(*this) /= a;}
    };
}
std::istream& operator>>(std::istream& is, const mod::mint<MOD>& a) { return is >> a.x;}
std::ostream& operator<<(std::ostream& os, const mod::mint<MOD>& a) { return os << a.x;}