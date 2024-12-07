#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <stack>

struct Item {
    std::string bloodType;
    int quantity;
};

class Inventory {
private:
    std::stack<Item> items;
public:
    void addItem(const Item& item);
    void removeItem();
    void viewInventory() const;
};

#endif // INVENTORY_H
