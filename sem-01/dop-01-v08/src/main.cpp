#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    int* AVec;   //Исходный массив
    int size = 0;    //Размер массива
    int step;    //На сколько элементов сдвигаем
    int temp;    //Переменная для временного хранения
    bool flag = false; //Флажок, говорящий нам о нахождении символов в массиве
    string answ; //Ответы пользователя
    string f_name = "input.txt"; //имя открываемого файла
    /****************
    ---ВВОД ДАННЫХ---
    ****************/


    ifstream ifs(f_name);

    /*********************************
    --ПРОВЕРКА ФАЙЛА НА КОРРЕКТНОСТЬ--
    *********************************/
    if (!ifs) { // Если файл не открыт
        cout << "Файл не найден" << endl;
        exit(1);
    }
    while (!ifs.eof()) {                                     //проверка содержания файла
        ifs >> temp;
        if (ifs.fail()) {
            if (temp && flag == false) {
                cout << "Файл пуст." << endl;
                ifs.close();
                exit(2);
            }
            else {
                
                    cout << "Обнаружены некорректные символы.\nПроверьте исходный файл с данными " << f_name << endl;
                    ifs.close();
                    exit(2);
                
            }
        }
        flag = true;
        size++;
    }
    size-=1
    ifs.seekg(0, ios::beg);                                  //Возращение в начало файла
    if (size == 1) {
        cout << "Массив из одного элемента" << endl;
        exit(2);
    }
    AVec = new int[size];
    cout << "Полученный массив:" << endl;
    for (int i = 0; i < size; i++) {
        ifs >> AVec[i];
        cout << AVec[i] << " ";
    }

    /****************************
   --ЦИКЛИЧЕСКИЙ СДВИГ МАССИВА--
   ****************************/


    cout << "\nНасколько сдвинуть массив?\nОтвет задайте числом." << endl;
    cin >> step;                         //Получаем информацию о сдвиге

   
    for (int i = 0; i < step; i++) {
        temp = AVec[size - 1];            //Запоминаем последний элемент
        for (int j = size - 2; j >= 0; j--) { //Сам сдвиг элементов
            AVec[j + 1] = AVec[j];
        }
        AVec[0] = temp;
        for (int k = 0; k < size; k++)cout << AVec[k] << " ";
        cout << "\n";
    }
}