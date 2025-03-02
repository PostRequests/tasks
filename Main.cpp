
#ifdef min
#undef min
#endif
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
	std::cout << "В данном тексте символ \"" << symbol<< "\" встречается " << getCountChar(a, symbol) << " раз(a)";
	endTask(m);
}
/// <summary>
/// Пользователь вводит строку. Определить количество букв, количество цифр и количество остальных символов, присутствующих в строке.
/// </summary>
void task6(TaskStructure m) {
	setCursorPosition(m.startPos);
	std::cout << "Введите предложение :";
	nextLine(m.startPos);
	const int limitSymbol = 200;
	char str[limitSymbol];
	std::cin.getline(str, limitSymbol);
	nextLine(m.startPos);
	int cpm = 0; //количество пунктуационных знаков
	int cl = 0; //количество букв
	int cn = 0; //количество цифр
	int co = 0; //количество пробелов, переносов строк, табуляций
	for (int i = 0 ; str[i]; i++) {
		if ((str[i] >= 'А' and str[i] <= 'я') or (str[i] >= 'A' and str[i] <= 'z')) cl++;
		else if (str[i] >= '0' and str[i] <= '9')cn++;
		else if (str[i] == ' ' or str[i] == '\t' or str[i] == '\n')co++;
		else cpm++;
	}
	nextLine(m.startPos);
	std::cout << "В строке пунктуационных знаков = " << cpm << "  букв = " << cl << " цифр = " << cn 
		<< " пробелов = " << co;
	endTask(m);
}
/// <summary>
/// Подсчитать количество слов во введенном предложении.
/// </summary>
void task7(TaskStructure m) {
	setCursorPosition(m.startPos);
	std::cout << "Введите предложение :";
	nextLine(m.startPos);
	const int limitSymbol = 200;
	char str[limitSymbol];
	std::cin.getline(str, limitSymbol);
	nextLine(m.startPos);
	std::cout << "В вашем предложении " << getCountWords(str) << " слов(а)";;
	endTask(m);
}



/// <summary>
/// Дана строка символов. Необходимо проверить является ли эта строка палиндромом.
/// </summary>
void task8(TaskStructure m) {
	setCursorPosition(m.startPos);
	std::cout << "Введите предложение :";
	nextLine(m.startPos);
	const int limitSymbol = 50;
	char str[limitSymbol];
	std::cin >> str;
	nextLine(m.startPos);
	std::cout << "Ваша строка" << ((isPalindrome(str)) ? " " : " не ") << "является палиндромом";

	endTask(m);
}

/*Stack*/
struct mstack {
	int data;
	mstack* prev = nullptr;
};


void push(mstack &s, int data)
{
	mstack* n = new mstack;
	n->data = data;
	n->prev = s.prev;
	s.prev = n;
}
int heap(mstack& s) {
	if (s.prev == 0)
		return -1;
	return s.prev->data;
}

int pop(mstack& s) {
	int r = -1;
	if (s.prev != 0) {
		mstack* t = s.prev;
		s.prev = s.prev->prev;
		r = t->data;
		delete t;
	}
	return r;
}



void show(mstack& s) {
	mstack* t = s.prev;
	while (t!= 0) {
		std::cout << "\n" << t->data;
		t = t -> prev;
	}
}
/*S*/

/*mlist*/
struct mitem{
	int data;
	mitem* next = nullptr;
	mitem* prev = nullptr;
};

struct mlist {
	mitem* start = nullptr;
	mitem* end = nullptr;
	mitem* cur = nullptr;
};

void to_start(mlist& lst) {
	lst.cur = lst.start;

}
void to_end(mlist& lst) {
	lst.cur = lst.end;
}

void to_next(mlist& lst) {
	if (lst.cur)
		if (lst.cur->next != nullptr)
			lst.cur = lst.cur->next;
}
void to_prev(mlist& lst) {
	if (lst.cur)
		if (lst.cur->prev != nullptr)
			lst.cur = lst.cur->prev;
}
int get_cur(mlist& lst) {
	if (lst.cur)
		return lst.cur->data;
	return -1;
}
bool is_end(mlist& lst) {
	if (lst.cur->next)
		return false;
	return true;
	return !lst.cur->next;
}
bool is_start(mlist& lst) {
	return !lst.cur->prev;
}
void show(mlist& lst) {
	std::cout << "\nLIST: |n";
	mitem* c = lst.start;
	while (c)
	{
		if (c == lst.cur)
			std::cout << " [" << c->data << "] ";
		else
			std::cout << "'" << c->data << "'";
		c = c->next;
	}
}
void add_to_starrt(mlist& lst, int data) {
	mitem* n = new mitem;
	n->data = data;
	if (!lst.start) {
		lst.cur = n;
		lst.end = n;
		lst.start = n;
	}
	else {
		lst.start->prev = n;
		n->next = lst.start;
		lst.start = n;
	}
}
/*L*/

int main()
{
	gitPush("Работа на уроке");//Задание 4 работа 21: Готово
	mlist lst;
	int s;
	do
	{
		std::cout << "\n STACK";
		show(lst);
		std::cout << "\n ------------------";
		std::cout << "\n1 start";
		std::cout << "\n2 end";
		std::cout << "\n3 next";
		std::cout << "\n4 prev";
		std::cout << "\n5 curr";
		std::cout << "\n6 add to start";
		std::cout << "\n your turn \n";
		std::cin >> s;
		int t;
		switch (s)
		{
		case 1:  ;
			to_start(lst);
			break;
		case 2:
			to_end(lst);

			break;
		case 3:
			to_next(lst);
		case 4:
			to_prev(lst);
		case 5:
			std::cout << "\nCURR=" << get_cur(lst);
			break;
		case 6:
			std::cout << "\Input digit";
			{
				int data;
				std::cin >> data;
				add_to_starrt(lst, data);
			}
			break;
		default:
			break;
		}
	} while (s != 0);
	
	
	
	
	//startMenu();

	
}

