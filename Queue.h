#pragma once

#include "QueueNode.h"

#include <ctime>

class Queue {

public:
	// constructor
	Queue();
	Queue(bool isExpress = false);
	
	// destructor
	~Queue();

	// getters
	QueueNode* getpHead() const;
	QueueNode* getpTail() const;
	int getTotalCustomers() const;
	int getTotalTime() const;
	bool getIsExpress() const;

	// setters
	bool setpHead(QueueNode *newpHead);
	bool setpTail(QueueNode *newpTail);
	
	// increment or decrement of time, inserted as a negative if decrementing or a positive if incrementing
	bool adjustTotalTime(int incOrDecTime);

	int genServiceTime();

	// queue operations
	bool enqueue(Data newData);
	bool dequeue();

	// print
	void printQueue();

private:
	
	// private queue operations
	bool enqueue(QueueNode *mpTail, Data newData);
	bool dequeue(QueueNode *mpHead);

	// private print
	void printQueue(QueueNode *mpHead);
	
	// data members
	QueueNode *mpHead;
	QueueNode *mpTail;
	int totalCustomers;
	int totalTime;
	bool isExpress;
};