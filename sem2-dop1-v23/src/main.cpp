#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
struct plane //Структура, обеспечивающая хранение и использование данных 
{
	char time[100];
	char fightNumber[100];
	char bortNumber[100];
	char passengersNumber[100];
};



void Swap(plane* To, plane* From)
{
	plane* temp = To;
	*To = *From;
	*From = *temp;
}

bool CorrectFile(const char f_name[], int& size, short*& correctStr)//Проверка файла 
{
	bool symb = false;		//Найдено ли слово
	bool find = false;      //Было ли хотя бы 1 слово в строке

	char tempChar;			//Временная переменная

	int numWords = 0;		//Счетчик слов
	int numWordsInStr = 0;  //Количество слов в строке
	int numStr = 0;			//Количество строк
	//int wordPos = 0;		//Позиция в слове

	string word;			//Наше слово

	ifstream ifs(f_name);

	if (!ifs.is_open()) //Проверка открытия файла
	{
		cout << "Ошибка открытия файла. Проверьте наличие файла \"" << f_name << '\"' << endl;
		return false;
	}
	else {
		cout << "Файл " << f_name << " открыт." << endl;
	}

	ifs.get(tempChar);
	if (ifs.eof() && tempChar) //Проверка на то, есть ли что-нибудь в файле
	{
		cout << "Файл пуст " << endl;
		return false;
	}
	ifs >> word;
	if (ifs.eof()) {
		cout << "В файле недостаточно данных." << endl;
		return false;
	}
	ifs.clear();
	ifs.seekg(0);


	while (!ifs.eof()) //Считаем количество строк
	{
		ifs.get(tempChar);
		if (tempChar == '\n') {
			size++;
		}
	}

	ifs.clear();
	ifs.seekg(0);

	correctStr = new short[size];
	cout << "Исходные данные:" << endl;
	word = "";
	while (!ifs.eof()) //Проходим по всему файлу
	{
		ifs.get(tempChar);
		if ((tempChar != ' ') && (tempChar != '\n') && !symb)//Нашлось ли слово
		{
			find = true;
			symb = true;		//Помечаем, что слово найдено
			numWords++;				//Считаем количество слов
			numWordsInStr++;	//Считаем количество слов в данной строке
		}

		if (symb && tempChar != '\n')	//Если достигли конца строки после слова
		{
			word += tempChar;			//Запоминаем строку
		}

		if ((tempChar == ' ') || (tempChar == '\n')) //Если слово кончилось
		{
			symb = false;			   //Запоминаем, что слово кончилось.
		}

		if ((tempChar == '\n') || ifs.eof())				   //Если достигли конца строки, то выводим ее
		{
			if (find) {
				cout << numStr + 1 << ")\t  " << word << endl;
				word = ""; //После вывода зануляем строку
				if (numWordsInStr == 4) //Проверяем количество слов в строке и помечаем,
										//в каких строках нужное количество данных 
				{
					correctStr[numStr] = 1; //Если количество слов совпадает с ожидаемым
				}
				else
				{
					if (numWordsInStr < 4) {
						correctStr[numStr] = 2; // Если слов меньше чем нужно
					}
					if (numWordsInStr > 4) {
						correctStr[numStr] = 3; //Если слов больше чем нужно
					}

				}
				find = false;
			}
			else {
				correctStr[numStr] = 4;
			}
			numStr++;		//Считаем количество строк
			numWordsInStr = 0;      //Зануляем счетчик слов в строке
		}

	}
	cout << endl;

	ifs.clear();
	ifs.seekg(0);
	ifs.close();
	return true;					//Если все проверки пройдены то файл корректен
}
void Show(plane**& Ppl, int size, const char* message) //Вывод массива структур plane
{
	//ширина ячеек в таблице
	int numStep = 3; //Ширина ячейки номера
	int timeStep = 6; //Ширина ячейки времени
	int fightStep = 12; //Ширина ячейки номера рейса
	int bortStep = 15; //Ширина ячейки бортового номера
	int passengersStep = 18; //Ширина ячейки кол-ва пассажиров

	cout << '+' << setfill('-')
		<< setw(numStep + timeStep + fightStep + bortStep + passengersStep)
		<< '+' << endl; //Выводим верхнюю часть шапки

	cout << setfill(' ') << '|'
		<< setw(numStep + timeStep + fightStep + bortStep + passengersStep - 1)
		<< right << message << '|' << endl; //Вывод самой шапки и названия таблицы

	cout << '+' << setfill('-') << setw(numStep)
		<< '+' << setw(timeStep) << '+'
		<< setw(fightStep) << '+'
		<< setw(bortStep) << '+'
		<< setw(passengersStep) << '+' << endl; //Выводим линию с разметкой ячеек

	cout << '|' << setfill(' ')
		<< setw(numStep - 1) << right << " №" << '|'
		<< setw(timeStep - 1) << right << "Время" << '|'
		<< setw(fightStep - 1) << right << "Номер рейса" << '|'
		<< setw(bortStep - 1) << right << "Бортовой номер" << '|'
		<< setw(passengersStep - 1) << right << "Кол-во пассажиров" << '|' << endl; //Выводим  ячейки и их оглавление

	for (int i = 0; i < size; i++) {

		cout << '+' << setfill('-')
			<< setw(numStep)
			<< '+' << setw(timeStep)
			<< '+' << setw(fightStep)
			<< '+' << setw(bortStep)
			<< '+' << setw(passengersStep)
			<< '+' << endl;   //Выводим линию с разметкой ячеек

		cout << '|' << setfill(' ') << setw(numStep - 1)
			<< right << i + 1 << '|' << setw(timeStep - 1)
			<< right << Ppl[i]->time << '|' << setw(fightStep - 1)
			<< right << Ppl[i]->fightNumber << '|' << setw(bortStep - 1)
			<< right << Ppl[i]->bortNumber << '|' << setw(passengersStep - 1)
			<< right << Ppl[i]->passengersNumber << '|' << endl; //И сами ячейки с данными
	}
	cout << '+' << setfill('-') << setw(numStep)
		<< '+' << setw(timeStep) << '+'
		<< setw(fightStep) << '+'
		<< setw(bortStep) << '+'
		<< setw(passengersStep) << '+' << endl; //В конце закрываем таблицу
}

