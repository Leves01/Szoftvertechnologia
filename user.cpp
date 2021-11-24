#include "user.h"

//nem vagyok benne biztos hogy tényleg kell konstruktor

User::User() {

}

// User::User(string fullName, string dateOfBirth, string address, string password, string codeOfUser):
//     fullName(fullName),
//     dateOfBirth(dateOfBirth),
//     address(address),
//     password(password),
//     codeOfUser(codeOfUser)
// {

// }

string User::getCodeOfUser()
{
    return codeOfUser;
}

string User::getFullName() {
    return fullName;
}

string User::getDateOfBirth() {
    return dateOfBirth;
}

string User::getAddress() {
    return address;
}

string User::getPassword()
{
    return password;
}

void User::setFullName(string newFullName) {
    fullName = newFullName;
}

void User::setDateOfBirth(string newDateOfBirth) {
    dateOfBirth = newDateOfBirth;
}

void User::setAddress(string newAddress) {
    address = newAddress;
}

void User::setPassword(string newPassword) {
    password = newPassword;
}

void User::setCodeOfUser(string newCodeOfUser)
{
    codeOfUser = newCodeOfUser;
}

void User::setType(int typeOf)
{
    if (typeOf < 0 || typeOf > 2) {
        throw "A típus 0, 1 vagy 2, 0-Vásárló 1-Dolgozó 2-Admin";
    }
    else
    {
        typeOfUser = typeOf;
    }
}

int User::checkType()
{
    return typeOfUser;
}