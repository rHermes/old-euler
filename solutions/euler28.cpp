#include <string>

/*
 * There are much better solutions to this, but I found my own here! I noticed
 * that the growth of the numbers in the diagonals follow a pattern:
 *
 * N  : 1 5  17  37  65  101  145  197
 * DN :  4 12  20  28  36   44   56
 * DDN:   8  8    8   8   8    8
 *
 * Once I realized there was a pattern I found the recursive series:
 *
 * a(x, 0) = a0
 * a(x, n) = a(x, n-1) + x + (n-1) * 8
 *
 * For all of our series a0 is 1 and x is the difference between a_1 and a_0.
 *
 * So just use this formula for all n from 1 to 500 for x's: 2, 4, 6, 8
 *
 * You also get the formula:
 *
 * a_(n+1) = a_n + x + 8*n
 *
 * Which can be used to turn this into an iterative algorithm instead of a
 * recursive one. Since since we want a_n to be a_(n+1) we can use += here.
 *
 * As I said there are better ways to do this, but I love the fact that I found
 * my own way to do it!
 */

std::string euler28() {
    int answer = 1, a = 1, b = 1, c = 1, d = 1;
    for (int n = 0; n < 500; n++) {
        a += 2 + 8*n;
        b += 4 + 8*n;
        c += 6 + 8*n;
        d += 8 + 8*n;

        answer += (a + b + c + d);
    }

    return std::to_string(answer);
}
