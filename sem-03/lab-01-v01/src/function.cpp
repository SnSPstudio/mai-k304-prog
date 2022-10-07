#include "function.h"
#include <math.h>
#include <stdlib.h>
#include <array>

//const float M_PI = 3.14;

// Реализация функций
void* AllRandom( // Функция формирующая случайную последовательность
    int* arr, // Массив
    int& size, // Количество элементов
    int& minLimitation, // Ограничение на минимальное рандомное число
    int& maxLimitation, // Ограничение на максимальное рандомное число
    int& interval // Интервал
) {
    // Алгоритм для целых чисел
    for (int i = 0; i < size; i++) {
        arr[i] = minLimitation + rand() % (maxLimitation - minLimitation);
    }
    return 0;
}

void* AllRandom( // Функция формирующая случайную последовательность
    float* arr, // Массив
    int& size, // Количество элементов
    float& minLimitation, // Ограничение на минимальное рандомное число
    float& maxLimitation, // Ограничение на максимальное рандомное число
    int& interval // Интервал
) {
    for (int i = 0; i < size; i++) {
        arr[i] = minLimitation + rand() % int(maxLimitation - minLimitation);
    }
    return 0;
}

void* UpRegularize( // Функция формирующая упорядоченную последовательность по возрастанию
    int* arr, // Массив
    int& size, // Количество элементов
    int& minLimitation, // Ограничение на минимальное рандомное число
    int& maxLimitation, // Ограничение на максимальное рандомное число
    int& interval // Интервал
) {
    // Алгоритм для целых чисел
    for (int i = 1; i < size; i++) {
        arr[i] = i * (maxLimitation - minLimitation) / (size - 1) + minLimitation;
    }
    return 0;
}

void* UpRegularize( // Функция формирующая упорядоченную последовательность по возрастанию
    float* arr, // Массив
    int& size, // Количество элементов
    float& minLimitation, // Ограничение на минимальное рандомное число
    float& maxLimitation, // Ограничение на максимальное рандомное число
    int& interval // Интервал
) {
    for (int i = 1; i < size; i++) {
        arr[i] = (i * (maxLimitation - minLimitation) / (size - 1) + minLimitation);
    }
    return 0;
}

void* DownRegularize( // Функция формирующая упорядоченную последовательность по убыванию
    int* arr, // Массив
    int& size, // Количество элементов
    int& minLimitation, // Ограничение на минимальное рандомное число
    int& maxLimitation, // Ограничение на максимальное рандомное число
    int& interval // Интервал
) {
    // Алгоритм для целых чисел
    arr[0] = minLimitation;
    for (int i = 1; i < size; i++) {
        arr[i] = i * -(maxLimitation - minLimitation) / (size - 1) + minLimitation;
    }
    return 0;
}

void* DownRegularize( // Функция формирующая упорядоченную последовательность по убыванию
    float* arr, // Массив
    int& size, // Количество элементов
    float& minLimitation, // Ограничение на минимальное рандомное число
    float& maxLimitation, // Ограничение на максимальное рандомное число
    int& interval // Интервал
) {
    arr[0] = minLimitation;
    for (int i = 1; i < size; i++) {
        arr[i] = i * -(maxLimitation - minLimitation) / (size - 1) + minLimitation;
    }
    return 0;
}

void* Saw( // Функция формирующая пилообразную последовательность
    int* arr, // Массив
    int& size, // Количество элементов
    int& minLimitation, // Ограничение на минимальное рандомное число
    int& maxLimitation, // Ограничение на максимальное рандомное число
    int& interval // Интервал
) {
    arr[0] = 20; // Первый элемент последовательности
    for (int i = 0; i < size; i++) {
        arr[i] = round((i % interval) * ((maxLimitation - minLimitation) / interval) + minLimitation);
    }
    return 0;
}

void* Saw( // Функция формирующая пилообразную последовательность
    float* arr, // Массив
    int& size, // Количество элементов
    float& minLimitation, // Ограничение на минимальное рандомное число
    float& maxLimitation, // Ограничение на максимальное рандомное число
    int& interval // Интервал
) {
    arr[0] = 20; // Первый элемент последовательности
    for (int i = 0; i < size; i++) {
        arr[i] = ((i % interval) * ((maxLimitation - minLimitation) / interval) + minLimitation);
    }
    return 0;
}

