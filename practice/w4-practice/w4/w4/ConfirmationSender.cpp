#include "ConfirmationSender.h"
#include"Reservation.h"
#include<iostream>
#include<utility>
namespace sdds
{
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& obj)
	{
		*this = obj;
	}
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& obj)
	{
		if (this != &obj)
		{
			this->m_cnt = obj.m_cnt;
			delete[] m_reservations;

			m_reservations = new const Reservation *[m_cnt];

			for (size_t i = 0; i < m_cnt ; i++)
			{
				this->m_reservations[i] = obj.m_reservations[i];
			}
		}
		return *this;
	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& obj)
	{
		*this = std::move(obj);
	}
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& obj)
	{
		if (this != &obj)
		{
			this->m_cnt = obj.m_cnt;
			delete[]m_reservations;

			this->m_reservations = obj.m_reservations;
			obj.m_reservations = nullptr;
			obj.m_cnt = 0;
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		bool check = false;
		for (size_t i = 0; i < this->m_cnt; i++)
		{
			if (this->m_reservations[i] == &res)
				check = true;
		}

		if (check == false)
		{
			const sdds::Reservation** tmp = nullptr;
			tmp = new const Reservation * [m_cnt + 1];
			for (size_t i = 0; i < m_cnt; i++)
				tmp[i] = this->m_reservations[i];
			tmp[m_cnt] = &res;
			m_cnt++;
			delete[]m_reservations;
			m_reservations = tmp;
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		for (size_t i = 0; i < m_cnt; i++)
		{
			if (m_reservations[i] == &res)
			{
				m_reservations[i] = nullptr;
				break;
			}
		}
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& sender)
	{
		os << "--------------------------\n";
		os << "Confirmations to Send\n";
		os << "--------------------------\n";
		if (sender.m_cnt == 0)
			os << "The object is empty!\n";
		for (auto i = 0u; i < sender.m_cnt; ++i)
			if (sender.m_reservations[i] != nullptr)
				os << *(sender.m_reservations[i]);
		os << "--------------------------\n";
		return os;
	}

}