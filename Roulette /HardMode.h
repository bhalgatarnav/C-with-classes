/// HardMode.h
#ifndef HARDMODE_H
#define HARDMODE_H

#include "Wheel.h"

class HardMode : public Wheel {
private:
    mutable int houseWinsStreak;
    mutable int prevHouseWinsStreak;

    int highWheel;
    int lowWheel;

    int leastAmount;  // Renamed variable
    int highestRange;  // Highest range the HardMode wheel can go up to

public:
    HardMode(int leastAmountVal, int highestRangeVal, int min = 1, int max = 10); // Updated parameter names
    int Hspin();
    void displayRange() const;

    void setWinsStreak(int wins) const;
    int getWinStreak() const;
    bool winsStreak() const;


    void maxValue();

};


#endif