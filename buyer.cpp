#include "buyer.h"

Buyer::Buyer()
{

}

void Buyer::addToBasket(int ProductId)
{
	MyBasket.push_back(&ProductId);


}

void Buyer::removeFromBasket(int ProductId)
{
	MyBasket.remove(&ProductId);
}

void Buyer::myBasket()
{ //amúgy passz ezt hogy akarjuk csinálni ezt kellett volna megbeszélni mi legyen product listet hasonlítsuk össze ezzel a listtel és azokat hasonlítsuk össze
	//vagy a mainben hozzunk létre egy product változót majd és az alapján getteljük  a productid alapján a nevét
	// vagy simán Id helyet inkább a nevét adjuk meg a fentebb található függvényeknek.
	//ut. donat ugyse olvassa baszodj meg te csicska geci.
	cout << A kosara tartalma:
	for (std::list<int>::iterator it = MyBasket.begin(); it != MyBasket.end(); ++it)
	{
		cout << it << endl;

	}
}
