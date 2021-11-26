#ifndef __DATABASE_H__
#define __DATABASE_H__

#include "codeGenerator.h"
#include "user.h"
#include "includes.h"
#include "product.h"

class Database{
	private:
		list<User> usersArray;
		list<Product> productArray;

	public:
		//Konstruktor
		Database();

		// Admin jogosultság 2
		void addUser(string newFullName, string newAddress, string newDateOfBirth, string newPassword, int newType);
		void deleteUser(string codeToBeDeleted);
		void listAll();
		void listWorkers();
		void listBuyers();
		
		// Admin és dolgozói jogosultság 1, 2
		/*void placeOfProduct();*/
		void addProduct(string name, int sector, int shelf, int row, int newId);
		void deleteProduct(int id);

		// Mindenkinek elérhető [nem bejelentkezett], 0, 1, 2
		/*void login(string username, string password, User& currentUser);
		void logout();*/
};

#endif // !__DATABASE_H__
