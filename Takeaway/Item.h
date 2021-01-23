#pragma once
#include<iostream>
#include<iomanip>
#include<vector>
#include<cstring>
#include<sstream>
using namespace std;

class Item {
protected:
	char pound = 156; // sets the variable pound to the pound sign
	string name;
	int calories;
	float price;
public:
	virtual string toString();
	string getName() { return name; } // function that 'gets' the name from the item class since the name variable is protected
	float getPrice() { return price; }
	string getCalories() { return to_string(calories); } // function that gets the calories variable from the item class and converts it to a string
};