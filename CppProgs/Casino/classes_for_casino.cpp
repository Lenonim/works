#include <iomanip> // для setw()
#include "classes_for_casino.h" // для связи с классами, чтобы можно было выносить их методы сюда

// struct Gamer
void Gamer::show_data() { // показывает даныне структуры 
	std::cout << "Баланс: " << std::setw(12) << this->money << std::endl // вывод баланса
		<< "Долг: " << std::setw(14) << this->debt << std::endl // вывод долга
		<< "Победы: " << std::setw(12) << this->wins << std::endl // вывод количества побед
		<< "Проигрыши: " << std::setw(9) << this->loses << std::endl // вывод количества проигрышей 
		<< "Процент побед: "; 
	if (loses + wins == 0) { // если нет ни побед, ни проигрышей 
		std::cout << std::setw(5) << 0 << std::endl;
	}
	else { // если есть победы и/или проигрыши
		std::cout << std::setw(4) << int((float(wins) / float(loses + wins)) * 100) <<'%'<< std::endl;
	}
}

Gamer::Gamer() { // создание нового игрока с нулевыми параметрами 
	money = 100; // стартовый баланса игрока 
	debt = 0; // долги игрока 
	wins = 0; // количество побед игрока 
	loses = 0; // количество проигрышей игрока 
	setlocale(LC_ALL, "Russian"); // подключаем кириллицу
	std::cout << "Добро пожаловать в Казино!\n" // приветствие в казино
		<< "Ваш стартовый капитал составляет: " << money << std::endl;
	system("pause");
}

// class Card
Card::Card() { // создание рандомной карты
	this->suit = card_suit(rand() % 4); // создание масти карты
	this->dignity = rand() % 13 + 2; // создание достоинства от 2 до туза
}

void Card::show_card() { // показ карты
	// блок показа достоинства карты
	if (this->dignity < 11) { // если достоинство карты - число
		std::cout << this->dignity << " ";
	}
	else { // если карта с нечисловым достоинством 
		switch (this->dignity) {
		case jack: // если валет
			std::cout << "валет ";
			break; 
		case queen: // если дама
			std::cout << "дама ";
			break;
		case king: // если король
			std::cout << "король ";
			break;
		case ace: // если туз
			std::cout << "туз ";
		}
	}
	// блок показа масти карты
	switch (this->suit) { // показ масти карты
	case heart: // если червы 
		std::cout << "червей\n";
		break;
	case diamond: // если буби
		std::cout << "бубей\n";
		break;
	case club: // если крести
		std::cout << "треф\n";
		break;
	case spade: // если пики
		std::cout << "пик\n";
	}
}

Card& Card::operator=(const Card& card) { // присвание значений одной карты другой
	this->dignity = card.dignity; // принимаем достоинство карты 
	this->suit = card.suit; // принимаем масть
	return *this; // возвращаем новую карту 
}

bool Card::operator==(const Card& card) { // проверка равенства двух карт 
	if (this->dignity == card.dignity && this->suit == card.suit) { // если одинаковые карты
		return true; // да, карты равны
	}
	else { // если разные карты 
		return false; // нет, карты не равны
	}
}

// class Deck
void Deck::deck_plus(Card*& deck, int& size) { // увеличение колоды
	Card* buffer_deck = new Card[++size]; // создаём буферный массив с расширенной размерностью
	for (int i = 0; i < size - 1; i++) {
		buffer_deck[i] = deck[i]; // берём значения карты из старого массива 
	}
	delete[] deck; // очищаем страный массив с картами
	deck = buffer_deck; // передаём указатель на буферный массив нашему массиву 
}

void Deck::deck_minus(Card*& deck, int& size) { // уменьшение колоды
	Card* buffer_deck = new Card[--size]; // создаём буферный массив с уменьшенной размерностью
	for (int i = 0; i < size; i++) { 
		buffer_deck[i] = deck[i]; // берём значения карты из старого массива
	}
	delete[] deck; // очищаем страный массив с картами
	deck = buffer_deck; // передаём указатель на буферный массив нашему массиву
}

void Deck::take_card() { // взять карту с воздуха 
	while (true) { // пока не будет создана карта, которой нет в колоде
		Card new_card; // создаём рандомну карту
		for (int i = 0; i < size; i++) { // бежим по колоде
			if (deck[i] == new_card) { // если найдена карта в колоде, которую мы хотим добавить 
				break; // начинаем цикл while заново
			}
			else if (i == size - 1) { // если последня карта не равна той, что мы хотим добавить
				deck_plus(deck, size); // расширяем колоду
				deck[i + 1] = new_card; // ложим новую карту в колоду в появившеяся место   
				return; // идём играть дальше
			}
		}
	}
}

void Deck::give_card(const Card table_deck_card, int& card_ptr) { // Взять карту из другой колоды
	if (size > 1 || !(card_ptr == 51)) { 
		deck_plus(deck, size); // расширяем колоду
	}
	deck[size - 1] = table_deck_card; // забираем карту из колоды
	--card_ptr; // уменьшаем итератор колоды 
}

void Deck::show_deck() { // вывод колоды
	for (int i = 0; i < size; i++) { // механизм обращения ко всем картам в колоде 
		deck[i].show_card(); // показываем карту 
	}
}

void Deck::fill_deck_up_52() { // полная колона на 52 карты
	for (int i = 0; i < 51; i++) { // заполнение колоды банка на 52 карты
		take_card(); // берём карту 
	}
}

int Deck::sum_dignity_bj() { // подсчёт суммы 
	int  sum = 0; // результирующая сумма 
	for (int i = 0; i < size; i++) { // считаем сумму достоинтсв колоды
		if (deck[i].get_dignity() > 10) { // если значение достоинства карт больше 10
			if (deck[i].get_dignity() == ace) { // если работаем с тузом 
				sum += 11;
			}
			else { // если работаем с вальтом, дамой и королём
				sum += 10;
			}
		}
		else { // если значение достоинств карт числовое 
			sum += deck[i].get_dignity();
		}
	}
	for (int i = 0; i < size; i++) { // понижение достоинства туза
		if (sum > 21) { // условие понижения достоинства туза
			if (deck[i].get_dignity() == ace) { // когда нашли туз
				sum -= 10; // имитируем понижение достоинства туза с 11 до 1
			}
		}
		else { // если сумма не больше 21
			break; // выход из цикла 
		}
	}
	return sum; // возвращаем результирующую сумму 
}

// class Hand
void Hand::show() { // выводим действие 
	switch (form)
	{
	case rock: // если камень
		std::cout << "камень\n";
		break;
	case scissors: // если ножницы
		std::cout << "ножницы\n";
		break;
	case paper: // если бумага
		std::cout << "бумага\n";
	}
}

bool Hand::operator==(Hand& other_hand) { // првоерка на равенство действий
	return this->form == other_hand.form; 
}

bool Hand::operator>(Hand& other_hand) { // проверка на превосходство действий
	switch (this->form) {
	case rock: // если у игрока камень
		if (other_hand.form == scissors) { // а у банка ножницы
			return true;
		}
		else { // а у банка бумага
			return false; // также предусматиривает, если у банка камень
		}
	case scissors: // если у игрока ножницы
		if (other_hand.form == paper) { // а у банка бумага
			return true;
		}
		else { // а у банка камень
			return false; // также предусматиривает, если у банка ножницы
		}
	case paper: // если у игрока бумага
		if (other_hand.form == rock) { // а у банка камень
			return true;
		}
		else { // а у банка ножницы
			return false; // также предусматиривает, если у банка бумага
		}
	}
}