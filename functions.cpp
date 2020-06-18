#include "functions.h"
#include <string>
#include "Tree.h"
#include <iostream>
using namespace std;
bool isNumFunction (char a) {
    bool flag = false;
    for (char number : numbers) {
        if (a == number) {
            flag = true;
        }
    }
    return flag;
}

bool isSingFunction (char a) {
    bool flag = false;
    for (char sign : signs) {
        if (a == sign) {
            flag = true;
        }
    }
    return flag;
}

void go() {
    cout << "Enter an expression " << endl;
    string s;
    getline(cin, s);
    Tree a;
    for (char i : s) {
        if (isSingFunction(i)) {
            a.addSign(i);
        }
    }
    for (char i : s) {
        if (isNumFunction(i)) {
            Tree::addNum(i, &a);
        }
    }
    cout <<  Tree::calculate(&a) << endl;
}
