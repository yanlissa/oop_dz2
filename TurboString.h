#pragma once
#include <cstring>
#include <iostream>

#include "Array.h"

class TurboString: public Array
{
public:
	TurboString(const char* s = nullptr)
		:Array{}
	{
		m_l = 0;
		m_data[0] = 0;
		if (!s) {
			return;
		}
		std::size_t l = strlen(s);
		if (l > 255) {
			throw std::overflow_error("TurboString::TurboString");
		}
		m_l = l;
		memmove(m_data, s, l + 1);
	}

	TurboString(const TurboString& t)
	{
		m_l = t.m_l;
		memmove(m_data, t.m_data, m_l + 1);
	}

	std::size_t len()
	{
		return m_l;
	}

	std::size_t str(const TurboString& s)
	{
		const char* find = reinterpret_cast<const char*>(s.m_data);
		const char* str = reinterpret_cast<const char*>(m_data);
		const char *p = strstr(str, find);
		if (!p) {
			return 0;
		}
		return p - str + 1;
	}

	TurboString& del(std::size_t pos, std::size_t len)
	{
		if ((pos - 1) >= m_l || (pos + len - 1) >= m_l) {
			throw std::out_of_range("TurboString::del");
		}
		memmove(m_data + pos - 1, m_data + pos + len - 1, m_l - len - pos + 2);
		m_l -= len;
		return *this;
	}

	TurboString& insert(std::size_t pos, const TurboString& t)
	{
		char tmp[256];
		if ((pos - 1) > m_l || (m_l + t.m_l) > 255) {
			throw std::overflow_error("TurboString::insert");
		}
		memmove(tmp, t.m_data, t.m_l + 1);
		memmove(m_data + pos + t.m_l - 1, m_data + pos - 1, t.m_l);
		memmove(m_data + pos - 1, tmp, t.m_l);
		m_l += t.m_l;
		return *this;
	}

	TurboString& append(const TurboString& t)
	{
		return insert(m_l + 1, t);
	}

	Array& operator+=(const Array& other) override
	{
		const TurboString* t = dynamic_cast<const TurboString*>(&other);
		if (!t) {
			throw std::logic_error("TurboString::+=");
		}
		return append(*t);
	}

	std::ostream& print(std::ostream& out) const override;
};
