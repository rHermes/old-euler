#include "tables/primes1.h"
#include <gmpxx.h>
#include <string>
#include <cstdint>

std::string euler10() {
    mpz_class answer(2);

    for (uint_fast64_t prime : primes1) {
        if (prime > 2000000)
            break;
        answer += prime;
    }

    return answer.get_str();
}
