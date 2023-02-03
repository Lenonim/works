#include <fstream> // ��� ������/������ ������� ������  
#include "safe_and_load_data.h" // ����� � �������

std::fstream fs; // ������ ������ � ������
std::string path; // ������ ���� �����

std::string get_path() // ����� ����� ����������
{
	char step; // ��� ������ ����� 
	while (true) { // ���� �� ����� ������ ����� ������ ��� �����
		system("cls");
		std::cout << "����� ������:\n" // ���� ������ ����� 
			<< "1 - ������\n"
			<< "2 - ������\n"
			<< "3 - ������\n"
			<< "4 - ��������\n"
			<< "5 - �����\n"
			<< "6 - �������\n"
			<< "7 - �������\n"
			<< "8 - �������\n"
			<< "9 - �������\n"
			<< "0 - �����\n"
			<< "�������� ���� ������: ";
		step = _getche(); // ���� ������ �����
		switch (step) {
		case '1': // ��������� ����� ������ �����
			return "first_saveslot";
		case '2': // ��������� ����� ������� �����
			return "second_saveslot";
		case '3': // ��������� ����� �������� �����
			return "third_saveslot";
		case '4': // ��������� ����� ��������� ����� 
			return "fourth_saveslot";
		case '5': // ��������� ����� ������ �����
			return "fifth_saveslot";
		case '6': // ��������� ����� ������� �����
			return "sith_saveslot";
		case '7': // ��������� ����� �������� �����
			return "seventh_saveslot";
		case '8': // ��������� ����� �������� �����
			return "eighth_saveslot";
		case '9': // ��������� ����� �������� �����
			return "nineth_saveslot";
		case '0': // ����������� ������
			return "nun";
		default: // ������ �� ������ ��� ��������� ������
			std::cout << "\n������ �������� ���, ���������� ��� ���\n";
			system("pause");
			break; // ������� � ����
		}
	}
}

void safe_data(Gamer& player) // ���������� ������
{
	path = get_path(); // ����� ����� ����������
	if (path == "nun") { // ���� ������������ �� ������� �������� ����
		return; // ����� � ������� ����
	}
	else { // ����� ���� ������
		fs.open(path, std::fstream::out); // ��������� ����� ��� ������ / ������ ���� 
		fs.write((char*)&player, sizeof(Gamer)); // ��������� ��������� ������
		std::cout << "\n������ c��������!\n";
		fs.close(); // ��������� �����
		system("pause");
	}
}

void load_data(Gamer& player) // ���������� ������ 
{
	while (true) {
		path = get_path(); // ����� ����� ���������� 
		if (path == "nun") { // ���� ������������ �� ������� �������� ����
			return; // ����� � ������� ���� 
		}
		else { // ����� ���� ������
			fs.open(path, std::fstream::in); // ��������� ����� ��� ���������� 
			if (fs.is_open()) { // ���� ���� ������ 
				fs.read((char*)&player, sizeof(Gamer)); // ��������� ������
				std::cout << "\n���������� ���������!\n";
				system("pause");
			}
			else { // ���� ���� �� ������ 
				std::cout << "\n���� �� ������!\n";
				system("pause");
				continue; // ����� �������� ����
			}
			fs.close(); // ��������� ����� 
			return; // ����� � ������� ����
		}
	}
}