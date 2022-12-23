#pragma once
#include "lender.h" // подключение структуры

void SortieranDaten(lander*& land , int& Kapazitat); // сортировка
int HeranSortierung(lander*& land , int i, int j); // прямой ход сортировки
void ZuruckSortierung(lander*& land , int& Kapazitat); // обратный ход сортировки
void SortierungNachVeranderungen(lander*& land , int& K); // изденение индексно-бинарных файлов