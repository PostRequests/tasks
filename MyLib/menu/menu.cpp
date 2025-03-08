#include "menu.h"
#include <iostream>


void clearMenu(Menu& m) {
	for (int i = 0; i < m.count; i++) {
		delete[] m.item[i];
	}
	delete[] m.item;
	m.item = nullptr;
	if (m.info.enable) {
		for (int i = 0; i < m.count; i++) {
			delete[] m.info.text[i];
		}
		delete m.info.text;
		m.info.text = nullptr;
	}
	if (m.head.enable) {
		delete[] m.head.text;
		m.head.text = nullptr;
	}
}
//������ ������� ������� �������� ����
void setItemColor(int color1, int color2) {
	if (color1)
		((color2) ? setColor(color1, color2) : setColor(color1));
	else if (color2)
		setColor(color2);
	else resetColor();
}
//�������������� ���������� ������� ����
void redrawItem(Menu m) {
	if (m.border) (m.start.x++, m.start.y++);
	m.start.y += (m.n) * (m.lineSkip + 1);
	setCursorPosition(m.start);
	std::cout << m.item[m.n];
	setCursorPosition(0, 0);
}
/// <summary>
/// �������� �������� ���� �� ������
/// </summary>
/// <param name="m">��������� ����</param>
void showItemMenu(Menu m) {
	m.visible = true;
	if (m.border) {
		m.finish = { m.start.x + m.width - 1,
							m.start.y + m.height - 1 };
		setItemColor(m.color.BG, m.color.borderFG);
		drawFillRectangle(m.start, m.finish);
		m.start.x++;
		m.start.y++;
	}
	Coordinate  temp = m.start;
	setItemColor(m.color.BG, m.color.FG);
	setCursorPosition(temp);
	for (int i = 0; i < m.count; i++) {
		setCursorPosition(temp);
		std::cout << m.item[i];
		temp.y += 1 * (m.lineSkip + 1);
	}
	if (m.lineSkip) { //����������� ������� ����� �����, ���� �������
		setColor(m.color.borderFG);
		temp = m.start;
		for (int i = 0; i < m.count - 1; i++)
		{
			temp.y++; //���������� ������������ ������� ����
			setCursorPosition(temp);
			for (int j = 0; j < m.lineSkip; j++)
			{
				for (int k = 0; k < m.width - ((m.border)?2:0); k++)
					std::cout << '-';
				temp.y++;
			}
		}
	}
	setItemColor(m.color.hiBG, m.color.hiFG);
	m.start.y += (m.n) * (m.lineSkip + 1);
	setCursorPosition(m.start);
	std::cout << m.item[m.n];
	setCursorPosition(0, 0);
	resetColor();
}



void addHeadMenu(Menu& m, Coordinate start, char* head, int margin[4], bool border, menuColor color) {
	Head &H = m.head; //��� ���������� ������

	//���� �� ������ �������� �������, ����� ������� �� ��������� ����
	if (color.BG) H.color = color; 
	else H.color = m.color;

	H.text = new char[(strlen(head) + 1)];//������� ������
	strcpy_s(H.text, strlen(head) + 1, head);//������� ����������
	H.enable = true;
	H.start = start;
	H.inTop = margin[0];
	H.inLeft = margin[1];
	H.inDown = margin[2];
	H.inRight = margin[3];
	H.border = border;
	H.width = strlen(head) + H.inLeft + H.inRight + ((border) ? 2 : 0);
	H.height = 1 + H.inTop + H.inDown + ((border) ? 2 : 0);
	H.finish = { H.start.x + H.width - 1,
							H.start.y + H.height - 1 };
}

void addInfoMenu(Menu& m, Coordinate start, Coordinate finish, const char** textInfo, bool border, menuColor color) {
	Info& I = m.info;//��� ���������� ������

	//���� �� ������ �������� �������, ����� ������� �� ��������� ����
	if (color.BG) m.info.color = color;
	else m.info.color = m.color;

	I.enable = true;
	I.start = start;
	I.finish = finish;
	I.height = finish.y - start.y - ((border) ? 2 : 0);
	I.width = finish.x - start.x - ((border) ? 2 : 0);
	I.text = new char* [m.count];
	for (int i = 0; i < m.count; i++) {
		//�������� ������ ��� �������� ���� � �������� ����������
		I.text[i] = new char[strlen(textInfo[i]) + 1]; 
		strcpy_s(I.text[i], strlen(textInfo[i]) + 1, textInfo[i]);
	}
}

void clsMenu(Menu &m) {
	drawEmptyRectangle(m.start.x, m.start.y, m.height, m.width);
	setCursorPosition(1, 1);
	m.visible = false;
	m.n = 0;
}


void showHeadMenu(Head h) {
	setCursorPosition(h.start);
	if (h.border) {//������ �����, ���� ��� ����
		setItemColor(h.color.BG, h.color.borderFG);
		drawFillRectangle(h.start, h.finish);
		h.start.x++;
		h.start.y++;
		h.finish.x--;
		h.finish.y--;
	}
	if (h.color.BG)//�������� ���������� ������� ������ ����
		drawEmptyRectangle(h.start, h.finish, h.color.BG);
	setCursorPosition(h.start.x + h.inLeft,
		h.start.y + h.inTop);
	setItemColor(h.color.BG, h.color.FG);
	std::cout << h.text;

}
int getLengthNextWord(char* t) {
	int len = 0; // ����������� ������ ����� �� ������� ��� ����� ������
	for (; *t && *t != ' '; len++, t++);
	return len;
}

