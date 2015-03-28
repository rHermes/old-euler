#include <string>
#include <cmath>

/*
 * Tried to find this one out cleverly, but I failed, so I had to resort to a
 * bruteforce solution. :(
 */

// Checks if a number is pentagonal
bool euler44_isP(int x) {
    double n = sqrt(24*x + 1.0) + 1.0;
    return (fmod(n, 6.0) == 0.0);
}

std::string euler44() {
    constexpr int limit = 3000;
    for (int j = 1; j < limit; j++) {
        int pj = (j * (3*j - 1))/2;
        for (int k = j+1; k < limit; k++) {
            int pk = (k * (3*k - 1))/2;

            if (euler44_isP(pk - pj) && euler44_isP(pk + pj))
                return std::to_string(pk - pj);

        }
    }

    return "-1";
}
