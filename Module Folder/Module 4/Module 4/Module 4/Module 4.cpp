// Dataset: Pokemon with stats
// Source: https://www.kaggle.com/datasets/abcsds/pokemon
// Selected fields: Name, HP, Attack
#include <iostream>
#include <string>
using namespace std;

int main() {
    string names[5] = {
        "Bulbasaur", "Ivysaur", "Venusaur",
        "Charmander", "Charmeleon"
    };

    int hp[5] = { 45, 60, 80, 39, 58 };
    int attack[5] = { 49, 62, 82, 52, 64 };

    int* hpPtr = &hp[0];

    cout << "=== POKEMON BATTLE STATS ===" << endl;

    for (int i = 0; i < 5; i++) {
        cout << names[i]
            << " | HP: " << hp[i]
            << " | Attack: " << attack[i] << endl;
    }

    cout << "\nFirst Pokemon's HP through pointer: "
        << *hpPtr << endl;

    return 0;
}