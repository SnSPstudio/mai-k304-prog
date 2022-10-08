/****************************************************************************************
*                                                                                       *
*****************************************************************************************
*Project type :Win64 Console Application                                                *
*Project name :Лаба 7                                                                   *
*File name    :Лаба 7.exe                                                               *
*Language     :CPP, MSVS 2019                                                           *
*Programmers  :Вожегов Артём Алексеевич, Виноградова Ольга Геннадьевна                  *
*Modified By  :                                                                         *
*Created      :21.10.2022                                                               *
*Last revision:xx.xx.2022                                                               *
*                                                                                       *
*Comment      :Формирование массивов эксперементальных данных                           *
****************************************************************************************/

#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <chrono>
using namespace std;

const int CountFunc = 5;

const char EnterData[] = "Data1.txt";
//const char EnterData[] = "Data2.txt";
//const char EnterData[] = "Data3.txt";
//const char EnterData[] = "Data4.txt";

const char OutIntTime[] = "FuncIntTime.txt";
const char OutRealTime[] = "FuncRealTime.txt";

const char* OutIntData[] = 
{ 
    "IncreaseSequenceInt.txt",
    "DecreaseSequenceInt.txt",
    "RandomSequenceInt.txt",
    "SawtoothSequenceInt.txt",
    "StepSequenceInt.txt" 
};
const char* OutRealData[] = 
{ 
    "IncreaseSequenceReal.txt",
    "DecreaseSequenceReal.txt",
    "RandomSequenceReal.txt",
    "SawtoothSequenceReal.txt",
    "StepSequenceReal.txt"
};

/****************************************************************************************
*                                                                                       *
*                           П Р О Т О Т И П Ы   Ф У Н К Ц И Й                           *
*                                                                                       *
****************************************************************************************/

void ReadData   (double** realArray, int** intArray, int& arrayLenght, int& period, double& step, double& minValue, double& maxValue);

void GetIncreaseSequence(int** array, int arrayLenght, int period, double step, double minValue, double maxValue);
void GetDecreaseSequence(int** array, int arrayLenght, int period, double step, double minValue, double maxValue);
void GetRandomSequence  (int** array, int arrayLenght, int period, double step, double minValue, double maxValue);
void GetSawtoothSequence(int** array, int arrayLenght, int period, double step, double minValue, double maxValue);
void GetStepSequence    (int** array, int arrayLenght, int period, double step, double minValue, double maxValue);

void GetIncreaseSequence(double** array, int arrayLenght, int period, double step, double minValue, double maxValue);
void GetDecreaseSequence(double** array, int arrayLenght, int period, double step, double minValue, double maxValue);
void GetRandomSequence  (double** array, int arrayLenght, int period, double step, double minValue, double maxValue);
void GetSawtoothSequence(double** array, int arrayLenght, int period, double step, double minValue, double maxValue);
void GetStepSequence    (double** array, int arrayLenght, int period, double step, double minValue, double maxValue);

/****************************************************************************************
*                                                                                       *
*                      О С Н О В Н О Й   К О Д   П Р О Г Р А М М Ы                      *
*                                                                                       *
****************************************************************************************/

int main()
{
    void (*IntFuncs[CountFunc])(int** array, int arrayLenght, int period, double step, double minValue, double maxValue) = 
    {
        GetIncreaseSequence,
        GetDecreaseSequence,
        GetRandomSequence,
        GetSawtoothSequence,
        GetStepSequence
    };
    void (*RealFuncs[CountFunc])(double** array, int arrayLenght, int period, double step, double minValue, double maxValue) =
    {
        GetIncreaseSequence,
        GetDecreaseSequence,
        GetRandomSequence,
        GetSawtoothSequence,
        GetStepSequence
    };
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    double* realArray;
    int* intArray;
    int arrayLenght;
    int period;
    double step;
    double minValue;
    double maxValue;

    ReadData(&realArray, &intArray, arrayLenght, period, step, minValue, maxValue);
    if (arrayLenght >= 150 && arrayLenght <= 200)
    {
        for (int i = 0; i < CountFunc; i++)
        {
            IntFuncs[i](&intArray, arrayLenght, period, step, minValue, maxValue);
            RealFuncs[i](&realArray, arrayLenght, period, step, minValue, maxValue);
            ofstream fout(OutIntData[i]);
            for (int j = 0; j < arrayLenght; j++)
                fout << intArray[j] << endl;
            fout.close();

            fout.open(OutRealData[i]);
            for (int j = 0; j < arrayLenght; j++)
                fout << realArray[j] << endl;
            fout.close();
        }
    }
    else
    {
        int count = arrayLenght / 200;

        ofstream fout(OutIntTime);
        for (int i = 0; i < CountFunc; i++)
        {
            auto pointTime = chrono::steady_clock::now();
            for (int j = 0; j < count; j++)
                IntFuncs[i](&intArray, arrayLenght, period, step, minValue, maxValue);
            auto totalTime = chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now() - pointTime);
            fout << totalTime.count() << 'mc\n\n' << endl;
            cout << totalTime.count() << "нc" << endl;
        }
        fout.close();

        cout << endl;

        fout.open(OutRealTime);
        for (int i = 0; i < CountFunc; i++)
        {
            auto pointTime = chrono::steady_clock::now();
            for (int j = 0; j < count; j++)
                RealFuncs[i](&realArray, arrayLenght, period, step, minValue, maxValue);
            auto totalTime = chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now() - pointTime);
            fout << totalTime.count() << 'mc\n\n' << endl;
            cout << totalTime.count() << "нс" << endl;
        }
        fout.close();
    }
    delete[]intArray;
    delete[]realArray;
}

