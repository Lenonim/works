#include "casino_games.h" // ��� ����������� ����������������
#include "Bank.h" // ��� �����������

//////////////////////////////////// ����� ���������� ////////////////////////////////////

void table_money_ctrl(int& table_money, const int money) { // ������ ������ 
	do { // ������ �� ������
		system("cls");
		std::cout << "��� ������ = " << money << std::endl
			<< "������� ������ � ������� Enter (��� ������ � ������� ���� ������� 0): ";
		std::cin >> table_money; // �������� ������ 
	} while (table_money < 0 || table_money > money); // ���� �� ����� ������� ���������� ������
}
void win_in_game(Gamer& player, int table_money, float k) { // ������ � ���� 
	std::cout << "�� ��������!!!\n" // ���������� � ������
		<< "��� ������� = " << (int)(table_money * k); // ���������� ����� �������� 
	std::cout << std::endl;
	player.money += table_money * k; // ��������� ������� ���������  
	player.wins++; // ��������� ����� �����
	system("pause");
}
void lose_in_game(Gamer& player, int table_money) { // �������� � ����
	std::cout << "�� ���������!!!\n" // ���������� � ������
		<< "��� �������� = " << table_money; // ����������� ����� ��������� 
	player.money -= table_money; // ���������� ������� ���������� 
	player.loses++; // ���������� ����� ����� 
	std::cout << std::endl;
	system("pause");
}

//////////////////////////////////// Dices ////////////////////////////////////

void dice_game(Gamer& player) { // ���� � ����� 
	srand(time(NULL)); // ��� �������
	if (player.money > 0) { // ���� ���� ������ ��� ���� 
		int table_money; // ��� ������
		char step; // ���� �� ����
			while (true) { // ��������� � ����
				table_money_ctrl(table_money, player.money); // ���� ������ 
				if (!table_money) { // ���� ������� ������ 
					return; // ����� � ������� ����
				}
				system("cls");
				std::cout << "�������� ����� ������:\n" // ����� ���� ������ 
					<< "1 - ��� �������� ������ (k = 1)\n"
					<< "2 - ��� �������� ��������� (k = 1)\n"
					<< "3 - ���� ������� ������, ������ - �������� (k = 1)\n"
					<< "4 - ������ (k = 6)\n"
					<< "5 - C���� �� ������ 6 (k = 1.5)\n"
					<< "6 - C���� ������ 6 (k = 1.5)\n"
					<< "0 - ����� � ������� ����\n"
					<< "�������� ���� �� �������: ";
				step = _getche(); // ���� ������ ����
				double_dices table_dices; // ������ ������� 
				switch (step) {
				case '1': // ������ �������� 
					system("cls");
					table_dices.show_dices(); // ����� ������ 
					if ((table_dices.get_black_dice() % 2 == 0) && (table_dices.get_white_dice() % 2 == 0)) {// ������� ������
						win_in_game(player, table_money, 1); // ������
					}
					else {
						lose_in_game(player, table_money); // �������� 
						if (money_controle(player.money) || collectors(player)) {// �������� ������� � ������
							return; // ����� � ������� ����
						}
					}
					break;
				case '2': // �������� �������� 
					system("cls");
					table_dices.show_dices(); // ����� ������ 
					if ((table_dices.get_black_dice() % 2 == 1) && (table_dices.get_white_dice() % 2 == 1)) {// ������� ������
						win_in_game(player, table_money, 1); // ������
					}
					else {
						lose_in_game(player, table_money); // �������� 
						if (money_controle(player.money) || collectors(player)) {// �������� ������� � ������
							return; // ����� � ������� ����
						}
					}
					break;
				case '3': // ���� ������, ������ ��������
					system("cls");
					table_dices.show_dices(); // ����� ������ 
					if (((table_dices.get_black_dice() % 2 == 0) && (table_dices.get_white_dice() % 2 == 1))
						|| ((table_dices.get_black_dice() % 2 == 1) && (table_dices.get_white_dice() % 2 == 0))) {// ������� ������
						win_in_game(player, table_money, 1); // ������
					}
					else {
						lose_in_game(player, table_money); // �������� 
						if (money_controle(player.money) || collectors(player)) {// �������� ������� � ������
							return; // ����� � ������� ����
						}
					}
					break;
				case '4': // ������
					system("cls");
					table_dices.show_dices(); // ����� ������ 
					if (table_dices.get_black_dice() == table_dices.get_white_dice()) {// ������� ������
						win_in_game(player, table_money, 6); // ������
					}
					else {
						lose_in_game(player, table_money); // �������� 
						if (money_controle(player.money) || collectors(player)) {// �������� ������� � ������
							return; // ����� � ������� ����
						}
					}
					break;
				case '5': // ����� �� ������ 6
					system("cls");
					table_dices.show_dices(); // ����� ������ 
					if ((table_dices.get_black_dice() + table_dices.get_white_dice()) <= 6) {// ������� ������
						win_in_game(player, table_money, 1.5); // ������
					}
					else {
						lose_in_game(player, table_money); // �������� 
						if (money_controle(player.money) || collectors(player)) {// �������� ������� � ������
							return; // ����� � ������� ����
						}
					}
					break;
				case '6': // ����� ������ 6
					system("cls");
					table_dices.show_dices(); // ����� ������ 
					if ((table_dices.get_black_dice() + table_dices.get_white_dice()) > 6) {// ������� ������
						win_in_game(player, table_money, 1.5); // ������
					}
					else {
						lose_in_game(player, table_money); // �������� 
						if (money_controle(player.money) || collectors(player)) { // �������� ������� � ������
							return; // ����� � ������� ����
						}
					}
					break;
				case '0': // ����������� ������ �� ����
					return; // ����� � ������� ���� 
				default:
					std::cout << "\n������ �������� ���, ���������� ��� ���\n";
					system("pause");
				}
			}
	}
	else { // ���� ��� ����� ��� ����
		std::cout << "\n� ��� ������������ �������!\n";
		system("pause");
		return; // ������� � ������� ���� 
	}
}

