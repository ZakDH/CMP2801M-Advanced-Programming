#include "Beverage.h"
#include <sstream>
#include<string>
#include <iostream>
#include <iomanip>

Beverage::Beverage(string aName, float aPrice, int aCalories, int aVolume, float aAbv) {
	name = aName;
	price = aPrice; // Item and Beverage class variables are equal to the beverage function variable names
	calories = aCalories;
	abv = aAbv;
	volume = aVolume;
}
string Beverage::toString() {
	string beverage; stringstream stream; stringstream stream2;
	stream << std::fixed << std::setprecision(2) << price; // sets the float value to only display two decimal places and assigned to a variable
	stream2 << std::fixed << std::setprecision(1) << abv; // repeat of last statment but only up to 1dp is assigned to a variable
	if (abv > 0) {
		beverage += name + ": " + pound + stream.str() + ", " + to_string(calories) + " cal (" + to_string(volume) + "ml)" + " " + stream2.str() + "% abv)" + '\n'; // if abv is greater than 0 display abv percentage to the menu
	}
	else {
		beverage += name + ": " + pound + stream.str() + ", " + to_string(calories) + " cal (" + to_string(volume) + "ml)" + " " + '\n'; // if abv is less than 0 abv value is not displayed
	}
	return beverage;
}