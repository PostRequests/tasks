
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
	std::cout << "Дан текст :";
	nextLine(m.startPos);
	int sizeF; //Размер будущего массива
	char* f = newChars("\tШепот, робкое дыханье,\n\tТрели соловья,\n\tСеребро и колыханье\n\tСонного ручья...");
	nextLine(m.startPos);
	showWrappedText(m, f);
	nextLine(m.startPos, 2);
	std::cout << "Укажите символ который нужно удалить :";
	char symbol;
	std::cin >> symbol;

	nextLine(m.startPos, 2);
	std::cout << "Теперь строка выглядит вот так :";
	deleteCharsInText(f, symbol);
	nextLine(m.startPos);
	showWrappedText(m, f);
	delete[] f;
	
	endTask(m);

}

/// <summary>
/// Дана матрица порядка MxN (M строк, N столбцов). 
/// Необходимо заполнить ее значениями и написать функцию, 
/// осуществляющую циклический сдвиг строк и/или столбцов массива указанное количество раз и в указанную сторону.
/// </summary>
void task3(TaskStructure m) {
	setCursorPosition(m.startPos);
	std::cout << "Дан текст :";
	nextLine(m.startPos);
	
	char* f = newChars("Я помню чудное ***,\nПередо мной явилась ты,\nКак мимолётное виденье,\nКак гений чистой красоты.");
	int sizeF = getCharLen(f); 
	nextLine(m.startPos);
	showWrappedText(m, f);
	nextLine(m.startPos, 2);
	std::cout << "Угадайте что зашифровано под *** слово:";
	const int limitSymbol = 100;
	char str[limitSymbol];
	
	std::cin.getline(str, limitSymbol);
	deleteCharsInText(f, '*');
	nextLine(m.startPos);

	std::cout << "Подставляем значение и получаем :";
	addStr(f, sizeF, str, 15);//Функция для решения задачи
	nextLine(m.startPos, 2);
	showWrappedText(m, f);
	delete[] f;
	endTask(m);

}
/// <summary>
///Транспонирование матрицы – это операция,
/// после которой столбцы прежней матрицы становятся строками, а строки столбцами.
/// Напишите функцию транспонирования матрицы.
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
/// Создайте динамический массив, хранящий в первой строке имя, а во второй- телефон. 
/// Организуйте поиск по имени и по номеру телефона и возможность ввода и изменения данных.
/// </summary>
void task5(TaskStructure m) {
	setCursorPosition(m.startPos);
	std::cout << "Дан текст :";
	nextLine(m.startPos);
	char a[] = {"\tВыхожу один я на дорогу;\n\tСквозь туман кремнистый путь блестит.\n\tНочь тиха. Пустыня внемлет Богу,\n\tИ звезда с звездою говорит."};
	showWrappedText(m, a);
	nextLine(m.startPos);
	std::cout << "Какой символ ищем?:";
	char symbol;
	std::cin >> symbol;
	nextLine(m.startPos);
	std::cout << "В данном тексте символ \"" << symbol<< "\" встречается " << getCountChar(a, symbol) << " раз(a)";
	endTask(m);
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
	gitPush("Задание 1: Работа 22 - готово");//Задание 4 работа 21: Готово
	
	
	
	startMenu();

	
}

