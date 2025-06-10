#ifndef MESSAGE_H
#define MESSAGE_H

#include<iostream>
using namespace std;

class Message {
private:
    string messageID;
    string senderID;
    string receiverID;
    string content;
    string date;

public:
    // Constructor
    Message(){}
    Message(string id, string sender, string receiver, string msgContent, string msgDate)
        : messageID(id), senderID(sender), receiverID(receiver), content(msgContent), date(msgDate) {}
    
    string getMessageID() const{ return messageID; }
    string getSenderID() const{	return senderID;}
    string getReceiverID() const{ return receiverID;}
    string getContent() const{  return content;} 
    string getDate() const{ return date;}
    friend ostream& operator<<(ostream& out, const Message& message);
    // Display Message
    void viewMessage() const {
        cout << "Message from " << senderID << " to " << receiverID 
             << "\nDate: " << date << "\nContent: " << content << endl;
    }
};
#endif
