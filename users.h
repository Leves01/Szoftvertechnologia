#ifndef __USERS_H__
#define __USERS_H__

#include <iostream>
#include <string>

using namespace std;

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
    
    // '4 karakterből álló generátor
    // +userCodeGenerator() : string
    
    string getFullName();
    string getDateOfBirth();
    string getAddress();
    void setFullName(string newFullName);
    void setDateOfBirth(string newDateOfBirth);
    void setAddress(string newAddress);
    void setPassword(string newPassword);
};

#endif // __USERS_H__