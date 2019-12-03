#pragma once
#include<iostream>
#include<iomanip>
namespace sdds
{
	template<typename L, typename V>
	class LVPair
	{
		L m_label;
		V m_value;
	public:
		LVPair():m_label(),m_value(){}
		
		LVPair(const L& aa, const V& bb)
		{
			m_label = aa;
			m_value = bb;
		}
		const L& key() const
		{
			return m_label;
		}
		const V& value() const
		{
			return m_value;
		}
		virtual void display(std::ostream& os)const
		{
			os << m_label << " : " << m_value << std::endl;
		}
	};


	template<typename L,typename V>
	class SummableLVPair : public LVPair
	{
		static V initial;
		static size_t fieldWidth;
	public:
		static const V& getInitialValue()
		{
			return initial;
		}
		SummableLVPair();
		
	};

	template<typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const sdds::LVPair<L, V>& pair)
	{
		pair.display(os);
		return os;
	}

}
