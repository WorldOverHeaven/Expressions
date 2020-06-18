#ifndef HOMEWORK2_TREE_H
#define HOMEWORK2_TREE_H

#include "functions.h"

class Tree {
private:
    Data* node{};
    Tree* left{};
    Tree* right{};
public:
    Tree();

    explicit Tree(char a);

    void addSign(char a);

    static bool addNum(char ch, Tree* a, bool flag = false);

    static void print(Tree* tree);

    static double calculate(Tree* a);
};

#endif
