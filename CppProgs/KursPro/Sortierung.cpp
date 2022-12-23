#include <iostream> // ��� ����� � ������
#include <iomanip> // ��� setw()
#include <conio.h> // ��� _getche()
#include <stdio.h> // ��� ������ � �������
#include <fstream> // ��� ������ � �������
#include "Peripherie.h" // ����������� ���� ����� ���������
#include "Sortierung.h" // ����������� ����������� ������������� �����

using namespace std; // ����������� ������������ ��� std

// ���������� ��������� ������� ��� ��������� ������������� �������, ���������� � ���� ������ 
int HeranSortierung(lander*& land , int i, int j); // ������ ��� ����������
void ZuruckSortierung(lander*& land , int& Kapazitat); // �������� ��� ���������� 

void SortieranDaten(lander*& land , int& Kapazitat) // ���������� ������ 
{
Haupt_Sortierung:; // ������ 151
	// ������� ���������� 
	ifstream IndexFileR; // ��� ������ ��������-�������� ������
	int K = Kapazitat; // ��� �������� ����������� �� ������ � ������ ������� 
	int* metamass = new int[Kapazitat]; // ��� ������ �������� �� ��������-�������� ������
	char laufgang = '8'; // ��� ���� �� ����

	// ��� ����������
	while (laufgang != '0') // ����������� �������������� ���� 
	{
		system("cls"); // ������� ������� 
		cout << "���� ����������:\n\n" // ���� ���������� 
			<< "1 - ���������� �� �������� ������ (�� ��������)\n"
			<< "2 - ���������� �� �������� ������� ������ (�� ��������)\n"
			<< "3 - ���������� �� ����������� ��������� ������ (�� ��������)\n"
			<< "4 - ���������� �� ������� ������ (�� ��������)\n"
			<< "5 - ���������� �� ��������� ��������� ������ (�� ��������)\n"
			<< "6 - ���������� �� ���� ������ ������ (�� ��������)\n"
			<< "0 - ����� �� ���� ����������\n"
			<< "\n����� ������ ����: ";
		laufgang = _getche(); // ����� ������ ���� 
		switch (laufgang) // ������������� �� ���� 
		{
		case '1':
			system("cls"); // ������� ������� 

			// �������� ���.-���. ����� � �������� ������ ��� ������ 
			IndexFileR.open("Sort_Name_Bin.txt", ios::binary | ios::out); 
			for (int i = 0; i < Kapazitat; i++) // ������ ������ �� �����
				IndexFileR.read((char*)&metamass[i], sizeof(metamass[i]));
			IndexFileR.close(); // �������� ��������-��������� �����
			// ����� ���������� 
			Mutze(); // ����� �����
			for (int i = 0; i < Kapazitat; i++) // ����� ���������������� �������
				for (int j = 0; j < Kapazitat; j++)
					if (metamass[i] == land[j].index) // ������� ������
						Schreiben(land, j);

			cout << endl; // ��� ��������
			Wartung(); // ����������� ��������
			break;
		case '2':
			system("cls"); // ������� �������

			// �������� ���.-���. ����� � �������� ������ ��� ������ 
			IndexFileR.open("Sort_Hauptstadt_Bin.txt", ios::binary | ios::out); 
			for (int i = 0; i < Kapazitat; i++) // ������ ������ �� �����
				IndexFileR.read((char*)&metamass[i], sizeof(metamass[i]));
			IndexFileR.close(); // �������� ��������-��������� �����
			// ����� ����������
			Mutze(); // ����� �����
			for (int i = 0; i < Kapazitat; i++) // ����� ���������������� �������
				for (int j = 0; j < Kapazitat; j++)
					if (metamass[i] == land[j].index) // ������� ������
						Schreiben(land, j);

			cout << endl; // ��� ��������
			Wartung(); // ����������� ��������
			break;
		case '3':
			system("cls"); // ������� �������

			// �������� ���.-���. ����� � �������� ������ ��� ������ 
			IndexFileR.open("Sort_Nas_Bin.txt", ios::binary | ios::out); 
			for (int i = 0; i < Kapazitat; i++) // ������ ������ �� �����
				IndexFileR.read((char*)&metamass[i], sizeof(metamass[i]));
			IndexFileR.close(); // �������� ��������-��������� �����
			// ����� ����������
			Mutze(); // ����� �����
			for (int i = 0; i < Kapazitat; i++) // ����� ���������������� �������
				for (int j = 0; j < Kapazitat; j++)
					if (metamass[i] == land[j].index) // ������� ������
						Schreiben(land, j);

			cout << endl; // ��� ��������
			Wartung(); // ����������� ��������
			break;
		case '4':
			system("cls"); // ������� �������

			// �������� ���.-���. ����� � �������� ������ ��� ������ 
			IndexFileR.open("Sort_Terr_Bin.txt", ios::binary | ios::out); 
			for (int i = 0; i < Kapazitat; i++) // ������ ������ �� �����
				IndexFileR.read((char*)&metamass[i], sizeof(metamass[i]));
			IndexFileR.close(); // �������� ��������-��������� �����
			// ����� ����������
			Mutze(); // ����� �����
			for (int i = 0; i < Kapazitat; i++) // ����� ���������������� �������
				for (int j = 0; j < Kapazitat; j++)
					if (metamass[i] == land[j].index) // ������� ������
						Schreiben(land, j);

			cout << endl; // ��� ��������
			Wartung(); // ����������� ��������
			break;
		case '5':
			system("cls"); // ������� �������

			// �������� ���.-���. ����� � �������� ������ ��� ������ 
			IndexFileR.open("Sort_Nas_pro_Terr_Bin.txt", ios::binary | ios::out); 
			for (int i = 0; i < Kapazitat; i++) // ������ ������ �� �����
				IndexFileR.read((char*)&metamass[i], sizeof(metamass[i]));
			IndexFileR.close(); // �������� ��������-��������� �����
			// ����� ����������
			Mutze(); // ����� �����
			for (int i = 0; i < Kapazitat; i++) // ����� ���������������� �������
				for (int j = 0; j < Kapazitat; j++)
					if (metamass[i] == land[j].index) // ������� ������
						Schreiben(land, j);

			cout << endl; // ��� ��������
			Wartung(); // ����������� ��������
			break;
		case '6':
			system("cls"); // ������� �������

			// �������� ���.-���. ����� � �������� ������ ��� ������ 
			IndexFileR.open("Sort_VAL_Bin.txt", ios::binary | ios::out); 
			for (int i = 0; i < Kapazitat; i++) // ������ ������ �� �����
				IndexFileR.read((char*)&metamass[i], sizeof(metamass[i]));
			IndexFileR.close(); // �������� ��������-��������� �����
			// ����� ����������
			Mutze(); // ����� �����
			for (int i = 0; i < Kapazitat; i++) // ����� ���������������� �������
				for (int j = 0; j < Kapazitat; j++)
					if (metamass[i] == land[j].index) // ������� ������
						Schreiben(land, j);

			cout << endl; // ��� ��������
			Wartung(); // ����������� ��������
			break;
		case '0': break; // ��� �������� ������ �� ���� 
		default:
			Prufung(); // �������������� � ������������ �����
			goto Haupt_Sortierung; // ������ 17
			break;
		}
	}
	system("cls"); // ������� ������� 
}

