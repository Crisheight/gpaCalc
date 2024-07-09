#include <iostream>
#include <map>
#include "gpaCalc.h"


int main() {
    int terms;
    int creditHours;
    std::map<int, int> creditHoursPerTerm;

    std::cout << "GPA Calculator, please enter the number of terms:\n";
    std::cin >> terms;

    for (int i = 0; i < terms; i++) {
        std::cout << "Enter the number of credit hours for term " << i + 1 << "\n";
        std::cin >> creditHours;
        creditHoursPerTerm[i] += creditHours;
    }

    gpaCalc findMyGPA;
    std::cout << "\n";
    findMyGPA.calculate(creditHoursPerTerm);
    return 0;
}
