#include "common.h"
#include <string>
#include <cstdint>
#include <vector>

std::string euler3() {
    std::vector<uint_fast64_t> factors = intPrimeFactor(600851475143);
    return std::to_string( factors.back() );
}
