#ifndef __DATABASE_H__
#define __DATABASE_H__

#include "codeGenerator.h"
#include "user.h"
#include "includes.h"

class Database{
	private:
		list<User> usersArray;

	public:
		// Admin jogosultság 2
		void addUser(string newFullName, string newAddress, string newDateOfBirth, string newPassword, int newType, User currentUser);
		void deleteUser(string codeToBeDeleted, User currentUser);
		void listAll(User currentUser);
		void listWorkers(User currentUser);
		void listBuyers(User currentUser);
		
		// Admin és dolgozói jogosultság 1, 2
		void placeOfProduct();
		void addProduct(string name, int sector, int shelf, int row, int id);
		void deleteProduct(int productId);

		// Mindenkinek elérhető [nem bejelentkezett], 0, 1, 2
		void login(string username, string password, User& currentUser);
		void logout();
};

#endif // !__DATABASE_H__
