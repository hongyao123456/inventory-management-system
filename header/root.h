#ifndef ROOT_H
#define ROOT_H

#include <vector>
#include <string>
#include <fstream>
#include "stock.h"

class AdminManager {
public:
    void login();
    void addStock();
    void updateStock();
    void deleteStock();
    void viewStock();
    void logAction(const std::string& action);
    void viewSystemLog();
    void viewAllOrders(); // Added declaration
};

#endif
