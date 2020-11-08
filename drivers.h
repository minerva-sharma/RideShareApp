#ifndef DRIVERS_H
#define DRIVERS_H

#include "driver.h"
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>

using namespace std;

class Drivers{
	public:
		void addDriver();			//adds driver to vector
		void editDriver(int ID);		//edits driver
		void deleteDriver(int ID);		//deletes driver
		int findDriver(int ID);			//returns driver index
		Driver getDriverObj(int i);		//returns driver object
		void printAllDriver();			//prints all drivers
		void printDetailsOfDriver(int ID);	//prints details of one driver
		void newDriver(Driver d);		//adds driver to vector
		int getCounter();			//returns the size of the vector
	private:
		vector<Driver> drivers;			//vector of drivers
		int counter = 0;			//counts # of drivers
};

#endif
