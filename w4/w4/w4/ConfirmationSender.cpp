
#include<iostream>
#include<utility>
#include"ConfirmationSender.h"
#include"Reservation.h"

namespace sdds
{

	ConfirmationSender::ConfirmationSender()
	{
		m_address = new const Reservation * [20];
		m_num = 0;
	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& other)
	{
		*this = other;
	}
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& other)
	{
		if (this != &other)
		{

			m_num = other.m_num;
			m_address = other.m_address;

		}
		return *this;
	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& other)
	{
		*this = std::move(other);
	}
	ConfirmationSender&& ConfirmationSender::operator=(ConfirmationSender&& other)
	{
		if (this != &other)
		{
			m_address = other.m_address;
			m_num = other.m_num;

			other.m_address = { nullptr };
			other.m_num = { 0 };
		}
		return std::move(*this);
	}
	ConfirmationSender::~ConfirmationSender()
	{
		//delete[] m_address;
		//m_address =  nullptr;
	}


	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		bool check = true;
		for (size_t i = 0; i < m_num; i++)
		{
			if (m_address[i] == &res)
			{
				check = false;
			}

		}

		if (check)
		{
			m_address[m_num++] = &res;

		}

		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		bool found = false;
		size_t i;
		for (i = 0; i < m_num; i++) {
			if (m_address[i] == &res)
			{
				found = true;
			}
			if (found)
			{
				m_address[i] = m_address[i + 1];
				m_address[m_num - 1] = nullptr;
				m_num--;
			}
		}

		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& obj)
	{
		if (obj.m_num == 0)
		{
			os << "This object is empty!" << std::endl;
		}
		else
		{
			os << obj.m_num << std::endl;
			os << "Fancy Resturnat" << std::endl;
			os << "-----------------------" << std::endl;
			for (size_t i = 0; i < obj.m_num; i++)
			{

				os << *obj.m_address[i];
			}
		}
		return os;
	}
}