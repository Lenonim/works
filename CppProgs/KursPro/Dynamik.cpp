#include <iostream> // для ввода и вывода
#include <conio.h> // для _getche()
#include <stdio.h> // для работы с файлами
#include <fstream> // для работы с файлами
#include <iomanip> // для setw()
#include <cmath> // для pow()
#include "Dynamik.h" // плдключение одноимённого заголовочного файла
#include "Peripherie.h" // подключение кода файла периферии
#include "Suchen.h" // подключение кода файла поиска
#include "Sortierung.h" // подключение кода файла сортировки 

using namespace std; // подключение пространства имён std

string DerNameDesTextes = "BinLender.txt"; // стандарное имя файла 

void LesenDaten(lander*& land, int& Kapazitat)
{
	ifstream wanderung; // переменная для чтения файла

	// открытие файла для работы с ним//
	wanderung.open(DerNameDesTextes, ios::binary | ios::out);

	// проверка открытия файла 
	while (!wanderung.is_open()) // пока не достигнет конца файла 
	{
		// оповещение о неоткрытии файла
		cout << "Файл не открыт, введите имя файла вручную: ";
		cin >> DerNameDesTextes; // ввод полного имени файла вручную
		wanderung.open(DerNameDesTextes); // открытие файла с введёным именем 
		system("cls"); // очистка консоли, чтобы её не загромождать 
	}
	
	Kapazitat = 0;
	wanderung.read((char*)&Kapazitat, sizeof(Kapazitat));
	if (Kapazitat != 0)
	{
		VeranderungZahlDaten(land, Kapazitat, 0);
		for (int i = 0; i < Kapazitat; i++) // процесс считывания данных
			wanderung.read((char*)&land[i], sizeof(land[i]));
		wanderung.close(); // закрытие файла после чтения 
	}
	else
	{
		Kapazitat++; // увеличение размерности массива на первый элемент
		VeranderungZahlDaten(land, Kapazitat, 0);
	ErsteSchrei:; 
		cout << "Внимание, записи отсутствуют! Сделайте первую запись:\n\n";
		char Zeitspanne[64];
		// инддексация
		land[0].index = 1;
		// ввод названия страны 
		cout << "Введите название страны: ";
		cin >> Zeitspanne;
		if (strlen(Zeitspanne) > 25) // проверка по длине
		{
			Prufung(); // оповещение о некорректном вводе 
			goto ErsteSchrei; 
		}
		for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы
			if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
				if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
					if ((Zeitspanne[i] != 95) && (Zeitspanne[i] != 45))
					{
						Prufung(); // оповещение о некорректном вводе 
						goto ErsteSchrei; 
					}
		KorrigierenDaten(Zeitspanne, 1); // коррекция введённых данных
		strcpy_s(land[0].Name, Zeitspanne); // определеине названия страны 

		// ввод названия столицы
		cout << "Введите название столицы: ";
		cin >> Zeitspanne;
		if (strlen(Zeitspanne) > 25) // проверка по длине
		{
			Prufung(); // оповещение о некорректном вводе 
			goto ErsteSchrei;
		}
		for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы 
			if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
				if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
					if ((Zeitspanne[i] != 95) && (Zeitspanne[i] != 45))
					{
						Prufung(); // оповещение о некорректном вводе 
						goto ErsteSchrei; 
					}
		KorrigierenDaten(Zeitspanne, 1); // коррекция введённых данных
		strcpy_s(land[0].HauptStadt, Zeitspanne); // определение названия столицы

		// ввод численности населения 
		cout << "Введите численность населения: ";
		cin >> Zeitspanne;
		if (strlen(Zeitspanne) > 9) // проверка по длине
		{
			Prufung(); // оповещение о некорректном вводе 
			goto ErsteSchrei; 
		}
		for (int j = 0; j < strlen(Zeitspanne); j++) // проверка на символы
			if ((static_cast<int>(Zeitspanne[j]) - 48 < 0) || (static_cast<int>(Zeitspanne[j]) - 48 > 9))
			{
				Prufung(); // оповещение о некорректном вводе 
				goto ErsteSchrei; 
			}
		land[0].Nas = 0; // обнуления для определения
		for (int j = 0; j < strlen(Zeitspanne); j++) // определение численности населения 
			land[0].Nas += (((static_cast<int>(Zeitspanne[j])) - 48) * pow(10, (strlen(Zeitspanne) - 1 - j)));

		// ввод площади
		cout << "Введите площать: ";
		cin >> Zeitspanne;
		if (strlen(Zeitspanne) > 9) // проверка по длине
		{
			Prufung(); // оповещение о некорректном вводе 
			goto ErsteSchrei; 
		}
		for (int j = 0; j < strlen(Zeitspanne); j++) // проверка на символы
			if ((static_cast<int>(Zeitspanne[j]) - 48 < 0) || (static_cast<int>(Zeitspanne[j]) - 48 > 9))
			{
				Prufung(); // оповещение о некорректном вводе 
				goto ErsteSchrei; 
			}
		land[0].Terr = 0; // обнуление для определения 
		for (int j = 0; j < strlen(Zeitspanne); j++) // определение площади
			land[0].Terr += (((static_cast<int>(Zeitspanne[j])) - 48) * pow(10, (strlen(Zeitspanne) - 1 - j)));
		if (land[0].Terr == 0) // предотвращение деления на 0
		{
			Prufung(); // оповещение о некорректном вводе 
			goto ErsteSchrei; 
		}

		// ввод кода валюты страны 
		cout << "Введитье код валюты страны: ";
		cin >> Zeitspanne;
		if (strlen(Zeitspanne) != 3) // проверка по длине
		{
			Prufung(); // оповещение о некорректном вводе 
			goto ErsteSchrei; 
		}
		for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы 
			if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
				if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
				{
					Prufung(); // оповещение о некорректном вводе 
					goto ErsteSchrei; 
				}
		KorrigierenDaten(Zeitspanne, 2); // коррекция введённых данных
		strcpy_s(land[0].VAL, Zeitspanne); // определение валюты страны

		// рассчёт плотности населения 
		land[0].Nas_pro_Terr = land[0].Nas / land[0].Terr;
		// перезапись бинарного файла
		SpeichernDatenInBinFile(land, Kapazitat);
	}
	// изменение индексно-бинарных файлов
	SortierungNachVeranderungen(land, Kapazitat); // функция изменения индексно-бинарных файлов (Sortierung.cpp)
}

