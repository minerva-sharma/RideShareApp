#include "passengers.h"
#include "passenger.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//gets information from user about passenger to store in object
void Passengers::addPassenger(){
	Passenger aPassenger;
	string first;
	string last;
	int pay;
	bool handi;
	float rating;
	bool pet;

	cout << "Passenger's First Name: ";
	cin >> first;
	aPassenger.setFirstName(first);

	pcounter++;
	aPassenger.setPassID(100500 + pcounter);

	cout << "Passenger's Last Name: ";
	cin >> last;
	aPassenger.setLastName(last);

	cout << "Passenger ID: " << (100500 + pcounter) << endl;

	cout << "Passenger's Payment Preference (1 for cash, 2 for credit, 3 debit): ";
	cin >> pay;
	aPassenger.setPayPref(pay);

	cout << "Passenger Handicapped (0 for no or 1 for yes): ";
	cin >> handi;
	aPassenger.setHandicapped(handi);

	cout << "Passenger Required Rating (enter a floating point value between 1-5): ";
	cin >> rating;
	aPassenger.setPassRating(rating);

	cout << "Passenger Has Pets (0 for no or 1 for yes): ";
	cin >> pet;
	aPassenger.setHasPets(pet);

	passengers.push_back(aPassenger);
}

//finds passenger index from their ID
int Passengers::findPassenger(int ID){
	int j = -1;
	for (int i = 0; i < passengers.size(); i++)
	{
		if (passengers.at(i).getPassID() == ID)
		{
			j = i;
			break;
		}
	}
	return j;
}

//returns the passenger object from the index of the passenger
Passenger Passengers::getPassObj(int i){
	return passengers.at(i);
}

//adds passenger object to the vector (w/o asking for information)
//for reading in file and saving in a vector
void Passengers::savePass(Passenger passenger){
	pcounter++;
	passengers.push_back(passenger);
}

//gets edits from user and edts object
void Passengers::editPassenger(int ID){
	int choice = 0;
	cout << "What do you want to edit?"<< endl;
	cout << "Enter 1: passenger payment preference" << endl;
	cout << "Enter 2: passenger handicapped" << endl;
	cout << "Enter 3: passenger rating required" << endl;
	cout << "Enter 4: passenger has pets" << endl;
	cout << "Enter 5: passenger first name" << endl;
	cout << "Enter 6: passenger last name: " << endl;
	cout << "Your choice: ";
	cin >> choice;

	while(choice < 1 && choice > 6){
		cout << "That is not one of the choices, enter another integer number: ";
	}

	switch(choice){
		case 1:{
			int money;
			cout << "New payment preference (1 for cash, 2 for credit, 3 for debit): ";
			cin >> money;
			passengers.at(findPassenger(ID)).setPayPref(money);
			break;
			}
		case 2:{
			bool handi;
			cout << "Is the passenger handicapped (0 for no or 1 for yes): ";
			cin >> handi;
			passengers.at(findPassenger(ID)).setHandicapped(handi);
			break;
			}
		case 3:{
			float rate;
			cout << "New passenger required rating (floating point number): ";
			cin >> rate;
			passengers.at(findPassenger(ID)).setPassRating(rate);
			break;
			}
		case 4:{
			bool pet;
			cout << "Does the rider have pets (0 for no or 1 for yes): ";
			cin >> pet;
			passengers.at(findPassenger(ID)).setHasPets(pet);
			break;
			}
		case 5:{
			string first;
			cout << "New first name (string): ";
			cin >> first;
			passengers.at(findPassenger(ID)).setFirstName(first);
			break;
			}
		case 6:{
			string last;
			cout << "New last name (string): ";
			cin >> last;
			passengers.at(findPassenger(ID)).setLastName(last);
			break;
			}
	}
}

//removes passenger object from vector from ID
void Passengers::deletePassenger(int ID){
	int deleteEle = findPassenger(ID);
	passengers.erase(passengers.begin() + deleteEle);
}

//prints the name and ID of all passengers
void Passengers::printAllPassengers(){
	cout << "Passengers: " << endl;
	for (int i = 0; i  < passengers.size(); i++){
		cout << "ID: " << passengers.at(i).getPassID() << " Name: " << passengers.at(i).getFirstName() << " " << passengers.at(i).getLastName()<< endl;
	}
}

//prints all information of one passenger
void Passengers::printDetailsOfPassenger(int ID){
	int id  = findPassenger(ID);
	cout << "ID: " << passengers.at(id).getPassID() << endl;
	cout << "Name: " << passengers.at(id).getFirstName() << " " << passengers.at(id).getLastName() << endl;
	if (passengers.at(id).getPayPref() == 1)
	{
		cout << "Passenger Payment Preference: cash" << endl;
	}
	if (passengers.at(id).getPayPref() == 2)
	{
		cout << "Passenger Payment Preference: credit" << endl;
	}
	else
	{
		cout << "Passenger Payment Preference: debit" << endl;
	}
	cout << "Handicapped: " << passengers.at(id).getHandicapped() << endl;
	cout << "Rating Required: " << passengers.at(id).getPassRating() << endl;
	cout << "Has Pets: " << passengers.at(id).getHasPets() << endl;
}

//returns size of the vector
int Passengers::getPCounter(){
	return passengers.size();
}
