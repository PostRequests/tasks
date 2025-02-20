﻿

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
	std::cout << "Дана строка :";
	nextLine(m.startPos);
	int sizeF; //Размер будущего массива
	char* f = newChars("Еду я по выбоинам, из выбоин не выеду я.", sizeF);
	nextLine(m.startPos);
	std::cout << f;
	nextLine(m.startPos, 2);
	std::cout << "Укажите символ который нужно удалить :";
	char symbol;
	std::cin >> symbol;

	nextLine(m.startPos, 2);
	std::cout << "Теперь строка выглядит вот так :";
	deleteCharsInText(f, sizeF, symbol);
	nextLine(m.startPos);
	std::cout << f;
	delete[] f;
	
	endTask(m);

}

/// <summary>
/// Написать функцию, которая вставляет в строку в указанную позицию заданный символ.
/// </summary>
void task3(TaskStructure m) {
	setCursorPosition(m.startPos);
	std::cout << "Дана строка :";
	nextLine(m.startPos);
	int sizeF; //Размер будущего массива
	char* f = newChars("Я помню чудное ***,\nПередо мной явилась ты,\nКак мимолётное виденье,\nКак гений чистой красоты.", sizeF);
	nextLine(m.startPos);
	showWrappedText(m, f);
	nextLine(m.startPos, 2);
	std::cout << "Угадайте что зашифровано под *** :";
	const int limitSymbol = 100;
	char str[limitSymbol];
	std::cin.getline(str, limitSymbol);
	deleteCharsInText(f, sizeF, '*');
	nextLine(m.startPos);
	std::cout << "Подставляем значение и получаем :";
	addStr(f, sizeF, str, 15);//Функция для решения задачи
	nextLine(m.startPos, 2);
	showWrappedText(m, f);
	delete[] f;
	endTask(m);

}
/// <summary>
/// Написать программу, которая заменяет все символы точки "." в строке, введенной пользователем, на символы восклицательного знака "!".
/// </summary>
void task4(TaskStructure m) {
	setCursorPosition(m.startPos);
	char a[] = "\tНочь, улица, фонарь, аптека,\n\tБессмысленный и тусклый свет.\n\tЖиви еще хоть четверть века —\n\tВсё будет так.Исхода нет.\n\n\tУмрешь — начнешь опять сначала,\n\tИ повторится всё, как встарь :\n\tНочь, ледяная рябь канала,\n\tАптека, улица, фонарь...";
	std::cout << "Было:";
	showWrappedText(m, a);
	replase(a, '.', '!');
	nextLine(m.startPos);
	std::cout << "Стало:";
	showWrappedText(m, a);
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



int main()
{
	
	system("chcp 1251>nul");
	
	gitPush("Задание 4 работа 21: Готово");
	
	startMenu();

	
}

