#include <gmpxx.h>
#include <string>

std::string euler15() {
    mpz_class     answer;
    unsigned long n = 20, k = 20;

    mpz_bin_uiui(answer.get_mpz_t(), n + k, n);
    return answer.get_str();
}
