#include <iostream> // для ввода и вывода
#include <iomanip> // для setw()
#include <conio.h> // для _getche()
#include <stdio.h> // для работы с файлами
#include <fstream> // для работы с файлами
#include "Peripherie.h" // подключение кода файла периферии
#include "Sortierung.h" // подключение одноимённого заголовочного файла

using namespace std; // подключение пространства имён std

// вынесенные прототипы функций для взаимного использования функций, хранящихся в этом модуле 
int HeranSortierung(lander*& land , int i, int j); // прямой ход сортировки
void ZuruckSortierung(lander*& land , int& Kapazitat); // обратный ход сортировки 

void SortieranDaten(lander*& land , int& Kapazitat) // сортировка данных 
{
Haupt_Sortierung:; // строка 151
	// рабочие переменные 
	ifstream IndexFileR; // для чтения индексно-бинарных файлов
	int K = Kapazitat; // для передачи размерности по ссылке в другие функции 
	int* metamass = new int[Kapazitat]; // для чтения индексов из индексно-бинарных файлов
	char laufgang = '8'; // для хода по меню

	// ход сортировки
	while (laufgang != '0') // организация повторяющегося меню 
	{
		system("cls"); // очистка консоли 
		cout << "Меню сортировки:\n\n" // меню сортировки 
			<< "1 - сортировка по названию страны (по алфавиту)\n"
			<< "2 - сортировка по названию столицы страны (по алфавиту)\n"
			<< "3 - сортировка по численности населения страны (по убыванию)\n"
			<< "4 - сортировка по площади страны (по убыванию)\n"
			<< "5 - сортировка по плотности населения страны (по убыванию)\n"
			<< "6 - сортировка по коду валюты страны (по алфавиту)\n"
			<< "0 - выход из меню сортировки\n"
			<< "\nВыбор пункта меню: ";
		laufgang = _getche(); // выбор пункта меню 
		switch (laufgang) // распределение по меню 
		{
		case '1':
			system("cls"); // очистка консоли 

			// открытие инд.-бин. файла в бинарном режиме для чтения 
			IndexFileR.open("Sort_Name_Bin.txt", ios::binary | ios::out); 
			for (int i = 0; i < Kapazitat; i++) // чтение данных из файла
				IndexFileR.read((char*)&metamass[i], sizeof(metamass[i]));
			IndexFileR.close(); // закрытие индексно-бинарного файла
			// вывод сортировки 
			Mutze(); // вывод шапки
			for (int i = 0; i < Kapazitat; i++) // вывод отсортированного массива
				for (int j = 0; j < Kapazitat; j++)
					if (metamass[i] == land[j].index) // условие вывода
						Schreiben(land, j);

			cout << endl; // для эстетики
			Wartung(); // организация задержки
			break;
		case '2':
			system("cls"); // очистка консоли

			// открытие инд.-бин. файла в бинарном режиме для чтения 
			IndexFileR.open("Sort_Hauptstadt_Bin.txt", ios::binary | ios::out); 
			for (int i = 0; i < Kapazitat; i++) // чтение данных из файла
				IndexFileR.read((char*)&metamass[i], sizeof(metamass[i]));
			IndexFileR.close(); // закрытие индексно-бинарного файла
			// вывод сортировки
			Mutze(); // вывод шапки
			for (int i = 0; i < Kapazitat; i++) // вывод отсортированного массива
				for (int j = 0; j < Kapazitat; j++)
					if (metamass[i] == land[j].index) // условие вывода
						Schreiben(land, j);

			cout << endl; // для эстетики
			Wartung(); // организация задержки
			break;
		case '3':
			system("cls"); // очистка консоли

			// открытие инд.-бин. файла в бинарном режиме для чтения 
			IndexFileR.open("Sort_Nas_Bin.txt", ios::binary | ios::out); 
			for (int i = 0; i < Kapazitat; i++) // чтение данных из файла
				IndexFileR.read((char*)&metamass[i], sizeof(metamass[i]));
			IndexFileR.close(); // закрытие индексно-бинарного файла
			// вывод сортировки
			Mutze(); // вывод шапки
			for (int i = 0; i < Kapazitat; i++) // вывод отсортированного массива
				for (int j = 0; j < Kapazitat; j++)
					if (metamass[i] == land[j].index) // условие вывода
						Schreiben(land, j);

			cout << endl; // для эстетики
			Wartung(); // организация задержки
			break;
		case '4':
			system("cls"); // очистка консоли

			// открытие инд.-бин. файла в бинарном режиме для чтения 
			IndexFileR.open("Sort_Terr_Bin.txt", ios::binary | ios::out); 
			for (int i = 0; i < Kapazitat; i++) // чтение данных из файла
				IndexFileR.read((char*)&metamass[i], sizeof(metamass[i]));
			IndexFileR.close(); // закрытие индексно-бинарного файла
			// вывод сортировки
			Mutze(); // вывод шапки
			for (int i = 0; i < Kapazitat; i++) // вывод отсортированного массива
				for (int j = 0; j < Kapazitat; j++)
					if (metamass[i] == land[j].index) // условие вывода
						Schreiben(land, j);

			cout << endl; // для эстетики
			Wartung(); // организация задержки
			break;
		case '5':
			system("cls"); // очистка консоли

			// открытие инд.-бин. файла в бинарном режиме для чтения 
			IndexFileR.open("Sort_Nas_pro_Terr_Bin.txt", ios::binary | ios::out); 
			for (int i = 0; i < Kapazitat; i++) // чтение данных из файла
				IndexFileR.read((char*)&metamass[i], sizeof(metamass[i]));
			IndexFileR.close(); // закрытие индексно-бинарного файла
			// вывод сортировки
			Mutze(); // вывод шапки
			for (int i = 0; i < Kapazitat; i++) // вывод отсортированного массива
				for (int j = 0; j < Kapazitat; j++)
					if (metamass[i] == land[j].index) // условие вывода
						Schreiben(land, j);

			cout << endl; // для эстетики
			Wartung(); // организация задержки
			break;
		case '6':
			system("cls"); // очистка консоли

			// открытие инд.-бин. файла в бинарном режиме для чтения 
			IndexFileR.open("Sort_VAL_Bin.txt", ios::binary | ios::out); 
			for (int i = 0; i < Kapazitat; i++) // чтение данных из файла
				IndexFileR.read((char*)&metamass[i], sizeof(metamass[i]));
			IndexFileR.close(); // закрытие индексно-бинарного файла
			// вывод сортировки
			Mutze(); // вывод шапки
			for (int i = 0; i < Kapazitat; i++) // вывод отсортированного массива
				for (int j = 0; j < Kapazitat; j++)
					if (metamass[i] == land[j].index) // условие вывода
						Schreiben(land, j);

			cout << endl; // для эстетики
			Wartung(); // организация задержки
			break;
		case '0': break; // для быстрого выхода из меню 
		default:
			Prufung(); // предупреждение о некорректном вводе
			goto Haupt_Sortierung; // строка 17
			break;
		}
	}
	system("cls"); // очистка консоли 
}

