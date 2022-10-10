#include <iomanip>
#include <iostream>
#include <ctime>
#include <chrono>
#include <fstream>
#include "function.h"

using namespace std;

const int functionCount = 3; // Количество функций

const char fileNameIn[] = "Input.txt"; // Имя файла входных данных

// Основная программа
int main() {
    // Системные команды
    setlocale(LC_ALL, "ru"); // Подключение русской локализации
    srand(time(NULL)); // Инициализация генератора случайных чисел

    // Массив указателей на функции целых чисел
    void* (*menuFunctionInt[functionCount])
    (int* arr, int& size, int& interval, int& minLimitation, int& maxLimitation) =
    {&AllRandom, &UpRegularize, &DownRegularize};

    // Массив указателей на функции дробных чисел
    void* (*menuFunctionFloat[functionCount])
    (float* arr, int& size, int& interval, float& minLimitation, float& maxLimitation) =
    {&AllRandom, &UpRegularize, &DownRegularize};

    // Переменные
    int size = 0; // Количество элементов
    int interval; // Интервал
    int minLimitationInt; // Ограничение на минимальное значение для целых чисел
    int maxLimitationInt; // Ограничение на максимальное значение для целых чисел
    float minLimitationFloat; // Ограничение на минимальное значение для дробных чисел
    float maxLimitationFloat; // Ограничение на максимальное значение для дробных чисел

    // Ввод значений переменных с файла
    ifstream fin ("Input.txt"); // Открытие файла входных данных
    if (fin.is_open()) { // Проверка открытия файла
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
}