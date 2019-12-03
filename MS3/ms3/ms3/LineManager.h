// Name: Jinpyo Ju
// Seneca Student ID: 134444181	
// Seneca email: jju3@myseneca.ca
// Date of completion: 12/01/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef LINE_H
#define LINE_H

#include <vector>
#include <deque>
#include <iostream>
#include "Task.h"
#include "CustomerOrder.h"

class LineManager
{
	std::vector<Task*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> Completed;
	unsigned int m_cntCustomerOrder;
	size_t first;
	size_t last;

public:
	LineManager(const std::string&, std::vector<Task*>&, std::vector<CustomerOrder>&);
	bool run(std::ostream&);
	void displayCompleted(std::ostream&) const;
	void validateTasks() const;
};


#endif // !LINE_H



