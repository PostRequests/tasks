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

void deletePrimeElement(int*& arr, int& size) {
    int newSize = getCountNoPrime(arr, size);
    int* newArr = new int[newSize];
    int* start = newArr;
    for (int i = 0; i < size; i++)
        if (!isPrime(arr[i])) {
            *start = arr[i];
            start++;
        }
    delete[] arr;
    size = newSize;
    arr = newArr;
}
int getSumRange(int* arr, int size) {
    int* end = arr + size;
    int result = 0;
    for (; arr != end; result += *arr, arr++);
    return result;
}
int getCountNoPrime(int* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++)
        if (!isPrime(arr[i])) count++;
    return count;
}
int getCountPrime(int* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++)
        if (isPrime(arr[i])) count++;
    return count;
}
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
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


void deletePositiveElement(int*& arr, int& size) {
    int newSize = getNegativeCount(arr, size);
    int* newArr = new int[newSize];
    int* start = newArr;
    for (int i = 0; i < size; i++)
        if (arr[i] < 0) {
            *start = arr[i];
            start++;
        }
    delete[] arr;
    size = newSize;
    arr = newArr;
}

void deleteNegativeElement(int* &arr, int& size) {
    int newSize = getPositiveCount(arr, size);
    int* newArr = new int[newSize];
    int* start = newArr;
    for (int i = 0; i < size; i++) 
        if (arr[i] > 0) {
            *start = arr[i];
            start++;
        }
    delete[] arr;
    size = newSize;
    arr = newArr;
}
int getNegativeCount(int* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) if (arr[i] < 0) count++;
    return count;
}



int getPositiveCount(int* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) if (arr[i] > 0) count++;
    return count;
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
int* getRepeatedElements(int* arr1, int size1, int* arr2, int size2, int repeated) {
    int* newArr = new int[repeated];
    int* temp = newArr;
    for (int a = 0; a < size1; a++) {
        bool isUnique = true;

        for (int self = 0; self < a; self++) {
            if (arr1[a] == arr1[self]) {
                isUnique = false;
                break;
            }
        }
        if (!isUnique) continue;

        bool foundInArr2 = false;
        for (int b = 0; b < size2; b++) {
            if (arr1[a] == arr2[b]) {
                foundInArr2 = true;
                break;
            }
        }
        if (foundInArr2) {
            *temp = arr1[a];
            temp++;
        }
           
    }

    return newArr;
}
int getRepeatedCount(int* arr1, int size1, int* arr2, int size2) {
    int repeated = 0;

    for (int a = 0; a < size1; a++) {
        bool isUnique = true;

        for (int self = 0; self < a; self++) {
            if (arr1[a] == arr1[self]) {
                isUnique = false; 
                break;
            }
        }
        if (!isUnique) continue; 

        bool foundInArr2 = false;
        for (int b = 0; b < size2; b++) {
            if (arr1[a] == arr2[b]) {
                foundInArr2 = true;
                break;
            }
        }
        if (foundInArr2) repeated++;
    }

    return repeated;
}


int getUniqueCount(int* arr1, int size1, int* arr2, int size2) {
    int unique = 0;
    for (int a = 0; a < size1; a++) {
        bool uniq = true;
        // Проверяем, встречается ли число в самом себе
        for (int self = a; self < size1; self++) {
            if (arr1[a] == arr1[self] && a != self) {
                uniq = false;
                break;
            }
        }
        if (!uniq) continue;

        for (int b = 0; b < size2; b++) {
            if (arr1[a] == arr2[b]) {
                uniq = false;
                break;
            }
        }
        if (uniq) unique++;
    }
    return unique;
}

int* getUniqueElements(int* arr1, int size1, int* arr2, int size2, int unique) {
    int* C = new int[unique];
    int* temp = C;
    for (int a = 0; a < size1; a++) {
        bool uniq = true;
        for (int self = a; self < size1; self++) {
            if (arr1[a] == arr1[self] && a != self) {
                uniq = false;
                break;
            }
        }
        if (!uniq) continue;

        for (int b = 0; b < size2; b++) {
            if (arr1[a] == arr2[b]) {
                uniq = false;
                break;
            }
        }
        if (uniq) {
            *temp = arr1[a];
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

void addColumn(int**& array, int rows, int& cols, int insertPos, int defaultValue) {
    int** newArray = new int* [rows];
    if (!newArray) return;
    for (int i = 0; i < rows; i++)
        newArray[i] = new int[cols + 1];

    for (int i = 0; i < rows; i++)
        for (int j = 0, newCol = 0; j < cols; j++, newCol++) {
            if (newCol == insertPos) {
                newArray[i][newCol] = defaultValue;
                newCol++;
            }
            newArray[i][newCol] = array[i][j];
        }
    if (insertPos == cols)
        for (int i = 0; i < rows; i++)
            newArray[i][cols] = defaultValue;

    for (int i = 0; i < rows; i++)
        delete[] array[i];

    cols++;
    delete[] array;
    array = newArray;
}

void delColumn(int**& array, int rows, int& cols, int delPos) {
    if (!array) return;
    int** newArray = new int* [rows];
    if (!newArray) return;
    for (int i = 0; i < rows; i++)
        newArray[i] = new int[cols - 1];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < delPos; j++)
            newArray[i][j] = array[i][j];
    if (delPos != cols)
        for (int i = 0; i < rows; i++)
            for (int j = delPos + 1; j < cols; j++)
                newArray[i][j - 1] = array[i][j];

    for (int i = 0; i < rows; i++)
        delete[] array[i];
    delete[] array;
    cols--;
    array = newArray;
}