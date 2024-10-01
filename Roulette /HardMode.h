/// HardMode.h
#ifndef HARDMODE_H
#define HARDMODE_H

#include "Wheel.h"

class HardMode : public Wheel {
private:
    int houseWinsStreak;
    int leastAmount;  // Renamed variable
    int highestRange;  // Highest range the HardMode wheel can go up to

public:
    HardMode(int leastAmountVal, int highestRangeVal, int min = 1, int max = 10); // Updated parameter names
    int Hspin(int playerResult);
    void displayRange() const;
};


#endif