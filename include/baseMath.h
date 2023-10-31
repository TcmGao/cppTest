#ifndef BATHMATH_H
#define BATHMATH_H

class BaseMath {

    public:
    virtual int plus(int a, int b) {
        return a + b;
    }

    virtual int plus(int a, int b, int c) {
        return 1;
    }
};

#endif