void AddierenDaten(lander*& land, int& Kapazitat) 
{
gt_index:; 
	// рабочии переменные
	int metaindex = 0; // для выбора индекса, после которого надо будет добавить запись
	char Zeitspanne[64]; // защитный буфер - защита от некорректных данных
	int x = 0; // для задания количества новых записей 

	// вывод рабочих данных 
	system("cls"); // очистка консоли 
	cout << "Данные записей: \n\n";
	Mutze(); // вывод шапки
	for (int i = 0; i < Kapazitat; i++) // вывод самих данных через итерационный процесс 
		Schreiben(land, i);

	// ввод номера записи
	cout << "\nУкажите номер записи, после которой необходимо добавить информацию: ";
	cin >> Zeitspanne; // ввод защитного буфера 
	for (int i = 0; i < strlen(Zeitspanne); i++) // провека ввода, для преобразования в число
		if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
		{
			Prufung(); // оповещение о некорректном вводе                                             
			goto gt_index;                                                                
		}
	for (int i = 0; i < strlen(Zeitspanne); i++) // получение индекса, после которого будет добавлена запись.
		metaindex += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));

	// провекра совпадений индекса 
	int leuchtturm = 0; // маячок для проверки индексов
	for (int i = 0; i < Kapazitat; i++) // проверка существования введённого индекса 
		if (land[i].index == metaindex)
			leuchtturm++;
	if (leuchtturm == 0)
	{
		Prufung();
		goto gt_index;  
	}

	// ввод количества новых записей 
	cout << "\nСколько записей ВЫ хотите добавить записей? : ";
	cin >> Zeitspanne;
	for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы 
		if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
		{
			Prufung(); // оповещение о некорректном вводе
			goto gt_index; 
		}
	for (int i = 0; i < strlen(Zeitspanne); i++) // получение количества новых записей 
		x += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));

	// расширение динамического массива
	VeranderungZahlDaten(land, Kapazitat, x);
	cout << endl;

	// блок ввода данных
	if (metaindex == Kapazitat) // если ввёднный инт=декс совпадает с последним 
	{
		// блок добавления записей 
		while (x > 0) // зацикливание до тех пор, пока не закончатся новые записи 
		{
		gt_VerSch:; 

			// ввод названия страны
			cout << "Введите название страны: ";
			cin >> Zeitspanne;
			if (strlen(Zeitspanne) > 25) // проверка на длину 
			{
				Prufung(); // оповещение о некорректном вводе 
				system("cls"); // очистка консоли
				goto gt_VerSch; 
			}
			for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы 
				if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
					if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
						if ((Zeitspanne[i] != 95) && (Zeitspanne[i] != 45))
						{
							Prufung(); // оповещение о некорректном вводе 
							system("cls"); // очистка консоли
							goto gt_VerSch; 
						}
			KorrigierenDaten(Zeitspanne, 1); // коррекция введённых данных 
			strcpy_s(land[Kapazitat].Name, Zeitspanne); // определение названия страны 

			// ввод названия столицы
			cout << "Введите название столицы страны: ";
			cin >> Zeitspanne;
			if (strlen(Zeitspanne) > 25) // проверка на длину 
			{
				Prufung(); // оповещение о некорректном вводе 
				system("cls"); // очистка консоли
				goto gt_VerSch; 
			}
			for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы 
				if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
					if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
						if ((Zeitspanne[i] != 95) && (Zeitspanne[i] != 45))
						{
							Prufung(); // оповещение о некорректном вводе 
							system("cls"); // очистка консоли
							goto gt_VerSch; 
						}
			KorrigierenDaten(Zeitspanne, 1); // коррекция введённых данных 
			strcpy_s(land[Kapazitat].HauptStadt, Zeitspanne); // определение названия столицы 

			// ввод численности населения
			cout << "Введите численность населения страны: ";
			cin >> Zeitspanne;
			if (strlen(Zeitspanne) > 10) // проверка на длину 
			{
				Prufung(); // оповещение о некорректном вводе 
				system("cls"); // очистка консоли
				goto gt_VerSch; 
			}
			for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы 
				if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
				{
					Prufung(); // оповещение о некорректном вводе 
					system("cls"); // очистка консоли
					goto gt_VerSch; 
				}
			land[Kapazitat].Nas = 0; // обнуление для определения
			for (int i = 0; i < strlen(Zeitspanne); i++) // определение численности населения 
				land[Kapazitat].Nas += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));

			// ввод площади страны
			cout << "Введите площадь страны: ";
			cin >> Zeitspanne;
			if (strlen(Zeitspanne) > 9) // проверка на длину 
			{
				Prufung(); // оповещение о некорректном вводе 
				system("cls"); // очистка консоли
				goto gt_VerSch; 
			}
			for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы 
				if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
				{
					Prufung(); // оповещение о некорректном вводе 
					system("cls"); // очистка консоли
					goto gt_VerSch; 
				}
			land[Kapazitat].Terr = 0; // обнуление для определения
			for (int i = 0; i < strlen(Zeitspanne); i++) // определение площади
				land[Kapazitat].Terr += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));
			if (land[Kapazitat].Terr == 0)
			{
				Prufung(); // оповещение о некорректном вводе 
				system("cls"); // очистка консоли
				goto gt_VerSch; 
			}

			// ввод кода валюты страны
			cout << "Введите код валюты страны: ";
			cin >> Zeitspanne;
			if (strlen(Zeitspanne) != 3) // проверка на длину 
			{
				Prufung(); // оповещение о некорректном вводе 
				system("cls"); // очистка консоли
				goto gt_VerSch; 
			}
			for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы 
				if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
					if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
					{
						Prufung(); // оповещение о некорректном вводе 
						system("cls"); // очистка консоли
						goto gt_VerSch; 
					}
			KorrigierenDaten(Zeitspanne, 2); // коррекция введённых данных 
			strcpy_s(land[Kapazitat].VAL, Zeitspanne); // определение кода валюты

			// редакция плотности и индекса
			land[Kapazitat].Nas_pro_Terr = land[Kapazitat].Nas / land[Kapazitat].Terr; // расчёт плотности населения 
			land[Kapazitat].index = Kapazitat + 1; // индексация 
			Kapazitat++; // увеличение размерности

			// контроль оставшегося числа новых записей 
			x--; // уменьшение числа записей
			if (x >= 1) // проверка количества введённых записей
				cout << "\nСделайте ещё одну запись\n\n";
		}
	}
	else // если введённый индекс не совпадает с последним 
	{
		while (x > 0) // пока не закончатся новые записи 
		{
			Kapazitat++; // расширения размерности массива 
			for (int i = Kapazitat - 1; i > 0; i--)
			{
				if (i - 1 == metaindex) // поиск необходимого элемента 
				{
					land[i] = land[i - 1]; // заключительный этап сортировки 
					land[i].index = metaindex + 2; // индексация новой записи 
				gt_ZVerSch:; 

					// ввод названия страны 
					cout << "Введите название страны: ";
					cin >> Zeitspanne;
					if (strlen(Zeitspanne) > 25) // проверка на длину 
					{
						Prufung(); // оповещение о некорректном вводе 
						system("cls"); // очистка консоли
						goto gt_ZVerSch;
					}
					for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы 
						if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
							if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
								if ((Zeitspanne[i] != 95) && (Zeitspanne[i] != 45))
								{
									Prufung(); // оповещение о некорректном вводе 
									system("cls"); // очистка консоли
									goto gt_ZVerSch; 
								}
					KorrigierenDaten(Zeitspanne, 1); // коррекция введённых данных 
					strcpy_s(land[metaindex].Name, Zeitspanne); // определение названия страны 

					// ввод названия столицы 
					cout << "Введите название столицы страны: ";
					cin >> Zeitspanne;
					if (strlen(Zeitspanne) > 25) // проверка на длину 
					{
						Prufung(); // оповещение о некорректном вводе 
						system("cls"); // очистка консоли 
						goto gt_ZVerSch; 
					}
					for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы 
						if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
							if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
								if ((Zeitspanne[i] != 95) && (Zeitspanne[i] != 45))
								{
									Prufung(); // оповещение о некорректном вводе 
									system("cls"); // очистка консоли
									goto gt_ZVerSch; 
								}
					KorrigierenDaten(Zeitspanne, 1); // коррекция введённых данных 
					strcpy_s(land[metaindex].HauptStadt, Zeitspanne); // определение названия столицы 

					// ввод численности населения страны 
					cout << "Введите численность населения страны: ";
					cin >> Zeitspanne;
					if (strlen(Zeitspanne) > 10) // проверка на длину 
					{
						Prufung(); // оповещение о некорректном вводе 
						system("cls"); // очистка консоли
						goto gt_ZVerSch; 
					}
					for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы 
						if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
						{
							Prufung(); // оповещение о некорректном вводе 
							system("cls"); // очистка консоли
							goto gt_ZVerSch; 
						}
					land[metaindex].Nas = 0; // обнуление для определения
					for (int i = 0; i < strlen(Zeitspanne); i++) // определение численности населения 
						land[metaindex].Nas += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));

					// ввод площади населения 
					cout << "Введите площадь старны: ";
					cin >> Zeitspanne;
					if (strlen(Zeitspanne) > 9) // проверка на длину 
					{
						Prufung(); // оповещение о некорректном вводе 
						system("cls"); // очистка консоли
						goto gt_ZVerSch; 
					}
					for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы 
						if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
						{
							Prufung(); // оповещение о некорректном вводе 
							system("cls"); // очистка консоли
							goto gt_ZVerSch; 
						}
					land[metaindex].Terr = 0; // обнуление для определения
					for (int i = 0; i < strlen(Zeitspanne); i++) // определение площади 
						land[metaindex].Terr += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));
					if (land[metaindex].Terr == 0) // предовтращения деления на 0
					{
						Prufung(); // оповещение о некорректном вводе 
						system("cls"); // очистка консоли
						goto gt_ZVerSch; 
					}

					// ввод кода валюты
					cout << "Введите код валюты страны: ";
					cin >> Zeitspanne;
					if (strlen(Zeitspanne) != 3) // проверка на длину 
					{
						Prufung(); // оповещение о некорректном вводе 
						system("cls"); // очистка консоли
						goto gt_ZVerSch; 
					}
					for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы 
						if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
							if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
							{
								Prufung(); // оповещение о некорректном вводе 
								system("cls"); // очистка консоли
								goto gt_ZVerSch; 
							}
					KorrigierenDaten(Zeitspanne, 2); // коррекция введённых данных 
					strcpy_s(land[metaindex].VAL, Zeitspanne); // определение кода валюты

					// редакция индекса для дальнейшей сортировки и плотности
					land[metaindex].Nas_pro_Terr = land[metaindex].Nas / land[metaindex].Terr; // рассчёт плотносит населения 
					metaindex++;  // изменение рабочего индекса добавления 
					land[metaindex - 1].index = metaindex; // индексация 

					x--; // уменьшение числа записей
					break; // выход из цикла for 
				}
				else
				{
					swap(land[i], land[i - 1]); // сортировка 
					land[i].index++; // индексация 
				}
			}
			if (x >= 1) // проверка количества введённых записей
				cout << "\nСделайте ещё одну запись\n\n";
		}
	}

	// перезапись бинарного файла
	SpeichernDatenInBinFile(land, Kapazitat);

	// изменение индексно-бинарных файлов 
	SortierungNachVeranderungen(land, Kapazitat);

	Wartung(); // организация задержки 
}

