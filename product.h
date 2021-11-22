#ifndef __PRODUCT_H__
#define __PRODUCT_H__

#include <iostream>
#include <string>

using namespace std;

class Product {
    private:
        string name;
        int sector;
        int shelf;
        int row;
        int id;
        
    public:
        //ez miért protected és nem public?
        Product(string name, int sector, int shelf, int row, int id);
        string getName();
        int getSector();
        int getShelf();
        int getRow(); 
        int getId();

};

#endif // __PRODUCT_H__