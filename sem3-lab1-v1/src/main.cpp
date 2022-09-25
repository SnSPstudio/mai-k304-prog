#include <iomanip>
#include <iostream>
#include <ctime>
#include <chrono>
#include <fstream>
#include "function.h"

using namespace std;

const int functionCountInt = 7; //количество функций для целых чисел
const int functionCountFloat = 7; //количество функций для дробных чисел

const char* fileNameInt[] = { //массив имён файлов целых последовательностей
    {"AllRandomInt.csv"},
    {"UpRegularizeInt.csv"},
    {"DownRegularizeInt.csv"},
    {"SawInt.csv"},
    {"StepInt.csv"},
    {"QuasiRegularizeInt.csv"},
    {"SinInt.csv"}
};

const char* fileNameFloat[] = { //массив имён файлов дробных последовательностей
    {"AllRandomFloat.csv"},
    {"UpRegularizeFloat.csv"},
    {"DownRegularizeFloat.csv"},
    {"SawFloat.csv"},
    {"StepFloat.csv"},
    {"QuasiRegularizeFloat.csv"},
    {"SinFloat.csv"}
};

const char fileNameIn[] = "Input.txt";
const char fileTime[] = "Time.csv";
ofstream foutTime(fileTime);

//основная программа
int main() {
    //системные команды
    setlocale(LC_ALL, "ru"); //подключение русской локализации
    srand(time(NULL)); //инициализация генератора случайных чисел

    //массив указателей на функции целых чисел
    int* (*MenuInt[functionCountInt])
    (int* arr, int& size, int& minLimitation, int& maxLimitation, int& interval) =
    {AllRandomInt, UpRegularizeInt, DownRegularizeInt, SawInt, StepInt, QuasiRegularizeInt, SinInt};

    //массив указателей на функции дробных чисел
    float* (*MenuFloat[functionCountFloat])
    (float* arr, int& size, float& minLimitation, float& maxLimitation, int& interval) =
    {AllRandomFloat, UpRegularizeFloat, DownRegularizeFloat, SawFloat, StepFloat, QuasiRegularizeFloat, SinFloat};

    //переменные
    int size; //количество элементов
    int interval; //интервал
    int minLimitationInt; //ограничение на минимальное значение для целых чисел
    int maxLimitationInt; //ограничение на максимальное значение для целых чисел
    float minLimitationFloat; //ограничение на минимальное значение для чисел с плавающей точкой
    float maxLimitationFloat; //ограничение на максимальное значение для чисел с плавающей точкой

    //ввод значений переменных с файла
    ifstream fin ("Input.txt");
    if (fin.is_open()) { //проверка открытия файла
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
        cout << "Файл не найден или повреждённ" << endl; //сообщение об ошибки
    }
    fin.close(); //закрытие файла

    cout << "Целочисленные последовательности:" << endl;

    //начало отсчёта выполнения алгоритма для целых чисел
    auto beginInt = chrono::steady_clock::now();

    int arrInt[size]; //создание массива целых чисел

    for (int i = 0; i < functionCountInt; i++) {
        MenuInt[i](arrInt, size, minLimitationInt, maxLimitationInt, interval);
        ofstream fout(fileNameInt[i]);
        cout << fileNameInt[i] << ": ";
        for (int j = 0; j < size; j++) {
            cout << "[" << j << "]: " << arrInt[j] << "; ";
            fout << arrInt[j] << ";";
        }
        cout << endl;
        fout.close(); //закрытие файла
    }

    //конец работы алгоритма для целых чисел
    auto endInt = chrono::steady_clock::now();
    //вывод времени затраченого на выполнения алгорима для целых чисел
    cout << "Время работы алгоритма для целых чисел: " << std::chrono::duration_cast<std::chrono::microseconds>(endInt - beginInt).count() << "ms" << endl;
    //запись времени выполнения алгоритма для целых чисел в файл
    //fileTime << std::chrono::duration_cast<std::chrono::microseconds>(endInt - beginInt).count() << ";";

    cout << "Дробные последовательности:" << endl;

    //начало отсчёта выполнения алгоритма для дробных чисел
    auto beginFloat = chrono::steady_clock::now();

    float arrFloat[size]; //создание массива дробных чисел

    for (int i = 0; i < functionCountFloat; i++) {
        MenuFloat[i](arrFloat, size, minLimitationFloat, maxLimitationFloat, interval);
        ofstream fout(fileNameFloat[i]);
        cout << fileNameFloat[i] << ": ";
        for (int j = 0; j < size; j++) {
            cout << "[" << j << "]: " << arrInt[j] << "; ";
            fout << arrInt[j] << ";;";
        }
        cout << endl;
        fout.close(); //закрытие файла
    }

    //Конец работы алгоритма для дробных чисел
    auto endFloat = chrono::steady_clock::now();
    cout << "Время работы алгоритма для дробных чисел: " << std::chrono::duration_cast<std::chrono::microseconds>(endFloat - beginFloat).count() << "ms" << endl;
    //запись времени выполнения алгоритма для дробных чисел в файл
    //fileTime << std::chrono::duration_cast<std::chrono::microseconds>(endFloat - beginFloat).count() << ";";
}