#include <iostream>
#include <limits>
#include "RecordTools.h"
using namespace std;

void addRecord(string names[], int hp[], int attack[],
    int& count, int capacity) {
    if (count >= capacity) {
        cout << "No room for more records." << endl;
        return;
    }

    string newName;
    int newHP;
    int newAttack;

    cout << "Enter Pokemon name: ";
    getline(cin >> ws, newName);

    cout << "Enter HP: ";
    if (!(cin >> newHP) || newHP <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid HP. Record not added." << endl;
        return;
    }

    cout << "Enter attack: ";
    if (!(cin >> newAttack) || newAttack <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid attack. Record not added." << endl;
        return;
    }

    names[count] = newName;
    hp[count] = newHP;
    attack[count] = newAttack;
    count++;

    cout << "Record added!" << endl;
}

void displayRecords(const string names[], const int hp[],
    const int attack[], int count) {
    for (int i = 0; i < count; i++) {
        cout << names[i]
            << " | HP: " << hp[i]
            << " | Attack: " << attack[i] << endl;
    }
}

double calculateAverageAttack(const int attack[], int count) {
    if (count == 0) {
        return 0.0;
    }

    int total = 0;

    for (int i = 0; i < count; i++) {
        total += attack[i];
    }

    return static_cast<double>(total) / count;
}