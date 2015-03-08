#include <string>
#include <vector>
#include <gmpxx.h>
#include "common.h"

std::string euler3() {
    std::vector<mpz_class> factors = gmpPrimeFactor(mpz_class{600851475143});
    return factors.back().get_str();
}
