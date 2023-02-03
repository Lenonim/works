#pragma once
#include "classes_for_casino.h" // для использования данных о игроке 

void money_status(Gamer& player); // просмотр баланса
void credit(Gamer& player); // пополнение баланса 
void debt_status(Gamer& player); // просмотр долгов
void data_status(Gamer& player); // просмотр статистики игрока
bool collectors(Gamer& player); // атака коллекторов 
bool money_controle(const int money); // контроль баланса во время игры 