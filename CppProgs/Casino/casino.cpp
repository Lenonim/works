#include "Bank.h" // для пополнения баланса и погашения долгов
#include "casino_games.h" // для полдключени игр
#include "safe_and_load_data.h" // для загрузки или сохранения данных

Gamer player; // баланс, долг и победы игрока
void((*way_casino[7]))(Gamer& player) = // массив указателей на функцию 
    { dice_game, black_jack_game, ropascis, // игры
    money_status, data_status, safe_data, load_data }; // работа с данными 

int main() {
    char step; // для выбора пункта меню 
    while (true) { // удержание в меню
        system("cls");
        std::cout << "Баланс: " << player.money << std::endl << "Главное меню:\n" // главное меню
            << "1 - Кости\n"
            << "2 - Блэкджек\n"
            << "3 - Камень-ножницы-бумага\n"
            << "4 - Баланс\n"
            << "5 - Статистика\n"
            << "6 - Сохранить прогресс\n"
            << "7 - Загрузить сохранение\n"
            << "0 - Выход из казино\n"
            << "Выберите один из вариантов: ";
        step = _getche(); // вводим пунтк меню
        if (step == '0') return 0; // выход из казино 
        else if (step > 48  && step < 56) way_casino[int(step - 49)](player); // разлёт по функциям 
        else { // защита от дураков или случайной ошибки
            std::cout << "\nТакого варианта нет, попробуйте ещё раз\n";
            system("pause"); // возврат в главное меню
        }
    }
}