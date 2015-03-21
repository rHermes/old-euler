#include <string>
#include <vector>
#include <set>
#include <algorithm>

/*
 * This one was really hard! So I did some soul searching and found that
 * I can  divide it into 3 parts: a * b = c. Now let's look at the length of
 * the 3 parts:
 *
 * len(a) + len(b) + len(c) = 9
 * 0 < len(a) <= len(b) <= len(c) <= 9
 *
 * The only possible solutions to this in {len(a),len(b),len(c)} format is:
 * {1,1,7}, {1,2,6}, {1,3,5}, {1,4,4}, {2,2,5}, {2,3,4}
 *
 * I put this into excel and found out which combinations would work and which
 * that would not work. What I'm left with is:
 *
 * {1,4,4} and {2,3,4}
 *
 * So these are the two I'll have to test for each permutations of 9 digits.
 */

std::string euler32() {
    int answer = 0;
    std::vector<short> digits {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::set<int> products;
    while (std::next_permutation(digits.begin(), digits.end())) {
        // Test {1,4,4}
        int a = digits[0];
        int b = digits[1]*1000 + digits[2] * 100 + digits[3] * 10 + digits[4];

        // Test {2,3,4}
        int a2 = digits[0] * 10 + digits[1];
        int b2 = 100*digits[2] + 10 * digits[3] + digits[4];

        // C is the same in both
        int c = digits[5]*1000 + digits[6] * 100 + digits[7] * 10 + digits[8];

        // I use a set to make sure there are no duplicates.
        if (a*b == c || a2*b2 == c)
            products.insert(c);
    }

    for (auto product : products)
        answer += product;

    return std::to_string(answer);
}
