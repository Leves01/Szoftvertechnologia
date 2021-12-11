#ifndef BUYER_H
#define BUYER_H
#include "user.h"
#include "includes.h"
#include "product.h"
#include "database.h"
#include "delivery.h"
 


class Buyer : public User
{
private:
    std::string userId;
    std::string orderCode;
    std::list<std::string> myBasket;

public:
    Buyer(std::string _userId);
    std::string getOrderCode() const;
    void addToBasket(std::string productId);
    void removeFromBasket(std::string productId);
    void listMyBasket()const;
    std::string setOrder();

};

#endif // BUYER_H

//- OrderCode : Order
//+ getOderCode : string
//+ addToBasket() : void
//+ removeFromBasket(ProductId) : void
//+ myBasket() : void