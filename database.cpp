#include "database.h"

Database::Database()
{
}

void Database::addUser(std::string newFullName, std::string newDateOfBirth, std::string newAddress, std::string newPassword, int newType)
{
	CodeGenerator newCode;
	std::string userCode = newCode.generateCode(4);

	//iterátor ami végigmegy a userArray listán, megnézi, hogy a generált kód ==-e bármelyik
	//eddigi legenerált kóddal

	auto it = std::find(usersArray.begin(), usersArray.end(), userCode);

	while (it != usersArray.end())
	{
		userCode = newCode.generateCode(4);
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
			std::cout << user.getCodeOfUser() << " " << user.getFullName() << " " << user.getDateOfBirth() << " " << user.getAddress() << " " << user.checkType() << std::endl;
	}
}

void Database::listWorkers() const
{
	for (const auto& user : usersArray)
	{
		if (user.checkType() >= 1) {
			std::cout << user.getCodeOfUser() << " " << user.getFullName() << " " << user.getDateOfBirth() << " " << user.getAddress() << " " << user.checkType() << std::endl;
		}
	}
}

void Database::listBuyers() const
{
	for (const auto& user : usersArray)
	{
		if (user.checkType() <= 1) {
			std::cout << user.getCodeOfUser() << " " << user.getFullName() << " " << user.getDateOfBirth() << " " << user.getAddress() << " " << user.checkType() << std::endl;
		}
	}
}



void Database::listProducts() const
{
	for (const auto& product : productArray)
	{
		std::cout << product.getName() << std::endl;
	}
}

void Database::listProducts(std::string _type) const
{
	for (const auto& product : productArray)
	{
		if(product.getName() == _type)
			std::cout << product.getName() << std::endl;

	}
}

//std::string name;
//int sector;
//int shelf;
//int row;
//int id;

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

void Database::login(std::string username, std::string password, User& currentUser)
{

	auto it = std::find(usersArray.begin(), usersArray.end(), username);

	if (it != usersArray.end()) {
		if (it->getPassword() == password) {
			currentUser = (*it);
		}
		else {
			std::cout << "Hibas belepesi adatok" << std::endl;
		}
	}
	else {
		std::cout << "Nincs ilyen felhasznalonev a rendszerben" << std::endl;
	}

}

void Database::loadUsers( User& _user)
{
	Database::usersArray.push_back(_user);
}

void Database::saveUsers() const
{
	std::ofstream file("users.txt");
	for (const auto& user : usersArray)
	{
		file << user.getFullName() << " ; " << user.getDateOfBirth() << " ; " << user.getAddress() << " ; " << user.getPassword() << " ; " << user.getCodeOfUser()<<" ; " << user.getType() << "\n";
	}

}
void Database::saveProducts() const
{
	std::ofstream file("products.txt");
	for (const auto& product : productArray)
	{
		file << product.getName() << " " << product.getSector() << " " << product.getShelf() << " " << product.getRow() << " " << product.getId() << " ;\n";
	}
}
