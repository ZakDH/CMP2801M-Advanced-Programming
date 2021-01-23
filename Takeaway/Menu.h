#pragma once
#include "ItemList.h"

class Menu : public ItemList { // menu class is derived from the public itemlist class
public:
	Menu(string filename); // declares the Menu function and ensures the file is passed as a parameter
	string toString(); // declares the tostring function to 
};