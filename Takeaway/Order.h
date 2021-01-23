#pragma once
#include "ItemList.h"
class Order : public ItemList {
private:
	float total = 0;
	string discount;
public:
	string choices; // stores all the function declarations to be used in the order.cpp file
	Order();
	string add(Item* choice);
	string remove(Item* choice);
	string toString();
	string calculateTotal();
	string placeOrder();
	void receipt();
};
