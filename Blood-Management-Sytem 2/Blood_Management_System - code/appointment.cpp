#include "appointment.h"
#include <iostream>

void AppointmentScheduling::bookAppointment(const Appointment& appointment) {
    appointments.push(appointment);
}

void AppointmentScheduling::viewAppointments() const {
    std::priority_queue<Appointment> temp = appointments;
    while (!temp.empty()) {
        Appointment appointment = temp.top();
        std::cout << "Name: " << appointment.name << ", Phone: " << appointment.phone << ", Blood Group: " << appointment.bloodGroup << ", Priority: " << appointment.priority << "\n";
        temp.pop();
    }
}
