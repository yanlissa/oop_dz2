#include <cstring>
#include "Array.h"

std::ostream& Array::print(std::ostream& out) const
{
	bool empty = true;
	out << "[";
	for (std::size_t i = 0; i < m_l; i++) {
		if (!empty) {
			out << ", ";
		}
		out << m_data[i];
	}
	return out << "]";
};

