#include "Alumni.h"
#include "Event.h"
#include"Message.h"

// Overload << operator to print Alumni details
ostream& operator<<(ostream& out, const Alumni& alumni) {
    out << "Alumni ID: " << alumni.getID() << endl;
    out << "Name: " << alumni.getName() << endl;
    out << "Graduation Year: " << alumni.getGraduationYear() << endl;
    out << "Degree: " << alumni.getDegree() << endl;
    out << "Department: " << alumni.getDepartment() << endl;
    out << "Email: " << alumni.getEmail() << endl;
    out << "Phone: " << alumni.getPhoneNumber() << endl;
    out << "Job Title: " << alumni.getCurrentPosition() << endl;
    out << "Company: " << alumni.getCompany() << endl;
    out << "Location: " << alumni.getLocation() << endl;
    return out;
}

//Overload >> operator to take Alumni details
istream& operator>>(istream& in, Alumni& alumni) {
    cout << "Enter Alumni ID: "; in >> alumni.id;
    cout << "Enter Name: "; in.ignore(); getline(in, alumni.name);
    cout << "Enter Graduation Year: "; in >> alumni.graduationYear;
    cout << "Enter Degree: "; in.ignore(); getline(in, alumni.degree);
    cout << "Enter Department: "; getline(in, alumni.department);
    cout << "Enter Email: "; getline(in, alumni.email);
    cout << "Enter Phone Number: "; getline(in, alumni.phoneNumber);
    cout << "Enter Current Position: "; getline(in, alumni.currentPosition);
    cout << "Enter Company: "; getline(in, alumni.company);
    cout << "Enter Location: "; getline(in, alumni.location);
    return in;
}

// Overload << operator to print Event details
ostream& operator<<(ostream& out, const Event& event) {
    out << "Event ID: " << event.getID() << endl;
    out << "Event Name: " << event.getName() << endl;
    out << "Date: " << event.getDate() << endl;
    out << "Location: " << event.getLocation() << endl;
    out << "Description: " << event.getDescription() << endl;

    // Print participants if there are any
    out << "Participants: ";
    if (event.getParticipants().empty()) {
        out << "No participants yet." << endl;
    } else {
        for (const auto& participant : event.getParticipants()) {
            out << participant->getName() << " (ID: " << participant->getID() << "), ";
        }
        out << endl;
    }

    return out;
}

//Overload >> operator to take Event details
istream& operator>>(istream& in, Event & e){
    in.ignore();
    cout << "Enter new Event ID: ";getline(in,e.eventID);
    cout << "Enter new Event Name: ";getline(in, e.name);
    cout << "Enter new Date (YYYY-MM-DD): "; getline(in, e.date);
    cout << "Enter new Location: ";getline(in, e.location);
    cout << "Enter new Description: ";getline(in, e.description);
    //Add participants to it using seperate function
    return in;
}

// Overload << operator to print Message details
ostream& operator<<(ostream& out, const Message& message) {
    out << "Message ID: " << message.getMessageID() << endl;
    out << "From Alumni ID: " << message.getSenderID() << endl;
    out << "To Alumni ID: " << message.getReceiverID() << endl;
    out << "Content: " << message.getContent() << endl;
    out << "Date: " << message.getDate() << endl;
    return out;
}

