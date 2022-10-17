#include "function.h"
#include <stdlib.h>
#include <math.h>

// Реализация функций
void* allRandom( // Функция формирующая случайную последовательность
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

void* allRandom( // Функция формирующая случайную последовательность
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

void* upRegularize( // Функция формирующая упорядоченную последовательность по возрастанию
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

void* upRegularize( // Функция формирующая упорядоченную последовательность по возрастанию
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

void* downRegularize( // Функция формирующая упорядоченную последовательность по убыванию
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

void* downRegularize( // Функция формирующая упорядоченную последовательность по убыванию
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

void* saw( // Функция формирующая пилообразную последовательность
    int* arr, // Массив
    int& size, // Количество элементов
    int& interval, // Интервал
    int& minLimitation, // Ограничение на минимальное число
    int& maxLimitation // Ограничение на максимальное число
) {
    for (int i = 0; i < size; i++) {
        arr[i] = int((i % interval) * (((maxLimitation - minLimitation)) / interval) + minLimitation);
    }
    return 0;
}

void* saw( // Функция формирующая пилообразную последовательность
    float* arr, // Массив
    int& size, // Количество элементов
    int& interval, // Интервал
    float& minLimitation, // Ограничение на минимальное число
    float& maxLimitation // Ограничение на максимальное число
) {
    for (int i = 0; i < size; i++) {
        arr[i] = (i % interval) * ((maxLimitation - minLimitation) / interval) + minLimitation;
    }
    return 0;
}

void* step( // Функция формирующая ступенчатую последовательность
    int* arr, // Массив
    int& size, // Количество элементов
    int& interval, // Интервал
    int& minLimitation, // Ограничение на минимальное число
    int& maxLimitation // Ограничение на максимальное число
) {
    for (int i = 1; i < size; i++)
    {
        if (arr[i] <= maxLimitation)
        {
            if (i % interval == 0) {
                arr[i] = int(arr[i - 1] + interval);
            } else {
                arr[i] = arr[i - 1];
            }
        }
    }
    return 0;
}

void* step( // Функция формирующая ступенчатую последовательность
    float* arr, // Массив
    int& size, // Количество элементов
    int& interval, // Интервал
    float& minLimitation, // Ограничение на минимальное число
    float& maxLimitation // Ограничение на максимальное число
) {
    for (int i = 1; i < size; i++)
    {
        if (arr[i] <= maxLimitation)
        {
            if (i % interval == 0) {
                arr[i] = arr[i - 1] + interval;
            } else {
                arr[i] = arr[i - 1];
            }
        }
    }
    return 0;
}

void* sin( // Функция формирующая синусоидаобразную последовательность
    int* arr, // Массив
    int& size, // Количество элементов
    int& interval, // Интервал
    int& minLimitation, // Ограничение на минимальное число
    int& maxLimitation // Ограничение на максимальное число
) {
    for (int i = 0; i < size; i++)
    {
        arr[i] = int(((maxLimitation - minLimitation) / 2) * sin(2 * M_PI * i / interval) + ((maxLimitation + minLimitation) / 2));
    }
    return 0;
}

void* sin( // Функция формирующая синусоидаобразную последовательность
    float* arr, // Массив
    int& size, // Количество элементов
    int& interval, // Интервал
    float& minLimitation, // Ограничение на минимальное число
    float& maxLimitation // Ограничение на максимальное число
) {
    for (int i = 0; i < size; i++)
    {
        arr[i] = ((maxLimitation - minLimitation) / 2) * sin(2 * M_PI * i / interval) + ((maxLimitation + minLimitation) / 2);
    }
    return 0;
}