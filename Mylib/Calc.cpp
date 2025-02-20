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
int getSumRange(int* arr, int size) {
    int* end = arr + size;
    int result = 0;
    for (; arr != end; result += *arr, arr++);
    return result;
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

void randIntArr(int arr[], int size, int min, int max) {
    static bool firstCall = true;
    if (firstCall) {
        srand(time(0));
        firstCall = false;
    }
    for (int i = 0; i < size; i++)
        arr[i] = rand() % (max - min + 1) + min;
}

int getUniqueCount(int* A, int M, int* B, int N) {
    int unique = 0;
    for (int a = 0; a < M; a++) {
        bool uniq = true;
        // Проверяем, встречается ли число в самом себе
        for (int self = a; self < M; self++) {
            if (A[a] == A[self] && a != self) {
                uniq = false;
                break;
            }
        }
        if (!uniq) continue;

        for (int b = 0; b < N; b++) {
            if (A[a] == B[b]) {
                uniq = false;
                break;
            }
        }
        if (uniq) unique++;
    }
    return unique;
}

int* getUniqueElements(int* A, int M, int* B, int N, int unique) {
    int* C = new int[unique];
    int* temp = C;
    for (int a = 0; a < M; a++) {
        bool uniq = true;
        for (int self = a; self < M; self++) {
            if (A[a] == A[self] && a != self) {
                uniq = false;
                break;
            }
        }
        if (!uniq) continue;

        for (int b = 0; b < N; b++) {
            if (A[a] == B[b]) {
                uniq = false;
                break;
            }
        }
        if (uniq) {
            *temp = A[a];
            temp++;
        }
    }
    return C;
}

int* joinArrays(int* arr1, int size1, int* arr2, int size2) {
    int* result = new int[size1 + size2];
    int* start = result;
    for (int i = 0; i < size1; i++, start++)
        *start = arr1[i];
    for (int i = 0; i < size2; i++, start++)
        *start = arr2[i];
    return result;
}