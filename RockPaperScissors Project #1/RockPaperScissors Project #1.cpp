
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
    bool playing = true;

    while (playing) {
        displayMenu();

        currentHand = getInput();
        if (currentHand != 4) {
            getRoundWinner(currentHand);
        }
        else {
            displayFinalResult(wins, losses, ties, rounds);
            return 0;
        }
        
        rounds += 1;
    }
            


}

void displayMenu() {
    cout << "Please pick a hand to play below or select 4 to quit: \n" << "    1. Rock\n" << "    2. Paper\n" << "    3. Scissors\n" << "    4. End Game & show score\n";
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

int getRoundWinner(int) {

}

void displayFinalResult(int wins, int losses, int ties, int roundsPlayed) {

}