#include "casino_games.h" // для нормального функционирования
#include "Bank.h" // для коллекторов

//////////////////////////////////// общий функционал ////////////////////////////////////

void table_money_ctrl(int& table_money, const int money) { // ставим ставку 
	do { // запрос на ставку
		system("cls");
		std::cout << "Ваш баланс = " << money << std::endl
			<< "Укажите ставку и нажмите Enter (для выхода в главное меню введите 0): ";
		std::cin >> table_money; // указание ставки 
	} while (table_money < 0 || table_money > money); // пока не будет введена корректная ставка
}
void win_in_game(Gamer& player, int table_money, float k) { // победа в игре 
	std::cout << "Вы победили!!!\n" // объявление о победе
		<< "Ваш выигрыш = " << (int)(table_money * k); // объявление суммы выигрыша 
	std::cout << std::endl;
	player.money += table_money * k; // повышение баланса выигрышем  
	player.wins++; // повышение числа побед
	system("pause");
}
void lose_in_game(Gamer& player, int table_money) { // проигрыш в игре
	std::cout << "Вы проиграли!!!\n" // объявление о победе
		<< "Ваш проигрыш = " << table_money; // объявлоение суммы проигрыша 
	player.money -= table_money; // уменьшение баланса проигрышем 
	player.loses++; // увеличение числа побед 
	std::cout << std::endl;
	system("pause");
}

//////////////////////////////////// Dices ////////////////////////////////////

void dice_game(Gamer& player) { // игра в кости 
	srand(time(NULL)); // для рандома
	if (player.money > 0) { // если есть деньги для игры 
		int table_money; // для ставки
		char step; // шаги по меню
			while (true) { // удержание в игре
				table_money_ctrl(table_money, player.money); // ввод ставки 
				if (!table_money) { // если нулевая ставка 
					return; // выход в главное меню
				}
				system("cls");
				std::cout << "Выберите пункт ставки:\n" // вывод меню ставок 
					<< "1 - Оба варианта чётные (k = 1)\n"
					<< "2 - Оба варианта нечёртные (k = 1)\n"
					<< "3 - Один вариант чётный, другой - нечётный (k = 1)\n"
					<< "4 - Дубляж (k = 6)\n"
					<< "5 - Cумма не больше 6 (k = 1.5)\n"
					<< "6 - Cумма больше 6 (k = 1.5)\n"
					<< "0 - Выход в главное меню\n"
					<< "Выберите один из пунктов: ";
				step = _getche(); // ввод пункта меню
				double_dices table_dices; // бросок кубиков 
				switch (step) {
				case '1': // чётные варианты 
					system("cls");
					table_dices.show_dices(); // показ костей 
					if ((table_dices.get_black_dice() % 2 == 0) && (table_dices.get_white_dice() % 2 == 0)) {// условие победы
						win_in_game(player, table_money, 1); // победа
					}
					else {
						lose_in_game(player, table_money); // проигрыш 
						if (money_controle(player.money) || collectors(player)) {// проверка баланса и долгов
							return; // выход в главное меню
						}
					}
					break;
				case '2': // нечётные варианты 
					system("cls");
					table_dices.show_dices(); // показ костей 
					if ((table_dices.get_black_dice() % 2 == 1) && (table_dices.get_white_dice() % 2 == 1)) {// условие победы
						win_in_game(player, table_money, 1); // победа
					}
					else {
						lose_in_game(player, table_money); // проигрыш 
						if (money_controle(player.money) || collectors(player)) {// проверка баланса и долгов
							return; // выход в главное меню
						}
					}
					break;
				case '3': // один чётный, другой нечётный
					system("cls");
					table_dices.show_dices(); // показ костей 
					if (((table_dices.get_black_dice() % 2 == 0) && (table_dices.get_white_dice() % 2 == 1))
						|| ((table_dices.get_black_dice() % 2 == 1) && (table_dices.get_white_dice() % 2 == 0))) {// условие победы
						win_in_game(player, table_money, 1); // победа
					}
					else {
						lose_in_game(player, table_money); // проигрыш 
						if (money_controle(player.money) || collectors(player)) {// проверка баланса и долгов
							return; // выход в главное меню
						}
					}
					break;
				case '4': // дубляж
					system("cls");
					table_dices.show_dices(); // показ костей 
					if (table_dices.get_black_dice() == table_dices.get_white_dice()) {// условие победы
						win_in_game(player, table_money, 6); // победа
					}
					else {
						lose_in_game(player, table_money); // проигрыш 
						if (money_controle(player.money) || collectors(player)) {// проверка баланса и долгов
							return; // выход в главное меню
						}
					}
					break;
				case '5': // сумма не больше 6
					system("cls");
					table_dices.show_dices(); // показ костей 
					if ((table_dices.get_black_dice() + table_dices.get_white_dice()) <= 6) {// условие победы
						win_in_game(player, table_money, 1.5); // победа
					}
					else {
						lose_in_game(player, table_money); // проигрыш 
						if (money_controle(player.money) || collectors(player)) {// проверка баланса и долгов
							return; // выход в главное меню
						}
					}
					break;
				case '6': // сумма больше 6
					system("cls");
					table_dices.show_dices(); // показ костей 
					if ((table_dices.get_black_dice() + table_dices.get_white_dice()) > 6) {// условие победы
						win_in_game(player, table_money, 1.5); // победа
					}
					else {
						lose_in_game(player, table_money); // проигрыш 
						if (money_controle(player.money) || collectors(player)) { // проверка баланса и долгов
							return; // выход в главное меню
						}
					}
					break;
				case '0': // организация выхода из игры
					return; // выход в главное меню 
				default:
					std::cout << "\nТакого варианта нет, попробуйте ещё раз\n";
					system("pause");
				}
			}
	}
	else { // если нет денег для игры
		std::cout << "\nУ вас недостаточно средств!\n";
		system("pause");
		return; // возврат в главное меню 
	}
}

