#include <iomanip>
#include <iostream>
#include <ctime>
#include <chrono>
#include <fstream>
#include "function.h"

using namespace std;

const int functionCountInt = 7; // Количество функций для целых чисел
const int functionCountFloat = 7; // Количество функций для дробных чисел

const char* fileNameInt[] = { // Массив имён файлов целых последовательностей
    {"AllRandomInt.txt"},
    {"UpRegularizeInt.txt"},
    {"DownRegularizeInt.txt"},
    {"SawInt.txt"},
    {"StepInt.txt"},
    {"QuasiRegularizeInt.txt"},
    {"SinInt.txt"}
};

const char* fileNameFloat[] = { // Массив имён файлов дробных последовательностей
    {"AllRandomFloat.txt"},
    {"UpRegularizeFloat.txt"},
    {"DownRegularizeFloat.txt"},
    {"SawFloat.txt"},
    {"StepFloat.txt"},
    {"QuasiRegularizeFloat.txt"},
    {"SinFloat.txt"}
};

const char fileNameIn[] = "Input.txt";
const char fileTime[] = "Time.csv";
ofstream foutTime(fileTime);

//основная программа
int main() {
    //системные команды
    setlocale(LC_ALL, "ru"); // Подключение русской локализации
    srand(time(NULL)); // Инициализация генератора случайных чисел

    // Массив указателей на функции целых чисел
    int* (*MenuInt[functionCountInt])
    (int* arr, int& size, int& minLimitation, int& maxLimitation, int& interval) =
    {AllRandomInt, UpRegularizeInt, DownRegularizeInt, SawInt, StepInt, QuasiRegularizeInt, SinInt};

    // Массив указателей на функции дробных чисел
    float* (*MenuFloat[functionCountFloat])
    (float* arr, int& size, float& minLimitation, float& maxLimitation, int& interval) =
    {AllRandomFloat, UpRegularizeFloat, DownRegularizeFloat, SawFloat, StepFloat, QuasiRegularizeFloat, SinFloat};

    // Меременные
    int size; // Количество элементов
    int interval; // Интервал
    int minLimitationInt; // Ограничение на минимальное значение для целых чисел
    int maxLimitationInt; // Ограничение на максимальное значение для целых чисел
    float minLimitationFloat; // Ограничение на минимальное значение для чисел с плавающей точкой
    float maxLimitationFloat; // Ограничение на максимальное значение для чисел с плавающей точкой

    // Ввод значений переменных с файла
    ifstream fin ("Input.txt");
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
        cout << "maxLimitationFloat = " <<  maxLimitationFloat << endl;
    }
    else {
        cout << "Файл не найден или повреждённ" << endl; // Сообщение об ошибки
    }
    fin.close(); // Закрытие файла

    cout << "Целочисленные последовательности:" << endl;

    // Начало отсчёта выполнения алгоритма для целых чисел
    auto beginInt = chrono::steady_clock::now();

    int arrInt[size]; // Создание массива целых чисел

    for (int i = 0; i < functionCountInt; i++) {
        MenuInt[i](arrInt, size, minLimitationInt, maxLimitationInt, interval);
        ofstream fout(fileNameInt[i]);
        cout << fileNameInt[i] << ": ";
        for (int j = 0; j < size; j++) {
            cout << "[" << j << "]: " << arrInt[j] << "; ";
            fout << arrInt[j];
            if (j != size - 1) {
                fout << "\n";
            }
        }
        cout << endl;
        fout.close(); // Закрытие файла
    }

    // Конец работы алгоритма для целых чисел
    auto endInt = chrono::steady_clock::now();
    // Вывод времени затраченого на выполнения алгорима для целых чисел
    cout << "Время работы алгоритма для целых чисел: " << std::chrono::duration_cast<std::chrono::microseconds>(endInt - beginInt).count() << "ms" << endl;
    // Запись времени выполнения алгоритма для целых чисел в файл
    //fileTime << std::chrono::duration_cast<std::chrono::microseconds>(endInt - beginInt).count() << ";";

    cout << "Дробные последовательности:" << endl;

    // Начало отсчёта выполнения алгоритма для дробных чисел
    auto beginFloat = chrono::steady_clock::now();

    float arrFloat[size]; // Создание массива дробных чисел

    for (int i = 0; i < functionCountFloat; i++) {
        MenuFloat[i](arrFloat, size, minLimitationFloat, maxLimitationFloat, interval);
        ofstream fout(fileNameFloat[i]);
        cout << fileNameFloat[i] << ": ";
        for (int j = 0; j < size; j++) {
            cout << "[" << j << "]: " << arrInt[j] << "; ";
            fout << arrInt[j];
            if (j != size - 1) {
                fout << "\n";
            }
        }
        cout << endl;
        fout.close(); // Закрытие файла
    }

    // Конец работы алгоритма для дробных чисел
    auto endFloat = chrono::steady_clock::now();
    cout << "Время работы алгоритма для дробных чисел: " << std::chrono::duration_cast<std::chrono::microseconds>(endFloat - beginFloat).count() << "ms" << endl;
    // Запись времени выполнения алгоритма для дробных чисел в файл
    //fileTime << std::chrono::duration_cast<std::chrono::microseconds>(endFloat - beginFloat).count() << ";";
}