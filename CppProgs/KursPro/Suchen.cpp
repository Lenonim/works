#include <iostream> // ��� ����� � ������
#include <conio.h> // ��� _getche()
#include "Peripherie.h" // ����������� 
#include "Suchen.h" // ����������� ����������� ������������� �����

using namespace std; // ����������� ������������ ��� std 

void SuchenDaten(lander*& land , int& Kapazitat) // ����� ������ 
{
	char laufgang = 'd'; // ��� ���� �� ���� 
	while (laufgang != '0')
	{
	Such:; // ������ 279
		// ������� ���������� 
		char Zeitspanne[64]; // �������� ����� - ������ �� ������������� ����� 
		int leuchtturm = 0; // ������ ��� ���������� ����������
		int metaint = 0; // ���������� ��� ��������� ������ 

		// ���� ������ ��� �������� 
		system("cls"); // ������� ������
		cout << "�� ������ ���� ����� ��������� �����?\n\n"
			<< "1 - �� �������\n"
			<< "2 - �� �������� ������\n"
			<< "3 - �� �������� �������\n"
			<< "4 - �� ����������� ���������\n"
			<< "5 - �� �������\n"
			<< "6 - �� ��������� ���������\n"
			<< "7 - �� ������\n"
			<< "0 - ����� � ����\n\n"
			<< "����� ����: ";
		laufgang = _getche(); // ����� ������ ���� 

		// ��� �� ���� 
		switch (laufgang)
		{

		case '1': // ����� �� ������� 

		Such_Ind:; // ������ 48
			metaint = 0; // ��������� ��� ����������� 
			system("cls"); // ������� ������� 
			cout << "������� ��������� ���������� �� ���� \"����� ����\": ";
			cin >> Zeitspanne;
			for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� ������� 
				if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
				{
					Prufung(); // ���������� � ������������ ����� 
					goto Such_Ind; // ������ 39
				}
			for (int i = 0; i < strlen(Zeitspanne); i++) // ����������� ���������� ���������
				metaint += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));
			for (int i = 0; i < Kapazitat; i++) // ������ ����������
				if (metaint == land[i].index) // ������� ����������
					leuchtturm++; // ���������� ���������� 
			if (leuchtturm == 0) // ���� ���������� ���
				cout << "\n����� �� �������!\n";
			else // ���� ���������� ����
			{
				cout << endl;
				Mutze(); // ����� ��������� �����
				for (int i = 0; i < Kapazitat; i++) // ����� ��������� �������
					if (metaint == land[i].index) // ������� ������
						Schreiben(land, i); // ����� i-��� ������
			}
			cout << endl;
			Wartung(); // ��������
			break;

		case '2': // ����� �� �������� ������

		Such_Name:; // ������ 78, 86
			system("cls"); // ������� �������
			cout << "������� ��������� ���������� �� ���� \"�������� ������\": ";
			cin >> Zeitspanne;
			if (strlen(Zeitspanne) > 25) // �������� �� ����� 
			{
				Prufung(); // ���������� � ������������ ����� 
				goto Such_Name; // ������ 71
			}
			for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� ������� 
				if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
					if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
						if ((Zeitspanne[i] != 95) && (Zeitspanne[i] != 45))
						{
							Prufung(); // ���������� � ������������ ����� 
							goto Such_Name; // ������ 71
						}
			KorrigierenDaten(Zeitspanne, 1); // ��������� �������� ������
			for (int i = 0; i < Kapazitat; i++) // ������ ����������
				if (strcmp(Zeitspanne, land[i].Name) == 0) // ������� ����������
					leuchtturm++; // ���������� ����������
			if (leuchtturm == 0) // ���� ���������� ���
				cout << "\n����� �� �������!\n";
			else // ���� ���������� ����
			{
				cout << endl;
				Mutze(); // ����� ��������� �����
				for (int i = 0; i < Kapazitat; i++) // ����� ��������� �������
					if (strcmp(Zeitspanne, land[i].Name) == 0) // ������� ������
						Schreiben(land, i); // ����� i-��� ������
			}
			cout << endl;
			Wartung(); // ��������
			break;

		case '3': // ����� �� �������� ������� 

		Such_HauptStadt:; // ������ 115, 123
			system("cls"); // ������� �������
			cout << "������� ��������� ���������� �� ���� \"�������� �������\": ";
			cin >> Zeitspanne;
			if (strlen(Zeitspanne) > 25) // �������� �� ����� 
			{
				Prufung(); // ���������� � ������������ ����� 
				goto Such_HauptStadt; // ������ 108
			}
			for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� ������� 
				if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
					if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
						if ((Zeitspanne[i] != 95) && (Zeitspanne[i] != 45))
						{
							Prufung(); // ���������� � ������������ ����� 
							goto Such_HauptStadt; // ������ 108
						}
			KorrigierenDaten(Zeitspanne, 1); // ��������� �������� ������
			for (int i = 0; i < Kapazitat; i++) // ������ ����������
				if (strcmp(Zeitspanne, land[i].HauptStadt) == 0) // ������� ����������
					leuchtturm++; // ���������� ����������
			if (leuchtturm == 0) // ���� ���������� ���
				cout << "\n����� �� �������!\n";
			else // ���� ���������� ����
			{
				cout << endl;
				Mutze(); // ����� ��������� �����
				for (int i = 0; i < Kapazitat; i++) // ����� ��������� �������
					if (strcmp(Zeitspanne, land[i].HauptStadt) == 0) // ������� ������
						Schreiben(land, i); // ����� i-��� ������
			}
			cout << endl;
			Wartung(); // ��������
			break;

		case '4': // ����� �� ����������� ��������� 

		Such_Nas:; // ������ 154
			metaint = 0; // ��������� ��� ����������� 
			system("cls"); // ������� �������
			cout << "������� ��������� ���������� �� ���� \"����� ����\": ";
			cin >> Zeitspanne;
			for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� ������� 
				if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
				{
					Prufung(); // ���������� � ������������ ����� 
					goto Such_Nas; // ������ 145
				}
			for (int i = 0; i < strlen(Zeitspanne); i++) // ����������� ���������� ���������
				metaint += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));
			for (int i = 0; i < Kapazitat; i++) // ������ ����������
				if (metaint == land[i].Nas) // ������� ����������
					leuchtturm++; // ���������� ����������
			if (leuchtturm == 0) // ���� ���������� ���
				cout << "\n����� �� �������!\n";
			else // ���� ���������� ����
			{ 
				cout << endl;
				Mutze(); // ����� ��������� �����
				for (int i = 0; i < Kapazitat; i++) // ����� ��������� �������
					if (metaint == land[i].Nas) // ������� ������
						Schreiben(land, i); // ����� i-��� ������
			}
			cout << endl;
			Wartung(); // ��������
			break;

		case '5': // ����� �� ������� 

		Such_Terr:; // ������ 186
			metaint = 0; // ��������� ��� ����������� 
			system("cls"); // ������� �������
			cout << "������� ��������� ���������� �� ���� \"����� ����\": ";
			cin >> Zeitspanne;
			for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� ������� 
				if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
				{
					Prufung(); // ���������� � ������������ ����� 
					goto Such_Terr; // ������ 177
				}
			for (int i = 0; i < strlen(Zeitspanne); i++) // ����������� ���������� ���������
				metaint += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));
			for (int i = 0; i < Kapazitat; i++) // ������ ����������
				if (metaint == land[i].Terr) // ������� ����������
					leuchtturm++; // ���������� ����������
			if (leuchtturm == 0) // ���� ���������� ���
				cout << "\n����� �� �������!\n";
			else // ���� ���������� ����
			{
				cout << endl;
				Mutze(); // ����� ��������� �����
				for (int i = 0; i < Kapazitat; i++) // ����� ��������� �������
					if (metaint == land[i].Terr) // ������� ������
						Schreiben(land, i); // ����� i-��� ������
			}
			cout << endl;
			Wartung(); // ��������
			break;

		case '6': // ����� �� ��������� ��������� 

		Such_Nas_pro_Terr:; // ������ 218
			metaint = 0; // ��������� ��� ����������� 
			system("cls"); // ������� �������
			cout << "������� ��������� ���������� �� ���� \"����� ����\": ";
			cin >> Zeitspanne;
			for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� ������� 
				if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
				{
					Prufung(); // ���������� � ������������ ����� 
					goto Such_Nas_pro_Terr; // ������ 208
				}
			for (int i = 0; i < strlen(Zeitspanne); i++) // ����������� ���������� ���������
				metaint += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));
			for (int i = 0; i < Kapazitat; i++) // ������ ����������
				if (metaint == land[i].Nas_pro_Terr) // ������� ����������
					leuchtturm++; // ���������� ����������
			if (leuchtturm == 0) // ���� ���������� ���
				cout << "\n����� �� �������!\n";
			else // ���� ���������� ����
			{
				cout << endl;
				Mutze(); // ����� ��������� �����
				for (int i = 0; i < Kapazitat; i++) // ����� ��������� �������
					if (metaint == land[i].Nas_pro_Terr) // ������� ������
						Schreiben(land, i); // ����� i-��� ������
			}
			cout << endl;
			Wartung(); // ��������
			break;

		case '7': // ����� �� ���� ������ 

		Such_VAL:; // ������ 248, 255
			system("cls"); // ������� �������
			cout << "������� ��������� ���������� �� ���� \"��� ������\": ";
			cin >> Zeitspanne;
			if (strlen(Zeitspanne) != 3) // �������� �� ����� 
			{
				Prufung(); // ���������� � ������������ ����� 
				goto Such_VAL; // ������ 241
			}
			for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� ������� 
				if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
					if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
					{
						Prufung(); // ���������� � ������������ ����� 
						goto Such_VAL; // ������ 241
					}
			KorrigierenDaten(Zeitspanne, 2); // ��������� �������� ������
			for (int i = 0; i < Kapazitat; i++) // ������ ����������
				if (strcmp(Zeitspanne, land[i].VAL) == 0) // ������� ����������
					leuchtturm++; // ���������� ����������
			if (leuchtturm == 0) // ���� ���������� ���
				cout << "\n����� �� �������!\n";
			else // ���� ���������� ����
			{
				cout << endl;
				Mutze(); // ����� ��������� �����
				for (int i = 0; i < Kapazitat; i++) // ����� ��������� �������
					if (strcmp(Zeitspanne, land[i].VAL) == 0) // ������� ������
						Schreiben(land, i); // ����� i-��� ������
			}
			cout << endl;
			Wartung(); // ��������
			break;

		case '0': break; // ��� ������

		default: // �������� ����� 
			Prufung(); // ���������� � ������������ �����
			goto Such; // ������ 13
		}
	}
}

