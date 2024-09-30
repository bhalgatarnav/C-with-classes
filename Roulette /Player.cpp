#include "Player.h"

Player::Player(double initialMoney) {
    this->money = initialMoney;
}

void Player::setMoney(double amount) {
    money = amount;
}

double Player::getMoney() const {
    return money;
}

int Player::spin() const{
    return wheel.spin();

}