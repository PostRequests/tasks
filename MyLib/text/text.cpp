#include "text.h"
#include <iostream>

int strMaxLen(const char** item, int count) {
	int maxWidthItem = strlen(item[0]); //������ ������ �������� �������� ���� � ��������
	//��������� ����� ������ �������� ��������
	for (int i = 1; i < count; i++) {
		int width = strlen(item[i]);
		if (maxWidthItem < width)
			maxWidthItem = width;
	}
	return maxWidthItem;
}
char toLowerRus(char ABC) {
	if ((ABC >= 'A' && ABC <= 'Z') || (ABC >= '�' && ABC <= '�'))
		return ABC + 32;
	return ABC;
}