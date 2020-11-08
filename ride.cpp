#include "ride.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

//constructor for all of the ride information
Ride::Ride(){
	rideID = 0;
	driverID = 0;
	passID = 0;
	pickUpLoc = "";
	dropOffLoc = "";
	partySize = 0;
	includePets = false;
	status = 0;
	customerRating = 0.0;
}

//sets or gets the ID of the ride, driver, passenger
void Ride::setRideID(int id){
	rideID = id;
}

int Ride::getRideID(){
	return rideID;
}


void Ride::setDriverID(int id){
	driverID = id;
}

int Ride::getDriverID(){
	return driverID;
}

void Ride::setPassID(int id){
	passID = id;
}

int Ride::getPassID(){
	return passID;
}

//sets and gets the pickup and dropoff locations
void Ride::setPickUp(string pickUp){
	pickUpLoc = pickUp;
}

string Ride::getPickUp(){
	return pickUpLoc;
}

void Ride::setDropOff(string dropOff){
	dropOffLoc = dropOff;
}

string Ride::getDropOff(){
	return dropOffLoc;
}

//sets and getst he pick up and drop off times
void Ride::setPickTime(time_t pickTime){
	pickupTime = pickTime;
}

time_t Ride::getPickTime(){
	return pickupTime;
}

void Ride::setDropTime(time_t dropTime){
	dropOffTime = dropTime;
}

time_t Ride::getDropTime(){
	return dropOffTime;
}

//sets and gets if the ride includes pets
void Ride::setPets(bool pets){
	includePets = pets;
}

bool Ride::getPets(){
	return includePets;
}

//sets and gets the number of people on the ride
void Ride::setPartySize(bool party){
	partySize = party;
}

bool Ride::getPartySize(){
	return partySize;
}

//sets and gets if the ride is active, completed, or cancelled
void Ride::setRideStatus(int stat){
	status = stat;
}

int Ride::getRideStatus(){
	return status;
}

//sets and gets the passenger's rating
void Ride::setCustRating(float rate){
	customerRating = rate;
}

float Ride::getCustRating(){
	return customerRating;
}
