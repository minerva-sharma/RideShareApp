#ifndef PASSENGER_H
#define PASSENGER_H
#include <string>

using namespace std;

class Passenger{
	public:
		Passenger();			//constuctor
		//sets and gets Passenger ID
		void setPassID(int ID);		
		int getPassID();
		//sets and gets the Passengers name (first and last)
		void setFirstName(string first);
		string getFirstName();
		void setLastName(string last);
		string getLastName();	
		//sets and gets the passenger's payment preference
		void setPayPref(int pPref);
		int getPayPref();
		//sets and gets if the passenger is handicapped
		void setHandicapped(bool handi);
		bool getHandicapped();
		//sets and gets the passenger's minimum required rating
		void setPassRating(float rating);
		float getPassRating();
		//sets and gets if the passenger has a pet
		void setHasPets(bool pets);
		bool getHasPets();
	private:
		int passID;		//the passenger's ID
		string firstName;	//the passenger's name
		string lastName;
		int paymentPref;	//the passenger's payment preference
		bool handicapped;	//if the passenger is handicapped or not
		float passRating;	//the passenger's minimum rating
		bool hasPets;		//if the passenger has pets or not
};
#endif