void SubstragierenDaten(lander*& land, int& Kapazitat)
{
Sub_Wahl:; 
	char Antwort; // для хода по меню
	char Zeitspanne[64]; // защитный буфер - защита от некорректного ввода 
	int  metaindex = 0; // переменная, по которой будет происходить удаление

	// меню удаления
	system("cls"); // очистка консоли
	cout << "Как будет происходить удаление?\n\n"
		<< "1 - по идексу записи\n"
		<< "2 - найти запись по полю и удалить её\n"
		<< "0 - выход в меню\n\n"
		<< "Пункт меню: ";
	Antwort = _getche(); // пункт меню

	// получение индекса удаления 
	if (Antwort == '0') // выход из меню
	{
		system("cls"); // очистка консоли
		goto gt_UmSchSub; 
	}
	else if ((Antwort != '1') && (Antwort != '2')) // проверка вода пункта меню
	{
		Prufung(); // оповещене о некорректном вводе
		goto Sub_Wahl; 
	}
	else if (Antwort == '1') // удаление по индексу 
	{
	gt_SubDat:; 
		// вывод записей
		system("cls"); // очистка консоли
		cout << "Данные записей: \n\n";
		Mutze(); // вывод элементов шапки
		for (int i = 0; i < Kapazitat; i++) // вывод элементво массива
			Schreiben(land, i); // вывод i-той записи
		metaindex = 0; // обнуление для определения
		// ввод индекса записи, которую необходимо удалить 
		cout << "\nВведите номер строки, для удаления её из списка: ";
		cin >> Zeitspanne;
		for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы 
			if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
			{
				Prufung(); // оповещение о некорректном вводе
				goto gt_SubDat; 
			}
		for (int i = 0; i < strlen(Zeitspanne); i++) // определение рабочего индекса
			metaindex += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));
		if ((metaindex > Kapazitat) || (metaindex < land[0].index))
		{
			Prufung(); // оповещение о некорректном вводе
			goto gt_SubDat;
		}
	}
	else if (Antwort == '2') // удаление по поиску
	{
		metaindex = SuchenFurSubstragierung(land, Kapazitat); // получение рабочего индекса через функцию поиска
		if (metaindex == 0) // условие возврата в начальное меню
			goto Sub_Wahl; 
	}

	// сортировка после получения рабочего индекса (удаляемая строка в самый вверх)
	for (int i = 0; i < Kapazitat; i++)
		if (metaindex == land[i].index) // условие сортировки 
			for (int j = i; j < Kapazitat; j++)
			{
				if (j == Kapazitat - 1) // если достигнут предконец массива
				{
					Kapazitat--; // уменьшение размерности массива 
					break;
				}
				swap(land[j], land[j + 1]); // перестановка 
				land[j].index--; // индексация
			}

