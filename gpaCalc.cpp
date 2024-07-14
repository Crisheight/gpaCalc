//
// Created by crisr on 7/9/2024.
//

#include "gpaCalc.h"

int gpaCalc::calculate(const std::map<int, int> &intMap){
    for (const auto& pair : intMap) {
        std::cout << pair.second << "\n";
    }
    return 0;
}
