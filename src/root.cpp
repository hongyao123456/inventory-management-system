#include "root.h"
#include "order.h"
#include <iostream>
#include <limits>
#include <ctime>
#include <algorithm>  // Ensure algorithm is included

using namespace std;

void AdminManager::login() {
    string adminUsername, adminPassword;
    int attempts = 0;

    while (attempts < 2) {
        cout << "Enter admin username: ";
        cin >> adminUsername;
        cout << "Enter admin password: ";
        cin >> adminPassword;

        if (adminUsername == "admin" && adminPassword == "admin123") {
            cout << "Admin login successful!\n";
            int option;
            do {
                cout << "\n--- Admin Menu ---\n";
                cout << "1. View Stock\n";
                cout << "2. Add Stock\n";
                cout << "3. Update Stock\n";
                cout << "4. Delete Stock\n";
                cout << "5. View System Log\n";
                cout << "6. View All Order Histories\n"; // View all order histories
                cout << "7. Logout\n";
                cout << "Choose an option: ";
                cin >> option;

                // Handle invalid input
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a number." << endl;
                    continue;
                }

                switch (option) {
                    case 1:
                        viewStock(); // Call the viewStock() function correctly
                        break;
                    case 2:
                        addStock();
                        break;
                    case 3:
                        updateStock();
                        break;
                    case 4:
                        deleteStock();
                        break;
                    case 5:
                        viewSystemLog();
                        break;
                    case 6:
                        viewAllOrders(); // View all orders
                        break;
                    case 7:
                        cout << "Logging out...\n";
                        return; // Properly logout and exit
                    default:
                        cout << "Invalid option. Try again.\n";
                }
            } while (true); // Repeat the admin menu until the user logs out
        } else {
            cout << "Invalid username or password. Try again.\n";
            attempts++;
        }
    }

    cout << "Too many failed attempts. Returning to the main menu...\n";
}

void AdminManager::addStock() {
    string itemName;
    int quantity;
    cout << "Enter item name: ";
    cin >> itemName;
    cout << "Enter quantity: ";
    cin >> quantity;

    stock.push_back({itemName, quantity});
    cout << "Stock added successfully!\n";
    logAction("Added stock: " + itemName + ", Quantity: " + to_string(quantity));
}

void AdminManager::updateStock() {
    string itemName;
    int newQuantity;
    cout << "Enter item name to update: ";
    cin >> itemName;

    bool found = false;
    for (auto& item : stock) {
        if (item.name == itemName) {
            cout << "Enter new quantity: ";
            cin >> newQuantity;
            item.quantity = newQuantity;
            cout << "Stock updated successfully!\n";
            logAction("Updated stock: " + itemName + ", New Quantity: " + to_string(newQuantity));
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Item not found in stock!\n";
    }
}

void AdminManager::deleteStock() {
    string itemName;
    cout << "Enter item name to delete: ";
    cin >> itemName;

    auto it = find_if(stock.begin(), stock.end(),
        [&](const StockItem& item) { return item.name == itemName; });

    if (it != stock.end()) {
        stock.erase(it);
        cout << "Item deleted successfully!\n";
    } else {
        cout << "Item not found in stock!\n";
    }
}

void AdminManager::viewStock() {
    cout << "--- Current Stock ---\n";
    if (stock.empty()) {
        cout << "No stock available.\n";
    } else {
        for (const auto& item : stock) {
            cout << "Item: " << item.name << ", Quantity: " << item.quantity << endl;
        }
    }
}

void AdminManager::logAction(const std::string& action) {
    std::ofstream logFile("system.log", std::ios::app);
    if (!logFile) return;

    time_t now = time(0);
    char* dt = ctime(&now);
    logFile << "[" << dt << "] " << action << std::endl;
    logFile.close();
}

void AdminManager::viewSystemLog() {
    std::ifstream logFile("system.log");
    if (!logFile) {
        cout << "Unable to open log file." << endl;
        return;
    }
    std::string line;
    while (std::getline(logFile, line)) {
        cout << line << endl;
    }
    logFile.close();
}

void AdminManager::viewAllOrders() {
    std::ifstream orderFile("order_history.txt");
    if (!orderFile) {
        cout << "Unable to open order history file." << std::endl;
        return;
    }

    cout << "--- All Orders ---\n";
    std::string line;
    while (std::getline(orderFile, line)) {
        cout << line << std::endl;
    }
    orderFile.close();
}