gt_Runde:; 
	system("cls"); // очистка консоли
	cout << "Данные записей: \n\n";
	Mutze(); // вывод элементов шапки
	for (int i = 0; i < Kapazitat; i++) // вывод элементов массива
		Schreiben(land, i); // вывод i-той записи
	cout << "\nУдалить ещё? (y или n): "; // запрос на повтор 
	Antwort = _getche(); // ответ
	if ((Antwort != 'y') && (Antwort != 'n')) // проверка ввода
	{
		Prufung(); // оповещение о некорректном вводе
		goto gt_Runde; 
	}
	if (Antwort == 'y') goto Sub_Wahl;
	else if (Antwort == 'n') // конец удаления 
	{
	gt_UmSchSub:; 
		system("cls"); // очистка консоли 
		cout << "Данные записей: \n\n";  Mutze(); // вывод элементов шапки
		for (int i = 0; i < Kapazitat; i++) // вывод элементов массива
			Schreiben(land, i); // вывод i-той записи
		cout << "\nПерезаписать данные? (y или n): "; // запрос на перезщапись данных
		Antwort = _getche(); // ответ 
		if ((Antwort != 'y') && (Antwort != 'n')) // проверка ввода
		{
			Prufung(); // оповещение о некорректном вводе
			goto gt_UmSchSub;
		}
		else if ((Antwort == 'y')) // перезаписывать данные
		{

			// уменьшение динамического массива
			VeranderungZahlDaten(land, Kapazitat, 0);

			// перезапись бинарного файла
			SpeichernDatenInBinFile(land, Kapazitat);
			cout << "\n\nДанные перезаписаны\n"; // оповещение о сохранённых данных
		}
		else if (Antwort == 'n') // не перезаписывать данные 
		{
			LesenDaten(land, Kapazitat);
			cout << "\n\nДанные остались без изменений\n";
		}
	}

	// перезапись индексно-бинарных файлов
	SortierungNachVeranderungen(land, Kapazitat); // изменение инд.-бин. файлов
	Wartung();
}

