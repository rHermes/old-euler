#include <string>
#include <vector>
#include <gmpxx.h>

#include "../common.hpp"

std::string euler23() {
    std::vector<unsigned> abundant;
    bool answerset[20162*2 + 1] = {false};

    // popilate both sets.
    for (unsigned n {1}; n <= 20161; n++)
        if (gmpDivisorFunction(1, n) > 2*n)
            abundant.push_back(n);

    // Let us see what we can make.
    for (unsigned i = 0; i < abundant.size(); i++)
        for (unsigned j = 0; j <= i; j++)
            answerset[abundant[i] + abundant[j]] = true;

    // Go through and make it quick!
    mpz_class answer {0};
    for (int i = 1; i <= 20161; ++i)
        if(!answerset[i])
            answer += i;

    return answer.get_str();
}
