#include "Functions.h"
#include <cstring>

int compareName(const Student& s1, const Student& s2) {
    int res = strcmp(s1.getName(), s2.getName());
    if (res == 0) return 0;
    return (res > 0) ? 1 : -1;
}

int compareMath(const Student& s1, const Student& s2) {
    if (s1.getMathGrade() == s2.getMathGrade()) return 0;
    return (s1.getMathGrade() > s2.getMathGrade()) ? 1 : -1;
}

int compareEnglish(const Student& s1, const Student& s2) {
    if (s1.getEnglishGrade() == s2.getEnglishGrade()) return 0;
    return (s1.getEnglishGrade() > s2.getEnglishGrade()) ? 1 : -1;
}

int compareHistory(const Student& s1, const Student& s2) {
    if (s1.getHistoryGrade() == s2.getHistoryGrade()) return 0;
    return (s1.getHistoryGrade() > s2.getHistoryGrade()) ? 1 : -1;
}

int compareAverage(const Student& s1, const Student& s2) {
    float a1 = s1.getAverage();
    float a2 = s2.getAverage();
    if (a1 == a2) return 0;
    return (a1 > a2) ? 1 : -1;
}