#pragma once
#include <iostream> // ��� �����/������
#include <ctime> // ��� �������
#include <conio.h> // ��� _getche()

struct Gamer // ��������� ������ 
{
	int money; // ������
	int debt; // ����
	int wins; // ���������� �����
	int loses; // ���������� ���������� 

	void show_data(); // ���������� ������ ���������
	Gamer(); // �������� ������ ������ � �������� �����������
};

enum high_dignity { jack = 11, queen, king, ace }; // ������������ ������ ���������� ���� - �������������� ����������� ��������
enum card_suit { heart = 0, diamond, club, spade }; // ������������ ������ ����

class Card // ����� ��������� �����
{
	card_suit suit; // ����� �����
	int dignity; // ����������� �����

public:
	Card(); // �������� ��������� �����
	int get_dignity() { // ��������� ����������� ����� 
		return this->dignity;
	}
	void show_card(); // ����� �����
	Card& operator=(const Card& card); // ��������� �������� ����� ����� ������
	bool operator==(const Card& card); // �������� ��������� ���� ���� 
};

class Deck //����� ������ ��������� ����
{
private:
	int size = 1; // ������ ������
	Card* deck = new Card[size]; // �������� ������ 

	void deck_plus(Card*& deck, int& size); // ���������� ������
	void deck_minus(Card*& deck, int& size); // ���������� ������

public:
	void take_card(); // ����� ����� � �������
	void give_card(const Card table_deck_card, int& card_ptr); // ����� ����� �� ������ ������
	void show_deck(); // ����� ������
	void fill_deck_up_52(); // ������ ������ �� 52 �����  
	int sum_dignity_bj(); // ������� ����� 
	Card& operator[](const int iterator) { // ��� ��������� � ����� � ������ ����� �������� 
		return deck[iterator]; // ���������� �����
	}
	~Deck() { // ����������� ������
		delete[] deck; // ������� ������
	}
};

class double_dices // ����� ������ ������
{
	int white_dice; // ����� �����
	int black_dice; // ������ �����

public:
	double_dices() { // �������� ������ ������
		this->white_dice = (rand() % 6) + 1; // �������� ����� �����
		this->black_dice = (rand() % 6) + 1; // �������� ������ �����
	}
	void show_dices() { // ����� ���������� ������ ������ 
		std::cout << "׸���� ����� = " << black_dice << std::endl
			<< "����� ����� = " << white_dice << std::endl;
	}
	int get_white_dice() { // ����� �������� ����� ����� 
		return white_dice;
	}
	int get_black_dice() { // ����� �������� ������ �����
		return black_dice;
	}
};

enum hand_form { rock = 0, scissors, paper }; // ������ - ������� - ������ 

class Hand // ��� ���� ������-�������-������
{
	hand_form form;

public:
	Hand() { // �������� ������ �������� 
		this->form = hand_form(rand() % 3);
	}
	Hand(hand_form form) { // ������� �������� 
		this->form = form;
	}
	void show(); // ���������� �������� 
	bool operator==(Hand& other_hand); // ���������� �� ��������� �������� 
	bool operator>(Hand& other_hand); // ���������� �������� 
};