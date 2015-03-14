#pragma once
#include <cmath>
#include <cstdint>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <gmpxx.h>

#include "tables/primes1.h"

/*
 * This is a file with common functons.
 */
bool isInteger(double d) {
    double intpart;

    return std::modf(d, &intpart) == 0.0;
}

bool isPalindrome(const int &n) {
    int num = n, dig, rev = 0;

    while (num > 0) {
        dig = num % 10;
        rev = rev * 10 + dig;
        num = num / 10;
    }

    return n == rev;
}

bool isPalindrome(const std::string& str) {
    int length = str.length();
    int limit  = length / 2;

    for (int i = 0; i < limit; i++)
        if (str[i] != str[length - i - 1])
            return false;

    return true;
}

constexpr uint_fast64_t intCantorPairing(const uint_fast64_t& k1, const uint_fast64_t& k2) {
    return 1 / 2 * (k1 + k2) * (k1 + k2 + 1) + k2;
}

// This is really slow, but it works!
std::vector<uint_fast64_t> intPrimeFactorTrial(uint_fast64_t N) {
    std::vector<uint_fast64_t> factors;

    // get rid of all the 2s
    while ( (N % 2) == 0 ) {
        factors.push_back(2);
        N /= 2;
    }

    // Get the max factor.
    uint_fast64_t maxFactor = (uint_fast64_t) std::sqrt(N);

    // We can iterate by 2
    for (uint_fast64_t factor = 3; N > 1 && factor <= maxFactor; factor += 2)
        while ( (N % factor) == 0 ) {
            factors.push_back(factor);
            N        /= factor;
            maxFactor = (uint_fast64_t) std::sqrt(N);
        }

    // IF N isn't 1 we know it is prime.
    if (N != 1)
        factors.push_back(N);

    return factors;
}

std::map<uint_fast64_t, uint_fast64_t> intPrimeFactorTrialExp(uint_fast64_t N) {
    std::map<uint_fast64_t,uint_fast64_t> factors;

    // get rid of all the 2s
    while ( (N % 2) == 0 ) {
        factors[2]++;
        N /= 2;
    }

    // Get the max factor.
    uint_fast64_t maxFactor = (uint_fast64_t) std::sqrt(N);

    // We can iterate by 2
    for (uint_fast64_t factor = 3; N > 1 && factor <= maxFactor; factor += 2)
        while ( (N % factor) == 0 ) {
            factors[factor]++;
            N        /= factor;
            maxFactor = (uint_fast64_t) std::sqrt(N);
        }

    // IF N isn't 1 we know it is prime.
    if (N != 1)
        factors[N]++;

    return factors;
}

/* This is slow ass, but will work. */
std::vector<mpz_class> gmpPrimeFactorTrial(mpz_class N) {
    std::vector<mpz_class> factors;

    // Get rid of all the 2s
    while ( mpz_even_p( N.get_mpz_t() ) ) {
        factors.push_back(mpz_class { 2 });
        N /= 2;
    }

    // Get the max factor.
    mpz_class maxFactor;
    mpz_sqrt( maxFactor.get_mpz_t(), N.get_mpz_t() );

    for (mpz_class factor { 3 }; N > 1 && factor <= maxFactor; factor += 2)
        while ( (N % factor) == 0 ) {
            factors.push_back(factor);
            N /= factor;
            mpz_sqrt( maxFactor.get_mpz_t(), N.get_mpz_t() );
        }

    // If N isn't 1 we know it is prime
    if (N != 1)
        factors.push_back(N);

    return factors;
}

// This is fast but only for a range
// This will fail for numbers with primes larger than the first million ones.
std::map<mpz_class,mpz_class> gmpPrimeFactorTrialExp(const mpz_class &N) {
    mpz_class    prime = 0, n = N, limit;
    unsigned int p_n   = 0;

    // format <prime, times>
    std::map<mpz_class,mpz_class> factors;

    mpz_sqrt( limit.get_mpz_t(), n.get_mpz_t() );

    for (prime = primes1[p_n]; prime <= limit; ++p_n, prime = primes1[p_n] )
        while ( (n % prime) == 0 ) {
            factors[prime]++;
            n /= prime;
            mpz_sqrt( limit.get_mpz_t(), n.get_mpz_t() );
        }


    if (n > 1)
        factors[n]++;

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

// Gives back a table of <prime,times> */
std::map<uint_fast64_t, uint_fast64_t> intPrimeFactorExp(uint_fast64_t N) {
    return intPrimeFactorTrialExp(N);
}

std::vector<uint_fast64_t> intPrimeFactor(uint_fast64_t N) {
    return intPrimeFactorTrial(N);
}

/* This could be optimized, as you could use some kind of algorithm to decide
 * to skip all even numbers if the number given is odd and so on. */

/* returns a list of numbers that divides N. Does not include 1 and N */
std::vector<mpz_class> gmpDivisibleBy(const mpz_class N) {
    std::vector<mpz_class> divides;

    const mpz_class limit { N / 2 };

    for (mpz_class divider { 2 }; divider <= limit; divider++)
        if ( (N % divider) == 0 )
            divides.push_back(divider);

    return divides;
}

// Defines the Divisor function function.
mpz_class gmpDivisorFunction(const int &x, const mpz_class &n) {
    mpz_class answer { 1 }, temp { 0 }, temp2 { 0 };

    // if x = 0, we can optimize this by setting the number of divisors to the
    // number of times each primefactor appears in the number + 1 times each other.
    for ( auto prime : gmpPrimeFactorExp(n) ) {
        temp2 = 1;

        for (uint_fast64_t j = 1; j <= prime.second; j++) {
            mpz_pow_ui(temp.get_mpz_t(), prime.first.get_mpz_t(), j * x);
            temp2 += temp;
        }

        answer *= temp2;
    }

    return answer;
}
