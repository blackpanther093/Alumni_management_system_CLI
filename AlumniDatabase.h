#ifndef ALUMNIDATABASE_H
#define ALUMNIDATABASE_H
#include<iostream>
#include<fstream>   //to read files
#include<sstream>   //to parse csv files
#include<vector>
using namespace std;

class AlumniDatabase {
private:
    vector<Alumni> alumniList;
    vector<Event> eventList;
    vector<Message> messageList;

public:
    // Add alumni to database
    void addAlumni(const Alumni& alumni) {
        alumniList.push_back(alumni);
        //cout << "Alumni added to database: " << alumni.getName() << endl;
    }
    
    vector<Alumni>& getAlumniList(){
        return alumniList;
    }
    vector<Event>& getEventList(){
        return eventList;
    }
    vector<Message>& getMessageList(){
        return messageList;
    }
    
    void loadAlumniFromFile(const string& dataset) {
        ifstream file(dataset);  // Open file for reading
        string line;
        
        // Check if file is open
        if (!file.is_open()) {
            cerr << "Failed to open file!" << endl;
            return;
        }

        while (getline(file, line)) {  // Read line by line
            stringstream ss(line);  // Stream to parse the line
            string id, name, degree, department, email, phone, jobTitle, company, location;
            int graduationYear;

            // Parse each field separated by commas
            getline(ss, id, ',');
            getline(ss, name, ',');
            ss >> graduationYear;
            ss.ignore();  // Ignore the comma after the year
            getline(ss, degree, ',');
            getline(ss, department, ',');
            getline(ss, email, ',');
            getline(ss, phone, ',');
            getline(ss, jobTitle, ',');
            getline(ss, company, ',');
            getline(ss, location, ',');
            
            // Create a new Alumni object with parsed data
            Alumni newAlumni(id, name, graduationYear, degree, department, email, phone, jobTitle, company, location);

            // Add the alumni to the database
            addAlumni(newAlumni);
        }

        file.close();  // Close the file after reading
    }

    // Method to search alumni by ID
    Alumni* searchAlumniByID(const string& alumniID) {
        string lowerID = alumniID;
        transform(lowerID.begin(), lowerID.end(), lowerID.begin(), [](unsigned char c) { return std::tolower(c); });
        for (auto& alumni : alumniList) {
            string a_id=alumni.getID();
            // Convert the entire ID string to lowercase
            transform(a_id.begin(), a_id.end(), a_id.begin(), [](unsigned char c) { return std::tolower(c); });
            if (a_id == lowerID) {
                return &alumni;
            }
        }
        return nullptr; // Return null if not found
    }
    
    // Search alumni by name - returns the first match
    Alumni* searchAlumniByName(const string& name) {
        string lowerID = name;
        transform(lowerID.begin(), lowerID.end(), lowerID.begin(), [](unsigned char c) { return std::tolower(c); });
        for (auto& alumni : alumniList) {
            string nm=alumni.getName();
            // Convert the entire name string to lowercase
            transform(nm.begin(), nm.end(), nm.begin(), [](unsigned char c) { return std::tolower(c); });
            if (nm == lowerID) {
                return &alumni;
            }
        }
        return nullptr; // Return nullptr if not found
    }

    // Search alumni by graduation year
    vector<Alumni*> searchAlumniByGraduationYear(int year) {
        vector<Alumni*> results;
        for (auto& alumni : alumniList) {
            if (alumni.getGraduationYear() == year) {
                results.push_back(&alumni);
            }
        }
        return results; // Returns vector of matching Alumni pointers
    }
    
    // Add event to database
    void addEvent(const Event& event) {
        eventList.push_back(event);
        //cout << "Event added to database: " << event.getName() << endl;
    }