//////////////////////////////////// Blackjack ////////////////////////////////////

void black_jack_game(Gamer& player) { // ���� � ��������
	srand(time(NULL)); // ��� �������
	if (player.money > 0) { // ���� ���� ������
		while (true) {
			int table_money; // ��� ������
			char first_step, second_step; // ����
			table_money_ctrl(table_money, player.money); // ���� ������
			if (!table_money) { // ���� ������� ������ 
				return; // ������� � ������� ����
			}
			Deck table_deck; // ������ �����
			table_deck.fill_deck_up_52(); // ��������� �������� ������ �� 52 �����
			int card_ptr = 51; // ������� ������ � ����� ���� 
			Deck my_deck; // ������ ������
			my_deck.give_card(table_deck[card_ptr], card_ptr); // �������� ������ ����� ������
			my_deck.give_card(table_deck[card_ptr], card_ptr); // �������� ������ ����� ������
			while (true) {
				system("cls");
				std::cout << "���� �����:\n";
				my_deck.show_deck(); // ���������� ����� �� ����� ������ 
				std::cout << "����: " << my_deck.sum_dignity_bj() << "\n\n"; // ������� ����� ���������� ����
				std::cout << "���? (y or n) "; // ����� �� ��� �����?
				second_step = _getche(); // ����� �� ���������������� ������
				if (second_step == 'y') { // ��, ����� ��� �����, ���� ����� �����
					my_deck.give_card(table_deck[card_ptr], card_ptr); // �������� ����� �� ������
					if (my_deck.sum_dignity_bj() > 21) { // ���� �������
						system("cls");
						std::cout << "���� �����:\n";
						my_deck.show_deck(); // ���������� ������ 
						std::cout << "����: " << my_deck.sum_dignity_bj() << "\n\n"; // ������� ����� ���������� ����
						std::cout << "�������!!! "; // ���������� ���������
						lose_in_game(player, table_money); // ������ ���������
						if (money_controle(player.money) || collectors(player)) { // �������� ������� � ������
							return; // ����� � ������� ����
						}
						break; // ����� ���� 
					}
					else if (my_deck.sum_dignity_bj() == 21) { // ���� ����� �������� 
						system("cls");
						std::cout << "���� �����:\n";
						my_deck.show_deck(); // ���������� ������
						std::cout << "����: " << my_deck.sum_dignity_bj() << "\n\n"; // ������� ����� ���������� ����
						std::cout << "��������!!! ";
						win_in_game(player, table_money, 2); // ������ ������ 
						break; // ����� ���� 
					}
				}
				else if (second_step == 'n') { // ���, ������ ���� �� �����, ����� ����� ����
					Deck bank_deck; // �������� ������ ����� 
					bank_deck[0] = table_deck[card_ptr]; // �������� ����� �� ������
					card_ptr--; // �������� ������ � ������
					bank_deck.give_card(table_deck[card_ptr], card_ptr); // ���� ���� ������ �����
					while (bank_deck.sum_dignity_bj() <= my_deck.sum_dignity_bj()) { // �������� ��
						bank_deck.give_card(table_deck[card_ptr], card_ptr); // ���� ���� ����� �� ������, ���� � ����� �� ����� ������, ��� � ������
					}
					if (bank_deck.sum_dignity_bj() >= my_deck.sum_dignity_bj() && bank_deck.sum_dignity_bj() < 22) { // ������ �����
						std::cout << std::endl << "\n����� �����:" << std::endl;
						bank_deck.show_deck(); // ����� ���� �����
						std::cout << "����: " << bank_deck.sum_dignity_bj() << "\n\n"; // ������� ����� ���������� ����
						std::cout << "���� ������ ������ ������!!! ";
						lose_in_game(player, table_money); // ���� ���������
						if (money_controle(player.money) || collectors(player)) { // �������� ������� � ������
							return; // ����� � ������� ����
						}
						break; // ����� ����
					}
					else if (bank_deck.sum_dignity_bj() > 21) { // �������� ����� 
						std::cout << std::endl << "\n����� �����:" << std::endl;
						bank_deck.show_deck(); // ����� ������ �����
						std::cout << "����: " << bank_deck.sum_dignity_bj() << "\n\n"; // ������� ����� ���������� ����
						std::cout << "� ����� �������!!! ";
						win_in_game(player, table_money, 1); // ������ ��������� 
						break; // ����� ���� 
					}
				}
				else { // ������ �� ������� ��� �� ��������� ������ 
					std::cout << "� ��� �� ������ �����!\n";
					system("pause");
				}
			}
		}
	}
	else { // ���� ����� ���
		std::cout << "\n� ��� ������������ �������! \n";
		system("pause");
		return; // � ������� ���� 
	}
};

