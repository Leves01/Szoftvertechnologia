#ifndef __DELIVERY_H__
#define __DELIVERY_H__
#include <string>

class Delivery {
private:
	std::string deliveryAddress;
	std::string deliveryCode;

public:
	Delivery() = default;
	void addDelivery();
	void setDeliveryAddress(std::string newAddress);
	std::string generateDeliveryCode();
	std::string getDeliveryAddress() const;
	std::string getDeliveryCode() const;


};

#endif // !__DELIVERY_H__
