#include <gmpxx.h>
#include <string>

std::string euler20() {
    mpz_class tmp;
    mpz_fac_ui(tmp.get_mpz_t(), 100);
    // Do the cross sum
    std::string num = tmp.get_str();
    uint answer = 0;
    for ( char x : num )
        answer += x - '0';
    
    return std::to_string(answer);  
}
