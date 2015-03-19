#include <string>
#include <gmpxx.h>

#include "../common.hpp"

std::string euler501() {
    mpz_class answer {224427};
    mpz_class limit {1000000000000};
    for (mpz_class i {1000000}; i < limit; i++) {
        if (gmpDivisorFunction(0, i) == 8) {
            answer++;
        }
    }

    return answer.get_str();
}
