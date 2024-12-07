#include "datastore.h"
#include <fstream>
#include <iostream>

void DataStore::saveData(const UserAuth& userAuth, const Inventory& inventory, const DonorRegistration& donorReg, const AppointmentScheduling& appointmentSched, const BloodSearch& bloodSearch) {
    std::ofstream file("data.txt");

    if (!file) {
        std::cerr << "Failed to open file for saving.\n";
        return;
    }

    User* current = userAuth.getHead();  
    while (current) {
        file << "User " << current->name << " " << current->email << " " << current->password << "\n";
        current = current->next;
    }

    

    file.close();
}

void DataStore::loadData(UserAuth& userAuth, Inventory& inventory, DonorRegistration& donorReg, AppointmentScheduling& appointmentSched, BloodSearch& bloodSearch) {
    std::ifstream file("data.txt");

    if (!file) {
        std::cerr << "Failed to open file for loading.\n";
        return;
    }

    
    std::string type;
    while (file >> type) {
        if (type == "User") {
            std::string name, email, password;
            file >> name >> email >> password;
            userAuth.addUser(name, email, password);
        }

    }

    file.close();
}
