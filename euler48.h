#include <string>
#include <gmpxx.h>

std::string euler48() {
    mpz_class sum { 0 }, power { 0 };

    for (int i = 1; i <= 1000; i++) {
        mpz_ui_pow_ui(power.get_mpz_t(), i, i);
        sum += power;
    }

    std::string answer = sum.get_str();
    return answer.substr(answer.length() - 10);
}

