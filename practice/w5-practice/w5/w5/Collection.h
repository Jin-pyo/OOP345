#pragma once
#include<iostream>
#include<string>


namespace sdds
{
	template<typename T>
	class Collection
	{
		std::string m_name;
		T* m_items = nullptr;
		size_t m_cnt = 0;

		void (*onItemAdded)(const Collection<T>&, const T&) = nullptr;

	public:
		Collection(std::string name) :m_name(name) {}
		Collection(Collection&) = delete;
		~Collection() {
			delete[] m_items;
			m_items = nullptr;
		}
		const std::string& name() const { return m_name; };
		size_t size() const;
		void setObserver(void (*observer)(const Collection<T>&, const T&))
		{
			this->onItemAdded = observer;
		}
		Collection<T>& operator+=(const T& item)
		{
			for (size_t i = 0; i < m_cnt; i++)
			{
				if (m_items[i].title() == item.title())
				{
					return *this;
				}
			}

			T* tmp = new T[m_cnt + 1];
			for (auto i = 0; i < m_cnt; i++)
				tmp[i] = m_items[i];
			tmp[m_cnt] = item;

			delete[]m_items;
			m_items = tmp;
			m_cnt++;
		}


	};
}