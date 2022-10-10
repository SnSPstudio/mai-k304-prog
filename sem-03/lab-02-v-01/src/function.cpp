#include "function.h"
#include <math.h>
#include <stdlib.h>
#include <array>

//const float M_PI = 3.14;

// Реализация функций
void* AllRandom( // Функция формирующая случайную последовательность
    int* arr, // Массив
    int& size, // Количество элементов
    int& interval, // Интервал
    int& minLimitation, // Ограничение на минимальное число
    int& maxLimitation // Ограничение на максимальное число
) {
    for (int i = 0; i < size; i++) {
        arr[i] = minLimitation + rand() % (maxLimitation - minLimitation);
    }
    return 0;
}

void* AllRandom( // Функция формирующая случайную последовательность
    float* arr, // Массив
    int& size, // Количество элементов
    int& interval, // Интервал
    float& minLimitation, // Ограничение на минимальное число
    float& maxLimitation // Ограничение на максимальное число
) {
    for (int i = 0; i < size; i++) {
        arr[i] = minLimitation + rand() % int(maxLimitation - minLimitation);
    }
    return 0;
}

void* UpRegularize( // Функция формирующая упорядоченную последовательность по возрастанию
    int* arr, // Массив
    int& size, // Количество элементов
    int& interval, // Интервал
    int& minLimitation, // Ограничение на минимальное число
    int& maxLimitation // Ограничение на максимальное число
) {
    for (int i = 0; i < size; i++) {
        arr[i] = i * (maxLimitation - minLimitation) / (size - 1) + minLimitation;
    }
    return 0;
}

void* UpRegularize( // Функция формирующая упорядоченную последовательность по возрастанию
    float* arr, // Массив
    int& size, // Количество элементов
    int& interval, // Интервал
    float& minLimitation, // Ограничение на минимальное число
    float& maxLimitation // Ограничение на максимальное число
) {
    for (int i = 0; i < size; i++) {
        arr[i] = (i * (maxLimitation - minLimitation) / (size - 1) + minLimitation);
    }
    return 0;
}

void* DownRegularize( // Функция формирующая упорядоченную последовательность по убыванию
    int* arr, // Массив
    int& size, // Количество элементов
    int& interval, // Интервал
    int& minLimitation, // Ограничение на минимальное число
    int& maxLimitation // Ограничение на максимальное число
) {
    for (int i = 0; i < size; i++) {
        arr[i] = i * -(maxLimitation - minLimitation) / (size - 1) + minLimitation;
    }
    return 0;
}

void* DownRegularize( // Функция формирующая упорядоченную последовательность по убыванию
    float* arr, // Массив
    int& size, // Количество элементов
    int& interval, // Интервал
    float& minLimitation, // Ограничение на минимальное число
    float& maxLimitation // Ограничение на максимальное число
) {
    for (int i = 0; i < size; i++) {
        arr[i] = i * -(maxLimitation - minLimitation) / (size - 1) + minLimitation;
    }
    return 0;
}