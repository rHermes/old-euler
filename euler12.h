#include <string>
#include "common.h"
/*
 * All natural numbers are divisible by 1 and themselves, so the real question
 * is: "What is the value of the first triangle number to have over 498
 * divisiors".
 *
 * This has later been optimized with the tips given in the overview 
 */
std::string euler12() {
    mpz_class answer {0};
    mpz_class max {0};
    mpz_class divis {0};
    for (mpz_class n{1}; max <= 498; n++) {
        if (mpz_even_p(n.get_mpz_t()))
            divis = gmpNumDivisors(n/2) * gmpNumDivisors(n+1);
        else
            divis = gmpNumDivisors(n) * gmpNumDivisors((n+1)/2);
        
        if (divis > max) {
            answer = n;
            max = divis;
        }
    }

    return answer.get_str();
}
