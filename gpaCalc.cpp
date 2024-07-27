//
// Created by crisr on 7/9/2024.
//

#include "gpaCalc.h"

float gpaCalc::calculate(const int choice){
    if(choice == 1) {gpaCalc::termGPA();}
    else if(choice == 2) {gpaCalc::cumulativeGPA();}
    else if(choice == 3) {gpaCalc::idealGPA();}
    else {gpaCalc::currentGPA();}
}

float gpaCalc::termGPA() {
    return 0;
}

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
}

float gpaCalc::idealGPA() {
    return 0;
}

float gpaCalc::currentGPA() {
    return 0;
}