    //Add Event from file
    void loadEventFromFile(const string& event_dataset) {
        ifstream file(event_dataset);  // Open file for reading
        string line;
        
        // Check if file is open
        if (!file.is_open()) {
            cerr << "Failed to open file!" << endl;
            return;
        }

        while (getline(file, line)) {  // Read line by line
            stringstream ss(line);  // Stream to parse the line
            string id, name, date, locn, desc;
            string participantsIDs;
            // Parse each field separated by commas
            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, date, ',');
            getline(ss, locn, ',');
            getline(ss, desc, ',');
            // Create a new Event object with parsed data
            

            getline(ss, participantsIDs);  // This assumes participants' IDs are comma-separated
            Event newEvent(id, name, date, locn, desc);

            // Now load participants for this event
            loadParticipantsForEvent(newEvent, participantsIDs);
            addEvent(newEvent);  // Add the event to the list
            //cout<<"\n";
        }

        file.close();  // Close the file after reading
    }
    
    // Method to load participants into the event from a string of IDs
    void loadParticipantsForEvent(Event& event, const string& participantsIDs) {
        stringstream ss(participantsIDs);
        string alumniID;
        
        // Loop through the participant IDs and add the corresponding alumni
        while (getline(ss, alumniID, ',')) {
            // Convert the entire ID string to lowercase
            transform(alumniID.begin(), alumniID.end(), alumniID.begin(), [](unsigned char c) { return std::tolower(c); });

            Alumni* participant = searchAlumniByID(alumniID);
            if (participant != nullptr) {
                event.addParticipant(participant);  // Add the participant to the event
            }
        }
    }
    
    // Send a message
    void sendMessage(const Message& message) {
        string a_id=message.getReceiverID();        
        // Convert the entire ID string to lowercase
        transform(a_id.begin(), a_id.end(), a_id.begin(), [](unsigned char c) { return std::tolower(c); });
        Alumni* recipient = searchAlumniByID(a_id);
        if (recipient == nullptr) {
            cout << "Error: No alumni found with ID " << message.getReceiverID() << endl;
            return; // Early exit if recipient is not found
        }
        
        messageList.push_back(message);
        cout << "Message sent from " << message.getSenderID() << " to " 
             << recipient->getName() << " (" << message.getReceiverID() << ") " << endl;
    }

    // Display all alumni
    void viewAllAlumni() const {
        for (const auto& alumni : alumniList) {
            //alumni.displayInfo();
            cout<<"\n";
            cout<<alumni;
        }
    }

    // Display all events
    void viewAllEvents() const {
        for (const auto& event : eventList) {
            //event.displayEventInfo();
            cout<<"\n";
            cout<<event;
        }
    }
    
    // Display all messages*
    void viewAllMessage() const {
        for (const auto& message : messageList) {
           cout<<"\n";
           message.viewMessage();

        }
    }
    // search an event with ID
    Event* searchEventByID(const string& eventID) {
        for (auto& event : eventList) {
            string e_id=event.getID();
            // Convert the entire ID string to lowercase
            transform(e_id.begin(), e_id.end(), e_id.begin(), [](unsigned char c) { return std::tolower(c); });
            if (e_id == eventID) {
                return &event;
            }
        }
        return nullptr; // Return null if not found
    }

    //add Participant to event
    bool addParticipantToEvent(const string& eventID, const string& alumniID) {
        Event* event = searchEventByID(eventID);
        Alumni* alumni = searchAlumniByID(alumniID);
        
        if (event && alumni) {
            event->addParticipant(alumni);
            //cout << "Participant added to event.\n";
            return true;
        } else {
            cout << "Event or Alumni not found.\n";
            return false;
        }
    }
    //remove an alumni
    void removeAlumni(string id){
        Alumni* rem=searchAlumniByID(id);
        for (auto it = alumniList.begin(); it != alumniList.end(); ++it) {
            if (&(*it) == rem) {
                alumniList.erase(it);
                cout << "Alumni removed successfully." << endl;
                return;
            }}   
                cout << "Alumni ID not found." << endl;
            
    }
    
    //remove an Event
    void removeEvent(string eventID){
    Event* remove=searchEventByID(eventID);
    for (auto it = eventList.begin(); it != eventList.end(); ++it) {
            if (&(*it) == remove) {
                eventList.erase(it);
                cout << "Event removed successfully!" << endl;
                return;
            }}   
                cout << "Event ID not found!" << endl;
    }
    
    
};
#endif
