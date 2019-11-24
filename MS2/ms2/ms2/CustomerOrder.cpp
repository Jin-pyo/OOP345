#include "CustomerOrder.h"
#include"Utilities.h"
#include<iostream>
#include<algorithm>


CustomerOrder::CustomerOrder(std::string& record)
{
	Utilities m_utility;
	char delimiter = m_utility.getDelimiter();
	bool more = false;
	size_t start = 0;
	size_t end = record.find(delimiter);
	this->m_name = record.substr(start, end);

	start = end + 1;
	end = record.find(delimiter, start);
	this->m_product = m_utility.extractToken(record, start, more);

	this->m_cntItem = std::count(record.begin(), record.end(), m_utility.getDelimiter()) - 1;
	if (m_cntItem > 0)
	{
		this->m_lstItem = new ItemInfo * [m_cntItem];

		for (auto i = 0u; i < this->m_cntItem; i++)
		{
			m_lstItem[i] = new ItemInfo("A");

		}
	}
	

}
CustomerOrder::CustomerOrder(CustomerOrder&&) noexcept
{

}
CustomerOrder& CustomerOrder::operator=(CustomerOrder&&)
{

}
CustomerOrder::~CustomerOrder()
{

}

bool CustomerOrder::getItemFillState(std::string) const
{

}
bool CustomerOrder::getOrderFillState() const
{

}
void CustomerOrder::fillItem(Item& item, std::ostream&)
{

}
void CustomerOrder::display(std::ostream&) const
{

}