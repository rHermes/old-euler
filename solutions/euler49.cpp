#include <string>
#include <algorithm>
#include <gmpxx.h>

/*
 * This is the most ugly bruteforce I have ever done. :(
 */

std::string euler49() {
    std::string answer = "";
    const mpz_class lower_prime {1009};
    const mpz_class upper_prime {9973};
    const mpz_class increment {3330};

    for (mpz_class prime {lower_prime}; prime <= upper_prime; mpz_nextprime(prime.get_mpz_t(), prime.get_mpz_t())) {
        mpz_class prime2 {prime + increment};
        mpz_class prime3 {prime2 + increment};

        std::string sprime {prime.get_str()};
        std::string sprime2 {prime2.get_str()};
        std::string sprime3 {prime3.get_str()};

        if (std::is_permutation(sprime.begin(), sprime.end(), sprime2.begin()) &&
                mpz_probab_prime_p(prime2.get_mpz_t(), 25) &&
            std::is_permutation(sprime.begin(), sprime.end(), sprime3.begin()) &&
                mpz_probab_prime_p(prime3.get_mpz_t(), 25)
                ) {
            answer = sprime + sprime2 + sprime3;
        }

    }

    return answer;
}