void UmSreibenData(lander*& land, int& Kapazitat)  
{
USD_Alles:; 
	// рабочие переменные 
	int metaindex = 0; // обнуление рабочего индекса
	char Zeitspanne[64]; // защитный буфер - защита от некорректного ввода
	char Antwort; // для хода по функции 

	// ввывод записей 
	system("cls"); // очистка консоли
	cout << "Данные записей: \n\n";
	Mutze(); // вывод шапки
	for (int i = 0; i < Kapazitat; i++) // вывод элементов массива 
		Schreiben(land, i); // вывод i-той записи

	// ввод индекса записи
	cout << "\nВведите номер записи, которую необходимо отредактировать: ";
	cin >> Zeitspanne;
	for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы 
		if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
		{
			Prufung(); // оповещение о некорректном вводе 
			goto USD_Alles; 
		}
	for (int i = 0; i < strlen(Zeitspanne); i++) // определение рабочего индекса
		metaindex += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));
	if ((metaindex > Kapazitat) || (metaindex < land[0].index)) // проверка существования индекса 
	{
		Prufung(); // оповещение о некорректном вводе 
		goto USD_Alles; 
	}

	// выбор режима редакции 
	cout << "\nОтредактировать всю запись? 'y' - всю, 'n' - часть записи: ";
	Antwort = _getche(); // ввод ответа 
	if ((Antwort != 'y') && (Antwort != 'n')) // проверка ввода ответа 
	{
		Prufung(); // оповещение о некорректном вводе 
		goto USD_Alles; 
	}
	if (Antwort == 'y') // редакция всей записи 
	{
	Alles_Um:; 

		// вывод редакции всей записи
		system("cls"); // очистка консоли  
		cout << "Редакция всей записи\n\n";
		Mutze(); // вывод элементов шапки
		for (int i = 0; i < Kapazitat; i++) // вывод элементов массива
			if ((metaindex == land[i].index)) // условие вывода 
				Schreiben(land, i); // вывод i-той записи

		// воод данных 
		for (int i = 0; i < Kapazitat; i++) // поиск изменяемой записи 
			if ((metaindex == land[i].index)) // условие остановки 
			{
				// ввод названия страны 
				cout << "\nВведите название страны: ";
				cin >> Zeitspanne;
				if (strlen(Zeitspanne) > 25) // проверка по длине
				{
					Prufung(); // оповещение о некорректном вводе 
					goto Alles_Um; 
				}
				for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы
					if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
						if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
							if ((Zeitspanne[i] != 95) && (Zeitspanne[i] != 45))
							{
								Prufung(); // оповещение о некорректном вводе 
								goto Alles_Um; 
							}
				KorrigierenDaten(Zeitspanne, 1); // коррекция введённых данных
				strcpy_s(land[i].Name, Zeitspanne); // определеине названия страны 

				// ввод названия столицы
				cout << "Введите название столицы: ";
				cin >> Zeitspanne;
				if (strlen(Zeitspanne) > 25) // проверка по длине
				{
					Prufung(); // оповещение о некорректном вводе 
					goto Alles_Um; 
				}
				for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы 
					if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
						if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
							if ((Zeitspanne[i] != 95) && (Zeitspanne[i] != 45))
							{
								Prufung(); // оповещение о некорректном вводе 
								goto Alles_Um; 
							}
				KorrigierenDaten(Zeitspanne, 1); // коррекция введённых данных
				strcpy_s(land[i].HauptStadt, Zeitspanne); // определение названия столицы

				// ввод численности населения 
				cout << "Введите численность населения: ";
				cin >> Zeitspanne;
				if (strlen(Zeitspanne) > 9) // проверка по длине
				{
					Prufung(); // оповещение о некорректном вводе 
					goto Alles_Um; 
				}
				for (int j = 0; j < strlen(Zeitspanne); j++) // проверка на символы
					if ((static_cast<int>(Zeitspanne[j]) - 48 < 0) || (static_cast<int>(Zeitspanne[j]) - 48 > 9))
					{
						Prufung(); // оповещение о некорректном вводе 
						goto Alles_Um; 
					}
				land[i].Nas = 0; // обнуления для определения
				for (int j = 0; j < strlen(Zeitspanne); j++) // определение численности населения 
					land[i].Nas += (((static_cast<int>(Zeitspanne[j])) - 48) * pow(10, (strlen(Zeitspanne) - 1 - j)));

				// ввод площади
				cout << "Введите площать: ";
				cin >> Zeitspanne;
				if (strlen(Zeitspanne) > 9) // проверка по длине
				{
					Prufung(); // оповещение о некорректном вводе 
					goto Alles_Um; 
				}
				for (int j = 0; j < strlen(Zeitspanne); j++) // проверка на символы
					if ((static_cast<int>(Zeitspanne[j]) - 48 < 0) || (static_cast<int>(Zeitspanne[j]) - 48 > 9))
					{
						Prufung(); // оповещение о некорректном вводе 
						goto Alles_Um; 
					}
				land[i].Terr = 0; // обнуление для определения 
				for (int j = 0; j < strlen(Zeitspanne); j++) // определение площади
					land[i].Terr += (((static_cast<int>(Zeitspanne[j])) - 48) * pow(10, (strlen(Zeitspanne) - 1 - j)));
				if (land[i].Terr == 0) // предотвращение деления на 0
				{
					Prufung(); // оповещение о некорректном вводе 
					goto Alles_Um; 
				}

				// ввод кода валюты страны 
				cout << "Введитье код валюты страны: ";
				cin >> Zeitspanne;
				if (strlen(Zeitspanne) != 3) // проверка по длине
				{
					Prufung(); // оповещение о некорректном вводе 
					goto Alles_Um; 
				}
				for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы 
					if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
						if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
						{
							Prufung(); // оповещение о некорректном вводе 
							goto Alles_Um; 
						}
				KorrigierenDaten(Zeitspanne, 2); // коррекция введённых данных
				strcpy_s(land[i].VAL, Zeitspanne); // определение валюты страны

				// рассчёт плотности населения 
				land[i].Nas_pro_Terr = land[i].Nas / land[i].Terr;
				break;
			}

		// вывод обновлённой записи
		cout << "\nОбновлённая запись: \n\n";
		Mutze(); // вывод шапки 
		for (int i = 0; i < Kapazitat; i++) // вывод записей массива
			if ((metaindex == land[i].index)) // условие вывода
				Schreiben(land, i); // вывод i-той записи
		cout << endl;

		Wartung(); // задержка
	}
	else
	{
		while (Antwort != '0') // обеспечение работы с меню редакции 
		{
		USD_Teil:; 
			system("cls"); // очистка консоли

			// вовыд меню редакции 
			Mutze(); // вывод элементов шапки 
			Schreiben(land, (metaindex - 1)); // вывод элементов выбранной записи 
			cout << "\nКакое поле изменить?\n\n" // меню редакции 
				<< "1 - Название страны\n"
				<< "2 - Название столицы\n"
				<< "3 - Численность населения\n"
				<< "4 - Площадь населения\n"
				<< "5 - Код валюты\n"
				<< "0 - Выход из редактирования\n\n"
				<< "Выберите поле: ";
			Antwort = _getche(); // выбор пункта меню редакции 

			// ход по меню редакции
			if (Antwort == '0') break; // выход из меню редакции 
			switch (Antwort)
			{

			case '1': // редакция названия страны
				cout << "\n\nВведите название страны: ";
				cin >> Zeitspanne;
				if (strlen(Zeitspanne) > 25) // проверка на длину
				{
					Prufung(); // опопвещение о некорректном вводе 
					goto USD_Teil; 
				}
				for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы
					if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
						if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
							if ((Zeitspanne[i] != 95) && (Zeitspanne[i] != 45))
							{
								Prufung(); // опопвещение о некорректном вводе 
								goto USD_Teil;
							}
				KorrigierenDaten(Zeitspanne, 1); // коррекция введённх данных
				strcpy_s(land[metaindex - 1].Name, Zeitspanne); // определение названия страны
				break;

			case '2': // редакция названия столицы
				cout << "\n\nВведите название столицы: ";
				cin >> Zeitspanne;
				if (strlen(Zeitspanne) > 25) // проверка на длину
				{
					Prufung(); // опопвещение о некорректном вводе 
					goto USD_Teil; 
				}
				for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы
					if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
						if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
							if ((Zeitspanne[i] != 95) && (Zeitspanne[i] != 45))
							{
								Prufung(); // опопвещение о некорректном вводе 
								goto USD_Teil; 
							}
				KorrigierenDaten(Zeitspanne, 1); // коррекция введённых данных
				strcpy_s(land[metaindex - 1].HauptStadt, Zeitspanne); // определение столицы страны
				break;

			case '3': // редакция численности населения 
				cout << "\n\nВведите численность населения: ";
				cin >> Zeitspanne;
				if (strlen(Zeitspanne) > 10) // проверка на длину
				{
					Prufung(); // опопвещение о некорректном вводе 
					goto USD_Teil;
				}
				for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы
					if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
					{
						Prufung(); // опопвещение о некорректном вводе 
						goto USD_Teil; 
					}
				land[metaindex - 1].Nas = 0; // обнуление для определения 
				for (int i = 0; i < strlen(Zeitspanne); i++) // определение численности населения 
					land[metaindex - 1].Nas += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));
				// переопределение плотности
				land[metaindex - 1].Nas_pro_Terr = land[metaindex - 1].Nas / land[metaindex - 1].Terr;
				break;

			case '4': // редакция плотости населения 
				cout << "\n\nВведите площадь населения: ";
				cin >> Zeitspanne;
				if (strlen(Zeitspanne) > 9) // проверка на длину
				{
					Prufung(); // опопвещение о некорректном вводе 
					goto USD_Teil; 
				}
				for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы 
					if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
					{
						Prufung(); // опопвещение о некорректном вводе 
						goto USD_Teil; 
					}
				land[metaindex - 1].Terr = 0; // обнуление для определения 
				for (int i = 0; i < strlen(Zeitspanne); i++) // определение площади
					land[metaindex - 1].Terr += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));
				if (land[metaindex - 1].Terr == 0) // протвращение деления на ноль
				{
					Prufung(); // опопвещение о некорректном вводе 
					goto USD_Teil; 
				}
				// переопределение плотности 
				land[metaindex - 1].Nas_pro_Terr = land[metaindex - 1].Nas / land[metaindex - 1].Terr;
				break;

			case '5': // редакция кода валюты страны
				cout << "\n\nВведите код валюты: ";
				cin >> Zeitspanne;
				if (strlen(Zeitspanne) != 3) // проверка на длину
				{
					Prufung(); // опопвещение о некорректном вводе 
					goto USD_Teil; 
				}
				for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы 
					if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
						if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
						{
							Prufung(); // опопвещение о некорректном вводе 
							goto USD_Teil;
						}
				KorrigierenDaten(Zeitspanne, 2); // коррекция вводимых данных
				strcpy_s(land[metaindex - 1].VAL, Zeitspanne); // определение кода валюты страны

				break;
			default:
				Prufung(); // оповещение о некорректном вводе 
				goto USD_Teil; 
				break;
			}
		}
	}

	// изменение бинарных файлов
	SpeichernDatenInBinFile(land, Kapazitat);

	// изменение индексно-бинарных файлов  
	SortierungNachVeranderungen(land, Kapazitat); // изменение инд.-бин. файлов
}

