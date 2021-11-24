#ifndef __USER_H__
#define __USER_H__

#include "includes.h"

class User {
    protected:
        string fullName;
        string dateOfBirth;
        string address;
        string password;
        string codeOfUser;
        int typeOfUser;

    public:
    User();
    // User(string fullName, string dateOfBirth, string address, string password, string codeOfUser);

    string getFullName();
    string getDateOfBirth();
    string getAddress();
    void setFullName(string newFullName);
    void setDateOfBirth(string newDateOfBirth);
    void setAddress(string newAddress);
    void setPassword(string newPassword);
    void setCodeOfUser(string newCodeOfUser);
    void setType(int typeOf);

    int checkType();	//0-v�s�rl� 1-dolgoz� 2-admin
};

#endif // __USER_H__