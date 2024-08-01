//
// Created by crisr on 7/14/2024.
//

#include <iostream>
#include <limits>
#include "menuDriver.h"

int menuDriver::setIntention() {
    int userChoice;

    std::cout << "Select an option: \n";
    std::cout << "1. Calculate Semester GPA \n";
    std::cout << "2. Calculate Cumulative GPA \n";
    std::cout << "3. Calculate Target GPA \n";
    std::cout << "4. Display Current GPA \n";
    std::cout << "5. Exit \n";

    std::cin >> userChoice;

    while (std::cin.fail() || userChoice < 1 || userChoice > 5) {
        std::cin.clear(); // Clear the error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        std::cout << "Please enter a number between 1 and 5 \n";
        std::cin >> userChoice;
    }

    return userChoice;
}