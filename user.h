#ifndef __USER_H__
#define __USER_H__

#include "includes.h"

class User {
    protected:
        std::string fullName;
        std::string dateOfBirth;
        std::string address;
        std::string password;
        std::string codeOfUser;
        int typeOfUser;

    public:
    User() = default;
    User(std::string fullName, std::string dateOfBirth, std::string address, std::string password, std::string codeOfUser, int typeOfUser);

    std::string getCodeOfUser() const;
    std::string getFullName() const;
    std::string getDateOfBirth() const;
    std::string getAddress() const;
    std::string getPassword() const;
    int getType()const;

    void setFullName(std::string newFullName);
    void setDateOfBirth(std::string newDateOfBirth);
    void setAddress(std::string newAddress);
    void setPassword(std::string newPassword);
    void setCodeOfUser(std::string newCodeOfUser);

    int checkType() const;	//0-vásárló 1-dolgozó 2-admin
    void setType(int typeOf);

    bool operator==(const User& rhs);
    bool operator!=(const User& rhs);

    bool operator==(const std::string& rhs);
};

#endif // __USER_H__