#include <string>
#include "User.h"

using namespace std;

User::User(){
}

User::User(const string& uname, const string& pass){
    username = uname;
    password = pass;
}

string User::getUsername() const{
    return username;
}

string User::getPass() const{
    return password;
}

bool User::check(const string &uname, const string &pass) const{
    if(username.empty() && password.empty()){
        return false;
    }
    else if(username == uname && password == pass){
        return true;
    }
    else{
        return false;
    }
}

bool User::setPassword(const string &oldpass, const string &newpass){
    if(oldpass == password){
        password = newpass;
        return true;
    }
    else{
        return false;
    }
}

void User::changeUser(string user){
    username = user;
}

void User:: changePass(string pass){
    password = pass;
}