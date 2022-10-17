#include <iostream>
#include <iomanip>
#include <math.h>

int main()
{  
    /***********************************
    ------ИНИЦИАЛИЗЫЦИЯ ПЕРЕМЕННЫХ------
    ***********************************/
    using namespace std;
    float a;                                  //Начало отрезка
    float b;                                  //Конец отрезка
    float h = 0;                              //Шаг между точками
    float change;                             //Переменная для смены местами А и В
    float x;                                  //Полученное значение x
    float F_x, G_x;                           //Функции в точке x
    int n;                                    //Количество отрезков  
    setlocale(LC_ALL, "Russian");

    /*****************************************
    ----ПОДГОТОВКА ЭЛЕМЕНТОВ ПСЕВДОГРАФИКИ----
    *****************************************/
    const char VerticalLine = (char)186;      //"║" - Вертикальная линия
    const char HorizontalLine = (char)205;    //"═" - Горизонтальная линия
    const char TopLeftCorner = (char)201;     //"╔" - Левый верхний угол
    const char TopRightCorner = (char)187;    //"╗" - Правый верхний угол
    const char BottomLeftCorner = (char)200;  //"╚" - Левый нижний угол
    const char BottomRightCorner = (char)188; //"╝" - Правый нижний угол
    const char LeftJunction = (char)185;      //"╣" - вертикальная "труба влево"
    const char RightJunction = (char)204;     //"╠" - вертикальная "труба вправо"
    const char BottomJunction = (char)203;    //"╦" - Горизонтальная вниз "труба"
    const char TopJunction = (char)202;       //"╩" - Горизонтальная вниз "труба"
    const char CrossJunction = (char)206;     //"╬" - пересечение линий
    const char Space = (char)32;

    /*******************************
    -----ВВОД И ПРОВЕРКА ДАННЫХ-----
    *******************************/
    cout << "Введите A: ";
    cin >> a;
    cout << "Введите B: ";
    cin >> b;
    if (a > b) //Если A > B меняем значения переменных А и В местами.
    { 
      cout << "A>B => меняем их значения местами." << endl;
      change = a;
      a = b;
      b = change;             
    }//конец if
    if (a == b)  //Если а = b то
    {            
       n = 0;    //Отрезков нет
       cout << " A = B => N = 0" << endl;
    }
    else {
        cout << "Введите N: ";
        cin >> n;
        if (n <= 0)         //Проверка значения N
        {
            cout << "N д.б. > 0" << endl;
            exit(1);
        }//конец if
        h = (b - a) / n;    //Считаем шаг

        cout << "H = " << h << endl;
    }//конец if
    setlocale(LC_ALL, "C"); //Отключаем русский язык во избежание курьезов.

    /*******************************************
    ПЕЧАТЬ ВЕРХУШКИ ТАБЛИЦЫ И ОБОЗНАЧЕНИЙ ДАННЫХ
    *******************************************/

    //╔══╦══╦══╗
    cout << TopLeftCorner << setfill(HorizontalLine) << setw(20)
         << BottomJunction
        << setw(20) << BottomJunction
        << setw(20) << TopRightCorner << endl;

    //║ x ║ F(x) ║ G(x) ║
    cout << VerticalLine << setfill(Space)
        
        << setw(19) << right << "x" << VerticalLine
        << setw(19) << right << "F(x)" << VerticalLine
        << setw(19) << right << "G(x)" << VerticalLine << endl;
    
    
    /**********************
    ---ОСНОВНОЙ АЛГОРИТМ--- 
    **********************/
    for (int i = 0; i <= n ; i++ ) 
    {
        x = a + (i*h);                                 //Считаем xi значения функций в точке x.
        F_x = pow((x - 2), 3);                          
        G_x = pow((x + 1), 3) / (1 + pow((cos(x)), 2));  

        /**********************************
        -----ПЕЧАТЬ ТАБЛИЦЫ С ДАННЫМИ------
        **********************************/

        // ╠══╬══╬══╣                               
        cout << RightJunction << setfill(HorizontalLine)
            << setw(20) << CrossJunction << setw(20)
                        << CrossJunction << setw(20)
            << LeftJunction << endl;

        // ║ x ║ F_x ║ G_x ║
        cout << VerticalLine << setfill(Space) << setw(19)            
            << right << x << VerticalLine << setw(19)
            << right << F_x << VerticalLine << setw(19)
            << right << G_x << VerticalLine << endl;
    }//конец for
   
    // ╚══╩══╩══╝
    cout << BottomLeftCorner << setfill(HorizontalLine) << setw(20) 
        << TopJunction << setw(20) 
        << TopJunction << setw(20) 
        << BottomRightCorner << endl;
}