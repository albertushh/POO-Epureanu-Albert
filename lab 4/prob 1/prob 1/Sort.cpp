#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <random>
#include <stdio.h>
#include <cstdlib>
#include <cstdarg>
#include <stdarg.h>
#include <initializer_list>
#include "Sort.h"

using namespace std;

void Sort::swapp(int& a, int& b)
{
    int aux;
    aux = a;
    a = b;
    b = aux;
}

Sort::Sort(int n, int mmin, int mmax)
{
    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(mmin, mmax);
    
    for (int i = 0; i < this->nr_elem; i++)
    {
        arr[i] = distrib(gen);
    }
}

Sort::Sort(std::initializer_list<int> list) {
    this->nr_elem = 0;
    for (int x : list) {
        if (this->nr_elem >= 100) break;
        arr[this->nr_elem++] = x;
    }
}

Sort::Sort(int v[], int n)
{
    this->nr_elem = n;
    for (int i = 0; i < n; i++)
        this->arr[i] = v[i];
}

Sort::Sort(int count, ...)
{
    va_list vl;
    va_start(vl, count);
    for (int i = 0; i < this->nr_elem; i++)
    {
        arr[i] = va_arg(vl, int);
    }
    va_end(vl);
}

Sort::Sort(const char* s) {
    this->nr_elem = 0;
    char temp[256];
    strncpy(temp, s, 255);
    temp[255] = '\0';

    char* token = strtok(temp, ",");
    while (token != NULL && this->nr_elem < 100) {
        arr[this->nr_elem++] = atoi(token);
        token = strtok(NULL, ",");
    }
}

void Sort::InsertSort(bool ascendant)
{
    for (int i = 1; i < nr_elem; ++i) 
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }   
}

int Sort::Partition(int low, int high, bool ascendent)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        bool condition = ascendent ? (arr[j] <= pivot) : (arr[j] >= pivot);
        if (condition) {
            i++;
            swapp(arr[i], arr[j]);
        }
    }
    swapp(arr[i + 1], arr[high]);
    return (i + 1);
}

void Sort::QuickSortRecursive(int low, int high, bool ascendent)
{
    if (low < high) {
        int pi = Partition(low, high, ascendent);
        QuickSortRecursive(low, pi - 1, ascendent);
        QuickSortRecursive(pi + 1, high, ascendent);
    }
}

void Sort::QuickSort(bool ascendent) 
{
    if (nr_elem > 0) QuickSortRecursive(0, nr_elem - 1, ascendent);
}

void Sort::BubbleSort(bool ascendent)
{
    bool swapped;

    for (int i = 0; i < nr_elem - 1; i++) 
    {
        swapped = false;
        for (int j = 0; j < nr_elem - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swapp(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void Sort::Print()
{
    for (int i = 0; i < nr_elem; i++)
        cout << arr[i] << " ";
}

int  Sort::GetElementsCount()
{
    return nr_elem;
}

int Sort::GetElementFromIndex(int index)
{
    return this->arr[index];
}