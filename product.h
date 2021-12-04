#ifndef __PRODUCT_H__
#define __PRODUCT_H__

#include "includes.h"

class Product {
    private:
        std::string name;
        int sector;
        int shelf;
        int row;
        int id;
        
    public:
        Product(std::string name, int sector, int shelf, int row, int id);
        std::string getName() const;
        int getSector() const;
        int getShelf() const;
        int getRow() const; 
        int getId() const;

        bool operator==(const Product& rhs);
        bool operator!=(const Product& rhs);

        bool operator==(const int rhs);

};

#endif // __PRODUCT_H__