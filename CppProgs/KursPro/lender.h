#pragma once

struct lander // стркуктра данных о стране 
{
	unsigned int index; // индекс для индексных файлов и некторой работы с массивом (4 символа)
	char Name[26]; // название страны
	char HauptStadt[26]; // название столицы
	unsigned int Nas; // численность населения
	unsigned int Terr; // площадь страны
	char VAL[4]; // код валюты страны
	unsigned int Nas_pro_Terr; // рассчитываемое поле - плотность населения
};