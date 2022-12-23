#include <iostream> // ��� ����� � ������
#include <conio.h> // ��� _getche()
#include "Statik.h" // ����������� ����������� ������������� �����
#include "Peripherie.h" // ����������� ���� ����� ���������

using namespace std; // ����������� ������������ ��� std

void SreibenDaten(lander*& land , int& Kapazitat) // ��� ������ ��������� ������� �� ����� 
{
	system("cls");  cout << "����� ����������� �����: \n\n";
	Mutze(); // ����� �����
	for (int i = 0; i < Kapazitat; i++) // ����� ��������� �������
		Schreiben(land, i); // ���������������� ����� i-���� �������� ������� �������� 
	cout << endl; // ��� �������� 
	Wartung(); // ����������� ������� 
}

void WahlDaten(lander*& land , int& Kapazitat) // ������� ������� 
{
Haupt_Wahl:; // ������ 35, 47, 56
	// ������� ���������� 
	system("cls");
	unsigned int NiedrigeGrenze = 0, HoheGrenze = 0; // ���������� ������ ���������� �������
	int leuchtturm = 0; // ������ ��� �������� ���������� 
	char Zeitspanne[64]; // �������� ����� - ������ �� ������������� �����
	cout << "������� ���������� ����������� ��������� ��� �������\n";

	// ���� ������ �������
	cout << "�� "; cin >> Zeitspanne;
	// �������� ������ �������
	for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� �������
		if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57)) 
		{
			Prufung(); // ���������� � ������������ ������
			goto Haupt_Wahl;  // ������ 20
		}
	for (int i = 0; i < strlen(Zeitspanne); i++) // ����������� ������ ������� ����������
		NiedrigeGrenze += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));

	// ���� ������� �������
	cout << "�� "; cin >> Zeitspanne;
	// �������� ������� �������
	for (int i = 0; i < strlen(Zeitspanne); i++) // �������� �� �������
		if ((Zeitspanne[i] < 48) || (Zeitspanne[i] > 57))
		{
			Prufung(); // ���������� � ������������ ������
			goto Haupt_Wahl;  // ������ 20
		}
	for (int i = 0; i < strlen(Zeitspanne); i++) // ����������� ������� ������� ����������
		HoheGrenze += ((Zeitspanne[i] - 48) * pow(10, (strlen(Zeitspanne) - 1 - i)));

	// ����� ��������
	if (NiedrigeGrenze >= HoheGrenze)
	{
		Prufung(); // ���������� � ������������ ������
		goto Haupt_Wahl;  // ������ 20
	}

	// �������� ���������� 
	for (int i = 0; i < Kapazitat; i++)
		if ((land[i].Nas > NiedrigeGrenze) && (land[i].Nas < HoheGrenze))
			leuchtturm++; // ��� ���������� ��� ���������� ������ 

	// �������� ��� �������
	if (leuchtturm == 0) // � ������, ���� ���������� �� ����
		cout << "\n��� �������, ��������������� �������!\n\n";
	else // � ������, ���� ���������� ����
	{
		cout << "\n������, ������������� ���������� ����������� ��������� [" 
			<< NiedrigeGrenze << ";" << HoheGrenze << "]:\n\n";
		Mutze(); // ����� ����� 
		for (int i = 0; i < Kapazitat; i++) // ����� ��������� �������
			if ((land[i].Nas > NiedrigeGrenze) && (land[i].Nas < HoheGrenze)) // ������� ������ ��������� �������
				Schreiben(land, i); // ���������������� ����� i-��� ������
		cout << "\n����� �������, ��������������� �������: " << leuchtturm << "\n\n"; // ����� ��������� ���������� 
	}

	Wartung(); // �������� 
}