void showIfoMenu(Menu m) {
	setItemColor(m.info.color.BG, m.info.color.FG);
	setCursorPosition(m.info.start);
	if (m.head.border) {//������ �����, ���� ��� ����
		setItemColor(m.info.color.BG, m.info.color.borderFG);
		drawFillRectangle(m.info.start, m.info.finish);
		m.info.start.y++;
		m.info.start.x++;
		m.info.finish.y--;
		m.info.finish.x--;
	}
	drawEmptyRectangle(m.info.start, m.info.finish, m.info.color.BG);
	Coordinate s = m.info.start;
	setCursorPosition(m.info.start);
	char* pt = m.info.text[m.n];
	int lineBreaks = 0; //���������� ��������� ������
	int currentLineLength = 0;// ���������� ��� �������������� �������� � ������� ������
	while (*pt)
	{
		int len = getLengthNextWord(pt);
		currentLineLength += len;
		if (currentLineLength < m.info.width) {
			for (int i = 0; i < len; i++)
				if (*pt == '\n') {
					lineBreaks++;
					currentLineLength = 0;
					setCursorPosition(s.x, s.y + lineBreaks);
					pt++;
				}
				else
					std::cout << *pt++;
			while (*pt == ' ') {
				currentLineLength++;
				std::cout << *pt++;
			}
		}
		else {
			lineBreaks++;
			currentLineLength = 0;
			setCursorPosition(s.x, s.y + lineBreaks);
		}
	}
	resetColor();
}

void clsHead(Menu &m) {
	drawEmptyRectangle(m.head.start, m.head.finish, 0);
	m.head.visible = false;
}
void clsInfo(Menu &m) {
	drawEmptyRectangle(m.info.start, m.info.finish, 0);
	m.info.visible = false;
}

int getShowMenu(Menu &m, bool closeEnd) {
	if (!m.visible) {
		showItemMenu(m);
		m.visible = true;
	}
		
	if (m.head.enable and !m.head.visible) {
		showHeadMenu(m.head); //���������� ���������, ���� ����
		m.head.visible = true;
	}
		
	if (m.info.enable and !m.info.visible) {
		showIfoMenu(m);//���������� ����������, ���� ����
		m.info.visible = true;
	}
		
	//if (m.border) {	m.start.x++;m.start.y++; }
	while (true){
		char key = catchKey();
		if (key == 'w' or key == 's') {
			//����������� ������� ������� � ����������� ����
			setItemColor(m.color.BG, m.color.FG);
			redrawItem(m);
			//����������, ��� ��������� ����� ����������� ��������
			if (key == 'w') (m.n - 1 == -1) ? m.n = m.count - 1 : m.n -= 1;
			else if (key == 's') (m.n + 1 == m.count) ? m.n = 0 : m.n += 1;
			//������������� ���������� �������
			setItemColor(m.color.hiBG, m.color.hiFG);
			redrawItem(m);
			//���� � ���� ���� ����������, �� �������������� � ��
			if (m.info.enable) showIfoMenu(m);
		}
		else if (key == 13) {
			resetColor();
			if (closeEnd) {
				clsMenu(m);
				if (m.head.enable) clsHead(m);
				if (m.info.enable) clsInfo(m);
			}
			setCursorPosition(0, 0);
			return m.n;
		}
	}
}

void constructMenu(Menu &m,Coordinate start, const char** item, int count, menuColor color, int lineSkip, char place, bool border) {
	m.start = start;
	m.count = count;
	m.n = 0;
	m.color = color;
	m.lineSkip = lineSkip;
	m.border = border;
	int maxWidthItem = strlen(item[0]); //������ ������ �������� �������� ���� � ��������
	//��������� ����� ������ �������� ��������
	for (int i = 1; i < count; i++) {
		int width = strlen(item[i]);
		if (maxWidthItem < width)
			maxWidthItem = width;
	}
	maxWidthItem += 2; //��������� ������ �� ����� � ����� ��� \0
	m.width = maxWidthItem + ((border) ? 2 : 0); //������������ ������ ����
	m.height = count * (lineSkip + 1) + ((border) ? 2 : 0) - lineSkip; //������������ ������
	
	char** pItem = new char* [count];
	for (int i = 0; i < count; i++)
		pItem[i] = new char[maxWidthItem + 1]; //�������� ������ ��� �������� ���� + ��� \0

	//��������� �������� ����
	//�������� ���������� �������������
	if (place == 'l')//������������ �� ������ ����
		for (int i = 0; i < count; i++)
		{
			int j = 1;
			int len = strlen(item[i]);
			pItem[i][0] = ' ';
			for (; j < len + 1; j++)
				pItem[i][j] = item[i][j - 1];
			for (; j < maxWidthItem; j++)
				pItem[i][j] = ' ';
			pItem[i][j] = '\0';
		}
	else if (place == 'r')//������������ �� ������� ����
		for (int i = 0; i < count; i++)
		{
			int j = 0;
			int len = strlen(item[i]);
			int space = maxWidthItem - len - 1;

			for (; j < space; j++)
				pItem[i][j] = ' ';
			for (; item[i][j - space]; j++)
				pItem[i][j] = item[i][j - space];
			pItem[i][j++] = ' ';
			pItem[i][j] = '\0';
		}
	else if (place == 'c')//������������ �� ������
		for (int i = 0; i < count; i++)
		{
			int j = 0;
			int len = strlen(item[i]); //������ ��������
			int space = (maxWidthItem - len) / 2;

			for (; j < space; j++)
				pItem[i][j] = ' ';
			for (; item[i][j - space]; j++)
				pItem[i][j] = item[i][j - space];
			for (; j < maxWidthItem; j++)
				pItem[i][j] = ' ';
			pItem[i][j] = '\0';
		}
	m.item = pItem;
}