#include <string>
#include <cstdint>
#include <map>
#include "../common.hpp"

std::string euler47() {
    uint_fast64_t answer = 1;
    int counter = 0;
    while (counter != 4) {
        auto factors = intPrimeFactorExp(answer);
        if ((intPrimeFactorExp(answer)).size() == 4)
            counter++;
        else
            counter = 0;

        answer++;
    }

    return std::to_string(answer - 4);
}
