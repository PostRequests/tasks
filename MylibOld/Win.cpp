#include "Header.h"

#include <iostream>
#include <Windows.h>
#include <conio.h>


void setCursorPosition(int x, int y) {
    std::cout << "\033[" << y << ";" << x << "H";
}

void setCursorPosition(Coordinate xy) {
    std::cout << "\033[" << xy.y << ";" << xy.x << "H";
}

Coordinate getCursorPosition() {
    Coordinate r; //Структура координат
    CONSOLE_SCREEN_BUFFER_INFO csbi; // Создаем структуру для хранения координат курсора
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Получаем информацию о текущем состоянии консоли
    if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        r.x = csbi.dwCursorPosition.X;
        r.y = csbi.dwCursorPosition.Y;
    }
    else {
        r.x = -1;
        r.y = -1;
    }
    return r;
}

Coordinate getConsoleSize() {
    Coordinate r;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        r.x = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        r.y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    }
    else {
        r.x = -1;
        r.y = -1;
    }
    return r;
}
void FullScreenMode() {
    SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
}

char convertKey(char key) {
    tolower(key);
    switch (key) {
    case 'w': case 72: case -106: case -26:	return 'w';
    case 'a': case 75: case -108: case -28:	return 'a';
    case 's': case 80: case -101: case -21:	return 's';
    case 'd': case 77: case -126: case -94:	return 'd';
    case 'q': case -87: case -119: return'q';
    case 't': case -97: case -123: return 't';
    case 'r': case -86: case -118: return 'r';
    case 'f': case -64: case -32: return 'f';
    case 13: return 13;
    default: return 0;
    }
}

char catchKey() {
    while (true)
    {
        int input = _getch();
        if (input != 0 and input != 0xE0) {
            char key = input;
            return convertKey(key);
        }
    }
}