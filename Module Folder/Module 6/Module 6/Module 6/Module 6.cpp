#include <iostream>
#include <string>
using namespace std;

class GameCharacter {
private:
    string name;
    int health;
    int attackPower;

public:
    // Constructor: sets the starting information.
    GameCharacter(string characterName, int startingHealth,
        int startingAttack) {
        name = characterName;
        health = startingHealth;
        attackPower = startingAttack;
    }

    // Member function: displays the character's information.
    void displayCharacter() {
        cout << "Name: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "Attack: " << attackPower << endl;
    }

    // Member function: reduces health without going below zero.
    void takeDamage(int damage) {
        if (damage > 0) {
            health -= damage;

            if (health < 0) {
                health = 0;
            }
        }
    }

    // Getter: returns the character's name.
    string getName() {
        return name;
    }

    // Setter: changes attack power if the value is valid.
    void setAttackPower(int newAttack) {
        if (newAttack >= 0) {
            attackPower = newAttack;
        }
    }
};

int main() {
    // Create two objects from the same class.
    GameCharacter player("Traveler", 100, 25);
    GameCharacter enemy("Cave Guardian", 80, 15);

    cout << "=== THE CURSED DUNGEON ===" << endl;

    player.displayCharacter();
    cout << endl;
    enemy.displayCharacter();

    // Demonstrate changing an object's information.
    cout << "\n" << player.getName()
        << " takes 20 damage and finds a stronger weapon!"
        << endl;

    player.takeDamage(20);
    player.setAttackPower(30);

    cout << "\n=== UPDATED PLAYER ===" << endl;
    player.displayCharacter();

    return 0;
}