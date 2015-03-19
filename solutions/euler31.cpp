#include <string>
#include <cstdint>
/*
 * Since we know that zer
 *
 */
std::string euler31() {
    // This should be easy. Include the 200p solution.
    uint_fast64_t answer = 1;
    for (int p100 = 0; p100 <= 200; p100 += 100) {
        for (int p50 = p100; p50 <= 200; p50 += 50) {
            for (int p20 = p50; p20 <= 200; p20 += 20) {
                for (int p10 = p20; p10 <= 200; p10 += 10) {
                    for (int p5 = p10; p5 <= 200; p5 += 5) {
                        for (int p2 = p5; p2 <= 200; p2 += 2) {
                            answer++;
                        }
                    }
                }

            }
        }
    }
    return std::to_string(answer);
}
