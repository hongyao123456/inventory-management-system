#include "order.h"
#include "stock.h"  // 确保包含了库存头文件
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <ctime>

using namespace std;

vector<Order> orderHistory;

void placeOrder(const string& username) {
    string itemName;
    int quantity;
    double pricePerUnit = 5.0; // 单价示例

    cout << "Enter item name to order: ";
    cin >> itemName;
    cout << "Enter quantity to order: ";
    cin >> quantity;

    // 遍历库存查看是否有此商品
    for (auto& item : stock) {
        if (item.name == itemName) {
            if (item.quantity >= quantity) {
                double totalPrice = quantity * pricePerUnit;
                cout << "Item: " << item.name << ", Total Price: $" << totalPrice << endl;
                cout << "Confirm order? (y/n): ";

                char confirmation;
                cin >> confirmation;

                if (confirmation == 'y' || confirmation == 'Y') {
                    item.quantity -= quantity;
                    Order newOrder = {username, itemName, quantity, totalPrice}; // 存储用户名与订单
                    orderHistory.push_back(newOrder);
                    logOrderToFile(username, itemName, quantity, totalPrice); // 记录到文件

                    cout << "Processing...\n";
                    this_thread::sleep_for(chrono::seconds(5)); // 模拟处理时间
                    cout << "Successful order!\n";
                } else {
                    cout << "Order canceled.\n";
                }
                return;
            } else {
                cout << "Not enough stock available for " << itemName << ".\n";
                return;
            }
        }
    }
    cout << "Item not found in stock!\n";
}

void viewOrderHistory(const string& username) {
    ifstream orderFile("order_history.txt");
    if (!orderFile) {
        cout << "Unable to open order history file." << endl;
        return;
    }

    string line;
    while (getline(orderFile, line)) {
        if (line.find("Username: " + username) != string::npos) {
            cout << line << endl;
        }
    }
    orderFile.close();
}

void viewAllOrderHistories() {
    ifstream orderFile("order_history.txt");
    if (!orderFile) {
        cout << "Unable to open order history file." << endl;
        return;
    }

    string line;
    while (getline(orderFile, line)) {
        cout << line << endl;
    }
    orderFile.close();
}

void logOrderToFile(const string& username, const string& itemName, int quantity, double totalPrice) {
    ofstream orderFile("order_history.txt", ios::app);
    if (orderFile.is_open()) {
        orderFile << "Username: " << username << ", Ordered: " << itemName
                  << ", Quantity: " << quantity << ", Total Price: $" << totalPrice << endl;
    } else {
        cout << "Unable to open order history file for logging." << endl;
    }
    orderFile.close();
}

void logSystemAction(const string& action) {
    ofstream logFile("system.log", ios::app);
    if (logFile.is_open()) {
        auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());
        logFile << ctime(&now) << ": " << action << endl;
    } else {
        cout << "Unable to open system log file." << endl;
    }
    logFile.close();
}
