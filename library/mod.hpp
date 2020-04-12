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
}
