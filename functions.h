#ifndef HOMEWORK2_FUNCTIONS_H
#define HOMEWORK2_FUNCTIONS_H

const char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
const char signs[4] = {'+', '-', '/', '*'};

bool isNumFunction (char a);

bool isSingFunction (char a);

void go();

struct Data {
    double num;
    bool isSign;
    char sign;
};

#endif
