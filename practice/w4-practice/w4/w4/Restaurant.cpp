#include "Restaurant.h"
#include<utility>
#include<iostream>
namespace sdds
{
	Restaurant::Restaurant(){
		
	}

	Restaurant::Restaurant(Reservation* reservations[], size_t cnt)
	{
		
		
			this->m_cnt = cnt;
			this->m_reservations = new Reservation[m_cnt];
			for (auto i = 0u; i < m_cnt; i++)
			{
				m_reservations[i] = *reservations[i];
			}
		
	}

	Restaurant::Restaurant(const Restaurant& obj)
	{
		*this = obj;
	}
	Restaurant& Restaurant::operator=(const Restaurant& obj)
	{
		if (this != &obj)
		{
			m_cnt = obj.m_cnt;
			delete[]m_reservations;
			m_reservations = new Reservation[m_cnt];
			for (auto i = 0u; i < m_cnt; i++)
			{
				m_reservations[i] = obj.m_reservations[i];
			}
		}
		return *this;
	}
	Restaurant::Restaurant(Restaurant&& obj)
	{
		*this = std::move(obj);
	}
	Restaurant& Restaurant::operator=(Restaurant&& obj)
	{
		if (this != &obj)
		{
			m_cnt = obj.m_cnt;
			m_reservations = obj.m_reservations;
			obj.m_cnt = 0;
			obj.m_reservations = nullptr;
		}
		return *this;
	}
	size_t Restaurant::size() const
	{
		return this->m_cnt;
	}

	std::ostream& operator<<(std::ostream& os, const Restaurant res)
	{
		os << "--------------------------\n";
		os << "Fancy Restaurant\n";
		os << "--------------------------\n";
		if (res.m_cnt == 0)
			os << "The object is empty!\n";
		for (auto i = 0u; i < res.m_cnt; ++i)
			os << res.m_reservations[i];
		os << "--------------------------\n";
		return os;
	}
}