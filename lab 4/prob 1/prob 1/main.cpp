#include <iostream>
#include "Sort.h"
using namespace std;

int main()
{	
	Sort s1(8, 10, 100);
	s1.BubbleSort(true);
	s1.Print();
	Sort s2({ 1, 5, 2, 8, 3 });
	s2.InsertSort(false);
	s2.Print();
	int v[] = { 10, 20, 5, 4 };
	Sort s3(v, 4);
	s3.QuickSort(true);
	s3.Print();
	Sort s4(4, 99, 11, 55, 22);
	s4.Print();
	Sort s5("7,1,9,4,2");
	s5.QuickSort(true);
	s5.Print();
	return 0;
}