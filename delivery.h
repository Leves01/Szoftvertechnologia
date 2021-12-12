#ifndef __DELIVERY_H__
#define __DELIVERY_H__
#include <string>

class Delivery {
private:
	std::string deliveryAddress;
	std::string deliveryCode;
	std::string buyerCode;
	std::string order;
	std::string megye;


public:
	Delivery(std::string _buyerCode, std::string _deliveryAddress, std::string _megye, std::string _order);
	void setDeliveryAddress(std::string newAddress);
	void generateDeliveryCode();
	std::string getDeliveryAddress() const;
	std::string getDeliveryCode() const;
	std::string getmegye()const;
	std::string getBuyer()const;
	std::string getOrder()const;


};

#endif // !__DELIVERY_H__
