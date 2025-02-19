#pragma once
#include <iostream>
#include "Print.h"
#include "Random.h"
#include "Matrix.h"
#include "Struct.h"

/*Helper*/

/// <summary>
/// Очищает поток ввода в случае ошибки
/// </summary>
/// <returns>Возвращает true в случае наличии ошибки, false если ошибки нет</returns>
bool clearCinOnError();
/// <summary>
/// Функция запрашивает у пользователя ввод целого числа и проверяет его на корректность.
/// </summary>
/// <param name="p">Сообщение, которое будет выведено пользователю для запроса ввода.</param>
/// <returns>Возвращает корректно введенное целое число.</returns>
int getValidInt(const char p[]);

/*Calc*/

/// <summary>
/// Ищет максимальное значение из двух чисел
/// </summary>
/// <param name="a">Первое число</param>
/// <param name="b">Второе число</param>
/// <returns>Возвращает указатель на большее число</returns>
int* findMax(int* a, int* b);
/// <summary>
/// Ищет минимальное значение из двух чисел
/// </summary>
/// <param name="a">Первое число</param>
/// <param name="b">Второе число</param>
/// <returns>Возвращает указатель на большее число</returns>
int* findMin(int* a, int* b);
/// <summary>
/// Рекурсивно вычисляет сумму всех целых чисел в заданном диапазоне [a, b].
/// </summary>
/// <param name="a">Первое число диапазона</param>
/// <param name="b">Второе число диапазона</param>
/// <returns>Сумма всех чисел в диапазоне от a до b включительно</returns>
int calculateRangeSum(int a, int b);
/// <summary>
/// Возведение в степень
/// </summary>
/// <param name="d">основание степени</param>
/// <param name="e">показатель степени</param>
/// <returns>Результат функции возвращает степень числа</returns>
int getPower(int d, int e);
/// <summary>
/// Рекурсивно вычисляет сумму элементов массива
/// </summary>
/// <param name="arr">Исходный массив</param>
/// <param name="size">Размер массива</param>
/// <param name="i">Начальный индекс диапазона</param>
/// <param name="j">Конечный индекс диапазона</param>
/// <returns>Cумма элементов массива в указанном диапазоне индексов</returns>
int getSumRangeArr(int arr[], int size, int i, int j);
/// <summary>
/// Возвращает количество символов в строке int
/// </summary>
/// <param name="n">Предоставленное число</param>
/// <returns>Количество символов для записи числа в консоль</returns>
int getNumLength(int n);
/// <summary>
/// Копирует в orig массив copy массив
/// </summary>
/// <param name="orig">Указатель на массив int, в который будут скопированы данные</param>
/// <param name="copy">Указатель на массив int, в который будут скопированы данные</param>
/// <param name="sOrig">Размер orig массива (количество элементов, которые можно скопировать)</param>
void copyNumArr(int* orig, int* copy, int sOrig);
/// <summary>
/// Функция позволяет напечатать на экране однострочный массив по указателю
/// </summary>
/// <param name="a">Указатель на первый элемент массива</param>
/// <param name="size">Размер массива</param>
void show(int* a, int size);
/// <summary>
/// Функция позволяет реверсировать числовой массив
/// </summary>
/// <param name="arr">Указатель на первый элемент массива</param>
/// <param name="size">Размер массива</param>
void reverseNumArr(int* arr, int size);
/// <summary>
/// Копирует реверсирование значение целочисленного массива
/// </summary>
/// <param name="arr">Указатель на элемент в который копируем</param>
/// <param name="arr2">Указатель на копируемый элемент</param>
/// <param name="size">Размер массива(Массивы должны совпадать)</param>
void copyReverseNumArr(int* copy, int* orig, int size);

/*Print*/

/// <summary>
/// Выводит элементы массива в консоль
/// </summary>
/// <typeparam name="T">Тип массива</typeparam>
/// <typeparam name="N">Размер массива</typeparam>
/// <param name="a">Ссылка на массив, который необходимо вывести</param>
template<typename T, size_t N> void show(T(&a)[N]);
template<typename T, size_t N>void show(T(&a)[N], int s, int e);
template<typename T, size_t N, size_t M>
/// <summary>
/// Выводит элементы массива в консоль
/// </summary>
/// <typeparam name="T">Тип массива</typeparam>
/// <typeparam name="N">Размер массива строк</typeparam>
/// <typeparam name="M">Размер массива колонок</typeparam>
/// <param name="a">Ссылка на массив, который необходимо вывести</param>
void show(T(&a)[N][M]);

