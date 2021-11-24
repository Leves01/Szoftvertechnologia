
#include "product.h"

Product::Product(string name, int sector, int shelf, int row, int id):
    name(name),
    sector(sector),
    shelf(shelf),
    row(row),
    id(id)
{
    
}

string Product::getName()
{
    return name;
}

int Product::getSector() 
{
    return sector;
}

int Product::getShelf() 
{
    return shelf;
}

int Product::getRow() 
{
    return row;
}

int Product::getId() 
{
    return id;
}
