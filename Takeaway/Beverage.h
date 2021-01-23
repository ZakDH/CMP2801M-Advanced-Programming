#pragma once
#include "Item.h"
class Beverage : public Item {
private:
	float abv = 0;
	int volume = 0;
public:
	Beverage(string aName, float aPrice, int aCalories, int aVolume, float aAbv);
	string toString();
};