/*Random*/

/// <summary>
/// Заполняет массив случайными значениями в заданном диапазоне [s, e]
/// </summary>
/// <typeparam name="T">Тип элементов массива</typeparam>
/// <typeparam name="N">Размер массива (определяется автоматически)</typeparam>
/// <param name="a">Ссылка на массив, который нужно заполнить</param>
/// <param name="s">Нижняя граница диапазона случайных чисел (включительно)</param>
/// <param name="e">Верхняя граница диапазона случайных чисел (включительно)</param>
template<size_t N>void randArr(char(&arr)[N], char s, char e);
/// Заполняет массив случайными значениями в заданном диапазоне [s, e]
/// </summary>
/// <typeparam name="T">Тип элементов массива</typeparam>
/// <typeparam name="N">Размер массива (определяется автоматически)</typeparam>
/// <param name="a">Ссылка на массив, который нужно заполнить</param>
/// <param name="s">Нижняя граница диапазона случайных чисел (включительно)</param>
/// <param name="e">Верхняя граница диапазона случайных чисел (включительно)</param>
template<typename T, size_t N>void randArr(T(&a)[N], T s, T e);
/// Заполняет двумерный массив случайными значениями в заданном диапазоне [s, e]
/// </summary>
/// <typeparam name="T">Тип элементов массива</typeparam>
/// <typeparam name="N">Размер массива (определяется автоматически)</typeparam>
/// <param name="a">Ссылка на массив, который нужно заполнить</param>
/// <param name="s">Нижняя граница диапазона случайных чисел (включительно)</param>
/// <param name="e">Верхняя граница диапазона случайных чисел (включительно)</param>
template<typename T, size_t N, size_t M>void randArr(T(&a)[N][M], T s, T e);

/*Matrix*/

/// <summary>
/// Определяет минимальный элемент в массиве
/// </summary>
/// <typeparam name="N">Размер массива</typeparam>
/// <param name="a">Ссылка на массив</param>
/// <returns>Максимально большое число в массиве</returns>
template<typename T, size_t N>T getMin(T(&a)[N]);
/// <summary>
/// Определяет минимальный элемент в двумерном массиве
/// </summary>
/// <typeparam name="N">Размер массива</typeparam>
/// <param name="a">Ссылка на массив</param>
/// <returns>Максимально большое число в массиве</returns>
template<typename T, size_t N, size_t M>T getMin(T(&a)[N][M]);
/// <summary>
/// Определяет максимальный элемент в массиве
/// </summary>
/// <typeparam name="N">Размер массива</typeparam>
/// <param name="a">Ссылка на массив</param>
/// <returns>Максимально большое число в массиве</returns>
template<typename T, size_t N>T getMax(T(&a)[N]);
/// <summary>
/// Определяет максимальный элемент в двумерном массиве
/// </summary>
/// <typeparam name="N">Размер массива</typeparam>
/// <param name="a">Ссылка на массив</param>
/// <returns>Максимально большое число в массиве</returns>
template<typename T, size_t N, size_t M>T getMax(T(&a)[N][M]);
/// <summary>
/// Шаблон сортировки массива методом пузырька
/// </summary>
/// <typeparam name="T">Тип элементов массива</typeparam>
/// <typeparam name="N">Размер массива (определяется автоматически)</typeparam>
/// <param name="a">Ссылка на массив, который нужно отсортировать</param>
template<typename T, size_t N>void sortStone(T (&a)[N]);
/// <summary>
/// Шаблон сортировки массива методом вставки
/// </summary>
/// <typeparam name="T">Тип элементов массива</typeparam>
/// <typeparam name="N">Размер массива (определяется автоматически)</typeparam>
/// <param name="a">Ссылка на массив, который нужно отсортировать</param>
template <typename T, size_t N>void sortInsert(T(&a)[N]);
/// <summary>
/// Шаблон сортировки двумерного массива методом вставки
/// </summary>
/// <typeparam name="T">Тип элементов массива</typeparam>
/// <typeparam name="N">Размер массива (определяется автоматически)</typeparam>
/// <param name="a">Ссылка на массив, который нужно отсортировать</param>
template <typename T, size_t N, size_t M>void sortInsert(T(&a)[N][M]);


/*Text*/

