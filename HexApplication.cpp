#include <iostream>

#include "HexApplication.h"

using namespace std;

void HexApplication::TestAll()
{
	Hex h1("1");
	Hex hn1("-1");
	Hex h100("100");
	Hex ha00("a00");
	cout << "1 ... " << h1 << endl;
	cout << "-1 ... " << hn1 << endl;
	cout << "100 ... " << h100 << endl;
	cout << "a00 ... " << ha00 << endl;

	Hex h("8");
	h += h;
	cout << "8 + 8 = " << h << endl;

	h -= h;
	cout << "10 - 10 = " << h << endl;

	h = Hex("185");
	Hex hx("96");
	h -= hx;
	cout << "185 - 96 = " << h << endl;

	h = Hex("fffffffffffffffffffffffffffffffffffffffff");
	h += h1;
	cout << "fffffffffffffffffffffffffffffffffffffffff +1 = " << h << endl;

	h = Hex("1");
	h += hn1;
	cout << "1 + (-1) = " << h << endl;

	h = Hex("185");
	hx -= h;
	cout << "96 - 185 = " << hx << endl;

	h = Hex("4");
	h *= h;
	cout << "4 * 4 = " << h << endl;

	h = Hex("64");
	hx = Hex("3e8");
	h *= hx;
	cout << "64 * 3e8 = " << h << endl;

	h = Hex("3e");
	hx = Hex("a");
	h -= hx;
	cout << "3e - a = " << h << endl;

	h = Hex("64");
	hx = Hex("a");
	h /= hx;
	cout << "64 / a = " << h << endl;

	h = Hex("186a0");
	hx = Hex("19");
	h /= hx;
	cout << "186a0 / 19 = " << h << endl;

	h = Hex("100000000");
	hx = Hex("19");
	cout << "100000000 - 19 = " << h - hx << endl;

	cout << "2 * 2 = " << Hex("2") * Hex("2") << endl;
}

void HexApplication::InputA()
{
	string s;
	cout << "Введите шестнадцатеричное число: ";
	cin >> s;
	cout << s << endl;
	delete m_a;
	m_a = new Hex(s.c_str());
}

void HexApplication::PrintMenu()
{
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Hex" << endl;
	cout << "A: ";
	if (m_a) {
		cout << *m_a;
	} else {
		cout << "не определено";
	}
        cout << endl;
        cout << "0: Выход" << endl;
        cout << "1: Отладочный вывод" << endl;
        cout << "2: Ввести А" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Выберите пункт: ";
}


void HexApplication::Run()
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
		case 2:
			InputA();
			break;
		default:
			break;
		}
	}
}
