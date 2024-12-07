#include "donor_registration.h"
#include <iostream>

void DonorRegistration::registerDonor(const Donor& donor) {
    donors[donor.bloodGroup] = donor;
}

void DonorRegistration::searchDonor(const std::string& bloodGroup) const {
    std::unordered_map<std::string, Donor>::const_iterator it = donors.find(bloodGroup);
    if (it != donors.end()) {
        std::cout << "Name: " << it->second.name << ", Phone: " << it->second.phone << ", Blood Group: " << it->second.bloodGroup << "\n";
    } else {
        std::cout << "Donor not found.\n";
    }
}
