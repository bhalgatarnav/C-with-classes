#include "HardMode.h"

#include <iostream>

HardMode::HardMode(int leastAmountVal, int highestRangeVal, int min, int max)
    : Wheel(min, max), houseWinsStreak(0), leastAmount(leastAmountVal), highestRange(highestRangeVal) {}


int HardMode::Hspin(int playerResult) {    // Method name matches class name
    int houseResult = Wheel::spin();

    if (playerResult > houseResult) {
        houseWinsStreak = 0;
        int newMax = getMax() * 2;
        if (newMax > 100) {
            newMax = 100;
        }
        setRange(getMin(), newMax);

    } else {
        houseWinsStreak++;
        if (houseWinsStreak >= 2) {
            int newRange = getMax() / 2;
            if (newRange < leastAmount) {  // Use leastAmount here
                newRange = leastAmount;
                setRange(getMin(), newRange);
            }
            if (newRange > highestRange) {  // Use highestRange here
                newRange = highestRange;
                setRange(getMin(), newRange);
            }
            
            houseWinsStreak = 0;
        }
    }
    return houseResult;
}

void HardMode::displayRange() const{
    std::cout << "New House Wheel range: " << getMin() << "-" << getMax() << std::endl;
}