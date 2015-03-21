/*
 *   This is the executor for each of the other euler tasks. Each of the functions
 *   must return the answer as a string, so as to avoid any overflows.
 */
#include <iostream>
#include <string>
#include <omp.h>
#include <iomanip>

#include "problems.hpp"

static double total          = 0.0;
static int    total_problems = 0;
static int    total_correct  = 0;

void executeProblem( int num, std::string (*problem)(), std::string correct_answer) {
    double      start  = omp_get_wtime();
    std::string answer = (*problem)();
    double      end    = omp_get_wtime();

    double diff = end - start;

    // Update global variables.
    total += diff;
    total_problems++;

    std::string correct = "INCORRECT";

    if (answer == correct_answer) {
        total_correct++;
        correct = "CORRECT";
    }

    std::cout << std::left << std::setw(3) << std::setfill(' ') << num;
    std::cout << std::right << std::setw(30) << std::setfill(' ') << answer;
    std::cout << std::right << std::setw(20) << std::setfill(' ') << std::fixed << std::showpoint << std::setprecision(6) << diff * 1000 << " ms";
    std::cout << std::right << std::setw(20) << std::setfill(' ') << correct;
    std::cout << std::endl;
}

int main() {
    // execute the problems.
    executeProblem(1, euler1, "233168");
    executeProblem(2, euler2, "4613732");
    executeProblem(3, euler3, "6857");
    executeProblem(4, euler4, "906609");
    executeProblem(5, euler5, "232792560");
    executeProblem(6, euler6, "25164150");
    executeProblem(7, euler7, "104743");
    executeProblem(8, euler8, "23514624000");
    executeProblem(9, euler9, "31875000");
    executeProblem(10, euler10, "142913828922");
    executeProblem(11, euler11, "70600674");
    executeProblem(12, euler12, "76576500");
    executeProblem(13, euler13, "5537376230");
    executeProblem(14, euler14, "837799");
    executeProblem(15, euler15, "137846528820");
    executeProblem(16, euler16, "1366");
    executeProblem(17, euler17, "21124");
    executeProblem(18, euler18, "1074");
    executeProblem(19, euler19, "171");
    executeProblem(20, euler20, "648");
    executeProblem(21, euler21, "31626");
    executeProblem(22, euler22, "871198282");
    executeProblem(23, euler23, "4179871");
    executeProblem(24, euler24, "2783915460");
    executeProblem(25, euler25, "4782");
    executeProblem(26, euler26, "983");
    executeProblem(27, euler27, "-59231");
    executeProblem(28, euler28, "669171001");
    executeProblem(29, euler29, "9183");
    executeProblem(30, euler30, "443839");
    executeProblem(31, euler31, "73682");
    executeProblem(32, euler32, "45228");
    executeProblem(33, euler33, "100");
    executeProblem(34, euler34, "40730");
    executeProblem(35, euler35, "55");
    executeProblem(36, euler36, "872187");
//    executeProblem(37, euler37, "748317"); A little slow
    executeProblem(38, euler38, "932718654");
    executeProblem(40, euler40, "210");
    executeProblem(41, euler41, "7652413");
    executeProblem(48, euler48, "9110846700");
    executeProblem(67, euler67, "7273");
    executeProblem(81, euler81, "427337");

//  executeProblem(82, euler82, "260324"); // To slow!
    executeProblem(83, euler83, "425185");
    executeProblem(349, euler349, "115384615384614952");

    std::cout << std::endl;

    std::cout << "The total running time was:   " << total * 1000 << " miliseconds." << std::endl;
    std::cout << "The average running time was: " << (total * 1000) / total_problems << " miliseconds." << std::endl;
    std::cout << "There was " << total_correct << " correct answer of " << total_problems << " possible." << std::endl;
}
