#include <iostream>

#include "TurboStringApplication.h"

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

void TurboStringApplication::InputA()
{
	string s;
	cout << "Введите строку: ";
	cin >> s;
	cout << s << endl;
	delete m_a;
	m_a = new TurboString(s.c_str());
}

void TurboStringApplication::InputB()
{
	string s;
	cout << "Введите строку: ";
	cin >> s;
	cout << s << endl;
	delete m_b;
	m_b = new TurboString(s.c_str());
}

void TurboStringApplication::ShowALength()
{
	cout << '"' << *m_a << '"' << ".len() = " << dec << m_a->len() << endl;
}

void TurboStringApplication::PrintMenu()
{
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "TurboString" << endl;
	cout << "A: ";
	if (m_a) {
		cout << *m_a;
	} else {
		cout << "не определена";
	}
        cout << endl;
	cout << "B: ";
	if (m_b) {
		cout << *m_b;
	} else {
		cout << "не определена";
	}
        cout << endl;
        cout << "0: Выход" << endl;
        cout << "1: Отладочный вывод" << endl;
        cout << "2: Ввод А" << endl;
        cout << "3: Ввод B" << endl;
        cout << "4: Показать длину А" << endl;
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
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			continue;
		}
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
		case 3:
			InputB();
			break;
		case 4:
			ShowALength();
			break;
		default:
			break;
		}
	}
}
