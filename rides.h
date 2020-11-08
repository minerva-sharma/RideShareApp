#include "ride.h"
#include "drivers.h"
#include "passengers.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Rides{
	public:
		void addRide(Ride rideObj);		//adds a ride object to the vector
		int findRide(int ID);			//finds the index of a ride
		void editRide(int ID);			//edits the information of a ride object
		void cancelRide(int ID);		//changes the status of a ride to cancelled
		void deleteRide(int ID);		//removes a ride from the ride vector
		void printAllRides();			//prints the ID of all of the rides
		void printDetailsOfRide(int ID);	//prints the details of one ride
		void printActiveRides();		//prints all of the rides with an active status
		void printCompletedRides();		//prints all of the rides with a completed status
		void printCancelledRides();		//prints all of the rides with a cancelled status
		void printDriverSched(int ID);		//prints all of the rides for a driver
		void printPassSched(int ID);		//prints all of the rides for a passenger
		void deleteCancelledRides();		//removes cancelled rides from the vector
		void updateRides();			//changes the status of the ride if completed
		int getRideID(int i);			//returns the rideID
		int getNewID();				//returns the rideID counter
		Ride getRide(int i);			//returns a ride object from the index
		int getRideCounter();			//returns the size of the vector
	private:
		vector<Ride> rides;			//vector the stores all of the rides made
		int counter = 0;			//counts the number of rides made total
};		
