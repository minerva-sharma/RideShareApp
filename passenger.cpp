#include "passenger.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

//constructor for all of the passenger's information
Passenger::Passenger(){
	firstName = "";
	lastName = "";
	passID = 0;
	paymentPref = 0;
	handicapped = false;
	passRating = 0.00;
	hasPets = false;
}

//sets and gets the passenger's ID
void Passenger::setPassID(int ID){
	passID = ID;
}

int Passenger::getPassID(){
	return passID;
}

//sets and gets the passenger's first and last name
void Passenger::setFirstName(string first){
	firstName = first;
}

string Passenger::getFirstName(){
	return firstName;
}

void Passenger::setLastName(string last){
	lastName = last;
}

string Passenger::getLastName(){
	return lastName;
}

//sets and gets the passenger's payment preference
void Passenger::setPayPref(int pPref){
	paymentPref = pPref;
}

int Passenger::getPayPref(){
	return paymentPref;
}

//sets and gets if the passenger is handicapped or not
void Passenger::setHandicapped(bool handi){
	handicapped = handi;
}

bool Passenger::getHandicapped(){
	return handicapped;
}

//sets and gets the passenger's minimum rating
void Passenger::setPassRating(float rating){
	passRating = rating;
}

float Passenger::getPassRating(){
	return passRating;
}

//sets and gets if the passengers has pets
void Passenger::setHasPets(bool pets){
	hasPets = pets;
}

bool Passenger::getHasPets(){
	return hasPets;
}