//////////////////////////////////// Blackjack ////////////////////////////////////

void black_jack_game(Gamer& player) { // игра в блэкджек
	srand(time(NULL)); // для рандома
	if (player.money > 0) { // если есть деньги
		while (true) {
			int table_money; // для ставки
			char first_step, second_step; // шаги
			table_money_ctrl(table_money, player.money); // ввод ставки
			if (!table_money) { // если нулевая ставка 
				return; // возврат в главное меню
			}
			Deck table_deck; // колода банка
			table_deck.fill_deck_up_52(); // заполняем рандомно колоду на 52 карты
			int card_ptr = 51; // счётчик взятых у банка карт 
			Deck my_deck; // колода игрока
			my_deck.give_card(table_deck[card_ptr], card_ptr); // забираем первую карту колоды
			my_deck.give_card(table_deck[card_ptr], card_ptr); // забираем вторую карту колоды
			while (true) {
				system("cls");
				std::cout << "Ваши карты:\n";
				my_deck.show_deck(); // показывает карты на руках игрока 
				std::cout << "счёт: " << my_deck.sum_dignity_bj() << "\n\n"; // подсчёт суммы достоинств карт
				std::cout << "ещё? (y or n) "; // нужна ли ещё карта?
				second_step = _getche(); // ответ на вышепоставленный вопрос
				if (second_step == 'y') { // да, нужна ещё карта, пока ходит игрок
					my_deck.give_card(table_deck[card_ptr], card_ptr); // забираем карты из колоды
					if (my_deck.sum_dignity_bj() > 21) { // если перебор
						system("cls");
						std::cout << "Ваши карты:\n";
						my_deck.show_deck(); // показываем колоду 
						std::cout << "счёт: " << my_deck.sum_dignity_bj() << "\n\n"; // подсчёт суммы достоинств карт
						std::cout << "Перебор!!! "; // объявление проигрыша
						lose_in_game(player, table_money); // расчёт проигрыша
						if (money_controle(player.money) || collectors(player)) { // проверка баланса и долгов
							return; // выход в главное меню
						}
						break; // конец игры 
					}
					else if (my_deck.sum_dignity_bj() == 21) { // если выпал блэкджэк 
						system("cls");
						std::cout << "Ваши карты:\n";
						my_deck.show_deck(); // показываем колоду
						std::cout << "счёт: " << my_deck.sum_dignity_bj() << "\n\n"; // подсчёт суммы достоинств карт
						std::cout << "БЛЭКДЖЭК!!! ";
						win_in_game(player, table_money, 2); // расчёт победы 
						break; // конец игры 
					}
				}
				else if (second_step == 'n') { // нет, больше карт не нужно, тогда ходит банк
					Deck bank_deck; // создаётся колода банка 
					bank_deck[0] = table_deck[card_ptr]; // забираем карту из колоды
					card_ptr--; // понищаем маркер с колоды
					bank_deck.give_card(table_deck[card_ptr], card_ptr); // банк берёт вторую карту
					while (bank_deck.sum_dignity_bj() <= my_deck.sum_dignity_bj()) { // имитация ии
						bank_deck.give_card(table_deck[card_ptr], card_ptr); // банк берёт карту из колоды, пока у банка не будет больше, чем у игрока
					}
					if (bank_deck.sum_dignity_bj() >= my_deck.sum_dignity_bj() && bank_deck.sum_dignity_bj() < 22) { // победа банка
						std::cout << std::endl << "\nКарты банка:" << std::endl;
						bank_deck.show_deck(); // показ карт банка
						std::cout << "счёт: " << bank_deck.sum_dignity_bj() << "\n\n"; // подсчёт суммы достоинств карт
						std::cout << "Банк набрал больше баллов!!! ";
						lose_in_game(player, table_money); // расёт проигрыша
						if (money_controle(player.money) || collectors(player)) { // проверка баланса и долгов
							return; // выход в главное меню
						}
						break; // конец игры
					}
					else if (bank_deck.sum_dignity_bj() > 21) { // проигрыш банка 
						std::cout << std::endl << "\nКарты банка:" << std::endl;
						bank_deck.show_deck(); // показ колоды банка
						std::cout << "счёт: " << bank_deck.sum_dignity_bj() << "\n\n"; // подсчёт суммы достоинств карт
						std::cout << "У Банка перебор!!! ";
						win_in_game(player, table_money, 1); // расчёт проигрыша 
						break; // конец игры 
					}
				}
				else { // защита от дураков или от случайной ошибки 
					std::cout << "У вас не верный ответ!\n";
					system("pause");
				}
			}
		}
	}
	else { // если денег нет
		std::cout << "\nУ вас недостаточно средств! \n";
		system("pause");
		return; // в главное меню 
	}
};

