#include <iostream>
#include "Student.h"
#include "Functions.h"

int main() {
    Student s1, s2;

    s1.setName("Alice");
    s1.setMathGrade(9.0f);
    s1.setEnglishGrade(8.5f);
    s1.setHistoryGrade(10.0f);

    s2.setName("Bob");
    s2.setMathGrade(7.0f);
    s2.setEnglishGrade(9.5f);
    s2.setHistoryGrade(10.0f);

    std::cout << "Comparing Name: " << compareName(s1, s2) << "\n";
    std::cout << "Comparing History (Should be 0): " << compareHistory(s1, s2) << "\n";
    std::cout << "S1 Average: " << s1.getAverage() << "\n";
    std::cout << "Comparing Average: " << compareAverage(s1, s2) << "\n";

    return 0;
}