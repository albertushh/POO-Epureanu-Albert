#include "student.h"
#include "abc.h"
int Student::GetVarsta()
{
	return this->varsta;
}

void Student::SetVarsta(int varsta)
{
	this->varsta = varsta;
}

Student::Student()
{
	this->varsta = 18;
	this->nota_logica = 4;
	this->nota_matematica = 4;
	this->nota_oop = 8;
	this->nume = nullptr;
}

Student::Student(const char* nume) : Student()
{
	this->nume = new char[100];
	my_strcpy(nume, this->nume);
}
int Student::GetNotaMatematica()
{	
	return this->nota_matematica;
}

int Student::GetNotaMatematica(bool a_trecut)
{
	if (nota_matematica > 5) return true;
	else return false;
}

int Student::GetNotaMatematica(char* nume)
{
	if(my_strcmp(this->nume))
}

int SetNotaMatematica(Student& stud)
{
	stud.nota_matematica = 0;
}