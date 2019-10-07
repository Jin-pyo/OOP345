#ifndef DD_H
#define DD_H

#include<cstring>
//#include"process.h"
#include<iostream>

namespace sdds
{

	template <typename T = int, int size = 50>
	class Array {
		T a[size];
		unsigned n;
		T dummy;
		static unsigned count;
	public:
		Array() : n{ 0 }, dummy{ 0 } { ++count; }
		T& operator[](unsigned i) {
			return i < 50u ? a[i] : dummy;
		}
		static unsigned cnt() { return count; }
		~Array() { --count; }
	};

	template <typename T = int, int size = 50>
	unsigned Array<T>::count = 0u;
}

#endif