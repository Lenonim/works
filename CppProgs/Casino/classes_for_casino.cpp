#include <iomanip> // ��� setw()
#include "classes_for_casino.h" // ��� ����� � ��������, ����� ����� ���� �������� �� ������ ����

// struct Gamer
void Gamer::show_data() { // ���������� ������ ��������� 
	std::cout << "������: " << std::setw(12) << this->money << std::endl // ����� �������
		<< "����: " << std::setw(14) << this->debt << std::endl // ����� �����
		<< "������: " << std::setw(12) << this->wins << std::endl // ����� ���������� �����
		<< "���������: " << std::setw(9) << this->loses << std::endl // ����� ���������� ���������� 
		<< "������� �����: "; 
	if (loses + wins == 0) { // ���� ��� �� �����, �� ���������� 
		std::cout << std::setw(5) << 0 << std::endl;
	}
	else { // ���� ���� ������ �/��� ���������
		std::cout << std::setw(4) << int((float(wins) / float(loses + wins)) * 100) <<'%'<< std::endl;
	}
}

Gamer::Gamer() { // �������� ������ ������ � �������� ����������� 
	money = 100; // ��������� ������� ������ 
	debt = 0; // ����� ������ 
	wins = 0; // ���������� ����� ������ 
	loses = 0; // ���������� ���������� ������ 
	setlocale(LC_ALL, "Russian"); // ���������� ���������
	std::cout << "����� ���������� � ������!\n" // ����������� � ������
		<< "��� ��������� ������� ����������: " << money << std::endl;
	system("pause");
}

// class Card
Card::Card() { // �������� ��������� �����
	this->suit = card_suit(rand() % 4); // �������� ����� �����
	this->dignity = rand() % 13 + 2; // �������� ����������� �� 2 �� ����
}

void Card::show_card() { // ����� �����
	// ���� ������ ����������� �����
	if (this->dignity < 11) { // ���� ����������� ����� - �����
		std::cout << this->dignity << " ";
	}
	else { // ���� ����� � ���������� ������������ 
		switch (this->dignity) {
		case jack: // ���� �����
			std::cout << "����� ";
			break; 
		case queen: // ���� ����
			std::cout << "���� ";
			break;
		case king: // ���� ������
			std::cout << "������ ";
			break;
		case ace: // ���� ���
			std::cout << "��� ";
		}
	}
	// ���� ������ ����� �����
	switch (this->suit) { // ����� ����� �����
	case heart: // ���� ����� 
		std::cout << "������\n";
		break;
	case diamond: // ���� ����
		std::cout << "�����\n";
		break;
	case club: // ���� ������
		std::cout << "����\n";
		break;
	case spade: // ���� ����
		std::cout << "���\n";
	}
}

Card& Card::operator=(const Card& card) { // ��������� �������� ����� ����� ������
	this->dignity = card.dignity; // ��������� ����������� ����� 
	this->suit = card.suit; // ��������� �����
	return *this; // ���������� ����� ����� 
}

bool Card::operator==(const Card& card) { // �������� ��������� ���� ���� 
	if (this->dignity == card.dignity && this->suit == card.suit) { // ���� ���������� �����
		return true; // ��, ����� �����
	}
	else { // ���� ������ ����� 
		return false; // ���, ����� �� �����
	}
}

// class Deck
void Deck::deck_plus(Card*& deck, int& size) { // ���������� ������
	Card* buffer_deck = new Card[++size]; // ������ �������� ������ � ����������� ������������
	for (int i = 0; i < size - 1; i++) {
		buffer_deck[i] = deck[i]; // ���� �������� ����� �� ������� ������� 
	}
	delete[] deck; // ������� ������� ������ � �������
	deck = buffer_deck; // ������� ��������� �� �������� ������ ������ ������� 
}

