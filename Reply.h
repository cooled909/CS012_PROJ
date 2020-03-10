//
// Created by eddie on 3/8/2020.
//

<<<<<<< HEAD
#ifndef _REPLY_H
#define _REPLY_H
=======
#ifndef __REPLY_H__
#define __REPLY_H__
>>>>>>> desktop 3/9 11:59 p

#include <string>
#include "Message.h"

class Reply : public Message{
public:
    //default constructor
    Reply();

    /* Parameterized constructor - similar to Message's constructor
     */
    Reply(const string &athr,
          const string &sbjct,
          const string &body,
          unsigned id);

    virtual bool isReply() const; // Returns true

    /* toFormattedString writes the contents of the Reply to a string in the
     * following format:

      <begin_reply>
      :id: 4
      :subject: single line
      :from: author
      :children: 5 6 [this line should not be printed if there are no children.]
      :body: multiple lines
      2nd line
      <end>

     * the line starting with :children: has the list of ID's of all children
     * (See file specs. for details)
     * This function should not assume the last character in body is a newline.
     * In other words, this function must manually add a newline after the last
     * line of the body (line 3 in this example).
     * Also, the last character in the string must be a newline.
     */
    virtual string toFormattedString() const; // New !!
};

#endif //CS012_PROJ_REPLY_H
