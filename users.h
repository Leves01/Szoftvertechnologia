#ifndef __USERS_H__
#define __USERS_H__

#include "includes.h"

class Users {
    private:
        string fullName;
        string dateOfBirth;
        string address;
        string password;
        string codeOfUser;

    public:
    Users();
    // Users(string fullName, string dateOfBirth, string address, string password, string codeOfUser);

    string getFullName();
    string getDateOfBirth();
    string getAddress();
    void setFullName(string newFullName);
    void setDateOfBirth(string newDateOfBirth);
    void setAddress(string newAddress);
    void setPassword(string newPassword);
    void setCodeOfUser(string newCodeOfUser);
};

#endif // __USERS_H__