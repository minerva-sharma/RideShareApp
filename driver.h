#ifndef DRIVER_H
#define DRIVER_H
#include <string>
#include <cstdlib>

using namespace std;

class Driver{
	public:
		Driver();	//construct for driver variables
		//sets and gets the driver's ID
		void setDriverID(int ID);
		int getDriverID();
		//sets and gets the driver's first and last name
		void setFirstName(string first);
		string getFirstName();
		void setLastName(string last);
		string getLastName();	
		//sets and gets the driver's vehicle capacity
		void setVehicleCap(int vCap);
		int getVehicleCap();
		//sets and gets if the driver is handicap capable
		void setHandicapCap(bool hCap);
		bool getHandicapCap();
		//sets and gets the driver's vehicle type
		void setVehicleType(int vType);
		int getVehicleType();
		//sets and gets the driver's rating
		void setDriverRating(float rating);
		float getDriverRating();
		//sets and gets if the driver is available
		void setDriverAva(bool ava);
		bool getAvailable();
		//sets and gets if the driver allows pets
		void setPetAllowed(bool pets);
		bool getPetAllowed();
		//sets and gets driver notes
		void setNotes(string note);
		string getNotes();
	private:
		int driverID;		//driver ID
		string firstName;	//driver's first name
		string lastName;	//driver's last name
		int vehicleCap;		//driver's capacity
		int vehicleType;	//driver's vehicle type
		bool handicapCAP;	//if the driver is handicap capable
		float driverRating;	//driver's rating
		bool available;		//driver avalibility
		bool petsAllowed;	//if the driver allows pets
		string notes;		//driver notes
};
#endif
