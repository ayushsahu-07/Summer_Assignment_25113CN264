//Write a program to Create voting eligibility system.


 #include <iostream>
#include <cstring>
using namespace std;

int main() {
    char name[50];
    int age;
    char citizen[4];   
    char registered[4];
    char criminal[4];
    char mental[4];

    int isCitizen = 0;
    int isRegistered = 0;
    int hasCriminal = 0;
    int hasMental = 0;
    int eligible = 1;  

    cout << "=============================\n";
    cout << "   VOTING ELIGIBILITY SYSTEM  \n";
    cout << "=============================\n\n";

    // --- Input ---
    cout << "Enter your name: ";
    cin.getline(name, 50);

    cout << "Enter your age: ";
    cin >> age;
    cin.ignore();  

    cout << "Are you a citizen? (yes/no): ";
    cin.getline(citizen, 4);

    cout << "Are you registered to vote? (yes/no): ";
    cin.getline(registered, 4);

    cout << "Do you have a criminal conviction? (yes/no): ";
    cin.getline(criminal, 4);

    cout << "Do you have a declared mental incapacity? (yes/no): ";
    cin.getline(mental, 4);

  
    if (strcmp(citizen, "yes") == 0)    isCitizen = 1;
    if (strcmp(registered, "yes") == 0) isRegistered = 1;
    if (strcmp(criminal, "yes") == 0)   hasCriminal = 1;
    if (strcmp(mental, "yes") == 0)     hasMental = 1;

    
    cout << "\n-----------------------------\n";
    cout << "   ELIGIBILITY REPORT\n";
    cout << "-----------------------------\n";
    cout << "Name       : " << name << "\n";
    cout << "Age        : " << age << "\n";
    cout << "Citizen    : " << citizen << "\n";
    cout << "Registered : " << registered << "\n";
    cout << "Criminal   : " << criminal << "\n";
    cout << "Mental Cap.: " << mental << "\n";
    cout << "-----------------------------\n";
    cout << "CHECKS:\n\n";

   
    if (age >= 18) {
        cout << "[PASS] Age: " << age << " (18 or above)\n";
    } else {
        cout << "[FAIL] Age: " << age << " (Must be 18 or above)\n";
        eligible = 0;
    }

   
    if (isCitizen) {
        cout << "[PASS] Citizenship: Verified\n";
    } else {
        cout << "[FAIL] Citizenship: Not a citizen\n";
        eligible = 0;
    }


    if (isRegistered) {
        cout << "[PASS] Voter Registration: Registered\n";
    } else {
        cout << "[FAIL] Voter Registration: Not registered\n";
        eligible = 0;
    }

    if (!hasCriminal) {
        cout << "[PASS] Criminal Record: None\n";
    } else {
        cout << "[FAIL] Criminal Record: Has conviction\n";
        eligible = 0;
    }

    if (!hasMental) {
        cout << "[PASS] Mental Capacity: No declared incapacity\n";
    } else {
        cout << "[FAIL] Mental Capacity: Declared incapacity on record\n";
        eligible = 0;
    }

    cout << "\n-----------------------------\n";
    if (eligible) {
        cout << "VERDICT: ELIGIBLE TO VOTE\n";
        cout << name << ", you may proceed to cast your vote.\n";
    } else {
        cout << "VERDICT: NOT ELIGIBLE TO VOTE\n";
        cout << name << ", you do not meet all the requirements.\n";
    }
    cout << "-----------------------------\n";

    return 0;
}