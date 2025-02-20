

#include <iostream>
#include "Mylib/Header.h"

/// <summary>
/// Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). Необходимо создать третий массив минимально возможного размера, в котором нужно собрать элементы массива A, которые не включаются в массив B, без повторений.
/// </summary>
void task1(Menu m) {
	
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
void task2(Menu m) {
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
void task3(Menu m) {

	endTask(m);

}
/// <summary>
/// Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). Необходимо создать третий массив минимально возможного размера, в котором нужно собрать общие элементы двух массивов без повторений.
/// </summary>
void task4(Menu m) {
	srand(time(0));
	int a = rand() % 100;
	int b = rand() % 100;
	int* pa = &a;
	int* pb = &b;
	setCursorPosition(m.startPos);
	std::cout << "Я загадал 2 числа " << a <<" и " << b;
	nextLine(m.startPos);
	std::cout << "Проведя диагностику, я выяснил, что " << *findMax(pa, pb) << " больше чем " << *findMin(pa, pb);
	endTask(m);
}
/// <summary>
/// Дан массив: А[M] (M вводится с клавиатуры). Необходимо удалить из массива четные или нечетные значения. Пользователь вводит данные в массив, а также с помощью меню решает, что нужно удалить.
/// </summary>
void task5(Menu m) {
	Coordinate pos = m.startPos;
	ColorANSI3b color;
	char text[12];
	char* pt = text;
	setCursorPosition(pos);
	while (true) {
		std::cout << "Введите число: ";
		std::cin >> text;
		if (isNumber(text))
			break;
		else {
			drawEmptyRectangle(16, 9, 3, m.cS.x - 17);
			pos = m.startPos;
			setCursorPosition(pos);
			setColor(color.RedFG);
			std::cout << "Число введено некорректно! Пожалуйста, попробуйте снова.";
			resetColor();
			nextLine(pos);
		}
	}
	nextLine(pos);
	std::cout << "Ваше число " << ((*pt == '-') ? "отрицательное" : "положительное");
	m.startPos = pos;
	endTask(m);
}
/// <summary>
/// Написать функцию, которая получает указатель на динамический массив и его размер. Функция должна удалить из массива все простые числа и вернуть указатель на новый динамический массив.
/// </summary>
void task6(Menu m) {
	srand(time(0));
	int a = rand() % 100;
	int b = rand() % 100;
	int* pa = &a;
	int* pb = &b;
	setCursorPosition(m.startPos);
	std::cout << "Я загадал 2 числа a = " << *pa << " и  б = " << *pb;
	nextLine(m.startPos);
	std::cout << "Адрес числа a = " << pa << " и адрес б = " << pb;
	nextLine(m.startPos, 2);
	std::cout << "А теперь меняем их местами";
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
	nextLine(m.startPos, 2);
	std::cout << "Теперь значение числа A = " << *pa << " а  B = " << *pb;
	nextLine(m.startPos);
	std::cout << "Адрес числа A = " << pa << " и адрес B = " << pb;
	endTask(m);
}
/// <summary>
/// 
/// </summary>
void task7(Menu m) {
	
	endTask(m);
}

int main()
{
	system("chcp 1251>nul");



	//startMenu();

	gitPush("Задание 2: Готово");
}

