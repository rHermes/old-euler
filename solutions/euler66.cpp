#include <string>
#include <vector>

#include <gmpxx.h>

/*
 * This might be the most beautiful thing I have ever written ;_;
 */

std::vector<mpq_class> euler66_chakravala(const mpz_class& N, std::vector<mpq_class> trip) {
    mpq_class a {trip[0]}, b {trip[1]}, k {trip[2]};

    // If k == 1, were done.
    if (k == 1)
        return trip;

    // find the optimal m.
    mpz_class m {1};
    mpz_class mini {m*m - N};

    for (mpz_class i {m+1}, curm {i*i -N}; mpz_cmpabs(curm.get_mpz_t(), mini.get_mpz_t()) <= 0; i++, curm = (i*i-N)) {
        // Mod is if the denominator after a / b is 1
        mpq_class divi {(a + b * i) / k};
        if (divi.get_den() == 1) {
            mini = curm;
            m = i;
        }
    }

    // Create the new bindings.
    trip[0] = (a*m + N * b) / abs(k);
    trip[1] = (a + m * b) / abs(k);
    trip[2] = (m*m - N) / k;
    return euler66_chakravala(N, trip);
}

std::vector<mpq_class> euler66_findBase(const mpz_class& N) {
    // we set b as 1 and see where we come.
    mpz_class a {1}, b {1}, k {a*a - N*b*b};

    // find the optimal m.
    mpz_class mini = abs(a*a - N * b * b);
    for (a = 2; abs(a*a - N*b*b) <= mini; a++) {
            k = a*a - N*b*b;
            mini = abs(a*a - N*b*b);
    }
    // This is critical, because we go one to far;
    a--;

    return std::vector<mpq_class> {mpq_class(a), mpq_class(b), mpq_class(k)};
}

std::string euler66() {
    mpz_class maxd{0}, maxx{0};
    for (mpz_class D {2}; D < 1000; D++) {
        // Find out if D is square
        if (mpz_perfect_square_p(D.get_mpz_t()))
            continue;

        std::vector<mpq_class> trip {euler66_chakravala(D, euler66_findBase(D))};
        if (trip[0].get_num() > maxx) {
            maxx = trip[0].get_num();
            maxd = D;
        }
    }

    return maxd.get_str();
}
