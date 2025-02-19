#pragma once
#include <iostream>


template<typename T, size_t N>
void show(T(&a)[N]) {
	std::cout << "|";
	for (int i = 0; i < N; i++) {
		std::cout.width(3);
		std::cout << a[i] << "|";
	}
		
}

template<typename T, size_t N, size_t M>
void show(T(&a)[N][M]) {
	for (size_t i = 0; i < N; i++)
		show(a[i]);
}

