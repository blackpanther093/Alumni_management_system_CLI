#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include<iostream>
#include"User.h"
#include "AlumniDatabase.h"
using namespace std;

class Administrator:public User {
private:
    string role;
    
public:
    // Constructor
    Administrator() {}
    Administrator(const string& adminID, const string& name, const string& email, const string& phoneNumber, const string& role)
        : User(adminID,name, email, phoneNumber), role(role) {}
        
    string getRole() const { return role; }
    void setRole(const string& role) { this->role = role; }
    
    // Method to update alumni information
    void updateAlumniInfo(const string& alumniID, AlumniDatabase& alumniDatabase) {
        Alumni* alumni = alumniDatabase.searchAlumniByID(alumniID);
        if (alumni) {
            string newEmail, newPhone;
            cout << "Enter new email: ";
            cin >> newEmail;
            cout << "Enter new phone number: ";
            cin >> newPhone;
            alumni->updateContactInfo(newEmail, newPhone);
            cout << "--- Updated info for " << alumni->getName() << " ---" << endl;
        } else {
            cout << "Alumni with ID " << alumniID << " not found." << endl;
        }
    }
    
    // Overriding displayInfo (Polymorphism)
    void displayInfo() const override {
        User::displayInfo(); // Display common user info
        cout << "Role: " << role << endl;
    }
    
    

};
#endif