bool TimeCorrect(char* data) //Контроль времени
{

	int i = 0;				//Счетчик символов 
	while (data[i] != '\0') //Проходим по всему слову
	{
		if (((data[i] < '0') || (data[i] > '9')) && (i != 2))
		{
			return false;
		}		//И проверяем все символы кроме символа с номером 2 на то, цифра ли это
		i++;
	}
	if (i != 5) { return false; } //Проверяем количество символов
	if (data[2] != ':') { return false; } //И что бы второй символ был двоеточием

	int hours = ((data[0] - 48) * 10) + (data[1] - 48);      //Перевод символов в часы
	int minutes = ((data[3] - 48) * 10) + (data[4] - 48);	 //Перевод символов в минуты
	if ((hours > 23) || (minutes > 59)) //Проверка на корректность времени
	{
		return false;
	}

	return true;
}
bool BortNumber(char* num) //Контроль бортового номера
{
	if ((num[0] != 'B') || (num[1] != '-')) //Проверка первых 2-х символов
	{
		return false;
	}

	int i = 2;
	while (num[i] != '\0') //Проверяем оставшиеся символы
	{
		if (!((num[i] >= '0') && (num[i] <= '9'))) //Проверка на то, является ли символ числом.
		{
			return false;
		}
		i++;
	}
	if (i != 6) //Если длина не соответствует ожидаемой, то номер некорректен
	{
		return false;
	}

	return true;
}
void Input(const char* f_name, plane** pl, int& size, short* correctStr) //Ввод данных в массив структур plane
{
	char t = ' ';
	int j = 0; //Инкремент, отвечающий за заполнение массива с начала до конца без пропусков.
	plane* buff; //Буфферная структура, отвечающая за проверку данных и последующий перенос их в массив
	ifstream ifs(f_name);

	int error = 0;           //Счетчик строк с ошибками
	bool incorrect = false;	 //Нашли ли ошибки
	bool correctTime;	     //Корректно ли время
	bool correctBortNumber;  //Корректен ли бортовой номер

	for (int i = 0; i <= size; i++) //Проходим для каждой "строки"
	{
		if (correctStr[i] == 1) {
			buff = new plane;
			ifs >> buff->time;               //Считываем данные в буфер
			ifs >> buff->fightNumber;
			ifs >> buff->bortNumber;
			ifs >> buff->passengersNumber;

			correctTime = TimeCorrect(buff->time);				//Проверяем корректность времени
			correctBortNumber = BortNumber(buff->bortNumber);  //Проверяем корректность бортового номера

			if (correctTime && correctBortNumber) //Если данные корректны, то переносим в массив
			{
				pl[j] = new plane;		  //Выделяем память под новый элемент 
				Swap(pl[j], buff);		  //Меняем местами указатель на буферную переменную и ячейку массива					  
				j++;					  //Переходим к следующему элементу массива
			}
			else {
				if (!incorrect) //Если это первый заход то выводим уведомление о найденных ошибках
				{
					incorrect = true;
					cout << "Обнаруженны следующие ошибки:" << endl;
				}
				error++;    //Счетчик строк с ошибками (количество строк с ошибками)
				cout << error << ") В строке с номером "
					<< i + 1 << ": " << buff->time
					<< ' ' << buff->fightNumber
					<< ' ' << buff->bortNumber
					<< ' ' << buff->passengersNumber << endl;//Вывод самой строки и ее позиции

				if (!correctBortNumber) //Проверяем какие данные были не верны
				{
					cout << "Неправильно задан бортовой номер." << endl;
				}

				if (!correctTime)
				{
					cout << "Время задано неверно." << endl;
				}
				cout << endl;
			}
			delete buff; //Не забываем про очистку памяти
		}
		else //Если количество слов в строке некорректно, то выводим предупреждение об этом
		{

			if (!incorrect) //Если это первый заход то выводим уведомление о найденных ошибках
			{
				incorrect = true;
				cout << "Обнаруженные ошибки:" << endl;
			}
			error++;
			//Далее выводим ошибку по указанному коду.
			if (correctStr[i] == 3) {
				cout << error << ") В строке с номером " << i + 1 << " данных больше, чем необходимо." << endl;
				ifs.get(t);
			}
			if (correctStr[i] == 2) {
				cout << error << ") В строке с номером " << i + 1 << " данных меньше, чем необходимо." << endl;
				ifs.get(t);
			}
			if (correctStr[i] == 4) {
				cout << error << ") В строке с номером " << i + 1 << " нет данных." << endl;
			}

			ifs.get(t);
			while (t != '\n') {
				ifs.get(t);
			}
		}
	}
	size = j; //Запоминаем количество корректных строк, по совместительству это размер выделенной части массива (в элементах)
}

