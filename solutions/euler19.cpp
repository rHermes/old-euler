#include <string>
#include <boost/date_time/gregorian/gregorian.hpp>

/*
 * Boost made this way too easy. I <3 boost.
 */

std::string euler19() {
    using namespace boost::gregorian;

    date          d(1901, Jan, 1);
    date          end(2000, Dec, 31);
    uint_fast64_t answer = 0;

    for ( ; d <= end; d = d + months(1) )
        if (d.day_of_week() == Sunday)
            answer++;

    return std::to_string(answer);
}
