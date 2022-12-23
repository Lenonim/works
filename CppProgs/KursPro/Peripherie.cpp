#include <iostream> // для ввода и вывода
#include <iomanip> // для setw ()
#include "Peripherie.h" // подключение одноимённого заголовочного файла

using namespace std; // подключение пространства имён std

void Mutze() // вывод шапки 
{
	// выравнивание по левой стороне и вывод элементов шапки с соответствующей резервацией места в консоли 
	cout << setw(5) << setiosflags(ios::left) << "Инд."
		<< setw(26) << "Страна"
		<< setw(26) << "Столица"
		<< setw(15) << "Население(чел)"
		<< setw(15) << "Площадь(км^2)"
		<< setw(15) << "Плотность(N/S)"
		<< setw(3) << "Валюта";
	cout << endl << endl; // для эстетики 
}

void Prufung() // оповещение о некорректных данных 
{
	system("cls"); // очистка консоли 
	// непостредственно оповещение о некорректных данных
	cout << "Неверный ввод данных!\n"
		<< "Недопустимый символ \n"
		<< "   |(исп. для ввода латиницу и '_' - для пробела - или '-')\n"
		<< "   |(исп. для ответов 'y' или 'n')\n"
		<< "   |(исп. для пунктов меню числа)\n"
		<< "или превышение доспустимой длины!\n"
		<< "Попробуйте ещё раз.\n\n";
	system("pause"); // организация задержки 
}

void Wartung() // функция задержки 
{
	system("pause"); // организация задержки
	system("cls"); // очистка консоли 
}

void Schreiben(lander*& land , int i) // функция вывода i-того элемента массива структур 
{
	// выравнивание по левой стороне и вывод элементов массива с соответствующей резервацией места в консоли
	cout << setw(5) << setiosflags(ios::left) << land[i].index  
		<< setw(26) << land[i].Name  
		<< setw(26) << land[i].HauptStadt
		<< setw(15) << land[i].Nas
		<< setw(15) << land[i].Terr
		<< setw(15) << land[i].Nas_pro_Terr
		<< setw(3) << land[i].VAL << endl;
}

void KorrigierenDaten(char Zeitspanne[], int gang) // для коррекции введённых основных данных 
{
	if (gang == 1) // коррекция для названия страны и столицы
	{
		for (int i = 0; i < strlen(Zeitspanne); i++) 
		{
			Zeitspanne[i] = tolower(Zeitspanne[i]); // уменьшение регистора всей строки
			if ((Zeitspanne[i] == 95) || (Zeitspanne[i] == 45)) // сравнение по коду таблицы ASCII
				if (i + 1 < strlen(Zeitspanne)) // дополнительное условие
				{
					// увеличение регистора после знаков "_" и "-" 
					Zeitspanne[i + 1] = toupper(Zeitspanne[i + 1]);
					i = i + 2;
				}
		}
		Zeitspanne[0] = toupper(Zeitspanne[0]); // увеличение регистора первого символа
	}
	else if (gang == 2) // коррекция для кода валюты страны
		for (int i = 0; i < 3; i++)
			Zeitspanne[i] = toupper(Zeitspanne[i]); // увеличение регистора каждого символа 
}