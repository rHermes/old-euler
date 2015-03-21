#include <string>
#include <cstdint>
/*
 * Since we know that any combination of the 2, 5, 10, 20, 50, 100 coins that
 * up to the value of 200 can be completed with x amount of 1 coins, we can
 * say that the amount of possibilities are:
 *
 * a*p100 + b*p50 + c*p20 + d*p10 + e*p5 + f*p2 <= 200
 *
 * So to solve this I simply use 6 for loops, with the starting terms set to
 * the above value and the iteration being the value of the coin.
 *
 * This is a nice way to do it for this particular problem, since the number of
 * coins were so small, but from reading the overview I see that a better way
 * to do this exists through recursion.
 */
std::string euler31() {
    // Since having a 200p is an option we start with 1 in the answer.
    uint_fast64_t answer = 1;
    for (int p100 = 0; p100 <= 200; p100 += 100)
        for (int p50 = p100; p50 <= 200; p50 += 50)
            for (int p20 = p50; p20 <= 200; p20 += 20)
                for (int p10 = p20; p10 <= 200; p10 += 10)
                    for (int p5 = p10; p5 <= 200; p5 += 5)
                        for (int p2 = p5; p2 <= 200; p2 += 2)
                            answer++;

    return std::to_string(answer);
}
