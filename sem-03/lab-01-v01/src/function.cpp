#include "function.h"
#include <math.h>
#include <stdlib.h>
#include <array>

//const float M_PI = 3.14;

// Реализация функций
void* AllRandom( // Функция формирующая случайную последовательность
    int* arrInt, // Массив целых чисел
    float* arrFloat, // Массив дробных чисел
    int& size, // Количество элементов
    float& minLimitation, // Ограничение на минимальное рандомное число
    float& maxLimitation, // Ограничение на максимальное рандомное число
    int& interval // Интервал
) {
    // Алгоритм для целых чисел
    for (int i = 0; i < size; i++) {
        arrInt[i] = round(minLimitation + rand() % int(maxLimitation - minLimitation));
    }
    // Алгоритм для дробных чисел
    for (int i = 0; i < size; i++) {
        arrFloat[i] = minLimitation + rand() % int(maxLimitation - minLimitation);
    }
    return 0;
}

void* UpRegularize( // Функция формирующая упорядоченную последовательность по возрастанию
    int* arrInt, // Массив целых чисел
    float* arrFloat, // Массив дробных чисел
    int& size, // Количество элементов
    float& minLimitation, // Ограничение на минимальное рандомное число
    float& maxLimitation, // Ограничение на максимальное рандомное число
    int& interval // Интервал
) {
    // Алгоритм для целых чисел
    for (int i = 1; i < size; i++) {
        arrInt[i] = round(i * (maxLimitation - minLimitation) / (size - 1) + minLimitation);
    }
    // Алгоритм для дробных чисел
    for (int i = 1; i < size; i++) {
        arrFloat[i] = (i * (maxLimitation - minLimitation) / (size - 1) + minLimitation);
    }
    return 0;
}

void* DownRegularize( // Функция формирующая упорядоченную последовательность по убыванию
    int* arrInt, // Массив целых чисел
    float* arrFloat, // Массив дробных чисел
    int& size, // Количество элементов
    float& minLimitation, // Ограничение на минимальное рандомное число
    float& maxLimitation, // Ограничение на максимальное рандомное число
    int& interval // Интервал
) {
    // Алгоритм для целых чисел
    arrInt[0] = round(minLimitation);
    for (int i = 1; i < size; i++) {
        arrInt[i] = round(i * -(maxLimitation - minLimitation) / (size - 1) + minLimitation);
    }
    // Алгоритм для дробных чисел
    arrFloat[0] = minLimitation;
    for (int i = 1; i < size; i++) {
        arrFloat[i] = (i * -(maxLimitation - minLimitation) / (size - 1) + minLimitation);
    }
    return 0;
}

void* Saw( // Функция формирующая пилообразную последовательность
    int* arrInt, // Массив целых чисел
    float* arrFloat, // Массив дробных чисел
    int& size, // Количество элементов
    float& minLimitation, // Ограничение на минимальное рандомное число
    float& maxLimitation, // Ограничение на максимальное рандомное число
    int& interval // Интервал
) {
    // Алгоритм для целых чисел
    arrInt[0] = 20; // Первый элемент последовательности
    for (int i = 0; i < size; i++) {
        arrInt[i] = round((i % interval) * ((maxLimitation - minLimitation) / interval) + minLimitation);
    }
    // Алгоритм для дробных чисел
    arrFloat[0] = 20; // Первый элемент последовательности
    for (int i = 0; i < size; i++) {
        arrFloat[i] = ((i % interval) * ((maxLimitation - minLimitation) / interval) + minLimitation);
    }
    return 0;
}

void* Step( // Функция формирующая ступенчатую последовательность
    int* arrInt, // Массив целых чисел
    float* arrFloat, // Массив дробных чисел
    int& size, // Количество элементов
    float& minLimitation, // Ограничение на минимальное рандомное число
    float& maxLimitation, // Ограничение на максимальное рандомное число
    int& interval // Интервал
) {
    // Алгоритм для целых чисел
    int lift = 0; // Размер перехода
    for (int i = 0; i < size; i++) {
        if ((i % interval) != 0) { // Достигает периода
            arrInt[i] = (rand() % 5 + 1) + lift;
        }
        else {
            arrInt[i] = (rand() % 10 + 20) + lift;
            lift = arrInt[i]; // Обновление значения перехода
        }
    }
    // Алгоритм для дробных чисел
    lift = 0; // Размер перехода
    for (int i = 0; i < size; i++) {
        if ((i % interval) != 0) { // Достигает периода
            arrFloat[i] = (float(rand() % 100) + 0.6342) + lift;
        }
        else {
            arrFloat[i] = (float(rand() % 100) + 0.6342) + lift;
            lift = arrFloat[i]; // Обновление значения перехода
        }
    }
    return 0;
}

void* QuasiRegularize( //функция формирующая квази-упорядоченную последовательность
    int* arrInt, // Массив целых чисел
    float* arrFloat, // Массив дробных чисел
    int& size, // Количество элементов
    float& minLimitation, // Ограничение на минимальное рандомное число
    float& maxLimitation, // Ограничение на максимальное рандомное число
    int& interval // Интервал
) {
    // Алгоритм для целых чисел
    float temp = 0;
    arrInt[0] = 0; // Первый элемент массива
    for (int i = 1; i < size; i++) {
        arrInt[i] = arrInt[i - 1] + round((maxLimitation-minLimitation)/(size-1));
    }
    for (int i = 1; i < size; i++) {
        if (i % 10 == 0) {
            int a = rand() % (size - 1);
            temp = arrInt[i];
            arrInt[i] = arrInt[a];
            arrInt[a] = round(temp);
        }
    }
    // Алгоритм для дробных чисел
    temp = 0;
    arrFloat[0] = 0; // Первый элемент массива
    for (int i = 1; i < size; i++) {
        arrFloat[i] = arrFloat[i - 1] + 5 + 0.6342;
    }
    for (int i = 1; i < size; i++) {
        if (i % 10 == 0) {
            float a = float(rand() % (size - 1)) + 0.6342;
            temp = arrFloat[i];
            arrFloat[i] = arrFloat[int(a)];
            arrFloat[int(a)] = temp;
        }
    }
    return 0;
}

void* Sin( // Функция формирующая синусоидаобразную последовательность
    int* arrInt, // Массив целых чисел
    float* arrFloat, // Массив дробных чисел
    int& size, // Количество элементов
    float& minLimitation, // Ограничение на минимальное рандомное число
    float& maxLimitation, // Ограничение на максимальное рандомное число
    int& interval // Интервал
) {
    // Алгоритм для целых чисел
    float a = (maxLimitation - minLimitation) / 2;
    float center = minLimitation + a;
    float period = 2 * M_PI;
    for (int i = 0; i < size; i++) {
        arrInt[i] = round((a * sin(2 * M_PI * i / period)) + center);
    }
    // Алгоритм для дробных чисел
    for (int i = 0; i < size; i++) {
        arrFloat[i] = (a * sin(2 * M_PI * i / period)) + center;
    }
    return 0;
}