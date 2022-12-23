#include <iostream> // ��� ����� � ������
#include <iomanip> // ��� setw ()
#include "Peripherie.h" // ����������� ����������� ������������� �����

using namespace std; // ����������� ������������ ��� std

void Mutze() // ����� ����� 
{
	// ������������ �� ����� ������� � ����� ��������� ����� � ��������������� ����������� ����� � ������� 
	cout << setw(5) << setiosflags(ios::left) << "���."
		<< setw(26) << "������"
		<< setw(26) << "�������"
		<< setw(15) << "���������(���)"
		<< setw(15) << "�������(��^2)"
		<< setw(15) << "���������(N/S)"
		<< setw(3) << "������";
	cout << endl << endl; // ��� �������� 
}

void Prufung() // ���������� � ������������ ������ 
{
	system("cls"); // ������� ������� 
	// ���������������� ���������� � ������������ ������
	cout << "�������� ���� ������!\n"
		<< "������������ ������ \n"
		<< "   |(���. ��� ����� �������� � '_' - ��� ������� - ��� '-')\n"
		<< "   |(���. ��� ������� 'y' ��� 'n')\n"
		<< "   |(���. ��� ������� ���� �����)\n"
		<< "��� ���������� ����������� �����!\n"
		<< "���������� ��� ���.\n\n";
	system("pause"); // ����������� �������� 
}

void Wartung() // ������� �������� 
{
	system("pause"); // ����������� ��������
	system("cls"); // ������� ������� 
}

void Schreiben(lander*& land , int i) // ������� ������ i-���� �������� ������� �������� 
{
	// ������������ �� ����� ������� � ����� ��������� ������� � ��������������� ����������� ����� � �������
	cout << setw(5) << setiosflags(ios::left) << land[i].index  
		<< setw(26) << land[i].Name  
		<< setw(26) << land[i].HauptStadt
		<< setw(15) << land[i].Nas
		<< setw(15) << land[i].Terr
		<< setw(15) << land[i].Nas_pro_Terr
		<< setw(3) << land[i].VAL << endl;
}

void KorrigierenDaten(char Zeitspanne[], int gang) // ��� ��������� �������� �������� ������ 
{
	if (gang == 1) // ��������� ��� �������� ������ � �������
	{
		for (int i = 0; i < strlen(Zeitspanne); i++) 
		{
			Zeitspanne[i] = tolower(Zeitspanne[i]); // ���������� ��������� ���� ������
			if ((Zeitspanne[i] == 95) || (Zeitspanne[i] == 45)) // ��������� �� ���� ������� ASCII
				if (i + 1 < strlen(Zeitspanne)) // �������������� �������
				{
					// ���������� ��������� ����� ������ "_" � "-" 
					Zeitspanne[i + 1] = toupper(Zeitspanne[i + 1]);
					i = i + 2;
				}
		}
		Zeitspanne[0] = toupper(Zeitspanne[0]); // ���������� ��������� ������� �������
	}
	else if (gang == 2) // ��������� ��� ���� ������ ������
		for (int i = 0; i < 3; i++)
			Zeitspanne[i] = toupper(Zeitspanne[i]); // ���������� ��������� ������� ������� 
}