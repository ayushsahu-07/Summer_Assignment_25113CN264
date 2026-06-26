//Write a program to Create number guessing game.
 
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int secret = rand() % 100 + 1; 
    int guess;
    int attempts = 0;
    int maxAttempts = 7;

    cout << "=============================\n";
    cout << "   NUMBER GUESSING GAME\n";
    cout << "=============================\n";
    cout << "Guess a number between 1 and 100\n";
    cout << "You have " << maxAttempts << " attempts!\n\n";

    while (attempts < maxAttempts) {
        cout << "Attempt " << (attempts + 1) << "/" << maxAttempts << " - Enter guess: ";
        cin >> guess;
        attempts++;

        if (guess < 1 || guess > 100) {
            cout << "  Invalid! Enter a number between 1 and 100.\n\n";
            attempts--;  
        } else if (guess < secret) {
            cout << "  Too LOW! Try higher.\n\n";
        } else if (guess > secret) {
            cout << "  Too HIGH! Try lower.\n\n";
        } else {
            cout << "\n*** YOU WIN! ***\n";
            cout << "You guessed " << secret << " in " << attempts << " attempt";
            if (attempts != 1) cout << "s";
            cout << "!\n";

            if (attempts <= 3) cout << "Rating: EXCELLENT!\n";
            else if (attempts <= 5) cout << "Rating: GOOD!\n";
            else cout << "Rating: YOU MADE IT!\n";

            return 0;
        }
    }

    cout << "\n*** GAME OVER! ***\n";
    cout << "The number was: " << secret << "\n";

    return 0;
}