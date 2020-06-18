#include "Hex.h"

bool Hex::absolute_lt(const Hex& h) const
{
	if (m_order < h.m_order) {
		return true;
	}

	if (m_order > h.m_order) {
		return false;
	}

	for (int i = m_order - 1; i >= 0; i--) {
		if (m_data[i] < h.m_data[i]) {
			return true;
		}
		if (m_data[i] > h.m_data[i]) {
			return false;
		}
	}
	return false;
}

bool Hex::absolute_gt(const Hex& h) const
{
	if (m_order > h.m_order) {
		return true;
	}

	if (m_order < h.m_order) {
		return false;
	}

	for (int i = m_order - 1; i >= 0; i--) {
		if (m_data[i] > h.m_data[i]) {
			return true;
		}
		if (m_data[i] < h.m_data[i]) {
			return false;
		}
	}
	return false;
}

bool Hex::absolute_e(const Hex& h) const
{
	if (m_order != h.m_order) {
		return false;
	}

	for (int i = m_order - 1; i > 0; i--) {
		if (m_data[i] != h.m_data[i]) {
			return false;
		}
	}
	return true;
}

Hex& Hex::add(const Hex& h)
{
	unsigned int c{0};
	if (h.m_order > m_order) {
		m_order = h.m_order;
	}

	for (int i = 0; i < m_order; i++) {
		c += m_data[i] + h.m_data[i];
		m_data[i] = c & 0xF;
		c >>= 4;
	}

	if (c) {
		if (m_order == HEX_SIZE) {
			throw std::overflow_error("Hex::add");
		}
		m_data[m_order] = c;
		m_order++;
	}

	return *this;
}

Hex& Hex::subtract(const Hex& h)
{
	int c{0};
	unsigned int new_order = 1;
	const unsigned char *a = m_data;
	const unsigned char *b = h.m_data;
	if (absolute_lt(h)) {
		m_sign = !m_sign;
		b = a;
		a = h.m_data;
	}

	for (int i = 0; i < m_order; i++) {
		c += a[i] - b[i];
		m_data[i] = c;
		if (c < 0) {
			m_data[i] += 16;
			c = -1;
		} else {
			c = 0;
		}
		if (m_data[i] > 0) {
			new_order = i + 1;
		}
	}

	m_order = new_order;

	return *this;
}

Hex& Hex::multiply_digit(unsigned char d)
{
	unsigned int c{0};

	for (int i = 0; i < m_order; i++) {
		c += m_data[i] * d;
		m_data[i] = c & 0xF;
		c >>= 4;
	}

	if (c) {
		if (m_order == HEX_SIZE) {
			throw std::overflow_error("Hex::add");
		}
		m_data[m_order] = c;
		m_order++;
	}

	return *this;
}


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
