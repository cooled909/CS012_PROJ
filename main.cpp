#include <iostream>
#include <string>

using namespace std;

#include "BBoard.h"

int main(int argc, char *argv[]) {
   string userfile = argv[1];
   // cout << "User file?" << endl;
   // cin >> userfile;
   // cout << endl;
   string file = "message.txt";
   BBoard bb("CS12 Bulletin Board");
   
   // load users from file
   if (!bb.loadUsers(userfile)) {
      cout << "Error loading users from file " << userfile << endl;
      return 1;
   }
   if (!bb.loadMessages(file)){
       cout << "Error loading messages from file " << file << endl;
       return 1;
   }
   if (!bb.login()) {
      cout << "Login not successful" << endl;
      return 1;
   }
   bb.run();

   return 0;
}
