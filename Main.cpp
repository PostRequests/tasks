#include <iostream>
#include <Windows.h>
#include "MyLib/console/console.h"
#include "MyLib/menu/menu.h"
#include "MyLib/git hub/git.h"
#include "MyLib/text/text.h"
#include "Pointer.h"
//Создает основное меню
Menu getMainMenu();
//Создает основное меню библиотеки
Menu getLibMenu();
/// <summary>
/// создаем меню поиска
/// </summary>
/// <param name="menu">необходимо, для определения координат от родителя</param>
/// <param name="numPer">номер строки родителя элемента меню</param>
/// <returns></returns>
Menu getSearchMenu(Menu menu, int numPer);
/// <summary>
/// Создаем меню сортировки
/// </summary>
/// <param name="menu">необходимо, для определения координат от родителя</param>
/// <param name="numPer">номер строки родителя элемента меню</param>
/// <returns></returns>
Menu getSortMenu(Menu menu, int numPer);
/// <summary>
/// Формирует начальный архив книг
/// </summary>
/// <param name="count">Количество книг, которые получились</param>
/// <returns></returns>
char*** createPointer(int& count);



int main()
{
	system("chcp 1251>null");
	gitPush("Наполовину сделал половину ДЗ № 24");
	int count = 0;
	char*** books = createPointer(count);
	delBook(books, count, 4);
	showBook(books, count);
	/////
	Menu m = getMainMenu();
	Menu mLib = getLibMenu();
	Menu mSearch = getSearchMenu(mLib, 4);
	Menu mSort = getSortMenu(mLib, 5);
	getShowMenu(m);
	while (true)
	{
		mLib.n = getShowMenu(mLib, false);
		 
		if (mLib.n == 4)
			getShowMenu(mSearch);
		else if(mLib.n == 5)
			getShowMenu(mSort);
	}

	clearMenu(mSearch);
	clearMenu(mLib);
	clearMenu(m);
}



Menu getMainMenu() {
	ColorANSI3b c;
	Coordinate cSize = getConsoleSize(); //Максимальный размер консоли
	//Формируем элементы меню
	char headMenu[] = "Домашняя работа № 24";
	const char* item[] = {
		"структура книг динамическая",
		"структура книг: двунаправленный список",
		"Выход",
	};
	const char* textInfo[] = {
		"Разработайте программу «Библиотека». Создайте структуру «Книга» (название, автор, издательство, жанр). Создайте динамический массив для хранения книг. Реализуйте для него следующие возможности:\n• Добавить книгу\n• Удалить книгу\n• Редактировать книгу\n• Печать всех книг\n• Поиск книг по автору\n• Поиск книги по названию\n• Сортировка массива по названию книг\n• Сортировка массива по автору\n• Сортировка массива по издательству",
		"Разработайте программу «Библиотека». Создайте структуру «Книга» (название, автор, издательство, жанр). Создайте двунаправленный список для хранения книг. Реализуйте для него следующие возможности:\n• Добавить книгу\n• Удалить книгу\n• Редактировать книгу\n• Печать всех книг\n• Поиск книг по автору\n• Поиск книги по названию\n• Сортировка массива по названию книг\n• Сортировка массива по автору\n• Сортировка массива по издательству",
		"Выход",
	};
	Coordinate startMenu = { 1,  cSize.y / 3 };///cSize.y/3
	int countMenu = sizeof(item) / sizeof(item[0]);
	menuColor colorMenu = { c.BlueBG,c.WhiteFG,c.MagentaFG,c.BlackFG, c.RedBG };
	Menu m;
	constructMenu(m, startMenu, item, countMenu, colorMenu, 1, 'c', true);

	//Формируем шапку меню
	menuColor colorHead = { c.RedBG,c.BlackFG, c.YellowFG };
	Coordinate startHead = { 1,1 };
	int s = strlen(headMenu) / 2;
	int indent = (cSize.x / 2) - s - 2;
	int marginHead[] = { 0,indent,0,indent + 1 };//{top, left, down, right}
	

	//Формируем информацию об элементах меню
	Coordinate start{ 1, cSize.y - 12 };
	Coordinate finish{ cSize.x - 2, cSize.y };
	menuColor colorInfo{ c.BlackBG, c.WhiteFG, c.YellowFG };
	int sInfo = sizeof(textInfo) / sizeof(textInfo[0]);

	if (countMenu != sInfo) {
		std::cout << "Возникла ошибка, не совпадение количества элементов" << std::endl;
		abort();
		//Остановка программы в случае, если элементы меню не равны количеству элементов описания
	}
	addHeadMenu(m, startHead, headMenu, marginHead, true, colorHead);
	addInfoMenu(m, start, finish, textInfo, true, colorInfo);
	return m;
}

