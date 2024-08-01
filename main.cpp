#include "menuDriver.h"
#include "gpaCalc.h"


int main() {

    int mainChoice;

    do {
        mainChoice = menuDriver::setIntention();
        if (mainChoice != menuDriver::EXIT_OPTION) {
            gpaCalc::calculate(mainChoice);
        }
    } while (mainChoice != menuDriver::EXIT_OPTION);

    std::cout << "Exiting program. Goodbye!\n";
    return 0;
}
