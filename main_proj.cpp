#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <chrono>
#include <iomanip>
#include <sstream>
#include "Alumni.h"
#include "Event.h"
#include "Message.h"
#include "Administrator.h"
#include "AlumniDatabase.h"
#include "login.h"
#include"User.h"
using namespace std;


int main() {
    AlumniDatabase db;
    User* currentUser = nullptr;
    
    //Database loading from file
    loadDatabase(db);
    
    // Create appropriate user object based on login
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Assuming login function returns a pointer to the correct User type
    currentUser = login(username, password, db);  // Assuming login() handles authentication and returns the appropriate user
    // Check if login failed
    if (!currentUser) {
        cout << "Login failed. Exiting..." << endl;
        return 1;  // Exit if login fails
    }
    
    cout << "Login successful!" << endl;  // Debugging step
    
    // Display menu based on the user type (admin or alumni)
    displayMenu(currentUser);

    string choice;
    bool running = true;

    while (running) {
        cout << "\nEnter your choice: ";
        cin >> choice;
        cout<<endl;

        // Debugging: Show which choice was entered
        //cout << "You entered choice: " << choice << endl;
        
        // Convert string to integer
        int optn;
        
        try{
             int optn = stoi(choice);
              switch (optn) {
                  case 1:
                      handleViewAllAlumni(db);
                      break;
                  case 2:
                      if (isAdmin(currentUser)) {
                          handleAddAlumni(dynamic_cast<Administrator*>(currentUser), db);
                      }
                      else {
                          cout<<"Access denied. Admin privileges required."<<endl;
                          }

                      break;
                  case 3:
                      handleSearchAlumniByID(db);
                      break;
                  case 4:
                      handleSearchAlumniByName(db);
                      break;
                  case 5:
                      if (isAdmin(currentUser)) {
                          handleUpdateAlumniInfo(dynamic_cast<Administrator*>(currentUser), db);
                      }
                      else {
                          cout<<"Access denied. Admin privileges required."<<endl;
                          }
                      break;
                  case 6:
                      if (isAdmin(currentUser)) {
                          handleRemoveAlumni(dynamic_cast<Administrator*>(currentUser), db);
                      }
                      else {
                          cout<<"Access denied. Admin privileges required."<<endl;
                          }
                      break;
                  case 7:
                      handleViewAllEvents(db);
                      break;
                  case 8:
                      if (isAdmin(currentUser)) {
                          handleAddEvent(dynamic_cast<Administrator*>(currentUser), db);
                      }
                      else {
                          cout<<"Access denied. Admin privileges required."<<endl;
                          }
                      break;
                  case 9:
                      handleSearchEventByID(db);
                      break;
                  case 10:
                      if (isAdmin(currentUser))
                          handleAddParticipantToEvent(db);
                      else {
                          cout<<"Access denied. Admin privileges required."<<endl;
                          }
                      break;
                  case 11:
                      if (isAdmin(currentUser)) {
                          handleUpdateEvent(dynamic_cast<Administrator*>(currentUser), db);
                      }
                      else {
                          cout<<"Access denied. Admin privileges required."<<endl;
                          }
                      break;
                  case 12:
                      if (isAdmin(currentUser)) {
                          handleRemoveEvent(dynamic_cast<Administrator*>(currentUser), db);
                      }
                      else {
                          cout<<"Access denied. Admin privileges required."<<endl;
                          }
                      break;
                  case 13:
                      handleSendMessage(currentUser, db);
                      break;
                  case 14:
                      handleViewMessages(db);
                      break;
                  case 15:
                      running = false;  // Exit the program
                      printColor("Exiting the program. Goodbye!", "\033[1;33m");
                      break;
                  default:
                      printColor("Invalid option. Please try again.", "\033[1;31m");
                      break;
              }}
        catch (const invalid_argument& e) {
            cout << "Error: Invalid input, please enter a valid number." << endl;
        } catch (const out_of_range& e) {
            cout << "Error: Input is out of range." << endl;
        }
        // To prevent the program from exiting prematurely due to input errors
        if (running) {
            displayMenu(currentUser);  // Display the menu again
        }
    }

    return 0;
}

