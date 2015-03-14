#include <string>
#include <cstdint>

/*
 * Here we are given the smallest number divisible by each natural number under
 * 10, which is 2520. We will use this for our increment.
 */

std::string euler5() {
    uint_fast64_t answer;

    for (answer = 2520 ; ; answer += 2520)
        if ( (answer % 11) == 0 && (answer % 12) == 0 && (answer % 13) == 0 &&
             (answer % 14) == 0 && (answer % 15) == 0 && (answer % 16) == 0 &&
             (answer % 17) == 0 && (answer % 18) == 0 && (answer % 19) == 0 &&
             (answer % 20) == 0 )
            break;

    return std::to_string(answer);
}

