#include "Menu.h"
Menu::Menu(string filename) {
	ifstream file(filename);
	string temp;
	if (!file.is_open()) {
		cerr << "Error file is not found!" << endl; // if the file isnt open output error message
	}
	while (getline(file, temp)) {
		vector<string>menuVector; // temporary vector that stores words from file
		string words;
		stringstream split(temp);
		while (getline(split, words, ',')) { // gets each line from file and splits each word by the comma
			menuVector.push_back(words); // each word stuck 
		}
		try {
			if (menuVector[0] == "a") { // if first index in menu vector is equal to a, b  or m
				Item* AppObj = new Appetiser(menuVector[1], stof(menuVector[2]), stoi(menuVector[3]), menuVector[4], menuVector[5]); // creates new Appetiser object from Item* class, takes menu vector index and assigns them to new object
				items.push_back(AppObj); // pushes back the newly created object to the items vector
			}
			else if (menuVector[0] == "m") {
				Item* MainObj = new MainCourse(menuVector[1], stof(menuVector[2]), stoi(menuVector[3]));
				items.push_back(MainObj);
			}
			else if (menuVector[0] == "b") {
				Item* BevObj = new Beverage(menuVector[1], stof(menuVector[2]), stoi(menuVector[3]), stoi(menuVector[6]), stof(menuVector[7]));
				items.push_back(BevObj);
			}
			else if (menuVector[0] != "a" || menuVector[0] != "b" || menuVector[0] != "m"){
				throw "Unable to recognise item type! ";
			}
		}
		catch (string error) {
			cout << error << endl;
		}
	}
	file.close();
}
string Menu::toString() {
	string AppsTitle = "---------------Appetisers-------------------\n"; // assigns the appetiser header to the string appstitle
	string MainsTitle = "---------------Main dishes-------------------\n";
	string BevsTitle = "---------------Beverages-------------------\n";
	string Apps; string Mains; string Bevs; // assigns string variables to be used for each item type
	int vectorsize = items.size(); // vectorsize is equal to the size of the items vector
	for (unsigned int j = 0; j<vectorsize; j++) { // iterates through vector size until j is equal to the size
		if (typeid(*items[j]) == typeid(Appetiser)) {
			Apps += "(" + to_string(j + 1) + ") " + items[j]->toString(); // Apps string is assigned with an iterator (item number) and that specific item to then sent to the tostring function to look appealing
		}
		if (typeid(*items[j]) == typeid(MainCourse)) { //if the type id for the items is equal to the typeid for main course then continue in the statement
			Mains += "(" + to_string(j + 1) + ") " + items[j]->toString();
		}
		if (typeid(*items[j]) == typeid(Beverage)) {
			Bevs += "(" + to_string(j + 1) + ") " + items[j]->toString();
		}
	}
	return AppsTitle + Apps + MainsTitle + Mains + BevsTitle + Bevs; // returns the menu titles then the item type content one after another
}