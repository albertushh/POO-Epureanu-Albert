#pragma once

class Student
{
private:
	char* nume;
	float notaMate;
	float notaEngleza;
	float notaIstorie;

public:
	void setName(const char* nume);
	const char* getName();
	
	bool setNotaMate(float nota);
	float getNotaMate();

	bool setNotaEngleza(float nota);
	float getNotaEngleza();

	bool setNotaIstorie(float nota);
	float getNotaIstorie();

	float getAverage();
};