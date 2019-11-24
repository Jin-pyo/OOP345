#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include "CustomerOrder.h"

size_t CustomerOrder::m_widthField = 1;

CustomerOrder::CustomerOrder() {
}

CustomerOrder::CustomerOrder(std::string& record) {
	Utilities m_utility;
	bool more = false;
	char d = m_utility.getDelimiter();
	size_t start = 0;
	size_t end = record.find(d);
	m_name = record.substr(start, end);

	start = end + 1;
	end = record.find(d, start);
	m_product = m_utility.extractToken(record, start, more);

	m_cntItem = std::count(record.begin(), record.end(), m_utility.getDelimiter()) - 1;
	if (m_cntItem > 0) {
		m_lstItem = new ItemInfo*[m_cntItem];
		for (size_t i = 0;i < m_cntItem;i++) {
			start = end + 1;
			if (record.find(d, end+1) != std::string::npos)
				end = record.find(d, start);
			else 
				end = record.length();
			m_lstItem[i] = new ItemInfo(m_utility.extractToken(record, start, more)); // ERROR
		}
	}

	if (m_widthField < m_utility.getFieldWidth())
		m_widthField = m_utility.getFieldWidth();
}

CustomerOrder::CustomerOrder(CustomerOrder&& obj) noexcept {
	*this = std::move(obj);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& obj) {
	if (this != &obj) {
		delete[] m_lstItem;
		m_lstItem = obj.m_lstItem;
		m_name = obj.m_name;
		m_product = obj.m_product;
		m_cntItem = obj.m_cntItem;
		obj.m_lstItem = nullptr;
		//obj.m_product = '\0';
		//obj.m_product = '\0';
		//obj.m_cntItem = 0;
	}
	return *this;
}

bool CustomerOrder::getItemFillState(std::string str) const {
	for (size_t i=0;i < m_cntItem;i++) 
		if (m_lstItem[i]->m_itemName == str) {
			if (m_lstItem[i]->m_fillState == false) {
				return false;
			}
		}
	return true;
}

bool CustomerOrder::getOrderFillState() const {
	for (size_t i = 0; i < m_cntItem; i++) 
			if (m_lstItem[i]->m_fillState == false)
				return false;
	return true;
}

// this is not right
void CustomerOrder::fillItem(Item& item, std::ostream& os) {
	for (size_t i = 0;i < m_cntItem;i++) {
		if (item.getName() == m_lstItem[i]->m_itemName) {
			if (item.getQuantity() == 0) {
				os << "Unable to fill " << m_name << ", " << m_product << "[" << item.getName() << "]" << std::endl;
			}
			else
				item.updateQuantity();
				m_lstItem[i]->m_serialNumber = item.getSerialNumber();
				m_lstItem[i]->m_fillState = true;
				os << "Filled " << m_name << ", " << m_product << "[" << item.getName() << "]" << std::endl;
		}
	}
}

/*
void fillItem(Item& item, std::ostream&) – fills the item in the current order that corresponds to the item passed into the function 
(the parameter item represents what is available in the inventory).
if item cannot be found in the current order, this function does nothing
if item is found, and the inventory contains at least one element, then this function substracts 1 from the inventory and updates 
ItemInfo::m_serialNumber and ItemInfo::m_fillState. Also it prints the message Filled NAME, PRODUCT[ITEM_NAME].
if item is found, and the inventory is empty, then this function prints the message Unable to fill NAME, PRODUCT[ITEM_NAME]. 
all messages printed should be terminated by an endline 
*/

void CustomerOrder::display(std::ostream& os) const {
	os << m_name << " - " << m_product << std::endl;
	for (size_t i = 0;i < m_cntItem;i++) {
		os << "[" << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
		os << std::setw(m_widthField) << std::setfill(' ') << m_lstItem[i]->m_itemName << " - ";
		if (m_lstItem[i]->m_fillState == true) {
			os << "FILLED";
		}
		else {
			os << "MISSING";
		}
		os << std::endl;
	}
}