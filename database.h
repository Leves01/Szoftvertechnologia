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
		void addProduct(std::string newName, int newSector, int newShelf,  int newRow);
		void deleteProduct(std::string id);

		// Mindenkinek elérhető [nem bejelentkezett], 0, 1, 2
		void login(std::string username, std::string password, User& currentUser);
		void listProducts() const;
		void listProductsInfo() const;
		void listProducts(std::string _type) const;
		void listDeliveriesByCode(std::string searchCode) const;
		void listDeliveriesByMegye(std::string megye) const;

		//Egyéb
		void loadUsers(User &_user);
		void loadProduct(Product& _product);
		void saveUsers() const;	
		int productArraySize() const;
		bool searchForProduct(std::string _productName) const;
		std::string getCodeFromArray(std::string searchName, std::string dateOB);
		void addDelivery(Delivery& D);
};

#endif // !__DATABASE_H__
