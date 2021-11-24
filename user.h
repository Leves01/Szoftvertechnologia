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

    string getCodeOfUser();
    string getFullName();
    string getDateOfBirth();
    string getAddress();
    string getPassword();

    void setFullName(string newFullName);
    void setDateOfBirth(string newDateOfBirth);
    void setAddress(string newAddress);
    void setPassword(string newPassword);
    void setCodeOfUser(string newCodeOfUser);

    int checkType();	//0-vásárló 1-dolgozó 2-admin
    void setType(int typeOf);
};

#endif // __USER_H__