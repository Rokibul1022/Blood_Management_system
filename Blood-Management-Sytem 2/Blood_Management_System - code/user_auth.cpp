#include "user_auth.h"
#include <iostream>
#include <string>
UserAuth::UserAuth() : head(nullptr) {}

UserAuth::~UserAuth() {
    User* current = head;
    while (current != nullptr) {
        User* next = current->next;
        delete current;
        current = next;
    }
}

void UserAuth::addUser(const std::string& name, const std::string& email, const std::string& password) {
    User* newUser = new User(name, email, password, nullptr); 
    newUser->next = head;
    head = newUser;
}

bool UserAuth::authenticateUser(const std::string& email, const std::string& password) {
    User* current = head;
    while (current != nullptr) {
        if (current->email == email && current->password == password) {
            return true;
        }
        current = current->next;
    }
    return false;
}

User* UserAuth::getHead() const {
    return head;
}
