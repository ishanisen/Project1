#include "daleng.h"
#include <iostream>

using namespace std;

void displayMainMenu(list& reclist);

int main() {
    list reclist;
    displayMainMenu(reclist);
    return 0;
}

void displayMainMenu(list& reclist) {
    char ch;
    while (true) {
        cout << "\nWelcome to Dalhousie Engineering Students Database Management Systen\n";
        cout << "\n===== Student Records Menu =====\n";
        cout << "a = Add a student record\n";
        cout << "r = Retrieve a student record\n";
        cout << "d = Delete a student record\n";
        cout << "w = Display all records\n";
        cout << "s = Sort records by B00 number\n";
        cout << "-------------------------------------\n";
        cout << "c = Count total records\n";
        cout << "e = Check if records are empty\n";
        cout << "f = Clear all records\n";
        cout << "q = Quit\n";
        cout << "=====================================\n";
        cout << "Enter your choice: ";
        cin >> ch;
        cin.ignore();

        if (ch == 'q') {
            cout << "\nExiting system... Goodbye!\n";
            break;
        }
        else if (ch == 'c') {
            cout << "\nTotal student records: " << reclist.size() << endl;
        }
        else if (ch == 'e') {
            cout << (reclist.empty() ? "\nThe database is empty.\n" : "\nThe database contains records.\n");
        }
        else if (ch == 'a') {
            int type;
            cout << "\nSelect student type to add:\n";
            cout << "1 = Scholar\n";
            cout << "2 = Self-Funded\n";
            cout << "3 = Non-Categorized\n";
            cout << "Enter your choice (1,2,3): ";
            cin >> type;
            cin.ignore();

            daleng* x = nullptr;

            if (type == 1) {
                x = new scholar();
                cout << "\nEnter details for Scholar student:\n";
            }
            else if (type == 2) {
                x = new selffunded();
                cout << "\nEnter details for Self-Funded student:\n";
            }
            else if (type == 3) {
                x = new daleng();
                cout << "\nEnter details for Non-Categorized student:\n";
            }
            else {
                cout << "Invalid student type.\n";
                continue;
            }

            x->read(cin);
            reclist.store(x);
            cout << "\nStudent record added successfully!\n";
        }
        else if (ch == 'r') {
            if (reclist.empty()) {
                cout << "The student database is empty. No records to retrieve.\n";
            }
            else {
                string b00;
                cout << "Enter B00 number to retrieve: ";
                cin >> b00;
                reclist.retrieve(b00);
            }
        }
        else if (ch == 'd') {
            if (reclist.empty()) {
                cout << "The student database is empty. No records to remove.\n";
            }
            else {
                string b00number;
                cout << "Enter B00 number to remove: ";
                cin >> b00number;
                reclist.removeByB00(b00number);
            }
        }
        else if (ch == 'f') {
            reclist.clear();
        }
        else if (ch == 's') {
            if (reclist.empty()) {
                cout << "\nNothing to sort. The list is empty.\n";
            }
            else {
                reclist.sort();
                cout << "\nRecords sorted by B00 number.\n";
            }
        }
        else if (ch == 'w') {
            reclist.write(cout);
        }
        else {
            cout << "\nInvalid option. Please try again.\n";
        }
    }
}