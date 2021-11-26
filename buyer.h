#ifndef BUYER_H
#define BUYER_H
#include "user.h"
#include "includes.h"
#include "product.h"


class Buyer : public User
{
private:
    std::string orderCode;
    std::list<int> myBasket;

public:
    Buyer();
    std::string getOrderCode() const;
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