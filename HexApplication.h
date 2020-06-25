#pragma once

#include "Hex.h"

class HexApplication {
private:
	Hex* m_a;
	Hex* m_b;
private:
        void PrintMenu();
        void TestAll();
	void InputA();
	void InputB();
public:
        HexApplication()
		:m_a{nullptr}, m_b{nullptr}
        {};

	~HexApplication()
	{
		delete m_a;
		delete m_b;
	}

        void Run();
};

