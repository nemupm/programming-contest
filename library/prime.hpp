vector<int> sieve_of_eratosthenes(int n) {
    vector<int> primes(n);
    for (int i = 2; i < n; ++i)
        primes[i] = i;
    for (int i = 2; i*i < n; ++i)
        if (primes[i])
            for (int j = i*i; j < n; j+=i)
                primes[j] = 0;
    return primes;
}
