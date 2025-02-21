

#include <iostream>
#include "Mylib/Header.h"

/// <summary>
/// Написать функцию, которая удаляет из строки символ с заданным номером.
/// </summary>
void task1(TaskStructure m) {
	
	setCursorPosition(m.startPos);
	std::cout << "Дана строка :";
	nextLine(m.startPos, 2);
	int sizeF; //Размер будущего массива
	char* f = newChars("Привет мир", sizeF);
	for (int i = 0; i < sizeF - 1; i++)
		std::cout << i;
	nextLine(m.startPos);
	std::cout << f;
	nextLine(m.startPos, 2);
	int N = getValidInt(m, "Укажите символ с каким номером нужно удалить :");

	nextLine(m.startPos, 2);
	for (int i = 0; i < sizeF-1; i++)
		if(N != i) std::cout << i;
	nextLine(m.startPos);
	deleteSymbol(f, sizeF, N);
	std::cout << f;
	delete[] f;

	endTask(m);
}
/// <summary>
/// Написать функцию, которая удаляет из строки все вхождения в нее заданного символа.
/// </summary>
void task2(TaskStructure m) {
	setCursorPosition(m.startPos);
	int M = getValidInt(m, "Введите длину первого массива :");
	nextLine(m.startPos);
	int N = getValidInt(m, "Введите длину второго массива :");
	nextLine(m.startPos, 2);
	int* A = new int[M];
	int* B = new int[N];
	int randA = 0;
	int randB = 10;
	std::cout << "Было сгенерировано 2 массива случайными числами от "
		<< randA << " до " << randB;
	randIntArr(A, M, randA, randB);
	randIntArr(B, N, randA, randB);
	nextLine(m.startPos);
	std::cout << "A = ";
	show(A, M);
	nextLine(m.startPos);
	std::cout << "B = ";
	show(B, N);
	nextLine(m.startPos);
	std::cout << "Уникальные элементы массива которые не повторяются:";
	int L = getUniqueCount(A, M, B, N);
	int* C = getUniqueElements(A, M, B, N, L);
	
	int L2 = getUniqueCount(B, N, A, M);
	int* C2 = getUniqueElements(B, N, A, M, L2);

	int L3 = L + L2;
	int* D = joinArrays(C,L,C2,L2);
	nextLine(m.startPos);
	show(D, L3);


	delete[] A;
	delete[] B;
	delete[] C;
	delete[] C2;
	delete[] D;

	endTask(m);

}
/// <summary>
/// Написать функцию, которая вставляет в строку в указанную позицию заданный символ.
/// </summary>
void task3(TaskStructure m) {
	setCursorPosition(m.startPos);
	int M = getValidInt(m, "Введите длину первого массива :");
	nextLine(m.startPos);
	int N = getValidInt(m, "Введите длину второго массива :");
	nextLine(m.startPos, 2);
	int* A = new int[M];
	int* B = new int[N];
	int randA = 0;
	int randB = 10;
	std::cout << "Было сгенерировано 2 массива случайными числами от "
		<< randA << " до " << randB;
	randIntArr(A, M, randA, randB);
	randIntArr(B, N, randA, randB);
	nextLine(m.startPos);
	std::cout << "A = ";
	show(A, M);
	nextLine(m.startPos);
	std::cout << "B = ";
	show(B, N);
	nextLine(m.startPos);
	std::cout << "Получаем склеенный массив:";
	int L = M + N;
	int* C = joinArrays(A, M, B, N);
	nextLine(m.startPos);
	show(C, L);
	delete[] A;
	delete[] B;
	delete[] C;
	endTask(m);

}
/// <summary>
/// Написать программу, которая заменяет все символы точки "." в строке, введенной пользователем, на символы восклицательного знака "!".
/// </summary>
void task4(TaskStructure m) {
	setCursorPosition(m.startPos);
	int M = getValidInt(m, "Введите длину первого массива :");
	nextLine(m.startPos);
	int N = getValidInt(m, "Введите длину второго массива :");
	nextLine(m.startPos, 2);
	int* A = new int[M];
	int* B = new int[N];
	int randA = 1;
	int randB = 10;
	std::cout << "Было сгенерировано 2 массива случайными числами от "
		<< randA << " до " << randB;
	randIntArr(A, M, randA, randB);
	randIntArr(B, N, randA, randB);
	nextLine(m.startPos);
	std::cout << "A = ";
	show(A, M);
	nextLine(m.startPos);
	std::cout << "B = ";
	show(B, N);
	nextLine(m.startPos);
	int L = getRepeatedCount(A, M, B, N);
	int* C = getRepeatedElements(A, M, B, N, L);
	show(C, L);
	delete[] A;
	delete[] B;
	delete[] C;
	endTask(m);
}
/// <summary>
/// Пользователь вводит строку символов и искомый символ, посчитать сколько раз он встречается в строке.
/// </summary>
void task5(TaskStructure m) {
	setCursorPosition(m.startPos);
	int M = getValidInt(m, "Введите длину массива :");
	nextLine(m.startPos);
	int* A = new int[M];
	int randA = -10;
	int randB = 10;
	std::cout << "Было сгенерировано массив случайными числами от "
		<< randA << " до " << randB;
	randIntArr(A, M, randA, randB);
	nextLine(m.startPos);
	std::cout << "A = ";
	show(A, M);
	nextLine(m.startPos);

	/*Создаем меню*/
	int countMenu = 2;
	const char* elemMenu[] = { "Удалить положительные", "Удалить отрицательные" };
	Menu menu = constructMenu( m.startPos, countMenu, elemMenu, 0);
	
	int nMenu = scrollMenu(menu);
	clearMenu(menu);
	nextLine(m.startPos, countMenu+1);
	if (nMenu == 0) deletePositiveElement(A, M);
	if (nMenu == 1) deleteNegativeElement(A, M);
	std::cout << "Теперь массив выглядит так:";
	nextLine(m.startPos);
	show(A, M);
	endTask(m);
}
/// <summary>
/// Пользователь вводит строку. Определить количество букв, количество цифр и количество остальных символов, присутствующих в строке.
/// </summary>
void task6(TaskStructure m) {
	setCursorPosition(m.startPos);
	std::cout << "Я придумал за вас динамический массив с простыми числами:";
	int sizeA = 10;
	int* a = new int[sizeA];//Динамический массив
	for (int i = 0; i < sizeA; i++)
		a[i] = i + 1;
	nextLine(m.startPos);
	show(a, sizeA);
	nextLine(m.startPos);
	std::cout << "Теперь я удалил из него простые числа:";
	nextLine(m.startPos);
	deletePrimeElement(a, sizeA);
	show(a, sizeA);
	delete[] a;
	endTask(m);
}
/// <summary>
/// Подсчитать количество слов во введенном предложении.
/// </summary>
void task7(TaskStructure m) {
	
	endTask(m);
}
/// <summary>
/// Дана строка символов. Необходимо проверить является ли эта строка палиндромом.
/// </summary>
void task8(TaskStructure m) {

	endTask(m);
}

int getCharInTextCount(char* text, char symbol) {
	int result = 0;
	while (*text) {
		if (*text == symbol) result++;
		text++;
	}
	return result;		
}

void deleteCharsInText(char* &text, int &size, char symbol) {
	int newSize = size - getCharInTextCount(text, size);
	char* newArr = new char[newSize];
	char* start = newArr;
	for (int i = 0; i < size; i++)
	{
		if (*start == symbol) continue;
		*start = text[i];
		start++;
	}
	delete[] text;
	size = newSize;
	text = newArr;
}

int main()
{
	
	system("chcp 1251>nul");
	int sizeF; //Размер будущего массива
	char* f = newChars("Привет мир", sizeF);
	deleteCharsInText(f, sizeF, 'и');
	std::cout << f;
	gitPush("Задание 1 работа 20: Готово");
	
	//startMenu();

	
}

