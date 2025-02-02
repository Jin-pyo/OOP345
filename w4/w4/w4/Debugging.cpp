// Name:Jinpyo Ju
// Seneca Student ID: 134444181
// Seneca email: jju3@myseneca.ca
// Date of completion: Oct 8,2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <utility>
#include "Restaurant.h"
#include "Restaurant.h"
#include "ConfirmationSender.h"
#include "ConfirmationSender.h"
#include "Reservation.h"
#include "Reservation.h"


int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n";

	sdds::Reservation** ppReservations = nullptr;
	size_t cnt = 0;

	// Process the file
	{
		std::ifstream file("data.txt");
		if (!file)
		{
			std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
			return 1;
		}

		std::string strReservation;
		// count how many records are in the file
		do
		{
			std::getline(file, strReservation);

			// if the previous operation failed, the "file" object is
			//   in error mode
			if (file)
			{
				// Check if this is a commented line.
				//   In the input file, commented lines start with '#'
				if (strReservation[0] != '#')
					++cnt;
			}
		} while (file);

		ppReservations = new sdds::Reservation * [cnt];
		cnt = 0;

		// read again from the file, but this time load and store data
		file.clear();
		file.seekg(std::ios::beg);
		do
		{
			std::getline(file, strReservation);

			// if the previous operation failed, the "file" object is
			//   in error mode
			if (file)
			{
				// Check if this is a commented line.
				//   In the input file, commented lines start with '#'
				if (strReservation[0] != '#')
				{
					ppReservations[cnt] = new sdds::Reservation(strReservation);
					++cnt;
				}
			}
		} while (file);
		file.close();
	}
	std::cout << "\nReservations\n--------------------------\n";
	for (auto i = 0u; i < cnt; ++i)
	{
		std::cout << *ppReservations[i];
	}
	std::cout << "--------------------------\n\n";

	{
		std::cout << "R: Testing Constuctor\n";
		std::cout << "==========================\n";
		sdds::Restaurant res1(ppReservations, cnt);
		std::cout << res1;
		std::cout << "==========================\n\n";

		std::cout << "R: Testing Copy Constuctor\n";
		std::cout << "==========================\n";
		sdds::Restaurant res2(res1);
		std::cout << res1;
		std::cout << res2;
		std::cout << "==========================\n\n";

		std::cout << "R: Testing Move Constuctor\n";
		std::cout << "==========================\n";
		sdds::Restaurant res3(std::move(res1));
		std::cout << res1;
		std::cout << res3;
		std::cout << "==========================\n\n";
	}


	// Confirmation Sender
	{
		std::cout << "CS: Testing Constuctor\n";
		std::cout << "==========================\n";
		sdds::ConfirmationSender sender1;
		std::cout << sender1;
		std::cout << "==========================\n\n";

		std::cout << "CS: Testing Operators\n";
		std::cout << "==========================\n";
		sender1 += *ppReservations[5];
		sender1 += *ppReservations[16];
		sender1 += *ppReservations[16];
		sender1 += *ppReservations[8];
		std::cout << sender1;
		sender1 -= *ppReservations[8];
		sender1 -= *ppReservations[7];
		std::cout << sender1;
		std::cout << "==========================\n\n";

		std::cout << "CS: Testing Copy Constuctor\n";
		std::cout << "==========================\n";
		sdds::ConfirmationSender sender2(sender1);
		std::cout << sender1;
		std::cout << sender2;
		std::cout << "==========================\n\n";

		std::cout << "CS: Testing Move Constuctor\n";
		std::cout << "==========================\n";
		sdds::ConfirmationSender sender3(std::move(sender1));
		std::cout << sender1;
		std::cout << sender3;
		std::cout << "==========================\n\n";

	}
	// cleanup
	for (auto i = 0u; i < cnt; ++i)
		delete ppReservations[i];
	delete[] ppReservations;

	return 0;
}