#include <string>
#include <gmpxx.h>

/*
 * Since F_n is asymptotic to (phi^n)/sqrt(5) the number of digits in F_n is
 * asymptotic to n * log10(phi) which is roughly 0.2090 * n. If we want a
 * starting point we can set up:
 *
 * 1000 = 0.2090 * n <=> n = 1000/0.2090
 *
 * And iterate down wards.
 */

std::string euler25() {
    unsigned int numdigits = 1000;
    int          answer    = (int)numdigits / 0.2090;
    mpz_class    fibnum    = 0;

    mpz_fib_ui(fibnum.get_mpz_t(), answer);

    // While we still have numdigits or more, get one down
    for ( ; fibnum.get_str().length() >= numdigits; mpz_fib_ui(fibnum.get_mpz_t(), answer) )
        answer--;

    // we went one to far.
    answer++;
    return std::to_string(answer);
}
