#include <iostream>
#include "Header.h"


int getCharLen(char* t) {
	int len = 0;//Длинна строки
	for (; *t != '\0'; t++, len++);
	return len;
}

int getCharLen(const char* t) {
    int len = 0;//Длинна строки
    for (; *t != '\0'; t++, len++);
    return len;
}


char* getGlueTogether(char* a, char* b) {
    int len = getCharLen(a) + getCharLen(b) + 1; // Длина итоговой строки
    char* result = new char[len]; //Результат функции

    while (*a) *result++ = *a++;
    while (*b) *result++ = *b++;
    *result = '\0';

    return result - len + 1;
}

char* intToStr(int num) {
    bool isNegative = num < 0;//Проверка на отрицательность
    if (isNegative) num = -num;
    int len = getNumLength(num) + 1 + (isNegative ? 1 : 0); //Длинна строки
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

void addStr(char* a, const char* b) {
    while (*a) a++;
    copyStr(a, b);
}

int getCharInTextCount(char* text, char symbol) {
    int result = 0;
    while (*text) {
        if (*text == symbol) result++;
        text++;
    }
    return result;
}
void addStr(char*& text, int& size, char* text2, int pos) {
    int size2 = getCharLen(text2);  // Размер вставляемого текста
    if (pos < 0 || pos > size) pos = size; // Коррекция позиции вставки
    int newSize = size + size2;
    char* newArr = new char[newSize + 1]; 
    char* start = newArr;
    for (int i = 0; i < pos; i++) {
        *start = text[i];
        start++;
    }
    copyStr(start, text2);
    start += size2;
    for (int i = pos; i < size; i++) {
        *start = text[i];
        start++;
    }
    delete[] text;

    size = newSize;
    text = newArr;
}
void replase(char* text, char replaceable, char inserted) {
    for (; *text; ++text) if (*text == replaceable) *text = inserted;
}
void deleteCharsInText(char*& text, char symbol) {
    int j = 0;
    for (int i = 0; text[i]; i++) 
        if (text[i] != symbol) 
            text[j++] = text[i];
    text[j] = '\0';
}

void deleteSymbol(char* text, int pos) {
    int i;
    for (i = pos; text[i + 1]; i++) 
        text[i] = text[i + 1];
    text[i] = '\0';
}
char* newChars(const char* text) {
    int size = getCharLen(text) + 1;
    char* result = new char[size];
    copyStr(result, text);
    return result;
}
int getLengthNextWord(char* t) {
    int len = 0; // Вычисляемая длинна слова до пробела или конца текста
    for (; *t && *t != ' '; len++, t++);
    return len;
}

bool includeContainsOnly(char* text, const char* content) {
    if (!*text) return false;
    for (; (*text); text++) {
        bool include = false;
        for (const char* c = content; *c; c++) {
            if (*c == *text) {
                include = true;
                break;
            }
        }
        if (!include) return false;
    }
    return true;
}

bool isNumber(char* text) {
    return includeContainsOnly(text, "1234567890-");
}

int strToInt(char* num) {
    int result = 0;//Результат функции
    int multiplier = 1; //Множитель
    bool isNegative = (*num == '-') ? true : false;
    if (isNegative) num++;
    char* end = num + getCharLen(num) - 1;
    for (; end != num-1; end--, multiplier *= 10) {
        result += (*end - '0') * multiplier;
    }
    return ((isNegative) ? -result : result);
}