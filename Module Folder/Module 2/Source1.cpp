#include <iostream>
#include <limits>
#include <string>
using namespace std;

void exploreDungeon() {
    cout << "You enter the dungeon. Something stirs in the darkness." << endl;
}

void viewCharacter() {
    cout << "Character details will appear here." << endl;
}

void openInventory() {
    cout << "Your inventory will appear here." << endl;
}

void rest() {
    cout << "You rest beside a dimly glowing shrine." << endl;
}

void howToPlay() {
    cout << "Explore the dungeon, collect supplies, and defeat its guardian." << endl;
}

void exitGame() {
    cout << "You leave the dungeon behind. For now..." << endl;
}

int main() {
    int choice = 0;

    while (choice != 6) {
        cout << "\n=== THE CURSED DUNGEON ===" << endl;
        cout << "1. Explore Dungeon" << endl;
        cout << "2. View Character" << endl;
        cout << "3. Open Inventory" << endl;
        cout << "4. Rest" << endl;
        cout << "5. How to Play" << endl;
        cout << "6. Exit" << endl;
        cout << "Choose an option: ";
        if (!(cin >> choice)) {
            if (cin.eof()) {
                break;
            }

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input. Enter a number from 1 to 6." << endl;
            continue;
        }

        switch (choice) {
        case 1:
            exploreDungeon();
            break;
        case 2:
            viewCharacter();
            break;
        case 3:
            openInventory();
            break;
        case 4:
            rest();
            break;
        case 5:
            howToPlay();
            break;
        case 6:
            exitGame();
            break;
        default:
            cout << "Invalid choice. Enter a number from 1 to 6." << endl;
        }
    }

    return 0;
}