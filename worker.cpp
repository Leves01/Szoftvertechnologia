#include "worker.h"

void Worker::setType(int typeOf)
{
	if (typeOf < 0 || typeOf > 2) {
		throw "A típus 0, 1 vagy 2, 0-Vásárló 1-Dolgozó 2-Admin";
	}
	else
	{
		typeOfWorker = typeOf;
	}
}

int Worker::checkType()
{
	return typeOfWorker;
}

void Worker::addUser(string fullNameOfUser, string address, string dateOfBirth, string password, int typeOfUser)
{
	switch (checkType())
	{
		case 0:
		{
			cout << "Nem rendelkezik megfelelő jogokkal";
			break;
		}
			
		case 1:
		{
			cout << "Nem rendelkezik megfelelő jogokkal";
			break;
		}

		case 2: 
		{
			CodeGenerator newCode;
			string userCode = newCode.generateCode(8);
			Users newWorker;
			newWorker.setCodeOfUser(userCode);
			newWorker.setFullName(fullNameOfUser);
			newWorker.setAddress(address);
			newWorker.setDateOfBirth(dateOfBirth);
			newWorker.setPassword(password);
			//ide még valahogy hogy beállítsa a típust
		}

		default:
		{
			cout << "Nem rendelkezik megfelelő jogokkal";
			break;
		}
	}
}
