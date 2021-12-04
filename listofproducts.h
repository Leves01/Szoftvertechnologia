#ifndef LISTOFPRODUCTS_H
#define LISTOFPRODUCTS_H
#include "includes.h"


class ListOfProducts
{
    private:
        std::string type;
        std::list<std::string> products;

    public:
        ListOfProducts() = default;
        ListOfProducts(std::string _type);
        void listProducts();
        void listProducts(std::string Type);

};

#endif // LISTOFPRODUCTS_H
//- type : string
//+ listProducts() : void
//+ listProducts(Type) : void