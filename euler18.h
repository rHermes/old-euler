#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

/*
 * The way I found to index this is in my own opinion quite smart!
 *
 * You define a location in the triangle by F(r, c) = r*padding + c
 *
 * Here we set padding as 100.
 *
 * This also means that since it points to the two under it, it points to
 *
 * F(r, c) + padding and F(r, c) + padding + 1
 *
 */
static std::map<int,std::pair<int,int> > euler18_graph;
static std::map<int,int>                 euler18_weights;
static std::map<int,int>                 euler18_cost;

int euler18_DFS(int key) {
    if ( euler18_cost.find(key) != euler18_cost.end() )
        return euler18_cost[key];

    // If not then it is
    auto node   = euler18_graph[key];
    int  answer = euler18_weights[key];
    answer           += std::max( euler18_DFS(node.first), euler18_DFS(node.second) );
    euler18_cost[key] = answer;
    return answer;
}

std::string euler18() {
    const int n = 15; // Number of rows.

    std::vector<std::vector<int> > input {
        { 75 },
        { 95, 64 },
        { 17, 47, 82 },
        { 18, 35, 87, 10 },
        { 20, 4, 82, 47, 65 },
        { 19, 1, 23, 75, 3, 34 },
        { 88, 2, 77, 73, 7, 63, 67 },
        { 99, 65, 4, 28, 6, 16, 70, 92 },
        { 41, 41, 26, 56, 83, 40, 80, 70, 33 },
        { 41, 48, 72, 33, 47, 32, 37, 16, 94, 29 },
        { 53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14 },
        { 70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57 },
        { 91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48 },
        { 63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31 },
        { 4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23 }
    };

    const unsigned int padding = 100;

    unsigned rownum = 1;

    for (std::vector<int> row : input ) {
        unsigned colnum = 1;

        for (int col : row) {
            int key = rownum * padding + colnum;
            euler18_graph[key]   = std::make_pair(key + padding, key + padding + 1);
            euler18_weights[key] = col;
            colnum++;
        }

        rownum++;
    }

    // set all the lower ones to point to -1
    for ( int i = 1; i <= n; i++) {
        euler18_graph[n * padding + i] = std::make_pair(-1,-1);
        euler18_cost[n * padding + i]  = euler18_weights[n * padding + i];
    }

    unsigned int answer = euler18_DFS(padding + 1);
    return std::to_string(answer);
}
