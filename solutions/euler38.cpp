#include <string>
#include <algorithm>

/*
 * First of all we setup the equations as
 *
 * a * n = b
 *
 * I fiddled with this in excel and found out that the largest a we can have,
 * as n > 1, is 9999. Now that I have an upper bound I guess the next move is
 * to brute force!
 *
 * Realized something. a also has to be pandigital!
 *
 * I guess that the number starts with 9 and since 4 is the only viable range,
 * that leaves us with just the range a = [9123, 9876]
 *
 */

std::string euler38() {
    for (int a =  9876; a >= 9123; a--) {
        // This is a smart way of doing concat(a*1, a*2);
        int al = a * 100002;

        // This checks if the string is a pandigital.
        std::string perm = std::to_string(al);
        std::sort(perm.begin(), perm.end());
        if (perm == "123456789")
            return std::to_string(al);
    }
    // This will always be wrong
    return std::to_string(-1);
}
