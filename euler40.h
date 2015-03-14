#include <string>

std::string euler40() {
    std::string champcons = ".";

    for (int number = 1; champcons.length() <= 1000000; number++ )
        champcons += std::to_string(number);

    int answer = 1;

    for (int digit : { 1, 10, 100, 1000, 10000, 100000, 1000000 })
        answer *= champcons[digit] - '0';

    return std::to_string(answer);
}
