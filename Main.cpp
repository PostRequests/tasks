
#ifdef min
#undef min
#endif
#include <iostream>
#include "Mylib/Header.h"



/// <summary>
/// Написать функцию, добавляющую столбец двухмерному массиву в указанную позицию.
/// </summary>
void task1(TaskStructure m) {
	setCursorPosition(m.startPos);
	int rowsArray = 5; //Количество строк массива
	int colsArray = 5;//Количество колонок массива
	int** array = new int* [rowsArray]; //Массив

	for (int i = 0; i < rowsArray; i++)
	{
		array[i] = new int[colsArray];
		for (int j = 0; j < colsArray; j++)
			array[i][j] = 5;  
	}
	std::cout << "Дана матрица";
	nextLine(m.startPos);
	show(m, array, rowsArray, colsArray);
	int input; //Вводимое пользователем число
	while (true) {
		input = getValidInt(m, "Укажите в какой столбец добавить новый. От 0 до 4 : ");
		if (input < 0 or input > colsArray -1 ) {
			m.startPos.y - 2;
			nextLine(m.startPos);
			std::cout << "Вне диапазона";
			nextLine(m.startPos);
		}
		else break;
	}
	addColumn(array, rowsArray, colsArray, input); //Функция по заданию
	show(m, array, rowsArray, colsArray); 
	for (int i = 0; i < rowsArray; i++)
	{
		delete[] array[i];
	}
	delete[] array;
	endTask(m);
}


/// <summary>
/// Написать функцию, удаляющую столбец двухмерного массива по указанному номеру.
/// </summary>
void task2(TaskStructure m) {
	setCursorPosition(m.startPos);
	int rowsArray = 5; //Количество строк массива
	int colsArray = 5;//Количество колонок массива
	int** array = new int* [rowsArray]; //Массив

	for (int i = 0; i < rowsArray; i++)
	{
		array[i] = new int[colsArray];
		for (int j = 0; j < colsArray; j++)
			array[i][j] = j;
	}
	std::cout << "Дана матрица";
	nextLine(m.startPos);
	show(m, array, rowsArray, colsArray);
	int input; //Вводимое пользователем число
	while (true) {
		input = getValidInt(m, "Укажите какой столбец удалить. От 0 до 4 : ");
		if (input < 0 or input > colsArray - 1) {
			m.startPos.y - 2;
			nextLine(m.startPos);
			std::cout << "Вне диапазона";
			nextLine(m.startPos);
		}
		else break;
	}
	delColumn(array, rowsArray, colsArray, input); //Функция по заданию
	show(m, array, rowsArray, colsArray);
	for (int i = 0; i < rowsArray; i++)
	{
		delete[] array[i];
	}
	delete[] array;
	endTask(m);

}

/// <summary>
/// Дана матрица порядка MxN (M строк, N столбцов). 
/// Необходимо заполнить ее значениями и написать функцию, 
/// осуществляющую циклический сдвиг строк и/или столбцов массива указанное количество раз и в указанную сторону.
/// </summary>
void task3(TaskStructure m) {
	setCursorPosition(m.startPos);
	int M = 10; //Количество строк массива
	int N = 10;//Количество колонок массива
	int** array = new int* [M]; //Массив

	for (int i = 0; i < M; i++)
	{
		array[i] = new int[N];
		for (int j = 0; j < N; j++)
			array[i][j] = *findMin(&j, &i);
	}
	std::cout << "Управление WASD, Для выхода нажмите Enter";
	nextLine(m.startPos);
	show(m, array, M, N);
	char input;
	while (true)
	{
		input = catchKey();
		if (input == 13) break;
		else if (input == 'w' or input == 'a' or input == 's' or input == 'd') {
			MassShift(array, M, N, input); //Функция решения задачи
			m.startPos.y -= M + 1;
			drawEmptyRectangle(m.startPos.x, m.startPos.y, M, N * 2);
			show(m, array, M, N);
		}
			
	}
	
	for (int i = 0; i < M; i++)
	{
		delete[] array[i];
	}
	delete[] array;
	endTask(m);

}

/// <summary>
///Транспонирование матрицы – это операция,
/// после которой столбцы прежней матрицы становятся строками, а строки столбцами.
/// Напишите функцию транспонирования матрицы.
/// </summary>
void task4(TaskStructure m) {
	setCursorPosition(m.startPos);
	int M = 9; //Количество строк массива
	int N = 9;//Количество колонок массива
	int** array = new int* [M]; //Массив

	for (int i = 0; i < M; i++)
	{
		array[i] = new int[N];
		for (int j = 0; j < N; j++)
			array[i][j] = j;
	}
	std::cout << "Управление WASD, Для выхода нажмите Enter";
	nextLine(m.startPos);
	show(m, array, M, N);
	char input;
	while (true)
	{
		input = catchKey();
		if (input == 13) break;
		else if (input == 'w' or input == 'a' or input == 's' or input == 'd') {
			transposeMatrix(array, M, N);//Функция решения задачи
			m.startPos.y -= M + 1;
			drawEmptyRectangle(m.startPos.x, m.startPos.y + 1, M, N * 2);
			show(m, array, M, N);
		}

	}

	for (int i = 0; i < M; i++)
	{
		delete[] array[i];
	}
	delete[] array;
	endTask(m);
}



