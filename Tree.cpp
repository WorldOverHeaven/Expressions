#include "Tree.h"
#include <iostream>
using namespace std;

Tree::Tree() {
    left = nullptr;
    right = nullptr;
    node = nullptr;
}

Tree::Tree(char a) {
    if (isNumFunction(a)) {
        auto nd2 = new Data;
        nd2->num = (double)a - 48;
        nd2->isSign = false;
        left = nullptr;
        right = nullptr;
        node = nd2;
    }
    else {
        auto nd2 = new Data;
        nd2->isSign = true;
        nd2->sign = a;
        left = nullptr;
        right = nullptr;
        node = nd2;
    }
}

void Tree::addSign(char a) {
    if (node == nullptr) {
        auto nd2 = new Data;
        nd2->isSign = true;
        nd2->sign = a;
        node = nd2;
    }
    else {
        if (a == '+' || a == '-') {
            left = new Tree(*this);
            auto nd2 = new Data;
            nd2->isSign = true;
            nd2->sign = a;
            node = nd2;
            right = nullptr;
        }
        else {
            auto b = new Tree(a);
            if (right == nullptr) {
                right = b;
            }
            else {
                auto c = right;
                while (c->right != nullptr) {
                    c = c->right;
                }
                c->right = b;
            }
        }
    }
}

bool Tree::addNum(char ch, Tree* a, bool flag) {
    if (a == nullptr || flag) {
        return flag;
    }
    flag = addNum(ch, a->left);
    if (flag) {
        return true;
    }
    if (a->node->isSign) {
        if (a->left == nullptr) {
            auto b = new Tree(ch);
            a->left = b;
            return true;
        }
        if (a->right == nullptr) {
            auto b = new Tree(ch);
            a->right = b;
            return true;
        }
    }
    addNum(ch, a->right);
    return false;
}

void Tree::print(Tree* tree) {
    if (tree != nullptr) {
        if (tree->node->isSign) {
            cout << tree->node->sign;
        }
        else {
            cout << tree->node->num;
        }
        print(tree->left);
        print(tree->right);
    }
}

double Tree::calculate(Tree* a) {
    if (!a->node->isSign) {
        return a->node->num;
    }
    else {
        if (a->node->sign == '+') {
            return (calculate(a->left) + calculate(a->right));
        }
        if (a->node->sign == '-') {
            return (calculate(a->left) - calculate(a->right));
        }
        if (a->node->sign == '*') {
            return (calculate(a->left) * calculate(a->right));
        }
        if (a->node->sign == '/') {
            return (calculate(a->left) / calculate(a->right));
        }
    }
    return 0;
}
