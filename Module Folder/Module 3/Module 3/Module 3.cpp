#include <iostream>
#include <string>
using namespace std;

int main() {
    // Store the welcome screen information
    string userName = "Cameron";
    string applicationName = "The Cursed Dungeon";
    string versionNumber = "0.1";

    // Display the welcome screen
    cout << "==================================" << endl;
    cout << "    WELCOME TO MY APPLICATION" << endl;
    cout << "==================================" << endl;
    cout << "Application: " << applicationName << endl;
    cout << "Version: " << versionNumber << endl;
    cout << "Welcome, " << userName << "!" << endl;
    cout << "The dungeon awaits..." << endl;
    cout << "==================================" << endl;

    return 0;
}