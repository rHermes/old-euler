all:
	g++ problems.cpp -o problems -O2 -std=c++11 -lgomp -lgmp -lgmpxx -Wall
