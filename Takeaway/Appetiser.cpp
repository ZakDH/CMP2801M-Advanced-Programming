#include "Appetiser.h"

Appetiser::Appetiser(string aName, float aPrice, int aCalories, string aShareable, string aTwoForOne) {
	name = aName;
	price = aPrice;
	calories = aCalories;
	if (aShareable == "y") { // if the ashareable variable equals y then the bool private shareable variable is then set to true
		p_shareable = true;
	}
	if (aTwoForOne == "y") {
		p_twoForOne = true;
	}
}
string Appetiser::toString() {
	string share; string twoforone; string appetiser; std::stringstream stream;
	if(p_shareable == true) {
		share = "(shareable)";
	} // if private sharable is equal to true then share variable is defined
	if (p_twoForOne == true) { 
		twoforone = "(2-4-1)"; 
	}	
	stream << std::fixed << std::setprecision(2) << price; // sets the float variable to a stringstream variable that only displays two dps
	appetiser += name + ": " + pound + stream.str() + ", " + to_string(calories) + " cal " + share + twoforone + '\n'; // assigns appetiser variable with the line to be printed in the menu
	return appetiser;
};