#include "QueueNode.h"

QueueNode::QueueNode(int customerNumber, int serviceTime, int totalTime)
{
	Data newData = NULL;

	newData.setCustomerNumber(customerNumber);
	newData.setServiceTime(serviceTime);
	newData.setTotalTime(totalTime);

	this->setData(newData);
	this->setpNext(nullptr);
}

QueueNode::QueueNode(Data newData)
{
	this->setData(newData);
	this->setpNext(nullptr);
}

QueueNode::~QueueNode()
{

}

Data QueueNode::getData() const
{
	return this->mData;
}

QueueNode* QueueNode::getpNext() const
{
	return this->mpNext;
}

int QueueNode::getTotalTime() const
{
	return this->mData.getTotalTime();
}

void QueueNode::setData(Data newData)
{
	this->mData = newData;
}

bool QueueNode::setpNext(QueueNode* newpNext)
{
	bool success = false;

	this->mpNext = newpNext;

	if (this->mpNext == newpNext) success = true;

	return success;
}

void QueueNode::adjustTotalTime(int incOrDecTime)
{
	this->mData.setTotalTime(this->mData.getTotalTime() + incOrDecTime);
}

void operator== (Data &lhs, Data &rhs)
{
	bool success = false;

	if (lhs.getCustomerNumber() == rhs.getCustomerNumber())
	{
		if (lhs.getServiceTime() == rhs.getServiceTime())
		{
			if (lhs.getTotalTime() == rhs.getTotalTime()) success = true;
		}
	}

}
