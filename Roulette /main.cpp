#include "Player.h"
#include <iostream>
#include <limits> // Required for numeric_limits

#include "HardMode.h"


using namespace std;

/** Function: getPlayerBet
*   Parameters:
*    - const Player& player: A reference to a Player object, which is used to access the player's current balance.
*   Returns:
*    - int: The player's valid bet, which is between 6 and 20 and does not exceed their current balance.
*/

int getPlayerBet(const Player& player) {
    int bet;

    do {
        // Reading the player's invested money
        cout << "Enter your bet (6-20, current balance: " << player.getMoney() << "): ";

        // Asking what amount player has to bet.
        cin >> bet;

        // cin.fail() :- function that ensure if a valid input is entered.
        // if user enters data that doesn't match the expected type.
        if ( bet < 6 || bet > 20 || bet > player.getMoney()) {
            cout << "Invalid bet. Please enter a number between 6 and 20, and not exceeding your balance." << endl;

            // Clears the input stream that ensures futher input to be taken.
            // cin.clear();
        }
    } while (bet < 6 || bet > 20 || bet > player.getMoney());

    return bet;
}



/** Function: getBetChangeChoice
* Parameters: None
* Purpose: Prompts the user to choose whether to double, halve, or keep their bet.
* Returns:
*   - char: The user's valid choice, either 'd' (double), 'h' (halve), or 'k' (keep).
*/

char getBetChangeChoice() {
    char choice;
    do {
        cout << "Double (d), Halve (h), or Keep (k) your bet? ";

        cin >> choice;

        if ((choice != 'd' && choice != 'h') && choice != 'k') {
            cout << "Invalid choice. Please enter 'd', 'h', or 'k'." << endl;
        }

    } while (choice != 'd' && choice != 'h' && choice != 'k');

    return choice;
}



// Function: determineWinner
// Parameters:
//   - int pSpin: The player's spin value.
//   - int hSpin1: The house's first spin value.
//   - int hSpin2: The house's second spin value.
//   - char betChange: The player's bet change choice ('d' for double, 'h' for halve, 'k' for keep).
// Purpose: Determines if the player wins based on their spin and the house's spins.
// Returns:
//   - bool: True if the player wins, otherwise false.

bool determineWinner(int pSpin, int hSpin1, int hSpin2, char betChange) {

    if (betChange == 'd'){
      return pSpin > hSpin1 && pSpin > hSpin2;
    }
    else if (betChange == 'h'){
      return  pSpin > hSpin1 || pSpin > hSpin2;
    }
    else {
        return pSpin > hSpin1;
    }

}



// Function: playRound
// Parameters:
//   - Player& player: A reference to the Player object, representing the current player.
//   - Wheel& houseWheel: A reference to the Wheel object, representing the house's wheel.

// Purpose: Executes one round of the game, where the player places a bet, spins the wheel, and can choose to
//          modify their bet (double, halve, or keep). Determines the outcome and updates the player's balance.
// Returns: None (void)

// Updates the private variable money according to the win rate.

void playRound(Player& player, Wheel& houseWheel) {

    // Calling the getPlayerBet function to determine the bet player wants to place.
    int bet = getPlayerBet(player);

    if (player.getMoney() < bet*2) {
        cout << " Sorry :( The game requires a margin that’s double the bet amount. \n";
        return;
    }

    // Getting the random number (minVal, maxVal)
    // Both parties spin their wheel and determine the number
    int playerSpin = player.spin();
    int houseSpin1 = houseWheel.spin();


    houseWheel.setRange(1,10);
    cout << "Player's spin value: " << playerSpin << endl;

    // Calling getBetChangeChoice to check if player wants any changes.
    char betChange = getBetChangeChoice();

    int houseSpin2 = 0;

    double betMultiplier = 1.0;


    if (betChange == 'd') {
        houseSpin2 = houseWheel.spin();
        betMultiplier = 2.0;

    } else if (betChange == 'h') {
        houseSpin2 = houseWheel.spin();
        betMultiplier = 0.5;
    }

    // Prints out the spin values of the house
    if (betChange != 'k') {
        cout << "House spins: " << houseSpin1 << ", " << houseSpin2 << endl;
    }
    else {
        cout << "House spin: " << houseSpin1 << endl;
    }



    // Change in the amount.
    // Considers the case where betChange is 'k'
      if (determineWinner(playerSpin, houseSpin1, houseSpin2, betChange)) {
          player.setMoney(player.getMoney() + bet * betMultiplier);

          // Based on the win status print the total money of the player
          cout << "You WON! Current balance: " << player.getMoney() << endl;

      } else {
          player.setMoney(player.getMoney() - bet * betMultiplier);

          // Based on the win status print the total money of the player
          cout << "You LOST! Current balance: " << player.getMoney() << endl;

      }
}


