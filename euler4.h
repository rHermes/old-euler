#include <string>
#include "common.h"

/*
 * This problem is fast to solve if you realize that you can write a 6 digit
 * number, written as abccba, can be written as:
 *
 * (100000a + 10000b + 1000c + 100c + 10b + a)
 *
 * which factored out can be written as:
 *
 * 11(9091a + 910b + 100c).
 *
 * This means that since 11 is a prime number, one of the factors that made
 * this number must be divisible by 11. We can use this to filter out a lot
 * of possibilities.
 */

std::string euler4() {
    int answer = 0;

    for (int i = 999; i > 100; i--)
        // 990 is the closest multiple of 11 from 999.
        for (int j = 990; j > 100; j -= 11) {
            int product = i * j;
            if ( product > answer && isPalindrome(product) )
                answer = product;
        }
    return std::to_string(answer);
}
