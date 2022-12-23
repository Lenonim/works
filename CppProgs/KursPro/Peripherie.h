#pragma once
#include "lender.h" // подключение структуры

void Schreiben(lander*& land , int i); // функция вывода элементов массива на экран
void Wartung(); // функция организации задержки и выхода в меню
void Prufung(); // реакция на неверно ведённые данные 
void Mutze(); // прось шапки таблицы
void KorrigierenDaten(char Zeitspanne[], int gang); // корректировка вводимых данных