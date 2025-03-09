#pragma once

/// <summary>
/// Вычисляет самый длинный элемент строкового массива и возвращает его длину
/// </summary>
/// <param name="item">Массив строк</param>
/// <param name="count">Количество элементов массива</param>
/// <returns>Количество символов в самой длинной строке</returns>
int strMaxLen(const char** item, int count);
/// <summary>
/// Позволяет преобразовать заглавные буквы в строковые
/// </summary>
/// <param name="ABC">Буква для преобразования</param>
/// <returns>Строковая буква</returns>
char toLowerRus(char ABC);
/// <summary>
/// Преобразует констант текст в выделенную память
/// </summary>
/// <param name="text">Константный текст</param>
/// <returns>Указатель на выделенную память</returns>
char* toMemPoint(const char* text);