void playHardRound(Player& player, HardMode& hardHouseWheel) {
    int bet = getPlayerBet(player);
    if (player.getMoney() < bet*2) {
        cout << " Sorry :( The game requires a margin that’s double the bet amount. \n";
        return;
    }

    int playerSpin = player.spin();

    hardHouseWheel.displayRange();
    cout << "Player's spin value: " << playerSpin << endl;

    // Calling the getPlayerBet function to determine the bet player wants to place.
    char betChange = getBetChangeChoice();

    int houseSpin1 = hardHouseWheel.Hspin(playerSpin);
    int houseSpin2;

    double betMultiplier = 1.0;



    if (betChange == 'd') {
        houseSpin2 = hardHouseWheel.Hspin(playerSpin);
        betMultiplier = 2.0;

    } else if (betChange == 'h') {
        houseSpin2 = hardHouseWheel.Hspin(playerSpin);
        betMultiplier = 0.5;

    }

    if (determineWinner(playerSpin, houseSpin1, houseSpin2, betChange)) {
        player.setMoney(player.getMoney() + bet * betMultiplier);
    }
    else {
        player.setMoney(player.getMoney() - bet * betMultiplier);
    }



    if (betChange != 'k') {
        cout << "House spins: " << houseSpin1 << ", " << houseSpin2 << endl;
    }
    else {
        cout << "House spin: " << houseSpin1 << endl;
    }

    cout << "Updated Current balance: " << player.getMoney() << endl;
}


int main() {

    cout << "Gamble to Win! Enter the amount you want to invest: ";

    int invValue, minRange, maxRange;
    cin >> invValue;
    Player player(invValue);

    Wheel houseWheel;

    char continueChoice = 'y';
    char gameMode;

    do{
        do {
            cout << "Select Game mode: Normal (n) or Hard (h)? ";
            cin >> gameMode;
            if (gameMode != 'n' && gameMode != 'h') {
                cout << "Invalid choice. Please enter 'n' or 'h'." << endl;
            }
        } while (gameMode != 'n' && gameMode != 'h');


            if (gameMode == 'n') {
                cout << "\n Normal Round! (Fixed Range 1-10) \n";

                // if (player.getMoney() < invValue*2) {
                //
                // }
                playRound(player, houseWheel);
            }

            else if (gameMode == 'h') {
                 cout << "\n Hard Round! (Range keeps changing) \n";
                // cout << "Enter the minimum value in the range: ";
                // cin >> minRange;
                //
                // cout << "Enter the maximum value in the range: ";
                // cin >> maxRange;

                // Calling the constructor
                HardMode hardHouseWheel (5, 100, 1, 10);
                playHardRound(player, hardHouseWheel);

            }


            do{
                cout << "\nPlay another round? (y/n): ";
                cin >> continueChoice;
                if(continueChoice != 'y' && continueChoice != 'n'){
                    cout << "\nInvalid choice. Please enter 'y' or 'n': ";
                }

            } while (continueChoice != 'y' && continueChoice != 'n');


        } while (continueChoice == 'y' && player.getMoney() >= 0);




    cout << "\nGame Over! Final balance: " << player.getMoney() << endl;


    return 0;
}