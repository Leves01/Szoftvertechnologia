#include "buyer.h"

Buyer::Buyer(std::string _userId) : userId(_userId)
{

}

std::string Buyer::getOrderCode() const
{
	return orderCode;
}

void Buyer::addToBasket(std::string productId)
{
	myBasket.push_back(productId);
}



void Buyer::removeFromBasket(std::string productId)
{
	myBasket.remove(productId);
}

void Buyer::listMyBasket() const
{ 
	for (const auto& basket : myBasket)
	{
		std::cout << basket << " ";
	}
	std::cout << std::endl;
}

std::string Buyer::setOrder() 
{
	std::string str;
	for (const auto& basket : myBasket)
	{
		
		str += " " + basket;
	}
	return str;
}
