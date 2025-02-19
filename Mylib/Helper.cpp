
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