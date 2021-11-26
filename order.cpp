#include "order.h"

Order::Order()
{

}

string Order::codeGenerator() const
{
	return CodeGenerator::generateCode(4);
}

int Order::getCode()
{
	return codeOfOrder;
}
