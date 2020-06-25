#include "TurboString.h"

std::ostream& TurboString::print(std::ostream& out) const
{
	if (!m_l) {
		return out;
	}

	return out << m_data;
}
