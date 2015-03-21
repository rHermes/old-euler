#include <string>
#include <map>
#include <vector>
#include <stack>

#include <Eigen/Dense>

/*
 * So I decided to have some fun with this one and generate alle the primitive
 * triples by using matrixes!
 *
 * I must say: I <3 Matrix!
 */

std::string euler39() {
    Eigen::Matrix3i a, b, c;
    a << 1, -2, 2, 2, -1, 2, 2, -2, 3;
    b << 1, 2, 2, 2, 1, 2, 2, 2, 3;
    c << -1, 2, 2, -2, 1, 2, -2, 2, 3;

    Eigen::Vector3i root (3, 4, 5);

    // All collections we need
    std::map<int,int> perimiters;
    std::vector<Eigen::Vector3i> triplets;
    std::stack<Eigen::Vector3i> Q;

    // Generate all triplets which have triplets::sum() <= 1000
    Q.push(root);
    while (!Q.empty()) {
        Eigen::Vector3i triplet {Q.top()};
        Q.pop();

        // If triple::sum() > 1000 then we discard it.
        if (triplet.sum() > 1000)
            continue;

        // If it's not then we add it to triplets and add it's children to the queue.
        triplets.push_back(triplet);

        // Add the children
        Q.push(a * triplet);
        Q.push(b * triplet);
        Q.push(c * triplet);
    }

    // Now loop through them and add all sums while they are not over 1000
    for (Eigen::Vector3i triplet : triplets) {
        // Since you can generate and endless amount of not primitive triplets
        // from any triplet, we need to account for that! Since multiplying the
        // triplet is the same as multiplying the sum, we do this!
        int sum = triplet.sum();
        while (sum <= 1000) {
            perimiters[sum]++;
            sum += triplet.sum();
        }
    }

    // Now we loop through the result and see what the max is.
    int answer = 0;
    for (auto perimiter : perimiters)
        if (perimiters[perimiter.first] > perimiters[answer])
            answer = perimiter.first;

    return std::to_string(answer);
}
