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
{ //am�gy passz ezt hogy akarjuk csin�lni ezt kellett volna megbesz�lni mi legyen product listet hasonl�tsuk �ssze ezzel a listtel �s azokat hasonl�tsuk �ssze
	//vagy a mainben hozzunk l�tre egy product v�ltoz�t majd �s az alapj�n gettelj�k  a productid alapj�n a nev�t
	// vagy sim�n Id helyet ink�bb a nev�t adjuk meg a fentebb tal�lhat� f�ggv�nyeknek.
	//ut. donat ugyse olvassa baszodj meg te csicska geci.
	cout << A kosara tartalma:
	for (std::list<int>::iterator it = MyBasket.begin(); it != MyBasket.end(); ++it)
	{
		cout << it << endl;

	}
}
