#include <iostream>
#include "TurboString.h"

using namespace std;

int main()
{
	TurboString s("TurboString");
	cout << s << endl;
	cout << '"' << s << '"' << ".len() = " << s.len() << endl;
	TurboString t("Turbo");
	cout << '"' << t << "\" in \"" << s  << "\" at " << s.str(t) << endl;
	cout << s.del(s.str(t), t.len()) << " w/out " << t << endl;
	cout << s.insert(1 , t) << " is back" << endl;
	return 0;
}
