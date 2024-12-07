#ifndef USER_AUTH_H
#define USER_AUTH_H

#include <string>

struct User {
    std::string name;
    std::string email;
    std::string password;
    User* next;

    User(const std::string& name, const std::string& email, const std::string& password, User* next = nullptr)
        : name(name), email(email), password(password), next(next) {}
};

class UserAuth {
private:
    User* head;
public:
    UserAuth();
    ~UserAuth();
    void addUser(const std::string& name, const std::string& email, const std::string& password);
    bool authenticateUser(const std::string& email, const std::string& password);
    User* getHead() const; 
};

#endif // USER_AUTH_H
