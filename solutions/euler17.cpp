#include <string>
#include <map>
#include <cstdint>

std::string euler17_cardinal(int n) {
    std::map<int,std::string> lookup;
    lookup[1]  = "one";
    lookup[2]  = "two";
    lookup[3]  = "three";
    lookup[4]  = "four";
    lookup[5]  = "five";
    lookup[6]  = "six";
    lookup[7]  = "seven";
    lookup[8]  = "eight";
    lookup[9]  = "nine";
    lookup[10] = "ten";

    lookup[11] = "eleven";
    lookup[12] = "twelve";
    lookup[13] = "thirteen";
    lookup[14] = "fourteen";
    lookup[15] = "fifteen";
    lookup[16] = "sixteen";
    lookup[17] = "seventeen";
    lookup[18] = "eighteen";
    lookup[19] = "nineteen";

    lookup[20] = "twenty";
    lookup[30] = "thirty";
    lookup[40] = "forty";
    lookup[50] = "fifty";
    lookup[60] = "sixty";
    lookup[70] = "seventy";
    lookup[80] = "eighty";
    lookup[90] = "ninety";

    lookup[100] = "onehundred";
    lookup[200] = "twohundred";
    lookup[300] = "threehundred";
    lookup[400] = "fourhundred";
    lookup[500] = "fivehundred";
    lookup[600] = "sixhundred";
    lookup[700] = "sevenhundred";
    lookup[800] = "eighthundred";
    lookup[900] = "ninehundred";

    lookup[1000] = "onethousand";

    std::string answer = "";

    if ( lookup.find(n) != lookup.end() )
        answer += lookup[n];

    else if (n < 100) {
        // Imagen number written as "ab"
        int b = n % 10;
        int a = n / 10;

        answer += lookup[a * 10] + lookup[b];
    } else if (n < 1000) {
        // Imagen number written as "abc"
        int a = n / 100;
        int b = (n % 100) / 10;
        int c = (n % 100) % 10;

        answer += lookup[a] + "hundredand";

        if ( lookup.find(b * 10 + c) != lookup.end() )
            answer += lookup[b * 10 + c];
        else
            answer += lookup[b * 10] + lookup[c];
    }

    return answer;
}

std::string euler17() {
    uint_fast64_t answer = 0;

    for (int i = 1; i <= 1000; i++)
        answer += euler17_cardinal(i).length();

    return std::to_string(answer);
}
