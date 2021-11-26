#include "buyer.h"

Buyer::Buyer()
{

}

string Buyer::getOrderCode() const
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
{ //am�gy passz ezt hogy akarjuk csin�lni ezt kellett volna megbesz�lni mi legyen product listet hasonl�tsuk �ssze ezzel a listtel �s azokat hasonl�tsuk �ssze
	//vagy a mainben hozzunk l�tre egy product v�ltoz�t majd �s az alapj�n gettelj�k  a productid alapj�n a nev�t
	// vagy sim�n Id helyet ink�bb a nev�t adjuk meg a fentebb tal�lhat� f�ggv�nyeknek.
	//ut. donat ugyse olvassa baszodj meg te csicska geci.
	cout << "A kosara tartalma : " << endl;
	for (std::list<int>::iterator it = myBasket.begin(); it != myBasket.end(); ++it)
	{
		cout << (*it) << endl;
	}
}
