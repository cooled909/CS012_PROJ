//
// Created by eddie on 3/8/2020.
//
#include "Reply.h"

Reply::Reply() {

}

Reply::Reply(const string &athr, const string &sbjct, const string &body, unsigned id) : Message(athr, sbjct, body,
                                                                                                 id) {

}

bool Reply::isReply() const {
    return true;
}

string Reply::toFormattedString() const {
    return std::__cxx11::string();
}


