#ifndef EVENT_H
#define EVENT_H

#include <vector>
#include<iostream>
using namespace std;

class Event {
private:
    string eventID;
    string name;
    string date;
    string location;
    string description;
    vector<Alumni*> participants; // List of pointers to Alumni participants

public:
    // Constructor
    Event(){}
    Event(string id, string n, string d, string loc, string desc)
        : eventID(id), name(n), date(d), location(loc), description(desc) {}
    
// Getter functions
    string getID() const { return eventID; }
    string getName() const { return name; }
    string getDate() const { return date; }
    string getLocation() const { return location; }
    string getDescription() const { return description; }
    
//setter functions
    void setName(string newName) { name=newName; }
    void setDate(string newDate) { date=newDate; }
    void setLocation(string newLocation) { location=newLocation; }
    void setDescription(string newDescription) { description=newDescription; }
    
    const vector<Alumni*>& getParticipants() const { return participants; }
    
    // Overload << operator to print event details
    friend ostream& operator<<(ostream& out, const Event& event);
    
    //Overload >> operator
    friend istream& operator>>(istream&, Event&);
    
    // Add a participant
    void addParticipant(Alumni* participant) {
        participants.push_back(participant);
        //cout << "Added " << participant->getName() << " to event " << name << endl;
    }

    // Remove a participant by pointer
    void removeParticipant(Alumni* participant) {
        for (auto it = participants.begin(); it != participants.end(); ++it) {
            if (*it == participant) {
                participants.erase(it);
                cout << "Removed " << participant->getName() << " from event " << name << endl;
                return;
            }
        }
    }

    // Display Event Information
    void displayEventInfo() const {
        cout << "Event ID: " << eventID << "\nName: " << name 
             << "\nDate: " << date << "\nLocation: " << location 
             << "\nDescription: " << description << "\nParticipants: ";
        for (const auto& participant : participants) {
            cout << participant->getName() << ", ";
        }
        cout << endl;
    }
};
#endif
