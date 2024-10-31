#include "Deck.h"
#include "SidePile.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to initialize decks with random cards
void initializeDeck(Deck &deck) {
    for (int i = 0; i < 10; ++i) {
        deck.enqueue(rand() % 10 + 1);  // Cards from 1 to 10
    }
}


void playRound(Deck &playerDeck, Deck &computerDeck, SidePile &playerSidePile, SidePile &computerSidePile) {

    char choice;
    int playerCard = playerDeck.dequeue();
    int sum = 0;

    cout << "\nYour top card is: " << playerCard << ".\nDo you want to (P)ush or (L)pull a card? ";
    cin >> choice;


    if (choice == 'P' || choice == 'p') {

        if (playerSidePile.size() < 5) {
            playerSidePile.push(playerCard);
            cout << "\nYou pushed card " << playerCard << " to your side pile.\n";

            sum = playerCard;
        }
        else {
            cout << "\nSide pile is full. You cannot push.\n";
            sum = playerCard;
        }

    } else if (choice == 'L' || choice == 'l') {

        if (!playerSidePile.isEmpty()) {
            int removedCard = playerSidePile.pop();
            cout << "\nYou pulled "<< removedCard <<" from your side pile.\n";

            sum = playerCard + removedCard;

        }
        else {
            cout << "\nSide pile is empty. Cannot pull.\n";
            sum = playerCard;
        }
    }

    // Computer's random decision
    int computerCard = computerDeck.dequeue();
    cout << "Computer plays card: " << computerCard << endl;

    cout << "\nYour card sum: " << sum << ", Computer's card: " << computerCard << endl;

    if (sum > computerCard) {
        cout << "You win the round!\n";
        playerDeck.enqueue(playerCard);
        playerDeck.enqueue(computerCard);


    } else {
        cout << "Computer wins the round.\n";
        computerDeck.enqueue(playerCard);
        computerDeck.enqueue(computerCard);


    }
}

// Main function
int main() {
    srand(static_cast<unsigned int>(time(0)));  // Seed random number generator

    Deck playerDeck, computerDeck;
    SidePile playerSidePile, computerSidePile;

    // Initialize both decks with random cards
    initializeDeck(playerDeck);
    initializeDeck(computerDeck);

    int choice;

    cout << "\nChoose one of the following options:" << endl;
    cout << "1. Play until one participant runs out of cards\n2. Play for a fixed number of rounds" << endl;
    cout << "\nChoose game style (1 or 2): ";

    cin >> choice;

    int rounds = 0;
    if (choice == 2) {
        cout << "Enter the number of rounds: ";
        cin >> rounds;
    }

    // Game loop
    while (!playerDeck.isEmpty() && !computerDeck.isEmpty() && (choice == 1 || rounds > 0)) {

        playRound(playerDeck, computerDeck, playerSidePile, computerSidePile);

        if (choice == 2) {
            rounds--;
        }
    }

    // Game conclusion
    if (playerDeck.isEmpty() && playerSidePile.isEmpty()) {
        cout << "You ran out of cards. Computer wins the game.\n";
    } else if (computerDeck.isEmpty() && computerSidePile.isEmpty()) {
        cout << "Computer ran out of cards. You win the game.\n";
    } else if (choice == 2 && rounds == 0) {
        cout << "Game over. Fixed rounds ended.\n";
    }

    return 0;
}
