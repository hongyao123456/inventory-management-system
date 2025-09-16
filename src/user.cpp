#include "user.h"
#include "stock.h"
#include "order.h"
#include <iostream>
#include <unordered_map>
#include <limits>

using namespace std;

unordered_map<string, string> users;  // 存储用户名和密码

void UserManager::createAccount() {
    string username, password;
    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    if (users.find(username) == users.end()) {
        users[username] = password;
        cout << "Account created successfully! Returning to the homepage...\n";
    } else {
        cout << "Username already exists! Please choose a different username.\n";
    }
}

void UserManager::login() {
    string username, password;
    int attempts = 0;
    
    while (attempts < 2) {
        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter your password: ";
        cin >> password;
        
        if (users.find(username) != users.end() && users[username] == password) {
            cout << "Login successful! Welcome, " << username << "!" << endl;       
            int select;
            bool loggedIn = true;

            while (loggedIn) {
                cout << "\n--- User Menu ---\n";
                cout << "1. View Stock\n";
                cout << "2. Place Order\n";
                cout << "3. View Order History\n";
                cout << "4. Logout\n";
                cout << "Choose an option: ";
                cin >> select;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a number." << endl;
                    continue;
                }

                switch (select) {
                    case 1:
                        viewStock();
                        break;
                    case 2:
                        placeOrder(username); // 传递用户名
                        break;
                    case 3:
                        viewOrderHistory(username); // 传递用户名
                        break;
                    case 4:
                        cout << "Logging out...\n";
                        loggedIn = false;
                        break;
                    default:
                        cout << "Invalid option. Try again.\n";
                }
            }
            return;
        } else {
            cout << "Invalid username or password!" << endl;
            attempts++;
        }
    }
    cout << "Too many failed attempts. Please try again later." << endl;
}

void UserManager::viewStock() {
    cout << "Viewing stock...\n"; 
    ::viewStock(); // 调用全局viewStock函数
}
