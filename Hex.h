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

	Hex(const Hex& h)
	{
		m_data = new unsigned char [HEX_SIZE]();
		memcpy(m_data, h.m_data, HEX_SIZE);
		m_sign = h.m_sign;
		m_order = h.m_order;
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

	Hex& operator+=(const Hex& h)
	{
		if (m_sign != h.m_sign) {
		return *this;
		}
		return add(h);
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
			m_data[m_order] = c;
			m_order++;
		}

		return *this;
	}

	friend std::ostream& operator <<(std::ostream& out, const Hex& h);
};
