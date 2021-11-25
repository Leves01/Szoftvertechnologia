#ifndef LISTOFPRODUCTS_H
#define LISTOFPRODUCTS_H
#include "includes.h"


class ListOfProducts
{private:
    string type;
    list<string> products;
public:
    ListOfProducts(string _type);
    void listProducts();
    void listProducts(string Type);
};

#endif // LISTOFPRODUCTS_H
//- type : string
//+ listProducts() : void
//+ listProducts(Type) : void