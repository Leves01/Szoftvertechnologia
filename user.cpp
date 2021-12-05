#include "user.h"

User::User(std::string fullName, std::string dateOfBirth, std::string address, std::string password, std::string codeOfUser, int typeOfUser):
    fullName(fullName),
    dateOfBirth(dateOfBirth),
    address(address),
    password(password),
    codeOfUser(codeOfUser),
    typeOfUser(typeOfUser)
{
}

std::string User::getCodeOfUser() const
{
    return codeOfUser;
}

std::string User::getFullName() const {
    return fullName;
}

std::string User::getDateOfBirth() const {
    return dateOfBirth;
}

std::string User::getAddress() const {
    return address;
}

std::string User::getPassword() const
{
    return password;
}

int User::getType() const
{
    return typeOfUser;
}

void User::setFullName(std::string newFullName) {
    fullName = newFullName;
}

void User::setDateOfBirth(std::string newDateOfBirth) {
    dateOfBirth = newDateOfBirth;
}

void User::setAddress(std::string newAddress) {
    address = newAddress;
}

void User::setPassword(std::string newPassword) {
    password = newPassword;
}

void User::setCodeOfUser(std::string newCodeOfUser)
{
    codeOfUser = newCodeOfUser;
}

void User::setType(int typeOf)
{
    if (typeOf < 0 || typeOf > 2) {
        throw "A tipus 0, 1 vagy 2, 0-Vasarlo 1-Dolgozo 2-Admin";
    }
    else
    {
        typeOfUser = typeOf;
    }
}

int User::checkType() const
{
    return typeOfUser;
}

bool User::operator==(const User& rhs)
{
    return codeOfUser == rhs.codeOfUser;
}

bool User::operator!=(const User& rhs)
{
    return !operator==(rhs);
}

bool User::operator==(const std::string& rhs)
{
    return codeOfUser == rhs;
}
