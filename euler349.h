#include <cstdint>
#include <map>
#include <string>
typedef int_fast64_t T;

class point {
public:
    T x;
    T y;

    bool operator<(const point &other) const {
        return (x < other.x) || ((x == other.x) && (y < other.y));
    }
};

enum class Direction { up, right, down, left };

Direction newDir(Direction dir, bool clockwise) {
    switch (dir) {
    case (Direction::up) : return (clockwise) ? Direction::right : Direction::left; break;
    case (Direction::right) : return (clockwise) ? Direction::down : Direction::up; break;
    case (Direction::down) : return (clockwise) ? Direction::left : Direction::right; break;
    case (Direction::left) : return (clockwise) ? Direction::up : Direction::down; break;
    }
    
    // Just to silence an error.
    return Direction::up;
}

void moveDir(point* p, Direction dir) {
    switch (dir) {
    case (Direction::up) : p->y += 1; break;
    case (Direction::right) : p->x += 1; break;
    case (Direction::down) : p->y -= 1; break;
    case (Direction::left) : p->x -= 1; break;
    }
}

std::string euler349() {
    /*
    So to solve this problem it is not efficient to run through all the steps,
    as after about 11 000 steps it starts looping in a 104 step cycle. Each
    104 step in this highway adds 12 blocks. Therefor it is only neccecary to
    compute the first 11064 blocks :)
    */

    using namespace std;
    constexpr T limit = 1000000000000000000;
    constexpr T reallimit = limit - 104 * ((limit - 11000) / 104);

    // pos and direction
    point pos{ 0, 0 };
    Direction dir{ Direction::up };

    // Grid - true = black, false = white
    map < point, bool > grid;

    // This holds our answer
    T counter = 0;

    for (T moves = 1; moves <= reallimit; moves++) {
        // Get the iterator to the post.
        auto tile = (grid.insert(make_pair(pos, false))).first;

        if (tile->second) {
            // It is black, so we flip it and rotate 90 degrees anti clockwise
            tile->second = false;
            counter -= 1;
            dir = newDir(dir, false);
        }
        else {
            // It is white, so we flip it and rotate 90 degress clockwise.
            tile->second = true;
            counter += 1;
            dir = newDir(dir, true);
        }

        // Move forward one tile.
        moveDir(&pos, dir);
    }

    // now that we have the pattern, we can just duplicate it up.
    counter += 12 * ((limit - 11000) / 104);

    return to_string(counter);  
}
