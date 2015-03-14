#include <string>
#include <gmpxx.h>

/*
 * We only need to test up to 7 digits as that is when n * 9! is less than the
 * largest 7 digit number.
 *
 * But I take a guess that it is actualy only 6 digits.
 */

std::string euler34() {
    mpz_class answer { 0 };
    mpz_class sum { 0 };
    const int factorial[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

    for (mpz_class counter { 3 }; counter < 1000000; counter++) {
        sum = 0;

        for ( char digit : counter.get_str() )
            sum += factorial[digit - '0'];

        if (sum == counter)
            answer += counter;
    }

    return answer.get_str();
}
