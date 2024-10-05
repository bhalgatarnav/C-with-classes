#include "HardMode.h"

#include <iostream>

HardMode::HardMode(int leastAmountVal, int highestRangeVal, int min, int max)
    : Wheel(min, max), houseWinsStreak(0), leastAmount(leastAmountVal), highestRange(highestRangeVal) {}


int HardMode::Hspin() {    // Method name matches class name

    int houseResult = Wheel::spin(getMin(), highWheel);

    return houseResult;
}

int HardMode::maxValue() {
    highWheel = getMax();

    if (houseWinsStreak == 2) {
        houseWinsStreak = 0;

        int newRange = getMax() / 2;

            highWheel = newRange;

    }
    else if (houseWinsStreak == -2) {
        houseWinsStreak = 0;
        int newRange = getMax() * 2;

            highWheel = newRange;


    }
}

void HardMode::displayRange() const{
    std::cout << "  Current House Wheel range: " << getMin() << "-" << highWheel << std::endl;
}

void HardMode::setWinsStreak(int wins) const {
    prevHouseWinsStreak = houseWinsStreak;
    houseWinsStreak += wins;
}

int HardMode::getWinStreak() const {
    return houseWinsStreak;
}


