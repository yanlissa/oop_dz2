#include <iostream>

#include "Application.h"

using namespace std;

void Application::PrintMenu()
{
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "0: Выход" << endl;
        cout << "1: Hex" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Выберите пункт: ";
}

void Application::Run()
{
        bool keks = true;
        int ex;
        while (keks)
	{
                PrintMenu();
                cin >> ex;
                cout << ex << endl;
                switch (ex) {
                case 0:
                        keks = false;
                        break;
                case 1:
                        m_hex_app.Run();
                        break;
                default:
                        break;
                }
        }
}
