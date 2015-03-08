#include <string>
#include <gmpxx.h>

/*
 * We know that we only need to test 6 digits as 
 *
 * 999999 > 6 * 9^5
 *
 */
std::string euler30() {
    mpz_class answer {0};
    
    // Just pick a random number of digits.
    int a, b, c, d, e, f;
    for (a = 0; a < 10; a++) {
        for (b = 0; b < 10; b++) {
            for (c = 0; c < 10; c++) {
                for (d = 0; d < 10; d++) {
                    for (e = 0; e < 10; e++) {
                        for (f = 0; f < 10; f++) {
                            mpz_class lhs {0};
                            lhs += a * 100000;
                            lhs += b * 10000;
                            lhs += c * 1000;
                            lhs += d * 100;
                            lhs += e * 10;
                            lhs += f * 1;

                            mpz_class rhs {0};
                            rhs += a * a * a * a * a; 
                            rhs += b * b * b * b * b;
                            rhs += c * c * c * c * c;
                            rhs += d * d * d * d * d;
                            rhs += e * e * e * e * e;
                            rhs += f * f * f * f * f;

                            if (lhs == rhs)
                                answer += lhs;
                        }
                    }
                }
            }
        }
    }
    // we don't include 1
    answer -= 1;
    return answer.get_str();
}
