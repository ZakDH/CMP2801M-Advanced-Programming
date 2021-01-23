#pragma once
#include "Item.h"
class Appetiser : public Item {
private:
	bool p_shareable = false; // sets the private bool variables to false
	bool p_twoForOne = false;
public:
	Appetiser(string aName, float aPrice, int aCalories, string aShareable, string aTwoForOne);
	string toString();
	string getDiscount() { return to_string(p_twoForOne); } // declares a getdiscount function which returns the private twoforone variable
};