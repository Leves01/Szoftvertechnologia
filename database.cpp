#include "database.h"

Database::Database()
{
}

void Database::addUser(string newFullName, string newAddress, string newDateOfBirth, string newPassword, int newType)
{
	//legenerálja a kódot
	CodeGenerator newCode;
	string userCode = newCode.generateCode(8);

	//iterátor ami végigmegy a userArray listán, megnézi, hogy a generált kód ==-e bármelyik
	//eddigi legenerált kóddal

	auto it = find(usersArray.begin(), usersArray.end(), &userCode);

	while (it != usersArray.end())
	{
		userCode = newCode.generateCode(8);
		it = find(usersArray.begin(), usersArray.end(), &userCode);
	}

	User newUser;
	newUser.setCodeOfUser(userCode);
	newUser.setFullName(newFullName);
	newUser.setAddress(newAddress);
	newUser.setDateOfBirth(newDateOfBirth);
	newUser.setPassword(newPassword);
	newUser.setType(newType);

	usersArray.push_back(newUser);
}

void Database::deleteUser(string codeToBeDeleted)
{
	auto it = find(usersArray.begin(), usersArray.end(), &codeToBeDeleted);

	if (it != usersArray.end()) 
	{
		char yesNo;
		cout << "Biztos szeretné törölni? (y/n)" << endl;
		cin >> yesNo;

		switch (yesNo)
		{
			case 'y':
			{

				break;
			}

			case 'n':
			{
				break;
			}

			default:
			{
				cout << "Rossz karaktert ütött be!" << endl;
				break;
			}
		}
	}
	else {
		cout << "Nincs ilyen felhasználói kód a rendszerben" << endl;
	}
}

void Database::listAll()
{
	for_each(usersArray.begin(), usersArray.end(), [](User& user)
		{
			cout << user.getCodeOfUser() << user.getFullName() << user.getDateOfBirth() << user.getAddress() << user.checkType() << endl;
		});
}

void Database::listWorkers()
{
	for_each(usersArray.begin(), usersArray.end(), [](User& user)
		{
			if (user.checkType() >= 1) {
				cout << user.getCodeOfUser() << user.getFullName() << user.getDateOfBirth() << user.getAddress() << user.checkType() << endl;
			}	
		});
}

void Database::listBuyers()
{
	for_each(usersArray.begin(), usersArray.end(), [](User& user)
		{
			if (user.checkType() <= 1) {
				cout << user.getCodeOfUser() << user.getFullName() << user.getDateOfBirth() << user.getAddress() << user.checkType() << endl;
			}
		});
}

void Database::addProduct(string newName, int newSector, int newShelf, int newRow, int newId)
{	
		Product newProduct = Product(newName, newSector, newShelf, newRow, newId);
		productArray.push_back(newProduct);
}

void Database::deleteProduct(int id)
{
	auto it = find(productArray.begin(), productArray.end(), &id);

	if (it != productArray.end()) {
		productArray.remove((*it));
	}
}

//void Database::login(string username, string password, User& currentUser)
//{
//
//	auto it = find(usersArray.begin(), usersArray.end(), &username);
//
//	if (it != usersArray.end()) {
//		if (it->getPassword() == password) {
//			currentUser = (*it);
//		}
//	}
//}
