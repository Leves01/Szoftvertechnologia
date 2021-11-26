#include "listofproducts.h"

ListOfProducts::ListOfProducts(std::string _type) : type(_type)
{
}

void ListOfProducts::listProducts()
{
	for (const auto& product : products)
	{
		std::cout << product << std::endl;
	}
}

void ListOfProducts::listProducts(std::string type)
{
	for (const auto& product : products)
	{
		if (type == product)
			std::cout << product << std::endl;
	}
}
