
#include "List2.h"
#include <iostream>

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
void add_to_prev(Mlist& lst, lBook* data) {
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
lBook* get_cur(Mlist& lst) {
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
void show(Mlist& lst , Coordinate& xy) {
	setCursorPosition(xy);
	Mitem* c = lst.start;
	while (c)
	{
		if (c == lst.cur)
			std::cout << "[" << (char*)c->data << "]";
		else
			std::cout << "'" << (char*)c->data << "'";
		c = c->next;
		xy.y++;
		setCursorPosition(xy);
	}
}
void show(Mlist& lst) {
	ColorANSI3b col;
	Mitem* c = lst.start;
	while (c)
	{
		//if (c == lst.cur)
			//std::cout << " -->";
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


//void add_to_next(Mlist& lst, void* data) {
//	char* newData = new char[strlen(data) + 1];
//	strcpy_s(newData, strlen(data) + 1, data);
//	Mitem* n = new Mitem;
//	n->data = newData;
//	if (!lst.start) {
//		lst.cur = n;
//		lst.end = n;
//		lst.start = n;
//	}
//	else {
//		n->prev = lst.cur;
//		n->next = lst.cur->next;
//
//		if (lst.cur->next) {
//			lst.cur->next->prev = n; 
//		}
//		else {
//			lst.end = n;
//		}
//
//		lst.cur->next = n; 
//	}
//}
//void add_to_start(Mlist& lst, void* data) {
//	Mitem* n = new Mitem;
//	n->data = data;
//	if (!lst.start) {
//		lst.cur = n;
//		lst.end = n;
//		lst.start = n;
//	}
//	else {
//		lst.start->prev = n;
//		n->next = lst.start;
//		lst.start = n;
//	}
//}

void del_cur(Mlist& lst) {
	if (!lst.cur) return;
	Mitem* Del = lst.cur;
	if (lst.cur->prev)
		lst.cur ->prev->next = lst.cur->next;
	else
		lst.start = lst.cur->next;
	if (lst.cur->next){
		lst.cur->next->prev = lst.cur->prev;
		lst.cur = lst.cur->next;
	}
	else{
		lst.end = lst.cur->prev;
		lst.cur = lst.end;
	}	
	delete[] Del->data;
	delete Del;
}

void cls_list(Mlist& lst) {
	
	while (lst.start) {
		Mitem* del = lst.start;
		char* i = (char*)del->data;
		lst.start = lst.start->next;
		delete[] del->data;
		delete del; 
	}
	lst.end = nullptr;
}