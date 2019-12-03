// Name: Jinpyo Ju
// Seneca Student ID: 134444181	
// Seneca email: jju3@myseneca.ca
// Date of completion: 12/01/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Task.h"

Task::Task(const std::string& line):Item(line)
{
	this->m_pNextTask = nullptr;
}
void Task::runProcess(std::ostream& os)
{
	if (!m_orders.empty() && !m_orders.front().getOrderFillState())
	{
		while (!m_orders.front().getItemFillState(getName()))
		{
			m_orders.front().fillItem(*this, os);
		}
	}

}
bool Task::moveTask()
{
	if (m_orders.empty())
	{
		return false;
	}

	else
	{
		if (m_pNextTask && m_orders.front().getItemFillState(getName()))
		{
			*this->m_pNextTask += std::move(m_orders.front());
			m_orders.pop_front();
		}
	}
	return true;
}
void Task::setNextTask(Task& task)
{
	this->m_pNextTask = &task;
}
bool Task::getCompleted(CustomerOrder& custOr)
{
	if (m_orders.front().getOrderFillState() && !m_orders.empty())
	{
		custOr = std::move(this->m_orders.front());
		this->m_orders.pop_front();
		return true;
	}
	return false;
}
void Task::validate(std::ostream& os) const
{
	os << this->getName() << "--> " << (this->m_pNextTask ? m_pNextTask->getName() : "END OF LINE") << std::endl;
}
Task& Task::operator+=(CustomerOrder&& custOr)
{
	m_orders.push_back(std::move(custOr));
	return *this;
}