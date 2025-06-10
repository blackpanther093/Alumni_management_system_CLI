#ifndef ALUMNI_H
#define ALUMNI_H

#include <iostream>
#include"User.h"
#include <string>
using namespace std;

class Alumni:public User {
private:
    int graduationYear;
    string degree;
    string department;
    string currentPosition;
    string company;
    string location;

public:
    // Constructor
    Alumni() {}
    Alumni(string id, string name, int graduationYear, string degree, 
            string department, string email, string phoneNumber, 
            string currentPosition, string company, string location)
        : User(id, name, email, phoneNumber), graduationYear(graduationYear), 
          degree(degree), department(department), currentPosition(currentPosition), 
          company(company), location(location) {}

    // Getters and Setters for Alumni-specific fields
    int getGraduationYear() const { return graduationYear; }
    void setGraduationYear(int year) { graduationYear = year; }

    string getDegree() const { return degree; }
    void setDegree(const string& degree) { this->degree = degree; }

    string getDepartment() const { return department; }
    void setDepartment(const string& department) { this->department = department; }

    string getCurrentPosition() const { return currentPosition; }
    void setCurrentPosition(const string& position) { this->currentPosition = position; }

    string getCompany() const { return company; }
    void setCompany(const string& company) { this->company = company; }

    string getLocation() const { return location; }
    void setLocation(const string& location) { this->location = location; }

    // Overload << operator to print alumni details
    friend ostream& operator<<(ostream& out, const Alumni& alumni);
    
    //Overload >> operator to take alumni details
    friend istream& operator>>(istream&, Alumni&);
    
    //overload < operator to compare graduation year
    bool operator<(const Alumni& other) const {
        return graduationYear < other.graduationYear;
    }
    
    // Method to update contact information
    void updateContactInfo(const string& newEmail, const string& newPhone) {
        email = newEmail;
        phoneNumber = newPhone;
    }

    // Method to update employment information
    void updateEmploymentInfo(const string& newPosition, const string& newCompany, const string& newLocation) {
        currentPosition = newPosition;
        company = newCompany;
        location = newLocation;
    }

    // Overriding displayInfo (Polymorphism)
    void displayInfo() const override {
        User::displayInfo();
        cout << "Graduation Year: " << graduationYear << ", Degree: " << degree
             << ", Department: " << department << ", Current Position: " << currentPosition
             << ", Company: " << company << ", Location: " << location << endl;
    }
    
    string getRole() const {
        return "Alumni";
    }
};

#endif


