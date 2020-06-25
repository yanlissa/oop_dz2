#pragma once

#include <ostream>

#define ARRAY_SIZE 128

class Array
{
protected:
	std::size_t m_l;
	unsigned char* m_data;
public:
	Array()
		:m_l{0}
	{
		m_data = new unsigned char [ARRAY_SIZE]();
	}

	~Array()
	{
		delete m_data;
	}

	Array(const unsigned char *ustr)
	{
		const char* str = reinterpret_cast<const char*>(ustr);
		int len = strlen(str);
		if (len > ARRAY_SIZE) {
			throw std::overflow_error("Array::Array(str)");
		}
		m_l = len;
		m_data = new unsigned char [ARRAY_SIZE]();
		memcpy(m_data, str, len);
	}

	Array(const Array& a)
	{
		m_data = new unsigned char [ARRAY_SIZE]();
		memcpy(m_data, a.m_data, a.m_l);
		m_l = a.m_l;
	}

	Array& operator=(const Array& h)
	{
		memcpy(m_data, h.m_data, ARRAY_SIZE);
		m_l = h.m_l;
		return *this;
	}

	Array& operator=(Array&& h)
	{
		delete m_data;
		m_l = h.m_l;
		m_data = h.m_data;
		h.m_data = nullptr;
		h.m_l = 0;
		return *this;
	}

	unsigned char& operator[](const std::size_t i)
	{
		if (i >= m_l) {
			throw std::out_of_range("Array::[]");
		}
		return m_data[i];
	}

	const unsigned char& operator[](const std::size_t i) const
	{
		if (i >= m_l) {
			throw std::out_of_range("Array::[]");
		}
		return m_data[i];
	}

	virtual Array& operator+=(const Array& other)
	{
		if (other.m_l > m_l) {
			m_l = other.m_l;
		}
		for (std::size_t i = 0; i < other.m_l; i++) {
			m_data[i] += other.m_data[i];
		}

		return *this;
	}

	virtual std::ostream& print(std::ostream& out) const;

        friend std::ostream& operator <<(std::ostream& out, const Array& a)
        {
                return a.print(out);
        }

};
