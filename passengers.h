#ifndef PASSENGERS_H
#define PASSENGERS_H

#include "passenger.h"
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Passengers{
	public:
		void addPassenger();			//adds passenger to vector of all passengers
		void editPassenger(int ID);		//edits the information in the passenger object
		void deletePassenger(int ID);		//removes a passenger form the vector
		int findPassenger(int ID);		//finds a passenger from their ID
		Passenger getPassObj(int i);		//returns a passenger object from their ID
		void printAllPassengers();		//prints the ID and name of all of the passengers
		void printDetailsOfPassenger(int ID);	//prints all of the information of one of the passengers
		void savePass(Passenger passenger);	//adds passenger to the vector
		int getPCounter();			//gets the size of the vector
	private:
		vector<Passenger> passengers;	//vector of all passengers
		int pcounter = 0;		//counts total number of passengers
};

#endif