int SuchenFurSubstragierung(lander*& land, int& Kapazitat) // ����� ��� �������� 
{
Such_Fur_Sub_Hauptablauf:; // ������ 852
	// ������� ���������� 
	char laufgang; // ��� �� ����
	char Zeitspanne[64]; // �������� ����� - ������ �� ������������� ����� 
	char TeilDel[64]; // �������� ����� - ������ ��� �������� �������
	char Antwort; // ���������� ������
	int leuchtturm = 0; // ������ ��� �������� ���������� 
	int metaint = 0; // ��� ���������
	int metaindex = 0; // ��� ������� ������� �������� 

	// ���� ������ ��� �������� 
	system("cls"); // ������� ������ 
	cout << "�� ������ ���� ����� ��������� ����� ��� ��������?\n\n"
		<< "1 - �� �������� ������\n"
		<< "2 - �� �������� �������\n"
		<< "3 - �� ����������� ���������\n"
		<< "4 - �� �������\n"
		<< "5 - �� ��������� ���������\n"
		<< "6 - �� ���� ������\n"
		<< "0 - ����� �� ������\n\n"
		<< "����� ����: ";
	laufgang = _getche(); // ���� ������ ����

	if (laufgang == 0) return 0; // ����� � ������� ����-�������

	// ��� �� ����
	switch (laufgang)
	{
	case '1': // ����� �� �������� ������

	Such_Fur_Sub_Anfang_Name:; // ������ 323, 321
		system("cls"); // ������� �������
		cout << "������� ��������� ���������� �� ���� \"�������� ������\": ";
		cin >> Zeitspanne;
		if (strlen(Zeitspanne) > 25) // �������� �� ����� 
		{
			Prufung(); // ���������� � ������������ ����� 
			goto Such_Fur_Sub_Anfang_Name; // ������ 316
		}
		for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� ������� 
			if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
				if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
					if ((Zeitspanne[i] != 95) && (Zeitspanne[i] != 45))
					{
						Prufung(); // ���������� � ������������ ����� 
						goto Such_Fur_Sub_Anfang_Name; // ������ 316
					}
		KorrigierenDaten(Zeitspanne, 1); // ��������� �������� ������

		// ������ � ������ ���������� 
		for (int i = 0; i < Kapazitat; i++)
			if (strcmp(Zeitspanne, land[i].Name) == 0) // ��������� � ��������������� ������� 
				leuchtturm++; // ���������� ������ ���������� 
		if (leuchtturm == 0) // ���� ���������� ��� 
		{
			cout << "\n����� �� �������!\n\n"; // ���������� � ����������� ������
			Wartung(); // ��������
			return 0; // ������� ����-�������
		}
		else if (leuchtturm == 1) // ���� ���������� ���� 
		{
			cout << endl;
		Such_Fur_Sub_EinLT_Name:; // ������ 362
			Mutze(); // ����� ��������� �����
			for (int i = 0; i < Kapazitat; i++)
				if (strcmp(Zeitspanne, land[i].Name) == 0) // ���������� ������ ��������� 
				{
					Schreiben(land, i); // ����� c����� ����������
					metaindex = land[i].index; // ����������� �������
				}
			cout << "\n������� ��� ������? (y ��� n): "; //������ �� �������� ������
			Antwort = _getche(); // ����� 
			if ((Antwort != 'y') && (Antwort != 'n')) // �������� �����
			{
				Prufung(); // ���������� � ������������ ����� 
				system("cls"); // ������� �������
				goto Such_Fur_Sub_EinLT_Name; // ������ 348
			}
			else if (Antwort == 'y') // ���� ����� ������������� 
				return metaindex; // ���������� ������� ������
			else if (Antwort == 'n') // ���� ����� ������������� 
				return 0; // ���������� ����-������
		}
		else if (leuchtturm > 1) // ���� ���������� ��������� 
		{
			cout << endl;
		Such_Fur_Sub_VielLT_Name:;  // ������ 384, 397
			Mutze(); // ����� ����� 
			for (int i = 0; i < Kapazitat; i++) // ����� ��������� ������� 
				if (strcmp(Zeitspanne, land[i].Name) == 0)
					Schreiben(land, i); // ����� c����� ����������
			cout << "\n������� ������ ������, ������� ���������� ������� (0 - �������): "; // ������ �� ��������
			cin >> TeilDel;
			for (int i = 0; i < strlen(TeilDel); i++) // �������� �� ������� 
				if ((TeilDel[i] < 48) || (TeilDel[i] > 57))
				{
					Prufung(); // ���������� � ������������ ����� 
					system("cls"); // ������� �������
					goto Such_Fur_Sub_VielLT_Name; // ������ 372
				}
			if ((strlen(TeilDel) == 1) && (TeilDel[0] == 48)) return 0; // ����� � ���� �������� 
			for (int i = 0; i < strlen(TeilDel); i++) // ����������� �������� ������  
				metaindex += ((TeilDel[i] - 48) * pow(10, (strlen(TeilDel) - 1 - i)));
			leuchtturm = 0; // ��������� ������ ���������� 
			for (int i = 0; i < Kapazitat; i++) // ������� ���������� 
				if (strcmp(Zeitspanne, land[i].Name) == 0)
					leuchtturm++; // ���������� ������ ����������
			if (leuchtturm == 0) // ���� ���������� ��� 
			{
				Prufung(); // ���������� � ������������ ����� 
				system("cls"); // ������� �������
				goto Such_Fur_Sub_VielLT_Name; // ������ 372
			}
			else // ���� ���������� ����  
				for (int i = 0; i < Kapazitat; i++)
					if (metaindex == land[i].index)
						return metaindex; // ������� �������� ������� 
		}

	case '2': // ����� �� �������� �������

	Such_Fur_Sub_Anfang_Hauptstadt:; // ������ 414, 422
		system("cls"); // ������� �������
		cout << "������� ��������� ���������� �� ���� \"�������� �������\": ";
		cin >> Zeitspanne;
		if (strlen(Zeitspanne) > 25) // �������� �� ����� 
		{
			Prufung(); // ���������� � ������������ ����� 
			goto Such_Fur_Sub_Anfang_Hauptstadt; // ����� 407
		}
		for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� ������� 
			if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
				if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
					if ((Zeitspanne[i] != 95) && (Zeitspanne[i] != 45))
					{
						Prufung(); // ���������� � ������������ ����� 
						goto Such_Fur_Sub_Anfang_Hauptstadt; // ����� 407
					}
		KorrigierenDaten(Zeitspanne, 1); // ��������� �������� ������

		// ������ � ������ ���������� 
		for (int i = 0; i < Kapazitat; i++)
			if (strcmp(Zeitspanne, land[i].HauptStadt) == 0) // ��������� � ��������������� ������� 
				leuchtturm++; // ���������� ������ ���������� 
		if (leuchtturm == 0) // ���� ���������� ��� 
		{
			cout << "\n����� �� �������!\n\n"; // ���������� � ����������� ������
			Wartung(); // ��������
			return 0; // ������� ����-�������
		}
		else if (leuchtturm == 1) // ���� ���������� ���� 
		{
			cout << endl;
		Such_Fur_Sub_EinLT_Hauptstadt:; // ������ 453
			Mutze(); // ����� ��������� �����
			for (int i = 0; i < Kapazitat; i++)
				if (strcmp(Zeitspanne, land[i].HauptStadt) == 0) // ���������� ������ ��������� 
				{
					Schreiben(land, i); // ����� c����� ����������
					metaindex = land[i].index; // ����������� �������
				}
			cout << "\n������� ��� ������? (y ��� n): "; //������ �� �������� ������
			Antwort = _getche(); // ����� 
			if ((Antwort != 'y') && (Antwort != 'n')) // �������� �����
			{
				Prufung(); // ���������� � ������������ ����� 
				system("cls"); // ������� �������
				goto Such_Fur_Sub_EinLT_Hauptstadt; // ������ 439
			}
			else if (Antwort == 'y') // ���� ����� ������������� 
				return metaindex; // ���������� ������� ������
			else if (Antwort == 'n') // ���� ����� ������������� 
				return 0; // ���������� ����-������
		}
		else if (leuchtturm > 1) // ���� ���������� ��������� 
		{
			cout << endl;
		Such_Fur_Sub_VielLT_Hauptstadt:; // ������ 475, 488
			Mutze(); // ����� ����� 
			for (int i = 0; i < Kapazitat; i++) // ����� ��������� ������� 
				if (strcmp(Zeitspanne, land[i].HauptStadt) == 0)
					Schreiben(land, i); // ����� c����� ����������
			cout << "\n������� ������ ������, ������� ���������� ������� (0 - �������): "; // ������ �� ��������
			cin >> TeilDel;
			for (int i = 0; i < strlen(TeilDel); i++) // �������� �� ������� 
				if ((TeilDel[i] < 48) || (TeilDel[i] > 57))
				{
					Prufung(); // ���������� � ������������ �����
					system("cls"); // ������� �������
					goto Such_Fur_Sub_VielLT_Hauptstadt; // ������ 463
				}
			if ((strlen(TeilDel) == 1) && (TeilDel[0] == 48)) return 0; // ����� � ���� �������� 
			for (int i = 0; i < strlen(TeilDel); i++) // ����������� �������� ������  
				metaindex += ((TeilDel[i] - 48) * pow(10, (strlen(TeilDel) - 1 - i)));
			leuchtturm = 0; // ��������� ������ ���������� 
			for (int i = 0; i < Kapazitat; i++) // ������� ���������� 
				if (strcmp(Zeitspanne, land[i].HauptStadt) == 0)
					leuchtturm++;
			if (leuchtturm == 0) // ���� ���������� ��� 
			{
				Prufung(); // ���������� � ������������ ����� 
				system("cls"); // ������� �������
				goto Such_Fur_Sub_VielLT_Hauptstadt; // ������ 463
			}
			else
				for (int i = 0; i < Kapazitat; i++)
					if (metaindex == land[i].index)
						return metaindex; // ������� �������� ������� 
		}

	case '3': // ����� �� ����������� ���������

	Such_Fur_Sub_Anfang_Nas:; // ������ 511
		system("cls"); // ������� ������� 
		cout << "������� ��������� ���������� �� ���� \"����������� ���������\": ";
		cin >> Zeitspanne; 
		if (strlen(Zeitspanne) > 10) // �������� �� ����� 
		{
			Prufung(); // ���������� � ������������ ����� 
			goto Such_Fur_Sub_Anfang_Nas;
		}
		for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� �������
			if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
			{
				Prufung(); // ���������� � ������������ ����� 
				goto Such_Fur_Sub_Anfang_Nas; // ������ 496
			}
		for (int i = 0; i < strlen(Zeitspanne); i++) // ����������� ��������� ����� ���������
			metaint += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));
		for (int i = 0; i < Kapazitat; i++)
			if (metaint == land[i].Nas) // ������� ���������� ����� ���������� 
				leuchtturm++;  // ���������� ������ ���������� 
		if (leuchtturm == 0) // ���� ���������� ��� 
		{
			cout << "\n����� �� �������!\n\n"; // ���������, ��� ������ �� ������� 
			Wartung(); // ��������
			return 0; // ������� ����-������� 
		}
		else if (leuchtturm == 1) // ���� ���� ���������� 
		{
			cout << endl;
		Such_Fur_Sub_EinLT_Nas:; // ������ 541
			Mutze(); // ����� ��������� ����� 
			for (int i = 0; i < Kapazitat; i++) 
				if (metaint == land[i].Nas) // ������� ������ 
				{
					Schreiben(land, i); // ����� c����� ����������
					metaindex = land[i].index; // ��������� �������� ������� 
				}
			cout << "\n������� ��� ������? (y ��� n): "; // ������ �� ��������
			Antwort = _getche(); // ����� 
			if ((Antwort != 'y') && (Antwort != 'n')) // �������� ����� 
			{
				Prufung(); // ���������� � ������������ �����
				system("cls"); // ������� �������
				goto Such_Fur_Sub_EinLT_Nas; // ������ 527
			}
			else if (Antwort == 'y') // ���� ����� ������������� 
				return metaindex; // ���������� ������� ������
			else if (Antwort == 'n') // ���� ����� ������������� 
				return 0; // ���������� ����-������
		}
		else if (leuchtturm > 1) // ���� ���������� ��������� 
		{
			cout << endl;
		Such_Fur_Sub_VielLT_Nas:; // ������ 563, 576
			Mutze(); // ����� ����� 
			for (int i = 0; i < Kapazitat; i++) // ����� ��������� ������� 
				if (metaint == land[i].Nas) // ������� ������ 
					Schreiben(land, i); // ����� c����� ����������
			cout << "\n������� ������ ������, ������� ���������� ������� (0 - �������): "; // ������ �� ��������
			cin >> TeilDel; 
			for (int i = 0; i < strlen(TeilDel); i++) // �������� �� ������� 
				if ((TeilDel[i] < 48) || (TeilDel[i] > 57))
				{
					Prufung(); // ���������� � ������������ ����� 
					system("cls"); // ������� �������
					goto Such_Fur_Sub_VielLT_Nas; // ������ 551
				}
			if ((strlen(TeilDel) == 1) && (TeilDel[0] == 48)) return 0; // ����� � ���� �������� 
			for (int i = 0; i < strlen(TeilDel); i++) // ����������� �������� ������  
				metaindex += ((TeilDel[i] - 48) * pow(10, (strlen(TeilDel) - 1 - i)));
			leuchtturm = 0; // ��������� ������ ���������� 
			for (int i = 0; i < Kapazitat; i++) // ������� ���������� 
				if (metaint == land[i].Nas) // ������� ���������� ����� ���������� 
					leuchtturm++;
			if (leuchtturm == 0) // ���� ���������� ��� 
			{
				Prufung(); // ���������� � ������������ ����� 
				system("cls"); // ������� �������
				goto Such_Fur_Sub_VielLT_Nas; // ������ 551
			}
			else
				for (int i = 0; i < Kapazitat; i++)
					if (metaindex == land[i].index)
						return metaindex; // ������� �������� ������� 
		}

	case '4': // ����� �� ������� 

	Such_Fur_Sub_Anfang_Terr:; // ������ 593
		system("cls"); // ������� ������� 
		cout << "������� ��������� ���������� �� ���� \"�������\": ";
		cin >> Zeitspanne;
		if (strlen(Zeitspanne) > 9) // �������� �� ����� 
		{
			Prufung(); // ���������� � ������������ ����� 
			goto Such_Fur_Sub_Anfang_Terr; // ������ 586
		}
		for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� �������
			if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
			{
				Prufung(); // ���������� � ������������ ����� 
				goto Such_Fur_Sub_Anfang_Terr; // ������ 586
			}
		for (int i = 0; i < strlen(Zeitspanne); i++) // ����������� ���������� ����� ��������� 
			metaint += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));
		for (int i = 0; i < Kapazitat; i++)
			if (metaint == land[i].Terr) // ������� ���������� ����� ���������� 
				leuchtturm++;  // ���������� ������ ���������� 
		if (leuchtturm == 0) // ���� ���������� ��� 
		{
			cout << "\n����� �� �������!\n\n"; // ���������, ��� ������ �� ������� 
			Wartung(); // ��������
			return 0; // ������� ����-������� 
		}
		else if (leuchtturm == 1) // ���� ���� ���������� 
		{
			cout << endl;
		Such_Fur_Sub_EinLT_Terr:; // ������ 629
			Mutze(); // ����� ����� 
			for (int i = 0; i < Kapazitat; i++)
				if (metaint == land[i].Terr) // ������� ������ 
				{
					Schreiben(land, i); // ����� c����� ����������
					metaindex = land[i].index; // ��������� �������� ������� 
				}
			cout << "\n������� ��� ������? (y ��� n): "; // ������ �� ��������
			Antwort = _getche(); // ����� 
			if ((Antwort != 'y') && (Antwort != 'n')) // �������� ����� 
			{
				Prufung(); // ���������� � ������������ �����
				system("cls"); // ������� �������
				goto Such_Fur_Sub_EinLT_Terr; // ������ 615
			}
			else if (Antwort == 'y') // ���� ����� ������������� 
				return metaindex; // ���������� ������� ������
			else if (Antwort == 'n') // ���� ����� ������������� 
				return 0; // ���������� ����-������
		}
		else if (leuchtturm > 1) // ���� ���������� ��������� 
		{
			cout << endl;
		Such_Fur_Sub_VielLT_Terr:; // ������ 651, 664
			Mutze(); // ����� �����  
			for (int i = 0; i < Kapazitat; i++) // ����� ��������� ������� 
				if (metaint == land[i].Terr) // ������� ������ 
					Schreiben(land, i); // ����� c����� ����������
			cout << "\n������� ������ ������, ������� ���������� ������� (0 - �������): "; // ������ �� ��������
			cin >> TeilDel;
			for (int i = 0; i < strlen(TeilDel); i++) // �������� �� ������� 
				if ((TeilDel[i] < 48) || (TeilDel[i] > 57))
				{
					Prufung(); // ���������� � ������������ ����� 
					system("cls"); // ������� �������
					goto Such_Fur_Sub_VielLT_Terr; // ������ 664
				}
			if ((strlen(TeilDel) == 1) && (TeilDel[0] == 48)) return 0; // ����� � ���� �������� 
			for (int i = 0; i < strlen(TeilDel); i++) // ����������� �������� ������  
				metaindex += ((TeilDel[i] - 48) * pow(10, (strlen(TeilDel) - 1 - i)));
			leuchtturm = 0; // ��������� ������ ���������� 
			for (int i = 0; i < Kapazitat; i++) // ������� ���������� 
				if (metaint == land[i].Terr) // ������� ���������� ����� ���������� 
					leuchtturm++;
			if (leuchtturm == 0) // ���� ���������� ��� 
			{
				Prufung(); // ���������� � ������������ ����� 
				system("cls"); // ������� �������
				goto Such_Fur_Sub_VielLT_Terr; // ������ 664
			}
			else
				for (int i = 0; i < Kapazitat; i++)
					if (metaindex == land[i].index)
						return metaindex; // ������� �������� ������� 
		}

	case '5':

	Such_Fur_Sub_Anfang_Nas_pro_Terr:; // ������ 681, 687
		system("cls"); // ������� ������� 
		cout << "������� ��������� ���������� �� ���� \"��������� ���������\": ";
		cin >> Zeitspanne; 
		if (strlen(Zeitspanne) > 8) // �������� �� ����� 
		{
			Prufung(); // ���������� � ������������ ����� 
			goto Such_Fur_Sub_Anfang_Nas_pro_Terr; // ������ 674
		}
		for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� �������
			if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
			{
				Prufung(); // ���������� � ������������ ����� 
				goto Such_Fur_Sub_Anfang_Nas_pro_Terr; // ������ 674
			}
		for (int i = 0; i < strlen(Zeitspanne); i++) // ����������� ��������� ����� ���������
			metaint += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));
		for (int i = 0; i < Kapazitat; i++)
			if (metaint == land[i].Nas_pro_Terr) // ������� ���������� ����� ���������� 
				leuchtturm++;  // ���������� ������ ���������� 
		if (leuchtturm == 0) // ���� ���������� ��� 
		{
			cout << "\n����� �� �������!\n\n"; // ���������, ��� ������ �� ������� 
			Wartung(); // ��������
			return 0; // ������� ����-������� 
		}
		else if (leuchtturm == 1) // ���� ���� ���������� 
		{
			cout << endl;
		Such_Fur_Sub_EinLT_Nas_pro_Terr:; // ������ 717
			Mutze(); // ����� ��������� ����� 
			for (int i = 0; i < Kapazitat; i++)
				if (metaint == land[i].Nas_pro_Terr) // ������� ������ 
				{
					Schreiben(land, i); // ����� c����� ����������
					metaindex = land[i].index; // ��������� �������� ������� 
				}
			cout << "\n������� ��� ������? (y ��� n): "; // ������ �� ��������
			Antwort = _getche(); // ����� 
			if ((Antwort != 'y') && (Antwort != 'n')) // �������� ����� 
			{
				Prufung(); // ���������� � ������������ ����� 
				system("cls"); // ������� �������
				goto Such_Fur_Sub_EinLT_Nas_pro_Terr; // ������ 703
			}
			else if (Antwort == 'y') // ���� ����� ������������� 
				return metaindex; // ���������� ������� ������
			else if (Antwort == 'n') // ���� ����� ������������� 
				return 0; // ���������� ����-������
		}
		else if (leuchtturm > 1) // ���� ���������� ��������� 
		{
			cout << endl;
		Such_Fur_Sub_VielLT_Nas_pro_Terr:; // ������ 739, 752
			Mutze(); // ����� ����� 
			for (int i = 0; i < Kapazitat; i++) // ����� ��������� ������� 
				if (metaint == land[i].Nas_pro_Terr) // ������� ������ 
					Schreiben(land, i); // ����� c����� ����������
			cout << "\n������� ������ ������, ������� ���������� ������� (0 - �������): "; // ������ �� ��������
			cin >> TeilDel;
			for (int i = 0; i < strlen(TeilDel); i++) // �������� �� ������� 
				if ((TeilDel[i] < 48) || (TeilDel[i] > 57))
				{
					Prufung(); // ���������� � ������������ ����� 
					system("cls"); // ������� �������
					goto Such_Fur_Sub_VielLT_Nas_pro_Terr; // ������ 727
				}
			if ((strlen(TeilDel) == 1) && (TeilDel[0] == 48)) return 0; // ����� � ���� �������� 
			for (int i = 0; i < strlen(TeilDel); i++) // ����������� �������� ������  
				metaindex += ((TeilDel[i] - 48) * pow(10, (strlen(TeilDel) - 1 - i)));
			leuchtturm = 0; // ��������� ������ ���������� 
			for (int i = 0; i < Kapazitat; i++) // ������� ���������� 
				if (metaint == land[i].Nas_pro_Terr) // ������� ���������� ����� ���������� 
					leuchtturm++; // ���������� ������ ���������� 
			if (leuchtturm == 0) // ���� ���������� ��� 
			{
				Prufung(); // ���������� � ������������ ����� 
				system("cls"); // ������� �������
				goto Such_Fur_Sub_VielLT_Nas_pro_Terr; // ������ 727
			}
			else
				for (int i = 0; i < Kapazitat; i++)
					if (metaindex == land[i].index)
						return metaindex; // ������� �������� ������� 
		}

	case '6': // ����� �� ���� ������ 

	Such_Fur_Sub_Anfang_VAL:; // ������ 769, 776
		system("cls"); // ������� �������
		cout << "������� ��������� ���������� �� ���� \"���� ������\": ";
		cin >> Zeitspanne;
		if (strlen(Zeitspanne) != 3) // �������� �� ����� 
		{
			Prufung(); // ���������� � ������������ ����� 
			goto Such_Fur_Sub_Anfang_VAL; // ������ 762
		}
		for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� ������� 
			if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
				if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
				{
					Prufung(); // ���������� � ������������ ����� 
					goto Such_Fur_Sub_Anfang_VAL; // ������ 762
				}
		KorrigierenDaten(Zeitspanne, 2); // ��������� �������� ������

		// ������ � ������ ���������� 
		for (int i = 0; i < Kapazitat; i++)
			if (strcmp(Zeitspanne, land[i].VAL) == 0) // ��������� � ��������������� ������� 
				leuchtturm++; // ���������� ������ ���������� 
		if (leuchtturm == 0) // ���� ���������� ��� 
		{
			cout << "\n����� �� �������!\n\n"; // ���������� � ����������� ������
			Wartung(); // ��������
			return 0; // ������� ����-�������
		}
		else if (leuchtturm == 1) // ���� ���������� ���� 
		{
			cout << endl;
		Such_Fur_Sub_EinLT_VAL:; // ������ 807
			Mutze(); // ����� ��������� �����
			for (int i = 0; i < Kapazitat; i++)
				if (strcmp(Zeitspanne, land[i].HauptStadt) == 0) // ���������� ������ ��������� 
				{
					Schreiben(land, i); // ����� c����� ����������
					metaindex = land[i].index; // ����������� �������
				}
			cout << "\n������� ��� ������? (y ��� n): "; //������ �� �������� ������
			Antwort = _getche(); // ����� 
			if ((Antwort != 'y') && (Antwort != 'n')) // �������� �����
			{
				Prufung(); // ���������� � ������������ ����� 
				system("cls"); // ������� �������
				goto Such_Fur_Sub_EinLT_VAL; // ������ 793
			}
			else if (Antwort == 'y') // ���� ����� ������������� 
				return metaindex; // ���������� ������� ������
			else if (Antwort == 'n') // ���� ����� ������������� 
				return 0; // ���������� ����-������
		}
		else if (leuchtturm > 1) // ���� ���������� ��������� 
		{
			cout << endl;
		Such_Fur_Sub_VielLT_VAL:; // ������ 829, 842
			Mutze(); // ����� ����� 
			for (int i = 0; i < Kapazitat; i++) // ����� ��������� ������� 
				if (strcmp(Zeitspanne, land[i].VAL) == 0)
					Schreiben(land, i); // ����� c����� ����������
			cout << "\n������� ������ ������, ������� ���������� ������� (0 - �������): "; // ������ �� ��������
			cin >> TeilDel;
			for (int i = 0; i < strlen(TeilDel); i++) // �������� �� ������� 
				if ((TeilDel[i] < 48) || (TeilDel[i] > 57))
				{
					Prufung(); // ���������� � ������������ ����� 
					system("cls"); // ������� �������
					goto Such_Fur_Sub_VielLT_VAL; // ������ 817
				}
			if ((strlen(TeilDel) == 1) && (TeilDel[0] == 48)) return 0; // ����� � ���� �������� 
			for (int i = 0; i < strlen(TeilDel); i++) // ����������� �������� ������  
				metaindex += ((TeilDel[i] - 48) * pow(10, (strlen(TeilDel) - 1 - i)));
			leuchtturm = 0; // ��������� ������ ���������� 
			for (int i = 0; i < Kapazitat; i++) // ������� ���������� 
				if (strcmp(Zeitspanne, land[i].VAL) == 0)
					leuchtturm++; // ���������� ������ ����������
			if (leuchtturm == 0) // ���� ���������� ��� 
			{
				Prufung(); // ���������� � ������������ ����� 
				system("cls"); // ������� �������
				goto Such_Fur_Sub_VielLT_VAL; // ������ 817
			}
			else
				for (int i = 0; i < Kapazitat; i++)
					if (metaindex == land[i].index)
						return metaindex; // ������� �������� ������� 
		}

	default: // �������� ��������������� ������ ���� 
		Prufung(); // ���������� � ������������ �����
		goto Such_Fur_Sub_Hauptablauf; // ������ 286
	}
}