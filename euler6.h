#include <string>
#include <cstdint>

/*
 * This is trivial, since the sum of all integers up to n can be written as:
 *
 * Sigma(1, n, x) = (n * (n+1))/2
 *
 * And the sum of all the square numbers up to n can be written as:
 *
 * Sigma(1, n, x*x) = (n*(n+1)*(2n+1))/6
 *
 * Refactoring these two statements and we get:
 *
 * (n (1 + n) (2 + 3 n) (-1 + n))/12
 */
std::string euler6() {
    const uint_fast64_t n      = 100;
    uint_fast64_t       answer = ( n * (1 + n) * (2 + 3 * n) * (n - 1) ) / 12;

    return std::to_string(answer);
}
