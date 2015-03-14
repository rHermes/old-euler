#pragma once

#include <cstdint>
#include <map>
#include <vector>


#include <gmpxx.h>

/*
 * This is a file with common functons.
 */

// Small functions.
bool isInteger(double d);
bool isPalindrome(const int &n);
bool isPalindrome(const std::string& str);

/* This can be adjusted later so that all solutions don't have to be edited :) */
std::vector<mpz_class> gmpPrimeFactor(mpz_class N);

/* Gives back a table of <prime,times> */
std::map<mpz_class, mpz_class> gmpPrimeFactorExp(mpz_class N);

// Gives back a table of <prime,times>
std::map<uint_fast64_t, uint_fast64_t> intPrimeFactorExp(uint_fast64_t N);

std::vector<uint_fast64_t> intPrimeFactor(uint_fast64_t N);

/* returns a list of numbers that divides N. Does not include 1 and N */
std::vector<mpz_class> gmpDivisibleBy(const mpz_class N);

// Defines the Divisor function function.
mpz_class gmpDivisorFunction(const int &x, const mpz_class &n);
