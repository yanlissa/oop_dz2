#pragma once

#include "HexApplication.h"
#include "TurboStringApplication.h"

class Application {
private:
        HexApplication m_hex_app;
        TurboStringApplication m_turbo_app;
private:
        void PrintMenu();
public:
        Application()
                :m_hex_app{}, m_turbo_app{}
        {};

        void Run();
};

