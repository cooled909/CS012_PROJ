#include <string>
#include <iostream>
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
    for(int i = 0; i < indent*2; i++){
        cout << " ";
    }
    cout << subject << endl << "from " << author << ": " << body << endl;
}

unsigned Message::getID() const {
    return id;
}

bool Message::future(string future) {
    futureChild.push_back(future);
}



