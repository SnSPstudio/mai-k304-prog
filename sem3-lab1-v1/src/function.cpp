#include "function.h"
#include <math.h>

//реализация функций
//функции работы с целыми числами
int* AllRandomInt( //функция формирующая случайную последовательность
    int* arr, //массив
    int& size, //количество элементов
    int& minLimitation, //ограничение на минимальное рандомное число
    int& maxLimitation, //ограничение на максимальное рандомное число
    int& interval //интервал
) {
    for (int i = 0; i < size; i++) {
        arr[i] = minLimitation + rand() % (maxLimitation - minLimitation);
    }
    return arr;
}

int* UpRegularizeInt( //функция формирующая упорядоченную последовательность по возрастанию
    int* arr, //массив
    int& size, //количество элементов
    int& minLimitation, //ограничение на минимальное рандомное число
    int& maxLimitation, //ограничение на максимальное рандомное число
    int& interval //интервал
) {
    for (int i = 1; i < size; i++) {
        arr[i] = (i * round((maxLimitation - minLimitation) / (size - 1)) + minLimitation);
    }
    return arr;
}

int* DownRegularizeInt( //функция формирующая упорядоченную последовательность по убыванию
    int* arr, //массив
    int& size, //количество элементов
    int& minLimitation, //ограничение на минимальное рандомное число
    int& maxLimitation, //ограничение на максимальное рандомное число
    int& interval //интервал
) {
    arr[0] = minLimitation;
    for (int i = 1; i < size; i++) {
        arr[i] = (i * -round((maxLimitation - minLimitation) / (size - 1)) + minLimitation);
    }
    return arr;
}

int* SawInt( //функция формирующая пилообразную последовательность
    int* arr, //массив
    int& size, //количество элементов
    int& minLimitation, //ограничение на минимальное рандомное число
    int& maxLimitation, //ограничение на максимальное рандомное число
    int& interval //интервал
) {
    arr[0] = 20; //первый элемент последовательности
    for (int i = 0; i < size; i++) {
        arr[i] = ((i % interval) * (round((maxLimitation - minLimitation) / interval)) + minLimitation);
    }
    return arr;
}

int* StepInt( //функция формирующая ступенчатую последовательность
    int* arr, //массив
    int& size, //количество элементов
    int& minLimitation, //ограничение на минимальное рандомное число
    int& maxLimitation, //ограничение на максимальное рандомное число
    int& interval //интервал
) {
    int lift = 0; //размер перехода
    for (int i = 0; i < size; i++) {
        if ((i % interval) != 0) { //достигает периода
            arr[i] = (rand() % 5 + 1) + lift;
        }
        else {
            arr[i] = (rand() % 10 + 20) + lift;
            lift = arr[i]; //обновление значения перехода
        }
    }
    return arr;
}

int* QuasiRegularizeInt( //функция формирующая квази-упорядоченную последовательность
    int* arr, //массив
    int& size, //количество элементов
    int& minLimitation, //ограничение на минимальное рандомное число
    int& maxLimitation, //ограничение на максимальное рандомное число
    int& interval //интервал
) {
    int temp = 0;
    arr[0] = 0;
    for (int i = 1; i < size; i++) {
        arr[i] = arr[i - 1] + 5;
    }
    for (int i = 1; i < size; i++) {
        if (i % 10 == 0) {
            int a = rand() % (size - 1);
            temp = arr[i];
            arr[i] = arr[a];
            arr[a] = temp;
        }
    }
    return arr;
}

int* SinInt( //функция формирующая синусоидаобразную последовательность
    int* arr, //массив
    int& size, //количество элементов
    int& minLimitation, //ограничение на минимальное рандомное число
    int& maxLimitation, //ограничение на максимальное рандомное число
    int& interval //интервал
) {
    for (int i = 0; i < size; i++) {
        arr[i] = int(((maxLimitation - minLimitation) / 2 * sin(2 * M_PI * i / interval)) + (maxLimitation + minLimitation) / 2);
    }
    return arr;
}

