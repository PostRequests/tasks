#pragma once
struct Coordinate {
    int x; //Ряд
    int y; //Строка
};

struct Menu {
    Coordinate startPos;//Координаты начала места печати меню
    int countMenu; //Количество элементов в меню
    char** elemMenu = nullptr;//Элементы меню
    int n; //Номер выбранного элемента меню
};
struct TaskStructure
{
    Coordinate cS;//Координаты крайней правой нижней точки консоли
    char* head = nullptr;//Заголовок с номером домашней работы
    char* theme = nullptr;//Тема домашней работы
    char** tNames = nullptr; //Текст меню
    char** textTasks = nullptr;//Текст задачи
    Coordinate startPos;//Координаты поля для ввода
    int countMenu; //Количество элементов menu
    int n; //Номер выделенного элемента меню

};

struct ColorANSI3b {//Цвета ANSI 3бит 
    const int BlackBG = 40;   // Фоновый черный
    const int BlackFG = 30;   // Текстовый черный
    const int RedBG = 41;     // Фоновый красный
    const int RedFG = 31;     // Текстовый красный
    const int GreenBG = 42;   // Фоновый зеленый
    const int GreenFG = 32;   // Текстовый зеленый
    const int YellowBG = 43;  // Фоновый желтый
    const int YellowFG = 33;  // Текстовый желтый
    const int BlueBG = 44;    // Фоновый синий
    const int BlueFG = 34;    // Текстовый синий
    const int MagentaBG = 45; // Фоновый пурпурный
    const int MagentaFG = 35; // Текстовый пурпурный
    const int CyanBG = 46;    // Фоновый циановый
    const int CyanFG = 36;    // Текстовый циановый
    const int WhiteBG = 47;   // Фоновый белый
    const int WhiteFG = 37;   // Текстовый белый
};

/// Набор символов для рисования таблиц
//LT1: "┌" H1 : "─" RT1 : "┐" V1 : "│" LD1 : "└" RD1 : "┘" LV1 : "├" RV1 : "┤" DH1 : "┴" UH1 : "┬"C1 : "┼" 
struct BorderCP866 {
    const char LT2 = 201; //╔ левый верхний двойной
    const char H2 = 205; //═ горизонтальный двойной
    const char RT2 = 187; //╗ правый верхний двойной
    const char V2 = 186; //║ вертикальный двойной
    const char LD2 = 200; //╚ левый нижний двойной
    const char RD2 = 188; //╝ правый нижний двойной
    const char LV2 = 204; //╠ левый вертикальный двойной
    const char RV2 = 185; //╣ правый вертикальный двойной
    const char DH2 = 202; //╩ нижний горизонтальный двойной
    const char UH2 = 203; //╦ верхний горизонтальный двойной
    const char C2 = 206; //╬ центральный двойной

    const char LT1 = 218; // ┌ левый верхний одинарный
    const char H1 = 196;  // ─ горизонтальный одинарный
    const char RT1 = 191; // ┐ правый верхний одинарный
    const char V1 = 179;  // │ вертикальный одинарный
    const char LD1 = 192; // └ левый нижний одинарный
    const char RD1 = 217; // ┘ правый нижний одинарный
    const char LV1 = 195; // ├ левый вертикальный одинарный
    const char RV1 = 180; // ┤ правый вертикальный одинарный
    const char DH1 = 193; // ┴ нижний горизонтальный одинарный
    const char UH1 = 194; // ┬ верхний горизонтальный одинарный
    const char C1 = 197;  // ┼ центральный одинарный
};