int HeranSortierung(lander*& land , int i, int j) // прямой ход ортировки 
{
	swap(land[i], land[j]); // перестановка значений 
	return 0; // возвращение обнулённого счётчика обхода
}

void ZuruckSortierung(lander*& land , int& Kapazitat) // обратный ход сортировки 
{
	for (int i = 0; i < Kapazitat; i++) // сортировка по индексу            
		for (int j = i + 1; j < Kapazitat; j++) // другими словами          
			if (land[i].index > land[j].index) // возврат исходного порядка 
				i = HeranSortierung(land, i, j); // прямой ход в обратном ходе :3
	cout << endl; // для эстетики 
}

void SortierungNachVeranderungen(lander*& land , int& K) // сортировка индексно-бинарных файлов после изменения данных
{
	ofstream IndexReisen; // переменная для изменения индексных файлов

	// сортировка по названию страны
	for (int i = 0; i < K; i++)
		for (int j = i + 1; j < K; j++)
			if (strcmp(land[i].Name, land[j].Name) > 0) // стравнение переменных для сортировки
				i = HeranSortierung(land, i, j); // непосредственная сортировка 
	// открытие соответствующего индексного-бинарного файла и его перезапись 
	IndexReisen.open("Sort_Name_Bin.txt", ios::binary | ios::out);
	for (int i = 0; i < K; i++) // запись изменённой последовательности индексов
		IndexReisen.write((char*)&land[i].index, sizeof(land[i].index));
	IndexReisen.close(); // закрытие файла

	// сортировка по названию столицы
	for (int i = 0; i < K; i++)
		for (int j = i + 1; j < K; j++)
			if (strcmp(land[i].HauptStadt, land[j].HauptStadt) > 0) // стравнение переменных для сортировки
				i = HeranSortierung(land, i, j); // непосредственная сортировка
	// открытие соответствующего индексного-бинарного файла и его перезапись 
	IndexReisen.open("Sort_Hauptstadt_Bin.txt", ios::binary | ios::out);
	for (int i = 0; i < K; i++) // запись изменённой последовательности индексов
		IndexReisen.write((char*)&land[i].index, sizeof(land[i].index));
	IndexReisen.close(); // закрытие файла

	// сортировка по численности населения страны 
	for (int i = 0; i < K; i++)
		for (int j = i + 1; j < K; j++)
			if (land[i].Nas < land[j].Nas) // стравнение переменных для сортировки
				i = HeranSortierung(land, i, j); // непосредственная сортировка
	// открытие соответствующего индексного-бинарного файла и его перезапись 
	IndexReisen.open("Sort_Nas_Bin.txt", ios::binary | ios::out);
	for (int i = 0; i < K; i++) // запись изменённой последовательности индексов
		IndexReisen.write((char*)&land[i].index, sizeof(land[i].index));
	IndexReisen.close(); // закрытие файла

	// сортировка по площади страны 
	for (int i = 0; i < K; i++)
		for (int j = i + 1; j < K; j++)
			if (land[i].Terr < land[j].Terr) // стравнение переменных для сортировки
				i = HeranSortierung(land, i, j); // непосредственная сортировка
	// открытие соответствующего индексного-бинарного файла и его перезапись 
	IndexReisen.open("Sort_Terr_Bin.txt", ios::binary | ios::out);
	for (int i = 0; i < K; i++) // запись изменённой последовательности индексов
		IndexReisen.write((char*)&land[i].index, sizeof(land[i].index));
	IndexReisen.close(); // закрытие файла

	// сортировка по плотности населения
	for (int i = 0; i < K; i++)
		for (int j = i + 1; j < K; j++)
			if (land[i].Nas_pro_Terr < land[j].Nas_pro_Terr) // стравнение переменных для сортировки
				i = HeranSortierung(land, i, j); // непосредственная сортировка
	// открытие соответствующего индексного-бинарного файла и его перезапись  
	IndexReisen.open("Sort_Nas_pro_Terr_Bin.txt", ios::binary | ios::out);
	for (int i = 0; i < K; i++) // запись изменённой последовательности индексов
		IndexReisen.write((char*)&land[i].index, sizeof(land[i].index));
	IndexReisen.close(); // закрытие файла

	// сортировка по коду валюты страны
	for (int i = 0; i < K; i++)
		for (int j = i + 1; j < K; j++)
			if (strcmp(land[i].VAL, land[j].VAL) > 0) // стравнение переменных для сортировки
				i = HeranSortierung(land, i, j); // непосредственная сортировка
	// открытие соответствующего индексного-бинарного файла и его перезапись 
	IndexReisen.open("Sort_VAL_Bin.txt", ios::binary | ios::out);
	for (int i = 0; i < K; i++) // запись изменённой последовательности индексов
		IndexReisen.write((char*)&land[i].index, sizeof(land[i].index));
	IndexReisen.close(); // закрытие файла

	// возвращение данных в исходный порядок 
	ZuruckSortierung(land, K);
}