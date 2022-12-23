#include <iostream> // для ввода и вывода
#include <conio.h> // для _getche()
#include "Peripherie.h" // подключение 
#include "Suchen.h" // подключение одноимённого заголовочного файла

using namespace std; // подключение пространства имён std 

void SuchenDaten(lander*& land , int& Kapazitat) // поиск данных 
{
	char laufgang = 'd'; // для хода по меню 
	while (laufgang != '0')
	{
	Such:; // строка 279
		// рабочие переменные 
		char Zeitspanne[64]; // защитный буфер - защита от некорректного ввода 
		int leuchtturm = 0; // маячок для подчсчётав совпадений
		int metaint = 0; // переменная для числового выбора 

		// меню поиска для удаления 
		system("cls"); // очистка экрана
		cout << "По какому полю будет проходить поиск?\n\n"
			<< "1 - по индексу\n"
			<< "2 - по названию страны\n"
			<< "3 - по назманию столицы\n"
			<< "4 - по численности населения\n"
			<< "5 - по площади\n"
			<< "6 - по плотности населения\n"
			<< "7 - по валюте\n"
			<< "0 - выход в меню\n\n"
			<< "Пункт меню: ";
		laufgang = _getche(); // выбор пункта меню 

		// ход по меню 
		switch (laufgang)
		{

		case '1': // поиск по индексу 

		Such_Ind:; // строка 48
			metaint = 0; // обнуление для определения 
			system("cls"); // очистка консоли 
			cout << "Введите поисковую информацию по полю \"идекс поля\": ";
			cin >> Zeitspanne;
			for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы 
				if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
				{
					Prufung(); // оповещение о некорректном вводе 
					goto Such_Ind; // строка 39
				}
			for (int i = 0; i < strlen(Zeitspanne); i++) // определение переменной сравнения
				metaint += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));
			for (int i = 0; i < Kapazitat; i++) // посчёт совпадений
				if (metaint == land[i].index) // условие совпадений
					leuchtturm++; // увеличение совпадений 
			if (leuchtturm == 0) // если совпадений нет
				cout << "\nДаные не найдены!\n";
			else // если совпадения есть
			{
				cout << endl;
				Mutze(); // вывод элементов шапки
				for (int i = 0; i < Kapazitat; i++) // вывод эдементов массива
					if (metaint == land[i].index) // условия вывода
						Schreiben(land, i); // вывод i-той записи
			}
			cout << endl;
			Wartung(); // задержка
			break;

		case '2': // поиск по названию страны

		Such_Name:; // строка 78, 86
			system("cls"); // очистка консоли
			cout << "Введите поисковую информацию по полю \"название страны\": ";
			cin >> Zeitspanne;
			if (strlen(Zeitspanne) > 25) // проверка на длину 
			{
				Prufung(); // оповещение о некорректном вводе 
				goto Such_Name; // строка 71
			}
			for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы 
				if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
					if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
						if ((Zeitspanne[i] != 95) && (Zeitspanne[i] != 45))
						{
							Prufung(); // оповещение о некорректном вводе 
							goto Such_Name; // строка 71
						}
			KorrigierenDaten(Zeitspanne, 1); // коррекция введённых данных
			for (int i = 0; i < Kapazitat; i++) // посчёт совпадений
				if (strcmp(Zeitspanne, land[i].Name) == 0) // условие совпадений
					leuchtturm++; // увеличение совпадений
			if (leuchtturm == 0) // если совпадений нет
				cout << "\nДаные не найдены!\n";
			else // если совпадения есть
			{
				cout << endl;
				Mutze(); // вывод элементов шапки
				for (int i = 0; i < Kapazitat; i++) // вывод эдементов массива
					if (strcmp(Zeitspanne, land[i].Name) == 0) // условия вывода
						Schreiben(land, i); // вывод i-той записи
			}
			cout << endl;
			Wartung(); // задержка
			break;

		case '3': // поиск по названию столицы 

		Such_HauptStadt:; // строка 115, 123
			system("cls"); // очистка консоли
			cout << "Введите поисковую информацию по полю \"название столицы\": ";
			cin >> Zeitspanne;
			if (strlen(Zeitspanne) > 25) // проверка на длину 
			{
				Prufung(); // оповещение о некорректном вводе 
				goto Such_HauptStadt; // строка 108
			}
			for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы 
				if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
					if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
						if ((Zeitspanne[i] != 95) && (Zeitspanne[i] != 45))
						{
							Prufung(); // оповещение о некорректном вводе 
							goto Such_HauptStadt; // стркоа 108
						}
			KorrigierenDaten(Zeitspanne, 1); // коррекция введённых данных
			for (int i = 0; i < Kapazitat; i++) // посчёт совпадений
				if (strcmp(Zeitspanne, land[i].HauptStadt) == 0) // условие совпадений
					leuchtturm++; // увеличение совпадений
			if (leuchtturm == 0) // если совпадений нет
				cout << "\nДаные не найдены!\n";
			else // если совпадения есть
			{
				cout << endl;
				Mutze(); // вывод элементов шапки
				for (int i = 0; i < Kapazitat; i++) // вывод эдементов массива
					if (strcmp(Zeitspanne, land[i].HauptStadt) == 0) // условия вывода
						Schreiben(land, i); // вывод i-той записи
			}
			cout << endl;
			Wartung(); // задержка
			break;

		case '4': // поиск по численности населения 

		Such_Nas:; // строка 154
			metaint = 0; // обнуление для определения 
			system("cls"); // очистка консоли
			cout << "Введите поисковую информацию по полю \"идекс поля\": ";
			cin >> Zeitspanne;
			for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы 
				if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
				{
					Prufung(); // оповещение о некорректном вводе 
					goto Such_Nas; // строка 145
				}
			for (int i = 0; i < strlen(Zeitspanne); i++) // определение переменной сравнения
				metaint += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));
			for (int i = 0; i < Kapazitat; i++) // посчёт совпадений
				if (metaint == land[i].Nas) // условие совпадений
					leuchtturm++; // увеличение совпадений
			if (leuchtturm == 0) // если совпадений нет
				cout << "\nДаные не найдены!\n";
			else // если совпадения есть
			{ 
				cout << endl;
				Mutze(); // вывод элементов шапки
				for (int i = 0; i < Kapazitat; i++) // вывод эдементов массива
					if (metaint == land[i].Nas) // условия вывода
						Schreiben(land, i); // вывод i-той записи
			}
			cout << endl;
			Wartung(); // задержка
			break;

		case '5': // поиск по площади 

		Such_Terr:; // строка 186
			metaint = 0; // обнуление для определения 
			system("cls"); // очистка консоли
			cout << "Введите поисковую информацию по полю \"идекс поля\": ";
			cin >> Zeitspanne;
			for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы 
				if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
				{
					Prufung(); // оповещение о некорректном вводе 
					goto Such_Terr; // строка 177
				}
			for (int i = 0; i < strlen(Zeitspanne); i++) // определение переменной сравнения
				metaint += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));
			for (int i = 0; i < Kapazitat; i++) // посчёт совпадений
				if (metaint == land[i].Terr) // условие совпадений
					leuchtturm++; // увеличение совпадений
			if (leuchtturm == 0) // если совпадений нет
				cout << "\nДаные не найдены!\n";
			else // если совпадения есть
			{
				cout << endl;
				Mutze(); // вывод элементов шапки
				for (int i = 0; i < Kapazitat; i++) // вывод эдементов массива
					if (metaint == land[i].Terr) // условия вывода
						Schreiben(land, i); // вывод i-той записи
			}
			cout << endl;
			Wartung(); // задержка
			break;

		case '6': // поиск по плотности населения 

		Such_Nas_pro_Terr:; // строка 218
			metaint = 0; // обнуление для определения 
			system("cls"); // очистка консоли
			cout << "Введите поисковую информацию по полю \"идекс поля\": ";
			cin >> Zeitspanne;
			for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы 
				if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
				{
					Prufung(); // оповещение о некорректном вводе 
					goto Such_Nas_pro_Terr; // строка 208
				}
			for (int i = 0; i < strlen(Zeitspanne); i++) // определение переменной сравнения
				metaint += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));
			for (int i = 0; i < Kapazitat; i++) // посчёт совпадений
				if (metaint == land[i].Nas_pro_Terr) // условие совпадений
					leuchtturm++; // увеличение совпадений
			if (leuchtturm == 0) // если совпадений нет
				cout << "\nДаные не найдены!\n";
			else // если совпадения есть
			{
				cout << endl;
				Mutze(); // вывод элементов шапки
				for (int i = 0; i < Kapazitat; i++) // вывод эдементов массива
					if (metaint == land[i].Nas_pro_Terr) // условия вывода
						Schreiben(land, i); // вывод i-той записи
			}
			cout << endl;
			Wartung(); // задержка
			break;

		case '7': // поиск по коду валюты 

		Such_VAL:; // строка 248, 255
			system("cls"); // очистка консоли
			cout << "Введите поисковую информацию по полю \"код валюты\": ";
			cin >> Zeitspanne;
			if (strlen(Zeitspanne) != 3) // проверка на длину 
			{
				Prufung(); // оповещение о некорректном вводе 
				goto Such_VAL; // строка 241
			}
			for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы 
				if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
					if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
					{
						Prufung(); // оповещение о некорректном вводе 
						goto Such_VAL; // строка 241
					}
			KorrigierenDaten(Zeitspanne, 2); // коррекция введённых данных
			for (int i = 0; i < Kapazitat; i++) // посчёт совпадений
				if (strcmp(Zeitspanne, land[i].VAL) == 0) // условие совпадений
					leuchtturm++; // увеличение совпадений
			if (leuchtturm == 0) // если совпадений нет
				cout << "\nДаные не найдены!\n";
			else // если совпадения есть
			{
				cout << endl;
				Mutze(); // вывод элементов шапки
				for (int i = 0; i < Kapazitat; i++) // вывод эдементов массива
					if (strcmp(Zeitspanne, land[i].VAL) == 0) // условия вывода
						Schreiben(land, i); // вывод i-той записи
			}
			cout << endl;
			Wartung(); // задержка
			break;

		case '0': break; // для выхода

		default: // проверка ввода 
			Prufung(); // оповещение о некорректном вводе
			goto Such; // строка 13
		}
	}
}

