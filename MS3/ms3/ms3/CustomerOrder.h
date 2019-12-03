// Name: Jinpyo Ju
// Seneca Student ID: 134444181	
// Seneca email: jju3@myseneca.ca
// Date of completion: 11/17/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H

#include <utility>
#include "Item.h"

struct ItemInfo
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_fillState = false;

	ItemInfo(std::string src) : m_itemName(std::move(src)) {};
};

class CustomerOrder
{
	std::string m_name;
	std::string m_product;
	unsigned int m_cntItem{};
	ItemInfo** m_listItem{};
	static size_t m_widthField;

public:
	CustomerOrder();
	explicit CustomerOrder(const std::string&);
	CustomerOrder(CustomerOrder&);
	CustomerOrder& operator=(CustomerOrder&) = delete;
	CustomerOrder(CustomerOrder&&) noexcept; // move constructor
	CustomerOrder& operator=(CustomerOrder&&) noexcept; // move assignment operator
	~CustomerOrder();

	bool getItemFillState(const std::string&) const;
	bool getOrderFillState() const;
	void fillItem(Item&, std::ostream&) const; // I think this member function should be const
	void display(std::ostream&) const;
};

#endif //CUSTOMERORDER_H
