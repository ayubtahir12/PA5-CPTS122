#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Data {

public:
	// constructor
	Data(int newCustomerNumber = 0, int newServiceTime = 0, int newTotalTime = 0);
	
	// destructor
	~Data();

	// getters

	int getCustomerNumber() const;
	int getServiceTime() const;
	int getTotalTime() const;

	// setters

	bool setCustomerNumber(int newCustomerNumber);
	bool setServiceTime(int newServiceTime);
	bool setTotalTime(int newTotalTime);

private:
	int mCustomerNumber;
	int mServiceTime;
	int mTotalTime;

};
