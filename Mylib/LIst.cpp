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
int get_cur(Mlist& lst) {
	if (lst.cur)
		return lst.cur->data;
	return -1;
}
bool is_end(Mlist& lst) {
	if (lst.cur->next)
		return false;
	return true;
	return !lst.cur->next;
}
bool is_start(Mlist& lst) {
	return !lst.cur->prev;
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
void add_to_start(Mlist& lst, int data) {
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