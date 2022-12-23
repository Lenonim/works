#include <iostream> // ��� ����� � ������
#include <conio.h> // ��� _getche()
#include <stdio.h> // ��� ������ � �������
#include <fstream> // ��� ������ � �������
#include <iomanip> // ��� setw()
#include <cmath> // ��� pow()
#include "Dynamik.h" // ����������� ����������� ������������� �����
#include "Peripherie.h" // ����������� ���� ����� ���������
#include "Suchen.h" // ����������� ���� ����� ������
#include "Sortierung.h" // ����������� ���� ����� ���������� 

using namespace std; // ����������� ������������ ��� std

string DerNameDesTextes = "BinLender.txt"; // ���������� ��� ����� 

void LesenDaten(lander*& land, int& Kapazitat)
{
	ifstream wanderung; // ���������� ��� ������ �����

	// �������� ����� ��� ������ � ���//
	wanderung.open(DerNameDesTextes, ios::binary | ios::out);

	// �������� �������� ����� 
	while (!wanderung.is_open()) // ���� �� ��������� ����� ����� 
	{
		// ���������� � ���������� �����
		cout << "���� �� ������, ������� ��� ����� �������: ";
		cin >> DerNameDesTextes; // ���� ������� ����� ����� �������
		wanderung.open(DerNameDesTextes); // �������� ����� � ������� ������ 
		system("cls"); // ������� �������, ����� � �� ������������ 
	}
	
	Kapazitat = 0;
	wanderung.read((char*)&Kapazitat, sizeof(Kapazitat));
	if (Kapazitat != 0)
	{
		VeranderungZahlDaten(land, Kapazitat, 0);
		for (int i = 0; i < Kapazitat; i++) // ������� ���������� ������
			wanderung.read((char*)&land[i], sizeof(land[i]));
		wanderung.close(); // �������� ����� ����� ������ 
	}
	else
	{
		Kapazitat++; // ���������� ����������� ������� �� ������ �������
		VeranderungZahlDaten(land, Kapazitat, 0);
	ErsteSchrei:; 
		cout << "��������, ������ �����������! �������� ������ ������:\n\n";
		char Zeitspanne[64];
		// �����������
		land[0].index = 1;
		// ���� �������� ������ 
		cout << "������� �������� ������: ";
		cin >> Zeitspanne;
		if (strlen(Zeitspanne) > 25) // �������� �� �����
		{
			Prufung(); // ���������� � ������������ ����� 
			goto ErsteSchrei; 
		}
		for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� �������
			if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
				if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
					if ((Zeitspanne[i] != 95) && (Zeitspanne[i] != 45))
					{
						Prufung(); // ���������� � ������������ ����� 
						goto ErsteSchrei; 
					}
		KorrigierenDaten(Zeitspanne, 1); // ��������� �������� ������
		strcpy_s(land[0].Name, Zeitspanne); // ����������� �������� ������ 

		// ���� �������� �������
		cout << "������� �������� �������: ";
		cin >> Zeitspanne;
		if (strlen(Zeitspanne) > 25) // �������� �� �����
		{
			Prufung(); // ���������� � ������������ ����� 
			goto ErsteSchrei;
		}
		for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� ������� 
			if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
				if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
					if ((Zeitspanne[i] != 95) && (Zeitspanne[i] != 45))
					{
						Prufung(); // ���������� � ������������ ����� 
						goto ErsteSchrei; 
					}
		KorrigierenDaten(Zeitspanne, 1); // ��������� �������� ������
		strcpy_s(land[0].HauptStadt, Zeitspanne); // ����������� �������� �������

		// ���� ����������� ��������� 
		cout << "������� ����������� ���������: ";
		cin >> Zeitspanne;
		if (strlen(Zeitspanne) > 9) // �������� �� �����
		{
			Prufung(); // ���������� � ������������ ����� 
			goto ErsteSchrei; 
		}
		for (int j = 0; j < strlen(Zeitspanne); j++) // �������� �� �������
			if ((static_cast<int>(Zeitspanne[j]) - 48 < 0) || (static_cast<int>(Zeitspanne[j]) - 48 > 9))
			{
				Prufung(); // ���������� � ������������ ����� 
				goto ErsteSchrei; 
			}
		land[0].Nas = 0; // ��������� ��� �����������
		for (int j = 0; j < strlen(Zeitspanne); j++) // ����������� ����������� ��������� 
			land[0].Nas += (((static_cast<int>(Zeitspanne[j])) - 48) * pow(10, (strlen(Zeitspanne) - 1 - j)));

		// ���� �������
		cout << "������� �������: ";
		cin >> Zeitspanne;
		if (strlen(Zeitspanne) > 9) // �������� �� �����
		{
			Prufung(); // ���������� � ������������ ����� 
			goto ErsteSchrei; 
		}
		for (int j = 0; j < strlen(Zeitspanne); j++) // �������� �� �������
			if ((static_cast<int>(Zeitspanne[j]) - 48 < 0) || (static_cast<int>(Zeitspanne[j]) - 48 > 9))
			{
				Prufung(); // ���������� � ������������ ����� 
				goto ErsteSchrei; 
			}
		land[0].Terr = 0; // ��������� ��� ����������� 
		for (int j = 0; j < strlen(Zeitspanne); j++) // ����������� �������
			land[0].Terr += (((static_cast<int>(Zeitspanne[j])) - 48) * pow(10, (strlen(Zeitspanne) - 1 - j)));
		if (land[0].Terr == 0) // �������������� ������� �� 0
		{
			Prufung(); // ���������� � ������������ ����� 
			goto ErsteSchrei; 
		}

		// ���� ���� ������ ������ 
		cout << "�������� ��� ������ ������: ";
		cin >> Zeitspanne;
		if (strlen(Zeitspanne) != 3) // �������� �� �����
		{
			Prufung(); // ���������� � ������������ ����� 
			goto ErsteSchrei; 
		}
		for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� ������� 
			if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
				if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
				{
					Prufung(); // ���������� � ������������ ����� 
					goto ErsteSchrei; 
				}
		KorrigierenDaten(Zeitspanne, 2); // ��������� �������� ������
		strcpy_s(land[0].VAL, Zeitspanne); // ����������� ������ ������

		// ������� ��������� ��������� 
		land[0].Nas_pro_Terr = land[0].Nas / land[0].Terr;
		// ���������� ��������� �����
		SpeichernDatenInBinFile(land, Kapazitat);
	}
	// ��������� ��������-�������� ������
	SortierungNachVeranderungen(land, Kapazitat); // ������� ��������� ��������-�������� ������ (Sortierung.cpp)
}

