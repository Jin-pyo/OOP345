#ifndef RESTAURANT_H
#define RESTAURANT_H

#include<iostream>

//#include"Reservation.h"
namespace sdds
{
	class Reservation;

	class Restaurant
	{
		Reservation* m_reservation = nullptr;
		size_t m_num = 0;
	public:
		Restaurant();
		Restaurant(Reservation* reservation[], size_t cnt);
		Restaurant(const Restaurant&);
		Restaurant& operator=(const Restaurant&);
		Restaurant(Restaurant&&);
		Restaurant&& operator=(Restaurant&&);
		~Restaurant();


		size_t size() const;

		friend std::ostream& operator<<(std::ostream& os, const Restaurant& obj);
	};
}


#endif // !RESTAURANT_H



