#include "Header.h"


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
void* get_cur(Mlist& lst) {
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
	std::cout << "\nLIST: |n";
	Mitem* c = lst.start;
	while (c)
	{
		if (c == lst.cur)
			std::cout << " [" << c->data << "] ";
		else
			std::cout << "'" << c->data << "'";
		c = c->next;
	}
}



void add_to_prev(Mlist& lst, char* data) {
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
void add_to_next(Mlist& lst, char* data) {
	char* newData = new char[strlen(data) + 1];
	strcpy_s(newData, strlen(data) + 1, data);
	Mitem* n = new Mitem;
	n->data = newData;
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
}
void add_to_start(Mlist& lst, char* data) {
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
}
void add_to_start(Mlist& lst, const char* data) {
	char* newData = new char[strlen(data) + 1];
	strcpy_s(newData, strlen(data) + 1, data);
	add_to_start(lst, newData);

}
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