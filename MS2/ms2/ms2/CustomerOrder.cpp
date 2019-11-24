#include "CustomerOrder.h"
#include"Utilities.h"
#include<iostream>
#include<algorithm>
#include<string>

size_t CustomerOrder::m_widthField = 1;

CustomerOrder::CustomerOrder()
{
	this->m_cntItem = 0u;
	this->m_name = "";
	this->m_product="";
}

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
		
		for (auto i = 0u; i < this->m_cntItem-1; i++)
		{
			start = end + 1;
			end = record.find(delimiter, start);
			m_lstItem[i] = new ItemInfo(m_utility.extractToken(record,start,more));
		}
		start = end + 1;
		m_lstItem[m_cntItem-1] = new ItemInfo(record.substr(start));
	}

	if (m_widthField < m_utility.getFieldWidth())
	{
		m_widthField = m_utility.getFieldWidth();
	}
	

}
CustomerOrder::CustomerOrder(CustomerOrder&& obj) noexcept
{
	*this = std::move(obj);
}
CustomerOrder& CustomerOrder::operator=(CustomerOrder&& obj)
{
	if (this != &obj) {
		m_lstItem = obj.m_lstItem;
		m_name = obj.m_name;
		m_product = obj.m_product;
		m_cntItem = obj.m_cntItem;
		obj.m_lstItem = nullptr;
		obj.m_name = "";
		obj.m_cntItem = 0;
		obj.m_product = "";
	}
	return *this;
}
CustomerOrder::~CustomerOrder()
{
	delete[] m_lstItem;
	m_lstItem = nullptr;
}
 
bool CustomerOrder::getItemFillState(std::string check) const
{
	for (auto i = 0u; i < this->m_cntItem; i++)
	{
		if (m_lstItem[i]->m_itemName == check)
		{
			if(m_lstItem[i]->m_fillState==false)
			return false;
		}
	}
	return true;
}
bool CustomerOrder::getOrderFillState() const
{
	for (auto i = 0u; i < m_cntItem; i++)
	{
		if (m_lstItem[i]->m_fillState == false)
			return false;
	}
	return true;
}
void CustomerOrder::fillItem(Item& item, std::ostream& os)
{
	for (auto i = 0u; i < m_cntItem; i++) 
	{
		if (item.getName() == m_lstItem[i]->m_itemName) 
		{
			if (item.getQuantity() > 0)
			{
				item.updateQuantity();
				m_lstItem[i]->m_serialNumber = item.getSerialNumber();
				m_lstItem[i]->m_fillState = true;
				os << "Filled " << m_name << ", " 
					<< m_product << "[" << item.getName() << "]" << std::endl;
			}
			else
			{
				os << "Unable to fill " << m_name << ", "
					<< m_product << "[" << item.getName() << "]" << std::endl;
			}
		}
	}
}
void CustomerOrder::display(std::ostream& os) const
{
	os << m_name << " - " << m_product << std::endl;

	for (size_t i = 0; i < m_cntItem; i++) 
	{
		os << "[" << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
		os << std::setw(m_widthField) << std::setfill(' ') << m_lstItem[i]->m_itemName << " - ";
		if (m_lstItem[i]->m_fillState) os << "FILLED";
		else os << "MISSING";

		os << std::endl;
	}
}