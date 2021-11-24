#ifndef __WORKER_H__

#include "codeGenerator.h"
#include "users.h"
#include "includes.h"

class Worker : public Users {
	private:
		int typeOfWorker;

	public:

		// Egyéb
		int checkType();	//0-vásárló 1-dolgozó 2-admin
		void setType(int typeOf);
		
		// Admin jogosultság 2
		void addUser(string fullNameOfUser, string address, string dateOfBirth, string password, int typeOfUser);
		void deleteUser(string codeOfUser);
		void listWorkers();
		void listBuyers();
		string checkPassword(string codeOfUser);
		
		// Admin és dolgozói jogosultság 1, 2
		void placeofProduct();
		void addProduct(string name, int sector, int shelf, int row, int id);
		void deleteProduct(int productId);

		// Mindenkinek elérhető [nem bejelentkezett], 0, 1, 2
		void login();
};

#endif // !__WORKER_H__
