#ifndef PLAYER_H
#define PLAYER_H

#include "Wheel.h" // Include the Wheel header

class Player {
private:
    Wheel wheel;  // Player's wheel
    double money;

public:
    Player(double initialMoney = 0.0);  // Constructor with default initial money
    void setMoney(double amount);
    double getMoney() const;        // Make this const as it doesn't modify the object
    int spin() const;             //spin should also be const
};

#endif