

#include <iostream>
#include "Mylib/Header.h"


/// <summary>
/// Написать функцию, которая удаляет из строки символ с заданным номером.
/// </summary>
void task1(TaskStructure m) {
	
	setCursorPosition(m.startPos);
	std::cout << "Дана строка :";
	nextLine(m.startPos, 2);
	char* f = newChars("Привет мир");
	int sizeF = getCharLen(f); //Размер будущего массива
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
	deleteSymbol(f, N);
	std::cout << f;
	delete[] f;

	endTask(m);
}
/// <summary>
/// Написать функцию, которая удаляет из строки все вхождения в нее заданного символа.
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
/// Написать функцию, которая вставляет в строку в указанную позицию заданный символ.
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
	std::cout << "Дан текст :";
	nextLine(m.startPos);
	char a[] = {"\tВыхожу один я на дорогу;\n\tСквозь туман кремнистый путь блестит.\n\tНочь тиха. Пустыня внемлет Богу,\n\tИ звезда с звездою говорит."};
	showWrappedText(m, a);
	nextLine(m.startPos);
	std::cout << "Какой символ ищем?:";
	char symbol;
	std::cin >> symbol;
	nextLine(m.startPos);
	std::cout << "В данном тексте символ \"" << symbol<< "\" встречается " << getCountChar(a, symbol) << " раз";
	endTask(m);
}
/// <summary>
/// Пользователь вводит строку. Определить количество букв, количество цифр и количество остальных символов, присутствующих в строке.
/// </summary>
void task6(TaskStructure m) {
	setCursorPosition(m.startPos);
	
	endTask(m);
}
/// <summary>
/// Подсчитать количество слов во введенном предложении.
/// </summary>
void task7(TaskStructure m) {
	setCursorPosition(m.startPos);

	endTask(m);
}
/// <summary>
/// Дана строка символов. Необходимо проверить является ли эта строка палиндромом.
/// </summary>
void task8(TaskStructure m) {
	setCursorPosition(m.startPos);

	endTask(m);
}



int main()
{
	system("chcp 1251 > nul");
	
	/*char a[] = "\tНочь, улица, фонарь, аптека,\n\tБессмысленный и тусклый свет.\n\tЖиви еще хоть четверть века —\n\tВсё будет так.Исхода нет.\n\n\tУмрешь — начнешь опять сначала,\n\tИ повторится всё, как встарь :\n\tНочь, ледяная рябь канала,\n\tАптека, улица, фонарь...";
	std::cout << a;
	std::cout << getCountChar(a, ',')*/;
	gitPush("Задание 5 работа 21: Готово");//Задание 4 работа 21: Готово
	
	startMenu();

	
}

