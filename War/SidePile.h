#ifndef SIDEPILE_H
#define SIDEPILE_H

// SidePile class (Array-based Stack)
class SidePile {
private:
    int pile[5];
    int top;

public:
    SidePile();              // Constructor
    void push(int card);      // Push card onto the stack
    int pop();                // Pop card from the stack
    bool isEmpty() const;     // Check if the side pile is empty
    int size() const;         // Get the number of cards in the side pile
};

#endif // SIDEPILE_H
