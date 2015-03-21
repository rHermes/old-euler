#include <string>
#include <vector>
#include <algorithm>
#include <gmpxx.h>

/*
 * A couple of optimalizations here:
 *
 * 9 digits cannot be done (1+2+3+4+5+6+7+8+9=45 => always divisble by 3)
 * 8 digits cannot be done (1+2+3+4+5+6+7+8=46 => always divisble by 3)
 *
 * We can go on like this, but I'm guessing the answer is in the max range.
 */

std::string euler41() {
    mpz_class answer {0};
    mpz_class tmp {0};
    std::vector<short> digits {1, 2, 3, 4, 5, 6, 7};

    for (int i = digits.size(); answer == 0; i--) {
        while (std::next_permutation(digits.begin(), digits.end())) {
            tmp = 0;

            // There is no point in going forward if the last digit is even.
            // As it can't be prime if it is.
            if (digits[i-1] % 2 == 0)
                continue;

            // This is probibly some of the more confusing c++ I've ever written.
            for (int j = 0; j < i; j++)
                tmp += (int)pow(10,j)*digits[i-j-1];

            if (mpz_probab_prime_p(tmp.get_mpz_t(), 25) && tmp > answer)
                answer = tmp;
        }

        digits.pop_back();
    }

    return answer.get_str();
}
