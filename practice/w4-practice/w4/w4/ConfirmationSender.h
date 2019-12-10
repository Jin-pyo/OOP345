#pragma once

#include"Reservation.h"

namespace sdds
{
	class ConfirmationSender
	{
		const sdds::Reservation** m_reservations = nullptr;
		size_t m_cnt =0u;

	public:
		ConfirmationSender() {};
		ConfirmationSender(const ConfirmationSender&);
		ConfirmationSender& operator=(const ConfirmationSender&);
		ConfirmationSender(ConfirmationSender&&);
		ConfirmationSender& operator=(ConfirmationSender&&);

		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);

		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& sender);

	};
}

