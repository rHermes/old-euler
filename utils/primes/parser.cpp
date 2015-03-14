#include <fstream>
#include <iostream>
#include <cstdint>
int main() {
    using namespace std;

    ifstream      infile("raw/primes1.txt");
    ofstream      outfile("tables/primes1.h");
    uint_fast64_t a, b, c, d, e, f, g, h;
    while (infile >> a >> b >> c >> d >> e >> f >> g >> h) {
    outfile << a << "," << b << "," << c << "," << d << "," << e << "," << f << "," << g << "," << h << "," << endl;
    }

    outfile.close();
    infile.close();
}
