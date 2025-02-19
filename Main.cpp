

#include <iostream>
#include "Mylib/Header.h"


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

void task2(Menu m) {
	int ma[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // Изначальный массив
	int sizeArr = sizeof(ma) / sizeof(ma[0]); // Размер начального массива
	/*Функция решения задания*/
	reverseNumArr(ma, sizeArr);
	setCursorPosition(m.startPos);
	std::cout << "Содержание изначального массива: ";
	nextLine(m.startPos);
	show(ma, sizeArr);
	nextLine(m.startPos);
	std::cout << "Теперь мы его перевернули ";
	
	nextLine(m.startPos);
	show(ma, sizeArr);
	endTask(m);

}
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
void task5(Menu m) {
	Coordinate pos = m.startPos;
	int num;
	int* pNum = &num;
	setCursorPosition(pos);
	std::cout << "Введите число: ";
	std::cin >> *pNum;

	nextLine(pos);
	std::cout << "Ваше число " << ((*pNum < 0) ? "отрицательное" : "положительное");
	m.startPos = pos;
	endTask(m);
}
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
	std::cout << "Теперь значение числа a = " << *pa << " а  б = " << *pb;
	nextLine(m.startPos);
	std::cout << "Адрес числа a = " << pa << " и адрес б = " << pb;
	endTask(m);
}
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
	startMenu();
}

