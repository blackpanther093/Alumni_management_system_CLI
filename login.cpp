#include"login.h"
#include<iostream>
using namespace std;

// Function to print colored text
void printColor(const string& message, const string& colorCode) {
    cout << colorCode << message << "\033[0m" << endl;  // Reset the color at the end
}

void loadDatabase(AlumniDatabase& alumniDatabase) {
    alumniDatabase.loadAlumniFromFile("dataset.csv"); // Load alumni data from file
    alumniDatabase.loadEventFromFile("event_dataset.csv"); // Load event data from file
}

// Credentials for Admin and Alumni
User* login(string &username, string& password, AlumniDatabase& db) {
    transform(username.begin(), username.end(), username.begin(), [](unsigned char c) { return std::tolower(c); });
    // Case for Admin login
    if (username == "admin" && password == "admin123") {
        return new Administrator("admin", "Admin", "admin@admin.com", "0000000000", "Admin");
    }

    // Case for Alumni login

    else if (username == "alumni") {
        transform(password.begin(), password.end(), password.begin(), [](unsigned char c) { return std::tolower(c); });
        Alumni* alumni = db.searchAlumniByID(password);

        if (alumni!=nullptr) {
            return alumni;  // Return the alumni if ID matches
      }
        else {
            cerr << "Error: Alumni not found with the given ID." << endl;
            return nullptr;
        }
        }
    // If no valid login found, return null pointer
    return nullptr;
}

bool isAdmin(User* user) {
    return dynamic_cast<Administrator*>(user) != nullptr;
}

void displayMenu(User* user) {
    printColor("\n--- Alumni Management System ---", "\033[1;34m");
    cout << "1. View All Alumni" << endl;
    if (isAdmin(user)) cout << "2. Add Alumni" << endl;
    cout << "3. Search Alumni by ID" << endl;
    cout << "4. Search Alumni by Name" << endl;
    if (isAdmin(user)) cout << "5. Update Alumni Information" << endl;
    if (isAdmin(user)) cout << "6. Remove Alumni" << endl;
    cout << "7. View All Events" << endl;
    if (isAdmin(user)) cout << "8. Add event" << endl;
    cout << "9. Search event" << endl;
    if (isAdmin(user)) cout << "10. Add Participant to any event" << endl;
    if (isAdmin(user)) cout << "11. Update Event" << endl;
    if (isAdmin(user)) cout << "12. Remove Event" << endl;
    cout << "13. Send Message" << endl;
    cout << "14. View all messages" << endl;
    cout << "15. Exit" << endl;
    cout << "Select an option: ";
}

void handleViewAllAlumni(AlumniDatabase& db) {
    db.viewAllAlumni();
}

void handleViewAllEvents(AlumniDatabase& db) {
    db.viewAllEvents();
}

void handleViewMessages(AlumniDatabase& db) {
    db.viewAllMessage();
}

void handleSearchAlumniByID(AlumniDatabase& db) {
    string alumniID;
    cout << "Enter Alumni ID: ";
    cin >> alumniID;
    transform(alumniID.begin(), alumniID.end(), alumniID.begin(), [](unsigned char c) { return std::tolower(c); });
    Alumni* alumni = db.searchAlumniByID(alumniID);
    if (alumni) {
        cout << "--- Alumni Details ---\n";
        cout << *alumni << endl;   //// Use overloaded operator<< for Alumni class
    } else {
        cout << "Alumni not found." << endl;
    }
}

void handleSearchAlumniByName(AlumniDatabase& db) {
    string name;
    cin.ignore();
    cout << "Enter Alumni Name: ";
    getline(cin,name);
    // Convert the entire name string to lowercase
    cout<<name<<endl;
    transform(name.begin(), name.end(), name.begin(), [](unsigned char c) { return std::tolower(c); });
    Alumni* alumni = db.searchAlumniByName(name);
    if (alumni) {
        cout << "--- Alumni Details ---\n";
        cout << *alumni << endl;
    } else {
        cout << "Alumni not found." << endl;
    }
}