//////////////////////////////////// Ropascis ////////////////////////////////////

void ropascis(Gamer& player) { // игра в камень-ножницы-бумага
	srand(time(NULL)); // для рандома
	if (player.money > 0) { // если есть деньги 
		int table_money; // для ставки 
		char step; // шаг по меню 
		while (true) { // удерживание в игре
			table_money_ctrl(table_money, player.money); // ввод ставки
			if (!table_money) { // если нулевая ставка 
				return; // возврат в главное меню
			}
			std::cout << "Выберите действие:\n" // меню действий
				<< "1 - камень\n"
				<< "2 - ножницы\n"
				<< "3 - бумага\n"
				<< "Ответ: ";
			step = _getche(); // ответ
			if (step != '1' && step != '2' && step != '3') { // защита от дурака или случайной ошибки 
				std::cout << "\nНеверный ответ! Попробуйте ещё раз!\n";
				system("pause");
				continue; // в начало игры
			}
			Hand my_hand(hand_form(step - 49)), bank_hand; // действия игрока и банка
			std::cout << "\nВы выбрали: ";
			my_hand.show(); // ваше действие
			std::cout << "Банк выбрал: ";
			bank_hand.show(); // действие банка
			if (my_hand == bank_hand) { // если одинаковые действия 
				std::cout << "Ничья!\n"; // объявление ничьи 
				system("pause");
			}
			else if (my_hand > bank_hand) { // победа игрока
				win_in_game(player, table_money, 1); // расчёт победы и её объявление 
			}
			else { // победа банка
				lose_in_game(player, table_money); // расчёт проигрыша и его объявление
				if (money_controle(player.money) || collectors(player)) {// проверка баланса и долгов
					return; // выход в главное меню
				}
			}
		}
	}
	else { // если денег нет
		std::cout << "\nУ вас недостаточно средств! Вам необходимо пополнить баланс\n";
		system("pause");
		return; // в главное меню 
	}
}