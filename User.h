#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User {
protected:
    string id;        // User ID (unique identifier)
    string name;      // Name of the user
    string email;     // Email address
    string phoneNumber; // Phone number

public:
    // Constructors
    User() {}
    User(const string& id, const string& name, const string& email, const string& phone)
        : id(id), name(name), email(email), phoneNumber(phone) {}

    // Virtual Destructor
    virtual ~User() {}

    // Getters
    string getID() const { return id; }
    string getName() const { return name; }
    string getEmail() const { return email; }
    string getPhoneNumber() const { return phoneNumber; }

    // Setters
    void setID(const string& id) { this->id = id; }
    void setName(const string& name) { this->name = name; }
    void setEmail(const string& email) { this->email = email; }
    void setPhoneNumber(const string& phone) { this->phoneNumber = phone; }

    // Display Information (Polymorphism example)
    virtual void displayInfo() const {
        cout << "ID: " << id << ", Name: " << name << ", Email: " << email 
             << ", Phone: " << phoneNumber << endl;
    }
};

#endif

