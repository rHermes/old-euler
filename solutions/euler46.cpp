#include <string>
#include <gmpxx.h>

/*
 * Just resorted to brute forcing, by finding a maximum n for
 *
 * a = p + 2*n^2
 *
 * by setting p as 1 and refactoring you get.
 *
 * n_max = sqrt((a-1)/2)
 *
 * And for each n from n_max to 1, check if the remainder of
 *
 * a - 2*n^2
 *
 * is a prime.
 */

std::string euler46() {
    mpz_class answer {1};
    bool done = false;

    while (!done) {
        answer += 2;

        // Check if the number is a prime.
        if(mpz_probab_prime_p(answer.get_mpz_t(), 25))
            continue;

        // Find the largest n can be.
        mpz_class n {(answer-1)/2};
        mpz_sqrt(n.get_mpz_t(), n.get_mpz_t());

        done = true;
        for ( ; n > 0; n--) {
            mpz_class a {answer};

            a -= 2 * n * n;
            if (mpz_probab_prime_p(a.get_mpz_t(), 25)) {
                done = false;
                break;
            }
        }
    }

    return answer.get_str();
}