/// <summary>
/// Определяет длину текста
/// </summary>
/// <param name="t">Указатель на первый элемент анализируемого текста</param>
/// <returns>Возвращает длину строки</returns>
int getCharLen(char* t);
/// <summary>
/// Определяет длину текста
/// </summary>
/// <param name="t">Указатель на первый элемент анализируемого текста</param>
/// <returns>Возвращает длину строки</returns>
int getCharLen(const char* t);
/// <summary>
/// Склеивает строку вместе
/// </summary>
/// <param name="a">Указатель на первый массив строки</param>
/// <param name="b">Указатель на второй массив строки</param>
/// <returns>Новый указатель на новый массив из склеенных 2х строк</returns>
char* getGlueTogether(char* a, char* b);
/// <summary>
/// Переводит число в строку
/// </summary>
/// <param name="num">Число которое хотим превратить в строку</param>
/// <returns>Указатель на строку полученную из числа</returns>
char* intToStr(int num);
/// <summary>
/// Позволяет копировать данные из одной строки в другую
/// </summary>
/// <param name="a">Указатель на строку копию</param>
/// <param name="b">Указатель на строку оригинал</param>
void copyStr(char* copy, char* orig);
/// <summary>
/// Позволяет копировать данные из одной строки в другую
/// </summary>
/// <param name="a">Указатель на строку копию</param>
/// <param name="b">Указатель на строку оригинал</param>
void copyStr(char* copy, const char* orig);
/// <summary>
/// Проверяет длину ближайшего слова до пробела или до конца текста
/// </summary>
/// <param name="t">Указатель на начальную точку поиска слова</param>
/// <returns>Возвращает количество символов в ближайшем слове</returns>
int getLengthNextWord(char* t);

/*Win*/

/// <summary>Конвертирует нажатые клавиши на русском и английском вединый вид </summary>
/// <param name="key">Символ который в итоге конвертируется</param>
/// <returns>Обработанный символ например ц==Ц==W==(w) возвращает w</returns>
char convertKey(char key);
/// <summary> Устанавливаем курсор в нужную позицию </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void setCursorPosition(int x, int y);
/// <summary>
/// Устанавливаем курсор в нужную позицию
/// </summary>
/// <param name="xy">Структура координат курсора xy.x xy.y</param>
void setCursorPosition(Coordinate xy);
/// <summary>
/// Определяет в какой позиции сейчас находиться курсор
/// </summary>
/// <returns>Возвращает структуру координат Coordinate.x Coordinate.y</returns>
Coordinate getCursorPosition();
/// <summary>
/// Определяет текущий размер экрана в символах
/// </summary>
/// <returns>Возвращает структуру координат максимальных точек Coordinate.x/y</returns>
Coordinate getConsoleSize();
/// <summary>
/// Раскрывает консоль в полный экран
/// </summary>
void FullScreenMode();
/// <returns>Возвращает нажатый символ</returns>
char catchKey();

/*Draw*/

/// <summary>
/// Рисуем горизонтальную линию
/// </summary>
/// <param name="c">Координаты начала</param>
/// <param name="e">Символ линии</param>
/// <param name="s">Количество элементов линии</param>
void drawVerticalLine(Coordinate c, char e, int s);
/// <summary>
/// Устанавливаем 1 цвет консоли
/// https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
/// </summary>
/// <param name="color">Цвет</param>
void setColor(int color);
/// <summary>
/// Устанавливаем 2 цвета консоли, для фона и для символа
/// </summary>
/// <param name="color1">Цвет1</param>
/// <param name="color2">Цвет2</param>
void setColor(int color1, int color2);
/// <summary>/// Сбрасываем все цвета консоли на стандартный/// </summary>
void resetColor();
/// <summary>
/// Печатает линию
/// </summary>
/// <param name="s">Длинна линии</param>
/// <param name="symbol">Элемент заполнения</param>
/// <param name="color1">Цвет консоли ANSI</param>
/// <param name="color2">Цвет консоли ANSI</param>
void printRowChars(int s, char symbol, int color1 = 0, int color2 = 0);
/// <summary>
/// Печатает линию
/// </summary>
/// <param name="s">Длинна линии</param>
/// <param name="l">Первый символ в линии</param>
/// <param name="c">Символ который будет заполнять центр линии</param>
/// <param name="r">Последний символ линии</param>
/// <param name="color1">Цвет консоли ANSI (не обязательный параметр)</param>
/// <param name="color2">Цвет консоли ANSI (не обязательный параметр)</param>
void printRowChars(int s, char l, char c, char r, int color1 = 0, int color2 = 0);
/// <summary>
/// Закрашивает/Удаляет область прямоугольную 
/// </summary>
/// <param name="posX">Позиция строки</param>
/// <param name="posY">Позиция колонки</param>
/// <param name="rows">Количество закрашиваемых строк</param>
/// <param name="cols">Количество закрашиваемых колонок</param>
/// <param name="color">Параметр цвета (указываем только задний фон)</param>
void drawEmptyRectangle(int posX, int posY, int rows, int cols, int color = 0);
/// <summary>
/// Печатаем 2мерный массив по координатам, можно использовать 2 цвета
/// </summary>
/// <param name="arr">Указатель на 2мерный массив</param>
/// <param name="posX">Позиция строки</param>
/// <param name="posY">Позиция колонки</param>
/// <param name="rows">Размерность массива в строках</param>
/// <param name="cols">Размерность массива в колонках</param>
/// <param name="color1">цвет 1 (не обязательный параметр)</param>
/// <param name="color2">цвет 2 (не обязательный параметр)</param>
void drawArr(char* arr, int posX, int posY, int rows, int cols, int color1 = 0, int color2 = 0);

