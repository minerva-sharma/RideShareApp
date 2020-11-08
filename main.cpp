/*
Minerva Sharma
minervasharma@my.unt.edu
This program will get information from a user and schedule rides for drivers and passengers.
*/
#include "drivers.h"
#include "passengers.h"
#include "rides.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

//functions for scanning and loading a file
void scanFile(string fileName, Rides &rides, Drivers &drivers, Passengers &passengers);
void loadFile(string fileName, Rides &rides, Drivers &drivers, Passengers &passengers);

int main() {
	//student information
	cout << "CSCE 1040.001" << endl;
	cout << "HW3" << endl;
	cout << "Minerva Sharma" << endl;
	cout << "minervasharma@my.unt.edu" << endl;
	cout << endl;
	cout << endl;

	int choice;
	string fileName;
	Rides rides;
	Drivers drivers;
	Passengers passengers;

	//title

	cout << "------------------------------Welcome to the Mean Green EagleLift System------------------------------" << endl;
	cout << endl;

	cout << "Would you like to save your information to a new file (enter 1) or load an existing file (enter 2)? ";
	cin >> choice;

	cout << "Enter the name of the file you want to write to or read from: ";
	cin >> fileName;
	cout << endl;
	
	if (choice == 2){
		scanFile(fileName, rides, drivers, passengers);
	}


	while (choice != 0){
	//main menu titles and choices
	cout << "-------------------------------------" << endl;
	cout << "MAIN MENU:" << endl;
	cout << endl;
	cout << "View existing information - enter 1" << endl;
	cout << "Edit/Create new information - enter 2" << endl;
	cout << "Quit - enter 0" << endl;
	cout << "Your Choice: ";
	cin >> choice;

		switch(choice){

			case 1:
				//sub-menu for viewing information of the rides, passengers, and drivers
				while (choice != 12){
				cout << endl;
				cout << "----------------------------------"<< endl;
				cout << "Viewing sub-menu:" << endl;
				cout << endl;
				cout << "Print All Drivers - enter 1" << endl;
				cout << "Print All Passengers - enter 2" << endl;
				cout << "Print All Rides - enter 3" << endl;
				cout << "Print Details of Driver - enter 4" << endl;
				cout << "Print Details of Passenger - enter 5" << endl;
				cout << "Print Details of Ride - enter 6" << endl;
				cout << "Print Active Rides - enter 7" << endl;
				cout << "Print Completed Rides - enter 8" << endl;
				cout << "Print Cancelled Rides - enter 9" << endl;
				cout << "Print Driver Schedule - enter 10" << endl;
				cout << "Print Passenger Schedule - enter 11" << endl;
				cout << "Go Back - enter 12" << endl;
				cout << "Your Choice: ";
				cin >> choice;
				cout << endl;
				//prints all drivers	
				if (choice == 1){
					drivers.printAllDriver();
				}
				//prints all passengers
				else if (choice == 2){
					passengers.printAllPassengers();
				}
				//prints all rides
				else if (choice == 3){
					rides.printAllRides();
				}
				//prints details of one driver
				else if (choice == 4){
					cout << "Enter Driver ID: ";
					int dID;
					cin >> dID;
					drivers.printDetailsOfDriver(dID);
				}
				//prints details of passengers
				else if (choice == 5){
					cout << "Enter Passenger ID: ";
					int pID;
					cin >> pID;
					passengers.printDetailsOfPassenger(pID);
				}
				//prints details of ride
				else if (choice == 6){
					cout << "Enter Ride ID: ";
					int rID;
					cin >> rID;
					rides.printDetailsOfRide(rID);
				}
				//prints active rides
				else if (choice == 7){
					rides.printActiveRides();
				}
				//prints completd rides
				else if (choice == 8){
					rides.printCompletedRides();
				}
				//prints cancelled rides
				else if (choice == 9){
					rides.printCancelledRides();
				}
				//prints driver's schedule
				else if (choice == 10){
					cout << "Enter Driver ID: ";
					int dID2;
					cin >> dID2;
					rides.printDriverSched(dID2); 
				}
				//prints passenger's schedule
				else if (choice == 11){
					cout << "Enter Passenger ID: ";
					int pID2;
					cin >> pID2;
					rides.printPassSched(pID2);
				}
				}
				break;
			case 2:
				//sub-menu for editing and creating
				while(choice != 12){
				cout << endl;
				cout << "-------------------------------------" << endl;
				cout << "Editing and creating sub-menu:" << endl;
				cout << endl;
				cout << "Add a Driver - enter 1" << endl;
				cout << "Add a Passenger - enter 2" << endl;
				cout << "Add a Ride - enter 3" << endl;
				cout << "Edit Details of a Driver - enter 4" << endl;
				cout << "Edit Details of a Passenger - enter 5" << endl;
				cout << "Edit Details of a Ride - enter 6" << endl;
				cout << "Delete a Driver - enter 7" << endl;
				cout << "Delete a Passenger - enter 8" << endl;
				cout << "Cancel a Ride - enter 9" << endl;
				cout << "Delete Cancelled Rides - enter 10" << endl;
				cout << "Update Rides - enter 11" << endl;
				cout << "Go Back - enter 12" << endl;
				cout << "Your Choice: ";
				cin >> choice;
				cout << endl;

				//adds a driver
				if (choice == 1){
					drivers.addDriver();
				}	
				//adds a passenger
				else if (choice == 2){
					passengers.addPassenger();
				}
				//adds a ride
				else if (choice == 3){
					//objects
					Driver driver;
					Passenger passenger;
					Ride ride;
					//variables for the ride information
					float rating;
					int passID;
					int party;
					bool pets;
					string pickUp;
					string dropOff;
					//variables for finding the pickup and dropoff times
					time_t pickUpT = time(0);
					tm *timeInfo = localtime(&pickUpT);
					time_t dropOffT = time(0);
					int month;
					int day;
					int hour;
					int min;

					//ask for ride information and store it in temporary variables
					cout << "Passenger ID: ";
					cin >> passID;

					cout << "Party Size: ";
					cin >> party;

					cout << "Does the ride include pets? (enter 0 for no or 1 for yes): ";
					cin >> pets;

					cout << "Pickup location: " << endl;
					cin.ignore();
					getline(cin, pickUp);

					cout << "Pickup date (enter month/date): ";
					scanf("%d/%d", &month, &day);
					cout << "Pickup time (enter hour:minute): ";
					scanf("%d:%d", &hour, &min);

					timeInfo->tm_mon = month - 1;
					timeInfo->tm_mday = day;
					timeInfo->tm_hour = hour;
					timeInfo->tm_min = min;

					pickUpT = mktime(timeInfo);

					cout << "Length of ride in minutes: ";
					cin >> min;

					dropOffT = pickUpT + (min * 60);

					cout << "Dropoff location: " << endl;		

					cin.ignore();
					getline(cin, dropOff);

					cout << "Ride Rating (floating point variable between 1-5): ";
					cin >> rating;

					//finds the right passenger (matches the passID)
					int passIndex = passengers.findPassenger(passID);
					passenger = passengers.getPassObj(passIndex);

					int before = rides.getRideCounter();
	
					int i = 0;
					int j = 0;
					//chooses the driver for the ride
					for (i = 0; i < drivers.getCounter(); i++){
						driver = drivers.getDriverObj(i);
						//checks if the driver is available, has a big enough capacity, and has a high enough rating
						if (driver.getAvailable() == 1 && driver.getVehicleCap() >= party && driver.getDriverRating() >= passenger.getPassRating())
						{
							//checks if the driver has the correct handicap capacity
							if (driver.getHandicapCap() == passenger.getHandicapped() || driver.getHandicapCap() == true)
							{
								//checks if the driver has the correct pet capacity
								if (driver.getPetAllowed() == passenger.getHasPets() || driver.getPetAllowed() == true)
								{
									for (j = 0; j < rides.getRideCounter(); j++)
									{
										ride = rides.getRide(j);

										//checks if the driver has other rides at the within the same time period
										if (ride.getDriverID() == driver.getDriverID())
										{
											if (pickUpT < ride.getPickTime() && pickUpT < ride.getDropTime())
											{
												if (dropOffT < ride.getPickTime() && dropOffT < ride.getDropTime()){
													Ride aride;
													aride.setRideID(rides.getNewID());
													cout << "Ride ID: " << aride.getRideID() << endl;
													aride.setCustRating(rating);
													aride.setPassID(passID);
													aride.setDriverID(driver.getDriverID());
													aride.setPartySize(party);
													aride.setPets(pets);
													aride.setPickUp(pickUp);
													aride.setPickTime(pickUpT);
													aride.setDropTime(dropOffT);
													aride.setDropOff(dropOff);
													aride.setRideStatus(1);
													cout << "Ride Status: Active:" << endl;
													rides.addRide(aride);
													break;
												}
											}
											else if (pickUpT > ride.getPickTime() && pickUpT > ride.getDropTime())
											{
												if (dropOffT > ride.getPickTime() && dropOffT > ride.getDropTime()){
													Ride aride;
													aride.setRideID(rides.getNewID());
													cout << "Ride ID: " << aride.getRideID() << endl;
													aride.setCustRating(rating);
													aride.setPassID(passID);
													aride.setDriverID(driver.getDriverID());
													aride.setPartySize(party);
													aride.setPets(pets);
													aride.setPickUp(pickUp);
													aride.setPickTime(pickUpT);
													aride.setDropTime(dropOffT);
													aride.setDropOff(dropOff);
													aride.setRideStatus(1);
													cout << "Ride Status: Active" << endl;
													rides.addRide(aride);
													break;
												}
											}
										}
									}
									//so only one ride is made at a time
									if (before < rides.getRideCounter()){
										break;
									}
									//if this is the driver's first ride:
									if (j == rides.getRideCounter()){
										Ride aride;
										aride.setRideID(rides.getNewID());
										cout << "Ride ID: " << aride.getRideID() << endl;
										aride.setCustRating(rating);
										aride.setPassID(passID);
										aride.setDriverID(driver.getDriverID());
										aride.setPartySize(party);
										aride.setPets(pets);
										aride.setPickUp(pickUp);
										aride.setPickTime(pickUpT);
										aride.setDropTime(dropOffT);
										aride.setDropOff(dropOff);
										aride.setRideStatus(1);
										cout << "Ride Status: Active" << endl;
										rides.addRide(aride);
										break;
									}	
								}
							}
						}	
						//if there are no drivers that match the passenger's requirements
						if (i == drivers.getCounter()){
						cout << "There are no drivers available that match your requirements" << endl;
						}
					}
					//cout << "Ride status: Active" << endl;
				}
				//edits driver information
				else if (choice == 4){
					cout << "Enter Driver ID: ";
					int dID4;
					cin >> dID4;
					drivers.editDriver(dID4);
				}
				//edits passenger information
				else if (choice == 5){
					cout << "Enter Passenger ID: ";
					int pID4;
					cin >> pID4;
					passengers.editPassenger(pID4);
				}
				//edits ride information
				else if (choice == 6){
					cout << "Enter Ride ID: ";
					int rID4;
					cin >> rID4;
					rides.editRide(rID4);
				}
				//deletes a driver
				else if (choice == 7){
					cout << "Enter Driver ID: ";
					int dID5;
					cin >> dID5;
					drivers.deleteDriver(dID5);
				}
				//deletes a passenger
				else if (choice == 8){
					cout << "Enter Passenger ID: ";
					int pID5;
					cin >> pID5;
					passengers.deletePassenger(pID5);
				}
				//cancels a ride
				else if (choice == 9){
					cout << "Enter Ride ID: ";
					int rID5;
					cin >> rID5;
					rides.cancelRide(rID5);
				}
				//deletes cancelled rides
				else if (choice == 10){
					rides.deleteCancelledRides();
				}
				//updates rides
				else if (choice == 11){
					rides.updateRides();
				}
				}
				break;	
		}
	}
	//loads file when user quits program
	loadFile(fileName, rides, drivers, passengers);
	return 0;
}

