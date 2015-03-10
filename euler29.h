#include <string>
#include <cmath>
#include <set>

std::string euler29() {
    std::set<double> powers;
    for(double a = 2; a <= 100; a++)
        for (double b = 2; b <= 100; b++)
            powers.insert(pow(a,b));

    return std::to_string(powers.size());
}
