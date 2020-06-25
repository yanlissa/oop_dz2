#pragma once

#include "Hex.h"

class HexApplication {
private:
	Hex* m_a;
private:
        void PrintMenu();
        void TestAll();
	void InputA();
public:
        HexApplication()
		:m_a{nullptr}
        {};

	~HexApplication()
	{
		delete m_a;
	}

        void Run();
};

