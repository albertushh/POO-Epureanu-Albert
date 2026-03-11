#include <iostream>
#include "Math.h"

using namespace std;

Math a;

int main()
{
	cout << a.Add(1, 2) << endl;
	cout << a.Add(1, 2, 3) << endl;
	cout << a.Add(1.2, 2.3) << endl;
	cout << a.Add(1.2, 1.3, 1.4) << endl;
	cout << a.Mul(1, 2) << endl;
	cout << a.Mul(1, 2, 3) << endl;
	cout << a.Mul(1.2, 2.3) << endl;
	cout << a.Mul(1.2, 3.4, 2.3) << endl;
	cout << a.Add(5, 2, 3, 12, 13, 123) << endl;
	cout << a.Add("baros", "cicoan") << endl;

	return 0;
}