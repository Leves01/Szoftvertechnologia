#include "users.h"

//nem vagyok benne biztos hogy tényleg kell konstruktor

Users::Users() {

}

// Users::Users(string fullName, string dateOfBirth, string address, string password, string codeOfUser):
//     fullName(fullName),
//     dateOfBirth(dateOfBirth),
//     address(address),
//     password(password),
//     codeOfUser(codeOfUser)
// {

// }

//ide jön a kód generáló függvény, bár fogalmam sincs hogyan kell megírni majd megnézzük



string Users::getFullName() {
    return fullName;
}

string Users::getDateOfBirth() {
    return dateOfBirth;
}

string Users::getAddress() {
    return address;
}

void Users::setFullName(string newFullName) {
    fullName = newFullName;
}

void Users::setDateOfBirth(string newDateOfBirth) {
    dateOfBirth = newDateOfBirth;
}

void Users::setAddress(string newAddress) {
    address = newAddress;
}

void Users::setPassword(string newPassword) {
    password = newPassword;
}