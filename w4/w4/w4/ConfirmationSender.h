// Name:Jinpyo Ju
// Seneca Student ID: 134444181
// Seneca email: jju3@myseneca.ca
// Date of completion: Oct 8,2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

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


