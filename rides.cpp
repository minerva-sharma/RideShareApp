#include "rides.h"
#include "drivers.h"
#include "passenger.h"
#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>

using namespace std;


//adds a ride object to the rides vector
void Rides::addRide(Ride rideObj){
	counter++;
	rides.push_back(rideObj);	
}

//finds a ride's index from the ID
int Rides::findRide(int ID){
	int i;
	for (i = 0; i < rides.size(); i++)
	{
		if(rides.at(i).getRideID() == ID)
		{
			break;
		}
	}
	return i;
}

//returns a ride object at a given index
Ride Rides::getRide(int i){
	return rides.at(i);
}

//changes the ride's status to cancelled
void Rides::cancelRide(int ID){
	int index = this->findRide(ID);
	rides.at(index).setRideStatus(3);
}

//edits the ride's information from user changes
void Rides::editRide(int rID){
	int choice = 0;
	cout << "What do you want to edit?"<< endl;
	cout << "Enter 1: pickup location" << endl;
	cout << "Enter 2: dropoff location" << endl;
	cout << "Your choice: ";
	cin >> choice;

	while(!(choice == 1 || choice == 2)){
		cout << "That is not one of the choices, enter another integer number: ";
		cin >> choice;
	}

	switch(choice){
		case 1:{
			string newPLoc;
			cout << "New pickup location: ";
			cin.ignore();
			getline(cin, newPLoc);
			rides.at(findRide(rID)).setPickUp(newPLoc);
			break;
			}
		case 2:{
			string newDLoc;
			cout << "New dropoff location: ";
			cin.ignore();
			getline(cin, newDLoc);
			rides.at(findRide(rID)).setDropOff(newDLoc);
			break;
			}
	}
}

//removes a ride from the vector
void Rides::deleteRide(int ID){
	int deleteEle = findRide(ID);
	rides.erase(rides.begin() + deleteEle);
}

//prints the all of the information for all of the rides
void Rides::printAllRides(){
	cout << "Rides: " << endl;
	for (int i = 0; i < rides.size(); i++){
		cout << "ID: " << rides.at(i).getRideID() << endl;
	}
}

//prints details of one ride
void Rides::printDetailsOfRide(int ID){
	int i = findRide(ID);
	time_t pickT = rides.at(i).getPickTime();
	time_t dropT = rides.at(i).getDropTime();

	cout << "Ride ID: " << rides.at(i).getRideID() << endl;
	cout << "Driver ID: " << rides.at(i).getDriverID() << endl;
	cout << "Passenger ID: " << rides.at(i).getPassID() << endl;
	cout << "Pickup Location: " << rides.at(i).getPickUp() << endl;
	cout << "Dropoff Location: " << rides.at(i).getDropOff() << endl;
	cout << "Pickup Time: " << ctime(&pickT) << endl;
	cout << "Dropoff Time: " << ctime(&dropT) << endl;
	cout << "Party Size: " << rides.at(i).getPartySize() << endl;
	cout << "Includes Pets: " << rides.at(i).getPets() << endl;
	if (rides.at(i).getRideStatus() == 1){
		cout << "Status: Active" << endl;
	}
	else if (rides.at(i).getRideStatus() == 2){
		cout << "Status: Completed" << endl;
	}
	else{
		cout << "Status: Cancelled" << endl;
	}
	cout << "Customer Rating: " << rides.at(i).getCustRating() << endl;	
}

//prints all rides with an active status
void Rides::printActiveRides(){
	cout << "Active Rides:" << endl;
	for (int i = 0; i < rides.size(); i++){
		if (rides.at(i).getRideStatus() == 1){
			cout << "Ride ID: " << rides.at(i).getRideID() << endl;
		}
	}
}

//prints all rides with a completed status
void Rides::printCompletedRides(){
	cout << "Complete Rides:" << endl;
	for (int i = 0; i < rides.size(); i++){
		if (rides.at(i).getRideStatus() == 2){
			cout << "Ride ID: " << rides.at(i).getRideID() << endl;
		}
	}
}

//prints all rides with a completed status
void Rides::printCancelledRides(){
	cout << "Cancelled Rides:" << endl;
	for (int i = 0; i < rides.size(); i++){
		if (rides.at(i).getRideStatus() == 3){
			cout << "Ride ID :" << rides.at(i).getRideID() << endl;
		}
	}

}

//prints all rides for a driver
void Rides::printDriverSched(int ID){
	cout << "Driver Schedule: " << endl;
	for (int i = 0; i < rides.size(); i++){
		if (ID == rides.at(i).getDriverID() && rides.at(i).getRideStatus() == 1){
			time_t pickT = rides.at(i).getPickTime();
			time_t dropT = rides.at(i).getDropTime();
			cout << "Ride ID: " << rides.at(i).getRideID() << endl;
			cout << "Pickup Time: " << ctime(&pickT) << endl;
			cout << "Dropoff Time: " << ctime(&dropT) << endl;
		}
	}
}

//prints all of the rides for a passenger
void Rides::printPassSched(int ID){
	cout << "Passenger Schedule: " << endl;
	for (int i = 0; i < rides.size(); i++){
		if (ID == rides.at(i).getPassID() && rides.at(i).getRideStatus() == 1){
			time_t pickT = rides.at(i).getPickTime();
			time_t dropT = rides.at(i).getDropTime();
			cout << "Ride ID: " << rides.at(i).getRideID() << endl;
			cout << "Pickup Time: " << ctime(&pickT) << endl;
			cout << "Dropoff Time: " << ctime(&dropT) << endl;
		}
	}

}

//removes cancelled rides from ride vector
void Rides::deleteCancelledRides(){
	for (int i = 0; i < rides.size(); i++){
		if (rides.at(i).getRideStatus() == 3){
			deleteRide(rides.at(i).getRideID());
		}
	}
}

//changes status of the ride if it has been completed
void Rides::updateRides(){
	time_t currentT = time(0);
	for (int i = 0; i < rides.size(); i++){
		if (rides.at(i).getDropTime() < currentT){
			rides.at(i).setRideStatus(2);
		}
	}
}

//returns the ID maker 
int Rides::getNewID(){
	return counter + 10000000;
}

//returns the size of the vector
int Rides::getRideCounter(){
	return rides.size();
}