void AddierenDaten(lander*& land, int& Kapazitat) 
{
gt_index:; 
	// ������� ����������
	int metaindex = 0; // ��� ������ �������, ����� �������� ���� ����� �������� ������
	char Zeitspanne[64]; // �������� ����� - ������ �� ������������ ������
	int x = 0; // ��� ������� ���������� ����� ������� 

	// ����� ������� ������ 
	system("cls"); // ������� ������� 
	cout << "������ �������: \n\n";
	Mutze(); // ����� �����
	for (int i = 0; i < Kapazitat; i++) // ����� ����� ������ ����� ������������ ������� 
		Schreiben(land, i);

	// ���� ������ ������
	cout << "\n������� ����� ������, ����� ������� ���������� �������� ����������: ";
	cin >> Zeitspanne; // ���� ��������� ������ 
	for (int i = 0; i < strlen(Zeitspanne); i++) // ������� �����, ��� �������������� � �����
		if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
		{
			Prufung(); // ���������� � ������������ �����                                             
			goto gt_index;                                                                
		}
	for (int i = 0; i < strlen(Zeitspanne); i++) // ��������� �������, ����� �������� ����� ��������� ������.
		metaindex += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));

	// �������� ���������� ������� 
	int leuchtturm = 0; // ������ ��� �������� ��������
	for (int i = 0; i < Kapazitat; i++) // �������� ������������� ��������� ������� 
		if (land[i].index == metaindex)
			leuchtturm++;
	if (leuchtturm == 0)
	{
		Prufung();
		goto gt_index;  
	}

	// ���� ���������� ����� ������� 
	cout << "\n������� ������� �� ������ �������� �������? : ";
	cin >> Zeitspanne;
	for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� ������� 
		if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
		{
			Prufung(); // ���������� � ������������ �����
			goto gt_index; 
		}
	for (int i = 0; i < strlen(Zeitspanne); i++) // ��������� ���������� ����� ������� 
		x += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));

	// ���������� ������������� �������
	VeranderungZahlDaten(land, Kapazitat, x);
	cout << endl;

	// ���� ����� ������
	if (metaindex == Kapazitat) // ���� ������� ���=���� ��������� � ��������� 
	{
		// ���� ���������� ������� 
		while (x > 0) // ������������ �� ��� ���, ���� �� ���������� ����� ������ 
		{
		gt_VerSch:; 

			// ���� �������� ������
			cout << "������� �������� ������: ";
			cin >> Zeitspanne;
			if (strlen(Zeitspanne) > 25) // �������� �� ����� 
			{
				Prufung(); // ���������� � ������������ ����� 
				system("cls"); // ������� �������
				goto gt_VerSch; 
			}
			for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� ������� 
				if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
					if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
						if ((Zeitspanne[i] != 95) && (Zeitspanne[i] != 45))
						{
							Prufung(); // ���������� � ������������ ����� 
							system("cls"); // ������� �������
							goto gt_VerSch; 
						}
			KorrigierenDaten(Zeitspanne, 1); // ��������� �������� ������ 
			strcpy_s(land[Kapazitat].Name, Zeitspanne); // ����������� �������� ������ 

			// ���� �������� �������
			cout << "������� �������� ������� ������: ";
			cin >> Zeitspanne;
			if (strlen(Zeitspanne) > 25) // �������� �� ����� 
			{
				Prufung(); // ���������� � ������������ ����� 
				system("cls"); // ������� �������
				goto gt_VerSch; 
			}
			for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� ������� 
				if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
					if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
						if ((Zeitspanne[i] != 95) && (Zeitspanne[i] != 45))
						{
							Prufung(); // ���������� � ������������ ����� 
							system("cls"); // ������� �������
							goto gt_VerSch; 
						}
			KorrigierenDaten(Zeitspanne, 1); // ��������� �������� ������ 
			strcpy_s(land[Kapazitat].HauptStadt, Zeitspanne); // ����������� �������� ������� 

			// ���� ����������� ���������
			cout << "������� ����������� ��������� ������: ";
			cin >> Zeitspanne;
			if (strlen(Zeitspanne) > 10) // �������� �� ����� 
			{
				Prufung(); // ���������� � ������������ ����� 
				system("cls"); // ������� �������
				goto gt_VerSch; 
			}
			for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� ������� 
				if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
				{
					Prufung(); // ���������� � ������������ ����� 
					system("cls"); // ������� �������
					goto gt_VerSch; 
				}
			land[Kapazitat].Nas = 0; // ��������� ��� �����������
			for (int i = 0; i < strlen(Zeitspanne); i++) // ����������� ����������� ��������� 
				land[Kapazitat].Nas += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));

			// ���� ������� ������
			cout << "������� ������� ������: ";
			cin >> Zeitspanne;
			if (strlen(Zeitspanne) > 9) // �������� �� ����� 
			{
				Prufung(); // ���������� � ������������ ����� 
				system("cls"); // ������� �������
				goto gt_VerSch; 
			}
			for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� ������� 
				if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
				{
					Prufung(); // ���������� � ������������ ����� 
					system("cls"); // ������� �������
					goto gt_VerSch; 
				}
			land[Kapazitat].Terr = 0; // ��������� ��� �����������
			for (int i = 0; i < strlen(Zeitspanne); i++) // ����������� �������
				land[Kapazitat].Terr += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));
			if (land[Kapazitat].Terr == 0)
			{
				Prufung(); // ���������� � ������������ ����� 
				system("cls"); // ������� �������
				goto gt_VerSch; 
			}

			// ���� ���� ������ ������
			cout << "������� ��� ������ ������: ";
			cin >> Zeitspanne;
			if (strlen(Zeitspanne) != 3) // �������� �� ����� 
			{
				Prufung(); // ���������� � ������������ ����� 
				system("cls"); // ������� �������
				goto gt_VerSch; 
			}
			for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� ������� 
				if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
					if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
					{
						Prufung(); // ���������� � ������������ ����� 
						system("cls"); // ������� �������
						goto gt_VerSch; 
					}
			KorrigierenDaten(Zeitspanne, 2); // ��������� �������� ������ 
			strcpy_s(land[Kapazitat].VAL, Zeitspanne); // ����������� ���� ������

			// �������� ��������� � �������
			land[Kapazitat].Nas_pro_Terr = land[Kapazitat].Nas / land[Kapazitat].Terr; // ������ ��������� ��������� 
			land[Kapazitat].index = Kapazitat + 1; // ���������� 
			Kapazitat++; // ���������� �����������

			// �������� ����������� ����� ����� ������� 
			x--; // ���������� ����� �������
			if (x >= 1) // �������� ���������� �������� �������
				cout << "\n�������� ��� ���� ������\n\n";
		}
	}
	else // ���� �������� ������ �� ��������� � ��������� 
	{
		while (x > 0) // ���� �� ���������� ����� ������ 
		{
			Kapazitat++; // ���������� ����������� ������� 
			for (int i = Kapazitat - 1; i > 0; i--)
			{
				if (i - 1 == metaindex) // ����� ������������ �������� 
				{
					land[i] = land[i - 1]; // �������������� ���� ���������� 
					land[i].index = metaindex + 2; // ���������� ����� ������ 
				gt_ZVerSch:; 

					// ���� �������� ������ 
					cout << "������� �������� ������: ";
					cin >> Zeitspanne;
					if (strlen(Zeitspanne) > 25) // �������� �� ����� 
					{
						Prufung(); // ���������� � ������������ ����� 
						system("cls"); // ������� �������
						goto gt_ZVerSch;
					}
					for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� ������� 
						if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
							if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
								if ((Zeitspanne[i] != 95) && (Zeitspanne[i] != 45))
								{
									Prufung(); // ���������� � ������������ ����� 
									system("cls"); // ������� �������
									goto gt_ZVerSch; 
								}
					KorrigierenDaten(Zeitspanne, 1); // ��������� �������� ������ 
					strcpy_s(land[metaindex].Name, Zeitspanne); // ����������� �������� ������ 

					// ���� �������� ������� 
					cout << "������� �������� ������� ������: ";
					cin >> Zeitspanne;
					if (strlen(Zeitspanne) > 25) // �������� �� ����� 
					{
						Prufung(); // ���������� � ������������ ����� 
						system("cls"); // ������� ������� 
						goto gt_ZVerSch; 
					}
					for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� ������� 
						if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
							if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
								if ((Zeitspanne[i] != 95) && (Zeitspanne[i] != 45))
								{
									Prufung(); // ���������� � ������������ ����� 
									system("cls"); // ������� �������
									goto gt_ZVerSch; 
								}
					KorrigierenDaten(Zeitspanne, 1); // ��������� �������� ������ 
					strcpy_s(land[metaindex].HauptStadt, Zeitspanne); // ����������� �������� ������� 

					// ���� ����������� ��������� ������ 
					cout << "������� ����������� ��������� ������: ";
					cin >> Zeitspanne;
					if (strlen(Zeitspanne) > 10) // �������� �� ����� 
					{
						Prufung(); // ���������� � ������������ ����� 
						system("cls"); // ������� �������
						goto gt_ZVerSch; 
					}
					for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� ������� 
						if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
						{
							Prufung(); // ���������� � ������������ ����� 
							system("cls"); // ������� �������
							goto gt_ZVerSch; 
						}
					land[metaindex].Nas = 0; // ��������� ��� �����������
					for (int i = 0; i < strlen(Zeitspanne); i++) // ����������� ����������� ��������� 
						land[metaindex].Nas += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));

					// ���� ������� ��������� 
					cout << "������� ������� ������: ";
					cin >> Zeitspanne;
					if (strlen(Zeitspanne) > 9) // �������� �� ����� 
					{
						Prufung(); // ���������� � ������������ ����� 
						system("cls"); // ������� �������
						goto gt_ZVerSch; 
					}
					for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� ������� 
						if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
						{
							Prufung(); // ���������� � ������������ ����� 
							system("cls"); // ������� �������
							goto gt_ZVerSch; 
						}
					land[metaindex].Terr = 0; // ��������� ��� �����������
					for (int i = 0; i < strlen(Zeitspanne); i++) // ����������� ������� 
						land[metaindex].Terr += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));
					if (land[metaindex].Terr == 0) // �������������� ������� �� 0
					{
						Prufung(); // ���������� � ������������ ����� 
						system("cls"); // ������� �������
						goto gt_ZVerSch; 
					}

					// ���� ���� ������
					cout << "������� ��� ������ ������: ";
					cin >> Zeitspanne;
					if (strlen(Zeitspanne) != 3) // �������� �� ����� 
					{
						Prufung(); // ���������� � ������������ ����� 
						system("cls"); // ������� �������
						goto gt_ZVerSch; 
					}
					for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� ������� 
						if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
							if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
							{
								Prufung(); // ���������� � ������������ ����� 
								system("cls"); // ������� �������
								goto gt_ZVerSch; 
							}
					KorrigierenDaten(Zeitspanne, 2); // ��������� �������� ������ 
					strcpy_s(land[metaindex].VAL, Zeitspanne); // ����������� ���� ������

					// �������� ������� ��� ���������� ���������� � ���������
					land[metaindex].Nas_pro_Terr = land[metaindex].Nas / land[metaindex].Terr; // ������� ��������� ��������� 
					metaindex++;  // ��������� �������� ������� ���������� 
					land[metaindex - 1].index = metaindex; // ���������� 

					x--; // ���������� ����� �������
					break; // ����� �� ����� for 
				}
				else
				{
					swap(land[i], land[i - 1]); // ���������� 
					land[i].index++; // ���������� 
				}
			}
			if (x >= 1) // �������� ���������� �������� �������
				cout << "\n�������� ��� ���� ������\n\n";
		}
	}

	// ���������� ��������� �����
	SpeichernDatenInBinFile(land, Kapazitat);

	// ��������� ��������-�������� ������ 
	SortierungNachVeranderungen(land, Kapazitat);

	Wartung(); // ����������� �������� 
}

