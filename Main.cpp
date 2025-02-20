

#include <iostream>
#include "Mylib/Header.h"

/// <summary>
/// Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). Необходимо создать третий массив минимально возможного размера, в котором нужно собрать элементы массива A, которые не включаются в массив B, без повторений.
/// </summary>
void task1(TaskStructure m) {
	
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
	std::cout << "Уникальные элементы массива A которые не встречаются в массиве B:";
	int L = getUniqueCount(A, M, B, N);
	int* C = getUniqueElements(A, M, B, N, L);
	nextLine(m.startPos);
	show(C, L);
	nextLine(m.startPos);
	std::cout << "Уникальные элементы массива B которые не встречаются в массиве A:";
	int L2 = getUniqueCount(B, N, A, M);
	int* C2  = getUniqueElements(B, N, A, M, L2);
	nextLine(m.startPos);
	show(C2, L2);

	delete[] A;
	delete[] B;
	delete[] C;
	delete[] C2;
	endTask(m);
}
/// <summary>
/// Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). Необходимо создать третий массив минимально возможного размера, в котором нужно собрать элементы массивов A и B, которые не являются общими для них, без повторений.
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
/// Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). Необходимо создать третий массив минимально возможного размера, в котором нужно собрать элементы обоих массивов.
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
/// Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). Необходимо создать третий массив минимально возможного размера, в котором нужно собрать общие элементы двух массивов без повторений.
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
/// Дан массив: А[M] (M вводится с клавиатуры). Необходимо удалить из массива четные или нечетные значения. Пользователь вводит данные в массив, а также с помощью меню решает, что нужно удалить.
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
/// Написать функцию, которая получает указатель на динамический массив и его размер. Функция должна удалить из массива все простые числа и вернуть указатель на новый динамический массив.
/// </summary>
void task6(TaskStructure m) {
	
	endTask(m);
}
/// <summary>
/// 
/// </summary>
void task7(TaskStructure m) {
	
	endTask(m);
}

int main()
{
	
	system("chcp 1251>nul");
	gitPush("Задание 5: Готово");


	//startMenu();

	
}

