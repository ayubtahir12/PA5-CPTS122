#include "Data.h"

Data::Data(int newCustomerNumber, int newServiceTime, int newTotalTime)
{
	this->setCustomerNumber(newCustomerNumber);
	this->setServiceTime(newServiceTime);
	this->setTotalTime(newTotalTime);
}

Data::~Data()
{

}

int Data::getCustomerNumber() const
{
	return this->mCustomerNumber;
}

int Data::getServiceTime() const
{
	return this->mServiceTime;
}

int Data::getTotalTime() const
{
	return this->mTotalTime;
}

bool Data::setCustomerNumber(int newCustomerNumber)
{
	bool success = false;
	
	if (newCustomerNumber > 0)
	{
		this->mCustomerNumber = newCustomerNumber;
		success = true;
	}

	return success;
}

bool Data::setServiceTime(int newServiceTime)
{
	bool success = false;

	if (newServiceTime > 0)
	{
		this->mServiceTime = newServiceTime;
		success = true;
	}

	return success;
}

bool Data::setTotalTime(int newTotalTime)
{
	bool success = false;

	if (newTotalTime > 0)
	{
		this->mTotalTime = newTotalTime;
		success = true;
	}

	return success;
}