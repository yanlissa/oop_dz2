#include "TurboString.h"

std::ostream& operator <<(std::ostream& out, const TurboString& s)
{
	if (!(s.m_l)) {
		return out;
	}

	return out << s.m_s;
}
