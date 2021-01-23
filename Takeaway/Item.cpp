#include "Item.h"
#include <sstream>
#include <iostream>
#include <iomanip>

string Item::toString() {
	string itemdisplay;
	stringstream stream;
	stream << fixed << setprecision(2) << price; // uses setprecision to ensure only 2 dp's are assigned to the variable
	itemdisplay += name + ": " + pound + stream.str() + ", " + to_string(calories) + " cal " +'\n'; // to_string converts a variable that isnt a string in this case either int or float to string
	return itemdisplay;
}