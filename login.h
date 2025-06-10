// Updated login.h with only functions from login.cpp
#ifndef LOGIN_H
#define LOGIN_H
#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <iomanip>
#include <sstream>
#include "Alumni.h"
#include "Event.h"
#include "Message.h"
#include "Administrator.h"
#include "AlumniDatabase.h"
#include"User.h"
void printColor(const string& message, const string& colorCode);
void loadDatabase(AlumniDatabase& alumniDatabase);
User* login(string &username, string& password, AlumniDatabase& db);
bool isAdmin(User* user);
void displayMenu(User* user);
void handleViewAllAlumni(AlumniDatabase& db);
void handleViewAllEvents(AlumniDatabase& db);
void handleViewMessages(AlumniDatabase& db);
void handleSearchAlumniByID(AlumniDatabase& db);
void handleSearchAlumniByName(AlumniDatabase& db);
void handleAddAlumni(Administrator* admin, AlumniDatabase& db);
void handleUpdateAlumniInfo(Administrator* admin, AlumniDatabase& db);
void handleRemoveAlumni(Administrator* admin, AlumniDatabase& db);
void handleSendMessage(User* user, AlumniDatabase& db);
void handleAddEvent(Administrator* admin, AlumniDatabase& db);
void handleSearchEventByID(AlumniDatabase& db);
void handleAddParticipantToEvent(AlumniDatabase& db);
void handleUpdateEvent(Administrator* admin, AlumniDatabase& db);
void handleRemoveEvent(Administrator* admin, AlumniDatabase& db);

#endif // LOGIN_H

