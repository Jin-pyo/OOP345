#pragma once

#include"Reservation.h"

namespace sdds
{

	class Restaurant
	{
		Reservation* m_reservations=nullptr;
		size_t m_cnt =0;

	public:
		Restaurant();
		Restaurant(Reservation* reservations[], size_t cnt);
		size_t size() const;
		Restaurant(const Restaurant&);
		Restaurant& operator=(const Restaurant&);
		Restaurant(Restaurant&&);
		Restaurant& operator=(Restaurant&&);

		friend std::ostream& operator<<(std::ostream&, const Restaurant);

	};

}
