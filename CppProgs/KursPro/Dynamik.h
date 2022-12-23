#pragma once
#include "lender.h" // подключение структуры

void AddierenDaten(lander*& land, int& Kapazitat); // добавление записей
void SubstragierenDaten(lander*& land, int& Kapazitat); // удаление записей 
void UmSreibenData(lander*& land, int& Kapazitat); // редактирвоание записей 
void LesenDaten(lander*& land, int& Kapazitat); // получение исходных данных
void SpeichernDatenInTextFile(lander*& land, int& Kapazitat); // для сохранения данных в текствоый файл
void VeranderungZahlDaten(lander*& land, int& Kapazitat, int delta); // для изменение размерности динамического массива
void SpeichernDatenInBinFile(lander*& land, int& Kapazitat); // для сохранения данных в бинарный файл