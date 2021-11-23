#ifndef __WORKER_H__

#include "codeGenerator.h"
#include "users.h"
#include "includes.h"

class Worker : public Users {
	private:
		int typeOfWorker;

	public:
		//0 a rendes dolgozó, 1 az admin, igen meglehetne boolal is, de nem
		int checkType();
		void addWorker(string fullNameOfWorker, string dateOfBirth, string password, int typeOfWorker);
		void deleteWorker(string codeOfUser);
		void listWorkers();
		void listBuyers();
		string checkPassword(string codeOfUser);
		void placeofProduct();
		void addProduct(string name, int sector, int shelf, int row, int id);
		void deleteProduct(int productId);
};

#endif // !__WORKER_H__
