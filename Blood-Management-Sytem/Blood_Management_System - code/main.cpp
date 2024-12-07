

#include "user_auth.h"
#include "user_auth.cpp"
#include "inventory.h"
#include "inventory.cpp"
#include "donor_registration.h"
#include "donor_registration.cpp"
#include "appointment.h"
#include "appointment.cpp"
#include "blood_search.h"
#include "blood_search.cpp"
#include "datastore.h"
#include "datastore.cpp"
#include <iostream>

void showMenu() {
    std::cout << "Main Menu:\n";
    std::cout << "1. User Authentication and Authorization\n";
    std::cout << "2. Inventory Management\n";
    std::cout << "3. Donor Registration\n";
    std::cout << "4. Appointment Scheduling\n";
    std::cout << "5. Blood Group Search\n";
    std::cout << "6. Exit\n";
    std::cout <<"Your Response : ";
}

int main() {
    UserAuth userAuth;
    Inventory inventory;
    DonorRegistration donorReg;
    AppointmentScheduling appointmentSched;
    BloodSearch bloodSearch;
    DataStore dataStore;

    dataStore.loadData(userAuth, inventory, donorReg, appointmentSched, bloodSearch);

    while (true) {
        showMenu();
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "1. Register\n2. Login\n";
                std::cout << "Your Response : ";
                int subChoice;
                std::cin >> subChoice;
                if (subChoice == 1) {
                    std::string name, email, password;
                    std::cout << "Enter name: ";
                    std::cin >> name;
                    std::cout << "Enter email: ";
                    std::cin >> email;
                    std::cout << "Enter password: ";
                    std::cin >> password;
                    userAuth.addUser(name, email, password);
                    std::cout << "User registered successfully.\n";
                } else if (subChoice == 2) {
                    std::string email, password;
                    std::cout << "Enter email: ";
                    std::cin >> email;
                    std::cout << "Enter password: ";
                    std::cin >> password;
                    if (userAuth.authenticateUser(email, password)) {
                        std::cout << "Login successful!\n";
                    } else {
                        std::cout << "Invalid credentials.\n";
                    }
                }
                break;
            }
            case 2: {
                std::cout << "1. Add Item\n2. Remove Item\n3. View Inventory\n";
                std::cout << "Your Response : ";
                int subChoice;
                std::cin >> subChoice;
                if (subChoice == 1) {
                    Item item;
                    std::cout << "Enter blood type: ";
                    std::cin >> item.bloodType;
                    std::cout << "Enter quantity: ";
                    std::cin >> item.quantity;
                    inventory.addItem(item);
                    std::cout << "Item added to inventory successfully.\n";
                } else if (subChoice == 2) {
                    inventory.removeItem();
                    std::cout << "Item removed from inventory.\n";
                } else if (subChoice == 3) {
                    inventory.viewInventory();
                }
                break;
            }
            case 3: {
                std::cout << "1. Register Donor\n2. Search Donor\n";
                std::cout << "Your Response : ";
                int subChoice;
                std::cin >> subChoice;
                if (subChoice == 1) {
                    Donor donor;
                    std::cout << "Enter name: ";
                    std::cin >> donor.name;
                    std::cout << "Enter phone: ";
                    std::cin >> donor.phone;
                    std::cout << "Enter blood group: ";
                    std::cin >> donor.bloodGroup;
                    donorReg.registerDonor(donor);
                    std::cout << "Donor registered successfully.\n";
                } else if (subChoice == 2) {
                    
                    std::string bloodGroup;
                    std::cout <<"Enter Blood group : ";
                    std::cin >> bloodGroup;
                    donorReg.searchDonor(bloodGroup);
                }
                break;
            }
            case 4: {
                std::cout << "1. Book Appointment\n2. View Appointments\n";
                std::cout << "Your Response : ";
                int subChoice;
                std::cin >> subChoice;
                if (subChoice == 1) {
                    Appointment appointment;
                    std::cout << "Enter name: ";
                    std::cin >> appointment.name;
                    std::cout << "Enter phone: ";
                    std::cin >> appointment.phone;
                    std::cout << "Enter blood group needed: ";
                    std::cin >> appointment.bloodGroup;
                    std::cout << "Enter priority (1-10): ";
                    std::cin >> appointment.priority;
                    appointmentSched.bookAppointment(appointment);
                    std::cout << "Appointment booked successfully.\n";
                } else if (subChoice == 2) {
                    appointmentSched.viewAppointments();
                }
                break;
            }
            case 5: {
                std::cout << "1. Add Blood Unit\n2. Search Blood Group\n3. View All Blood Units\n";
                std::cout << "Your Response : ";
                int subChoice;
                std::cin >> subChoice;
                if (subChoice == 1) {
                    std::string bloodGroup;
                    int quantity;
                    std::cout << "Enter blood group: ";
                    std::cin >> bloodGroup;
                    std::cout << "Enter quantity: ";
                    std::cin >> quantity;
                    bloodSearch.addBloodUnit(bloodGroup, quantity);
                    std::cout << "Blood unit added successfully.\n";
                } else if (subChoice == 2) {
                    std::string bloodGroup;
                    std::cout << "Enter blood group: ";
                    std::cin >> bloodGroup;
                    bloodSearch.searchBloodGroup(bloodGroup);
                } else if (subChoice == 3) {
                    bloodSearch.viewAllBloodUnits();
                }
                break;
            }
            case 6: {
                dataStore.saveData(userAuth, inventory, donorReg, appointmentSched, bloodSearch);
                std::cout << "Data saved successfully. Exiting program.\n";
                return 0;
            }
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
