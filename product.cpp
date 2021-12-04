#include "product.h"

Product::Product(std::string name, int sector, int shelf, int row, int id):
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


int Product::getId() const
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

bool Product::operator==(const int rhs)
{
    return id == rhs;
}
