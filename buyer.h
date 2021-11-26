#ifndef BUYER_H
#define BUYER_H
#include "user.h"
#include "includes.h"
#include "product.h"


class Buyer : public User
{
private:
    string orderCode;
    list<int> myBasket;

public:
    Buyer();
    string getOrderCode() const;
    void addToBasket(int ProductId);
    void removeFromBasket(int ProductId);
    void listMyBasket();

};

#endif // BUYER_H

//- OrderCode : Order
//+ getOderCode : string
//+ addToBasket() : void
//+ removeFromBasket(ProductId) : void
//+ myBasket() : void