void SubstragierenDaten(lander*& land, int& Kapazitat)
{
Sub_Wahl:; 
	char Antwort; // ��� ���� �� ����
	char Zeitspanne[64]; // �������� ����� - ������ �� ������������� ����� 
	int  metaindex = 0; // ����������, �� ������� ����� ����������� ��������

	// ���� ��������
	system("cls"); // ������� �������
	cout << "��� ����� ����������� ��������?\n\n"
		<< "1 - �� ������ ������\n"
		<< "2 - ����� ������ �� ���� � ������� �\n"
		<< "0 - ����� � ����\n\n"
		<< "����� ����: ";
	Antwort = _getche(); // ����� ����

	// ��������� ������� �������� 
	if (Antwort == '0') // ����� �� ����
	{
		system("cls"); // ������� �������
		goto gt_UmSchSub; 
	}
	else if ((Antwort != '1') && (Antwort != '2')) // �������� ���� ������ ����
	{
		Prufung(); // ��������� � ������������ �����
		goto Sub_Wahl; 
	}
	else if (Antwort == '1') // �������� �� ������� 
	{
	gt_SubDat:; 
		// ����� �������
		system("cls"); // ������� �������
		cout << "������ �������: \n\n";
		Mutze(); // ����� ��������� �����
		for (int i = 0; i < Kapazitat; i++) // ����� ��������� �������
			Schreiben(land, i); // ����� i-��� ������
		metaindex = 0; // ��������� ��� �����������
		// ���� ������� ������, ������� ���������� ������� 
		cout << "\n������� ����� ������, ��� �������� � �� ������: ";
		cin >> Zeitspanne;
		for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� ������� 
			if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
			{
				Prufung(); // ���������� � ������������ �����
				goto gt_SubDat; 
			}
		for (int i = 0; i < strlen(Zeitspanne); i++) // ����������� �������� �������
			metaindex += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));
		if ((metaindex > Kapazitat) || (metaindex < land[0].index))
		{
			Prufung(); // ���������� � ������������ �����
			goto gt_SubDat;
		}
	}
	else if (Antwort == '2') // �������� �� ������
	{
		metaindex = SuchenFurSubstragierung(land, Kapazitat); // ��������� �������� ������� ����� ������� ������
		if (metaindex == 0) // ������� �������� � ��������� ����
			goto Sub_Wahl; 
	}

	// ���������� ����� ��������� �������� ������� (��������� ������ � ����� �����)
	for (int i = 0; i < Kapazitat; i++)
		if (metaindex == land[i].index) // ������� ���������� 
			for (int j = i; j < Kapazitat; j++)
			{
				if (j == Kapazitat - 1) // ���� ��������� ��������� �������
				{
					Kapazitat--; // ���������� ����������� ������� 
					break;
				}
				swap(land[j], land[j + 1]); // ������������ 
				land[j].index--; // ����������
			}