//reads in the file and stores the data in the respective vectors
void scanFile(string fileName, Rides &rides, Drivers &drivers, Passengers &passengers){
	ifstream in;		//ifstream variable for reading the file
	in.open(fileName);	//opens file
	char objName;		//variable for identifying if the object is a driver (d), passenger (p), or ride (r)

	//checks if the file opened correctly
	if(!in.is_open()){
		cout << "OPENING FILE ERROR";
		exit(EXIT_FAILURE);
	}

	in >> objName;
	while(objName != 'm'){
		if (objName == 'd'){
			//reads in the information from the file
			int ID;
			in >> ID;

			string fName;
			in >> fName;

			string lName;
			in >> lName;

			int cap;
			in >> cap;

			bool handi;
			in >> handi;

			int type;
			in >> type;

			float rating;
			in >> rating;

			bool ava;
			in >> ava;

			bool pets;
			in >> pets;

			in.ignore();
			string notes;
			getline(in, notes);

			//puts information in a driver object that is added to the vector
			Driver driver;
			driver.setDriverID(ID);
			driver.setFirstName(fName);
			driver.setLastName(lName);
			driver.setVehicleCap(cap);
			driver.setHandicapCap(handi);
			driver.setVehicleType(type);
			driver.setDriverRating(rating);
			driver.setDriverAva(ava);
			driver.setPetAllowed(pets);
			driver.setNotes(notes);

			drivers.newDriver(driver);
			in >> objName;			//gets the next identifying letter
		}
		if (objName == 'p'){
			//reads in the information from the file
			int ID;
			in >> ID;

			string fName;
			in >> fName;

			string lName;
			in >> lName;

			int pay;
			in >> pay;

			bool handi;
			in >> handi;

			float rating;
			in >> rating;

			bool pets;
			in >> pets;

			//puts information in a passenger object that is added to the vector
			Passenger passenger;
			passenger.setPassID(ID);
			passenger.setFirstName(fName);
			passenger.setLastName(lName);
			passenger.setPayPref(pay);
			passenger.setHandicapped(handi);
			passenger.setPassRating(rating);
			passenger.setHasPets(pets);

			passengers.savePass(passenger);
			in >> objName;			//gets the next identifying letter		
		}
		if (objName == 'r'){
			//reads in the information from the file
			int rID;
			in >> rID;

			int pID;
			in >> pID;

			int dID;
			in >> dID;

			string pickL;
			in.ignore();
			getline(in, pickL);

			string dropL;
			getline(in, dropL);

			time_t pickT;
			in >> pickT;

			time_t dropT;
			in >> dropT;

			int party;
			in >> party;

			bool pets;
			in >> pets;

			int rStatus;
			in >> rStatus;

			float custRating;
			in >> custRating;
			
			//puts information in a passenger object that is added to the vector
			Ride ride;
			ride.setRideID(rID);
			ride.setPassID(pID);
			ride.setDriverID(dID);
			ride.setPickUp(pickL);
			ride.setDropOff(dropL);
			ride.setPickTime(pickT);
			ride.setDropTime(dropT);
			ride.setPartySize(party);
			ride.setPets(pets);
			ride.setRideStatus(rStatus);
			ride.setCustRating(custRating);

			rides.addRide(ride);
			in >> objName;			//gets the next identifying letter
		}
	}
	in.close();					//closes the file
}

