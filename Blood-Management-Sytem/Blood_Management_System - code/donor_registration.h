#ifndef DONOR_REGISTRATION_H
#define DONOR_REGISTRATION_H

#include <string>
#include <unordered_map>

struct Donor {
    std::string name;
    std::string phone;
    std::string bloodGroup;
};

class DonorRegistration {
private:
    std::unordered_map<std::string, Donor> donors;
public:
    void registerDonor(const Donor& donor);
    void searchDonor(const std::string& phone) const;
};

#endif // DONOR_REGISTRATION_H
