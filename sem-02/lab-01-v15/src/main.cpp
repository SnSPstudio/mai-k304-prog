#include <iostream>
#include <fstream>



using namespace std;



int main()
{
    setlocale(LC_ALL, "Russian");

    const int nString = 2;   //Количество строк

    int LenStr[nString];     //Длины строк

    char* str1;              //Первая строка
    char* str2;              //Вторая строка
    char* SumStr;            //Результат объединения строк
    char* word;              //Повторяющееся слово

    char temp = ' ';         //Переменная, временно хранящая в себе символ, считываемый с файла   

    int bw1 = 0;             //Начало слова в 1 строке
    int ew1 = 1;             //Конец слова в первой строке

    int bw2 = 0;              //Начало слова
    int ew2 = 1;              //Конец слова

    int n = 0;
    int n1 = 0;
    int n2 = 0;

    bool check = true;        //Флажок проверки совпадения слова
    bool find = false;       //Нашли ли слово
    bool space = false;
    bool exit = false;       //Выходим ли из цикла

    bool incorrect = false;  //Корректны ли входные данные






    /***********************************
    *           ВВОД ДАННЫХ            *
    ***********************************/

    const char f_name[] = "test_01.txt";

    ifstream ifs(f_name);

    if (ifs.is_open())
    {

        for (int i = 0; i < nString; i++)
        {
            LenStr[i] = 0;

            while (((temp != '\n') || check) && (!ifs.eof()))
            {
                check = false;
                ifs.get(temp);
                if (!space && (temp != ' ')) {
                    space = true;
                }
                LenStr[i]++;

            }
            if (!ifs.eof()) {
                check = true;
            }
            cout << LenStr[i] << ' ';
        }
        cout << endl;


        /*******************************
        *   ВХОДНОЙ КОНТРОЛЬ ДАННЫХ    *
        *******************************/





        if ((LenStr[0] < 2) && (LenStr[1] < 2)) {
            cout << "На первых двух строках в файле не обнаружены данные\n";
            incorrect = true;
        }
        else {
            if (LenStr[0] < 2) {
                cout << "Первая строка отсутствует.\n";
                incorrect = true;
            }
            if (LenStr[1] < 2) {
                cout << "Вторая строка отсутствует.\n";
                incorrect = true;
            }
        }

        if (!incorrect) {

            ifs.clear();
            ifs.seekg(0);

            str1 = new char[LenStr[0]];         //Задаем размеры массивов
            str2 = new char[LenStr[1]];

            ifs.getline(str1, LenStr[0]);       //Считываем строки в массивы
            ifs.getline(str2, LenStr[1]);

            str1[LenStr[0] - 1] = '\0';         //Не забываем терминальный ноль
            cout << str1 << endl;

            str2[LenStr[1] - 1] = '\0';         //И тут тоже
            cout << str2 << endl;

            //Смотрим, какая строка больше
            if (LenStr[0] > LenStr[1]) {
                word = new char[LenStr[0]];
            }
            else {
                word = new char[LenStr[1]];
            }

            //Задаем размер массива для слова в соответствии с наибольшим размером строк


    /*************************************************
    *             ПОИСК ОДИНАКОВЫХ СЛОВ              *
    *************************************************/
            int i = 0;                          //Счетчики элементов массивов
            int k = 0;

            while (ew2 < LenStr[1] - 2)
            {
                cout << "Flag main" << endl;
                k = 0;                          //Обнуляем счетчик


                while ((str2[i] == ' ') && (str2[i] != '\0'))  //Пропускаем все пробелы в начале строки
                {
                    i++;
                    cout << "Flag i" << endl;
                }

                bw2 = i;                                       //Раз не пробел и не конец - значит начало слова
                ew2 = i;                                       //Заодно и конец переместим сюда же
                while ((str2[i] != ' ') && (str2[i] != '\0'))  //Смотрим размер слова
                {
                    ew2++;
                    i++;
                    cout << "Flag ew2" << endl;
                }


                ew2--;                                          //Корректировочка

                while (k < (LenStr[0] - 1))      // Начинаем работу с другой строкой
                {
                    cout << "       k = " << k << endl;

                    cout << "Flag word 2" << endl;

                    while ((str1[k] == ' ') && (str1[k] != '\0')) //Снова ищем начало слова, нов в другой строке
                    {
                        k++;
                        cout << "Flag k" << endl;
                    }

                    bw1 = k;
                    ew1 = k;

                    while ((str1[k] != ' ') && (ew1 < LenStr[0])) //И его конец
                    {
                        ew1++;
                        k++;
                        cout << "Flag ew1" << endl;
                    }

                    ew1--;                               //И снова корректировочка


                    if ((ew1 - bw1) == (ew2 - bw2)) //Сравниваем длины слов
                    {
                        int LenWord = ew1 - bw1 + 1;
                        n = 0;
                        i = bw2;
                        k = bw1;

                        while ((str1[k] == str2[i]) && (n < LenWord)) //Раз длины равны, то сравниваем посимвольно
                        {
                            word[n] = str2[i];
                            n++; i++; k++;
                            cout << "flag n" << endl;
                        }
                        if (n < LenWord) //А вот тут незадача... Расхождение в словах! Обнуляем!
                        {
                            word[0] = '\0';
                        }
                        else //Если не так, то выводим наше слово.
                        {
                            word[n] = '\0';
                            cout << "word = " << word << endl;
                        }
                    }
                }              
            }
            if ((!((LenStr[0] - 1) % 4) && (LenStr[0] == LenStr[1]))) //Проверяем размеры массивов на кратность четырем
            {
                SumStr = new char[LenStr[0] + LenStr[1] - 1]; //Формируем массив, в котором будет сумма исходных.
                n = 0;                                       //Обнуляем счетчик
                n1 = 0;                                  //Кхм... Счетчики
                n2 = 0;
                int i = 0;
                while (i < (LenStr[0] + LenStr[1])) //Гуляем по циклам пока не встретимся с концом массива.
                {

                    for (int j = 0; j < 4; j++) //4 символа с первого массива
                    {

                        SumStr[n] = str1[n1];
                        i++;
                        n++;
                        n1++;
                    }

                    for (int j = 0; j < 4; j++)  // 4 символа со второго массива
                    {

                        SumStr[n] = str2[n2];
                        i++;
                        n++;
                        n2++;
                    }
                }
                SumStr[n] = '\0';      //Терминальный ноль в конце
                cout << SumStr << endl;
            }
            else    //Иначе - гулять!
            {
                cout << "Размеры массивов не удовлетворяют условию\n";
            }
        }
    }
    else {
        cout << "Файл не открыт" << endl;
    }
}