#include <iostream>
#include <map>
#include "menuDriver.h"
#include "gpaCalc.h"


int main() {
    int menuChoice;

    menuDriver menu;
    menuChoice = menu.setIntention();

    gpaCalc findMyGPA;
    findMyGPA.calculate(menuChoice);

    return 0;
}
