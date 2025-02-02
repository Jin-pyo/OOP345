// Name: Jinpyo Ju
// Seneca Student ID: 134444181
// Seneca email: jju3@myseneca.ca	
// Date of completion: 11/26/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

// Workshop 9 - Multi-Threading
// SecureData.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include "SecureData.h"

using namespace std;

namespace w9 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs)
	{
		ofs = pOfs;

		// open text file
		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		// copy from file into memory
		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key)
	{

		char* tmp1;
		char* tmp2;

		tmp1 = new char[nbytes / 2];
		tmp2 = new char[nbytes / 2];

		for (int i = 0; i < nbytes / 2; i++)
		{
			tmp1[i] = this->text[i];
		}
		for (int i = 0; i < nbytes / 2; i++)
		{
			tmp2[i] = this->text[(nbytes / 2) + i];
		}
		// TODO (at-home): rewrite this function to use at least two threads
		//         to encrypt/decrypt the text.
		//converter(text, key, nbytes, Cryptor());
		thread h1(std::bind(converter, tmp1, key, nbytes / 2, Cryptor()));
		thread h2(std::bind(converter, tmp2, key, nbytes - (nbytes / 2), Cryptor()));

		h1.join();
		h2.join();



		encoded = !encoded;
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{
			// TODO: open a binary file for writing
			std::ofstream f(file, std::ios::out | std::ios::binary);
			if (!f) { throw std::string("\n*** Can't open file in backup ***\n"); }

			// TODO: write data into the binary file
			//         and close the file
			f.write(this->text, this->nbytes);
			f.close();
		}
	}

	void SecureData::restore(const char* file, char key) {
		// TODO: open binary file for reading
		std::ifstream f(file, std::ios::in | std::ios::binary);
		if (!f) { throw std::string("\n*** Can't open file in restore ***\n"); };

		// TODO: - allocate memory here for the file content
		f.seekg(0, std::ios::end);
		this->nbytes = (int)f.tellg();
		delete[]text;
		text = new char[this->nbytes + 1];

		// TODO: - read the content of the binary file
		f.seekg(0, std::ios::beg);
		f.read(text, this->nbytes);
		f.close();

		*ofs << "\n" << nbytes << " bytes copied from binary file "
			<< file << " into memory.\n";

		encoded = true;

		// decode using key
		code(key);

		*ofs << "Data decrypted in memory\n\n";
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}