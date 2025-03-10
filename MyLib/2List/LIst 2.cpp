
#include "List2.h"
#include "../../Pointer.h"
#include "../text/text.h"
#include <iostream>

void add_to_prev(Mlist& lst, LBook* data) {
	lst.count++;
	Mitem* n = new Mitem;
	n->data = data;

	if (!lst.start) {
		lst.cur = n;
		lst.end = n;
		lst.start = n;
	}
	else if (lst.cur == lst.start) {
		n->next = lst.start;
		lst.start->prev = n;
		lst.start = n;
	}
	else {
		n->next = lst.cur;
		n->prev = lst.cur->prev;
		lst.cur->prev->next = n;
		lst.cur->prev = n;
	}
}
void to_start(Mlist& lst) {
	lst.cur = lst.start;
}
void to_end(Mlist& lst) {
	lst.cur = lst.end;
}
void to_next(Mlist& lst) {
	if (lst.cur)
		if (lst.cur->next != nullptr)
			lst.cur = lst.cur->next;
}
void to_prev(Mlist& lst) {
	if (lst.cur)
		if (lst.cur->prev != nullptr)
			lst.cur = lst.cur->prev;
}
LBook* get_cur(Mlist& lst) {
	if (lst.cur)
		return lst.cur->data;
	return nullptr;
}
bool is_end(Mlist& lst) {
	return !lst.cur->next;
}
bool is_start(Mlist& lst) {
	return !lst.cur->prev;
}
void show(Mlist& lst) {
	ColorANSI3b col;
	Mitem* c = lst.start;
	Coordinate cSize = getConsoleSize();
	drawEmptyRectangle(0, 8, (lst.count + 1) * 3, cSize.x - 27, 0);
	setCursorPosition(0, 8);
	while (c)
	{
		if (c == lst.cur)
			std::cout << " -->|";
		std::cout << "\t" << c->data->title;
		setColor(col.RedFG);
		std::cout << "\n\t Автор: ";
		resetColor();
		std::cout << c->data->author;
		setColor(col.BlueFG);
		std::cout << " Издательство: ";
		resetColor();
		std::cout << c->data->publishing;
		setColor(col.GreenFG);
		std::cout << " Жанр: ";
		resetColor();
		std::cout << c->data->genre << std::endl;
		std::cout << "\t----------------------------------------------\n";
		c = c->next;
	}
}
void del_cur(Mlist& lst) {
	if (!lst.cur) return;
	lst.count--;
	Mitem* Del = lst.cur;
	if (lst.cur->prev) {
		lst.cur->prev->next = lst.cur->next;
	}
	else {
		lst.start = lst.cur->next;
	}
	if (lst.cur->next) {
		lst.cur->next->prev = lst.cur->prev;
		lst.cur = lst.cur->next;
	}
	else {
		lst.end = lst.cur->prev;
		lst.cur = lst.end;
	}
	if (Del->data) {
		delete[] Del->data->author;
		delete[] Del->data->genre;
		delete[] Del->data->publishing;
		delete[] Del->data->title;
		delete Del->data;
	}
	delete Del;
}
void cls_list(Mlist& lst) {

	while (lst.start) {
		Mitem* del = lst.start;
		lst.start = lst.start->next;
		delete[] del->data->author;
		delete[] del->data->genre;
		delete[] del->data->publishing;
		delete[] del->data->title;
		delete[] del->data;
		delete del;
	}
	lst.end = nullptr;
}
void add_to_start(Mlist& lst, LBook* data) {
	Mitem* n = new Mitem;
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
	lst.count++;
}
void add_to_next(Mlist& lst, LBook* data) {
	Mitem* n = new Mitem;
	n->data = data;
	if (!lst.start) {
		lst.cur = n;
		lst.end = n;
		lst.start = n;
	}
	else {
		n->prev = lst.cur;
		n->next = lst.cur->next;

		if (lst.cur->next) {
			lst.cur->next->prev = n; 
		}
		else {
			lst.end = n;
		}
		lst.cur->next = n; 
	}
	lst.count++;
}
void go_to(Mlist& lst, int index) {
	lst.cur = lst.start;

	while (index != 0)
	{
		to_next(lst);
		index--;
	}
	
}
bool get_search(Mlist& lst, int numIndex, char* what) {
	to_start(lst);
	
	do
	{
		char* fields[] = { lst.cur->data->title, lst.cur->data->author, lst.cur->data->publishing, lst.cur->data->genre };
		char* a = fields[numIndex];
		if (textMatch(what, fields[numIndex])) return true;
		to_next(lst);
	}while (lst.cur->next);
	to_start(lst);
	return false;
}
void edit_cur(Mlist& lst,int numBook, int numIndex, char* text) {
	go_to(lst, numBook);
	char* fields[] = { lst.cur->data->title, lst.cur->data->author, lst.cur->data->publishing, lst.cur->data->genre };
	strcpy_s(fields[numIndex], strlen(text) + 1, text);
}
bool textMatch(Mitem* a, Mitem* b, int index) {
	if (!a->data || !b->data) return false; 
	char* fieldsA[] = { a->data->title, a->data->author, a->data->publishing, a->data->genre };
	char* fieldsB[] = { b->data->title, b->data->author, b->data->publishing, b->data->genre };
	for (int i = 0; i < strlen(fieldsA[index]); i++) {
		char lowA = toLowerRus(fieldsA[index][i])* -1;
		char lowB = toLowerRus(fieldsB[index][i])*-1;
		if (lowA == lowB)
			continue;
		else if (lowA < lowB)
			return true;
		else return false;
	}
}
void swap(Mitem* a, Mitem* b) {
	LBook* tempData = a->data;
	a->data = b->data;
	b->data = tempData;
}
void sort_list(Mlist& lst, int index) {
	if (lst.count < 2) return;
	Mitem* c;
	bool swapped;
	do {
		swapped = false;
		 c = lst.start;

		while (c->next) {
			if (textMatch(c, c->next, index)) {
				swap(c, c->next); 
				swapped = true;
			}
			c = c->next;
		}
	} while (swapped);
}