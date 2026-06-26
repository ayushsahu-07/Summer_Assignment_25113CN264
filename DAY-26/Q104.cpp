

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char playerName[50];
    int choice;
    int score = 0;
    int total = 5;
    char answer;

   
    char questions[5][100] = {
        "1. What is the capital of India?",
        "2. Which planet is known as the Red Planet?",
        "3. What is 12 x 12?",
        "4. Who invented the telephone?",
        "5. What is the largest ocean on Earth?"
    };

    char options[5][4][60] = {
        {"A. Mumbai", "B. Delhi", "C. Kolkata", "D. Chennai"},
        {"A. Venus",  "B. Jupiter", "C. Mars",  "D. Saturn"},
        {"A. 124",   "B. 144",    "C. 164",    "D. 134"},
        {"A. Edison", "B. Newton", "C. Tesla",  "D. Bell"},
        {"A. Atlantic", "B. Indian", "C. Arctic", "D. Pacific"}
    };

    char correctAnswers[5] = {'B', 'C', 'B', 'D', 'D'};

    char explanations[5][100] = {
        "Delhi is the capital of India.",
        "Mars is called the Red Planet due to iron oxide on its surface.",
        "12 x 12 = 144.",
        "Alexander Graham Bell invented the telephone in 1876.",
        "The Pacific Ocean is the largest ocean, covering over 165 million sq km."
    };

   
    cout << "================================\n";
    cout << "       QUIZ APPLICATION         \n";
    cout << "================================\n";
    cout << "Enter your name: ";
    cin.getline(playerName, 50);

    cout << "\nHello, " << playerName << "!\n";
    cout << "You will be asked " << total << " questions.\n";
    cout << "Enter A, B, C, or D for each.\n";
    cout << "--------------------------------\n\n";

  
    for (int i = 0; i < total; i++) {
        cout << questions[i] << "\n";

        for (int j = 0; j < 4; j++) {
            cout << "   " << options[i][j] << "\n";
        }

        cout << "Your answer: ";
        cin >> answer;

        if (answer >= 'a' && answer <= 'd') {
            answer = answer - 32;
        }

        while (answer != 'A' && answer != 'B' && answer != 'C' && answer != 'D') {
            cout << "Invalid! Enter A, B, C or D: ";
            cin >> answer;
            if (answer >= 'a' && answer <= 'd') answer = answer - 32;
        }

        if (answer == correctAnswers[i]) {
            cout << "  CORRECT!\n";
            score++;
        } else {
            cout << "  WRONG! Correct answer: " << correctAnswers[i] << "\n";
        }

        cout << "  Explanation: " << explanations[i] << "\n\n";
    }

    float percentage = ((float)score / total) * 100;

    cout << "================================\n";
    cout << "           YOUR RESULT          \n";
    cout << "================================\n";
    cout << "Player   : " << playerName << "\n";
    cout << "Score    : " << score << " / " << total << "\n";
    cout << "Percentage: " << percentage << "%\n";
    cout << "--------------------------------\n";

    if (percentage == 100) {
        cout << "Grade: A+  | PERFECT SCORE!\n";
    } else if (percentage >= 80) {
        cout << "Grade: A   | Excellent!\n";
    } else if (percentage >= 60) {
        cout << "Grade: B   | Good Job!\n";
    } else if (percentage >= 40) {
        cout << "Grade: C   | Needs Improvement\n";
    } else {
        cout << "Grade: F   | Better luck next time!\n";
    }

    cout << "================================\n";
    cout << "Thanks for playing, " << playerName << "!\n";

    return 0;
}