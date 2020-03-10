//
// Created by eddie on 3/8/2020.
//
#include "Reply.h"

Reply::Reply() {

}

<<<<<<< HEAD
Reply::Reply(const string &athr, const string &sbjct, const string &body, unsigned id) : Message(athr, sbjct, body,
                                                                                                 id) {
=======
Reply::Reply(const string &athr, const string &sbjct, const string &body, unsigned id) : Message(athr, sbjct, body, id) {
>>>>>>> desktop 3/9 11:59 p

}

bool Reply::isReply() const {
    return true;
}

string Reply::toFormattedString() const {
    return std::__cxx11::string();
}


