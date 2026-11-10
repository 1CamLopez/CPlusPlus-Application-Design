#include <iostream>
#include <string>
using namespace std;

int getPositiveNumber() {
    int value;

    while (true) {
        cout << "Enter a character ID: ";

        if (cin >> value && value > 0) {
            cin.ignore(10000, '\n');
            return value;
        }

        cout << "Invalid ID. Please enter a positive number.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}
string getUsername() {
    string name;

    while (true) {
        cout << "Enter your username: ";
        getline(cin, name);

        if (name.find_first_not_of(" \t") != string::npos) {
            return name;
        }

        cout << "Username cannot be empty. Try again.\n";
    }
}


// Records must be sorted before using binary search.
int binarySearch(int data[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (data[mid] == target) return mid;

        if (data[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

class User {
protected:
    string username;

public:
    User(string name) : username(name) {}

    void viewRecords(int records[], int size) {
        cout << username << " is viewing character IDs: ";

        for (int i = 0; i < size; i++) {
            cout << records[i] << " ";
        }

        cout << endl;
    }

    void searchRecords(int records[], int size, int id) {
        int index = binarySearch(records, size, id);

        if (index == -1)
            cout << "Character ID " << id << " not found." << endl;
        else
            cout << "Character ID " << id
            << " found at index " << index << "." << endl;
    }
};

class Admin : public User {
public:
    Admin(string name) : User(name) {}

    void addRecord(int records[], int& size, int capacity, int id) {
        if (size >= capacity) {
            cout << "Records are full." << endl;
            return;
        }

        if (binarySearch(records, size, id) != -1) {
            cout << "That ID already exists." << endl;
            return;
        }

        // Move larger IDs right to make space.
        int i = size;

        while (i > 0 && records[i - 1] > id) {
            records[i] = records[i - 1];
            i--;
        }

        records[i] = id;
        size++;

        cout << username << " added character ID " << id << "." << endl;
    }

    void deleteRecord(int records[], int& size, int id) {
        int index = binarySearch(records, size, id);

        if (index == -1) {
            cout << "Record not found." << endl;
            return;
        }

        // Shift records left to fill the gap.
        for (int i = index; i < size - 1; i++) {
            records[i] = records[i + 1];
        }

        size--;

        cout << username << " deleted character ID " << id << "." << endl;
    }
};

class RegularUser : public User {
public:
    RegularUser(string name) : User(name) {}
};


int main() {
    const int CAPACITY = 10;
    int records[CAPACITY] = { 101, 103, 105 };
    int size = 3;

    cout << "=== DUNGEON CHARACTER RECORDS ===" << endl;

    string name = getUsername();

    Admin admin("Cameron");
    RegularUser player(name);

    admin.viewRecords(records, size);

    cout << "\nAdmin: Add a new character record.\n";
    int newID = getPositiveNumber();

    admin.addRecord(records, size, CAPACITY, newID);
    admin.viewRecords(records, size);

    player.viewRecords(records, size);

    cout << "\nSearch for a character.\n";
    int searchID = getPositiveNumber();

    player.searchRecords(records, size, searchID);

    cout << "\nAdmin: Delete a character record.\n";
    int deleteID = getPositiveNumber();

    admin.deleteRecord(records, size, deleteID);
    player.viewRecords(records, size);

    return 0;
}
