namespace lib {
    long long gcd(long long a, long long b) {
        if (a < b) swap(a, b);
        long long r = a % b;
        while(r!=0){
            a = b;
            b = r;
            r = a % b;
        }
        return b;
    }

    long long lcm(long long a, long long b) {
        return a * b / gcd(a, b);
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
