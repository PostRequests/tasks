#pragma once
#include <iostream>
#include <Windows.h>
template<size_t N>
void randArr(char(&arr)[N], char s, char e) {
    srand(time(0));
    for (size_t i = 0; i < N; i++) {
        arr[i] =  rand() % (e - s + 1) + s + 1;
    }
}

template<typename T, size_t N>
void randArr(T(&a)[N], T s, T e) {
    static bool firstCall = true;
    if (firstCall) {
        srand(time(0));
        firstCall = false;
    }
    for (size_t i = 0; i < N; i++) {
        a[i] = static_cast<T>(rand()) / (static_cast<T>(RAND_MAX / (e - s))) + s + 1 ;
    }
}
template<typename T, size_t N, size_t M>
void randArr(T(&a)[N][M], T s, T e) {
    for (size_t i = 0; i < N; i++) {
        Sleep(5);
        randArr(a[i], s, e);
    }
        
}