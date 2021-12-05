#ifndef __DELIVERY_H__
#define __DELIVERY_H__
#include <string>

class Delivery {
private:
	std::string deliveryAddress;
	std::string deliveryCode

public:
	void setDeliveryAddress();
	std::string generateDeliveryCode();
	std::string getDeliveryAddress();
	std::string getDeliveryCode();
	std::string listDeliveriesByCode(string deliveryCode);
	std::string listDeliveriesByCountry(string deliveryAddress);

};

#endif // !__DELIVERY_H__
