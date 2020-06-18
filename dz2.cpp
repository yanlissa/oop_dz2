#include "Hex.h"

using namespace std;

int main()
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

	return 0;
}
