#include <string>
#include <set>
#include <gmpxx.h>
#include "../common.hpp"

std::string euler21() {
    mpz_class answer;

    std::set<mpz_class> pairs;
    mpz_class           a, b;

    for (int i = 2; i < 10000; i++) {
        if ( pairs.count(i) )
            continue;

        a = gmpDivisorFunction(1, i) - i;
        b = gmpDivisorFunction(1, a) - a;

        // if they i == b and i != a then its ammicable.
        if (i == b && i != a) {
            pairs.insert({ b, a });
            answer += a + b;
        }
    }

    return answer.get_str();
}
