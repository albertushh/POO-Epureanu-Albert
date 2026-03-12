#pragma once
class Sort
{
    // add data members 
    int arr[200];
    int nr_elem = 0;
    void swapp(int& a, int& b);
    int Partition(int low, int high, bool ascendent);
    void QuickSortRecursive(int low, int high, bool ascendent);
public:
    
    
    Sort(int v[], int n);
    Sort(std::initializer_list<int> list);
    Sort(int n, int mmin, int mmax);
    Sort(int count, ...);
    Sort(const char* s);
    // add constuctors
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