//loads the file with the information of each element of the vectors
void loadFile(string fileName, Rides &rides, Drivers &drivers, Passengers &passengers){
	ofstream out;			//ofstream variable for writing to a file
	out.open(fileName);
	//checks that the file opened correctly
	if (!out.is_open()){
		cout << "OPENING FILE ERROR" << endl;
		exit(EXIT_FAILURE);
	}

	//prints the information for the driver vector
	for (int di = 0; di < drivers.getCounter(); di++){
		Driver d = drivers.getDriverObj(di);

		out << 'd' << endl;			//used so drivers can be identified
		out << d.getDriverID() << endl;
		out << d.getFirstName() << endl;
		out << d.getLastName() << endl;
		out << d.getVehicleCap() << endl;
		out << d.getHandicapCap() << endl;
		out << d.getVehicleType() << endl;
		out << d.getDriverRating() << endl;
		out << d.getAvailable() << endl;
		out << d.getPetAllowed() << endl;
		out << d.getNotes() << endl;
	}

	//prints the information for the passengers in the passenger vector
	for (int pi = 0; pi < passengers.getPCounter(); pi++){
		Passenger p = passengers.getPassObj(pi);

		out << 'p' << endl;			//used so passengers can be identified
		out << p.getPassID() << endl;
		out << p.getFirstName() << endl;
		out << p.getLastName() << endl;
		out << p.getPayPref() << endl;
		out << p.getHandicapped() << endl;
		out << p.getPassRating() << endl;
		out << p.getHasPets() << endl;
	}

	//prints the information for the rides in the ride vector
	for (int ri = 0; ri < rides.getRideCounter(); ri++){
		Ride r = rides.getRide(ri);

		out << 'r' << endl;			//used so rides can be identified
		out << r.getRideID() << endl;
		out << r.getPassID() << endl;
		out << r.getDriverID() << endl;
		out << r.getPickUp() << endl;
		out << r.getDropOff() << endl;
		out << r.getPickTime() << endl;
		out << r.getDropTime() << endl;
		out << r.getPartySize() << endl;
		out << r.getPets() << endl;
		out << r.getRideStatus() << endl;
		out << r.getCustRating() << endl;
	}
	out << 'm' << endl; 				//used to identify the end of the file
	out.close();					//closes the file
}
