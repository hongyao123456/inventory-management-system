#ifndef STOCK_H
#define STOCK_H

#include <string>
#include <vector>

struct StockItem {
    std::string name; // Name of the stock item
    int quantity;     // Quantity of the stock item
};

extern std::vector<StockItem> stock; // Global stock vector

void viewStock(); // Function to view all stock items

#endif
