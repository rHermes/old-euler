/*
This is the executor for each of the other euler tasks. Each of the functions
must return the answer as a string, so as to avoid any overflows.
*/
#include <iostream>
#include <string>
#include <omp.h>

// Problem solutions
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
	std::cout << "The answer to euler " << num << " is: " << answer << ". The answer was found in " << diff*1000 << " miliseconds." << std::endl;

}

int main() {
	// execute the problems.
	executeProblem(7, euler7);
	executeProblem(10, euler10);
	executeProblem(13, euler13);
	executeProblem(15, euler15);
	executeProblem(16, euler15);
	executeProblem(20, euler15);
	executeProblem(349, euler349);
	
	std::cout << std::endl << "The total running time was: " << total * 1000 << " miliseconds." << std::endl;

}
