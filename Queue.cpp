#include "Queue.h"

Queue::Queue()
{
	this->setpHead(nullptr);
	this->setpTail(nullptr);
	this->totalCustomers = 0;
	this->totalTime = 0;
	this->isExpress = false;
}

Queue::Queue(bool isExpress)
{
	this->setpHead(nullptr);
	this->setpTail(nullptr);
	this->totalCustomers = 0;
	this->totalTime = 0;
	this->isExpress = isExpress;
}

Queue::~Queue()
{

}

QueueNode* Queue::getpHead() const
{
	return this->mpHead;
}

QueueNode* Queue::getpTail() const
{
	return this->mpTail;
}

int Queue::getTotalCustomers() const
{
	return this->totalCustomers;
}

int Queue::getTotalTime() const
{
	return this->totalTime;
}

bool Queue::getIsExpress() const
{
	return this->isExpress;
}

bool Queue::setpHead(QueueNode *newpHead)
{
	bool success = false;
	
	this->mpHead = newpHead;
	if (this->mpHead == newpHead) success = true;

	return success;
}

bool Queue::setpTail(QueueNode *newpTail)
{
	bool success = false;

	this->mpTail = newpTail;
	if (this->mpTail == newpTail) success = true;

	return success;
}

bool Queue::adjustTotalTime(int incOrDecTime)
{
	bool success = false;
	
	this->mpTail->adjustTotalTime(incOrDecTime);
	this->totalTime = this->mpTail->getTotalTime();
	success = true;

	return success;
}

int Queue::genServiceTime()
{
	int servTime;
	
	if (this->getIsExpress())
	{
		servTime = rand() % 5 + 1;
	}
	else
	{
		servTime = rand() % 6 + 3;
	}

	return servTime;
}

bool Queue::enqueue(Data newData)
{
	bool success = false;

	success = this->enqueue(this->mpTail, newData);

	this->totalCustomers++;

	return success;
}

bool Queue::dequeue()
{
	bool success = false;
	
	success = this->dequeue(this->mpHead);
	this->totalCustomers--;


	return success;
}

void Queue::printQueue()
{
	printQueue(this->mpHead);
}

bool Queue::enqueue(QueueNode *mpTail, Data newData)
{
	bool success = false;
	QueueNode *pCur = new QueueNode(newData);

	if (this->getpHead() == nullptr && this->getpTail() == nullptr)
	{
		this->setpHead(pCur);
		this->setpTail(pCur);
		success = true;
	}
	else
	{
		this->getpTail()->setpNext(pCur);
		this->setpTail(pCur);
		success = true;
	}
	
	return success;
}

bool Queue::dequeue(QueueNode *mpHead)
{
	bool success = false;

	// if there is one or zero nodes in the queue
	if (this->getpHead() == this->getpTail())
	{
		delete this->getpHead();
		delete this->getpTail();
		success = true;
	}

	// theres more than one node
	else
	{
		QueueNode *pCur = this->getpHead();
		this->setpHead(this->getpHead()->getpNext());
		delete pCur;
		success = true;
	}

	return success;
}


void Queue::printQueue(QueueNode *mpHead)
{
	QueueNode *pCur = this->getpHead();

	while (pCur != nullptr)
	{
		cout << "Customer " << pCur->getData().getCustomerNumber() << "\nService Time: " << pCur->getData().getServiceTime() << "\nTotal Time: " <<
			pCur->getData().getTotalTime() << "\n\n";

		pCur = pCur->getpNext();
	}

}