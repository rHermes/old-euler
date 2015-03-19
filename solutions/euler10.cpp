#include <gmpxx.h>
#include <string>
#include <cstdint>

#include "../constants.hpp"

std::string euler10() {
    mpz_class answer(0);

    for (uint_fast64_t prime : primes1) {
        if (prime >= 2000000)
            break;

        answer += prime;
    }

    return answer.get_str();
}
