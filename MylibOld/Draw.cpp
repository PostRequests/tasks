#include "Header.h"
#include <iostream>

void setColor(int color) {
    std::cout << "\x1b[" << color << 'm';
}

void setColor(int color1, int color2) {
    std::cout << "\x1b[" << color1 << ';' << color2 << 'm';
}

void resetColor() { setColor(0); }

void printRowChars(int s, char symbol, int color1 ,int color2) {
    if (color1)
        ((color2) ? setColor(color1, color2) : setColor(color1));
    for (int i = 0; i < s; i++)
        std::cout << symbol;
}

void printRowChars(int s, char l, char c, char r, int color1, int color2) {
    if (color1)
        ((color2) ? setColor(color1, color2) : setColor(color1));
    std::cout << l;
    for (int i = 1; i < s - 1; i++)
        std::cout << c;
    std::cout << r;
}

void drawEmptyRectangle(int posX, int posY, int rows, int cols, int color) {
    setCursorPosition(posX, posY);
    for (int r = 0; r < rows; r++) {
        printRowChars(cols, ' ', color);
        setCursorPosition(posX, posY + r + 1);
    }
}

void drawArr(char *arr, int posX, int posY, int rows, int cols, int color1, int color2) {
    if (color1)
        ((color2) ? setColor(color1, color2) : setColor(color1));
    setCursorPosition(posX, posY);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
            std::cout << *(arr + i * cols + j);
        setCursorPosition(posX, posY + i + 1);
    }
}

void drawVerticalLine(Coordinate c, char e, int s) {
    system("chcp 866 > nul");
    setCursorPosition(c);
    for (int i = 0; i < s + 1; i++)
    {
        std::cout << e;
        setCursorPosition(c.x , c.y + i);
    }
    system("chcp 1251>nul");
}