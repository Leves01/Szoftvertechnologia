#include "database.h"

Database::Database()
{
}

void Database::addUser(std::string newFullName, std::string newAddress, std::string newDateOfBirth, std::string newPassword, int newType)
{
	//legenerálja a kódot
	CodeGenerator newCode;
	std::string userCode = newCode.generateCode(8);

	//iterátor ami végigmegy a userArray listán, megnézi, hogy a generált kód ==-e bármelyik
	//eddigi legenerált kóddal

	auto it = std::find(usersArray.begin(), usersArray.end(), userCode);

	while (it != usersArray.end())
	{
		userCode = newCode.generateCode(8);
		it = std::find(usersArray.begin(), usersArray.end(), userCode);
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

void Database::deleteUser(std::string codeToBeDeleted)
{
	auto it = std::find(usersArray.begin(), usersArray.end(), codeToBeDeleted);

	if (it != usersArray.end()) 
	{
		char yesNo;
		std::cout << "Biztos szeretne torolni? (y/n)" << std::endl;
		std::cin >> yesNo;

		switch (yesNo)
		{
			case 'y':
			{
				usersArray.erase(it);
				break;
			}

			case 'n':
			{
				break;
			}

			default:
			{
				std::cout << "Rossz karaktert utott be!" << std::endl;
				break;
			}
		}
	}
	else {
		std::cout << "Nincs ilyen felhasznaloi kod a rendszerben" << std::endl;
	}
}

void Database::listAll() const
{
	for (const auto& user : usersArray)
	{
			std::cout << user.getCodeOfUser() << user.getFullName() << user.getDateOfBirth() << user.getAddress() << user.checkType() << std::endl;
	}
}

void Database::listWorkers() const
{
	for (const auto& user : usersArray)
	{
		if (user.checkType() >= 1) {
			std::cout << user.getCodeOfUser() << user.getFullName() << user.getDateOfBirth() << user.getAddress() << user.checkType() << std::endl;
		}
	}
}

void Database::listBuyers() const
{
	for (const auto& user : usersArray)
	{
		if (user.checkType() <= 1) {
			std::cout << user.getCodeOfUser() << user.getFullName() << user.getDateOfBirth() << user.getAddress() << user.checkType() << std::endl;
		}
	}
}

void Database::addProduct(std::string newName, int newSector, int newShelf, int newRow, int newId)
{	
		Product newProduct = Product(newName, newSector, newShelf, newRow, newId);
		productArray.push_back(newProduct);
}

void Database::deleteProduct(int id)
{
	auto it = std::find(productArray.begin(), productArray.end(), id);

	if (it != productArray.end()) {
		productArray.erase(it);
	}
}

//void Database::login(std::string username, std::string password, User& currentUser)
//{
//
//	auto it = std::find(usersArray.begin(), usersArray.end(), &username);
//
//	if (it != usersArray.end()) {
//		if (it->getPassword() == password) {
//			currentUser = (*it);
//		}
//	}
//}
