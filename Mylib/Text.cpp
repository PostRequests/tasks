#include <iostream>
#include "Header.h"


int getCharLen(char* t) {
	int len = 0;//������ ������
	for (; *t != '\0'; t++, len++);
	return len;
}

int getCharLen(const char* t) {
    int len = 0;//������ ������
    for (; *t != '\0'; t++, len++);
    return len;
}


char* getGlueTogether(char* a, char* b) {
    int len = getCharLen(a) + getCharLen(b) + 1; // ����� �������� ������
    char* result = new char[len]; //��������� �������

    while (*a) *result++ = *a++;
    while (*b) *result++ = *b++;
    *result = '\0';

    return result - len + 1;
}

char* intToStr(int num) {
    bool isNegative = num < 0;//�������� �� ���������������
    if (isNegative) num = -num;
    int len = getNumLength(num) + 1 + (isNegative ? 1 : 0); //������ ������
    char* result = new char[len];
    result += len - 1;
    *result = '\0';
    do
        * --result = '0' + (num % 10);
        while (num /= 10);

    if (isNegative) *(--result) = '-';
    
    return result;
}

void copyStr(char* a, char* b) {
    for (; (*a = *b) ; a++, b++);
}
void copyStr(char* a, const char* b) {
    for (; (*a = *b); a++, b++);
}

int getLengthNextWord(char* t) {
    int len = 0; // ����������� ������ ����� �� ������� ��� ����� ������
    for (; *t && *t != ' '; len++, t++);
    return len;
}