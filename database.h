#ifndef __DATABASE_H__
#define __DATABASE_H__

#include "codeGenerator.h"
#include "user.h"
#include "includes.h"
#include <algorithm>
#include "product.h"
#include <fstream>

class Database{
	private:
		std::list<User> usersArray;
		std::list<Product> productArray;

	public:
		//Konstruktor
		Database();

		// Admin jogosultság 2
		void addUser(std::string newFullName, std::string newDateOfBirth, std::string newAddress, std::string newPassword, int newType);
		void deleteUser(std::string codeToBeDeleted);
		void listAll() const;	 
		void listWorkers() const;
		void listBuyers() const;
		void saveProducts() const;
		
		
		// Admin és dolgozói jogosultság 1, 2
		void placeOfProduct();
		void addProduct(std::string name, int sector, int shelf, int row, int newId);
		void deleteProduct(int id);

		// Mindenkinek elérhető [nem bejelentkezett], 0, 1, 2
		void login(std::string username, std::string password, User& currentUser);
		void listProducts() const;
		void listProducts(std::string _type) const;

		//Egyéb
		void loadUsers( User &_user);
		void saveUsers() const;
		

		
		
};

#endif // !__DATABASE_H__
