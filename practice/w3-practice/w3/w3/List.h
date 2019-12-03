#pragma once

namespace sdds
{
	template<typename T,size_t N>
	class List {
		T t[N];
		size_t n{ 0u };
	public:
		size_t size() const
		{
			return this->n;
		}
		const T& operator[](size_t i) const
		{
			if (0 <= i)
			{
				return this->t[i];
			}
		}
		void operator+=(const T& tt)
		{
			if (n<N)
			{
				t[n] = tt;
			}
			n++;
		}
	};


}

