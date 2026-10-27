#include <iostream>
#include <limits>
#include "RecordTools.h"
using namespace std;

int main() {
    const int CAPACITY = 10;
    int count = 5;

    string names[CAPACITY] = {
        "Bulbasaur", "Ivysaur", "Venusaur",
        "Charmander", "Charmeleon"
    };

    int hp[CAPACITY] = { 45, 60, 80, 39, 58 };
    int attack[CAPACITY] = { 49, 62, 82, 52, 64 };

    int choice = 0;

    while (choice != 4) {
        cout << "\n=== POKEMON RECORD TOOLS ===" << endl;
        cout << "1. Add a record" << endl;
        cout << "2. Display records" << endl;
        cout << "3. Calculate average attack" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose an option: ";

        if (!(cin >> choice)) {
            if (cin.eof()) {
                break;
            }

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number from 1 to 4." << endl;
            continue;
        }

        switch (choice) {
        case 1:
            addRecord(names, hp, attack, count, CAPACITY);
            break;

        case 2:
            displayRecords(names, hp, attack, count);
            break;

        case 3:
            cout << "Average attack: "
                << calculateAverageAttack(attack, count)
                << endl;
            break;

        case 4:
            cout << "Goodbye!" << endl;
            break;

        default:
            cout << "Please choose an option from 1 to 4." << endl;
        }
    }

    return 0;
}