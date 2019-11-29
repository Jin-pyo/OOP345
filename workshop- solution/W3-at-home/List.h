// Workshop 3 - Templates
// 2019/01/23 - Chris Szalwinski
// 2019/09/20 - Cornel

#ifndef SDDS_LIST_H
#define SDDS_LIST_H

namespace sdds
{
	template <typename T, size_t N>
	class List
	{
		T t[N];
		size_t n{ 0u };
	public:
		size_t size() const
		{
			return n;
		}
		
		const T& operator[](size_t i) const
		{
			return t[i];
		}
		
		void operator+=(const T& tt)
		{
			if (n < N)
				t[n++] = tt;
		}
	};

	template <typename L, typename V, typename T, size_t N>
	class LVList : public List<T, N>
	{
	public:
		V accumulate(const L& label) const
		{
			V sum = T::getInitialValue();
			for (size_t i = 0; i < this->size(); i++)
			{
				sum = (*this)[i].sum(label, sum);
			}
			return sum;
		}
	};
}

#endif