#include "driver.h"
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

//constuctor
Driver::Driver(){
	driverID = 0;
	firstName = "";
	lastName = "";
	vehicleCap = 0;
	handicapCAP = 0;
	vehicleType = 0;
	driverRating = 0.00;
	available = 0;
	petsAllowed = 0;
	notes = "";
}

//sets and gets driver ID
void Driver::setDriverID(int ID){
	driverID = ID;
}

int Driver::getDriverID(){
	return driverID;
}

//sets and gets driver name
void Driver::setFirstName(string first){
	firstName = first;
}

string Driver::getFirstName(){
	return firstName;
}
void Driver::setLastName(string last){
	lastName = last;
}

string Driver::getLastName(){
	return lastName;
}

//sets and gets car capacity
void Driver::setVehicleCap(int vCap){
	vehicleCap = vCap;
}

int Driver::getVehicleCap(){
	return vehicleCap;
}

//sets and gets if handicap capable
void Driver::setHandicapCap(bool hCap){
	handicapCAP = hCap;
}

bool Driver::getHandicapCap(){
	return handicapCAP;
}

//sets and gets car type
void Driver::setVehicleType(int vType){
	vehicleType = vType;
}

int Driver::getVehicleType(){
	return vehicleType;
}

//sets and gets rating
void Driver::setDriverRating(float rating){
	driverRating = rating;
}

float Driver::getDriverRating(){
	return driverRating;
}

//sets and gets avalible
void Driver::setDriverAva(bool ava){
	available = ava;
}

bool Driver::getAvailable(){
	return available;
}

//sets and gets if pets are allowed
void Driver::setPetAllowed(bool pets){
	petsAllowed = pets;
}

bool Driver::getPetAllowed(){
	return petsAllowed;
}

//sets and gets notes
void Driver::setNotes(string note){
	notes = note;
}

string Driver::getNotes(){
	return notes;
}
