#pragma once
#include<iostream>
#include<string>
#include"Item.h"

struct ItemInfo
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_fillState = false;

	ItemInfo(std::string src) : m_itemName(src) {};
};

class CustomerOrder
{
	std::string m_name;
	std::string m_product;
	unsigned int m_cntItem;
	ItemInfo** m_lstItem;
	static size_t m_widthField;
public:
	CustomerOrder() {};
	CustomerOrder(std::string&);
	CustomerOrder(const CustomerOrder&) { throw "Copy Not allowed"; }
	CustomerOrder& operator=(const CustomerOrder&) = delete;
	CustomerOrder(CustomerOrder&&) noexcept;
	CustomerOrder& operator=(CustomerOrder&&);
	~CustomerOrder();

	bool getItemFillState(std::string) const;
	bool getOrderFillState() const;
	void fillItem(Item& item, std::ostream&);
	void display(std::ostream&) const;



};

