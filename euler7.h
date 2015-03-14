#include <string>
#include <cstdint>

#include "tables/primes1.h"

std::string euler7() {
    return std::to_string(primes1[10000]);
}

