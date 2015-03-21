#include <string>

#include <boost/rational.hpp>

/*
 * Kind of proud of this one!
 *
 * So the rules of the game gives us that we want:
 *
 * (10*a + b)/(10*b + c) = a/c
 *
 * Where the following restraints must be met:
 *
 * 0 < a < c < 10
 * 0 < b < 10
 *
 * This comparison can be done with two loops and using boost::rational this
 * becomes very easy!
 */

std::string euler33() {
    boost::rational<int> answer(1,1);
    for (double a = 1; a < 9; a++)
        for (double c = a+1; c < 10; c++)
            for (double b = 1; b < 10; b++)
                if ((10*a + b)/(10*b + c) == a/c)
                    answer *= boost::rational<int>(a,c);

    return std::to_string(answer.denominator());
}
