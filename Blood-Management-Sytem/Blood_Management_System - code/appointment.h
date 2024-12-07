#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
#include <queue>
#include <vector>

struct Appointment {
    std::string name;
    std::string phone;
    std::string bloodGroup;
    int priority;

    bool operator<(const Appointment& other) const {
        return priority < other.priority;
    }
};

class AppointmentScheduling {
private:
    std::priority_queue<Appointment> appointments;
public:
    void bookAppointment(const Appointment& appointment);
    void viewAppointments() const;
};

#endif // APPOINTMENT_H
