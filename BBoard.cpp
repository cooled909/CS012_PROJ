
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "BBoard.h"
<<<<<<< HEAD
#include "Topic.h"
#include "Reply.h"
=======

>>>>>>> desktop 3/9 11:59 p

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
<<<<<<< HEAD
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
=======
        cout << "Menu" << endl << "- Display Messages (\'D\' or \'d\')" << endl << "- Add New Topic (\'N\' or \'n\')"
        << endl << "- Add Reply to a Topic (\'R\' or \'d\')" << endl << "- Quit (\'Q\' or \'q\')" << endl;
        cout << "Choose an action: ";
        cin >> action;
        cout << endl;
        if(action == 'n' || action == 'N'){
           addTopic();
        }
>>>>>>> desktop 3/9 11:59 p
        if(action == 'd' || action == 'D'){
            if(messageList.size() == 0){
                cout << "Nothing to Display." << endl << endl;
            }
<<<<<<< HEAD
            if(messageList.size() > 0){
                for(unsigned i = 0; i < messageList.size(); i++){
                    cout << "---------------------------------------------------------" << endl;
                    cout << "Message #" << messageList.at(i)->getID() << ": ";
                    messageList.at(i)->print(0);
=======
            if(messageList.size() > 0 ){
                for(unsigned i = 0; i < messageList.size(); i++){
                    if(!messageList.at(i)->isReply()) {
                        cout << "---------------------------------------------------------" << endl;
                        cout << "Message #" << messageList.at(i)->getID() << ": ";
                        messageList.at(i)->print(0);
                    }
>>>>>>> desktop 3/9 11:59 p
                }
                cout << "---------------------------------------------------------" << endl << endl;
            }
        }
<<<<<<< HEAD
=======
        if(action == 'r' || action == 'R'){
            addReply();
        }
>>>>>>> desktop 3/9 11:59 p
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
<<<<<<< HEAD
=======
    string temp;
    int intTemp;
    vector<string> futureChild;
>>>>>>> desktop 3/9 11:59 p
    int id = 1;
    fin.open(datafile);
    if(!(fin.is_open())){
        return false;
    }
<<<<<<< HEAD
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

=======
    while(fin >> atr) {
        if (atr == "<begin_topic>") {
            cout << "topic found" << endl;
            fin.ignore();
            fin.ignore(256, '\n');
            fin.ignore(256, ' ');
            getline(fin, sub);
            fin.ignore(256, ' ');
            fin >> atr;
            fin.ignore();
            fin >> temp;
            if(temp == ":children:"){
                fin >> temp;
                while(temp != ":body:"){
                    futureChild.push_back(temp);
                    fin >> temp;
                }
            }
            fin.ignore();
            getline(fin, bdy);
            bdy += "\n";
            fin >> temp;
            while (temp != "<end>") {
                bdy += temp;
                getline(fin, temp);
                bdy += temp;
                bdy += "\n";
                fin >> temp;
            }
            Topic *temp = new Topic(atr, sub, bdy, id);
            messageList.push_back(temp);
            if(futureChild.size() > 0) {
                messageList.at(id - 1)->future(futureChild);
            }
            id++;
            while(futureChild.size() != 0){
                futureChild.pop_back();
            }
        }
        if (atr == "<begin_reply>") {
            cout << "reply found" << endl;
            fin.ignore();
            fin.ignore(256, '\n');
            fin.ignore(256, ' ');
            getline(fin, sub);
            fin.ignore(256, ' ');
            fin >> atr;
            fin.ignore();
            fin >> temp;
            if(temp == ":children:"){
                fin >> temp;
                while(temp != ":body:"){
                    futureChild.push_back(temp);
                    fin >> temp;
                }
            }
            fin.ignore();
            getline(fin, bdy);
            bdy += "\n";
            fin >> temp;
            while (temp != "<end>") {
                bdy += temp;
                getline(fin, temp);
                bdy += temp;
                bdy += "\n";
                fin >> temp;
            }
            Reply *temp2 = new Reply(atr, sub, bdy, id);
            messageList.push_back(temp2);
            if(futureChild.size() > 0) {
                messageList.at(id - 1)->future(futureChild);
            }
            id++;
            while(futureChild.size() != 0){
                futureChild.pop_back();
            }
        }

    }
    for(unsigned i = 0; i < messageList.size(); i++){
        vector<int> copy = messageList.at(i)->returnVec();
        if(copy.size() > 0){
            for(unsigned j = 0; j < copy.size(); j++){
                messageList.at(i)->addChild(messageList.at(copy.at(j)-1));
            }
        }
    }
    return true;
}


>>>>>>> desktop 3/9 11:59 p
bool BBoard::saveMessages(const string &datafile) {
    return false;
}

<<<<<<< HEAD
=======
void BBoard::addTopic() {
    string athr = currentUser->getUsername();
    string sub;
    string body;
    int id = messageList.at(messageList.size()-1)->getID() + 1;
    cout << "Enter Subject: ";
    cin.ignore(1, '\n');
    getline(cin, sub);
    cout << endl << "Enter Body: ";
    getline(cin, body);
    Message * temp = new Topic(athr, sub, body, id);
    messageList.push_back(temp);
    cout << endl;
    cout << "Message Recorded!" << endl << endl;
}

void BBoard::addReply() {
    string athr = currentUser->getUsername();
    string sub;
    string body;
    int childOf = -1;
    int id = messageList.at(messageList.size()-1)->getID() + 1;
    while((childOf < 1 || childOf > messageList.size())) {
        cout << "Enter Message ID (-1 for Menu): ";
        cin >> childOf;
        if (childOf == -1) {
            return;
        }
    }
    sub = "Re: " + messageList.at(childOf-1)->getSubject();
    cout << endl << "Enter Body: ";
    cin.ignore(1, '\n');
    getline(cin, body);
    Message * temp = new Reply(athr, sub, body, id);
    messageList.push_back(temp);
    messageList.at(childOf-1)->addChild(messageList.back());
    cout << endl;
    cout << "Message Recorded!" << endl << endl;
}

>>>>>>> desktop 3/9 11:59 p

