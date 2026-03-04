#include "Student.h"
#include <iostream>

void Student::setName(const char* nume)
{
	this->nume = nullptr;
}

const char* Student::getName()
{
	return this->nume;
}

bool Student::setNotaMate(float nota)
{
	if (nota >= 1.0f && nota <= 10.0f)
	{
		notaMate = nota;
		return true;
	}
	return false;
}

float Student::getNotaMate() 
{
	return notaMate;
}

bool Student::setNotaEngleza(float nota)
{
	if (nota >= 1.0f && nota <= 10.0f)
	{
		notaEngleza = nota;
		return true;
	}
	return false;
}

float Student::getNotaEngleza()
{
	return notaEngleza;
}

bool Student::setNotaIstorie(float nota)
{
	if (nota >= 1.0f && nota <= 10.0f)
	{
		notaIstorie = nota;
		return true;
	}
	return false;
}

float Student::getNotaIstorie()
{
	return notaIstorie;
}

float Student::getAverage()
{
	return (notaEngleza + notaIstorie + notaMate) / 3.0f;
}
