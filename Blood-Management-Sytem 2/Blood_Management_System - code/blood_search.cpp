#include "blood_search.h"
#include <iostream>

void BloodSearch::addBloodUnit(const std::string& bloodGroup, int quantity) {
    addBloodUnit(root, bloodGroup, quantity);
}

void BloodSearch::addBloodUnit(BloodUnit*& node, const std::string& bloodGroup, int quantity) {
    if (!node) {
        node = new BloodUnit(bloodGroup, quantity);
    } else if (bloodGroup < node->bloodGroup) {
        addBloodUnit(node->left, bloodGroup, quantity);
    } else if (bloodGroup > node->bloodGroup) {
        addBloodUnit(node->right, bloodGroup, quantity);
    } else {
        node->quantity += quantity;
    }
}

void BloodSearch::searchBloodGroup(const std::string& bloodGroup) const {
    BloodUnit* result = searchBloodGroup(root, bloodGroup);
    if (result) {
        std::cout << "Blood Group: " << result->bloodGroup << ", Quantity: " << result->quantity << "\n";
    } else {
        std::cout << "Blood group not found.\n";
    }
}

BloodUnit* BloodSearch::searchBloodGroup(BloodUnit* node, const std::string& bloodGroup) const {
    if (!node || node->bloodGroup == bloodGroup) {
        return node;
    }
    if (bloodGroup < node->bloodGroup) {
        return searchBloodGroup(node->left, bloodGroup);
    } else {
        return searchBloodGroup(node->right, bloodGroup);
    }
}

void BloodSearch::viewAllBloodUnits() const {
    inOrderTraversal(root);
}

void BloodSearch::inOrderTraversal(BloodUnit* node) const {
    if (node) {
        inOrderTraversal(node->left);
        std::cout << "Blood Group: " << node->bloodGroup << ", Quantity: " << node->quantity << "\n";
        inOrderTraversal(node->right);
    }
}

BloodSearch::~BloodSearch() {
    clear(root);
}

void BloodSearch::clear(BloodUnit* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}