void SpeichernDatenInTextFile(lander*& land, int& Kapazitat)
{
	system("cls"); // очистка консоли 
	ofstream reisen; // переменная для записи в файл
	reisen.open("Lender.txt"); // открытие соответствующего файла
	reisen << "Notes: " << Kapazitat; // запись рабочей строки
	for (int j = 0; j < Kapazitat; j++) // запись элементов массива
		reisen << endl << setw(26) << setiosflags(ios::left) << land[j].Name // запись названия страны
		<< setw(26) << land[j].HauptStadt // запись нназвания столицы
		<< setw(15) << land[j].Nas // запись численности населения страны
		<< setw(15) << land[j].Terr // запись площади страны
		<< setw(3) << land[j].VAL; // запись кода валюты страны
	reisen.close(); // закрытие файла
	cout << "Данные успешно сохранены\n\n";
	Wartung();
}

void VeranderungZahlDaten(lander*& land, int& Kapazitat, int delta)
{
	lander* buffer = new lander[Kapazitat + delta]; // создание переменного буфера 
	for (int i = 0; i < Kapazitat; i++) // сохранение данных в переменных буфер 
		buffer[i] = land[i];
	delete[] land; // очистка основного буфера
	land = new lander[Kapazitat + delta]; // переопределение основного буфера 
	for (int i = 0; i < Kapazitat; i++) // сохранение данных в расширенный основной буфер
		land[i] = buffer[i];
	delete[] buffer; // очистка переменного буфера
}

void SpeichernDatenInBinFile(lander*& land, int& Kapazitat)
{
	ofstream reisen; // переменная для записи в файл
	reisen.open(DerNameDesTextes, ios::binary | ios::out); // открытие бинарног файла
	reisen.write((char*)&Kapazitat, sizeof(Kapazitat)); // запись рабочей строки
	for (int i = 0; i < Kapazitat; i++) // запись изменённой последовательности индексов
		reisen.write((char*)&land[i], sizeof(land[i]));
	reisen.close(); // закрытие файла
}