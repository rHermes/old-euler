#include <string>
#include <algorithm>
/*
 * In this program I assume that there will be enough lexicographic permutations.
 */

std::string euler24() {
    std::string answer = "0123456789";
    for (int counter = 1; counter < 1000000; counter++)
        std::next_permutation(answer.begin(), answer.end());

    return answer;
}
