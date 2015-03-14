#include <string>

#include <gmpxx.h>

std::string euler26() {
    mpz_class answer {7};
    mpz_class max {0};
    for ( mpz_class counter {7}; counter < 1000; mpz_nextprime(counter.get_mpz_t(), counter.get_mpz_t())) {
        mpz_class k {1};
        mpz_class k10 {10};
        while (k10 % counter != 1) {
            k++;
            k10 *= 10;
        }

        if (k > max) {
            max = k;
            answer = counter;
        }
    }

    return answer.get_str();
}
