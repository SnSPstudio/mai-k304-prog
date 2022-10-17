#include <iomanip>
#include <iostream>
#include <ctime>
#include <chrono>
#include <fstream>
#include "function.h"

using namespace std;

const int FUNCTION_GENERATION_COUNT = 2; // Количество функций генерации последовательностей
const int FUNCTION_SEARCH_COUNT = 3; // Количество функций поиска

const char FILE_NAME_IN[] = "Input.txt"; // Имя файла входных данных

// Основная программа
int main() {
    // Системные команды
    setlocale(LC_ALL, "ru"); // Подключение русской локализации
    srand(time(NULL)); // Инициализация генератора случайных чисел

    // Массив указателей на функции генерации целых чисел
    void* (*menuFunctionGenerationInt[FUNCTION_GENERATION_COUNT])
    (int* arr, int& size, int& interval, int& minLimitation, int& maxLimitation) =
    {&allRandom, &upRegularize};

    // Массив указателей на функции генерации дробных чисел
    void* (*menuFunctionGenerationFloat[FUNCTION_GENERATION_COUNT])
    (float* arr, int& size, int& interval, float& minLimitation, float& maxLimitation) =
    {&allRandom, &upRegularize};

    // Массив указателей на функции поиска целых чисел
    int* (*menuFunctionSearchInt[ FUNCTION_SEARCH_COUNT])
    (int* arr, int& size, int& key)
    {&betterLinearSearch, &sentinelLinearSearch, &binarySearch};

    // Массив указателей на функции поиска дробных чисел
    int* (*menuFunctionSearchFloat[ FUNCTION_SEARCH_COUNT])
    (float* arr, int& size, float& key)
    {&betterLinearSearch, &sentinelLinearSearch, &binarySearch};

    // Переменные
    int size = 0; // Количество элементов
    int key; // Искомое значение
    int interval; // Интервал
    int minLimitationInt; // Ограничение на минимальное значение для целых чисел
    int maxLimitationInt; // Ограничение на максимальное значение для целых чисел
    float minLimitationFloat; // Ограничение на минимальное значение для дробных чисел
    float maxLimitationFloat; // Ограничение на максимальное значение для дробных чисел

    // Ввод значений переменных с файла
    ifstream fin (FILE_NAME_IN); // Открытие файла входных данных
    if (fin.is_open()) { // Проверка открытия файла
        fin >> key;
        cout << "key = " << key << endl;
        fin >> size;
        cout << "size = " << size << endl;
        fin >> interval;
        cout << "interval = " << interval << endl;
        fin >> minLimitationInt;
        cout << "minLimitationInt = " << minLimitationInt << endl;
        fin >> maxLimitationInt;
        cout << "maxLimitationInt = " << maxLimitationInt << endl;
        fin >> minLimitationFloat;
        cout << "minLimitationFloat = " << minLimitationFloat << endl;
        fin >> maxLimitationFloat;
        cout << "maxLimitationFloat = " << maxLimitationFloat << endl;
    }
    else {
        cout << "Error: File not found" << endl; // Сообщение об ошибки
    }
    fin.close(); // Закрытие файла

    // Объявление массивов
    int arrInt[size]; // Создание массива целых чисел
    float arrFloat[size]; // Создание массива дробных чисел

    // Генерация рандомной последовательности целых чисел
    menuFunctionGenerationInt[0](arrInt, size, interval, minLimitationInt, maxLimitationInt);
    // Генерация рандомной последовательности дробных чисел
    menuFunctionGenerationInt[1](arrFloat, size, interval, minLimitationFloat, maxLimitationFloat);

    int temp; // Искомый номер элемента
    temp = menuFunctionSearchInt[0](arrInt, size, key);
    cout << "betterLinearSearchInt = " << temp << endl;
    temp = menuFunctionSearchInt[0](arrFloat, size, key);
    cout << "betterLinearSearchFloat = " << temp << endl;

    

}