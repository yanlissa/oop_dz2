#include <iostream>
#include "TurboString.h"

using namespace std;

int main()
{
	TurboString s("TurboString");
	cout << s << endl;
	cout << '"' << s << '"' << ".len() = " << s.len() << endl;
	return 0;
}
