#pragma once
#include <iostream> // для ввода/вывода
#include <ctime> // для рандома
#include <conio.h> // для _getche()

struct Gamer // параметры игрока 
{
	int money; // баланс
	int debt; // долг
	int wins; // количество побед
	int loses; // количество проигрышей 

	void show_data(); // показывает даныне структуры
	Gamer(); // создание нового игрока с нулевыми параметрами
};

enum high_dignity { jack = 11, queen, king, ace }; // перечисление особых достоинств карт - альтернативное определение констант
enum card_suit { heart = 0, diamond, club, spade }; // перечисление мастей карт

class Card // класс игральной карты
{
	card_suit suit; // масть карты
	int dignity; // достоинство карты

public:
	Card(); // создание рандомной карты
	int get_dignity() { // получение достоинства карты 
		return this->dignity;
	}
	void show_card(); // показ карты
	Card& operator=(const Card& card); // присвание значений одной карты другой
	bool operator==(const Card& card); // проверка равенства двух карт 
};

class Deck //класс колоды игральных карт
{
private:
	int size = 1; // размер колоды
	Card* deck = new Card[size]; // имитация колоды 

	void deck_plus(Card*& deck, int& size); // увеличение колоды
	void deck_minus(Card*& deck, int& size); // уменьшение колоды

public:
	void take_card(); // взять карту с воздуха
	void give_card(const Card table_deck_card, int& card_ptr); // Взять карту из другой колоды
	void show_deck(); // вывод колоды
	void fill_deck_up_52(); // полная колона на 52 карты  
	int sum_dignity_bj(); // подсчёт суммы 
	Card& operator[](const int iterator) { // для обращения к карте в колоде через итератор 
		return deck[iterator]; // созвращаем карту
	}
	~Deck() { // уничтожалем колоду
		delete[] deck; // очищаем массив
	}
};

class double_dices // класс парных костей
{
	int white_dice; // белая кость
	int black_dice; // чёрная кость

public:
	double_dices() { // имитация броска костей
		this->white_dice = (rand() % 6) + 1; // значение белой кости
		this->black_dice = (rand() % 6) + 1; // значение чёрной кости
	}
	void show_dices() { // показ результата броска костей 
		std::cout << "Чёрная кость = " << black_dice << std::endl
			<< "Белая кость = " << white_dice << std::endl;
	}
	int get_white_dice() { // показ значение белой кости 
		return white_dice;
	}
	int get_black_dice() { // показ значения чёрной кости
		return black_dice;
	}
};

enum hand_form { rock = 0, scissors, paper }; // камень - ножницы - бумага 

class Hand // для игры камень-ножницы-бумага
{
	hand_form form;

public:
	Hand() { // рандомно создаём действие 
		this->form = hand_form(rand() % 3);
	}
	Hand(hand_form form) { // передаём действие 
		this->form = form;
	}
	void show(); // показываем действие 
	bool operator==(Hand& other_hand); // проверяемя на равенство действие 
	bool operator>(Hand& other_hand); // сравниваем действие 
};