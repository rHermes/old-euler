#include <string>
#include <cstdint>

/*
 * I didn't implement a lookup table here as it would only slow the program
 * down for such a small N. This would however shave of a lot of time if N
 * was larger.
 */

std::string euler14() {
    uint_fast64_t answer   = 0, maxchain = 0;

    for (uint_fast64_t N = 1; N < 1000000; N++) {
        uint_fast64_t chain = 1, n = N;

        while (n != 1) {
            if ( (n % 2) == 0 ) {
                n /= 2;
                chain++;
            } else {
                // We do two steps in once, as we know that the next number is
                // even.
                n      = (3 * n + 1) / 2;
                chain += 2;
            }
        }

        if (chain > maxchain) {
            answer   = N;
            maxchain = chain;
        }
    }

    return std::to_string(answer);
}
