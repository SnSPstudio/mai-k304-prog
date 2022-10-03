#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double x;
    double chisl;     // Числитель в слагаемом
    double tsum;      // Точная сумма
    double sum;       // Получаемая сумма
    double slag;      // Слагаемое
    double diff;      // Получемая разность с точной суммой
    double eps;       // Задаваемая точность
    long double fact; // Факториал
    int n;            // Количество слагаемых
    short znak;       // Переменная, отвечающая за смену знака слагаемого
    cout << "Пожалуйста, введите значение переменной.\nВаш ответ:";
    cin >> x;
    cout << "Пожалуйста, введите точность.\nВаш ответ:";
    cin >> eps;
    if (eps <= 0) {
        cout << "Eps д.б. > 0" << endl;
        exit(1);
    }
    

    tsum = sin(x);
    chisl = 0;
    diff = eps;
    sum = 0;
    n = 0;
    znak = -1;

    /**************
     Основной цикл
    **************/
    while (diff >= eps)
    {
        n++;                    //следующий n
        diff = abs(tsum - sum); //считаем модуль разности 
        znak = -znak;
        chisl = chisl * x * x;
        if (n == 1) {
            fact = 1;
        }
        else {
            fact = fact * ((2 * n) - 1) * ((2 * n) - 2);
        }
        slag = znak * chisl / fact; // формируем слагаемое
        sum = sum + slag;
        //cout << n << ".  fact=" << fact << " chisl = " <<chisl << " sum=" << sum  << "\n" << endl;// контрольный вывод
    }
    /*************
     Вывод данных
     ************/
    cout << "\nКоличество элементов = " << n
         << "\ntsum = " << tsum
         << "\nSum = " << sum
         << "\nEps = " << eps
         << "\nDiff = " << diff << endl;
}