int SuchenFurSubstragierung(lander*& land, int& Kapazitat) // поиск для удаления 
{
Such_Fur_Sub_Hauptablauf:; // стркоа 852
	// рабочие переменные 
	char laufgang; // ход по меню
	char Zeitspanne[64]; // защитный буфер - защита от некорректного ввода 
	char TeilDel[64]; // защитный буфер - защита для рабочего индекса
	char Antwort; // переменная ответа
	int leuchtturm = 0; // маячок для постчёта совпадений 
	int metaint = 0; // для сравнения
	int metaindex = 0; // для взврата индекса удаления 

	// меню поиска для удаления 
	system("cls"); // очистка экрана 
	cout << "По какому полю будет проходить поиск для удаления?\n\n"
		<< "1 - по названию страны\n"
		<< "2 - по назманию столицы\n"
		<< "3 - по численности населения\n"
		<< "4 - по площади\n"
		<< "5 - по плотности населения\n"
		<< "6 - по коду валюты\n"
		<< "0 - выход из поиска\n\n"
		<< "Пункт меню: ";
	laufgang = _getche(); // ввод пункта меню

	if (laufgang == 0) return 0; // выход и возврат ноль-индекса

	// ход по меню
	switch (laufgang)
	{
	case '1': // поиск по названию страны

	Such_Fur_Sub_Anfang_Name:; // строки 323, 321
		system("cls"); // очистка консоли
		cout << "Введите поисковую информацию по полю \"название страны\": ";
		cin >> Zeitspanne;
		if (strlen(Zeitspanne) > 25) // проверка на длину 
		{
			Prufung(); // оповещение о некорректном вводе 
			goto Such_Fur_Sub_Anfang_Name; // строка 316
		}
		for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы 
			if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
				if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
					if ((Zeitspanne[i] != 95) && (Zeitspanne[i] != 45))
					{
						Prufung(); // оповещение о некорректном вводе 
						goto Such_Fur_Sub_Anfang_Name; // строка 316
					}
		KorrigierenDaten(Zeitspanne, 1); // коррекция введённых данных

		// работа с мачком совпадений 
		for (int i = 0; i < Kapazitat; i++)
			if (strcmp(Zeitspanne, land[i].Name) == 0) // сравнение с действительными данными 
				leuchtturm++; // увеличение маячка совпадений 
		if (leuchtturm == 0) // если совпадений нет 
		{
			cout << "\nДаные не найдены!\n\n"; // оповещение о ненайденных данных
			Wartung(); // задержка
			return 0; // вовзрат ноль-индекса
		}
		else if (leuchtturm == 1) // если совпадение одно 
		{
			cout << endl;
		Such_Fur_Sub_EinLT_Name:; // строка 362
			Mutze(); // вывод элементов шапки
			for (int i = 0; i < Kapazitat; i++)
				if (strcmp(Zeitspanne, land[i].Name) == 0) // нахождение строки сопадения 
				{
					Schreiben(land, i); // вывод cтроки совпадения
					metaindex = land[i].index; // запоминание индекса
				}
			cout << "\nУдалить эту запись? (y или n): "; //запрос на удаление записи
			Antwort = _getche(); // ответ 
			if ((Antwort != 'y') && (Antwort != 'n')) // проверка ввода
			{
				Prufung(); // оповещение о некорректном вводе 
				system("cls"); // очистка консоли
				goto Such_Fur_Sub_EinLT_Name; // строка 348
			}
			else if (Antwort == 'y') // если ответ положительный 
				return metaindex; // возвращаем рабочий индекс
			else if (Antwort == 'n') // если ответ отрицательный 
				return 0; // возвращаем ноль-индекс
		}
		else if (leuchtturm > 1) // если совпадений несколько 
		{
			cout << endl;
		Such_Fur_Sub_VielLT_Name:;  // строки 384, 397
			Mutze(); // вывод шапки 
			for (int i = 0; i < Kapazitat; i++) // вывод элементов массива 
				if (strcmp(Zeitspanne, land[i].Name) == 0)
					Schreiben(land, i); // вывод cтроки совпадения
			cout << "\nВведите индекс записи, которую необходимо удалить (0 - никакую): "; // запрос на удаление
			cin >> TeilDel;
			for (int i = 0; i < strlen(TeilDel); i++) // проверка на символы 
				if ((TeilDel[i] < 48) || (TeilDel[i] > 57))
				{
					Prufung(); // оповещение о некорректном вводе 
					system("cls"); // очистка консоли
					goto Such_Fur_Sub_VielLT_Name; // строка 372
				}
			if ((strlen(TeilDel) == 1) && (TeilDel[0] == 48)) return 0; // выход в меню удаления 
			for (int i = 0; i < strlen(TeilDel); i++) // определение рабочего сивола  
				metaindex += ((TeilDel[i] - 48) * pow(10, (strlen(TeilDel) - 1 - i)));
			leuchtturm = 0; // обнуление маячка совпадений 
			for (int i = 0; i < Kapazitat; i++) // подсчёт совпадений 
				if (strcmp(Zeitspanne, land[i].Name) == 0)
					leuchtturm++; // увеличение маячка совпадений
			if (leuchtturm == 0) // если совпадений нет 
			{
				Prufung(); // оповещение о некорректном вводе 
				system("cls"); // очистка консоли
				goto Such_Fur_Sub_VielLT_Name; // строка 372
			}
			else // если совпадения есть  
				for (int i = 0; i < Kapazitat; i++)
					if (metaindex == land[i].index)
						return metaindex; // возврат рабочего индекса 
		}

	case '2': // поиск по названию столицы

	Such_Fur_Sub_Anfang_Hauptstadt:; // строки 414, 422
		system("cls"); // очистка консоли
		cout << "Введите поисковую информацию по полю \"название столицы\": ";
		cin >> Zeitspanne;
		if (strlen(Zeitspanne) > 25) // проверка на длину 
		{
			Prufung(); // оповещение о некорректном вводе 
			goto Such_Fur_Sub_Anfang_Hauptstadt; // стрка 407
		}
		for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы 
			if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
				if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
					if ((Zeitspanne[i] != 95) && (Zeitspanne[i] != 45))
					{
						Prufung(); // оповещение о некорректном вводе 
						goto Such_Fur_Sub_Anfang_Hauptstadt; // стрка 407
					}
		KorrigierenDaten(Zeitspanne, 1); // коррекция введённых данных

		// работа с мачком совпадений 
		for (int i = 0; i < Kapazitat; i++)
			if (strcmp(Zeitspanne, land[i].HauptStadt) == 0) // сравнение с действительными данными 
				leuchtturm++; // увеличение маячка совпадений 
		if (leuchtturm == 0) // если совпадений нет 
		{
			cout << "\nДаные не найдены!\n\n"; // оповещение о ненайденных данных
			Wartung(); // задержка
			return 0; // вовзрат ноль-индекса
		}
		else if (leuchtturm == 1) // если совпадение одно 
		{
			cout << endl;
		Such_Fur_Sub_EinLT_Hauptstadt:; // строка 453
			Mutze(); // вывод элементов шапки
			for (int i = 0; i < Kapazitat; i++)
				if (strcmp(Zeitspanne, land[i].HauptStadt) == 0) // нахождение строки сопадения 
				{
					Schreiben(land, i); // вывод cтроки совпадения
					metaindex = land[i].index; // запоминание индекса
				}
			cout << "\nУдалить эту запись? (y или n): "; //запрос на удаление записи
			Antwort = _getche(); // ответ 
			if ((Antwort != 'y') && (Antwort != 'n')) // проверка ввода
			{
				Prufung(); // оповещение о некорректном вводе 
				system("cls"); // очистка консоли
				goto Such_Fur_Sub_EinLT_Hauptstadt; // строка 439
			}
			else if (Antwort == 'y') // если ответ положительный 
				return metaindex; // возвращаем рабочий индекс
			else if (Antwort == 'n') // если ответ отрицательный 
				return 0; // возвращаем ноль-индекс
		}
		else if (leuchtturm > 1) // если совпадений несколько 
		{
			cout << endl;
		Such_Fur_Sub_VielLT_Hauptstadt:; // строки 475, 488
			Mutze(); // вывод шапки 
			for (int i = 0; i < Kapazitat; i++) // вывод элементов массива 
				if (strcmp(Zeitspanne, land[i].HauptStadt) == 0)
					Schreiben(land, i); // вывод cтроки совпадения
			cout << "\nВведите индекс записи, которую необходимо удалить (0 - никакую): "; // запрос на удаление
			cin >> TeilDel;
			for (int i = 0; i < strlen(TeilDel); i++) // проверка на символы 
				if ((TeilDel[i] < 48) || (TeilDel[i] > 57))
				{
					Prufung(); // оповещение о некорректном вводе
					system("cls"); // очистка консоли
					goto Such_Fur_Sub_VielLT_Hauptstadt; // строка 463
				}
			if ((strlen(TeilDel) == 1) && (TeilDel[0] == 48)) return 0; // выход в меню удаления 
			for (int i = 0; i < strlen(TeilDel); i++) // определение рабочего сивола  
				metaindex += ((TeilDel[i] - 48) * pow(10, (strlen(TeilDel) - 1 - i)));
			leuchtturm = 0; // обнуление маячка совпадений 
			for (int i = 0; i < Kapazitat; i++) // подсчёт совпадений 
				if (strcmp(Zeitspanne, land[i].HauptStadt) == 0)
					leuchtturm++;
			if (leuchtturm == 0) // если совпадений нет 
			{
				Prufung(); // оповещение о некорректном вводе 
				system("cls"); // очистка консоли
				goto Such_Fur_Sub_VielLT_Hauptstadt; // строка 463
			}
			else
				for (int i = 0; i < Kapazitat; i++)
					if (metaindex == land[i].index)
						return metaindex; // возврат рабочего индекса 
		}

	case '3': // посик по численности населения

	Such_Fur_Sub_Anfang_Nas:; // строка 511
		system("cls"); // очистка консоли 
		cout << "Введите поисковую информацию по полю \"численность населения\": ";
		cin >> Zeitspanne; 
		if (strlen(Zeitspanne) > 10) // проверка на длину 
		{
			Prufung(); // оповещение о некорректном вводе 
			goto Such_Fur_Sub_Anfang_Nas;
		}
		for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы
			if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
			{
				Prufung(); // оповещение о некорректном вводе 
				goto Such_Fur_Sub_Anfang_Nas; // строка 496
			}
		for (int i = 0; i < strlen(Zeitspanne); i++) // определение ключевого числа сравнения
			metaint += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));
		for (int i = 0; i < Kapazitat; i++)
			if (metaint == land[i].Nas) // условие увеличения числа совпадений 
				leuchtturm++;  // увеличение маячка совпадений 
		if (leuchtturm == 0) // если совпадений нет 
		{
			cout << "\nДаные не найдены!\n\n"; // опвещение, что данные не найдены 
			Wartung(); // задержка
			return 0; // возврат ноль-индекса 
		}
		else if (leuchtturm == 1) // если одно совпадение 
		{
			cout << endl;
		Such_Fur_Sub_EinLT_Nas:; // строка 541
			Mutze(); // вывод элементов шапки 
			for (int i = 0; i < Kapazitat; i++) 
				if (metaint == land[i].Nas) // условие поиска 
				{
					Schreiben(land, i); // вывод cтроки совпадения
					metaindex = land[i].index; // получение рабочего индекса 
				}
			cout << "\nУдалить эту запись? (y или n): "; // запрос на уделание
			Antwort = _getche(); // ответ 
			if ((Antwort != 'y') && (Antwort != 'n')) // проверка ввода 
			{
				Prufung(); // оповещение о некорректном вводе
				system("cls"); // очистка консоли
				goto Such_Fur_Sub_EinLT_Nas; // строка 527
			}
			else if (Antwort == 'y') // если ответ положительный 
				return metaindex; // возвращаем рабочий индекс
			else if (Antwort == 'n') // если ответ отрицательный 
				return 0; // возвращаем ноль-индекс
		}
		else if (leuchtturm > 1) // если совпадений несколько 
		{
			cout << endl;
		Such_Fur_Sub_VielLT_Nas:; // строки 563, 576
			Mutze(); // вывод шапки 
			for (int i = 0; i < Kapazitat; i++) // вывод элементов массива 
				if (metaint == land[i].Nas) // условие вывода 
					Schreiben(land, i); // вывод cтроки совпадения
			cout << "\nВведите индекс записи, которую необходимо удалить (0 - никакую): "; // запрос на удаление
			cin >> TeilDel; 
			for (int i = 0; i < strlen(TeilDel); i++) // проверка на символы 
				if ((TeilDel[i] < 48) || (TeilDel[i] > 57))
				{
					Prufung(); // оповещение о некорректном вводе 
					system("cls"); // очистка консоли
					goto Such_Fur_Sub_VielLT_Nas; // строка 551
				}
			if ((strlen(TeilDel) == 1) && (TeilDel[0] == 48)) return 0; // выход в меню удаления 
			for (int i = 0; i < strlen(TeilDel); i++) // определение рабочего сивола  
				metaindex += ((TeilDel[i] - 48) * pow(10, (strlen(TeilDel) - 1 - i)));
			leuchtturm = 0; // обнуление маячка совпадений 
			for (int i = 0; i < Kapazitat; i++) // подсчёт совпадений 
				if (metaint == land[i].Nas) // условие увеличения числа совпадений 
					leuchtturm++;
			if (leuchtturm == 0) // если совпадений нет 
			{
				Prufung(); // оповещение о некорректном вводе 
				system("cls"); // очистка консоли
				goto Such_Fur_Sub_VielLT_Nas; // строка 551
			}
			else
				for (int i = 0; i < Kapazitat; i++)
					if (metaindex == land[i].index)
						return metaindex; // возврат рабочего индекса 
		}

	case '4': // поиск по площади 

	Such_Fur_Sub_Anfang_Terr:; // строки 593
		system("cls"); // очистка консоли 
		cout << "Введите поисковую информацию по полю \"площадь\": ";
		cin >> Zeitspanne;
		if (strlen(Zeitspanne) > 9) // проверка на длину 
		{
			Prufung(); // оповещение о некорректном вводе 
			goto Such_Fur_Sub_Anfang_Terr; // строка 586
		}
		for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы
			if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
			{
				Prufung(); // оповещение о некорректном вводе 
				goto Such_Fur_Sub_Anfang_Terr; // строка 586
			}
		for (int i = 0; i < strlen(Zeitspanne); i++) // определение ключеговго числа сравнения 
			metaint += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));
		for (int i = 0; i < Kapazitat; i++)
			if (metaint == land[i].Terr) // условие увеличения числа совпадений 
				leuchtturm++;  // увеличение маячка совпадений 
		if (leuchtturm == 0) // если совпадений нет 
		{
			cout << "\nДаные не найдены!\n\n"; // опвещение, что данные не найдены 
			Wartung(); // задержка
			return 0; // возврат ноль-индекса 
		}
		else if (leuchtturm == 1) // если одно совпадение 
		{
			cout << endl;
		Such_Fur_Sub_EinLT_Terr:; // строка 629
			Mutze(); // вывод шапки 
			for (int i = 0; i < Kapazitat; i++)
				if (metaint == land[i].Terr) // условие поиска 
				{
					Schreiben(land, i); // вывод cтроки совпадения
					metaindex = land[i].index; // получение рабочего индекса 
				}
			cout << "\nУдалить эту запись? (y или n): "; // запрос на уделание
			Antwort = _getche(); // ответ 
			if ((Antwort != 'y') && (Antwort != 'n')) // проверка ввода 
			{
				Prufung(); // оповещение о некорректном вводе
				system("cls"); // очистка консоли
				goto Such_Fur_Sub_EinLT_Terr; // строка 615
			}
			else if (Antwort == 'y') // если ответ положительный 
				return metaindex; // возвращаем рабочий индекс
			else if (Antwort == 'n') // если ответ отрицательный 
				return 0; // возвращаем ноль-индекс
		}
		else if (leuchtturm > 1) // если совпадений несколько 
		{
			cout << endl;
		Such_Fur_Sub_VielLT_Terr:; // строки 651, 664
			Mutze(); // вывод шапки  
			for (int i = 0; i < Kapazitat; i++) // вывод элементов массива 
				if (metaint == land[i].Terr) // условие вывода 
					Schreiben(land, i); // вывод cтроки совпадения
			cout << "\nВведите индекс записи, которую необходимо удалить (0 - никакую): "; // запрос на удаление
			cin >> TeilDel;
			for (int i = 0; i < strlen(TeilDel); i++) // проверка на символы 
				if ((TeilDel[i] < 48) || (TeilDel[i] > 57))
				{
					Prufung(); // оповещение о некорректном вводе 
					system("cls"); // очистка консоли
					goto Such_Fur_Sub_VielLT_Terr; // строка 664
				}
			if ((strlen(TeilDel) == 1) && (TeilDel[0] == 48)) return 0; // выход в меню удаления 
			for (int i = 0; i < strlen(TeilDel); i++) // определение рабочего сивола  
				metaindex += ((TeilDel[i] - 48) * pow(10, (strlen(TeilDel) - 1 - i)));
			leuchtturm = 0; // обнуление маячка совпадений 
			for (int i = 0; i < Kapazitat; i++) // подсчёт совпадений 
				if (metaint == land[i].Terr) // условие увеличения числа совпадений 
					leuchtturm++;
			if (leuchtturm == 0) // если совпадений нет 
			{
				Prufung(); // оповещение о некорректном вводе 
				system("cls"); // очистка консоли
				goto Such_Fur_Sub_VielLT_Terr; // строка 664
			}
			else
				for (int i = 0; i < Kapazitat; i++)
					if (metaindex == land[i].index)
						return metaindex; // возврат рабочего индекса 
		}

	case '5':

	Such_Fur_Sub_Anfang_Nas_pro_Terr:; // строки 681, 687
		system("cls"); // очистка консоли 
		cout << "Введите поисковую информацию по полю \"плотность населения\": ";
		cin >> Zeitspanne; 
		if (strlen(Zeitspanne) > 8) // проверка на длину 
		{
			Prufung(); // оповещение о некорректном вводе 
			goto Such_Fur_Sub_Anfang_Nas_pro_Terr; // строка 674
		}
		for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы
			if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
			{
				Prufung(); // оповещение о некорректном вводе 
				goto Such_Fur_Sub_Anfang_Nas_pro_Terr; // строка 674
			}
		for (int i = 0; i < strlen(Zeitspanne); i++) // определение ключевого числа сравнения
			metaint += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));
		for (int i = 0; i < Kapazitat; i++)
			if (metaint == land[i].Nas_pro_Terr) // условие увеличения числа совпадений 
				leuchtturm++;  // увеличение маячка совпадений 
		if (leuchtturm == 0) // если совпадений нет 
		{
			cout << "\nДаные не найдены!\n\n"; // опвещение, что данные не найдены 
			Wartung(); // задержка
			return 0; // возврат ноль-индекса 
		}
		else if (leuchtturm == 1) // если одно совпадение 
		{
			cout << endl;
		Such_Fur_Sub_EinLT_Nas_pro_Terr:; // строка 717
			Mutze(); // вывод элементов шапки 
			for (int i = 0; i < Kapazitat; i++)
				if (metaint == land[i].Nas_pro_Terr) // условие поиска 
				{
					Schreiben(land, i); // вывод cтроки совпадения
					metaindex = land[i].index; // получение рабочего индекса 
				}
			cout << "\nУдалить эту запись? (y или n): "; // запрос на уделание
			Antwort = _getche(); // ответ 
			if ((Antwort != 'y') && (Antwort != 'n')) // проверка ввода 
			{
				Prufung(); // оповещение о некорректном вводе 
				system("cls"); // очистка консоли
				goto Such_Fur_Sub_EinLT_Nas_pro_Terr; // строка 703
			}
			else if (Antwort == 'y') // если ответ положительный 
				return metaindex; // возвращаем рабочий индекс
			else if (Antwort == 'n') // если ответ отрицательный 
				return 0; // возвращаем ноль-индекс
		}
		else if (leuchtturm > 1) // если совпадений несколько 
		{
			cout << endl;
		Such_Fur_Sub_VielLT_Nas_pro_Terr:; // строки 739, 752
			Mutze(); // вывод шапки 
			for (int i = 0; i < Kapazitat; i++) // вывод элементов массива 
				if (metaint == land[i].Nas_pro_Terr) // условие вывода 
					Schreiben(land, i); // вывод cтроки совпадения
			cout << "\nВведите индекс записи, которую необходимо удалить (0 - никакую): "; // запрос на удаление
			cin >> TeilDel;
			for (int i = 0; i < strlen(TeilDel); i++) // проверка на символы 
				if ((TeilDel[i] < 48) || (TeilDel[i] > 57))
				{
					Prufung(); // оповещение о некорректном вводе 
					system("cls"); // очистка консоли
					goto Such_Fur_Sub_VielLT_Nas_pro_Terr; // строка 727
				}
			if ((strlen(TeilDel) == 1) && (TeilDel[0] == 48)) return 0; // выход в меню удаления 
			for (int i = 0; i < strlen(TeilDel); i++) // определение рабочего сивола  
				metaindex += ((TeilDel[i] - 48) * pow(10, (strlen(TeilDel) - 1 - i)));
			leuchtturm = 0; // обнуление маячка совпадений 
			for (int i = 0; i < Kapazitat; i++) // подсчёт совпадений 
				if (metaint == land[i].Nas_pro_Terr) // условие увеличения числа совпадений 
					leuchtturm++; // увеличение маячка совпадений 
			if (leuchtturm == 0) // если совпадений нет 
			{
				Prufung(); // оповещение о некорректном вводе 
				system("cls"); // очистка консоли
				goto Such_Fur_Sub_VielLT_Nas_pro_Terr; // строка 727
			}
			else
				for (int i = 0; i < Kapazitat; i++)
					if (metaindex == land[i].index)
						return metaindex; // возврат рабочего индекса 
		}

	case '6': // поиск по коду валюты 

	Such_Fur_Sub_Anfang_VAL:; // строки 769, 776
		system("cls"); // очистка консоли
		cout << "Введите поисковую информацию по полю \"коду валюты\": ";
		cin >> Zeitspanne;
		if (strlen(Zeitspanne) != 3) // проверка на длину 
		{
			Prufung(); // оповещение о некорректном вводе 
			goto Such_Fur_Sub_Anfang_VAL; // строка 762
		}
		for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы 
			if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
				if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
				{
					Prufung(); // оповещение о некорректном вводе 
					goto Such_Fur_Sub_Anfang_VAL; // строка 762
				}
		KorrigierenDaten(Zeitspanne, 2); // коррекция введённых данных

		// работа с мачком совпадений 
		for (int i = 0; i < Kapazitat; i++)
			if (strcmp(Zeitspanne, land[i].VAL) == 0) // сравнение с действительными данными 
				leuchtturm++; // увеличение маячка совпадений 
		if (leuchtturm == 0) // если совпадений нет 
		{
			cout << "\nДаные не найдены!\n\n"; // оповещение о ненайденных данных
			Wartung(); // задержка
			return 0; // вовзрат ноль-индекса
		}
		else if (leuchtturm == 1) // если совпадение одно 
		{
			cout << endl;
		Such_Fur_Sub_EinLT_VAL:; // строка 807
			Mutze(); // вывод элементов шапки
			for (int i = 0; i < Kapazitat; i++)
				if (strcmp(Zeitspanne, land[i].HauptStadt) == 0) // нахождение строки сопадения 
				{
					Schreiben(land, i); // вывод cтроки совпадения
					metaindex = land[i].index; // запоминание индекса
				}
			cout << "\nУдалить эту запись? (y или n): "; //запрос на удаление записи
			Antwort = _getche(); // ответ 
			if ((Antwort != 'y') && (Antwort != 'n')) // проверка ввода
			{
				Prufung(); // оповещение о некорректном вводе 
				system("cls"); // очистка консоли
				goto Such_Fur_Sub_EinLT_VAL; // строка 793
			}
			else if (Antwort == 'y') // если ответ положительный 
				return metaindex; // возвращаем рабочий индекс
			else if (Antwort == 'n') // если ответ отрицательный 
				return 0; // возвращаем ноль-индекс
		}
		else if (leuchtturm > 1) // если совпадений несколько 
		{
			cout << endl;
		Such_Fur_Sub_VielLT_VAL:; // строки 829, 842
			Mutze(); // вывод шапки 
			for (int i = 0; i < Kapazitat; i++) // вывод элементов массива 
				if (strcmp(Zeitspanne, land[i].VAL) == 0)
					Schreiben(land, i); // вывод cтроки совпадения
			cout << "\nВведите индекс записи, которую необходимо удалить (0 - никакую): "; // запрос на удаление
			cin >> TeilDel;
			for (int i = 0; i < strlen(TeilDel); i++) // проверка на символы 
				if ((TeilDel[i] < 48) || (TeilDel[i] > 57))
				{
					Prufung(); // оповещение о некорректном вводе 
					system("cls"); // очистка консоли
					goto Such_Fur_Sub_VielLT_VAL; // строка 817
				}
			if ((strlen(TeilDel) == 1) && (TeilDel[0] == 48)) return 0; // выход в меню удаления 
			for (int i = 0; i < strlen(TeilDel); i++) // определение рабочего сивола  
				metaindex += ((TeilDel[i] - 48) * pow(10, (strlen(TeilDel) - 1 - i)));
			leuchtturm = 0; // обнуление маячка совпадений 
			for (int i = 0; i < Kapazitat; i++) // подсчёт совпадений 
				if (strcmp(Zeitspanne, land[i].VAL) == 0)
					leuchtturm++; // увеличение маячка совпадений
			if (leuchtturm == 0) // если совпадений нет 
			{
				Prufung(); // оповещение о некорректном вводе 
				system("cls"); // очистка консоли
				goto Such_Fur_Sub_VielLT_VAL; // строка 817
			}
			else
				for (int i = 0; i < Kapazitat; i++)
					if (metaindex == land[i].index)
						return metaindex; // возврат рабочего индекса 
		}

	default: // указание несуществующего пункта меню 
		Prufung(); // оповещение о некорректном вводе
		goto Such_Fur_Sub_Hauptablauf; // строка 286
	}
}