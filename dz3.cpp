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
	return 0;
}
