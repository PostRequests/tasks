#include <iostream>
#include <Windows.h>

#include "Header.h"

int calculateRangeSum(int a, int b) {
    if (a > b)
        std::swap(a, b);
    if (a == b)
        return a;
    return a + calculateRangeSum(a + 1, b);
}

int getPower(int d, int e) {
    if (e == 0)
        return 1; // любое число в степени 0 равно 1
    if (e == 1)
        return d; // любое число в степени 1 равно самому себе
    return d * getPower(d, e - 1);
}

int getSumRange(int arr[], int i, int j) {
    if (i == j)
        return arr[i];
    return arr[j] + getSumRange(arr, i, j - 1);
}

int getSumRangeArr(int arr[], int size, int i, int j) {
    if (i > j)
        std::swap(i, j);
    if (i < 0 || j < 0 || i >= size || j >= size) 
        return -1;
    if (i == j) 
        return arr[i];

    return arr[i] + getSumRangeArr(arr, size, i + 1, j);
}

int getNumLength(int n) {
    int length = 0;
    if (n < 0) {
        length++;
        n = -n;
    }
    while (n > 0) {
        length++;
        n /= 10;
    }
    return length;
}

void copyNumArr(int* orig, int* copy, int sOrig) {
    for (int i = 0; i < sOrig; i++, orig++, copy++)
        *orig = *copy;

}

void show(int* a, int size) {
    std::cout << "|";
    for (int i = 0; i < size; i++) {
        std::cout.width(3);
        std::cout << a[i] << "|";
    }
}

void reverseNumArr(int* arr, int size) {
    int* end = arr + size - 1;
    for (; arr < end; arr++, end--)
        std::swap(*arr, *end);
    
}

void copyReverseNumArr(int* arr, int* arr2, int size) {
    int* end = arr2 + size - 1;
    for (; arr2 - 1 != end; *arr = *end, end--, arr++);
}

int* findMax(int* a, int* b) {
    return (*a > *b) ? a : b;
}
int* findMin(int* a, int* b) {
    return (*a < *b) ? a : b;
}