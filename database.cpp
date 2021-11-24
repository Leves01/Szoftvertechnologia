#include "database.h"



void Database::addUser(string newFullName, string newAddress, string newDateOfBirth, string newPassword, int newType, User currentUser)
{
	if (currentUser.checkType() >= 2) {

		//legenerálja a kódot
		CodeGenerator newCode;
		string userCode = newCode.generateCode(8);

		//iterátor ami végigmegy a userArray listán, megnézi, hogy a generált kód ==-e bármelyik
		//eddigi legenerált kóddal
		auto it = find(usersArray.begin(), usersArray.end(), userCode);

		if (it != usersArray.end()) {
			
		}
		else {
			User newUser;
			newUser.setCodeOfUser(userCode);
			newUser.setFullName(newFullName);
			newUser.setAddress(newAddress);
			newUser.setDateOfBirth(newDateOfBirth);
			newUser.setPassword(newPassword);
			newUser.setType(newType);

			usersArray.insert(usersArray.end(), newUser);
		}
		
	}
	else {
		cout << "Nem rendelkezik megfelelő jogokkal" << endl;
	}
	
}

void Database::deleteUser(string codeToBeDeleted, User currentUser)
{
	char yesNo;
	string codeWantDeleted;
	auto it = find(usersArray.begin(), usersArray.end(), codeWantDeleted);

	if (currentUser.checkType() >= 2) {

		cout << "Kérem adja meg a kitörlendő kódot" << endl;
		cin >> codeWantDeleted;

		if (it != usersArray.end()) 
		{
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
	else {
		cout << "Nem rendelkezik megfelelő jogokkal" << endl;
	}
}
