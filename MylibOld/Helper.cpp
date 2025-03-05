
#include <iostream>
#include "Header.h"
#include <limits>


bool clearCinOnError() {
    if (std::cin.fail()) {
        std::cin.clear();
        ///std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return true; // Ошибка была
    }
    return false; // Ошибки нет
}



int getValidInt(const char p[]) {
    int n; // Вводимое пользователем число
    while (true) {
        std::cout << p;
        std::cin >> n;
        if (!clearCinOnError())
            return n;
        else
            std::cout << "Число введено некорректно! Пожалуйста, попробуйте снова.\n";
    }
}
int getValidInt(TaskStructure &m, const char text[]) {
    ColorANSI3b color;
    Coordinate pos = m.startPos;
    char numb[11];
    while (true) {
        std::cout << text;
        std::cin >> numb;
        if (isNumber(numb))
            break;
        else {
            drawEmptyRectangle(16, m.startPos.y,  pos.y - m.startPos.y + 1, m.cS.x - 17);
            pos = m.startPos;
            setCursorPosition(pos);
            setColor(color.RedFG);
            std::cout << "Число введено некорректно! Пожалуйста, попробуйте снова.";
            resetColor();
            nextLine(pos);
        }
    }
    m.startPos = pos;
    return strToInt(numb);
}

void gitPush(const char* text) {
    system("git add .>nul");
    char gitText[] = "git commit -m \"";
    char* temp = new char[getCharLen(gitText) + getCharLen(text) + 2];
    copyStr(temp, gitText);
    addStr(temp, text);
    addStr(temp, "\"");
    std::cout << temp;
    system(temp);
    system("git push");
    system("git status");
    delete[] temp;
}