Menu getLibMenu() {
	
	ColorANSI3b c;
	Coordinate cSize = getConsoleSize(); //Максимальный размер консоли
	//Формируем элементы меню
	char headMenu[] = "Динамический массив хранения книг";
	const char* item[] = {
		"Печать всех книг",
		"Добавить книгу",
		"Удалить книгу",
		"Редактировать книгу",
		"Поиск книг",
		"Сортировка",
		"Назад"
	};
	int countMenu = sizeof(item) / sizeof(item[0]);
	int mWidth = strMaxLen(item, countMenu) + 4; //Ширина меню
	Coordinate startMenu = { cSize.x - mWidth,  4};
	menuColor colorMenu = { c.CyanBG,c.WhiteFG,c.MagentaFG,c.BlackFG, c.RedBG };
	Menu m;
	constructMenu(m, startMenu, item, countMenu, colorMenu, 1, 'r', true);

	//Формируем шапку меню
	menuColor colorHead = { c.CyanBG,c.BlackFG, c.MagentaFG };
	Coordinate startHead = { 1,1 };//Координаты начала рисования названия меню
	int s = strlen(headMenu) / 2;
	int indent = (cSize.x / 2) - s - 2;
	int marginHead[] = { 0,indent,0,indent };//{top, left, down, right}
	addHeadMenu(m, startHead, headMenu, marginHead, true, colorHead);
	return m;
}

Menu getSearchMenu(Menu menu, int numPer) {

	ColorANSI3b c;
	Coordinate cSize = getConsoleSize(); //Максимальный размер консоли
	//Формируем элементы меню
	char headMenu[] = "Динамический массив хранения книг";
	const char* item[] = {
		"По автору",
		"По названию",
	};
	int countMenu = sizeof(item) / sizeof(item[0]);
	int mWidth = strMaxLen(item, countMenu) + 4; //Ширина меню
	//Пока указываем произвольное значение начала меню
	//Потом определим куда его ставить
	Coordinate startMenu; 
	//ставим координаты меню относительно родителя
	startMenu.y = 4 + (numPer * (menu.lineSkip + 1));
	
	menuColor colorMenu = { c.CyanBG,c.WhiteFG,c.MagentaFG,c.BlackFG, c.RedBG };

	Menu m;
	constructMenu(m, startMenu, item, countMenu, colorMenu, 1, 'r', true);
	m.start.x = menu.start.x - m.width;

	return m;
}

Menu getSortMenu(Menu menu, int numPer) {

	ColorANSI3b c;
	Coordinate cSize = getConsoleSize(); //Максимальный размер консоли
	//Формируем элементы меню
	char headMenu[] = "Динамический массив хранения книг";
	const char* item[] = {
		"По названию",
		"По автору",
		"По издательству"
	};
	int countMenu = sizeof(item) / sizeof(item[0]);
	int mWidth = strMaxLen(item, countMenu) + 4; //Ширина меню
	//Пока указываем произвольное значение начала меню
	//Потом определим куда его ставить
	Coordinate startMenu;
	//ставим координаты меню относительно родителя
	startMenu.y = 4 + (numPer * (menu.lineSkip + 1));

	menuColor colorMenu = { c.CyanBG,c.WhiteFG,c.MagentaFG,c.BlackFG, c.RedBG };

	Menu m;
	constructMenu(m, startMenu, item, countMenu, colorMenu, 1, 'r', true);
	m.start.x = menu.start.x - m.width;

	return m;
}

char*** createPointer(int & count) {
	//подготавливаем 5 начальных книг
	char little_prince[][100] = {
	   "Маленький принц",       //Название
	   "Антуан де Сент-Экзюпери", //Автор
	   "Reynal & Hitchcock",     //Издательство
	   "Философская сказка"      //Жанр
	};

	char ulyss[][100] = {
		"Улисс",                  
		"Джеймс Джойс",           
		"Shakespeare and Company", 
		"Модернистский роман"     
	};

	char atlas_shrugged[][100] = {
		"Атлант расправил плечи", 
		"Айн Рэнд",               
		"Random House",           
		"Философский роман, антиутопия" 
	};

	char shadow_of_the_wind[][100] = {
		"Тень ветра",             
		"Карлос Руис Сафон",      
		"Planeta",               
		"Мистический роман, исторический детектив" 
	};

	char hunger_games[][100] = {
		"Голодные игры",         
		"Сьюзен Коллинз",        
		"Scholastic",            
		"Научная фантастика, антиутопия"
	};
	char*** books = nullptr;
	addBook(books, count, hunger_games);
	addBook(books, count, shadow_of_the_wind);
	addBook(books, count, atlas_shrugged);
	addBook(books, count, ulyss);
	addBook(books, count, little_prince);
	return books;
}
