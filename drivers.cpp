#include "drivers.h"
#include "driver.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//asks for questions about driver object and adds it to vector
void Drivers::addDriver(){
	Driver adriver;
	string first;
	string last;
	int vehiclecap;
	bool handicap;
	int vehicle;
	float rating;
	bool avail;
	bool pets;
	string notes1;

	cout << "Driver's first name: ";
	cin >> first;
	adriver.setFirstName(first);

	counter++;
	adriver.setDriverID(counter + 100000);

	cout << "Driver's last name: ";
	cin >> last;
	adriver.setLastName(last);

	cout << "Driver id: " << (counter + 100000) << endl;

	cout << "Driver's Vehicle Capcity (enter a positive interger number value): ";
	cin >> vehiclecap;
	adriver.setVehicleCap(vehiclecap);

	cout << "Is the Driver Handicapped Capable? (0 for no or 1 for yes): ";
	cin >> handicap;
	adriver.setHandicapCap(handicap);

	cout << "Driver's Vehicle Type (enter 1 for Compact 2Door, 2 for Sedan 4Door, 3 for SUV, 4 for Van, or 5 for other): ";
	cin >> vehicle;
	adriver.setVehicleType(vehicle);

	cout << "Driver Rating (enter a positive float number between 1-5): ";
	cin >> rating;
	adriver.setDriverRating(rating);

	cout << "Is the Driver Available? (0 for no or 1 for yes): ";
	cin >> avail;
	adriver.setDriverAva(avail);

	cout << "Does the Driver allow pets? (0 for no or 1 for yes): ";
	cin >> pets;
	adriver.setPetAllowed(pets);

	cout << "Add Any Notes About the Driver: ";
	cin.ignore();
	getline(cin, notes1);
	adriver.setNotes(notes1);

	drivers.push_back(adriver);
}

//finds the index of driver from ID
int Drivers::findDriver(int ID){
	int i = 0;
	for (i = 0; i < drivers.size(); i++)
	{
		if (drivers.at(i).getDriverID() == ID)
		{
			break;
		}
	}
	return i;
}

//adds new driver to vector (w/o asking for questions)
void Drivers::newDriver(Driver d){
	drivers.push_back(d);
	counter++;
}

//returns driver object at index
Driver Drivers::getDriverObj(int i){
	return drivers.at(i);
}

//edits a driver object with user entered data
void Drivers::editDriver(int ID){
	int choice = 0;
	cout << "What do you want to edit?"<< endl;
	cout << "Enter 1: driver vehicle capacity" << endl;
	cout << "Enter 2: driver handicapped capability" << endl;
	cout << "Enter 3: vehicle type" << endl;
	cout << "Enter 4: driver rating" << endl;
	cout << "Enter 5: driver availability" << endl;
	cout << "Enter 6: driver pet availability" << endl;
	cout << "Enter 7: driver notes" << endl;
	cout << "Enter 8: driver first name" << endl;
	cout << "Enter 9: driver last name" << endl;
	cout << "Your choice: ";
	cin >> choice;

	while(choice < 1 && choice > 9){
		cout << "That is not one of the choices, enter another integer number:";
		cin >> choice;
	}

	switch(choice){
		case 1:{
			int capa;
			cout << "New vehicle capacity (int number): ";
			cin >> capa;
			drivers.at(findDriver(ID)).setVehicleCap(capa);
			break;
			}
		case 2:
			{
			bool handi;
			cout << "Driver handicapped capability (0 for no or 1 for yes): ";
			cin >> handi;
			drivers.at(findDriver(ID)).setHandicapCap(handi);
			break;
			}
		case 3:
			{
			int vehiType;
			cout << "New vehicle type (enter 1 for Compact 2Door, 2 for Sedan 4Door, 3 for SUV, 4 for Van, or 5 for other): ";
			cin >> vehiType;
			drivers.at(findDriver(ID)).setVehicleType(vehiType);
			break;
			}
		case 4:
			{
			float rates;
			cout << "New rating (enter a floating point between 1 -5): ";
			cin >> rates;
			drivers.at(findDriver(ID)).setDriverRating(rates);
			break;
			}
		case 5:
			{
			bool avali;
			cout << "Driver availability (0 for no or 1 for yes): ";
			cin >> avali;
			drivers.at(findDriver(ID)).setDriverAva(avali);
			break;
			}
		case 6: 
			{
			bool pet;
			cout << "Driver pet availability (0 for no or 1 for yes): ";
			cin >> pet;
			drivers.at(findDriver(ID)).setPetAllowed(pet);
			break;
			}
		case 7:
			{
			string note;
			cout << "New Driver notes (string): ";
			cin.ignore();
			getline(cin, note);
			drivers.at(findDriver(ID)).setNotes(note);
			break;
			}
		case 8:
			{
			string first;
			cout << "New driver first name (string): ";
			cin >> first;
			drivers.at(findDriver(ID)).setFirstName(first);
			break;
			}
		case 9:
			{
			string last;
			cout << "New driver last name(string): ";
			cin >> last;
			drivers.at(findDriver(ID)).setLastName(last);
			break;
			}
		}
}

//removes a driver object from the vector
void Drivers::deleteDriver(int ID){
	int deleteEle = findDriver(ID);
	drivers.erase(drivers.begin() + deleteEle);
}

//prints name and ID of all drivers
void Drivers::printAllDriver(){
	cout << "Drivers: " << endl;
	for (int i = 0; i  < drivers.size(); i++){
		cout << "ID: " << drivers.at(i).getDriverID() << " Name: " <<  drivers.at(i).getFirstName() << " " << drivers.at(i).getLastName() << endl;
	}
}

//prints all of the details of one driver
void Drivers::printDetailsOfDriver(int ID){
	int id  = findDriver(ID);
	cout << "ID: " << drivers.at(id).getDriverID() << endl;
	cout << "Name: " << drivers.at(id).getFirstName() << " " << drivers.at(id).getLastName() << endl;
	cout << "Vehicle Capacity: " << drivers.at(id).getVehicleCap() << endl;
	cout << "Handicapped Capable " << drivers.at(id).getHandicapCap() << endl;
	switch(drivers.at(id).getVehicleType()){
		case 1:
			cout << "Vehicle Type: Compact 2 Door" << endl;
			break;
		case 2:
			cout << "Vehicle Type: Sedan 4 Door" << endl;
			break;
		case 3:
			cout << "Vehicle Type: SUV" << endl;
			break;
		case 4:
			cout << "Vehicle Type: Van" << endl;
			break;
		case 5: 
			cout << "Vehicle Type: other" << endl;
			break;
	}
	cout << "Rating: " << drivers.at(id).getDriverRating() << endl;
	cout << "Available: " << drivers.at(id).getAvailable() << endl;
	cout << "Pet Availability: " << drivers.at(id).getPetAllowed() << endl;
	cout << "Notes: " << drivers.at(id).getNotes() << endl;
}

//returns the size of the vector
int Drivers::getCounter(){
	return drivers.size();
}