void handleAddAlumni(Administrator* admin, AlumniDatabase& db) {
    if (admin) {
        string id, name, degree, department, email, phone, jobTitle, company, location;
        int graduationYear;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Graduation Year: ";
        cin >> graduationYear;
        cout << "Enter Degree: ";
        cin >> degree;
        cout << "Enter Department: ";
        cin >> department;
        cout << "Enter Email: ";
        cin >> email;
        cout << "Enter Phone: ";
        cin >> phone;
        cout << "Enter Job Title: ";
        cin >> jobTitle;
        cout << "Enter Company: ";
        cin >> company;
        cout << "Enter Location: ";
        cin >> location;

        Alumni newAlumni(id, name, graduationYear, degree, department, email, phone, jobTitle, company, location);
        db.addAlumni(newAlumni);
        cout << "Alumni added successfully!" << endl;
    }
    
}

void handleUpdateAlumniInfo(Administrator* admin, AlumniDatabase& db) {
    if (admin) {
        string alumniID;
        cout << "Enter Alumni ID to update: ";
        cin >> alumniID;
        // Convert the entire id string to lowercase
        transform(alumniID.begin(), alumniID.end(), alumniID.begin(), [](unsigned char c) { return std::tolower(c); });
        admin->updateAlumniInfo(alumniID, db);
    }
    
}

void handleRemoveAlumni(Administrator* admin, AlumniDatabase& db) {
    if (admin) {
        string alumniID;
        cout << "Enter Alumni ID to remove: ";
        cin >> alumniID;
        // Convert the entire id string to lowercase
        transform(alumniID.begin(), alumniID.end(), alumniID.begin(), [](unsigned char c) { return std::tolower(c); });
        db.removeAlumni(alumniID);
    }
}

void handleSendMessage(User* user, AlumniDatabase& db) {
    string messageContent,recipientID;
    cout << "Enter Message: ";
    cin.ignore();  // To clear the buffer before getline
    getline(cin, messageContent);
    
    string date;
    // Get the current date in YYYY-MM-DD format using chrono
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d");
        date = ss.str();

    // Ask admin how they want to send the message
        int choice=0;
        if(isAdmin(user)){
            cout << "\nChoose message recipient(s):" << endl; 
            cout << "1. Send to a specific alumni (by ID)" << endl;
            cout << "2. Send to all alumni of a specific graduation year" << endl;
            cout << "3. Send to all alumni" << endl;
            cout << "Enter choice: ";
            cin >> choice;}
        
        if (choice == 1 || !isAdmin(user)) {
        // Send to specific alumni
        cout << "Enter Recipient Alumni ID: ";
        cin >> recipientID;
        // Convert the entire id string to lowercase
        transform(recipientID.begin(), recipientID.end(), recipientID.begin(), [](unsigned char c) { return std::tolower(c); });
        
        if (user == nullptr) {
    cout << "Error: User is not logged in." << endl;
    return;
}
        Alumni* recipient = db.searchAlumniByID(recipientID);
        if (recipient == nullptr) {
            cout << "Invalid Recipient ID." << endl;
            return;
        }
        Message newMessage("M" + to_string(rand() % 1000), user->getID(), recipientID, messageContent, date);
        db.sendMessage(newMessage);
        //cout <<message<< endl;

    }
      else if (choice == 2 && isAdmin(user)) {
            // Send to all alumni of a specific graduation year
            int year;
            cout << "Enter Graduation Year: ";
            cin >> year;
            cout<<"\n";
            // Create a message for each alumni with that year
            vector<Alumni*> alumniList = db.searchAlumniByGraduationYear(year);
            
            if (alumniList.empty()) {
                cout << "No alumni found for the given graduation year." << endl;
                return;
            }
            // Create a message for each alumni with that year
            for (size_t i = 0; i < alumniList.size(); ++i) {
                Alumni* alumni = alumniList[i];
                Message newMessage("M" + to_string(rand() % 1000), user->getID(), alumni->getID(), messageContent, date);
                db.sendMessage(newMessage);
                //cout <<message<< endl;
        }}
        
        else if (choice == 3 && isAdmin(user)) {
              // Send to all alumni
              bool sentToAnyone = false;
              for (auto& alumni : db.getAlumniList()) {
                  Message message("M" + to_string(rand() % 1000), user->getID(), alumni.getID(), messageContent, date);
                  db.sendMessage(message);
                 // cout << message<< endl;
                  sentToAnyone = true;
              }
              if (!sentToAnyone) {
                  cout << "No alumni available to send the message." << endl;
        }}
        else if((choice ==2 || choice == 3) && !isAdmin){
              cout << "Access denied. Admin privileges required."<<endl;
            }
    else {
        cout << "Invalid choice. Please choose between 1, 2, or 3." << endl;
    }
  }