//////////////////////////////////// Ropascis ////////////////////////////////////

void ropascis(Gamer& player) { // ���� � ������-�������-������
	srand(time(NULL)); // ��� �������
	if (player.money > 0) { // ���� ���� ������ 
		int table_money; // ��� ������ 
		char step; // ��� �� ���� 
		while (true) { // ����������� � ����
			table_money_ctrl(table_money, player.money); // ���� ������
			if (!table_money) { // ���� ������� ������ 
				return; // ������� � ������� ����
			}
			std::cout << "�������� ��������:\n" // ���� ��������
				<< "1 - ������\n"
				<< "2 - �������\n"
				<< "3 - ������\n"
				<< "�����: ";
			step = _getche(); // �����
			if (step != '1' && step != '2' && step != '3') { // ������ �� ������ ��� ��������� ������ 
				std::cout << "\n�������� �����! ���������� ��� ���!\n";
				system("pause");
				continue; // � ������ ����
			}
			Hand my_hand(hand_form(step - 49)), bank_hand; // �������� ������ � �����
			std::cout << "\n�� �������: ";
			my_hand.show(); // ���� ��������
			std::cout << "���� ������: ";
			bank_hand.show(); // �������� �����
			if (my_hand == bank_hand) { // ���� ���������� �������� 
				std::cout << "�����!\n"; // ���������� ����� 
				system("pause");
			}
			else if (my_hand > bank_hand) { // ������ ������
				win_in_game(player, table_money, 1); // ������ ������ � � ���������� 
			}
			else { // ������ �����
				lose_in_game(player, table_money); // ������ ��������� � ��� ����������
				if (money_controle(player.money) || collectors(player)) {// �������� ������� � ������
					return; // ����� � ������� ����
				}
			}
		}
	}
	else { // ���� ����� ���
		std::cout << "\n� ��� ������������ �������! ��� ���������� ��������� ������\n";
		system("pause");
		return; // � ������� ���� 
	}
}