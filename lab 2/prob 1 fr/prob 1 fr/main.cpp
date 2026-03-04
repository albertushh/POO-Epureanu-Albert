#include <iostream>
#include "NumberList.h"

using namespace std;

NumberList n;

int main()
{
	n.Init();
	n.Add(12);
	n.Add(1434);
	n.Add(124);
	n.Add(134141);
	n.Print();
	n.Sort();
	n.Print();
}