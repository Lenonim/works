#include <iostream> // для ввода и вывода
#include <conio.h> // для _getche()
#include "Statik.h" // подключение одноимённого заголовочного файла
#include "Peripherie.h" // подключение кода файла периферии

using namespace std; // подключение пространства имён std

void SreibenDaten(lander*& land , int& Kapazitat) // для вывода элементов массива на экран 
{
	system("cls");  cout << "Вывод содержимого файла: \n\n";
	Mutze(); // вывод шапки
	for (int i = 0; i < Kapazitat; i++) // вывод элементов массива
		Schreiben(land, i); // непосредственный вывод i-того элемента массива структур 
	cout << endl; // для эстетики 
	Wartung(); // организация зарежки 
}

void WahlDaten(lander*& land , int& Kapazitat) // функция выборки 
{
Haupt_Wahl:; // строки 35, 47, 56
	// рабочие переменные 
	system("cls");
	unsigned int NiedrigeGrenze = 0, HoheGrenze = 0; // переменные границ промежутка выборки
	int leuchtturm = 0; // маячок для подсчёта совпадений 
	char Zeitspanne[64]; // защитный буфер - защита от некорректного ввода
	cout << "Укажите промежуток численности населения для выборки\n";

	// ввод нижней границы
	cout << "от "; cin >> Zeitspanne;
	// проверка нижней границы
	for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы
		if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57)) 
		{
			Prufung(); // оповещение о некорректных данных
			goto Haupt_Wahl;  // строка 20
		}
	for (int i = 0; i < strlen(Zeitspanne); i++) // определение нижней границы промежутка
		NiedrigeGrenze += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));

	// ввод верхней границы
	cout << "до "; cin >> Zeitspanne;
	// проверка верхней границы
	for (int i = 0; i < strlen(Zeitspanne); i++) // проверка на символы
		if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
		{
			Prufung(); // оповещение о некорректных данных
			goto Haupt_Wahl;  // строка 20
		}
	for (int i = 0; i < strlen(Zeitspanne); i++) // определение верхней границы промежутка
		HoheGrenze += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));

	// общая проверка
	if (NiedrigeGrenze >= HoheGrenze)
	{
		Prufung(); // оповещение о некорректных данных
		goto Haupt_Wahl;  // строка 20
	}

	// проверка совпадений 
	for (int i = 0; i < Kapazitat; i++)
		if ((land[i].Nas > NiedrigeGrenze) && (land[i].Nas < HoheGrenze))
			leuchtturm++; // при совпадении идёт увеличение маячка 

	// основной ход выборки
	if (leuchtturm == 0) // в случае, если совпадений не было
		cout << "\nНет записей, удовлетворяющих условию!\n\n";
	else // в случае, если совпадения есть
	{
		cout << "\nСтраны, принадлежащие промежутку численности населения [" 
			<< NiedrigeGrenze << ";" << HoheGrenze << "]:\n\n";
		Mutze(); // вывод шапки 
		for (int i = 0; i < Kapazitat; i++) // вывод элементов массива
			if ((land[i].Nas > NiedrigeGrenze) && (land[i].Nas < HoheGrenze)) // условия вывода элементов массива
				Schreiben(land, i); // непосредственный вывод i-той записи
		cout << "\nВсего записей, удовлетворяющих условию: " << leuchtturm << "\n\n"; // вывод количесва совпадений 
	}

	Wartung(); // задержка 
}