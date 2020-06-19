#pragma once
#include <cstring>
#include <iostream>

class TurboString
{
private:
	std::size_t m_l;
	char m_s[256];
public:
	TurboString(const char* s = nullptr)
	{
		m_l = 0;
		m_s[0] = 0;
		if (!s) {
			return;
		}
		std::size_t l = strlen(s);
		if (l > 255) {
			throw std::overflow_error("TurboString::TurboString");
		}
		m_l = l;
		memmove(m_s, s, l + 1);
	}

	TurboString(const TurboString& t)
	{
		m_l = t.m_l;
		memmove(m_s, t.m_s, m_l + 1);
	}

	std::size_t len()
	{
		return m_l;
	}

	std::size_t str(const TurboString& s)
	{
		const char *p = strstr(m_s, s.m_s);
		if (!p) {
			return 0;
		}
		return p - m_s + 1;
	}

	friend std::ostream& operator <<(std::ostream& out, const TurboString& s);
};
