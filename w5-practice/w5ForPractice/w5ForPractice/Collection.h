#ifndef COLLECTION_H
#define COLLECTION_H

#include<iostream>

namespace sdds
{

	template<typename T>
	class Collection
	{
		std::string m_name;
		T* m_items;
		size_t m_cnt;

		void (*onItemAdded)(const Collection<T>&, const T&)
	public:
		Collection(std::string name);
		~Collection() { delete[]m_items; }
		const std::string& name() const { return m_name; }
		size_t size() const { return m_cnt; }
		void setObserver(void(*observer)(const Collection<T>&, const T&))
		{
			onItemAdded = observer;
		}
		Collection<T>& operator+=(const T& item)
		{
			bool check = true;
			for (size_t i = 0; i < m_cnt; i++){
				if (item[i].title() == m_itesm[i].title()){
					check = false;
				}
			}
			if (check)
			{
				T* tmp = new T[m_cnt + 1];
				for (size_t i = 0; i < m_cnt; i++)
				{
					tmp[i] = m_items[i];
				}
				tmp[m_cnt + 1] = item;

				delete[]items;
				m_items = tmp;
				this->m_cnt++;
			}
				return *this;
		}
		T& operator[](size_t idx)const
		{
			if (idx > m_cnt)
			{
				std::string error;
				error += "Bad index [";
				error += std::to_string(idx);
				error += "]. Collection has [";
				error += std::to_string(m_cnt);
				error += "] items.";
				throw std::out_of_range(error);
			}
			return this->m_items[idx];
		}


		T* operator[](std::string title) const
		{
			for (size_t i = 0; i < m_cnt; i++)
			{
				if (m_items[i].title()==title)
				{
					return &this->m_items;
				}
			}
			return nullptr;
			
		}

		friend std::ostream& operator<<(std::ostream& os, const Collection& obj)
		{
			for (auto i = 0; i < obj.size(); i++)
			{
				os << obj.m_items[i];
			}
			return os;
		}

	};


}
#endif