gt_Runde:; 
	system("cls"); // ������� �������
	cout << "������ �������: \n\n";
	Mutze(); // ����� ��������� �����
	for (int i = 0; i < Kapazitat; i++) // ����� ��������� �������
		Schreiben(land, i); // ����� i-��� ������
	cout << "\n������� ���? (y ��� n): "; // ������ �� ������ 
	Antwort = _getche(); // �����
	if ((Antwort != 'y') && (Antwort != 'n')) // �������� �����
	{
		Prufung(); // ���������� � ������������ �����
		goto gt_Runde; 
	}
	if (Antwort == 'y') goto Sub_Wahl;
	else if (Antwort == 'n') // ����� �������� 
	{
	gt_UmSchSub:; 
		system("cls"); // ������� ������� 
		cout << "������ �������: \n\n";  Mutze(); // ����� ��������� �����
		for (int i = 0; i < Kapazitat; i++) // ����� ��������� �������
			Schreiben(land, i); // ����� i-��� ������
		cout << "\n������������ ������? (y ��� n): "; // ������ �� ����������� ������
		Antwort = _getche(); // ����� 
		if ((Antwort != 'y') && (Antwort != 'n')) // �������� �����
		{
			Prufung(); // ���������� � ������������ �����
			goto gt_UmSchSub;
		}
		else if ((Antwort == 'y')) // �������������� ������
		{

			// ���������� ������������� �������
			VeranderungZahlDaten(land, Kapazitat, 0);

			// ���������� ��������� �����
			SpeichernDatenInBinFile(land, Kapazitat);
			cout << "\n\n������ ������������\n"; // ���������� � ���������� ������
		}
		else if (Antwort == 'n') // �� �������������� ������ 
		{
			LesenDaten(land, Kapazitat);
			cout << "\n\n������ �������� ��� ���������\n";
		}
	}

	// ���������� ��������-�������� ������
	SortierungNachVeranderungen(land, Kapazitat); // ��������� ���.-���. ������
	Wartung();
}

