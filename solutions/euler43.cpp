#include <string>
#include <vector>
#include <algorithm>
#include <cstdint>

/*
 * Here it comes in handy to know some divisibilty rules!
 *
 * Here I have just ordered the tests like they were listed but it would be
 * smart to put the expensive tests, such as for 7 at the bottom, to avoid
 * having to do it as much as possible.
 *
 * One could also cut down on the number of iterations, by finding out which
 * three numbers satesfies the various requirements, but when in doubt:
 *
 * BRUTE FORCE!
 */

std::string euler43() {
    uint_fast64_t answer = 0;
    std::vector<uint_fast64_t> digits {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    do {
        // For d_2 d_3 d_4 to be even, d_4 must be even.
        if (digits[3] % 2 != 0)
            continue;

        // For d_3 d_4 d_5 to be divisible by 3, 3 must divide the digit sum!
        if ((digits[2] + digits[3] + digits[4]) % 3 != 0)
            continue;

        // For d_4 d_5 d_6 to be divisible by 5, d_6 must be 0 or 5
        if (digits[5] != 0 && digits[5] != 5)
            continue;

        // For d_5 d_6 d_7 to be divisble by 7, it is best to just check!
        if ((100*digits[4] + 10*digits[5] + digits[6]) % 7 != 0)
            continue;

        // For d_6 d_7 d_8 to be divisble by 11, the alternating sum must be!
        if ((digits[5] - digits[6] + digits[7]) % 11 != 0)
            continue;

        // for d_7 d_8 d_9 to be divisible by 13, it is best to just check!
        if ((100*digits[6] + 10*digits[7] + digits[8]) % 13 != 0)
            continue;

        // for d_8 d_9 d_10 to be divisible by 17, it is best to just check!
        if ((100*digits[7] + 10*digits[8] + digits[9]) % 17 != 0)
            continue;

        answer += digits[9]
            + 10 * digits[8]
            + 100 * digits[7]
            + 1000 * digits[6]
            + 10000 * digits[5]
            + 100000 * digits[4]
            + 1000000 * digits[3]
            + 10000000 * digits[2]
            + 100000000 * digits[1]
            + 1000000000 * digits[0];
    } while (std::next_permutation(digits.begin(), digits.end()));

    return std::to_string(answer);
}
