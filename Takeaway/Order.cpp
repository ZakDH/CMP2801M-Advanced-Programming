#include "Order.h"
#include <sstream>
#include <iostream>
#include <iomanip>

Order::Order() { // calls the order class from the order header file
};

string Order::add(Item* choice) { // passes in the choice the user has entered after the command eg: after - add, remove
	string temp;
	cout << choice->getName() << " was added to the order!" << endl; // gets name thats matched to the choice given and prints out to user
	items.push_back(choice); // pushes back the choice into the items vector
	total += choice->getPrice(); // gets the price of the item that the user has chosen - price is a protected variable in Item class so getprice is used to get the price
	return temp;
}

string Order::remove(Item* choice) {
	string temp;
	cout << choice->getName() << " was removed from the order!" << endl;
	auto findchoice = find(items.begin(), items.end(), choice); //finds the choice the user gave by iterating through the items vector from start to finish until the 'choice' is found
	if (findchoice != items.end()) { // if choice is not equal to the end of the vector
		items.erase(findchoice); // deletes the choice the user has entered from the items vector
		total -= choice->getPrice(); // subtracts the price from the choice given by the user from the total variable 
		return temp;
	}
}
string Order::toString() {
	string checkout;
	for (int i = 0; i < items.size(); i++) { // iterates through the items vector and increments each time until i is equal to the size of the vector ie : 12
		cout << "(" + to_string(i + 1) + ") " + items[i]->toString(); 
		checkout += "(" + to_string(i + 1) + ") " + items[i]->toString();// prints the item number then calls the item tostring function to display the order
	}
	return checkout;
	calculateTotal(); // calls the calculatetotal function
}
string Order::calculateTotal() {
	char pound = 156; // assigns the pound variable with the character numbered 156 which is the pound sign
	string calculations;
	calculations + "Total: "+ pound + to_string(total) + '\n'; // assigns the total output to the variable calculations which is then returned 
	//cout << "Total: " << pound << total << endl; // prints the total price of the items added to the order
	return calculations;
}
string Order::placeOrder() {
	cout << "Do you want to place your order? " << endl;
	cout << "Type 'y' to confirm order, or 'n' to change the order confirmation. " << endl;
	string input;
	cin >> input;
	if (input == "y") { // if the user is done with their order the receipt function is called
		receipt();
	}
	else if (input == "n") { // if the user is not done with their order the input is returned and the user can add to the order again
		cout << "Make the necessary changes to your order! "<< endl;
		return input;
	}
}
void Order::receipt() {
	ofstream receipt("Receipt.txt", ofstream::trunc); // creates a file called receipt.txt where the receipt will be written into. trunc ensures that the file doesnt exist and if it does then file is overwritten
	if (!receipt) { // is output file is not created
		cerr << "Cannot open the output file. " << endl; // throw an error to the user
	}
	receipt << "Receipt:" << endl; // writes Receipt to the file
	receipt << toString() << " " << endl; // writes the tostring function content to the file
	receipt.close(); // ensures the receipt file is closed before the program is terminated
}