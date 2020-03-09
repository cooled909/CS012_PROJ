
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "BBoard.h"
#include "Topic.h"
#include "Reply.h"

using namespace std;

BBoard::BBoard(){
    title = "";
    

}

BBoard::BBoard(const string &name){
    title = name;
    

}

bool BBoard::loadUsers(const string &file){
    ifstream fin;
    string user;
    string pass;
    User newUser;
    fin.open(file);
    if(!(fin.is_open())){
        return false;
    }
    while(!(user == "end")){
        fin >> user;
        fin >> pass;
        newUser.changeUser(user);
        newUser.changePass(pass);
        userList.push_back(newUser);
    }
        return true;
    }


bool BBoard::login(){
    string tempUser;
    string tempPass;
    bool goodUser = false;
    
    cout << "Welcome to " << title << endl;
    while(!(goodUser)){
        cout << "Enter your username ('Q' or 'q' to quit): " << endl;
        cin >>  tempUser;
        if (tempUser == "q" || tempUser == "Q"){
            cout << "Bye!" << endl;    
            return false;
            }
        cout << "Enter your password: " << endl;
        cin >> tempPass;
        for(unsigned i = 0; i < userList.size(); i++){
            if(userList.at(i).check(tempUser, tempPass) == true){
                goodUser = true;
                currentUser = &userList.at(i);
                return true;
            }
        }
        cout << "Invalid Username or Password!" << endl << endl;
    }
    return false;
}
void BBoard::run(){
    char action = 'p';      
    cout << "Welcome back " << currentUser->getUsername() << "!" << endl << endl;
        
    while(!(action == 'q' || action == 'Q')){
        cout << "Menu" << endl << "- Display Messages (\'D\' or \'d\')" << endl << "- Add New Message (\'N\' or \'n\')"
        << endl << "- Quit (\'Q\' or \'q\')" << endl;
        cout << "Choose an action: ";
        cin >> action;
        cout << endl;
        /*if(action == 'n' || action == 'N'){
           string athr = currentUser.getUsername();
           string sub;
           string body;
           cout << "Enter Subject: ";
           cin.ignore(1, '\n');
           getline(cin, sub);
           cout << endl << "Enter Body: ";
           getline(cin, body);
           Message newMessage(athr, sub , body);
           messageList.push_back(newMessage);
           cout << endl;
           cout << "Message Recorded!" << endl << endl;
        }*/
        if(action == 'd' || action == 'D'){
            if(messageList.size() == 0){
                cout << "Nothing to Display." << endl << endl;
            }
            if(messageList.size() > 0){
                for(unsigned i = 0; i < messageList.size(); i++){
                    cout << "---------------------------------------------------------" << endl;
                    cout << "Message #" << messageList.at(i)->getID() << ": ";
                    messageList.at(i)->print(0);
                }
                cout << "---------------------------------------------------------" << endl << endl;
            }
        }
    }
    cout << "Bye!"<< endl;
}

void BBoard::display() const {

}

bool BBoard::loadMessages(const string &datafile) {
    ifstream fin;
    string atr;
    string sub;
    string bdy;
    int id = 1;
    fin.open(datafile);
    if(!(fin.is_open())){
        return false;
    }
    while(fin >> atr){
    if(atr == "<begin_topic>") {
        fin.ignore();
        fin.ignore(256, ' ');
        fin >> id;
        fin.ignore();
        fin.ignore(256, ' ');
        getline(fin, sub);
        fin.ignore(256, ' ');
        fin >> atr;
        fin.ignore();
        fin.ignore(256, '\n');
        fin.ignore(256, ' ');
        getline(fin, bdy);

        Message *temp = new Topic(atr, sub, bdy, id);
        messageList.push_back(temp);
        return true;
    }
    else if(atr == "<begin_reply>"){
        fin.ignore();
        fin.ignore(256, ' ');
        fin >> id;
        fin.ignore();
        fin.ignore(256, ' ');
        getline(fin, sub);
        fin.ignore(256, ' ');
        fin >> atr;
        fin.ignore();
        fin >> bdy;
        if(bdy == ":children:"){
            
        }
        else{
            fin.ignore(256, '\n');
        }
        fin.ignore(256, ' ');
        getline(fin, bdy);
        Message *temp = new Reply(atr, sub, bdy, id);
        messageList.push_back(temp);
        return true;
    }
    }
    return false;
}

bool BBoard::saveMessages(const string &datafile) {
    return false;
}


