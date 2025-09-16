#ifndef ORDER_H
#define ORDER_H

#include "stock.h"
#include <string>
#include <vector>
#include <fstream>  // 需要包括这个文件以进行文件操作

using namespace std;

struct Order {
    string username;  // 用户名，记录是谁下的订单
    string itemName;
    int quantity;
    double totalPrice;
};

extern vector<Order> orderHistory;  // 全局订单历史

void placeOrder(const string& username); // 下订单函数
void viewOrderHistory(const string& username); // 用户查看自己的订单历史
void viewAllOrderHistories(); // 管理员查看所有订单历史

void logOrderToFile(const string& username, const string& itemName, int quantity, double totalPrice); // 记录订单到文件
void logSystemAction(const string& action); // 记录系统日志

#endif
