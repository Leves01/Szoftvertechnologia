#include "product.h"

Product::Product(std::string name, int sector, int shelf, int row, std::string id):
    name(name),
    sector(sector),
    shelf(shelf),
    row(row),
    id(id)
{
    
}

std::string Product::getName() const
{
    return name;
}

int Product::getSector()  const
{
    return sector;
}

int Product::getShelf()  const
{
    return shelf;
}



int Product::getRow() const
{
    return row;
}


std::string Product::getId() const
{
    return id;
}

bool Product::operator==(const Product& rhs)  
{
   return id == rhs.id;
}

bool Product::operator!=(const Product& rhs) 
{
    return !operator==(rhs);
}

bool Product::operator==(const std::string rhs)
{
    return id == rhs;
}

void Product::setName(std::string newName) {
    name = newName;
}

void Product::setSector(int newSector) {
    sector = newSector;
}

void Product::setShelf(int newShelf) {
    shelf = newShelf;
}

void Product::setRow(int newRow) {
    row = newRow;
}

void Product::setId(std::string newId) {
    id = newId;
}