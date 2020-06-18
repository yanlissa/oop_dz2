#include "Hex.h"

std::ostream& operator <<(std::ostream& out, const Hex& h)
{
	if (h.m_sign) {
		out << '-';
	}

	for (int i = h.m_order - 1; i >= 0; i--) {
		out << std::hex << (unsigned int) h.m_data[i];
	}
	return out;
}
