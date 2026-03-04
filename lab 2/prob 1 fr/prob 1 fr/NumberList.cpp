#include "NumberList.h"
#include <algorithm>
#include <iostream>

void NumberList::Init()
{
	this->count = 0;
}

bool NumberList::Add(int x)
{
    if (count > 10) return false;
    this->numbers[count] = x;       
    count++;
    return true;
}

void NumberList::Sort()
{
    int n = count;
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                std::swap(numbers[j], numbers[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped, then break
        if (!swapped)
            break;
    }
}

void NumberList::Print()
{
    for (int i = 0; i < count; i++)
        std::cout << numbers[i]  << " ";
}