int HeranSortierung(lander*& land , int i, int j) // ������ ��� ��������� 
{
	swap(land[i], land[j]); // ������������ �������� 
	return 0; // ����������� ���������� �������� ������
}

void ZuruckSortierung(lander*& land , int& Kapazitat) // �������� ��� ���������� 
{
	for (int i = 0; i < Kapazitat; i++) // ���������� �� �������            
		for (int j = i + 1; j < Kapazitat; j++) // ������� �������          
			if (land[i].index > land[j].index) // ������� ��������� ������� 
				i = HeranSortierung(land, i, j); // ������ ��� � �������� ���� :3
	cout << endl; // ��� �������� 
}

void SortierungNachVeranderungen(lander*& land , int& K) // ���������� ��������-�������� ������ ����� ��������� ������
{
	ofstream IndexReisen; // ���������� ��� ��������� ��������� ������

	// ���������� �� �������� ������
	for (int i = 0; i < K; i++)
		for (int j = i + 1; j < K; j++)
			if (strcmp(land[i].Name, land[j].Name) > 0) // ���������� ���������� ��� ����������
				i = HeranSortierung(land, i, j); // ���������������� ���������� 
	// �������� ���������������� ����������-��������� ����� � ��� ���������� 
	IndexReisen.open("Sort_Name_Bin.txt", ios::binary | ios::out);
	for (int i = 0; i < K; i++) // ������ ��������� ������������������ ��������
		IndexReisen.write((char*)&land[i].index, sizeof(land[i].index));
	IndexReisen.close(); // �������� �����

	// ���������� �� �������� �������
	for (int i = 0; i < K; i++)
		for (int j = i + 1; j < K; j++)
			if (strcmp(land[i].HauptStadt, land[j].HauptStadt) > 0) // ���������� ���������� ��� ����������
				i = HeranSortierung(land, i, j); // ���������������� ����������
	// �������� ���������������� ����������-��������� ����� � ��� ���������� 
	IndexReisen.open("Sort_Hauptstadt_Bin.txt", ios::binary | ios::out);
	for (int i = 0; i < K; i++) // ������ ��������� ������������������ ��������
		IndexReisen.write((char*)&land[i].index, sizeof(land[i].index));
	IndexReisen.close(); // �������� �����

	// ���������� �� ����������� ��������� ������ 
	for (int i = 0; i < K; i++)
		for (int j = i + 1; j < K; j++)
			if (land[i].Nas < land[j].Nas) // ���������� ���������� ��� ����������
				i = HeranSortierung(land, i, j); // ���������������� ����������
	// �������� ���������������� ����������-��������� ����� � ��� ���������� 
	IndexReisen.open("Sort_Nas_Bin.txt", ios::binary | ios::out);
	for (int i = 0; i < K; i++) // ������ ��������� ������������������ ��������
		IndexReisen.write((char*)&land[i].index, sizeof(land[i].index));
	IndexReisen.close(); // �������� �����

	// ���������� �� ������� ������ 
	for (int i = 0; i < K; i++)
		for (int j = i + 1; j < K; j++)
			if (land[i].Terr < land[j].Terr) // ���������� ���������� ��� ����������
				i = HeranSortierung(land, i, j); // ���������������� ����������
	// �������� ���������������� ����������-��������� ����� � ��� ���������� 
	IndexReisen.open("Sort_Terr_Bin.txt", ios::binary | ios::out);
	for (int i = 0; i < K; i++) // ������ ��������� ������������������ ��������
		IndexReisen.write((char*)&land[i].index, sizeof(land[i].index));
	IndexReisen.close(); // �������� �����

	// ���������� �� ��������� ���������
	for (int i = 0; i < K; i++)
		for (int j = i + 1; j < K; j++)
			if (land[i].Nas_pro_Terr < land[j].Nas_pro_Terr) // ���������� ���������� ��� ����������
				i = HeranSortierung(land, i, j); // ���������������� ����������
	// �������� ���������������� ����������-��������� ����� � ��� ����������  
	IndexReisen.open("Sort_Nas_pro_Terr_Bin.txt", ios::binary | ios::out);
	for (int i = 0; i < K; i++) // ������ ��������� ������������������ ��������
		IndexReisen.write((char*)&land[i].index, sizeof(land[i].index));
	IndexReisen.close(); // �������� �����

	// ���������� �� ���� ������ ������
	for (int i = 0; i < K; i++)
		for (int j = i + 1; j < K; j++)
			if (strcmp(land[i].VAL, land[j].VAL) > 0) // ���������� ���������� ��� ����������
				i = HeranSortierung(land, i, j); // ���������������� ����������
	// �������� ���������������� ����������-��������� ����� � ��� ���������� 
	IndexReisen.open("Sort_VAL_Bin.txt", ios::binary | ios::out);
	for (int i = 0; i < K; i++) // ������ ��������� ������������������ ��������
		IndexReisen.write((char*)&land[i].index, sizeof(land[i].index));
	IndexReisen.close(); // �������� �����

	// ����������� ������ � �������� ������� 
	ZuruckSortierung(land, K);
}