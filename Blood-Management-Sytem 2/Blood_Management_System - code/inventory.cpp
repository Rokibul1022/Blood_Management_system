#include "inventory.h"
#include <iostream>

void Inventory::addItem(const Item& item) {
    items.push(item);
}

void Inventory::removeItem() {
    if (!items.empty()) {
        items.pop();
    } else {
        std::cout << "Inventory is empty.\n";
    }
}

void Inventory::viewInventory() const {
    std::stack<Item> temp = items;
    while (!temp.empty()) {
        Item item = temp.top();
        std::cout << "Blood Type: " << item.bloodType << ", Quantity: " << item.quantity << "\n";
        temp.pop();
    }
}
