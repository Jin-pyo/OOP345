// Name: Jinpyo Ju
// Seneca Student ID: 134444181	
// Seneca email: jju3@myseneca.ca
// Date of completion: 12/01/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include<iostream>
#include<fstream>
#include "LineManager.h"
#include"Utilities.h"


LineManager::LineManager(const std::string& str, std::vector<Task*>& tasks, std::vector<CustomerOrder>& customer_order)
{
	m_cntCustomerOrder = 0;
	Utilities util;
	size_t next_pos = 0;
	auto more = true;
	auto check = true;
	std::string record;
	std::string next;
	std::ifstream file(str);

	while (!file.eof())
	{
		std::getline(file, record);
		auto tmp = util.extractToken(record, next_pos, more);

		if (more)
			next = util.extractToken(record, next_pos, more);

		for (size_t i = 0; i < tasks.size(); ++i)
		{
			if (tasks[i]->getName() == tmp)
			{
				if (check)
				{
					first = i;
					check = false;
				}
				if (next.empty())
				{
					last = i;
				}
				else
				{
					for (size_t j = 0; j < tasks.size(); ++j)
						if (tasks[j]->getName() == next)
						{
							tasks[i]->setNextTask(*tasks[j]);
							break;
						}
				}
				break;
			}
		}

		next_pos = 0;
		more = true;
		tmp.clear();
		next.clear();
	}

	AssemblyLine = tasks;

	for (auto& co : customer_order)
	{
		ToBeFilled.push_back(std::move(co));
	}

	customer_order.erase(customer_order.begin(), customer_order.end());
	
}
bool LineManager::run(std::ostream& os)
{
	auto check = true;

	if (!ToBeFilled.empty())
	{
		*AssemblyLine[this->first] += std::move(ToBeFilled.front());
		ToBeFilled.pop_front();
	}

	for (auto& i : AssemblyLine)
		i->runProcess(os);

	CustomerOrder tmp;
	if (AssemblyLine[this->last]->getCompleted(tmp))
	{
		Completed.push_back(std::move(tmp));

	}

	for (auto& i : AssemblyLine)
	{
		if (i->moveTask())
			check = false;
	}

	return check;

	

}
void LineManager::displayCompleted(std::ostream& os) const
{
	if (!Completed.empty())
		for (const auto& i : Completed)
			i.display(os);
}
void LineManager::validateTasks() const
{
	if (!AssemblyLine.empty())
		for (auto i : AssemblyLine)
			i->validate(std::cout);
}