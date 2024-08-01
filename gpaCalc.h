//
// Created by crisr on 7/9/2024.
//

#ifndef GPACALC_GPACALC_H
#define GPACALC_GPACALC_H

#include <iostream>
#include <map>


class gpaCalc {
public:
    static void calculate(int);
    static float semesterGPA();
    static float cumulativeGPA();
    static float targetGPA();
    static float currentGPA();
    static float letterGradeToGPA(char);
};

#endif //GPACALC_GPACALC_H
