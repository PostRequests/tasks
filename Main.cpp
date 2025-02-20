

#include <iostream>
#include "Mylib/Header.h"

/// <summary>
/// Используя два указателя на массив целых чисел, скопировать один массив в другой. Использовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования.
/// </summary>
void task1(Menu m) {
	int ma[]{ 1, 23, 42, 12, 45, 64, 23, 4, 5, 10 }; // Изначальный массив
	int sizeArr = sizeof(ma) / sizeof(ma[0]); // Размер начального массива
	int* pm = new int[sizeArr]; // Новый указатель на массив
	/*Функция решения задания*/
	copyNumArr(pm, ma, sizeArr); 
	setCursorPosition(m.startPos);
	std::cout << "Адрес изначального массива = " << &ma;
	nextLine(m.startPos);
	std::cout << "Его содержание = ";
	show(ma);
	nextLine(m.startPos, 2);
	std::cout << "Адрес копии массива = " << pm;
	nextLine(m.startPos);
	std::cout << "Его содержание = ";
	show(pm, sizeArr);

	delete[] pm;
	pm = nullptr;
	endTask(m);
}
/// <summary>
/// Используя указатель на массив целых чисел, изменить порядок следования элементов массива на противоположный. Использовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования.
/// </summary>
void task2(Menu m) {
	int ma[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // Изначальный массив
	int sizeArr = sizeof(ma) / sizeof(ma[0]); // Размер начального массива
	
	setCursorPosition(m.startPos);
	std::cout << "Содержание изначального массива: ";
	nextLine(m.startPos);
	show(ma, sizeArr);
	nextLine(m.startPos);
	std::cout << "Теперь мы его перевернули ";
	/*Функция решения задания*/
	reverseNumArr(ma, sizeArr);
	nextLine(m.startPos);
	show(ma, sizeArr);
	endTask(m);

}
/// <summary>
/// Используя два указателя на массивы целых чисел, скопировать один массив в другой так, чтобы во втором массиве элементы находились в обратном порядке. Использовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования.
/// </summary>
void task3(Menu m) {
	int ma[]{ 1, 2, 4, 5, 6, 7, 8, 9, 10, 11 }; // Изначальный массив
	int sizeArr = sizeof(ma) / sizeof(ma[0]); // Размер начального массива
	int* pm = new int[sizeArr]; // Новый указатель на массив
	setCursorPosition(m.startPos);
	std::cout << "Адрес изначального массива = " << &ma;
	nextLine(m.startPos);
	std::cout << "Содержание изначального массива: ";
	nextLine(m.startPos);
	show(ma, sizeArr);
	nextLine(m.startPos, 2);
	std::cout << "Адрес копии массива = " << pm;
	nextLine(m.startPos);
	std::cout << "Содержание копированного и перевернутого массива: ";
	nextLine(m.startPos);
	/*Функция решения задания*/
	copyReverseNumArr(pm, ma, sizeArr);
	show(pm, sizeArr);

	delete[] pm;
	pm = nullptr;
	endTask(m);

}
/// <summary>
/// Используя указатели и оператор разыменования, определить наибольшее из двух чисел.
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
/// Используя указатели и оператор разыменования, определить знак числа, введённого с клавиатуры.
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
/// Используя указатели и оператор разыменования, обменять местами значения двух переменных.
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
/// Используя указатель на массив целых чисел, посчитать сумму элементов массива. Использовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования.
/// </summary>
void task7(Menu m) {
	int ma[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // Изначальный массив
	int sizeArr = sizeof(ma) / sizeof(ma[0]); // Размер начального массива
	setCursorPosition(m.startPos);
	std::cout << "Содержание массива: ";
	nextLine(m.startPos);
	show(ma, sizeArr);
	nextLine(m.startPos);
	std::cout << "Сумма массива = " << getSumRange(ma, sizeArr);

	endTask(m);
}

int main()
{
	system("chcp 1251>nul");
	gitPush("Коментарий");
	//startMenu();
}

