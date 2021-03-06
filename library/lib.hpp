namespace lib {
    // a x + b y = gcd(a, b)
    template <typename T>
    T extgcd(T a, T b, T &x, T &y) {
        T g = a;
        x = 1;
        y = 0;
        if (b != 0) {
            g = extgcd<T>(b, a % b, y, x);
            y -= (a / b) * x;
        }
        return g;
    }

    // a x + b y = c
    // x(>=0) is minimum
    template <typename T>
    void extgcd(T a, T b, T &x, T &y, T c) {
        T g = extgcd<T>(a, b, x, y);
        if (g < 0) {
            g *= -1;
            x *= -1;
            y *= -1;
        }
        assert(abs(c) % g == 0);
        T l = lcm(abs(a), abs(b));
        if ((x < 0) ^ (c < 0)) {
            x = abs(l / a) - abs(x) % abs(l / a);
        }
        x = (__int128(abs(x)) % abs(l / a)) * (__int128(abs(c) / g) % abs(l / a));
        x %= abs(l / a);
        assert(x >= 0);
        y = (__int128(c) - __int128(a) * x) / b;
        assert(__int128(a) * x + __int128(b) * y == c);
    }

    long long floor(long long a, long long b) {
        if (abs(a) % abs(b) == 0) return a / b;
        if ((a > 0 && b > 0) || (a < 0 && b < 0)) return a / b;
        else return a / b - 1;
    }

    long long ceil(long long a, long long b) {
        if (abs(a) % abs(b) == 0) return a / b;
        if ((a > 0 && b > 0) || (a < 0 && b < 0)) return a / b + 1;
        else return a / b;
    }
}

struct hash_pair {
    static size_t m_hash_pair_random;
    template<class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        size_t seed = 0;
        seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= m_hash_pair_random + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        return seed;
    }
};
size_t hash_pair::m_hash_pair_random = (size_t) random_device()();
