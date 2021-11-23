#include "worker.h"

int Worker::checkType()
{
	return typeOfWorker;
}

void Worker::addWorker(string fullNameOfWorker, string dateOfBirth, string password, int typeOfWorker)
{
	switch (checkType())
	{
	case 0:
		cout << "Nem rendelkezik megfelelő jogokkal";
		break;

	case 1:
		CodeGenerator newCode;


	default:
		cout << "Nem rendelkezik megfelelő jogokkal";
		break;
	}
}
