#ifndef CONFIRM_H
#define CONFIRM_H


#include"Reservation.h"
#include"Restaurant.h"
#include<iostream>

namespace sdds
{

	class Reservation;

	class ConfirmationSender
	{
		const sdds::Reservation** m_address;
		size_t m_num;

	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender&);
		ConfirmationSender& operator=(const ConfirmationSender&);
		ConfirmationSender(ConfirmationSender&&);
		ConfirmationSender&& operator=(ConfirmationSender&&);
		~ConfirmationSender();


		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);

		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& obj);
	};

}

#endif // !CONFIRM_H


