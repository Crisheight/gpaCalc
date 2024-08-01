//
// Created by crisr on 7/9/2024.
//

#include <limits>
#include <iomanip>
#include "gpaCalc.h"

float updatedGPA;

void gpaCalc::calculate(const int choice){

    if(choice == 1) {gpaCalc::semesterGPA();}
    else if(choice == 2) {gpaCalc::cumulativeGPA();}
    else if(choice == 3) {gpaCalc::targetGPA();}
    else if(choice == 4){gpaCalc::currentGPA();}
    else if(choice == 5){exit(0);}

} // End calculate

float gpaCalc::semesterGPA() {
    int classes;
    int creditHours;
    char letterGrade;
    float courseGPA;
    int totalCreditHours = 0;
    float totalSemGPA = 0.0;

    std::map<int, std::pair<int, float>> courseInfo;
    //use the class as a key to access the pair that holds course hour and grade

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

        std::cout << "Enter the letter grade for class " << i + 1 << " (A-F)" << "\n";
        std::cin >> letterGrade;
        letterGrade = toupper(letterGrade);

        while (std::cin.fail() ||
               (letterGrade != 'A' && letterGrade != 'B' && letterGrade != 'C' && letterGrade != 'D' &&
                letterGrade != 'F')) {
            std::cin.clear(); // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Please enter a valid grade (A, B, C, D, F) for class " << i + 1 << ":\n";
            std::cin >> letterGrade;
            letterGrade = toupper(letterGrade);
        }

        courseGPA = gpaCalc::letterGradeToGPA(letterGrade);
        courseInfo[i] = std::pair(creditHours, courseGPA);
    }

    for (auto iter : courseInfo) {
        totalSemGPA += (iter.second.first * iter.second.second);
        totalCreditHours += iter.second.first;
    }

    if (totalCreditHours > 0) {
        totalSemGPA /= totalCreditHours;
    } else {
        totalSemGPA = 0.0; // Handle case where no classes were entered correctly
    }

    std::cout << std::setprecision(3) << totalSemGPA << "\n";
    updatedGPA = totalSemGPA;
    return totalSemGPA;
} // End semesterGPA

float gpaCalc::cumulativeGPA() {
    int terms;
    int totalCreditHours = 0;
    float totalGPA = 0.0;

    std::cout << "Cumulative GPA Calculator, please enter the number of terms:\n";
    std::cin >> terms;

    while (std::cin.fail() || terms < 1) {
        std::cin.clear(); // Clear the error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        std::cout << "Please enter a valid number of terms (at least 1):\n";
        std::cin >> terms;
    }

    for (int i = 0; i < terms; i++) {
        std::cout << "For term " << i + 1 << ":\n";

        int termCreditHours;
        std::cout << "Enter the total number of credit hours for term " << i + 1 << "\n";
        std::cin >> termCreditHours;

        float termGPA = gpaCalc::semesterGPA();

        while (std::cin.fail() || termCreditHours < 1) {
            std::cin.clear(); // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Please enter a valid number of credit hours (at least 1):\n";
            std::cin >> termCreditHours;
        }

        totalGPA += termGPA * termCreditHours;
        totalCreditHours += termCreditHours;
    }

    float cumulativeGPA = 0.0;
    if (totalCreditHours > 0) {
        cumulativeGPA = totalGPA / totalCreditHours;
    }

    std::cout << "Cumulative GPA: " << std::setprecision(3) << cumulativeGPA << "\n";
    updatedGPA = cumulativeGPA;
    return cumulativeGPA;
} // End cumulativeGPA

float gpaCalc::targetGPA() {
    std::cout << "Enter the GPA you want to achieve: ";
    return 0;
} // End targetGPA

float gpaCalc::currentGPA() {
    if (updatedGPA > 0) {
        std::cout << updatedGPA;
        return updatedGPA;
    } else {
        std::cout << 0.0;
        return 0;
    }
} // End currentGPA

float gpaCalc::letterGradeToGPA(char grade) {
    switch (grade) {
        case 'A': return 4.0;
        case 'B': return 3.0;
        case 'C': return 2.0;
        case 'D': return 1.0;
        case 'F': return 0.0;
        default: return 0; // Should not reach here
    }
} // End letterGradeToGPA


