#pragma once
#include "Appetiser.h"
#include "Beverage.h"
#include "MainCourse.h"
#include "Item.h"
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<istream>
class ItemList {
protected:
	vector<Item*>items; // pointer vector is assigned the name items
public:
	virtual string toString() = 0; // pure virtual function is assigned the value of 0 so function can then be overwritten in other functions and classes
	vector<Item*> getVector(); // declares a getvector function which will 'get' the items vector to be used else where in the program
};
