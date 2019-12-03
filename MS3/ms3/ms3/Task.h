#ifndef TASK_H
#define TASK_H

#include <deque>
#include <ostream>
#include <string>
// Name: Jinpyo Ju
// Seneca Student ID: 134444181	
// Seneca email: jju3@myseneca.ca
// Date of completion: 12/01/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Item.h"
#include "CustomerOrder.h"

class Task : public Item
{
	std::deque<CustomerOrder> m_orders;
	Task* m_pNextTask;

public:
	Task(const std::string&);
	Task(Task&) = delete;
	Task(Task&&) = delete;
	Task& operator=(Task&) = delete;
	Task& operator=(Task&&) = delete;

	void runProcess(std::ostream&);
	bool moveTask();
	void setNextTask(Task&);
	bool getCompleted(CustomerOrder&);
	void validate(std::ostream&) const;
	Task& operator+=(CustomerOrder&&);
};

#endif // TASK_H