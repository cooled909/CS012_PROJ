#include <string>
#include <iostream>
<<<<<<< HEAD
=======
#include <sstream>
#include <utility>
>>>>>>> desktop 3/9 11:59 p
#include "Message.h"

using namespace std;

Message::Message(){
    author = "";
    subject = "";
    body = "";
}

Message::Message(const string &athr, const string &sbjct, const string &body, unsigned int id) : author(athr),
                subject(sbjct), body(body), id(id){

}

Message::~Message() {

}

void Message::print(unsigned indent) const {
<<<<<<< HEAD
    for(int i = 0; i < indent*2; i++){
        cout << " ";
    }
    cout << subject << endl << "from " << author << ": " << body << endl;
=======

    if(!isReply()){
        cout << subject << endl << "from " << author << ": ";
        if(body.find('\n') != string::npos){
            int first = 0;
            string substr = body.substr(first, body.find('\n') );
            cout << substr << endl;
            first = body.find('\n', first) + 1;
            while(body.find('\n', first) != string::npos) {
                for (int i = 0; i < indent * 2; i++) {
                    cout << " ";
                }
                string temp = substr;
                string substr = body.substr(first, body.find('\n', first)-first);
                cout << substr << endl;
                first = body.find('\n', first) + 1;
            }
        }
        else {
            cout << body << endl;
        }
        indent++;
        for(int i = 0; i < childList.size(); i++) {
            childList.at(i)->print(indent);
        }
    }
    else{
        cout << endl;
        for (int i = 0; i < indent * 2; i++) {
            cout << " ";
        }
        cout << "Message #" << id << ": " << subject << endl;
        for (int i = 0; i < indent * 2; i++) {
                cout << " ";
        }
        cout << "from " << author << ": ";
        if(body.find('\n') != string::npos){
            int first = 0;
            string substr = body.substr(first, body.find('\n') );
            cout << substr << endl;
            first = body.find('\n', first) + 1;
            while(body.find('\n', first) != string::npos) {
                for (int i = 0; i < indent * 2; i++) {
                    cout << " ";
                }
                string temp = substr;
                string substr = body.substr(first, body.find('\n', first)-first);
                cout << substr << endl;
                first = body.find('\n', first) + 1;
            }
        }
        else {
            cout << body << endl;
        }
        if(childList.size() >0 ) {
            indent++;
            for(int i = 0; i < childList.size(); i++) {
                childList.at(i)->print(indent);
            }
            indent--;
        }
    }
>>>>>>> desktop 3/9 11:59 p
}

unsigned Message::getID() const {
    return id;
}

<<<<<<< HEAD
bool Message::future(string future) {
    futureChild.push_back(future);
=======
void Message::future(vector<string> future) {
    for(unsigned i = 0; i < future.size(); i++){
        stringstream in(future.at(i));
        int x = 0;
        in >> x;
        futureChild.push_back(x);
    }
}


void Message::addChild(Message *child) {
    childList.push_back(child);
}

vector<int> Message::returnVec() const {
    return futureChild;
}

const string &Message::getSubject() const {
    return subject;
>>>>>>> desktop 3/9 11:59 p
}



