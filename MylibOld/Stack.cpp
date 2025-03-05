#include "Header.h"

void push(Mstack& s, int data)
{
	Mstack* n = new Mstack;
	n->data = data;
	n->prev = s.prev;
	s.prev = n;
}
int heap(Mstack& s) {
	if (s.prev == 0)
		return -1;
	return s.prev->data;
}

int pop(Mstack& s) {
	int r = -1;
	if (s.prev != 0) {
		Mstack* t = s.prev;
		s.prev = s.prev->prev;
		r = t->data;
		delete t;
	}
	return r;
}



void show(Mstack& s) {
	Mstack* t = s.prev;
	while (t != 0) {
		std::cout << "\n" << t->data;
		t = t->prev;
	}
}