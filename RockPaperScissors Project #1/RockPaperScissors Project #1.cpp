
#include <iostream>
#include <random>

using namespace std;

void displayMenu();
int getInput();
int getRoundWinner(int);
void displayFinalResult(int,int,int,int);

int main()
{
    int wins = 0;
    int losses = 0;
    int ties = 0;
    int rounds = 0;
    int currentHand = 0;
    int result = 0;
    bool playing = true;

    while (playing) {

        displayMenu();

        currentHand = getInput();

        if (currentHand != 4) {

            result = getRoundWinner(currentHand);
            if (result == 1) {
                ties += 1;
                cout << "You tied!\n";
            }
            else if (result == 2) {
                wins += 1;
                cout << "You won!\n";
            }
            else {
                losses += 1;
                cout << "They won!\n";
            }

            rounds += 1;
        }
        else {
            playing = false;
        }
        
    }
            

    displayFinalResult(wins, losses, ties, rounds);
    return 0;
}

void displayMenu() {
    cout << "Please pick a hand to play below or select 4 to quit: \n" << "    1. Rock\n" << "    2. Paper\n" << "    3. Scissors\n" << "    4. End Game & show score\n";
    return;
}

int getInput() {
    int option = 0;
    bool valid = false;

    while (!valid) {
        cin >> option;
        if (option == 1 || 2 || 3 || 4) {
            valid = true;
        }
        else {
            cout << "Invalid selection, please choose 1-4\n";
        }
    }

    return option;
}

int getRoundWinner(int hand) {
    random_device engine;
    uniform_int_distribution<int> randomness(1, 3);
    int computerHand = randomness(engine);


    if (hand == 1) {
        cout << "You played rock\n";
    }
    else if (hand == 2) {
        cout << "You played paper\n";
    }
    else if (hand == 3) {
        cout << "You played scissors\n";
    }

    if (computerHand == 1) {
        cout << "They played rock\n";
    }
    else if (computerHand == 2) {
        cout << "They played paper\n";
    }
    else if (computerHand == 3) {
        cout << "They played scissors\n";
    }


    if (hand == computerHand) {
        return 1;
    }
    else if (hand == 1 && computerHand == 3) {
        return 2;
    }
    else if (hand == 2 && computerHand == 1) {
        return 2;
    }
    else if (hand == 3 && computerHand == 2) {
        return 2;
    }
    else if (hand == 1 && computerHand == 2) {
        return 3;
    }
    else if (hand == 2 && computerHand == 3) {
        return 3;
    }
    else if (hand == 3 && computerHand == 1) {
        return 3;
    }
}

void displayFinalResult(int wins, int losses, int ties, int roundsPlayed) {
    cout << "You've ended the game after " << roundsPlayed << " rounds!\n";
    cout << "You won " << wins << " times, the computer won " << losses << " times, and you tied " << ties << " times!\n";

    if (wins == losses) {
        cout << "In the end, you tied!";
        return;
    }
    else if (wins - losses > 0) {
        cout << "In the end, you won! Congratulations!";
        return;
    }
    else if (wins - losses < 0) {
        cout << "In the end, the computer won. Better luck next time!";
        return;
    }
}