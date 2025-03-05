#pragma once
#include "../console/console.h"
//|-------------------------------------------------|
//|Не работает без подключения                      |
//|#include "../console/console.h"                  |
//|В основном файле                                 |
//|_________________________________________________|

//Цветовая палитра меню
struct menuColor {
    int BG; //Цвет фона элемента меню
    int FG; //Цвет текста элемента меню
    int hiBG; //Цвет выделенного фона элемента меню
    int hiFG; //Цвет выделенного текста элемента меню
    int borderFG; //Цвет окантовки меню
};

//Меню
struct Menu {
    Coordinate start;//Координаты начала места печати меню
    char** item = nullptr;//Элементы меню
    int count; //Количество элементов в меню
    int n; //Номер выбранного элемента меню
    menuColor color;//Цветовая палитра меню
    int lineSkip; //Количество пропущенных строк между элементами меню
    int width; //Ширина меню
    int height;//Ширина меню
    bool visible;//Видимость меню
    bool border;//Окантовка меню
};


/// <summary>
/// Печатает элементы меню на экране
/// </summary>
/// <param name="m">Структура меню</param>
void showItemMenu(Menu m);
/// <summary>
/// Анимирует перемещение по меню
/// </summary>
/// <param name="m">Структура меню</param>
/// <returns>Возвращает номер элемента выбранного в меню</returns>
int scrollMenu(Menu m);
/// <summary>
/// Очищает указатели в меню. Не требует очищения без выделения памяти.
/// </summary>
/// <param name="m">Структура меню</param>
void clearMenu(Menu& m);