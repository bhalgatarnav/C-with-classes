#include "Wheel.h"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

Wheel::Wheel(int min, int max) : minVal(min), maxVal(max) {
    srand(time(0)); // Seed rand() ONLY ONCE in the constructor
}

void Wheel::setRange(int min, int max) {
    minVal = min;
    maxVal = max;
}

int Wheel::spin() const {
    // Use rand() with modulo and scaling to get the desired range:
    return minVal + (rand() % (maxVal - minVal + 1));
}

int Wheel::getMin() const {
    return minVal;
}
int Wheel::getMax() const {
    return maxVal;
}