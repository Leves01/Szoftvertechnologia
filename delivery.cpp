#include "delivery.h"
#include "codeGenerator.h"

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

