#include "Deck.h"
#include <stdexcept>
using namespace std;

// Constructor for Node
Node::Node(int v) : value(v), next(nullptr) {}

// Constructor for Deck
Deck::Deck() : front(nullptr), rear(nullptr), cardCount(0) {}

// Destructor for Deck
Deck::~Deck() {
    while (!isEmpty()) {
        dequeue();
    }
}

// Enqueue (Add card to the rear)
void Deck::enqueue(int card) {
    Node* newNode = new Node(card);
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cardCount++;
}

// Dequeue (Remove card from the front)
int Deck::dequeue() {
    if (front == nullptr) {
        throw runtime_error("Deck is empty.");
    }
    Node* temp = front;
    int card = temp->value;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
    cardCount--;
    return card;
}

// Check if the deck is empty
bool Deck::isEmpty() const {
    return cardCount == 0;
}

// Get the number of cards in the deck
int Deck::size() const {
    return cardCount;
}
