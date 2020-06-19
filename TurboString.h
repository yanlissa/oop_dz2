#pragma once
#include <cstring>
#include <ostream>

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
		memcpy(m_s, s, l + 1);
	}

	friend std::ostream& operator <<(std::ostream& out, const TurboString& s);
};