void Deck::deck_minus(Card*& deck, int& size) { // ���������� ������
	Card* buffer_deck = new Card[--size]; // ������ �������� ������ � ����������� ������������
	for (int i = 0; i < size; i++) { 
		buffer_deck[i] = deck[i]; // ���� �������� ����� �� ������� �������
	}
	delete[] deck; // ������� ������� ������ � �������
	deck = buffer_deck; // ������� ��������� �� �������� ������ ������ �������
}

void Deck::take_card() { // ����� ����� � ������� 
	while (true) { // ���� �� ����� ������� �����, ������� ��� � ������
		Card new_card; // ������ �������� �����
		for (int i = 0; i < size; i++) { // ����� �� ������
			if (deck[i] == new_card) { // ���� ������� ����� � ������, ������� �� ����� �������� 
				break; // �������� ���� while ������
			}
			else if (i == size - 1) { // ���� �������� ����� �� ����� ���, ��� �� ����� ��������
				deck_plus(deck, size); // ��������� ������
				deck[i + 1] = new_card; // ����� ����� ����� � ������ � ����������� �����   
				return; // ��� ������ ������
			}
		}
	}
}

void Deck::give_card(const Card table_deck_card, int& card_ptr) { // ����� ����� �� ������ ������
	if (size > 1 || !(card_ptr == 51)) { 
		deck_plus(deck, size); // ��������� ������
	}
	deck[size - 1] = table_deck_card; // �������� ����� �� ������
	--card_ptr; // ��������� �������� ������ 
}

void Deck::show_deck() { // ����� ������
	for (int i = 0; i < size; i++) { // �������� ��������� �� ���� ������ � ������ 
		deck[i].show_card(); // ���������� ����� 
	}
}

void Deck::fill_deck_up_52() { // ������ ������ �� 52 �����
	for (int i = 0; i < 51; i++) { // ���������� ������ ����� �� 52 �����
		take_card(); // ���� ����� 
	}
}

int Deck::sum_dignity_bj() { // ������� ����� 
	int  sum = 0; // �������������� ����� 
	for (int i = 0; i < size; i++) { // ������� ����� ���������� ������
		if (deck[i].get_dignity() > 10) { // ���� �������� ����������� ���� ������ 10
			if (deck[i].get_dignity() == ace) { // ���� �������� � ����� 
				sum += 11;
			}
			else { // ���� �������� � �������, ����� � ������
				sum += 10;
			}
		}
		else { // ���� �������� ���������� ���� �������� 
			sum += deck[i].get_dignity();
		}
	}
	for (int i = 0; i < size; i++) { // ��������� ����������� ����
		if (sum > 21) { // ������� ��������� ����������� ����
			if (deck[i].get_dignity() == ace) { // ����� ����� ���
				sum -= 10; // ��������� ��������� ����������� ���� � 11 �� 1
			}
		}
		else { // ���� ����� �� ������ 21
			break; // ����� �� ����� 
		}
	}
	return sum; // ���������� �������������� ����� 
}

// class Hand
void Hand::show() { // ������� �������� 
	switch (form)
	{
	case rock: // ���� ������
		std::cout << "������\n";
		break;
	case scissors: // ���� �������
		std::cout << "�������\n";
		break;
	case paper: // ���� ������
		std::cout << "������\n";
	}
}

bool Hand::operator==(Hand& other_hand) { // �������� �� ��������� ��������
	return this->form == other_hand.form; 
}

bool Hand::operator>(Hand& other_hand) { // �������� �� ������������� ��������
	switch (this->form) {
	case rock: // ���� � ������ ������
		if (other_hand.form == scissors) { // � � ����� �������
			return true;
		}
		else { // � � ����� ������
			return false; // ����� ����������������, ���� � ����� ������
		}
	case scissors: // ���� � ������ �������
		if (other_hand.form == paper) { // � � ����� ������
			return true;
		}
		else { // � � ����� ������
			return false; // ����� ����������������, ���� � ����� �������
		}
	case paper: // ���� � ������ ������
		if (other_hand.form == rock) { // � � ����� ������
			return true;
		}
		else { // � � ����� �������
			return false; // ����� ����������������, ���� � ����� ������
		}
	}
}