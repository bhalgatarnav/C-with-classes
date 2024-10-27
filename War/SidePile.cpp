#include "SidePile.h"
#include <stdexcept>
using namespace std;

// Constructor for SidePile
SidePile::SidePile() : top(-1) {}

// Push card onto the stack
void SidePile::push(int card) {
    if (top == 4) {
        throw runtime_error("Side pile is full.");
    }
    pile[++top] = card;
}

// Pop card from the stack
int SidePile::pop() {
    if (top == -1) {
        throw runtime_error("Side pile is empty.");
    }
    return pile[top--];
}

// Check if the side pile is empty
bool SidePile::isEmpty() const {
    return top == -1;
}

// Get the number of cards in the side pile
int SidePile::size() const {
    return top + 1;
}
