#ifndef DATASTORE_H
#define DATASTORE_H

#include "user_auth.h"
#include "inventory.h"
#include "donor_registration.h"
#include "appointment.h"
#include "blood_search.h"

class DataStore {
public:
    void saveData(const UserAuth& userAuth, const Inventory& inventory, const DonorRegistration& donorReg, const AppointmentScheduling& appointmentSched, const BloodSearch& bloodSearch);
    void loadData(UserAuth& userAuth, Inventory& inventory, DonorRegistration& donorReg, AppointmentScheduling& appointmentSched, BloodSearch& bloodSearch);
};

#endif // DATASTORE_H
