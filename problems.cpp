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
#include "euler3.h"
#include "euler4.h"
#include "euler5.h"
#include "euler6.h"
//#include "euler7.h"
#include "euler8.h"
#include "euler9.h"
//#include "euler10.h"
#include "euler11.h"
#include "euler12.h"
#include "euler13.h"
#include "euler14.h"
#include "euler15.h"
#include "euler16.h"
#include "euler17.h"
#include "euler18.h"
#include "euler20.h"
#include "euler29.h"
#include "euler30.h"
#include "euler34.h"
#include "euler36.h"
#include "euler48.h"
#include "euler67.h"
#include "euler349.h"

static double total = 0.0;
static int total_problems = 0;

void executeProblem(int num, std::string (*problem)()) {
	double start = omp_get_wtime();
	std::string answer = (*problem)();
	double end = omp_get_wtime();
	
	double diff = end - start;

    // Update global variables.
	total += diff;	
    total_problems++;

	std::cout << std::left << std::setw(3) << std::setfill(' ') << num;
	std::cout << std::right << std::setw(30) << std::setfill(' ') << answer;
	std::cout << std::right << std::setw(20) << std::setfill(' ') << std::fixed << std::showpoint << std::setprecision(6) << diff*1000 << " ms";
	std::cout << std::endl;
}

int main() {
	// execute the problems.
    executeProblem(1, euler1);
    executeProblem(2, euler2);
    executeProblem(3, euler3);
    executeProblem(4, euler4);
    executeProblem(5, euler5);
    executeProblem(6, euler6);
//	executeProblem(7, euler7);
	executeProblem(8, euler8);
	executeProblem(9, euler9);
//	executeProblem(10, euler10);
	executeProblem(11, euler11);
	executeProblem(12, euler12);
	executeProblem(13, euler13);
	executeProblem(14, euler14);
	executeProblem(15, euler15);
	executeProblem(16, euler16);
	executeProblem(17, euler17);
	executeProblem(18, euler18);
	executeProblem(20, euler20);
	executeProblem(29, euler29);
	executeProblem(30, euler30);
	executeProblem(34, euler34);
	executeProblem(36, euler36);
	executeProblem(48, euler48);
    executeProblem(67, euler67);
	executeProblem(349, euler349);
    
    std::cout << std::endl;

	std::cout << "The total running time was:   " << total * 1000 << " miliseconds." << std::endl;
	std::cout << "The average running time was: " << (total * 1000)/total_problems << " miliseconds." << std::endl;
}
