#pragma once

#include "Data.h"

class QueueNode {

public:
	// constructor
	QueueNode(int customerNumber = 0, int serviceTime = 0, int totalTime = 0);
	QueueNode(Data newData);

	// destructor
	~QueueNode();

	// getters
	Data getData() const;
	QueueNode* getpNext() const;
	int getTotalTime() const;
	
	// setters
	void setData(Data newData);
	bool setpNext(QueueNode* newpNext);
	void adjustTotalTime(int incOrDecTime);

private:
	Data mData;
	QueueNode *mpNext;

};

void operator== (Data &lhs, Data &rhs);
