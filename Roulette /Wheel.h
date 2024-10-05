#ifndef WHEEL_H
#define WHEEL_H

#include <cstdlib> // For rand() and srand()

class Wheel {
private:
    int minVal;
    int maxVal;

public:
    Wheel(int min = 1, int max = 10);
    void setRange(int min, int max);
    virtual int spin() const;  // Still virtual and const
    int spin(int min, int max);

    int getMin() const;
    int getMax() const;
};

#endif