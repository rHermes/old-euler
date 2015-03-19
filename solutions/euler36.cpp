#include <string>
#include <algorithm>
#include <gmpxx.h>
#include "../common.hpp"
/*
 * We only need to check odd numbers as any even number would look like:
 *
 * 1 .... 0
 *
 * In binary!
 */

bool euler36_doublePalindrome(const mpz_class& n) {
    return isPalindrome( n.get_str() ) && isPalindrome( n.get_str(2) );

}

std::string euler36() {
    mpz_class answer { 0 };
    for (mpz_class counter { 1 }; counter < 1000000; counter += 2)
        if ( euler36_doublePalindrome(counter) )
            answer += counter;

    return answer.get_str();
}