void handleAddEvent(Administrator* admin, AlumniDatabase& db) {
    if (admin) {
        string eventID, name, date, location, description;
        cout << "Enter Event ID: ";
        cin >> eventID;
        cout << "Enter Event Name: ";
        cin >> name;
        cout << "Enter Event Date: ";
        cin >> date;
        cout << "Enter Event Location: ";
        cin >> location;
        cout << "Enter Event Description: ";
        cin >> description;

        Event newEvent(eventID, name, date, location, description);
        db.addEvent(newEvent);
        cout << "Event added successfully!" << endl;
    }

}

void handleSearchEventByID(AlumniDatabase& db) {
    string eventID;
    cout << "Enter Event ID: ";
    cin >> eventID;
    // Convert the entire name string to lowercase
    transform(eventID.begin(), eventID.end(), eventID.begin(), [](unsigned char c) { return std::tolower(c); });
    Event* event = db.searchEventByID(eventID);
    if (event) {
        cout << *event << endl;
    } else {
        cout << "Event not found." << endl;
    }
}

void handleAddParticipantToEvent(AlumniDatabase& db) {
    string eventID, alumniID;
    cout << "Enter Event ID: ";
    cin >> eventID;
    cout << "Enter Alumni ID: ";
    cin >> alumniID;
    // Convert the entire event id string to lowercase
    transform(eventID.begin(), eventID.end(), eventID.begin(), [](unsigned char c) { return std::tolower(c); });
    // Convert the entire alumni id string to lowercase
    transform(alumniID.begin(), alumniID.end(), alumniID.begin(), [](unsigned char c) { return std::tolower(c); });
    if (db.addParticipantToEvent(eventID, alumniID)) {
        cout << "Participant added to event successfully." << endl;
    } else {
        cout << "Failed to add participant to event." << endl;
    }
}

void handleUpdateEvent(Administrator* admin, AlumniDatabase& db) {
    if (admin) {
        string eventID;
        cout << "Enter Event ID to update: ";
        cin >> eventID;
        // Convert the entire event id string to lowercase
        transform(eventID.begin(), eventID.end(), eventID.begin(), [](unsigned char c) { return std::tolower(c); });
        Event* event = db.searchEventByID(eventID);
        if (event) {
            string name, date, location, description;
            cout << "Enter new Event Name (current: " << event->getName() << "): ";
            cin >> name;
            event->setName(name);
            
            cout << "Enter new Event Date (current: " << event->getDate() << "): ";
            cin >> date;
            event->setDate(date);
            
            cout << "Enter new Event Location (current: " << event->getLocation() << "): ";
            cin >> location;
            event->setLocation(location);
            
            cout << "Enter new Event Description (current: " << event->getDescription() << "): ";
            cin >> description;
            event->setDescription(description);

            cout << "Event updated successfully!" << endl;
        } else {
            cout << "Event not found!" << endl;
        }
    }

}

void handleRemoveEvent(Administrator* admin, AlumniDatabase& db) {
    if (admin) {
        string eventID;
        cout << "Enter Event ID to remove: ";
        cin >> eventID;
        // Convert the entire event id string to lowercase
        transform(eventID.begin(), eventID.end(), eventID.begin(), [](unsigned char c) { return std::tolower(c); });
        Event* event = db.searchEventByID(eventID);
            db.removeEvent(eventID);
    }
}

