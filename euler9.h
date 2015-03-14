#include <string>

#include "common.h"

/*
 * We set up the conditions that
 *
 * 1)   0 < a < b < c
 * 2)   a + b + c = 1000
 * 3)   a^2 + b^2 = c^2
 *
 * From this we can deduct that
 *
 *      b = 1000*(500-a)/(1000-a)
 *
 * So all we have to do is find an "a" between 1 and 499 so that b is an
 * integer. Then all we have to do is plugg a and b into the formula.
 */

std::string euler9() {
    int answer = 0, a = 0;
    double b;

    do {
        a++;
        b = ( 1000.0 * (500 - a) ) / (1000 - a);
    } while ( !isInteger(b) );

    answer = a * (int)b * (1000 - a - (int)b);

    return std::to_string(answer);
}

