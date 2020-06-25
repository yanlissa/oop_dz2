#pragma once

#include "HexApplication.h"

class Application {
private:
        HexApplication m_hex_app;
private:
        void PrintMenu();
        void RunHexApplication();
public:
        Application()
                :m_hex_app{}
        {};

        void Run();
};