void UmSreibenData(lander*& land, int& Kapazitat)  
{
USD_Alles:; 
	// ������� ���������� 
	int metaindex = 0; // ��������� �������� �������
	char Zeitspanne[64]; // �������� ����� - ������ �� ������������� �����
	char Antwort; // ��� ���� �� ������� 

	// ������ ������� 
	system("cls"); // ������� �������
	cout << "������ �������: \n\n";
	Mutze(); // ����� �����
	for (int i = 0; i < Kapazitat; i++) // ����� ��������� ������� 
		Schreiben(land, i); // ����� i-��� ������

	// ���� ������� ������
	cout << "\n������� ����� ������, ������� ���������� ���������������: ";
	cin >> Zeitspanne;
	for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� ������� 
		if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
		{
			Prufung(); // ���������� � ������������ ����� 
			goto USD_Alles; 
		}
	for (int i = 0; i < strlen(Zeitspanne); i++) // ����������� �������� �������
		metaindex += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));
	if ((metaindex > Kapazitat) || (metaindex < land[0].index)) // �������� ������������� ������� 
	{
		Prufung(); // ���������� � ������������ ����� 
		goto USD_Alles; 
	}

	// ����� ������ �������� 
	cout << "\n��������������� ��� ������? 'y' - ���, 'n' - ����� ������: ";
	Antwort = _getche(); // ���� ������ 
	if ((Antwort != 'y') && (Antwort != 'n')) // �������� ����� ������ 
	{
		Prufung(); // ���������� � ������������ ����� 
		goto USD_Alles; 
	}
	if (Antwort == 'y') // �������� ���� ������ 
	{
	Alles_Um:; 

		// ����� �������� ���� ������
		system("cls"); // ������� �������  
		cout << "�������� ���� ������\n\n";
		Mutze(); // ����� ��������� �����
		for (int i = 0; i < Kapazitat; i++) // ����� ��������� �������
			if ((metaindex == land[i].index)) // ������� ������ 
				Schreiben(land, i); // ����� i-��� ������

		// ���� ������ 
		for (int i = 0; i < Kapazitat; i++) // ����� ���������� ������ 
			if ((metaindex == land[i].index)) // ������� ��������� 
			{
				// ���� �������� ������ 
				cout << "\n������� �������� ������: ";
				cin >> Zeitspanne;
				if (strlen(Zeitspanne) > 25) // �������� �� �����
				{
					Prufung(); // ���������� � ������������ ����� 
					goto Alles_Um; 
				}
				for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� �������
					if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
						if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
							if ((Zeitspanne[i] != 95) && (Zeitspanne[i] != 45))
							{
								Prufung(); // ���������� � ������������ ����� 
								goto Alles_Um; 
							}
				KorrigierenDaten(Zeitspanne, 1); // ��������� �������� ������
				strcpy_s(land[i].Name, Zeitspanne); // ����������� �������� ������ 

				// ���� �������� �������
				cout << "������� �������� �������: ";
				cin >> Zeitspanne;
				if (strlen(Zeitspanne) > 25) // �������� �� �����
				{
					Prufung(); // ���������� � ������������ ����� 
					goto Alles_Um; 
				}
				for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� ������� 
					if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
						if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
							if ((Zeitspanne[i] != 95) && (Zeitspanne[i] != 45))
							{
								Prufung(); // ���������� � ������������ ����� 
								goto Alles_Um; 
							}
				KorrigierenDaten(Zeitspanne, 1); // ��������� �������� ������
				strcpy_s(land[i].HauptStadt, Zeitspanne); // ����������� �������� �������

				// ���� ����������� ��������� 
				cout << "������� ����������� ���������: ";
				cin >> Zeitspanne;
				if (strlen(Zeitspanne) > 9) // �������� �� �����
				{
					Prufung(); // ���������� � ������������ ����� 
					goto Alles_Um; 
				}
				for (int j = 0; j < strlen(Zeitspanne); j++) // �������� �� �������
					if ((static_cast<int>(Zeitspanne[j]) - 48 < 0) || (static_cast<int>(Zeitspanne[j]) - 48 > 9))
					{
						Prufung(); // ���������� � ������������ ����� 
						goto Alles_Um; 
					}
				land[i].Nas = 0; // ��������� ��� �����������
				for (int j = 0; j < strlen(Zeitspanne); j++) // ����������� ����������� ��������� 
					land[i].Nas += (((static_cast<int>(Zeitspanne[j])) - 48) * pow(10, (strlen(Zeitspanne) - 1 - j)));

				// ���� �������
				cout << "������� �������: ";
				cin >> Zeitspanne;
				if (strlen(Zeitspanne) > 9) // �������� �� �����
				{
					Prufung(); // ���������� � ������������ ����� 
					goto Alles_Um; 
				}
				for (int j = 0; j < strlen(Zeitspanne); j++) // �������� �� �������
					if ((static_cast<int>(Zeitspanne[j]) - 48 < 0) || (static_cast<int>(Zeitspanne[j]) - 48 > 9))
					{
						Prufung(); // ���������� � ������������ ����� 
						goto Alles_Um; 
					}
				land[i].Terr = 0; // ��������� ��� ����������� 
				for (int j = 0; j < strlen(Zeitspanne); j++) // ����������� �������
					land[i].Terr += (((static_cast<int>(Zeitspanne[j])) - 48) * pow(10, (strlen(Zeitspanne) - 1 - j)));
				if (land[i].Terr == 0) // �������������� ������� �� 0
				{
					Prufung(); // ���������� � ������������ ����� 
					goto Alles_Um; 
				}

				// ���� ���� ������ ������ 
				cout << "�������� ��� ������ ������: ";
				cin >> Zeitspanne;
				if (strlen(Zeitspanne) != 3) // �������� �� �����
				{
					Prufung(); // ���������� � ������������ ����� 
					goto Alles_Um; 
				}
				for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� ������� 
					if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
						if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
						{
							Prufung(); // ���������� � ������������ ����� 
							goto Alles_Um; 
						}
				KorrigierenDaten(Zeitspanne, 2); // ��������� �������� ������
				strcpy_s(land[i].VAL, Zeitspanne); // ����������� ������ ������

				// ������� ��������� ��������� 
				land[i].Nas_pro_Terr = land[i].Nas / land[i].Terr;
				break;
			}

		// ����� ���������� ������
		cout << "\n���������� ������: \n\n";
		Mutze(); // ����� ����� 
		for (int i = 0; i < Kapazitat; i++) // ����� ������� �������
			if ((metaindex == land[i].index)) // ������� ������
				Schreiben(land, i); // ����� i-��� ������
		cout << endl;

		Wartung(); // ��������
	}
	else
	{
		while (Antwort != '0') // ����������� ������ � ���� �������� 
		{
		USD_Teil:; 
			system("cls"); // ������� �������

			// ����� ���� �������� 
			Mutze(); // ����� ��������� ����� 
			Schreiben(land, (metaindex - 1)); // ����� ��������� ��������� ������ 
			cout << "\n����� ���� ��������?\n\n" // ���� �������� 
				<< "1 - �������� ������\n"
				<< "2 - �������� �������\n"
				<< "3 - ����������� ���������\n"
				<< "4 - ������� ���������\n"
				<< "5 - ��� ������\n"
				<< "0 - ����� �� ��������������\n\n"
				<< "�������� ����: ";
			Antwort = _getche(); // ����� ������ ���� �������� 

			// ��� �� ���� ��������
			if (Antwort == '0') break; // ����� �� ���� �������� 
			switch (Antwort)
			{

			case '1': // �������� �������� ������
				cout << "\n\n������� �������� ������: ";
				cin >> Zeitspanne;
				if (strlen(Zeitspanne) > 25) // �������� �� �����
				{
					Prufung(); // ����������� � ������������ ����� 
					goto USD_Teil; 
				}
				for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� �������
					if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
						if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
							if ((Zeitspanne[i] != 95) && (Zeitspanne[i] != 45))
							{
								Prufung(); // ����������� � ������������ ����� 
								goto USD_Teil;
							}
				KorrigierenDaten(Zeitspanne, 1); // ��������� ������� ������
				strcpy_s(land[metaindex - 1].Name, Zeitspanne); // ����������� �������� ������
				break;

			case '2': // �������� �������� �������
				cout << "\n\n������� �������� �������: ";
				cin >> Zeitspanne;
				if (strlen(Zeitspanne) > 25) // �������� �� �����
				{
					Prufung(); // ����������� � ������������ ����� 
					goto USD_Teil; 
				}
				for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� �������
					if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
						if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
							if ((Zeitspanne[i] != 95) && (Zeitspanne[i] != 45))
							{
								Prufung(); // ����������� � ������������ ����� 
								goto USD_Teil; 
							}
				KorrigierenDaten(Zeitspanne, 1); // ��������� �������� ������
				strcpy_s(land[metaindex - 1].HauptStadt, Zeitspanne); // ����������� ������� ������
				break;

			case '3': // �������� ����������� ��������� 
				cout << "\n\n������� ����������� ���������: ";
				cin >> Zeitspanne;
				if (strlen(Zeitspanne) > 10) // �������� �� �����
				{
					Prufung(); // ����������� � ������������ ����� 
					goto USD_Teil;
				}
				for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� �������
					if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
					{
						Prufung(); // ����������� � ������������ ����� 
						goto USD_Teil; 
					}
				land[metaindex - 1].Nas = 0; // ��������� ��� ����������� 
				for (int i = 0; i < strlen(Zeitspanne); i++) // ����������� ����������� ��������� 
					land[metaindex - 1].Nas += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));
				// ��������������� ���������
				land[metaindex - 1].Nas_pro_Terr = land[metaindex - 1].Nas / land[metaindex - 1].Terr;
				break;

			case '4': // �������� �������� ��������� 
				cout << "\n\n������� ������� ���������: ";
				cin >> Zeitspanne;
				if (strlen(Zeitspanne) > 9) // �������� �� �����
				{
					Prufung(); // ����������� � ������������ ����� 
					goto USD_Teil; 
				}
				for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� ������� 
					if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
					{
						Prufung(); // ����������� � ������������ ����� 
						goto USD_Teil; 
					}
				land[metaindex - 1].Terr = 0; // ��������� ��� ����������� 
				for (int i = 0; i < strlen(Zeitspanne); i++) // ����������� �������
					land[metaindex - 1].Terr += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));
				if (land[metaindex - 1].Terr == 0) // ������������ ������� �� ����
				{
					Prufung(); // ����������� � ������������ ����� 
					goto USD_Teil; 
				}
				// ��������������� ��������� 
				land[metaindex - 1].Nas_pro_Terr = land[metaindex - 1].Nas / land[metaindex - 1].Terr;
				break;

			case '5': // �������� ���� ������ ������
				cout << "\n\n������� ��� ������: ";
				cin >> Zeitspanne;
				if (strlen(Zeitspanne) != 3) // �������� �� �����
				{
					Prufung(); // ����������� � ������������ ����� 
					goto USD_Teil; 
				}
				for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� ������� 
					if ((Zeitspanne[i] < 65) || (Zeitspanne[i] > 90))
						if ((Zeitspanne[i] < 97) || (Zeitspanne[i] > 122))
						{
							Prufung(); // ����������� � ������������ ����� 
							goto USD_Teil;
						}
				KorrigierenDaten(Zeitspanne, 2); // ��������� �������� ������
				strcpy_s(land[metaindex - 1].VAL, Zeitspanne); // ����������� ���� ������ ������

				break;
			default:
				Prufung(); // ���������� � ������������ ����� 
				goto USD_Teil; 
				break;
			}
		}
	}

	// ��������� �������� ������
	SpeichernDatenInBinFile(land, Kapazitat);

	// ��������� ��������-�������� ������  
	SortierungNachVeranderungen(land, Kapazitat); // ��������� ���.-���. ������
}

