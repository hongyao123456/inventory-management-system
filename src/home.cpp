#include "user.h"
#include "root.h"
#include <iostream>
#include <limits>

using namespace std;

int main() {
    UserManager userManager;      // Manages user operations
    AdminManager adminManager;    // Manages admin operations

    int choice;
    do {
        cout << "\n--- Welcome to the Homepage ---" << endl;
        cout << "1. Administrator Login" << endl;
        cout << "2. User Login" << endl;
        cout << "3. Create Account" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                adminManager.login();
                break;
            case 2:
                userManager.login();
                break;
            case 3:
                userManager.createAccount();
                break;
            case 4:
                cout << "Exiting... Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
