#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <iostream>
#include <cstring>
#include <algorithm>

int Number::CharToInt(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    return 0;
}

char Number::IntToChar(int v) {
    if (v >= 0 && v <= 9) return (char)(v + '0');
    return (char)(v - 10 + 'A');
}

long long Number::ToDecimal() const {
    long long res = 0;
    long long p = 1;
    int len = (int)strlen(value);
    for (int i = len - 1; i >= 0; i--) {
        res += (long long)CharToInt(value[i]) * p;
        p *= base;
    }
    return res;
}

char* Number::FromDecimal(long long val, int base) {
    char temp[128];
    int pos = 0;
    if (val == 0) temp[pos++] = '0';
    while (val > 0) {
        temp[pos++] = IntToChar(val % base);
        val /= base;
    }
    temp[pos] = '\0';
    for (int i = 0; i < pos / 2; i++) std::swap(temp[i], temp[pos - i - 1]);

    char* res = new char[pos + 1];
    strcpy(res, temp);
    return res;
}

Number::Number(const char* val, int b) : base(b) {
    value = new char[strlen(val) + 1];
    strcpy(value, val);
}

Number::Number(int val) : base(10) {
    value = FromDecimal(val, 10);
}

Number::Number(const char* val) : base(10) {
    value = new char[strlen(val) + 1];
    strcpy(value, val);
}

Number::~Number() {
    delete[] value;
}

Number::Number(const Number& other) : base(other.base) {
    value = new char[strlen(other.value) + 1];
    strcpy(value, other.value);
}

Number::Number(Number&& other) noexcept : value(other.value), base(other.base) {
    other.value = nullptr;
}

Number& Number::operator=(Number&& other) noexcept {
    if (this != &other) {
        delete[] value;
        value = other.value;
        base = other.base;
        other.value = nullptr;
    }
    return *this;
}

Number& Number::operator=(const Number& other) {
    if (this != &other) {
        delete[] value;
        base = other.base;
        value = new char[strlen(other.value) + 1];
        strcpy(value, other.value);
    }
    return *this;
}

Number& Number::operator=(const char* val) {
    delete[] value;
    value = new char[strlen(val) + 1];
    strcpy(value, val);
    return *this;
}

Number& Number::operator=(int val) {
    long long decimalVal = val;
    char* newVal = FromDecimal(decimalVal, this->base);
    delete[] value;
    value = newVal;
    return *this;
}

char Number::operator[](int index) const {
    return value[index];
}

bool Number::operator>(const Number& other) const { return ToDecimal() > other.ToDecimal(); }
bool Number::operator<(const Number& other) const { return ToDecimal() < other.ToDecimal(); }
bool Number::operator>=(const Number& other) const { return ToDecimal() >= other.ToDecimal(); }
bool Number::operator<=(const Number& other) const { return ToDecimal() <= other.ToDecimal(); }
bool Number::operator==(const Number& other) const { return ToDecimal() == other.ToDecimal(); }

Number operator+(const Number& n1, const Number& n2) {
    int resBase = (n1.base > n2.base) ? n1.base : n2.base;
    long long sum = n1.ToDecimal() + n2.ToDecimal();
    char* resStr = Number::FromDecimal(sum, resBase);
    Number res(resStr, resBase);
    delete[] resStr;
    return res;
}

Number operator-(const Number& n1, const Number& n2) {
    int resBase = (n1.base > n2.base) ? n1.base : n2.base;
    long long diff = n1.ToDecimal() - n2.ToDecimal();
    char* resStr = Number::FromDecimal(diff, resBase);
    Number res(resStr, resBase);
    delete[] resStr;
    return res;
}

Number& Number::operator+=(const Number& other) {
    *this = *this + other;
    return *this;
}

Number& Number::operator--() {
    int len = (int)strlen(value);
    if (len > 0) {
        memmove(value, value + 1, len);
    }
    return *this;
}

Number Number::operator--(int) {
    Number temp(*this);
    int len = (int)strlen(value);
    if (len > 0) {
        value[len - 1] = '\0';
    }
    return temp;
}

void Number::SwitchBase(int newBase) {
    if (base == newBase) return;
    char* newVal = FromDecimal(ToDecimal(), newBase);
    delete[] value;
    value = newVal;
    base = newBase;
}

void Number::Print() const {
    if (value) std::cout << value << std::endl;
}

int Number::GetDigitsCount() const { return (int)strlen(value); }
int Number::GetBase() const { return base; }