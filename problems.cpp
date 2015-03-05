/*
This is the executor for each of the other euler tasks. Each of the functions
must return the answer as a string, so as to avoid any overflows.
*/
#include <iostream>
#include <string>
#include <omp.h>
#include <iomanip>

// Problem solutions
#include "euler1.h"
#include "euler2.h"
#include "euler7.h"
#include "euler10.h"
#include "euler13.h"
#include "euler15.h"
#include "euler16.h"
#include "euler20.h"
#include "euler349.h"

static double total = 0.0;
void executeProblem(int num, std::string (*problem)()) {
	double start = omp_get_wtime();
	std::string answer = (*problem)();
	double end = omp_get_wtime();
	
	double diff = end - start;
	total += diff;	
	std::cout << std::left << std::setw(3) << std::setfill(' ') << num;
	std::cout << std::right << std::setw(30) << std::setfill(' ') << answer;
	std::cout << std::right << std::setw(20) << std::setfill(' ') << std::fixed << std::showpoint << std::setprecision(6) << diff*1000 << " ms";
	std::cout << std::endl;
}

int main() {
	// execute the problems.
    executeProblem(1, euler1);
    executeProblem(2, euler2);
	executeProblem(7, euler7);
	executeProblem(10, euler10);
	executeProblem(13, euler13);
	executeProblem(15, euler15);
	executeProblem(16, euler16);
	executeProblem(20, euler20);
	executeProblem(349, euler349);
	
	std::cout << std::endl << "The total running time was: " << total * 1000 << " miliseconds." << std::endl;

}
