/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for "Takeaway" assignment
Autumn 2020

Written by James Brown

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure you follow that guideline.
Also make sure that you don't modify the code provided here,
but instead add what you need to complete the tasks.

Good luck!
------------------------------------------------------ */
#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include "Order.h"
#include "Item.h"

using namespace std;

int main()
{
	string userCommand;
	vector <string> parameters;

	//Create a menu object from a CSV file
	Menu menu = Menu("menu.csv"); // creates object for Menu and passes the file name/path as the argument
	vector<Item*>ordering = menu.getVector(); 

	// Create an order object
	Order order = Order(); // creates order object from order class

	while (userCommand != "exit") // while the user choice is not equal to exit the program will not quit
	{
		getline(cin, userCommand); // gets the entire input from the user
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());

		char* token;
		token = strtok(cstr, " "); // gets a token of each word/character that is split by a space

		while (token != NULL) // while token is not empty
		{
			parameters.push_back(token); // the first word is pushed back into the parameters vector
			token = strtok(NULL, " ");
		}
		string command = parameters[0]; // command is equal to the first index in the user input 'parameters' eg: add
		if (command.compare("menu") == 0) { // if user enters menu the menu tostring function is called to display the menu in an appealing manner
			cout << menu.toString();
		}
		else if (command.compare("add") == 0)
		{
			for (int i = 1; i < parameters.size(); i++) {
				Item* choice = ordering[stoi(parameters[i]) - 1]; // you need to instantiate this using the menu object! // indexing starts at 0 so -1 ensures that the user doesnt enter an invalid index eg: anything > 12
				order.add(choice); // calls the add function in order class with the choice the user has entered// loops through each character same as remove to compare to the items number and find a match
			}
		}	
			// You may also wish to implement the ability to add multiple items at once!
			// e.g. add 1 5 9 	
		else if (command.compare("remove") == 0)
		{
			for (int i = 1; i < parameters.size(); i++) { // loops through each character same as add to compare to the items number and find a match
				
				Item* choice = ordering[stoi(parameters[i]) - 1]; // you need to instantiate this using the menu object! // indexing starts at 0 so -1 ensures that the user doesnt enter an invalid index eg: anything > 12
				order.remove(choice); // calls the remove function in order class with the choice the user has entered
			}	
		}
		else if (command.compare("checkout") == 0) // if user input is equal to 'checkout'
		{
			string input;
			cout << "===== Checkout =====" << endl;
			order.toString();// calls the order to string function to display the final checkout to the user before confirming order
			order.calculateTotal();	// calls the calculate total function which gives the user the overall cost of all the items added by the user
			input += order.placeOrder(); // assigns the variable input to what the user enters in the place order function 'either y or n'
			if (input == "n") { // if the user wants to change their order
				string orderchange;
				cout << "What would you like to change to the order? " << endl;
				getline(cin, orderchange);	// gets the entire input from the user rather than the first entered word
			}
		}
		else if (command.compare("help") == 0) // if user wants help this is displayed to help them
		{
			cout << "menu - display the menu to the user" << endl;
			cout << "add [INDEX] - add an item to the order by numeric index in the menu (starting at 1)" << endl;
			cout << "remove [INDEX] - remove item from order by numeric index in the order (starting at 1)" << endl;
			cout << "checkout - display the items in the user’s order, the price, and discount savings" << endl;
			cout << "help - display a help menu for the user with the available options" << endl;
			cout << "exit - terminate the program gracefully" << endl;
		}
		else {
			cerr << "An unrecognised word was entered into the program, please try again! " << endl;
			exit(EXIT_FAILURE);
		}
		parameters.clear(); // clears what is in parameters vector to save memory 
	}
	cout << "Press any key to quit..."; // quits the program gracefully
	std::getchar();
}