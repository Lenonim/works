#include <fstream> // для чтения/записи потоков данных  
#include "safe_and_load_data.h" // связь с хедером

std::fstream fs; // объект работы с файлом
std::string path; // объект пути файла

std::string get_path() // выбор слота сохранения
{
	char step; // для выбора слота 
	while (true) { // пока не будет указан пункт выхода или слота
		system("cls");
		std::cout << "Слоты памяти:\n" // меню выбора слота 
			<< "1 - первый\n"
			<< "2 - второй\n"
			<< "3 - третий\n"
			<< "4 - четвёртый\n"
			<< "5 - пятый\n"
			<< "6 - шествой\n"
			<< "7 - седьмой\n"
			<< "8 - восьмой\n"
			<< "9 - девятый\n"
			<< "0 - выход\n"
			<< "Выбирите слот памяти: ";
		step = _getche(); // ввод пункта слота
		switch (step) {
		case '1': // получение имени первго слота
			return "first_saveslot";
		case '2': // получение имени второго слота
			return "second_saveslot";
		case '3': // получение имени третьего слота
			return "third_saveslot";
		case '4': // получение имени четвёртого слота 
			return "fourth_saveslot";
		case '5': // получение имени пятого слота
			return "fifth_saveslot";
		case '6': // получение имени шестого слота
			return "sith_saveslot";
		case '7': // получение имени седьмого слота
			return "seventh_saveslot";
		case '8': // получение имени восьмого слота
			return "eighth_saveslot";
		case '9': // получение имени девятого слота
			return "nineth_saveslot";
		case '0': // организация выхода
			return "nun";
		default: // защита от дурака иди случайной ошибки
			std::cout << "\nТакого варианта нет, попробуйте ещё раз\n";
			system("pause");
			break; // возврат в меню
		}
	}
}

void safe_data(Gamer& player) // сохранения данных
{
	path = get_path(); // выбор слота сохранения
	if (path == "nun") { // если пользователь не захотел выбирать слот
		return; // выход в главное меню
	}
	else { // когда слот выбран
		fs.open(path, std::fstream::out); // открываем поток для записи / создаём слот 
		fs.write((char*)&player, sizeof(Gamer)); // сохраняем параметры игрока
		std::cout << "\nДанные cохранены!\n";
		fs.close(); // закрываем поток
		system("pause");
	}
}

void load_data(Gamer& player) // сохранение данных 
{
	while (true) {
		path = get_path(); // выбор слота сохранения 
		if (path == "nun") { // если пользователь не захотел выбирать слот
			return; // выход в главное меню 
		}
		else { // когда слот выбран
			fs.open(path, std::fstream::in); // открываем поток для считывания 
			if (fs.is_open()) { // если файл открыт 
				fs.read((char*)&player, sizeof(Gamer)); // сохраняем деньги
				std::cout << "\nСохранение загружено!\n";
				system("pause");
			}
			else { // если файл не открыт 
				std::cout << "\nСлот не найден!\n";
				system("pause");
				continue; // снова получаем слот
			}
			fs.close(); // закрываем поток 
			return; // выход в главное меню
		}
	}
}