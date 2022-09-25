#include <iostream>
#include <fstream>
//#include <string>

using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");

	int LenString[2] = {0,0};
	

	int bw_0 = 0; //Начало слова из 1 строки
	int bw_1 = 0; //Начало слова из 2 строки
	int ew_0 = 0; //Конец слова из 1 строки
	int ew_1 = 0; //Конец слова из 2 строки
	int LenWord = 0; //Длина слова
	int pos_0 = 0;   //Позиция в 1 строке
	int pos_1 = 0;	 //Позиция во 2 строке
	int word_pos_0;	 //Позиция внутри слова в 1 строке
	int word_pos_1;  //Позиция внутри слова во 2 строке
	int word_n = 0;	 //Номер следующего элемента слова (куда записывать символ)
	int num_word = 0;   //Количество слов во 2 строке (Использовано для отладки)
	int NewStringPos = 0;  //Позиция в обьединенной строке

	char temp = ' '; //Временная переменная (Нужна для проверок)
	

	char* word;		 //указатель на массив со словом
	char* string_0;	 //указатель на массив с 1 строкой
	char* string_1;	 //указатель на массив со 2 строкой
	char* NewString; //указатель на массив с обьединенной строкой


	//Имя открываемого файла
	//const char file_name[] = "correct_01.txt"; //Равные длины строк, одинаковых слов нет
	const char file_name[] = "correct_02.txt"; //Разные длины строк, 3 одинаковых слова
	//const char file_name[] = "correct_03.txt"; //Равные длины строк, кратные 4 и строки одинаковы
	//const char file_name[] = "correct_04.txt";
	//const char file_name[] = "correct_05.txt";

	//const char file_name[] = "incorrect_00.txt"; //Не существует этого файла
	//const char file_name[] = "incorrect_01.txt";
	//const char file_name[] = "incorrect_02.txt";
	//const char file_name[] = "incorrect_03.txt";
	//const char file_name[] = "incorrect_04.txt";
	//const char file_name[] = "incorrect_05.txt";



	short i = 0;    //Просто переключатель для массива с размерами строк.

	//Ленивое создание файлов в проекте :)
	/*string i_s;
	string file_create;
	for (int i = 1; i < 6; i++) {
		file_create = "incorrect_0";
		i_s = to_string(i);
		file_create += i_s;
		file_create += ".txt";
		ofstream ofs(file_create);	
	}
	return 0;*/

	ifstream ifs(file_name);

	if (!ifs.is_open())  //Проверка открытия файла
	{
		cout << "Ошибка открытия файла\n";
		exit(1);
	}

	ifs >> temp;     
	if (temp == ' ')   // если в temp ничего не записоалось, то файл пуст
	{
		cout << "Файл пуст.\n";
		exit(3);
	}

	ifs.clear();
	ifs.seekg(0);

	while (!ifs.eof())  //Считаем количество символов в первых двух строках. 
	 {
		ifs.get(temp);		//Считываем данные
		LenString[i]++;		//Счетчик
		
		if ((temp == '\n') && (i == 1)) //Наткнулись на конец второй строки - завершаем подсчет
		{
			break;
		}
		if ((temp == '\n')&&(i == 0)) //Наткнулись на конец первой строки - начинаем считать длину второй.
		{			
			i = 1;			
		}
	}

	if ((LenString[0] < 2) && (LenString[1] < 2)) //Проверяем размеры строк
	{
		cout << "Обе строки пусты.\n";
		exit(2);
	}
	else {
		if ((LenString[0] < 2)) {
			cout << "Первая строка пуста.\n";
			exit(2);
		}
		if ((LenString[1] < 2)) {
			cout << "Вторая строка пуста.\n";
			exit(2);
		}
	}	

	ifs.clear();
	ifs.seekg(0);

	string_0 = new char[LenString[0]];    //Задаем размеры массивов, в которых будут храниться строки
	string_1 = new char[LenString[1]];

	

	ifs.getline(string_0, LenString[0]);                //Считываем строки
	ifs.getline(string_1, LenString[1]);
	cout << "Первая строка:\n" << string_0              //Вывод строк
		<< "\nВторая строка:\n" << string_1 << endl; 


	

	while (pos_0 < LenString[0] - 2)   //Начинаем поиск и сравнение слов
	{
		pos_1 = 0;					   //Обнуляем счетчики
		num_word = 0;

		//cout << "Поиск первого слова\n";

		while ((string_0[pos_0] == ' ') && (pos_0 < LenString[0] - 1)) //Пропуск пробелов
		{
			pos_0++;
			//cout << "Пропуск пробела в первой строке\n";
		}

		ew_0 = bw_0 = pos_0; //Первый символ, отличный от пробела - начало слова.

		while ((string_0[pos_0] != ' ') && (pos_0 < LenString[0] - 1)) // "Проход" по слову
		{
			pos_0++;
			//cout << "Считаем количество символов слова в первой строке\n";
		}
		ew_0 = pos_0 - 1;    //Раз наткнулись на пробел либо на конец строки, слово закончилось.
		

		//cout << "ew_0 = " << ew_0 << "\tbw_0 = " << bw_0<<endl;

		while (pos_1 < LenString[1] - 2) //Начинаем посик второго слова и сравнение
		{
			//cout << "Поиск второго слова\n";
			num_word++;

			while ((string_1[pos_1] == ' ') && (pos_1 < LenString[1] - 1)) //Снова пропуск пробелов
			{
				pos_1++;
				//cout << "Пропуск пробела во второй строке\n";
			}

			ew_1 = bw_1 = pos_1;

			while ((string_1[pos_1] != ' ') && (pos_1 < LenString[1] - 1)) //И нахождение конца слова
			{
				pos_1++;
				//cout << "Считаем количество символов слова во второй строке\n";
			}
			ew_1 = pos_1 - 1; //Снова корректировочка
			

			//cout << "ew_1 = " << ew_1 << "     bw_1 = " << bw_1 << endl;

			if ((ew_0 - bw_0) == (ew_1 - bw_1)) //Если длины найденных слов равны, то начинаем сравнение
			{
				word_n = 0;    //Обнуляем счетчик
				LenWord = ew_0 - bw_0 + 1; //И считаем размер слова

				//cout << "Сравнение слов\n" << endl;

				word = new char[LenWord + 1]; //Далее задаем размер массиву, в котором будет слово

				word_pos_0 = bw_0;            //Копируем данные в подпрограмму для того, что бы не вызывать сдвиг
				word_pos_1 = bw_1;
				cout <<"bw_0 = " << bw_0 << endl <<"ew_0 = " << ew_0 << endl;
				while (word_pos_0 <= ew_0) // И начинаем сравнение
				{
					
					//cout << "Сравнение символов двух строк\n";
					
					if (string_0[word_pos_0] == string_1[word_pos_1])//Срабатывает только когда символы равны
					{
						word[word_n] = string_0[word_pos_0];
						word_n++;						
					}
					word_pos_0++; word_pos_1++; //Наши счетчики позиций в строках
				}
				
				if (word_n == LenWord) //Если длина полученного слова совпала с ожидаемой - выводим.
									   //Ну а если нет, значит было расхождение в символах т.к. некоторые символы не записались в массив
				{
					word[word_n] = '\0';
					cout << "word = " << word << endl;
				}
			}			
		}
	}
	
	//cout << "Во второй строке слов: " << num_word << endl;      //Это для отладки

	if ((LenString[0] == LenString[1]) && !((LenString[0] - 1) % 4)) //Проверяем размеры строк на критерии задания
	{
		NewString = new char[(LenString[0] * 2) - 1]; // Задаем размер массива с результатом
		//cout << "Размер нового массива = " << sizeof(NewString)<<endl;
		pos_0 = 0; //Идем с начало строк.
		pos_1 = 0;

		while (NewStringPos < (LenString[0]*2)) //Идем пока не кончатся строки
		{

			for (int i = 0; i < 4; i++) //Вставляем по 4 символа за раз
			{
				NewString[NewStringPos] = string_0[pos_0];
				NewStringPos++; pos_0++;
			}
			for (int i = 0; i < 4; i++) {
				NewString[NewStringPos] = string_1[pos_1];
				NewStringPos++; pos_1++;
			}
		}
		NewString[NewStringPos - 1] = '\0'; //Терминальный ноль ставим
		cout <<"Новая строка:\n" << NewString << endl; //И выводим в консоль

	}
	else {
		cout << "Размеры массивов не соответствуют условию." << endl;
	}
}


