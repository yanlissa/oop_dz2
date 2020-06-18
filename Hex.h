#pragma once
#include <cstring>
#include <iostream>

#define HEX_SIZE 128

class Hex
{
private:
	unsigned char* m_data;
	unsigned int m_sign;
	unsigned int m_order;
public:
	Hex()
		:m_sign{0}, m_order{0}
	{
		m_data = new unsigned char [HEX_SIZE]();
	}

	~Hex()
	{
		delete m_data;
	}

	Hex(const char *str)
	{
		m_sign = 0;
		m_data = new unsigned char [HEX_SIZE]();
		int len = strlen(str);
		if (len > HEX_SIZE) {
			return;
		}
		unsigned char* d= new unsigned char [HEX_SIZE]();
		int j = len - 1;
		for (int i = 0; i < len; i++) {
			char c = str[j];
			if (c >= '0' && c <='9') {
				d[i] = c - '0';
			} else if (c >= 'a' && c <='f') {
				d[i] = c - 'a' + 10;
			} else if (c >= 'A' && c <='F') {
				d[i] = c - 'A' + 10;
			} else if (c == '-') {
				if (j > 0) {
					delete d;
					return;
				}
				m_sign = 1;
			} else {
				delete d;
				return;
			}
			j--;
		}
		delete m_data;
		m_order = len - m_sign;
		m_data = d;
	}

	Hex(const Hex& h, std::size_t sh = 0)
	{
		if (h.m_order + sh > HEX_SIZE) {
			throw std::overflow_error("Hex::Hex");
		}
		m_data = new unsigned char [HEX_SIZE]();
		memcpy(m_data + sh, h.m_data, HEX_SIZE - sh);
		m_sign = h.m_sign;
		m_order = h.m_order + sh;
	}

	Hex& operator=(const Hex& h)
	{
		memcpy(m_data, h.m_data, HEX_SIZE);
		m_sign = h.m_sign;
		m_order = h.m_order;
		return *this;
	}

	Hex& operator=(Hex&& h)
	{
		delete m_data;
		m_data = h.m_data;
		h.m_data = nullptr;
		m_sign = h.m_sign;
		m_order = h.m_order;
		return *this;
	}

	bool operator<(const Hex& h)
	{
		if (m_order < h.m_order) {
			return true;
		}

		if (m_order > h.m_order) {
			return false;
		}

		for (int i = m_order - 1; i > 0; i--) {
			if (m_data[i] < h.m_data[i]) {
				return true;
			}
			if (m_data[i] > h.m_data[i]) {
				return false;
			}
		}
		return false;
	}

	Hex& operator+=(const Hex& h)
	{
		if (m_sign != h.m_sign) {
			return subtract(h);
		}
		return add(h);
	}

	Hex& operator-=(const Hex& h)
	{
		if (m_sign != h.m_sign) {
			return add(h);
		}
		return subtract(h);
	}

	Hex& operator*=(const Hex& h)
	{
		if (h.m_order + m_order > HEX_SIZE) {
			throw std::overflow_error("Hex::add");
		}
		m_sign ^= h.m_sign;
		Hex result("0");
		const Hex* a = this;
		const Hex* b = &h;
		if (h.m_order > m_order) {
			b = a;
			a = &h;
		}

		for (int i = 0; i < b->m_order; i++) {
			Hex tmp(*a , i);
			tmp.multiply_digit(b->m_data[i]);
			result += tmp;
		}
		return *this = result;
	}

	Hex& add(const Hex& h)
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

	Hex& subtract(const Hex& h)
	{
		int c{0};
		unsigned int new_order = 1;
		const unsigned char *a = m_data;
		const unsigned char *b = h.m_data;
		if (*this < h) {
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
			}
			if (m_data[i] > 0) {
				new_order = i + 1;
			}
		}

		m_order = new_order;

		return *this;
	}

	Hex& multiply_digit(unsigned char d)
	{
		unsigned int c{0};

		for (int i = 0; i < m_order; i++) {
			c += m_data[i] * d;
			std::cout << (int)m_data[i] << " * " << (int)d << " = " << c << "\n";
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

	friend std::ostream& operator <<(std::ostream& out, const Hex& h);
};
