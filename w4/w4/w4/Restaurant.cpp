// Name:Jinpyo Ju
// Seneca Student ID: 134444181
// Seneca email: jju3@myseneca.ca
// Date of completion: Oct 8,2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include"Restaurant.h"
#include"Reservation.h"
#include<iostream>
#include<utility>

namespace sdds
{

	Restaurant::Restaurant() :m_reservation{ nullptr }, m_num{ 0 }
	{}


	Restaurant::Restaurant(Reservation* reservations[], size_t cnt)
	{
		if (cnt > 0 && reservations != nullptr)
		{
			this->m_num = 0;
			this->m_reservation = new Reservation[cnt];

			for (size_t i = 0; i < cnt; i++)
			{
				this->m_reservation[i] = *reservations[i];

			}
			m_num = cnt;
		}
	}

	Restaurant::Restaurant(const Restaurant& other)
	{
		*this = other;
	}
	Restaurant& Restaurant::operator=(const Restaurant& other)
	{
		if (this != &other)
		{
			delete[]m_reservation;
			this->m_num = other.m_num;
			
			m_reservation = new Reservation[m_num];
			for (size_t i = 0; i < m_num; i++)
			{
				m_reservation[i] = other.m_reservation[i];
			}
		}
		return *this;
	}
	Restaurant::Restaurant(Restaurant&& other)
	{
		*this = std::move(other);
	}
	Restaurant&& Restaurant::operator=(Restaurant&& other)
	{
		if (this != &other)
		{
			this->m_reservation = other.m_reservation;
			this->m_num = other.m_num;
			other.m_reservation = nullptr;
			other.m_num = 0;
		}
		return std::move(*this);

	}
	Restaurant::~Restaurant()
	{
		//delete[] m_reservation;
		//m_reservation = nullptr;
	}

	size_t Restaurant::size() const
	{
		return m_num;
	}


	std::ostream& operator<<(std::ostream& os, const Restaurant& obj)
	{

		os << "-----------------------" << std::endl;
		os << "Fancy Resturnat" << std::endl;
		os << "-----------------------" << std::endl;
		if (obj.m_num == 0 && obj.m_reservation == nullptr)
		{

			os << "This object is empty!" << std::endl;
		}
		else
		{
			
			for (size_t i = 0; i < obj.m_num; i++)
			{

				os << obj.m_reservation[i];
			}
		}

		os << "-----------------------" << std::endl;
		return os;
	}

}
