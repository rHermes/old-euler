#include <string>

std::string euler2() {
    unsigned int answer = 2, fib1 = 3, fib2 = 5, temp = fib1;
    constexpr unsigned limit = 4000000;

    while (fib2 < limit) {
        temp = fib1;
        fib1 = fib2;
        fib2 = temp + fib2;

        if (fib1 % 2 == 0)
            answer += fib1;
    }

    return std::to_string(answer);
}
