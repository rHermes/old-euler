#include <string>

std::string euler1() {
    int answer = 0;

    for (int x = 3; x < 1000; x += 3)
        answer += x;

    for (int x = 5; x < 1000; x += 5)
        answer += x;

    for (int x = 15; x < 1000; x += 15)
        answer -= x;

    return std::to_string(answer);
}
