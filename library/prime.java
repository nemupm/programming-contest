import java.io.*;
import java.util.*;

class Sieve {
    private final long n;
    private final long[] sieve;
    private final List<Long> primes;

    static class PrimeFactor {
        public long prime;
        public int cnt;

        public PrimeFactor(final long prime, final int cnt) {
            this.prime = prime;
            this.cnt = cnt;
        }
    }

    public Sieve(final long n) {
        this.n = n;
        sieve = new long[(int)n+1];
        primes = new ArrayList<Long>();

        for (long i = 2; i <= n; i++) {
            if (sieve[(int)i] != 0) continue;
            primes.add(i);
            sieve[(int)i] = i;
            for (long j = i*i; j <= n; j += i) {
                if (sieve[(int)j] == 0) sieve[(int)j] = i;
            }
        }
    }

    boolean isPrime(final long x) {
        assert n * n >= x;
        if (n >= x) {
            return sieve[(int)x] == x;
        } else {
            for (final var prime: primes) {
                if (x % prime == 0) return false;
            }
            return true;
        }
    }

    final List<Long> getPrimes() {
        return primes;
    }

    final List<PrimeFactor> getPrimeFactors(long x) {
        assert n * n >= x;
        var factorList = new ArrayList<Long>();
        for (int i = primes.size()-1; i >= 0 ; i--) {
            if (n >= x) break;
            while (x % primes.get(i) == 0) {
                x /= primes.get(i);
                factorList.add(primes.get(i));
            }
        }
        if (isPrime(x)) {
            factorList.add(x);
            x /= x;
        }
        assert n >= x;
        while (x != 1) {
            factorList.add(sieve[(int)x]);
            x /= sieve[(int)x];
        }
        var res = new ArrayList<PrimeFactor>();
        if (factorList.isEmpty()) return res;
        res.add(new PrimeFactor(factorList.get(0), 0));
        for (final long factor : factorList) {
            if (res.get(res.size()-1).prime == factor) {
                res.get(res.size()-1).cnt++;
            } else {
                res.add(new PrimeFactor(factor, 1));
            }
        }
        return res;
    }
}
