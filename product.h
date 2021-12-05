#ifndef __PRODUCT_H__
#define __PRODUCT_H__

#include "includes.h"

class Product {
    private:
        std::string name;
        int sector;
        int shelf;
        int row;
        std::string id;
        
    public:
        Product() = default;
        Product(std::string name, int sector, int shelf, int row, std::string id);
        std::string getName() const;
        int getSector() const;
        int getShelf() const;
        int getRow() const; 
        std::string getId() const;

        void setName(std::string newName);
        void setSector(int newSector);
        void setShelf(int newShelf);
        void setRow(int newRow);
        void setId(std::string newId);

        bool operator==(const Product& rhs);
        bool operator!=(const Product& rhs);

        bool operator==(const std::string rhs);

};

#endif // __PRODUCT_H__