/*Win*/

/// <summary> Устанавливаем курсор в нужную позицию </summary>
/// <param name="x"> - координата</param>
/// <param name="y">- координата</param>
void setCursorPosition(int x, int y);
/// <summary>
/// Устанавливаем курсор в нужную позицию
/// </summary>
/// <param name="xy">Структура координат курсора xy.x xy.y</param>
void setCursorPosition(Coordinate xy);
/// <summary>
/// Определяет в какой позиции сейчас находиться курсор
/// </summary>
/// <returns>Возвращает структуру координат Coordinate.x Coordinate.y</returns>
Coordinate getCursorPosition();
/// <summary>
/// Определяет текущий размер экрана в символах
/// </summary>
/// <returns>Возвращает структуру координат максимальных точек Coordinate.x/y</returns>
Coordinate getConsoleSize();
/// <summary>
/// Раскрывает консоль в полный экран
/// </summary>
void FullScreenMode();
/// <returns>Возвращает нажатый символ</returns>
char catchKey();

/*Task Menu*/

/// <summary>
/// Очищает все указатели в меню
/// </summary>
/// <param name="m">Структура меню</param>
void clearMenu(Menu& m);
/// <summary>
/// Непосредственно функция зацикливающая работу с меню
/// </summary>
void startMenu();
/// <summary>
/// Задает первоначальные данные в консоль
/// </summary>
/// <param name="m">Структура меню</param>
void constructMenu(Menu& m);
/// <summary>
/// Позволяет установить координаты для структуры координат
/// </summary>
/// <param name="x">Координаты по х</param>
/// <param name="y">Координаты по y</param>
/// <returns>Координаты с параметрами x и y</returns>
Coordinate setCoordinate(int x, int y);
/// <summary>
/// Печатает элементы меню на экране
/// </summary>
/// <param name="m">Структура меню</param>
void showItemMenu(Menu m);
/// <summary>
/// Перенос строки
/// </summary>
/// <param name="xy">Координаты по которым изменяется стока</param>
/// <param name="howeMach">На сколько позиций вниз перенос</param>
void nextLine(Coordinate& xy, int howeMach = 1);
/// <summary>
/// Завершение программы task
/// </summary>
/// <param name="m"></param>
void endTask(Menu& m);
/// <summary>
/// Рисует на экране целиком все элементы меню
/// </summary>
/// <param name="m">Структура меню</param>
void showMenu(const Menu m);
/// <summary>
/// Функция, запускающая задание №1
/// </summary>
void task1(Menu);
/// <summary>
/// Функция, запускающая задание №2
/// </summary>
void task2(Menu);
/// <summary>
/// Функция, запускающая задание №3
/// </summary>
void task3(Menu);
/// <summary>
/// Функция, запускающая задание №4
/// </summary>
void task4(Menu);
/// <summary>
/// Функция, запускающая задание №5
/// </summary>
void task5(Menu);
/// <summary>
/// Функция, запускающая задание №6
/// </summary>
void task6(Menu);
/// <summary>
/// Функция, запускающая задание №7
/// </summary>
void task7(Menu);
/// <summary>
/// Изменяет номер элемента бокового меню и перерисовывает его
/// </summary>
/// <param name="m">Структура меню</param>
/// <param name="direction">Направление w - Вверх, s - Вниз</param>
void changeItemMenu(Menu &m, char direction);
/// <summary>
/// Печатает текст задачи
/// </summary>
/// <param name="m">Структура меню</param>
void showTextMenu(Menu &m);
