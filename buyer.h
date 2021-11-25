#ifndef BUYER_H
#define BUYER_H
#include "includes.h"
#include "product.h"


class Buyer
{
private:
    string OrderCode;
    list<int> MyBasket;

public:
    Buyer();
    string getOrderCode() const { return OrderCode };
    void addToBasket(int ProductId);
    void removeFromBasket(int ProductId);
    void myBasket();

};

#endif // BUYER_H
//- OrderCode : Order
//+ getOderCode : string
//+ addToBasket() : void
//+ removeFromBasket(ProductId) : void
//+ myBasket() : void