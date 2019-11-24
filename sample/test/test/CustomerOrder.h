#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H
#include <string>
#include "Utilities.h"
#include "Item.h"

struct ItemInfo {
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_fillState = false;

	ItemInfo(std::string src) : m_itemName(src) {};
};

class CustomerOrder {
	std::string m_name;
	std::string m_product;
	size_t m_cntItem = 0;
	ItemInfo** m_lstItem = nullptr;
	static size_t m_widthField;
public:
	CustomerOrder();
	CustomerOrder(std::string&);
	CustomerOrder(const CustomerOrder&) { throw "Error"; };
	CustomerOrder& operator=(const CustomerOrder&) = delete;
	CustomerOrder(CustomerOrder&&) noexcept;
	CustomerOrder& operator=(CustomerOrder&&);
	~CustomerOrder() {
		delete[] m_lstItem;
		m_lstItem = nullptr;
	};
	bool getItemFillState(std::string) const;
	bool getOrderFillState() const;
	void fillItem(Item&, std::ostream&);
	void display(std::ostream&) const;
};

#endif
