#include "Restaurant.h"
#include<utility>
#include<iostream>
namespace sdds
{
	Restaurant::Restaurant(){
		this->m_reservations = nullptr;
		this->m_cnt = 0;
	}

	Restaurant::Restaurant(Reservation* reservations[], size_t cnt)
	{
		if (cnt > 0)
		{
			m_cnt = cnt;
			this->m_reservations = new Reservation[m_cnt];

			for (size_t i = 0; i < m_cnt; i++)
			{
				m_reservations[i] = *reservations[i];
			}
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
			this->m_cnt = obj.m_cnt;
			delete[] this->m_reservations;

			this->m_reservations = new Reservation[m_cnt];

			for (size_t i = 0; i < m_cnt; i++)
			{
				this->m_reservations[i] = obj.m_reservations[i];
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
			this->m_cnt = obj.m_cnt;
			delete[]m_reservations;
			this->m_reservations = obj.m_reservations;

			obj.m_cnt = 0;
			obj.m_reservations = nullptr;
		}
		return *this;
	}
	size_t Restaurant::size() const
	{
		return this->m_cnt;
	}

	std::ostream& operator<<(std::ostream& os, const Restaurant obj)
	{
		os << "--------------------------" << std::endl;
		os << "Fancy Restaurant" << std::endl;
		os << "--------------------------" << std::endl;

		if (obj.m_cnt > 0)
		{
			for (size_t i = 0; i < obj.m_cnt; i++)
				os << obj.m_reservations[i];
		}
		else
		{
			os << "The object is empty!" << std::endl;
		}
		os << "--------------------------" << std::endl;

		return os;
	}
}