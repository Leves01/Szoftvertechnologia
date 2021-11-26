#ifndef ORDER_H
#define ORDER_H
#include "includes.h"
#include "codeGenerator.h"


class Order
{
private:
    int codeOfOrder;
    string OrderedProductId;

public:
    Order();
    string codeGenerator()const;
    int getCode();
};

#endif // ORDER_H
