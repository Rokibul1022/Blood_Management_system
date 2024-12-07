#ifndef BLOOD_SEARCH_H
#define BLOOD_SEARCH_H

#include <string>

struct BloodUnit {
    std::string bloodGroup;
    int quantity;
    BloodUnit* left;
    BloodUnit* right;

    BloodUnit(const std::string& bg, int qty) : bloodGroup(bg), quantity(qty), left(nullptr), right(nullptr) {}
};

class BloodSearch {
private:
    BloodUnit* root;
    void addBloodUnit(BloodUnit*& node, const std::string& bloodGroup, int quantity);
    void inOrderTraversal(BloodUnit* node) const;
    BloodUnit* searchBloodGroup(BloodUnit* node, const std::string& bloodGroup) const;
public:
    BloodSearch() : root(nullptr) {}
    ~BloodSearch();
    void addBloodUnit(const std::string& bloodGroup, int quantity);
    void searchBloodGroup(const std::string& bloodGroup) const;
    void viewAllBloodUnits() const;
    void clear(BloodUnit* node);
};

#endif // BLOOD_SEARCH_H
