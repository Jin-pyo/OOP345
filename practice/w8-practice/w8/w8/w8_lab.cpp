
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Element.h"
#include "List.h"
#include "Utilities.h"

const int FWC = 5;
const int FWD = 12;
const int FWP = 8;

using namespace sdds;
using namespace std;

size_t Product::idGenerator = 0;
bool Product::Trace = true;

int main(int argc, char** argv)
{
	

	
	try {
		sdds::List<sdds::Description> desc("Descriptions.dat");
		sdds::List<sdds::Price> priceBad("BadPrices.dat");
		sdds::List<sdds::Price> priceGood("Prices.dat");

		cout << setw(FWC) << "Code" << setw(FWD) << "Description" << endl;
		cout << desc << endl;

		cout << "********************************************" << endl
			<< "* Good Prices" << endl
			<< "********************************************" << endl;
		cout << setw(FWC) << "Code" << setw(FWP) << "Price" << endl;
		cout << priceGood << endl;

		cout << "********************************************" << endl
			<< "* Bad Prices" << endl
			<< "********************************************" << endl;
		cout << setw(FWC) << "Code" << setw(FWP) << "Price" << endl;
		cout << priceBad << endl;

		Product::Trace = true;
		cout << "********************************************" << endl
			<< "* Merging bad prices using Raw Pointers" << endl
			<< "********************************************" << endl;
		try {
			List<Product> priceList = mergeRaw(desc, priceBad);
		}
		catch (const string & msg) {
			cout << "ERROR: " << msg << std::endl;
			cout << "NOTE: An exception occurred while creating the list of products!" << endl
				<< "      You should notice that not all objects are deleted." << endl;
		}

		cout << endl;
		cout << "********************************************" << endl
			<< "* Merging bad prices using Smart Pointers" << endl
			<< "********************************************" << endl;
		try {
			List<Product> priceList = mergeSmart(desc, priceBad);
		}
		catch (const string & msg) {
			cout << "ERROR: " << msg << std::endl;
			cout << "NOTE: An exception occurred while creating the list of products!" << endl
				<< "      You should notice that ALL objects are deleted." << endl;
		}

		Product::Trace = false;
		cout << endl << endl;
		// no exceptions should be generated from the code below.
		cout << "********************************************" << endl
			<< "* Merging good prices using Raw Pointers" << endl
			<< "********************************************" << endl;
		{
			List<Product> priceList = mergeRaw(desc, priceGood);
			cout << setw(FWD) << "Description" << setw(FWP) << "Price" << endl;
			cout << priceList << endl;
		}

		cout << "********************************************" << endl
			<< "* Merging good prices using Smart Pointers" << endl
			<< "********************************************" << endl;
		{
			List<Product> priceList = mergeSmart(desc, priceGood);
			cout << setw(FWD) << "Description" << setw(FWP) << "Price" << endl;
			cout << priceList << endl;
		}
	}
	catch (...) {
		cout << "ERROR: Unknown error!";
	}
}