#pragma once

class Student
{
private:
	int varsta = 0;
	char* nume;
	int nota_oop;
	int nota_matematica;
	int nota_logica;

	void SetVarsta(int varsta);
public:
	int GetVarsta();

	Student();
	Student(const char* nume);

	int GetNotaMatematica();
	int GetNotaMatematica(bool a_trecut);
	int GetNotaMatematica(char* nume);

	friend int SetNotaMatematica(Student& stud);
};

// default is private
