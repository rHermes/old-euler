#include <string>

std::string euler2() {
    int answer = 2;
    int fib1   = 3;
    int fib2   = 5;
    int temp   = 0;

    while (fib2 < 4000000) {
        temp = fib1;
        fib1 = fib2;
        fib2 = temp + fib2;

        if ( (fib1 % 2) == 0 )
            answer += fib1;
    }

    return std::to_string(answer);
}
