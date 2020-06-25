#include <iostream>

#include "TurboStringApplication.h"
#include "TurboString.h"

using namespace std;

void TurboStringApplication::TestAll()
{
	TurboString s("TurboString");
	cout << "s: \"" << s << "\"" << endl;
	cout << "s.len() = " << dec << s.len() << endl;
	TurboString t("Turbo");
	cout << '"' << t << "\" in \"" << s  << "\" at " << s.str(t) << endl;
	cout << "s without \"" << t << "\" :  " << s.del(s.str(t), t.len()) << endl;
	cout << s.insert(1 , t) << " is back" << endl;
	cout << "s with \"" << t << "\" : " << s.append(t) << endl;
}

void TurboStringApplication::PrintMenu()
{
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "TurboString" << endl;
        cout << "0: Выход" << endl;
        cout << "1: Отладочный вывод" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Выберите пункт: ";
}


void TurboStringApplication::Run()
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
			TestAll();
			break;
		default:
			break;
		}
	}
}
