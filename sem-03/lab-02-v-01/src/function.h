#ifndef FUNCTION_H
#define FUNCTION_H

// Прототипы функций

// Функции генерации последовательностей
void* allRandom ( // Функция формирующая случайную последовательность
    int* arr, // Массив
    int& size, // Количество элементов
    int& interval, // Интервал
    int& minLimitation, // Ограничение на минимальное число
    int& maxLimitation // Ограничение на максимальное число
);

void* allRandom ( // Функция формирующая случайную последовательность
    float* arr, // Массив
    int& size, // Количество элементов
    int& interval, // Интервал
    float& minLimitation, // Ограничение на минимальное число
    float& maxLimitation // Ограничение на максимальное число
);

void* upRegularize ( // Функция формирующая упорядоченную последовательность по возрастанию
    int* arr, // Массив
    int& size, // Количество элементов
    int& interval, // Интервал
    int& minLimitation, // Ограничение на минимальное число
    int& maxLimitation // Ограничение на максимальное число
);

void* upRegularize ( // Функция формирующая упорядоченную последовательность по возрастанию
    float* arr, // Массив
    int& size, // Количество элементов
    int& interval, // Интервал
    float& minLimitation, // Ограничение на минимальное число
    float& maxLimitation // Ограничение на максимальное число
);

// Функции сортировки последовательностей

// Алгоритм Better Linear Search
int* betterLinearSearch (int* arr, int& size, int& key);
int* betterLinearSearch (float* arr, int& size, float& key);

// Алгоритм Sentinel Linear Search
int* sentinelLinearSearch (int* arr, int& size, int& key);
int* sentinelLinearSearch (float* arr, int& size, float& key);

// Алгоритм бинарного поиска
int* binarySearch (int* arr, int& size, int& key);
int* binarySearch (float* arr, int& size, float& key);

#endif