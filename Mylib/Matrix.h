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

template <typename T>
void MassShift(T*a, int N, char d) {

	if (d == 'a') {
		T temp = a[0];
		for (int i = 0; i < N - 1; i++)
			a[i] = a[i + 1];
		a[N - 1] = temp;
	}
	else if (d == 'd') {
		T temp = a[N - 1];
		for (int i = N - 1; i > 0; i--)
			a[i] = a[i - 1];
		a[0] = temp;
	}
}

template<typename T>
void MassShift(T **a, int N, int M, char d) {
	if (d == 'a' || d == 'd')
		for (int i = 0; i < N; i++)
			MassShift(a[i],N ,d);
	else if (d == 'w') {
		T* aTemp = new T[M];
		for (int i = 0; i < M; i++)
			aTemp[i] = a[0][i];
		for (int r = 0; r < N - 1; r++)
			for (int c = 0; c < M; c++)
				a[r][c] = a[r + 1][c];
		for (int i = 0; i < M; i++)
			a[N - 1][i] = aTemp[i];
		delete[]aTemp;
	}
	else if (d == 's') {
		T* aTemp = new T[M];
		for (int i = 0; i < M; i++)
			aTemp[i] = a[N - 1][i];
		for (int r = N - 1; r > 0; r--)
			for (int c = 0; c < M; c++)
				a[r][c] = a[r - 1][c];
		for (int i = 0; i < M; i++)
			a[0][i] = aTemp[i];
		delete[]aTemp;
	}
	
		
}
