#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <fstream>
#include "function.h"

using namespace std;

const int FUNCTION_COUNT = 6; // Количество функций

const char* FILE_NAME_OUT[] = { // Массив имён файлов
    {"AllRandomInt.txt"},
    {"UpRegularizeInt.txt"},
    {"DownRegularizeInt.txt"},
    {"SawInt.txt"},
    {"StepInt.txt"},
    {"SinInt.txt"},
    {"AllRandomFloat.txt"},
    {"UpRegularizeFloat.txt"},
    {"DownRegularizeFloat.txt"},
    {"SawFloat.txt"},
    {"StepFloat.txt"},
    {"SinFloat.txt"}
};

const char FILE_NAME_IN[] = "Input.txt"; // Имя файла входных данных
const char FILE_NAME_TIME[] = "Time.txt"; // Файл для записи времени

// Основная программа
int main() {
    // Системные команды
    setlocale(LC_ALL, "ru"); // Подключение русской локализации
    srand(time(NULL)); // Инициализация генератора случайных чисел

    // Массив указателей на функции целых чисел
    void* (*menuFunctionInt[functionCount])
    (int* arr, int& size, int& interval, int& minLimitation, int& maxLimitation) =
    {&allRandom, &upRegularize, &downRegularize, &saw, &step, &sin};

    // Массив указателей на функции дробных чисел
    void* (*menuFunctionFloat[functionCount])
    (float* arr, int& size, int& interval, float& minLimitation, float& maxLimitation) =
    {&allRandom, &upRegularize, &downRegularize, &saw, &step, &sin};

    // Переменные
    int size = 0; // Количество элементов
    int interval; // Интервал
    int minLimitationInt; // Ограничение на минимальное значение для целых чисел
    int maxLimitationInt; // Ограничение на максимальное значение для целых чисел
    float minLimitationFloat; // Ограничение на минимальное значение для дробных чисел
    float maxLimitationFloat; // Ограничение на максимальное значение для дробных чисел

    // Ввод значений переменных с файла
    ifstream fin (FILE_NAME_IN); // Открытие файла входных данных
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

    // Открытие файла для записи времени выполнения алгоритма
    ofstream foutTime(FILE_NAME_TIME);

    // Начало отсчёта выполнения алгоритма
    auto begin = chrono::steady_clock::now();

    // Объявление массивов
    int arrInt[size]; // Создание массива целых чисел
    float arrFloat[size]; // Создание массива дробных чисел

    // Объявление переменных времени
    auto beginFunction = chrono::steady_clock::now();
    auto endFunction = chrono::steady_clock::now();

    for (int i = 0; i < functionCount; i++) {
        // Алгоритм для целых чисел
        beginFunction = chrono::steady_clock::now(); // Начало отсчёта
        menuFunctionInt[i](arrInt, size, interval, minLimitationInt, maxLimitationInt);
        ofstream foutInt(FILE_NAME_OUT[i]); // Открытие файла для записи целых чисел
        cout << FILE_NAME_OUT[i] << ":" << endl;
        for (int j = 0; j < size; j++) {
            cout << "[" << j << "]: " << arrInt[j] << ";" << endl;
            foutInt << arrInt[j];
            if (j != size - 1) {
                foutInt << "\n";
            }
        }
        foutInt.close(); // Закрытие файла
        // Конец работы алгоритма
        endFunction = chrono::steady_clock::now();
        // Вывод времени затраченого на выполнения алгорима
        cout << "Time: " << std::chrono::duration_cast<std::chrono::microseconds>(endFunction - beginFunction).count() << "ms" << endl;
        // Запись времени выполнения алгоритма в файл
        foutTime << std::chrono::duration_cast<std::chrono::microseconds>(endFunction - beginFunction).count() << "\n";
        cout << endl;

        // Алгоритм для дробных чисел
        beginFunction = chrono::steady_clock::now(); // Начало отсчёта
        menuFunctionFloat[i](arrFloat, size, interval, minLimitationFloat, maxLimitationFloat);
        ofstream foutFloat(FILE_NAME_OUT[functionCount + i]); // Открытие файла для записи дробных чисел
        cout << FILE_NAME_OUT[functionCount + i] << ":" << endl;
        for (int k = 0; k < size; k++) {
            cout << "[" << k << "]: " << arrFloat[k] << ";" << endl;
            foutFloat << arrFloat[k];
            if (k != size - 1) {
                foutFloat << "\n";
            }
        }
        foutInt.close(); // Закрытие файла
        // Конец работы алгоритма
        endFunction = chrono::steady_clock::now();
        // Вывод времени затраченого на выполнения алгорима
        cout << "Time: " << std::chrono::duration_cast<std::chrono::microseconds>(endFunction - beginFunction).count() << "ms" << endl;
        // Запись времени выполнения алгоритма в файл
        foutTime << std::chrono::duration_cast<std::chrono::microseconds>(endFunction - beginFunction).count() << "\n";
        cout << endl;
    }

    // Конец работы алгоритма
    auto end = chrono::steady_clock::now();
    // Вывод времени затраченого на выполнения алгорима
    cout << "Время работы алгоритма для целых чисел: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "ms" << endl;
    // Запись времени выполнения алгоритма в файл
    foutTime << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "\n";
}