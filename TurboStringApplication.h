#pragma once

#include "TurboString.h"

class TurboStringApplication {
private:
	TurboString* m_a;
private:
        void PrintMenu();
        void TestAll();
	void InputA();
public:
        TurboStringApplication()
		:m_a{nullptr}
        {};

        ~TurboStringApplication()
	{
		delete m_a;
	}

        void Run();
};
