#include "Bank.h" // ��� ����� �������� 

void credit_help(Gamer& player, int power_credit); // ������ ����������

void money_status(Gamer& player) // �������� ��������� �������
{
	char step; // ��� ���� �� ����
	while (true) { // ���� �� ����� ������ ����� ������ �� ���� 
		system("cls");
		std::cout << "������: " << player.money << std::endl // ���� �������
 			<< "1 - ��������� ������\n"
			<< "2 - ������ ������\n"
			<< "0 - ��������� � ������� ����\n"
			<< "�������� ���� �� ���������: ";
		step = _getche(); // ������ ����� ����
		switch (step) {
		case '1':
			credit(player); // ����������� ���������� ������� 
			break; // � ���� �������
		case '2':
			debt_status(player); // ����������� ��������� ������
			break; // � ���� ������� 
		case '0': // ���� case ����, ����� ������������� ��������� � default ��� ������ ������ ����
			return; // ����� � ������� ����
		default: // ������ �� ������� ��� �������� ������
			std::cout << "\n������ �������� ���, ���������� ��� ���\n";
			system("pause");
			break; // ������� � ���� �������
		}
	}
}

void credit(Gamer& player) // ���������� ������� 
{
	char step; // ��� ������ ������ ����
	while (true) { // ���� �� ����� ������ ����� ������ �� ����
		system("cls");
		std::cout << "���� ���������� (������� ������ ������� �� �����):\n" // ���� ����������
			<< "1 - ������ (100)\n"
			<< "2 - ���� (250)\n"
			<< "3 - ������ � ����� (500)\n"
			<< "4 - �������� � ������ (1000)\n"
			<< "5 - ��������� (1500)\n"
			<< "6 - ������ � �������� (2000)\n"
			<< "0 - ������� \n"
			<< "�������� ���� �� ���������: ";
		step = _getche(); // ����� ������ ����
		switch (step) {
		case '0': return; // ����� � ���� �������
		case '1': // ��������� �� 100
			credit_help(player, 100);
			return; // ����� � ���� �������
		case '2': // ���������� �� 250
			credit_help(player, 250);
			return; // ����� � ���� �������
		case '3': // ���������� �� 500
			credit_help(player, 500);
			return; // ����� � ���� �������
		case '4': // ���������� �� 1000
			credit_help(player, 1000);
			return; // ����� � ���� �������
		case '5': // ���������� �� 1500
			credit_help(player, 1500);
			return; // ����� � ���� �������
		case '6': // ���������� �� 2000
			credit_help(player, 2000);
			return; // ����� � ���� �������
		default: // ������ �� ������ ��� ��������� ������
			std::cout << "\n������ �������� ���, ���������� ��� ���\n";
			system("pause");
			break; // � ���� ����������
		}
	}
}

void debt_status(Gamer& player) // ��������� ��������� ������ 
{
	if (!player.debt) { // ���� ���� ����� 0
		std::cout << "\n� ��� ��� ������\n";
		system("pause");
		return; // ������� � ������� ����
	}
	else { // ���� ����� ����
		char step; // ���� �� ����
		while (true) {
			system("cls");
			std::cout << "���� �����: " << player.debt << std::endl // ���� ������
				<< "1 - �������� �����\n"
				<< "2 - ��������� � ���� �������\n"
				<< "�������� ���� �� ���������: ";
			step = _getche(); // ����� ������ ����
			switch (step) {
			case '1': // ������� ��������� ������ 
				int return_debt; // ����� ��������� 
				while (true) {
					system("cls");
					std::cout << "��� ������: " << player.money << std::endl // ������� ���������
						<< "���� �����: " << player.debt << std::endl
						<< "��� �������� � ���� ������� ������ ������� 0\n"
						<< "������� ����� ��������� ����� � ������� Enter: ";
					std::cin >> return_debt; // ���� ����� ��������� 
					if (return_debt == 0) return; // ���� ������ 0, �� � ���� ������� 
					if (return_debt < 0) { // ���� ������� ������������� ����� 
						std::cout << "�� ����� ������������� �����!\n";
						continue; // � ������� ��������� 
					}
					if (return_debt <= player.money) { // ���� ������� ����� ������� ���� ������ ������� ������
						if (return_debt > player.debt) { // ���� ������� ����� ������������� ��� ����
							player.money -= player.debt; // ���������� ������ ����� �� ��� ����
							player.debt = 0; // �������� �����
						}
						else { // ���� ������� ����� �� ������������� ��� ���� 
							player.debt -= return_debt; // ��������� ������ �� ����� ��������� 
							player.money -= return_debt; // ��������� ��� ���� �� ����� ���������
						}
						if (player.debt == 0) std::cout << "����� ��������!\n"; // ���� ����� ��������
						else std::cout << "������� ������: " << player.debt << std::endl; // ���� �������� ����
						system("pause");
						return; // � ���� �������
					}
					else { // ���� ������� ����� ������������� ������ ������
						std::cout << "� ��� ������������ �������!\n";
						system("pause");
						continue; // � ������� ��������� ������
					}
				}
				break; // � ������ ����� 
			case '2': return; // ����� � ���� �������
			default:
				std::cout << "\n������ �������� ���, ���������� ��� ���\n";
				system("pause");
			}
		}
	}
}

void data_status(Gamer& player) { // ���������� ������
	system("cls");
	player.show_data(); // �������� ����������
	system("pause");
}

bool collectors(Gamer& player) // ��������� �����������
{
	if (player.debt > 20000) { // ������� "������"
		player.debt = player.money = player.wins = 0; // ��������� ������
		system("cls");
		std::cout << "�� �������� ������� ������� ����� (����� 20000) � � ��� ������ ����������!!!"
			<< "\n�� ���������!!! ���� ������ ��������\n"; // ���������� �� ��������� 
		system("pause");
		return true; // ��, � ������ �������� 
	}
	else return false; // ���, � ������ ��� ������� 
}

bool money_controle(const int player_money)
{
	if (player_money <= 0) { // � ������ ��� ���� ������ 
		system("cls");
		std::cout << "\n� ��� ������������ ������, ����� ���������� ���!\n";
		system("pause");
		return true; // ��, � ������ ��������
	}
	else return false; // ���, � ������ ��� ������� 
}

void credit_help(Gamer& player, int power_credit) // ������ ���������� 
{
	std::cout << "\n��� ������ ���������� �� " << power_credit << std::endl; // ����� ���������� 
	player.money += power_credit; // ���������������� ����������
	player.debt += power_credit + int(power_credit * 0.1); // ������ �����
	if (int(player.wins / 10) < power_credit) player.debt += int(player.wins / 10); // ������� �� �����
	else player.debt += power_credit; // ������������ ������� �� ����� (�� ������ ��������� ����� ���������)
	collectors(player); // �������� ������� ����� ������ 
	system("pause");
}