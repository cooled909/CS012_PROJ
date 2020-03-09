//
// Created by eddie on 3/8/2020.
//

#include "Topic.h"

Topic::Topic(const string &athr,
             const string &sbjct,
             const string &body,
             unsigned id) : Message(athr, sbjct, body, id){
}

bool Topic::isReply() const {
    return false;
}

string Topic::toFormattedString() const {
    return std::__cxx11::string();
}

