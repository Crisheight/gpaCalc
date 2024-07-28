//
// Created by crisr on 7/9/2024.
//

#include <limits>
#include "gpaCalc.h"

float lastKnownGPA;

void gpaCalc::calculate(const int choice){

    if(choice == 1) {gpaCalc::semesterGPA();}
    else if(choice == 2) {gpaCalc::cumulativeGPA();}
    else if(choice == 3) {gpaCalc::idealGPA();}
    else {gpaCalc::currentGPA();}
} // End calculate

float gpaCalc::semesterGPA() {
    int classes;
    int creditHours;
    std::map<int, int> creditHoursPerClass;

    std::cout << "Semester GPA Calculator, please enter the number of classes:\n";
    std::cin >> classes;

    while (std::cin.fail() || classes < 1 || classes > 9) {
        std::cin.clear(); // Clear the error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        std::cout << "Please enter a number between 1 and 9 \n";
        std::cin >> classes;
    }

    for (int i = 0; i < classes; i++) {
        std::cout << "Enter the number of credit hours for class " << i + 1 << "\n";
        std::cin >> creditHours;
        creditHoursPerClass[i] += creditHours;
    }

    return 0;
} // End semesterGPA

float gpaCalc::cumulativeGPA() {
    int terms;
    int creditHours;
    std::map<int, int> creditHoursPerTerm;

    std::cout << "Cumulative GPA Calculator, please enter the number of terms:\n";
    std::cin >> terms;

    for (int i = 0; i < terms; i++) {
        std::cout << "Enter the number of credit hours for term " << i + 1 << "\n";
        std::cin >> creditHours;
        creditHoursPerTerm[i] += creditHours;
    }

    return 0;
} // End cumulativeGPA

float gpaCalc::idealGPA() {
    return 0;
} // End idealGPA

float gpaCalc::currentGPA() {
    if (lastKnownGPA > 0) {
        return lastKnownGPA;
    } else {
        return 0;
    }
} // End currentGPA
