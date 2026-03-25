#ifndef NUMBER_H
#define NUMBER_H
#define _CRT_SECURE_NO_WARNINGS

class Number {
    char* value;
    int base;

    static int CharToInt(char c);
    static char IntToChar(int v);
    long long ToDecimal() const;
    static char* FromDecimal(long long val, int base);

public:
    Number(const char* value, int base);
    Number(int value);
    Number(const char* value);
    ~Number();

    Number(const Number& other);
    Number& operator=(const Number& other);

    Number(Number&& other) noexcept;
    Number& operator=(Number&& other) noexcept;

    Number& operator=(const char* val);
    Number& operator=(int val);

    char operator[](int index) const;
    bool operator>(const Number& other) const;
    bool operator<(const Number& other) const;
    bool operator>=(const Number& other) const;
    bool operator<=(const Number& other) const;
    bool operator==(const Number& other) const;

    friend Number operator+(const Number& n1, const Number& n2);
    friend Number operator-(const Number& n1, const Number& n2);

    Number& operator+=(const Number& other);

    Number& operator--();
    Number operator--(int);

    void SwitchBase(int newBase);
    void Print() const;
    int GetDigitsCount() const;
    int GetBase() const;
};

#endif  