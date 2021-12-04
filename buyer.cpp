#include "buyer.h"

Buyer::Buyer()
{

}

std::string Buyer::getOrderCode() const
{
	return orderCode;
}

void Buyer::addToBasket(int productId)
{
	myBasket.push_back(productId);
}

void Buyer::removeFromBasket(int productId)
{
	myBasket.remove(productId);
}

void Buyer::listMyBasket()
{ 
	std::cout << "A kosara tartalma : " << std::endl;
	for (std::list<int>::iterator it = myBasket.begin(); it != myBasket.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}
}