plane** TimeBubleSort(plane** pl, int size) //Пузырьковая сортировка по времени прибытия
{

	for (int j = 0; j < size - 1; j++) {
		for (int i = 0; i < size - 1; i++) {

			int hours1 = ((pl[i]->time[0] - 48) * 10) + (pl[i]->time[1] - 48);  //Считаем часы и минуты самолетов, которые сравниваем
			int minutes1 = ((pl[i]->time[3] - 48) * 10) + (pl[i]->time[4] - 48);
			int time1 = minutes1 + (60 * hours1);   // и заодно время с начала суток в минутах

			int hours2 = ((pl[i + 1]->time[0] - 48) * 10) + (pl[i + 1]->time[1] - 48);
			int minutes2 = ((pl[i + 1]->time[3] - 48) * 10) + (pl[i + 1]->time[4] - 48);
			int time2 = minutes2 + (60 * hours2);

			//cout << time1 << ' ' << time2 << endl;
			if (time1 < time2)				//Далее сравниваем эти времена
			{
				plane* buff = new plane;    //Используем указатель на буфферную структуру во избежание 

				Swap(buff, pl[i + 1]);		//Меняем местами наши соседние элементы массива
				Swap(pl[i + 1], pl[i]);
				Swap(pl[i], buff);
				delete buff;				//И не забываем подчищать за собой память
			}
		}
	}
	return pl; //Возвращаем отсортированный массив
}

int main()
{




	const char f_name[] = "correct_01.txt";		//Все данные корректны, пустых строк нет
	//const char f_name[] = "correct_02.txt";		//Все данные корректны, есть пустые строки
	//const char f_name[] = "correct_03.txt";		//Не все данные корректны, нет пустых строк
	//const char f_name[] = "correct_04.txt";		//Не все данные корректны, пустые строки есть



	//const char f_name[] = "incorrect.txt";	    //Этого файла нет
	//const char f_name[] = "incorrect_01.txt";	    //Пустой файл
	//const char f_name[] = "incorrect_02.txt";	    //В файле мусор в одну строку
	//const char f_name[] = "incorrect_03.txt";	    //Все данные некорректны, пустых строк нет
	//const char f_name[] = "incorrect_04.txt";	    //Все данные некорректны, пустые строки есть
	//const char f_name[] = "incorrect_05.txt";	    //В файле куча пустых строк




	int size = 0;                               //Наш размер массива.
	short* correctStr;

	setlocale(LC_ALL, "ru");

	//while(1)     //Для проверки утечек памяти
	if (CorrectFile(f_name, size, correctStr)) {

		plane** planes;		//Указатель на массив указателей на структуры 
		planes = new plane * [size];

		Input(f_name, planes, size, correctStr);
		cout << endl;
		//cout << endl << "Полученные корректные входные данные:" << endl;
		if (size != 0) {
			Show(planes, size, "Полученные корректные входные данные");
			cout << endl << endl;

			planes = TimeBubleSort(planes, size);	  //Сортировка пузырьком по дате
			Show(planes, size, "Отсортированный по времени опоздания список");

		}
		else {
			cout << endl << "Корректные данные отсутствуют." << endl << endl;;
		}
		for (int i = 0; i < size; i++) //Не забываем за собой очищать память
		{
			delete planes[i];
		}

		size = 0;
	}
	else {
		cout << "\nОбнаружены ошибки в файле. (см. выше)" << endl;
	}
	system("pause");
	return 0;
}