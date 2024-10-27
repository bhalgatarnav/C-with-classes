#ifndef DECK_H
#define DECK_H

// Node structure for the Linked List (Deck)
struct Node {
    int value;
    Node* next;
    Node(int v);
};

// Deck class (Linked List as Queue)
class Deck {
private:
    Node* front;
    Node* rear;
    int cardCount;

public:
    Deck();  // Constructor
    ~Deck(); // Destructor to clean up nodes

    void enqueue(int card);  // Add card to the rear (tail)
    int dequeue();           // Remove card from the front (head)
    bool isEmpty() const;    // Check if the deck is empty
    int size() const;        // Get the number of cards in the deck
};

#endif // DECK_H
