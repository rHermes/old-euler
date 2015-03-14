#include <string>

#include "common.h"

/*
 * This has later been optimized with the tips given in the overview
 */

std::string euler12() {
    mpz_class answer, divis, n;

    for (n = 1; divis <= 500; n++) {
        if ( mpz_even_p( n.get_mpz_t() ) )
            divis = gmpDivisorFunction(0, n / 2) * gmpDivisorFunction(0, n + 1);
        else
            divis = gmpDivisorFunction(0, n) * gmpDivisorFunction(0, (n + 1) / 2 );
    }

    answer = ( n * (n - 1) ) / 2;

    return answer.get_str();
}
