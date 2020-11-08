#ifndef RIDE_H
#define RIDE_H

#include <iostream>
#include <stdio.h>
#include <vector>
#include <ctime>

using namespace std;

class Ride{
	public:
		Ride();					//constructor
		//sets and gets the ride's ID
		void setRideID(int id);
		int getRideID();
		//sets and gets the Drivers's ID
		void setDriverID(int id);
		int getDriverID();
		//sets and gets the Passenger's ID
		void setPassID(int id);
		int getPassID();
		//sets and gets the pickup and dropoff locations for the ride
		void setPickUp(string pickUp);
		string getPickUp();
		void setDropOff(string dropOff);
		string getDropOff();
		//sets and gets the pickup and dropoff times for the ride
		void setPickTime(time_t pickTime);
		time_t getPickTime();
		void setDropTime(time_t dropTime);
		time_t getDropTime();
		//sets and gets if the ride includes pets
		void setPets(bool pets);
		bool getPets();
		//sets and gets the number of people in the ride
		void setPartySize(bool party);
		bool getPartySize();
		//sets and gets if the ride is active, completed of cancelled
		void setRideStatus(int stat);
		int getRideStatus();
		//setes and gets the passenger's rating of the ride
		void setCustRating(float rate);
		float getCustRating();
	private:
		int rideID;		//ID number for the ride
		int driverID;		//ID of the driver
		int passID;		//ID of the passenger
		string pickUpLoc;	//pick up location
		string dropOffLoc;	//drop off location
		time_t pickupTime;	//pick up time
		time_t dropOffTime;	//drop off time
		bool includePets;	//if the ride includes pets or not
		int partySize;		//number of people in ride
		int status;		//if the ride is active, completed, or cancelled
		float customerRating;	//passenger's rating
};

#endif