/// <summary>
/// Создайте динамический массив, хранящий в первой строке имя, а во второй- телефон. 
/// Организуйте поиск по имени и по номеру телефона и возможность ввода и изменения данных.
/// </summary>
void task5(TaskStructure m) {
	Coordinate start = m.startPos;
	setCursorPosition(m.startPos);
	const int limitSymbol = 256;//Лимит символов для ввода пользователем
	int cur = 1; // Текущий элемент массива
	int countData  = 0; //Количество телефонных номеров сейчас в массиве
	char*** data = nullptr;
	addUser(data, countData, "Иванов", "123-456-789");
	addUser(data, countData, "Петров", "789-456-789");
	addUser(data, countData, "Сидоров", "123-321-879");
	Menu mainMenu;
	mainMenu.countMenu = 5;
	const char* elemMainMenu[] = {
		"Добавить",
		"Заменить текущий",
		"Удалить текущий",
		"Поиск",
		"Выход"
	};
	mainMenu.n = 0;
	
	
	mainMenu.elemMenu = new char*[mainMenu.countMenu];
	for (int i = 0; i < mainMenu.countMenu; i++) {
		mainMenu.elemMenu[i] = new char[strlen(elemMainMenu[i]) + 1];
		strcpy_s(mainMenu.elemMenu[i], strlen(elemMainMenu[i]) + 1, elemMainMenu[i]);
	}

	int enterMenu;
	
	while (true)
	
	{
		showData(data, countData, cur, m);
		mainMenu.startPos = m.startPos;
		enterMenu = scrollMenu(mainMenu);
		switch (enterMenu)
		{
		case 0: //Добавить
		{
			drawEmptyRectangle(m.startPos.x, m.startPos.y, mainMenu.countMenu + 1, 20);//Стираем меню
			setCursorPosition(m.startPos);
			std::cout << "Введите имя :";

			char name[limitSymbol];
			std::cin.getline(name, limitSymbol);
			nextLine(m.startPos);
			std::cout << "Введите телефон :";
			char phone[limitSymbol];
			std::cin.getline(phone, limitSymbol);
			addUser(data, countData, name, phone);
			m.startPos = start;
			drawEmptyRectangle(m.startPos.x, m.startPos.y, 100, 100);
			setCursorPosition(m.startPos);
		}
		break;
		case 1://Заменить текущий

		{
			drawEmptyRectangle(m.startPos.x, m.startPos.y, mainMenu.countMenu + 1, 20);//Стираем меню
			setCursorPosition(m.startPos);
			std::cout << "Введите имя :";

			char name[limitSymbol];
			std::cin.getline(name, limitSymbol);
			nextLine(m.startPos);
			std::cout << "Введите телефон :";
			char phone[limitSymbol];
			std::cin.getline(phone, limitSymbol);
			changeData(data, countData, cur, name, phone);
			m.startPos = start;
			drawEmptyRectangle(m.startPos.x, m.startPos.y, 100, 100);
			setCursorPosition(m.startPos);
		}
		break;
		case 2://Удалить текущий
			drawEmptyRectangle(m.startPos.x, m.startPos.y, mainMenu.countMenu + 1, 20);//Стираем меню
			delCurData(data, countData, cur);
			m.startPos = start;
			drawEmptyRectangle(m.startPos.x, m.startPos.y, 100, 100);
			setCursorPosition(m.startPos);
			break;
		case 3://Поиск
			drawEmptyRectangle(m.startPos.x, m.startPos.y, mainMenu.countMenu + 1, 20);//Стираем меню
			setCursorPosition(m.startPos);
			std::cout << "Введите строку поиска :";
			char any[limitSymbol];
			std::cin.getline(any, limitSymbol);
			{
				int res = searchData(data, countData, any);
				if (res != -1)
					cur = res;
			}
			m.startPos = start;
			drawEmptyRectangle(m.startPos.x, m.startPos.y, 100, 100);
			setCursorPosition(m.startPos);
			break;
		case 4://Выход
			drawEmptyRectangle(m.startPos.x, m.startPos.y, 100, 100);
			clearMenu(mainMenu);
			endTask(m);
			return;
			break;
		default:
			break;
		}
	}

}

/// <summary>
/// 
/// </summary>
void task6(TaskStructure m) {
	setCursorPosition(m.startPos);
	
	endTask(m);
}
/// <summary>
/// 
/// </summary>
void task7(TaskStructure m) {
	setCursorPosition(m.startPos);
	endTask(m);
}



/// <summary>
///
/// </summary>
void task8(TaskStructure m) {
	setCursorPosition(m.startPos);

	endTask(m);
}





int main()
{
	system("chcp 1251>null");
	gitPush("Задание 5: Работа 22 - готово");
	
	std::cout << textMatch("Ива", "иВан");

	startMenu();

	
}

