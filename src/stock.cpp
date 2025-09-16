#include "stock.h"
#include <iostream>

std::vector<StockItem> stock = {
    {"Apple", 50},
    {"Orange", 30},
    {"Banana", 20}
};

void viewStock() {
    std::cout << "\n--- Available Stock ---\n";
    for (const auto& item : stock) {
        std::cout << "Item: " << item.name << ", Quantity: " << item.quantity << std::endl;
    }
}
