#ifndef __DATABASE_H__
#define __DATABASE_H__

#include "codeGenerator.h"
#include "user.h"
#include "includes.h"
#include <algorithm>
#include "product.h"
#include <fstream>
#include "delivery.h"

class Database{
	private:
		std::list<User> usersArray;
		std::list<Product> productArray;
		std::list<Delivery> deliveryArray;

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
		//void placeOfProduct(int id);
		void addProduct(std::string name, int sector, int shelf, int row, int newId);
		void deleteProduct(int id);

		// Mindenkinek elérhető [nem bejelentkezett], 0, 1, 2
		void login(std::string username, std::string password, User& currentUser);
		void listProducts() const;
		void listProductsInfo() const;
		void listProducts(std::string _type) const;
		void listDeliveriesByCode(std::string searchCode) const;
		void listDeliveriesByCountry(std::string searchAddress) const;

		//Egyéb
		void loadUsers( User &_user);
		void saveUsers() const;	
		int productArraySize() const;
};

#endif // !__DATABASE_H__
