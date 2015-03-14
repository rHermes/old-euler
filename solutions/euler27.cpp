#include <string>
#include <gmpxx.h>

std::string euler27() {
    int maxa = 0;
    int maxb = 0;
    int maxp = 0;
    mpz_class tmp, output;
    for (int a = -999; a < 1000; a++)
        for (int b = 1; b < 1000; b++) {

            // Test them alone, which is the same as only testing at first.
            output = b;
            int n = 1, nump = 0;
            for ( ; mpz_probab_prime_p(output.get_mpz_t(), 25); n++, nump++ )
                output = n*n + a*n + b;

            if (nump > maxp) {
                maxp = nump;
                maxa = a;
                maxb = b;
            }
        }

    return std::to_string(maxa * maxb);
}
