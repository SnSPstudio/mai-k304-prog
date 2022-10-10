#ifndef FUNCTION_H
#define FUNCTION_H

// Прототипы функций
void* AllRandom( // Функция формирующая случайную последовательность
    int* arr, // Массив
    int& size, // Количество элементов
    int& interval, // Интервал
    int& minLimitation, // Ограничение на минимальное число
    int& maxLimitation // Ограничение на максимальное число
);

void* AllRandom( // Функция формирующая случайную последовательность
    float* arr, // Массив
    int& size, // Количество элементов
    int& interval, // Интервал
    float& minLimitation, // Ограничение на минимальное число
    float& maxLimitation // Ограничение на максимальное число
);

void* UpRegularize( // Функция формирующая упорядоченную последовательность по возрастанию
    int* arr, // Массив
    int& size, // Количество элементов
    int& interval, // Интервал
    int& minLimitation, // Ограничение на минимальное число
    int& maxLimitation // Ограничение на максимальное число
);

void* UpRegularize( // Функция формирующая упорядоченную последовательность по возрастанию
    float* arr, // Массив
    int& size, // Количество элементов
    int& interval, // Интервал
    float& minLimitation, // Ограничение на минимальное число
    float& maxLimitation // Ограничение на максимальное число
);

void* DownRegularize( // Функция формирующая упорядоченную последовательность по убыванию
    int* arr, // Массив
    int& size, // Количество элементов
    int& interval, // Интервал
    int& minLimitation, // Ограничение на минимальное число
    int& maxLimitation // Ограничение на максимальное число
);

void* DownRegularize( // Функция формирующая упорядоченную последовательность по убыванию
    float* arr, // Массив
    int& size, // Количество элементов
    int& interval, // Интервал
    float& minLimitation, // Ограничение на минимальное число
    float& maxLimitation // Ограничение на максимальное число
);

#endif