/****************************************************************************************
*                                                                                       *
*                       Р Е А Л И З А Ц И Я   Ф У Н К Ц И Й                             *
*                                                                                       *
****************************************************************************************/

// ----- Чтение входных данных из файла ----- //
void ReadData(double** realArray, int** intArray, int& arrayLenght, int& period, double& step, double& minValue, double& maxValue)
{
    ifstream fin(EnterData);
    fin >> arrayLenght;
    fin >> period;
    fin >> step;
    fin >> minValue;
    fin >> maxValue;
    (*intArray) = new int[arrayLenght];
    (*realArray) = new double[arrayLenght];
}

//===================================================//
// - - - - - БЛОК ЦЕЛОЧИСЛЕННЫХ ПЕРЕГРУЗОК - - - - - //
//===================================================//

// ----- Формирование упорядоченной по возростанию последовательности ----- //
void GetIncreaseSequence(int** array, int arrayLenght, int period, double step, double minValue, double maxValue)
{
    double multiplier = (maxValue - minValue) / arrayLenght;
    for (int i = 0; i < arrayLenght; i++)
        (*array)[i] = int(i * multiplier + minValue);
}
// ----- Формирование упорядоченной по убыванию последовательности ----- //
void GetDecreaseSequence(int** array, int arrayLenght, int period, double step, double minValue, double maxValue)
{
    double multiplier = (maxValue - minValue) / arrayLenght;
    for (int i = 0; i < arrayLenght; i++)
        (*array)[i] = int(i * -multiplier + maxValue);
}
// ----- Формирование случайной последовательности ----- //
void GetRandomSequence  (int** array, int arrayLenght, int period, double step, double minValue, double maxValue)
{
    srand(time(NULL));
    for (int i = 0; i < arrayLenght; i++)
        (*array)[i] = int((maxValue - minValue) * rand() / RAND_MAX + minValue);
}
// ----- Формирование пилообразной последовательности ----- //
void GetSawtoothSequence(int** array, int arrayLenght, int period, double step, double minValue, double maxValue)
{
    double multiplier = (maxValue - minValue) / period;
    int count = 0;
    while (count != int(arrayLenght / period))
    {
        for (int i = 0; i < period; i++)
        {
            if (i % period == 0)
                (*array)[i + count * period] = int(minValue);
            else
                (*array)[i + count * period] = int((multiplier * i) + minValue);
        }
        count++;
    }
}
// ----- Формирование ступенчатой последовательности ----- //
void GetStepSequence    (int** array, int arrayLenght, int period, double step, double minValue, double maxValue)
{
    (*array)[0] = int(minValue);
    for (int i = 1; i < arrayLenght; i++)
    {
        if ((*array)[i] <= maxValue)
        {
            if (i % period == 0)
                (*array)[i] = int((*array)[i - 1] + step);
            else
                (*array)[i] = (*array)[i - 1];
        }
    }
}

//==================================================//
// - - - - - БЛОК ВЕЩЕСТВЕННЫХ ПЕРЕГРУЗОК - - - - - //
//==================================================//

// ----- Формирование упорядоченной по возростанию последовательности ----- //
void GetIncreaseSequence(double** array, int arrayLenght, int period, double step, double minValue, double maxValue)
{
    double multiplier = (maxValue - minValue) / arrayLenght;
    for (int i = 0; i < arrayLenght; i++)
        (*array)[i] = i * multiplier + minValue;
}
// ----- Формирование упорядоченной по убыванию последовательности ----- //
void GetDecreaseSequence(double** array, int arrayLenght, int period, double step, double minValue, double maxValue)
{
    double multiplier = (maxValue - minValue) / arrayLenght;
    for (int i = 0; i < arrayLenght; i++)
        (*array)[i] = i * -multiplier + maxValue;
}
// ----- Формирование случайной последовательности ----- //
void GetRandomSequence  (double** array, int arrayLenght, int period, double step, double minValue, double maxValue)
{
    srand(time(NULL));
    for (int i = 0; i < arrayLenght; i++)
        (*array)[i] = (maxValue - minValue) * rand() / RAND_MAX + minValue;
}
// ----- Формирование пилообразной последовательности ----- //
void GetSawtoothSequence(double** array, int arrayLenght, int period, double step, double minValue, double maxValue)
{
    double multiplier = (maxValue - minValue) / period;
    int count = 0;
    while (count != int(arrayLenght / period))
    {
        for (int i = 0; i < period; i++)
        {
            if (i % period == 0)
                (*array)[i + count * period] = minValue;
            else
                (*array)[i + count * period] = multiplier * i + minValue;
        }
        count++;
    }
}
// ----- Формирование ступенчатой последовательности ----- //
void GetStepSequence    (double** array, int arrayLenght, int period, double step, double minValue, double maxValue)
{
    (*array)[0] = minValue;
    for (int i = 1; i < arrayLenght; i++)
    {
        if ((*array)[i] <= maxValue)
        {
            if (i % period == 0)
                (*array)[i] = (*array)[i - 1] + step;
            else
                (*array)[i] = (*array)[i - 1];
        }
    }
}