//функции работы с числами с плавающей запятой
float* AllRandomFloat( //функция формирующая случайную последовательность
    float* arr, //массив
    int& size, //количество элементов
    float& minLimitation, //ограничение на минимальное рандомное число
    float& maxLimitation, //ограничение на максимальное рандомное число
    int& interval //интервал
) {
    for (int i = 0; i < size; i++) {
        arr[i] = minLimitation + rand() % int(maxLimitation - minLimitation);
    }
    return arr;
}

float* UpRegularizeFloat( //функция формирующая упорядоченную последовательность по возрастанию
    float* arr, //массив
    int& size, //количество элементов
    float& minLimitation, //ограничение на минимальное рандомное число
    float& maxLimitation, //ограничение на максимальное рандомное число
    int& interval //интервал
) {
    for (int i = 1; i < size; i++) {
        arr[i] = (i * (maxLimitation - minLimitation) / (size - 1) + minLimitation);
    }
    return arr;
}

float* DownRegularizeFloat( //функция формирующая упорядоченную последовательность по убыванию
    float* arr, //массив
    int& size, //количество элементов
    float& minLimitation, //ограничение на минимальное рандомное число
    float& maxLimitation, //ограничение на максимальное рандомное число
    int& interval //интервал
) {
    arr[0] = minLimitation;
    for (int i = 1; i < size; i++) {
        arr[i] = (i * -(maxLimitation - minLimitation) / (size - 1) + minLimitation);
    }
    return arr;
}

float* SawFloat( //функция формирующая пилообразную последовательность
    float* arr, //массив
    int& size, //количество элементов
    float& minLimitation, //ограничение на минимальное рандомное число
    float& maxLimitation, //ограничение на максимальное рандомное число
    int& interval //интервал
) {
    arr[0] = 20; //первый элемент последовательности
    for (int i = 0; i < size; i++) {
        arr[i] = ((i % interval) * ((maxLimitation - minLimitation) / interval) + minLimitation);
    }
    return arr;
}

float* StepFloat( //функция формирующая ступенчатую последовательность
    float* arr, //массив
    int& size, //количество элементов
    float& minLimitation, //ограничение на минимальное рандомное число
    float& maxLimitation, //ограничение на максимальное рандомное число
    int& interval //интервал
) {
    int lift = 0; //размер перехода
    for (int i = 0; i < size; i++) {
        if ((i % interval) != 0) { //достигает периода
            arr[i] = (float(rand() % 100) + 0.6342) + lift;
        }
        else {
            arr[i] = (float(rand() % 100) + 0.6342) + lift;
            lift = arr[i]; //обновление значения перехода
        }
    }
    return arr;
}

float* QuasiRegularizeFloat( //функция формирующая квази-упорядоченную последовательность
    float* arr, //массив
    int& size, //количество элементов
    float& minLimitation, //ограничение на минимальное рандомное число
    float& maxLimitation, //ограничение на максимальное рандомное число
    int& interval //интервал
) {
    int temp = 0;
    arr[0] = 0;
    for (int i = 1; i < size; i++) {
        arr[i] = arr[i - 1] + 5 + 0.6342;
    }
    for (int i = 1; i < size; i++) {
        if (i % 10 == 0) {
            int a = float(rand() % (size - 1)) + 0.6342;
            temp = arr[i];
            arr[i] = arr[a];
            arr[a] = temp;
        }
    }
    return arr;
}

float* SinFloat( //функция формирующая синусоидаобразную последовательность
    float* arr, //массив
    int& size, //количество элементов
    float& minLimitation, //ограничение на минимальное рандомное число
    float& maxLimitation, //ограничение на максимальное рандомное число
    int& interval //интервал
) {
    for (int i = 0; i < size; i++) {
        arr[i] = ((maxLimitation - minLimitation) / 2 * sin(2 * M_PI * i / interval)) + (maxLimitation + minLimitation) / 2;
    }
    return arr;
}