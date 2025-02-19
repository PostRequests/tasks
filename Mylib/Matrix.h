#pragma once
#include "Header.h"
#include <iostream>
template<typename T, size_t N>
T getMax(T (&a)[N]) {
	T max = a[0];
	for (int i = 1; i < N; ++i)
		if (max < a[i]) max = a[i];
	return max;
}
template<typename T, size_t N, size_t M>
T getMax(T(&a)[N][M]) {
	T max = a[0][0];
	for (int i = 0; i < N; ++i) {
		T maxT = getMax(a[i]);
		if (maxT > max) max = maxT;
	}
	return max;
}

template<typename T, size_t N>
T getMin(T(&a)[N]) {
	T max = a[0];
	for (int i = 1; i < N; ++i)
		if (max > a[i]) max = a[i];
	return max;
}
template<typename T, size_t N, size_t M>
T getMin(T(&a)[N][M]) {
	T max = a[0][0];
	for (int i = 0; i < N; ++i) {
		T maxT = getMin(a[i]);
		if (maxT < max) max = maxT;
	}
	return max;
}


template<typename T, size_t N>
void sortStone(T (&a)[N]) {
	for (size_t i = 0; i < N; i++)
	{
		bool f = true;
		for (size_t c = 0; c < N - 1 - i; c++)
		{
			if (a[c] > a[c + 1])
			{
				T temp = a[c];
				a[c] = a[c + 1];
				a[c + 1] = temp;
			}
			else f = false;
		}
		if (f) break;
	}
}

template <typename T, size_t N>
void sortInsert(T (&a)[N]) {
	int j;
	for (size_t i = 0; i < N; i++) {
		T temp = a[i];
		for (j = i - 1; j >= 0 && a[j] > temp; j--)
			a[j + 1] = a[j];
		a[j + 1] = temp;
	}
}

template <typename T, size_t N, size_t M>
void sortInsert(T(&a)[N][M]) {
	for (size_t i = 0; i < N; i++)
		sortInsert(a[i]);
}

