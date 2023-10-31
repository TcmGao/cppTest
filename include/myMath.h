#ifndef MYMATH_H
#define MYMATH_H

#include "baseMath.h"

class MyMath : public BaseMath {

    public:
    int plus(int a, int b) override {
        return a + b + 100;
    }

    int plus(int a, int b, int c) override {
        return a + b + c;
    }
};

#endif