void* Step( // Функция формирующая ступенчатую последовательность
    int* arr, // Массив
    int& size, // Количество элементов
    int& minLimitation, // Ограничение на минимальное рандомное число
    int& maxLimitation, // Ограничение на максимальное рандомное число
    int& interval // Интервал
) {
    // Алгоритм для целых чисел
    int lift = 0; // Размер перехода
    for (int i = 0; i < size; i++) {
        if ((i % interval) != 0) { // Достигает периода
            arr[i] = (rand() % 5 + 1) + lift;
        }
        else {
            arr[i] = (rand() % 10 + 20) + lift;
            lift = arr[i]; // Обновление значения перехода
        }
    }
    return 0;
}

void* Step( // Функция формирующая ступенчатую последовательность
    float* arr, // Массив
    int& size, // Количество элементов
    float& minLimitation, // Ограничение на минимальное рандомное число
    float& maxLimitation, // Ограничение на максимальное рандомное число
    int& interval // Интервал
) {
    float lift = 0; // Размер перехода
    for (int i = 0; i < size; i++) {
        if ((i % interval) != 0) { // Достигает периода
            arr[i] = (float(rand() % 100) + 0.6342) + lift;
        }
        else {
            arr[i] = (float(rand() % 100) + 0.6342) + lift;
            lift = arr[i]; // Обновление значения перехода
        }
    }
    return 0;
}

void* QuasiRegularize( //функция формирующая квази-упорядоченную последовательность
    int* arr, // Массив
    int& size, // Количество элементов
    int& minLimitation, // Ограничение на минимальное рандомное число
    int& maxLimitation, // Ограничение на максимальное рандомное число
    int& interval // Интервал
) {
    // Алгоритм для целых чисел
    int temp = 0;
    arr[0] = 0; // Первый элемент массива
    for (int i = 1; i < size; i++) {
        arr[i] = arr[i - 1] + round((maxLimitation-minLimitation)/(size-1));
    }
    for (int i = 1; i < size; i++) {
        if (i % 10 == 0) {
            int a = rand() % (size - 1);
            temp = arr[i];
            arr[i] = arr[a];
            arr[a] = temp;
        }
    }
    return 0;
}

void* QuasiRegularize( //функция формирующая квази-упорядоченную последовательность
    float* arr, // Массив
    int& size, // Количество элементов
    float& minLimitation, // Ограничение на минимальное рандомное число
    float& maxLimitation, // Ограничение на максимальное рандомное число
    int& interval // Интервал
) {
    float temp = 0;
    arr[0] = 0; // Первый элемент массива
    for (int i = 1; i < size; i++) {
        arr[i] = arr[i - 1] + 5 + 0.6342;
    }
    for (int i = 1; i < size; i++) {
        if (i % 10 == 0) {
            int a = int(rand() % (size - 1) + 0.6342);
            temp = arr[i];
            arr[i] = arr[a];
            arr[a] = temp;
        }
    }
    return 0;
}

void* Sin( // Функция формирующая синусоидаобразную последовательность
    int* arr, // Массив
    int& size, // Количество элементов
    int& minLimitation, // Ограничение на минимальное рандомное число
    int& maxLimitation, // Ограничение на максимальное рандомное число
    int& interval // Интервал
) {
    // Алгоритм для целых чисел
    float a = (maxLimitation - minLimitation) / 2;
    float center = minLimitation + a;
    float period = 2 * M_PI;
    for (int i = 0; i < size; i++) {
        arr[i] = round((a * sin(2 * M_PI * i / period)) + center);
    }
    return 0;
}

void* Sin( // Функция формирующая синусоидаобразную последовательность
    float* arr, // Массив
    int& size, // Количество элементов
    float& minLimitation, // Ограничение на минимальное рандомное число
    float& maxLimitation, // Ограничение на максимальное рандомное число
    int& interval // Интервал
) {
    float a = (maxLimitation - minLimitation) / 2;
    float center = minLimitation + a;
    float period = 2 * M_PI;
    for (int i = 0; i < size; i++) {
        arr[i] = (a * sin(2 * M_PI * i / period)) + center;
    }
    return 0;
}