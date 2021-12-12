#include "delivery.h"
#include "codeGenerator.h"

Delivery::Delivery(std::string _buyerCode, std::string _deliveryAddress, std::string _megye, std::string _order) : 
	buyerCode(_buyerCode),
	deliveryAddress(_deliveryAddress),
	megye(_megye),
	order(_order)

{
	Delivery::generateDeliveryCode();
}

void Delivery::setDeliveryAddress(std::string newAddress)
{
	deliveryAddress = newAddress;
}

void Delivery::generateDeliveryCode()
{
	CodeGenerator newCode;
	std::string newDeliveryCode = newCode.generateCode(8);
	deliveryCode = newDeliveryCode;
}

std::string Delivery::getDeliveryAddress() const
{
	return deliveryAddress;
}

std::string Delivery::getDeliveryCode() const
{
	return deliveryCode;
}

std::string Delivery::getmegye() const
{
	return megye;
}

std::string Delivery::getBuyer() const
{
	return buyerCode;
}

std::string Delivery::getOrder() const
{
	return order;
}

void Delivery::setDeliveryCode(std::string _code)
{
	deliveryCode = _code;
}

