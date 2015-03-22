#include <string>
#include <cmath>
#include <cstdint>

/*
 * One can quite easily create the formulas needed to check if a number is
 * pentagonal and hexagonal. I also found delta T, so a little time is spared
 * not doing more than we need to :)
 *
 * So I am stupid. Every hexagonal number is a triangular number! Delta H
 * is 4n + 1.
 */

std::string euler45() {
    uint_fast64_t answer = 143;
    uint_fast64_t hexagon = answer * (2*answer - 1);

    bool isP = false;


    while (!isP) {
        // Delta H = 4n +1
        hexagon += 4*answer + 1;
        answer++;

        isP = (fmod(sqrt(24*hexagon + 1) + 1.0, 6.0) == 0.0);
    }

    return std::to_string(hexagon);
}
