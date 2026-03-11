#include "Math.h"
#include <iostream>
#include <cstring>
#include <cstdarg>

using namespace std;

char* strcpyy( char* a, const char* b)
{
	if (b == nullptr || a == nullptr)
		return a;
	char* c = a;
	
	while (*b != '\0')
	{
		*a = *b;
		a++;
		b++;
	}
	
	*a = '\0';
	
	return c;
}

char* strcatt(char* a, const char* b)
{
	if (b == nullptr || a == nullptr)
		return a;
	char* c = a;

	while (*a != '\0')
		a++;

	while (*b != '\0')
	{
		*a = *b;
		a++;
		b++;
	}

	*a = '\0';

	return c;
}

int Math::Add(int a, int b)
{
	return a + b;
}

int Math::Add(int a, int b, int c)
{
	return a + b + c;
}

int Math::Add(double a, double b)
{
	return a + b;
}

int Math::Add(double a, double b, double c)
{
	return a + b + c;
}

int Math::Mul(int a, int b)
{
	return a * b;
}

int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}

int Math::Mul(double a, double b)
{
	return a * b;
}

int Math::Mul(double a, double b, double c)
{
	return a * b * c;
}

int Math::Add(int count, ...)
{
	int sum = 0;
	va_list arg;
	va_start(arg, count);
	for (int i = 0; i < count; i++)
	{
		sum += va_arg(arg, int);
	}

	va_end(arg);
	return sum;
}

char* Math::Add(const char* a, const char* b)
{
	if (a == nullptr || b == nullptr) return nullptr;

	int lungime = strlen(a) + strlen(b) + 1;
	char* rez = new char[lungime];
	strcpyy(rez, a);
	strcatt(rez, b);

	return rez;
}
