#include <string>
#include <map>
#include <cstdint>
#include <gmpxx.h>

#include "../constants.hpp"

/*
 * I think this problem can be solved using dynamic programing, but I'm not
 * quite sure how it would be done. How do one even check if a combination
 * of primes under you?
 *
 * Ended up just bruteforcing it.
 */

std::string euler50() {
    constexpr int limit = 1000000;

    // Find the largest prime under 100;
    int pindex = 0;
    for (; primes1[pindex] < limit; pindex++) {};
    pindex--;

    // loop through all and see what we get.
    std::map<uint_fast64_t,uint_fast64_t> cache;
    for (int i = 0; i <= pindex; i++) {
        uint_fast64_t count = 1;
        uint_fast64_t sum = primes1[i];

        for (int j = i+1; j <= pindex && sum < limit; j++) {
            count += 1;
            sum += primes1[j];

            if (count > cache[sum])
                cache[sum] = count;
        }
    }

    uint_fast64_t answer = 0;
    uint_fast64_t max = 0;
    for (auto& pair : cache) {
        mpz_class tprime {pair.first};
        if (pair.second > max && mpz_probab_prime_p(tprime.get_mpz_t(), 25)) {
            answer = pair.first;
            max = pair.second;
        }
    }

    return std::to_string(answer);
}
