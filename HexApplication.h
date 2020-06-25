#pragma once

#include "Hex.h"

class HexApplication {
private:
	Hex* m_a;
	Hex* m_b;
	Hex* m_c;
private:
        void PrintMenu();
        void TestAll();
	void InputA();
	void InputB();
	void AddAtoB();
	void SubtractBfromA();
	void MultiplyAbyB();
	void DivideAbyB();
public:
        HexApplication()
		:m_a{nullptr}, m_b{nullptr}, m_c{nullptr}
        {};

	~HexApplication()
	{
		delete m_a;
		delete m_b;
		delete m_c;
	}

        void Run();
};

