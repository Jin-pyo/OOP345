// Workshop 3 - Templates
// 2019/01/23 - Chris Szalwinski
// 2019/09/20 - Cornel

#ifndef SDDS_LVPAIR_H
#define SDDS_LVPAIR_H

#include <iostream>

namespace sdds
{
	template <typename L, typename V>
	class LVPair
	{
		L m_label;
		V m_value;
	public:
		LVPair() : m_label(), m_value() { }
		LVPair(const L& aa, const V& bb) : m_label(aa), m_value(bb) {}
		const L& key() const
		{
			return m_label;
		}

		const V& value() const
		{
			return m_value;
		}

		virtual void display(std::ostream& os) const
		{
			os << m_label << " : " << m_value << std::endl;
		}
	};

	template <typename L, typename V>
	class SummableLVPair : public LVPair<L, V>
	{
		static V initial;
		static size_t fieldWidth;
	public:
		SummableLVPair() { }
		SummableLVPair(const L& aa, const V& bb) : LVPair<L, V>(aa, bb)
		{
			if (fieldWidth < aa.size())
				fieldWidth = aa.size();
		}
		static const V& getInitialValue()
		{
			return initial;
		}

		V sum(const L& l, const V& v) const
		{
			return l == LVPair<L, V>::key() ? v + LVPair<L, V>::value() : v;
		}
		void display(std::ostream& os) const
		{
			os << std::left << std::setw(fieldWidth);
			LVPair<L, V>::display(os);
			os << std::right;
		}
	};

	template <typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair)
	{
		pair.display(os);
		return os;
	}

	// initialize class variable
	//
	template <typename L, typename V>
	size_t SummableLVPair<L, V>::fieldWidth = 0;

	template <>
	std::string SummableLVPair<std::string, std::string>::initial = std::string("");

	template <>
	int SummableLVPair<std::string, int>::initial = 0;

	template <>
	std::string SummableLVPair<std::string, std::string>::sum(const std::string& k, const std::string& v) const
	{
		if (key() == k)
			return v == "" ? value() : v + std::string(", ") + value();
		else
			return v;
	}
}

#endif


