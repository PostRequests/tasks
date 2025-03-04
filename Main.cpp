
#ifdef min
#undef min
#endif
#include <iostream>
#include "Mylib/Header.h"



/// <summary>
/*написать программу демонстрирующую работу двунаправленного списка.Реализовать следующий функционал двунаправленного списка :
• Перейти в начало списка
• Перейти в конец списка
• Перейти к следующему элементу
• Перейти к предыдущему элементу
• Добавить перед текущим элементом
• Добавить после текущего элемента
• Удалить текущий элемент
• Отчистить список(удалить все элементы)*/
/// </summary>
void task1(TaskStructure m) {
	const int limitSymbol = 256;//Лимит символов для ввода пользователем
	setCursorPosition(m.startPos);
	Coordinate start = m.startPos;
	Menu mainMenu;
	Mlist list;
	
	add_to_start(list, "Хлеб");
	add_to_start(list, "Сыр");
	add_to_start(list, "Молоко");
	add_to_start(list, "Сахар");
	//to_end(list);
	//cls_list(list);
	mainMenu.countMenu = 9;
	const char* elemMainMenu[] = {
		"Переходит в начало списка",
		"Переходим в конец списка",
		"Переходим к следующему элементу списка",
		"Переходим к предыдущему элементу списка",
		"Добавить перед текущим элементом",
		"Добавить после текущего элемента",
		"Удалить текущий элемент",
		"Отчистить список(удалить все элементы)",
		"Выход"
	};
	mainMenu.n = 0;


	mainMenu.elemMenu = new char* [mainMenu.countMenu];
	for (int i = 0; i < mainMenu.countMenu; i++) {
		mainMenu.elemMenu[i] = new char[strlen(elemMainMenu[i]) + 1];
		strcpy_s(mainMenu.elemMenu[i], strlen(elemMainMenu[i]) + 1, elemMainMenu[i]);
	}


	while (true)
	{
		setCursorPosition(m.startPos);
		show(list, m.startPos);
		mainMenu.startPos = m.startPos;
		mainMenu.n = scrollMenu(mainMenu);
		
		switch (mainMenu.n)
		{
		case 0: {//Переходит в начало списка
			m.startPos = start;
			//drawEmptyRectangle(m.startPos.x, m.startPos.y, 100, 100);
			to_start(list);
			
			break;
		}
		case 1: {//Переходим в конец списка
			m.startPos = start;
			to_end(list);
			break;
		}
		case 2: {//Переходим к следующему элементу списка
			m.startPos = start;
			to_next(list);
			break;
		}
		case 3: {// Переходим к предыдущему элементу списка
			m.startPos = start;
			to_prev(list);
			break;
		}
		case 4: {//Добавить перед текущим элементом
			drawEmptyRectangle(m.startPos.x, m.startPos.y, mainMenu.countMenu + 1, 50);//Стираем меню
			setCursorPosition(m.startPos);
			std::cout << "Введите элемент списка :";
			char any[limitSymbol];
			std::cin.getline(any, limitSymbol);
			//Без указателя очистить память под указатель невозможно)
			char* pAny = new char[strlen(any) + 1];
			strcpy_s(pAny, strlen(any) + 1, any);

			add_to_prev(list, pAny);
			m.startPos = start;
			drawEmptyRectangle(m.startPos.x, m.startPos.y, 100, 100);
			setCursorPosition(m.startPos);
			break;
		}
		case 5: {//Добавить после текущего элемента
			drawEmptyRectangle(m.startPos.x, m.startPos.y, mainMenu.countMenu + 1, 50);//Стираем меню
			setCursorPosition(m.startPos);
			std::cout << "Введите элемент списка :";
			char any[limitSymbol];
			std::cin.getline(any, limitSymbol);
			//Без указателя очистить память под указатель невозможно)
			char* pAny = new char[strlen(any) + 1];
			strcpy_s(pAny, strlen(any) + 1, any);
			add_to_next(list, pAny);
			m.startPos = start;
			drawEmptyRectangle(m.startPos.x, m.startPos.y, 100, 100);
			setCursorPosition(m.startPos);
			break;
		}
		case 6: {//Удалить текущий элемент
			del_cur(list);
			m.startPos = start;
			drawEmptyRectangle(m.startPos.x, m.startPos.y, 100, 100);
			setCursorPosition(m.startPos);
			break;
		}
		case 7: {//Отчистить список(удалить все элементы)
			cls_list(list);
			m.startPos = start;
			drawEmptyRectangle(m.startPos.x, m.startPos.y, 100, 100);
			setCursorPosition(m.startPos);
			break;
		}
		case 8: {//Выход
			drawEmptyRectangle(m.startPos.x, m.startPos.y, 100, 100);
			cls_list(list);
			clearMenu(mainMenu);
			endTask(m);
			return;
			break;
		}
		default:
			break;
		}
	}
	endTask(m);
}


/// <summary>
/// </summary>
void task2(TaskStructure m) {
	setCursorPosition(m.startPos);
	
	endTask(m);

}

/// <summary>

/// </summary>
void task3(TaskStructure m) {
	setCursorPosition(m.startPos);
	
	endTask(m);

}

/// <summary>

/// </summary>
void task4(TaskStructure m) {
	setCursorPosition(m.startPos);

	endTask(m);
}


/// <summary>
///
/// </summary>
void task5(TaskStructure m) {
	setCursorPosition(m.startPos);

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
	gitPush("Задание 1: Работа 23 - готово");
	

	startMenu();

	
}

