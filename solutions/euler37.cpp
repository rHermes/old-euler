#include <string>
#include <gmpxx.h>
#include <cstdint>
/*
 * For this I just gussed an upper bound, until it gave me the right answer.
 *
 * There are smarter ways to do this, but I'm lazy :)
 */

std::string euler37() {
    mpz_class answer {0};

    // Remember to start at 11!
    for (mpz_class prime {12}; prime < 1000000; mpz_nextprime(prime.get_mpz_t(), prime.get_mpz_t())) {
        // check if nubmer is all prime if it is prime all the way
        bool trunc = true;
        uint_fast64_t digits = 1;
        mpz_class tmp = prime;

        // Check right truncation, all but the last possibility.
        while (tmp > 10) {
            digits *= 10;
            tmp /= 10;
            if (!mpz_probab_prime_p(tmp.get_mpz_t(), 25)) {
                trunc = false;
                break;
            }
        }

        // If the last digit isn't prime we move on.
        if (!trunc || !mpz_probab_prime_p(tmp.get_mpz_t(), 25)) {
            continue;
        }

        // Now do left truncation
        tmp = prime;
        while (tmp > 10) {
            tmp = tmp % digits;
            digits /= 10;

            if (!mpz_probab_prime_p(tmp.get_mpz_t(), 25)) {
                trunc = false;
                break;
            }
        }

        // If the last digit isn't prime we move on.
        if (!trunc || !mpz_probab_prime_p(tmp.get_mpz_t(), 25)) {
            continue;
        }

        answer += prime;
    }

    return answer.get_str();
}
