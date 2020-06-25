#pragma once

#include "TurboString.h"

class TurboStringApplication {
private:
	TurboString* m_a;
	TurboString* m_b;
private:
        void PrintMenu();
        void TestAll();
	void InputA();
	void InputB();
	void ShowALength();
	void FindBinA();
	void RemoveFromA();
	void InsertBinA();
	void ConcatAandB();
public:
        TurboStringApplication()
		:m_a{nullptr}, m_b{nullptr}
        {};

        ~TurboStringApplication()
	{
		delete m_a;
		delete m_b;
	}

        void Run();
};
