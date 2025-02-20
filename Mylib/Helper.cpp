
#include <iostream>
#include "Header.h"
#include <limits>


bool clearCinOnError() {
    if (std::cin.fail()) {
        std::cin.clear();
        ///std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return true; // ������ ����
    }
    return false; // ������ ���
}



int getValidInt(const char p[]) {
    int n; // �������� ������������� �����
    while (true) {
        std::cout << p;
        std::cin >> n;
        if (!clearCinOnError())
            return n;
        else
            std::cout << "����� ������� �����������! ����������, ���������� �����.\n";
    }
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
    delete[] temp;
}