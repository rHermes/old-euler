#include <string>

std::string euler1() {
    unsigned answer = 0, x = 0;
    constexpr unsigned limit = 1000;

    for (x = 3; x < limit; x += 3)
        answer += x;

    for (x = 5; x < limit; x += 5)
        answer += x;

    for (x = 15; x < limit; x += 15)
        answer -= x;

    return std::to_string(answer);
}