void SpeichernDatenInTextFile(lander*& land, int& Kapazitat)
{
	system("cls"); // ������� ������� 
	ofstream reisen; // ���������� ��� ������ � ����
	reisen.open("Lender.txt"); // �������� ���������������� �����
	reisen << "Notes: " << Kapazitat; // ������ ������� ������
	for (int j = 0; j < Kapazitat; j++) // ������ ��������� �������
		reisen << endl << setw(26) << setiosflags(ios::left) << land[j].Name // ������ �������� ������
		<< setw(26) << land[j].HauptStadt // ������ ��������� �������
		<< setw(15) << land[j].Nas // ������ ����������� ��������� ������
		<< setw(15) << land[j].Terr // ������ ������� ������
		<< setw(3) << land[j].VAL; // ������ ���� ������ ������
	reisen.close(); // �������� �����
	cout << "������ ������� ���������\n\n";
	Wartung();
}

void VeranderungZahlDaten(lander*& land, int& Kapazitat, int delta)
{
	lander* buffer = new lander[Kapazitat + delta]; // �������� ����������� ������ 
	for (int i = 0; i < Kapazitat; i++) // ���������� ������ � ���������� ����� 
		buffer[i] = land[i];
	delete[] land; // ������� ��������� ������
	land = new lander[Kapazitat + delta]; // ��������������� ��������� ������ 
	for (int i = 0; i < Kapazitat; i++) // ���������� ������ � ����������� �������� �����
		land[i] = buffer[i];
	delete[] buffer; // ������� ����������� ������
}

void SpeichernDatenInBinFile(lander*& land, int& Kapazitat)
{
	ofstream reisen; // ���������� ��� ������ � ����
	reisen.open(DerNameDesTextes, ios::binary | ios::out); // �������� �������� �����
	reisen.write((char*)&Kapazitat, sizeof(Kapazitat)); // ������ ������� ������
	for (int i = 0; i < Kapazitat; i++) // ������ ��������� ������������������ ��������
		reisen.write((char*)&land[i], sizeof(land[i]));
	reisen.close(); // �������� �����
}