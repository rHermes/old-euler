#pragma once
#include <cmath>
#include <cstdint>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <gmpxx.h>

/*
 * This is a file with common functons.
 */
bool isInteger(double d) {
    double intpart;
    return std::modf(d, &intpart) == 0.0;
}

/* This is slow ass, but will work. */
std::vector<mpz_class> gmpPrimeFactorTrial(mpz_class N) {
    std::vector<mpz_class> factors;

    // Get rid of all the 2s
    while (mpz_even_p(N.get_mpz_t())) {
        factors.push_back(mpz_class{2});
        N /= 2;
    }
    
    // Get the max factor.
    mpz_class maxFactor;
    mpz_sqrt(maxFactor.get_mpz_t(), N.get_mpz_t());

    for (mpz_class factor {3}; N > 1 && factor <= maxFactor; factor += 2) {
        while ((N % factor) == 0) {
            factors.push_back(factor);
            N /= factor;
            mpz_sqrt(maxFactor.get_mpz_t(), N.get_mpz_t());
        }
    }
    
    // If N isn't 1 we know it is prime
    if (N != 1)
        factors.push_back(N);

    return factors;
}

/* This is slow ass, but will work. */
std::map<mpz_class,mpz_class> gmpPrimeFactorTrialExp(mpz_class N) {
    std::map<mpz_class,mpz_class> factors;

    // Get rid of all the 2s
    while (mpz_even_p(N.get_mpz_t())) {
        factors[mpz_class {2}] = factors[mpz_class{2}] + 1;
        N /= 2;
    }
    
    // Get the max factor.
    mpz_class maxFactor;
    mpz_sqrt(maxFactor.get_mpz_t(), N.get_mpz_t());

    for (mpz_class factor {3}; N > 1 && factor <= maxFactor; factor += 2) {
        while ((N % factor) == 0) {
            factors[factor] = factors[factor] + 1;
            N /= factor;
            mpz_sqrt(maxFactor.get_mpz_t(), N.get_mpz_t());
        }
    }
    
    // If N isn't 1 we know it is prime
    if (N != 1)
        factors[N] = factors[N] + 1;

    return factors;
}

/* This can be adjusted later so that all solutions don't have to be edited :) */
std::vector<mpz_class> gmpPrimeFactor(mpz_class N) {
    return gmpPrimeFactorTrial(N);
}

/* Gives back a table of <prime,times> */
std::map<mpz_class, mpz_class> gmpPrimeFactorExp(mpz_class N) {
   return gmpPrimeFactorTrialExp(N); 
}

/* This could be optimized, as you could use some kind of algorithm to decide
 * to skip all even numbers if the number given is odd and so on. */

/* returns a list of numbers that divides N. Does not include 1 and N */
std::vector<mpz_class> gmpDivisibleBy(const mpz_class N) {
    std::vector<mpz_class> divides; 

    const mpz_class limit {N/2};
    for (mpz_class divider{2}; divider <= limit; divider++) {
        if ((N % divider) == 0)
            divides.push_back(divider);
    }

    return divides;
}

mpz_class gmpNumDivisors(const mpz_class N) {
    // first get the prime numbers.
    std::map<mpz_class,mpz_class> primeFactors = gmpPrimeFactorExp(N);
    
    mpz_class answer {1};

    for (auto prime : primeFactors)
        answer *= prime.second + 1;

    return answer;
}
