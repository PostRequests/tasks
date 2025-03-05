#include "menu.h"
#include <iostream>


void clearMenu(Menu& m) {
	for (int i = 0; i < m.countMenu; i++) {
		delete[] m.elemMenu[i];
	}
	delete[] m.elemMenu;
	m.elemMenu = nullptr;
}

void showItemMenu(Menu m) {
	ColorANSI3b color;
	setCursorPosition(m.startPos);
	for (int i = 0; i < m.countMenu; i++) {
		if (m.n == i) setColor(color.WhiteBG, color.BlackFG);
		m.startPos.y++;
		setCursorPosition(m.startPos);
		std::cout << m.elemMenu[i] << "  ";
		if (m.n == i) resetColor();
	}
	return;
}

int scrollMenu(Menu m) {
	showItemMenu(m);
	while (true)
	{
		char key = catchKey();
		if (key == 'w') {
			(m.n - 1 == -1) ? m.n = m.countMenu - 1 : m.n -= 1;
			showItemMenu(m);
		}
		else if (key == 's') {
			(m.n + 1 == m.countMenu) ? m.n = 0 : m.n += 1;
			showItemMenu(m);
		}
		else if (key == 13) {
			return m.n;
		}

	}
}