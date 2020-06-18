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
private:
	bool absolute_lt(const Hex& h) const;
	bool absolute_gt(const Hex& h) const;
	bool absolute_e(const Hex& h) const;
	Hex& add(const Hex& h);
	Hex& subtract(const Hex& h);
	Hex& multiply_digit(unsigned char d);
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

	bool operator<(const Hex& h) const
	{
		if (m_sign > h.m_sign) {
			return true;
		}
		if (m_sign < h.m_sign) {
			return false;
		}
		if (m_sign) {
			return absolute_gt(h);
		}
		return absolute_lt(h);
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

	Hex& operator/=(const Hex& h)
	{
		if (h.m_order == 1 && h.m_data[0] == 0) {
			throw std::overflow_error("Hex::/=");
		}
		Hex q("0");
		if (absolute_lt(h)) {
			return *this = q;
		}
		m_sign ^= h.m_sign;

		Hex one("1");
		for (int i = m_order - h.m_order; i >= 0; i--) {
			Hex tmp(h , i);
			Hex q1(one, i);
			while (!tmp.absolute_gt(*this)) {
				subtract(tmp);
				q += q1;
			}
		}
		return *this = q;
	}

	Hex operator+(const Hex& b)
	{
		Hex c(*this);
		c += b;
		return c;
	}

	Hex operator-(const Hex& b)
	{
		Hex c(*this);
		c -= b;
		return c;
	}

	Hex operator*(const Hex& b)
	{
		Hex c(*this);
		c *= b;
		return c;
	}

	Hex operator/(const Hex& b)
	{
		Hex c(*this);
		c /= b;
		return c;
	}

	friend std::ostream& operator <<(std::ostream& out, const Hex& h);
};
