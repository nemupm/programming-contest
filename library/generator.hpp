namespace generator {
    random_device seed_gen;
    mt19937_64 rnd(seed_gen());

    template <typename T>
    std::vector<T> make_vector (size_t size, T min, T max) {
        std::vector<T> ret(size);
        uniform_int_distribution<T> dist(min, max);
        for (size_t i=0; i<size; i++) {
            ret[i] = dist(rnd);
        }
        return ret;
    }
}
