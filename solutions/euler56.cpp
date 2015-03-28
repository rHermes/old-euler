#include <string>
#include <gmpxx.h>

/*
 * Pure bruteforce here!
 */

std::string euler56() {
    int answer = 0;
    mpz_class tmp {0};
    for (unsigned a = 1; a < 100; a++) {
        for (unsigned b = 1; b < 100; b++) {
            mpz_ui_pow_ui(tmp.get_mpz_t(), a, b);

            // decide the digit sum.
            int digitsum = 0;
            for (char digit : tmp.get_str())
                digitsum += digit - '0';

            // Is it larger than answer?
            if (digitsum > answer)
                answer = digitsum;

        }
    }

    return std::to_string(answer);
}
