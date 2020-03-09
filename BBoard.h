//BBoard.h

//Don't forget the inclusion guard!!

#include <string>
#include <vector>
using namespace std;

#include "Topic.h"
#include "User.h"

class BBoard {
   
 private:
    string title;
    vector<User> userList;
    const User * currentUser;
    vector<Message *> messageList;

 public:
    /* Constructs a board with a default title, 
     * empty user & message lists, 
     * and the "default" User
     */
    BBoard();

    /* Same as the default constructor except 
     * it sets the title of the board
     */
    BBoard(const string &);


    bool loadUsers(const string &);

    bool loadMessages(const string& datafile);

    bool saveMessages(const string &datafile);

    bool login();

    /* Contains main loop of Bulletin Board.
     * First verifies a User has been logged in before calling this function.
     * (Do not call login function within this function.)
     * Returns from **function** immediately if no User logged in (Default User).
     * Continues to display menu options to user and performs requested action
     * until user chooses to quit.
     * See output samples for exact format of menu.
     */
    void run();
    

 private:
 
    // These are only suggestions, not required helper functions.
    // Feel free to make your own private helper functions as you see fit.
    void display() const;
};
