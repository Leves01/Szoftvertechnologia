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
{ //amúgy passz ezt hogy akarjuk csinálni ezt kellett volna megbeszélni mi legyen product listet hasonlítsuk össze ezzel a listtel és azokat hasonlítsuk össze
	//vagy a mainben hozzunk létre egy product változót majd és az alapján getteljük  a productid alapján a nevét
	// vagy simán Id helyet inkább a nevét adjuk meg a fentebb található függvényeknek.
	//ut. donat ugyse olvassa baszodj meg te csicska geci.
	std::cout << "A kosara tartalma : " << std::endl;
	for (std::list<int>::iterator it = myBasket.begin(); it != myBasket.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}
}
