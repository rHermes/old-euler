#include <string>
#include <algorithm>

#include <gmpxx.h>

#include "../constants.hpp"

/*
 * First time I've used exceptions to just ignore some errors. It is dirty, but
 * I can come back and fix it later.
 */

std::string euler35() {
    int answer = 0;

    for (auto prime : primes1) {
        if (prime >= 1000000)
            break;

        std::string num1 = std::to_string(prime);
        std::string num2 = num1;
        std::rotate(num2.begin(), num2.begin() + 1, num2.end());

        int add = 1;
        while (num1 != num2) {
            try {
                mpz_class num3 (num2);
                if (mpz_probab_prime_p(num3.get_mpz_t(), 25)) {
                    std::rotate(num2.begin(), num2.begin() + 1, num2.end());
                } else {
                    add = 0;
                    break;
                }
            } catch (std::exception& e) {
                add = 0;
                break;
            }
        }

        answer += add;
    }

    return std::to_string(answer);
}
