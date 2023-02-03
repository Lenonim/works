#include "Bank.h" // для связи проектов 

void credit_help(Gamer& player, int power_credit); // расчёт пополнения

void money_status(Gamer& player) // просмотр состояния баланса
{
	char step; // для хода по меню
	while (true) { // пока не будет выбран пунтк выхода из меню 
		system("cls");
		std::cout << "Баланс: " << player.money << std::endl // меню баланса
 			<< "1 - Пополнить баланс\n"
			<< "2 - Статус долгов\n"
			<< "0 - Вернуться в главное меню\n"
			<< "Выберите один из вариантов: ";
		step = _getche(); // вводим пункт меню
		switch (step) {
		case '1':
			credit(player); // организация пополнения баланса 
			break; // в меню баланса
		case '2':
			debt_status(player); // организация погашения долгов
			break; // в меню баланса 
		case '0': // этот case есть, чтобы предотвратить попадение в default при выборе пункта меню
			return; // выход в главное меню
		default: // защита от дураков или случаной ошибки
			std::cout << "\nТакого варианта нет, попробуйте ещё раз\n";
			system("pause");
			break; // возврат в меню баланса
		}
	}
}

void credit(Gamer& player) // пополнение баланса 
{
	char step; // для выбора пунтка меню
	while (true) { // пока не будет указан пункт выхода из меню
		system("cls");
		std::cout << "Меню пополнения (процент долгов зависит от побед):\n" // меню пополнения
			<< "1 - должок (100)\n"
			<< "2 - долг (250)\n"
			<< "3 - кредит в банке (500)\n"
			<< "4 - расписка с мафией (1000)\n"
			<< "5 - закладная (1500)\n"
			<< "6 - сделка с дьяволом (2000)\n"
			<< "0 - возврат \n"
			<< "Выберите один из вариантов: ";
		step = _getche(); // выбор пунтка меню
		switch (step) {
		case '0': return; // выход в меню баланса
		case '1': // пополение на 100
			credit_help(player, 100);
			return; // выход в меню баланса
		case '2': // пополнение на 250
			credit_help(player, 250);
			return; // выход в меню баланса
		case '3': // пополнение на 500
			credit_help(player, 500);
			return; // выход в меню баланса
		case '4': // пополнение на 1000
			credit_help(player, 1000);
			return; // выход в меню баланса
		case '5': // пополнение на 1500
			credit_help(player, 1500);
			return; // выход в меню баланса
		case '6': // пополнение на 2000
			credit_help(player, 2000);
			return; // выход в меню баланса
		default: // защита от дурака или случайной ошибки
			std::cout << "\nТакого варианта нет, попробуйте ещё раз\n";
			system("pause");
			break; // в меню пополнения
		}
	}
}

void debt_status(Gamer& player) // показание состояние долгов 
{
	if (!player.debt) { // если долг равен 0
		std::cout << "\nУ вас нет долгов\n";
		system("pause");
		return; // возврат в главное меню
	}
	else { // если долги есть
		char step; // шаги по меню
		while (true) {
			system("cls");
			std::cout << "Ваши долги: " << player.debt << std::endl // меню долгов
				<< "1 - Погасить долги\n"
				<< "2 - Вернуться в меню баланса\n"
				<< "Выберите один из вариантов: ";
			step = _getche(); // выбор пунтка меню
			switch (step) {
			case '1': // процесс погашения долгов 
				int return_debt; // сумма погашения 
				while (true) {
					system("cls");
					std::cout << "Ваш баланс: " << player.money << std::endl // процесс погашения
						<< "Ваши долги: " << player.debt << std::endl
						<< "для возврата в меню статуса долгов введите 0\n"
						<< "Введите сумму погашения долга и нажмите Enter: ";
					std::cin >> return_debt; // ввод суммы погашения 
					if (return_debt == 0) return; // елси указал 0, то в меню баланса 
					if (return_debt < 0) { // если введено отрицательное число 
						std::cout << "Вы ввели отрицательное число!\n";
						continue; // в процесс погашения 
					}
					if (return_debt <= player.money) { // если введена сумма меньшая либо равная балансу игрока
						if (return_debt > player.debt) { // если введена сумма превосходящая сам долг
							player.money -= player.debt; // уменьшаяем баланс ровно на сам долг
							player.debt = 0; // обнуляем долги
						}
						else { // если введена сумма не превосходящая сам долг 
							player.debt -= return_debt; // уменьшаем баланс на сумму погашения 
							player.money -= return_debt; // уменьшаем сам долг на сумму погашения
						}
						if (player.debt == 0) std::cout << "Долги погашены!\n"; // если долги погашены
						else std::cout << "Остаток долгов: " << player.debt << std::endl; // если остались доги
						system("pause");
						return; // в меню баланса
					}
					else { // если введена сумма превосходящая баланс игрока
						std::cout << "У вас недостаточно средств!\n";
						system("pause");
						continue; // в процесс погашения долгов
					}
				}
				break; // в начало цикла 
			case '2': return; // выход в меню баланса
			default:
				std::cout << "\nТакого варианта нет, попробуйте ещё раз\n";
				system("pause");
			}
		}
	}
}

void data_status(Gamer& player) { // статистика игрока
	system("cls");
	player.show_data(); // просмотр статистики
	system("pause");
}

bool collectors(Gamer& player) // симуляция коллекторов
{
	if (player.debt > 20000) { // условие "смерти"
		player.debt = player.money = player.wins = 0; // обнуление данных
		system("cls");
		std::cout << "Вы накопили слишком большие долги (более 20000) и к вам пришли коллекторы!!!"
			<< "\nВы проиграли!!! Ваши данные обнулены\n"; // объявление об обнулении 
		system("pause");
		return true; // да, у игрока проблемы 
	}
	else return false; // нет, у игрока нет проблем 
}

bool money_controle(const int player_money)
{
	if (player_money <= 0) { // у игрока ещё есть деньги 
		system("cls");
		std::cout << "\nУ вас недостаточно средст, чтобы продолжать игу!\n";
		system("pause");
		return true; // да, у игрока проблемы
	}
	else return false; // нет, у игрока нет проблем 
}

void credit_help(Gamer& player, int power_credit) // расчёт пополнения 
{
	std::cout << "\nваш баланс увеличился на " << power_credit << std::endl; // сумма пополнения 
	player.money += power_credit; // непосредственное пополнения
	player.debt += power_credit + int(power_credit * 0.1); // расчёт долга
	if (int(player.wins / 10) < power_credit) player.debt += int(player.wins / 10); // процент от побед
	else player.debt += power_credit; // максимальный процент от побед (не должен превышать сумму пополения)
	collectors(player); // проревка пиковой суммы долгов 
	system("pause");
}