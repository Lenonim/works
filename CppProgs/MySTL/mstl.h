#pragma once

#include <stdarg.h>

namespace hardstl
{

	//////////////////////////////////////////////////////////////////////////
	/*								строка									*/
	//////////////////////////////////////////////////////////////////////////

	class string
	{
		char* symbols;
	public:

	};

	//////////////////////////////////////////////////////////////////////////
	/*					одномерный динамический массив						*/
	//////////////////////////////////////////////////////////////////////////

	template<typename imitator> //  прямая - одномерный динамический массив 
	class straight 
	{
		int size; // размерность массива
		imitator* _array; // неспосредственно сам массив (указатель на его первый элемент)

		// блок extension
		void extension(const int position, const int quantity) { // расширяем массив
			imitator* bufer_array = new imitator[size + quantity]; // создаём буферный массив 
			for (int i = 0; i < size; i++) { // механизм переноса данных в буферный массив
				if (i >= position) // проверка позиции, после которой немобходимо добовлять элементы
					bufer_array[i + quantity] = _array[i]; // передача данных буферному массиву в смещённом варианте
				else // если не дошли ещё до необходимой позиции
					bufer_array[i] = _array[i]; // передача данных буферному массиву в штатном режиме
			}
			size += quantity; // увеличение размера массива на указанное количество элементов
			delete[] _array; // очистка из оперативной памяти данных исходного массива
			_array = bufer_array; // меняем указатель с оригинального массива на буферный массив
		}

		// блок reduction 
		void reduction(const int position, const int quantity) { // удаление некоторого числа элементов после позиции 
			imitator* bufer_array = new imitator[size - quantity]; // создаём буферный массив 
			for (int i = 0; i < size - quantity; i++) { // механизм переноса данных в буферный массив
				if (i >= position) // проверка позиции, после которой немобходимо удалить элементы
					bufer_array[i] = _array[i + quantity]; // передача данных буферному массиву в смещённом варианте
				else // если не дошли ещё до необходимой позиции
					bufer_array[i] = _array[i]; // передача данных буферному массиву в штатном режиме
			}
			size -= quantity; // уменьшение размера массива на указанное количество элементов
			delete[] _array; // очистка из оперативной памяти данных исходного массива
			_array = bufer_array; // меняем указатель с оригинального массива на буферный массив
		}

	public:

		// блок extension
		void to_end(imitator value) { // добавление нового элемента в конец массива
			extension(size, 1); // расширяем массив на один элемент после указанной позиции 
			_array[size - 1] = value; // заполняем пустой элемент
		}
		void to_begin(imitator value) { // добавление нового элемента в начало массива
			extension(0, 1); // расширяем массив на один элемент после указанной позиции 
			_array[0] = value; // заполняем пустой элемент
		}
		void to_position(imitator value, int position) { // добавление нового элемента в указанную позицию
			extension(position, 1); // расширяем массив на один элемент после указанной позиции 
			_array[position] = value; // заполняем пустой элемент
		}

		// блок reduction
		void out_end() { // удаление из конца 
			reduction(size - 1, 1); // удаляем последний элемент 
		}
		void out_begin() { // удаление из начала
			reduction(0, 1); //удаляем первый элемент
		}
		void out_position(int position) { // удаление по позиции
			reduction(position, 1); // удаляем элемент по позиции 
		}

		// функциональный блок
		int get_size() { // получение размерности массива
			return this->size; // возвращаем размерность
		}
		imitator& operator[](int iterator) { // обращение к элементам массива через объект класса
			return _array[iterator]; // возвращает элемент массива
		}

		// сахарный блок
		void mirror() { // отзеркаливает массив 
			for (int i = 0; i < (int)(size / 2); i++) // механизм swap
				std::swap(_array[i], _array[size - 1 - i]); // меняем местами значения элементов массива
		}
		void operator=(const straight<imitator>& Straight) { // присвоение другого объекта класса
			delete[] this->_array; // очинаем массив 
			this->size = Straight.size; // адаём новую размерность 
			_array = new imitator[Straight.size]; // выделяем новое место в памяти с новой размерностью
			for (int i = 0; i < Straight.size; i++) // механизм передачи данных 
				_array[i] = Straight._array[i]; // передаём данные из копируемого массива в копирующий массив
		}

		// конструкторы / деструктор
		straight(int size = 0) { // создание пустого массива с заданым количеством элементов 
			this->size = size; // задаём размерность 
			this->_array = new imitator[size]; // выделяем место в динамической памяти
		}
		~straight() { // удаляем массив 
			delete[] _array; // непосредственное удаление 
			size = 0; // нуль-размерность 
		}
	};

	//////////////////////////////////////////////////////////////////////////
	/*					двумерный динамический массив						*/
	//////////////////////////////////////////////////////////////////////////
	
	template<typename imitator> // плоскость - двумерный динамический массив
	class plane 
	{
		int rows; // количество рядов
		int columns; // количество столбцов
		imitator** _array; // сам массив (указатель на указатель на первый элемент первого ряда)

		// блок extension
		void vertical_extension(const int row_position, const int quantity) { // расширение по рядам
			imitator** bufer_array = new imitator * [rows + quantity]; //|
			for (int i = 0; i < rows + quantity; i++)                  //| создаём буферный двумерный массив
				bufer_array[i] = new imitator[columns];                //|
			for (int i = 0; i < rows; i++)         //| механизм переноса данных в буферный массив
				for (int j = 0; j < columns; j++)  //|
					if (i >= row_position) // проверка позиции
						bufer_array[i + quantity][j] = _array[i][j]; // передача данных буферному массиву в смещённом варианте
					else // если до необходимой позиции ещё не дошли
						bufer_array[i][j] = _array[i][j]; // передача данных буферному массиву в штатном режиме
			for (int i = 0; i < rows; i++) //|
				delete[] _array[i];        //| очистка из оперативной памяти данных исходного	двумерного массива 
			delete[] _array;               //| 
			rows += quantity; // увеличение количества рядов исходного массива
			_array = bufer_array; // меняем указатель с оригинального массива на буферный массив
		}
		void horizontal_extension(const int column_position, const int quantity) { // расширение по столбцам 
			imitator** bufer_array = new imitator * [rows];        //|
			for (int i = 0; i < rows; i++)                         //| создаём буферный двумерный массив
				bufer_array[i] = new imitator[columns + quantity]; //|
			for (int i = 0; i < rows; i++)        //| механизм переноса данных в буферный массив
				for (int j = 0; j < columns; j++) //|
					if (j >= column_position)
						bufer_array[i][j + quantity] = _array[i][j]; // передача данных буферному массиву в смещённом варианте
					else // если до необходимой позиции ещё не дошли
						bufer_array[i][j] = _array[i][j]; // передача данных буферному массиву в штатном режиме
			for (int i = 0; i < rows; i++) //|
				delete[] _array[i];        //| очистка из оперативной памяти данных исходного	двумерного массива 
			delete[] _array;               //| 
			columns += quantity; // увеличение количества рядов исходного массива
			_array = bufer_array; // меняем указатель с оригинального массива на буферный массив
		}
		
		// блок reduction
		void vertical_reduction(const int row_position, const int quantity) { // сужение по рядам 
			imitator** bufer_array = new imitator * [rows - quantity];  //|
			for (int i = 0; i < rows - quantity; i++)                   //| создаём буферный двумерный массив
				bufer_array[i] = new imitator[columns];                 //|
			for (int i = 0; i < rows - quantity; i++) //| механизм переноса данных в буферный массив
				for (int j = 0; j < columns; j++)     //|
					if (i >= row_position) // проверка позиции
						bufer_array[i][j] = _array[i + quantity][j]; // передача данных буферному массиву в смещённом варианте
					else // если до необходимой позиции ещё не дошли
						bufer_array[i][j] = _array[i][j]; // передача данных буферному массиву в штатном режиме
			for (int i = 0; i < rows; i++) //|
				delete[] _array[i];        //| очистка из оперативной памяти данных исходного двумерного массива 
			delete[] _array;               //| 
			rows -= quantity; // уменьшение количества рядов исходного массива
			_array = bufer_array; // меняем указатель с оригинального массива на буферный массив
		}
		void horizontal_reduction(const int column_position, const int quantity) { // сужение по столбцам
			imitator** bufer_array = new imitator * [rows];        //|
			for (int i = 0; i < rows; i++)                         //| создаём буферный двумерный массив
				bufer_array[i] = new imitator[columns - quantity]; //|
			for (int i = 0; i < rows; i++)                   //| механизм переноса данных в буферный массив
				for (int j = 0; j < columns - quantity; j++) //|
					if (j >= column_position)
						bufer_array[i][j] = _array[i][j + quantity]; // передача данных буферному массиву в смещённом варианте
					else // если до необходимой позиции ещё не дошли
						bufer_array[i][j] = _array[i][j]; // передача данных буферному массиву в штатном режиме
			for (int i = 0; i < rows; i++) //|
				delete[] _array[i];        //| очистка из оперативной памяти данных исходного	двумерного массива 
			delete[] _array;               //| 
			columns -= quantity; // уменьшкние количества столбцов исходного массива
			_array = bufer_array; // меняем указатель с оригинального массива на буферный массив
		}

		// контроль-блок 
		void extension_ctrl() {
			if (rows == 0 && columns != 0)
				rows++;
			else if (rows != 0 && columns == 0)
				columns++;
		}
		void reduction_ctrl() {
			if (rows == 0 && columns != 0)
				columns--;
			else if (rows != 0 && columns == 0)
				rows--;
		}

	public:

		// блок extension
		void row_to_end(int quantity, imitator ...) { // доавление ряда в конец
			va_list args; // объект для работы с переменным числом параметров 
			va_start(args, quantity); // начинаем работу с переменным числом аргмументов с указанием их количества 
			vertical_extension(rows, 1); // добавляем ряд в конец
			for (int j = 0; j < quantity; j++) // механизм добавления
				_array[rows - 1][j] = va_arg(args, imitator); // закидываем параметы в ряд
			va_end(args); // завершаем работу с переменными числом параметров
			extension_ctrl(); // для сопряжения рядов и столбцов 
		} 
		void set_row_to_end(imitator data) { // добавление ряда с одинаковыми значениями в конец
			vertical_extension(rows, 1); // добавляем ряд в конец
			set_row(data, rows - 1); // заполняем новый ряд одинаковыми значениями 
			extension_ctrl(); // для сопряжения рядов и столбцов
		}
		void row_to_begin(int num, ...) { // добавление ряда в начало 
			va_list args; // объект для работы с переменным числом параметров
			va_start(args, num); // начинаем работу с переменным числом аргмументов с указанием их количества
			vertical_extension(0, 1); // добавляем ряд в начало
			for (int j = 0; j < columns; j++) // механизм добавления
				_array[0][j] = va_arg(args, imitator); // закидываем параметы в ряд
			va_end(args); // завершаем работу с переменными числом параметров
			extension_ctrl(); // для сопряжения рядов и столбцов
		}
		void set_row_to_begin(imitator data) { // добавление ряда с одинаковыми значениями в начало
			vertical_extension(0, 1); // добавляем ряд в начало
			set_row(data, 0); // заполняем новый ряд одинаковыми значениями 
			extension_ctrl(); // для сопряжения рядов и столбцов
		}
		void row_to_position(int position, int num, ...) { // добавление ряда по позиции 
			va_list args; // объект для работы с переменным числом параметров
			va_start(args, num); // начинаем работу с переменным числом аргмументов с указанием их количества
			vertical_extension(position, 1); // добавляем ряд по позиции
			for (int j = 0; j < columns; j++) // механизм добавления
				_array[position][j] = va_arg(args, imitator); // закидываем параметы в ряд
			va_end(args); // завершаем работу с переменными числом параметров
			extension_ctrl(); // для сопряжения рядов и столбцов
		}

		void columns_to_end(int num, ...) { // добовление столбца в конец
			va_list args; // объект для работы с переменным числом параметров
			va_start(args, num); // начинаем работу с переменным числом аргмументов с указанием их количества
			horizontal_extension(columns, 1); // добавляем слобец в конец
			for (int i = 0; i < rows; i++) // механизм добавления
				_array[i][columns - 1] = va_arg(args, imitator); // закидываем параметы в столбец
			va_end(args); // завершаем работу с переменными числом параметров 
			extension_ctrl(); // для сопряжения рядов и столбцов
		}
		void columns_to_begin(int num, ...) { // добавление слобца в начало
			va_list args; // объект для работы с переменным числом параметров
			va_start(args, num); // начинаем работу с переменным числом аргмументов с указанием их количества
			horizontal_extension(0, 1); // добавляем столбец в начало 
			for (int i = 0; i < rows; i++) // механизм добавления
				_array[i][0] = va_arg(args, imitator); // закидываем параметы в столбец
			va_end(args); // завершаем работу с переменными числом параметров
			extension_ctrl(); // для сопряжения рядов и столбцов
		}
		void columns_to_position(int position, int num, ...) { // добавление слобца по позиции
			va_list args; // объект для работы с переменным числом параметров
			va_start(args, num); // начинаем работу с переменным числом аргмументов с указанием их количества
			horizontal_extension(position, 1); // добавляем столбец по позиции
			for (int i = 0; i < rows; i++) // механизм добавления
				_array[i][position] = va_arg(args, imitator); // закидываем параметы в столбец
			va_end(args); // завершаем работу с переменными числом параметров
			extension_ctrl(); // для сопряжения рядов и столбцов
		}
		// блок reduction
		void row_out_end() { // удаление ряда из конца
			vertical_reduction(rows, 1); // удаление ряда из конца массива
			reduction_ctrl(); // сопрягаем массив 
		}
		void row_out_begin() { // удаление ряда из начала 
			vertical_reduction(0, 1); // удаление ряда из начала массива
			reduction_ctrl(); // сопрягаем массив
		}
		void row_out_position(int position) { // удаление ряда по позиции
			vertical_reduction(position, 1); // удаление ряда по позиции в массиве
			reduction_ctrl(); // сопрягаем массив
		}

		void column_out_end() { // удаление столбца из конца
			horizontal_reduction(columns, 1); // удаление слобца из конца массива
			reduction_ctrl(); // сопрягаем массив
		}
		void column_out_begin() { // удаление столбца из начала 
			horizontal_reduction(0, 1); // удаление столбца из начала массива 
			reduction_ctrl(); // сопрягаем массив
		}
		void column_out_position(int position) { // удаление слобца по позиции
			horizontal_reduction(position, 1); // удаление столбца по позиции в массиве 
			reduction_ctrl(); // сопрягаем массив
		}

		// функциональный блок
		int get_rows() { // получение значение количества рядом
			return this->rows; // возврат количества рядов
		} 
		int get_columns() { // получение значение количества столбцов
			return this->columns; // возврат количества столбцов
		}
		imitator* operator[](int iterator) { // получение эелмента двумерного массива
			return _array[iterator]; // возвращаем указатель на одномерный массив, далее дело за АрУк
		} /* это оказалось значительно проще, чем казалось - спасибо арифметике указателей - array[i][j] */

		// сахарный блок
		void horizontal_mirror() { // отзеркалить по рядам 
			for (int i = 0; i < (int)(rows / 2); i++)    //| механизм swap 
				for (int j = 0; j < columns; j++)        //|
					std::swap(_array[i][j], _array[rows - 1 - i][j]); // меняем местами значения элементов массива
		}
		void vertical_mirror() { // озеркалить по столбцам 
			for (int i = 0; i < rows; i++)                   //| механизм swap 
				for (int j = 0; j < (int)(columns / 2); j++) //|
					std::swap(_array[i][j], _array[i][columns - 1 - j]); // меняем местами значения элементов массива
		}
		void set_row(imitator data, int row_position) { // заполнения ряда одним значением 
			for (int j = 0; j < columns; j++) // механизм заполнения
				_array[row_position][j] = data; // заполняем значением каждую ячейку определённого ряда
		}
		void set_column(imitator data, int column_position) { // заполнение столбца одним значением 
			for (int i = 0; i < rows; i++) // механизм заполнения
				_array[i][column_position] = data; // заполняем значением каждую ячейку определённого столбца 
		}
		void transposition() { // транспонирование массива
			imitator** buffer_array = new imitator*[columns]; //| создаём буферный массив
			for (int j = 0; j < columns; j++)                 //| с поменяными размерностями 
				buffer_array[j] = new imitator[rows];         //| рядов и стролбцов
			for (int j = 0; j < columns; j++)          //| перекидываем элементы
				for (int i = 0; i < rows; i++)         //| из старого массива
					buffer_array[j][i] = _array[i][j]; //| в новый
			for (int i = 0; i < rows; i++) //|
				delete[] _array[i];        //| очищаем сатрый массив
			delete[] _array;               //|
			std::swap(rows, columns); // меняем местави значения количества рядов и столбцов
			_array = buffer_array; // меняем указатель на буферный массив
		}
		void operator=(const plane& Plane) { // присвоение одной плоскости другой 
			for (int i = 0; i < rows; i++)	//| 
				delete[] _array[i];			//| очищаем старый массив 
			delete[] _array;				//|
			this->rows = Plane.rows; // изменяем размерность рядов
			this->columns = Plane.columns; // изменяем размерность столбцов
			_array = new imitator * [Plane.rows];		//|
			for (int i = 0; i < rows; i++)				//| пересоздаём старый массив с новыми размерностями
				_array[i] = new imitator[Plane.columns];//|
			for (int i = 0; i < Plane.rows; i++)		//|
				for (int j = 0; j < Plane.columns; j++)	//| закидываем данные в пересозданный массив
					_array[i][j] = Plane._array[i][j];	//|
		}

		// конструкторы / деструктор
		plane(int rows = 0, int columns = 0) { // создание пустой плоскости
			this->rows = rows; // указываем значение количесва рядов
			this->columns = columns; // указываем значение количества столбцов
			//rows_and_columns_ctrl(); 
			_array = new imitator * [rows];		   //| выделяем место в памяти
			for (int i = 0; i < rows; i++)         //| под двумерный массив
				_array[i] = new imitator[columns]; //|
		}
		~plane() { // уничтожаем объект
			for (int i = 0; i < rows; i++)	//| очищаем место в памяти
				delete [] _array[i];		//| занимаемое
			delete [] _array;				//| двумерным массивом 
			rows = columns = 0; // обнуляем размерность 
		}
	};

	//////////////////////////////////////////////////////////////////////////
	/*					трёхмерный динамический массив						*/
	//////////////////////////////////////////////////////////////////////////

	template<typename imitator> // пространство - трёхмерный динамический массив
	class space 
	{
		int rows; // количество рядов
		int columns; // количество столбцов  
		int levels; // количество 
		imitator*** _array; // сам массив (указатель на первый элемент первого ряда первого столбца)

		// блок extension


		// блок reduction


	public:
		// блок extension


		// блок reduction


		// функциональный блок
		int get_rows() { // получаем количество рядов в массиве 
			return this->rows; // возвращаем размерность рядов 
		}
		int get_columns() { // получаем количество стобцов в массиве 
			return this->columns; // возвращаем размерность столбцов
		}
		int get_levels() { // получаем количество уровней в массиве 
			return this->levels; // возвращаем размерность уровней 
		}
		imitator** operator[](int iterator) { // тройная индексация для массивов
			return _array[iterator]; // возвращаем указатель на указатель на элемент 
		} 

		// сахарный блок 


		// конструкторы / деструктор
		space(int rows = 0, int columns = 0, int levels = 0) { // создаём трёхмерный массив
			this->rows = rows; // указываем количество рядов
			this->columns = columns; // указываем количество столбцов
			this->levels = levels; // указываем количество уровней 
			_array = new imitator** [rows]; // создаём массив двумерных массивов
			for (int i = 0; i < rows; i++) { // механизм созадния двумерных одномерных массивов
				_array[i] = new imitator* [columns]; // создаём массив одномерных массивов
				for (int j = 0; j < columns; j++) // механизм создания ячеек для одномерных массивов
					_array[i][j] = new imitator[levels]; // создаём ячейки для одномерного массива 
			}
		}
		~space() { // очишаем трёхмерный массив 
			for (int i = 0; i < rows; i++) { // механизм очистки двумерных массивов
				for (int j = 0; j < columns; j++) // механизм очистки одномерных массивов
					delete[] _array[i][j]; // очистка двумерных массивов
				delete[] _array[i]; // очистка двумерных массивов
			}
			delete[] _array; // очистка трёхмерного массива 
			rows = columns = levels = NULL; // обнуляем размерности 
		}
	};

	//////////////////////////////////////////////////////////////////////////
	/*					четырёхмерный динамический массив					*/
	//////////////////////////////////////////////////////////////////////////

	template<typename imitator> // континуум - четырёхмерный динамический массив 
	class continuum
	{
		int rows; // количество рядов
		int columns; // количество столбцов  
		int levels; // количество уровней
		int time; // момент времени или порядки 
		imitator**** _array; // сам массив (указатель на первый элемент первого ряда первого столбца)

		// блок 


		// блок


	public:
		// блок


		//блок


		// функциональный блок
		int get_rows() { // получаем количество рядов в массиве 
			return this->rows; // возвращаем размерность рядов 
		}
		int get_columns() { // получаем количество стобцов в массиве
			return this->columns; // возвращаем размерность столбцов 
		}
		int get_levels() { // получаем количество уровней в массиве
			return this->levels; // возвращаем размерность уровней 
		}
		int get_time() { // получаем количество порядков в массиве
			return this->time; // возвращаем размерность порядков 
		}
		imitator*** operator[](int iterator) { // четверная индексация массива 
			return _array[iterator]; // возращаем указатель на указатель на указатель на элемент 
		}

		// конструкторы / деструктор
		continuum(int rows = 0, int columns = 0, int levels = 0, int time = 0) { // создаём континум
			this->rows = rows; // указываем количество рядов
			this->columns = columns; // указываем количество столбцов
			this->levels = levels; // указываем количество уровней
			this->time = time; // указываем количество порядков 
			_array = new imitator***[rows]; // создание трёхмерных массивов
			for (int i = 0; i < rows; i++) { // механизм создания двумерных массивов
				_array[i] = new imitator** [columns]; // создание двумерных массивов 
				for (int j = 0; j < columns; j++) { // механизм создания одномерных массивов
					_array[i][j] = new imitator* [levels]; // создание одномерных массивов
					for (int k = 0; k < levels; k++) // механизм создания ячеек для одномерных массивов
						_array[i][j][k] = new imitator [time]; // создание ячеек для одномерных массивов
				}
			}
		}
		~continuum() { // очищаем континум 
			for (int i = 0; i < rows; i++) { // механизм очистки трёхмерных массивов 
				for (int j = 0; j < columns; j++) { // механизм очистки двумерных массивов
					for (int k = 0; k < levels; k++) // механизм очистки одномерных массивов
						delete[] _array[i][j][k]; // очищаем одномерные массивы
					delete[] _array[i][j]; // очищаем двумерные массивы
				}
				delete[] _array[i]; // очищаем трёхмерные массивы
			}
			delete[] _array; // очищаем четырёхмерный массив 
			rows = columns = levels = time = NULL; // обнуляем размерности 
		}
	};

	//////////////////////////////////////////////////////////////////////////
	/*							односвязный список							*/
	//////////////////////////////////////////////////////////////////////////

	template <typename imitator> // стрела - односвязный список
	class arrow 
	{
		template <typename imitator> // шаблон контейнера
		class Node // класс контейнера для осблуживания класса односвязного списка 
		{
		public: // поскольку этот класс нужен для обслуживания класса arrow
			imitator data; // данные контейнера списка
			Node* pointer_next; // указатель на следующий контейнер

			Node(imitator data = imitator(), Node* point_next = nullptr) { // предусматривает осутствие / наличие данных или указателя
				this->data = data; // закидывание данных в контейнер 
				this->pointer_next = point_next; // направляем на следующий контейнер 
			}
		};
		int size; // размерность списка
		Node<imitator>* head; // указатель на первый элемент массива 

	public:
		// блок extension 
		void to_end(imitator data) { // добавление в конец списка 
			if (head == nullptr) // если нет элементов в списке
				head = new Node<imitator>(data, head); // создаём новый элемент 
			else { // если есть элементы в списке
				Node<imitator>* current = head; // начинаем обход с начала 
				while (current->pointer_next != nullptr) // пока не дойдём до последнего элемента
					current = current->pointer_next; // переходим к слудующему элементу 
				current->pointer_next = new Node<imitator>(data, nullptr); // добавляем элемент в конце 
			}
			size++; // увеличение размерности 
		}
		void to_begin(imitator data) { // добавление в начало
			head = new Node<imitator>(data, head); // создаём новый элемент в начале 
			size++; // увеличение размерности 
		}
		void to_position(imitator data, int position) { // добавление по позиции 
			if (position <= 0) // если указана позиция начала
				to_begin(data); // добавляем в начало
			else if (position >= size - 1) // если указана позиция конца 
				to_end(data); // добовляем в цонец 
			else { // если указана иная позиция 
				Node<imitator>* current = head; // начинаем обход с начала 
				for (; position > 1; position--) // пока не дойдём до предстоящего элемента 
					current = current->pointer_next; // переходим к следующему элементу 
				current->pointer_next = new Node<imitator>(data, current->pointer_next); // создаём новый элемент 
				size++; // увеличиваем размерность 
			}
		}
		// блок reduction
		void out_end() { // удаление с конца
			Node<imitator>* current = head; // начинаем обход с начала 
			while (current->pointer_next->pointer_next != nullptr) // пока не дойдём до предпоследнего элемента
				current = current->pointer_next; // переходим на новыйэлемент
			delete current->pointer_next->pointer_next; // удаляем последний элемент 
			current->pointer_next = nullptr; // делаем предпослежний элемент замыкающим 
			size--; // уменьшение размерности
		}
		void out_begin() { // удаление с начала
			Node<imitator>* temp = head; // сохраняем элемент под head
			head = head->pointer_next; // перемещаем head на второй элемент 
			delete temp; // удаляем первый элемент
			size--; // уменьшение размерности 
		}
		void out_position(int position) { // удаление по позиции 
			if (position <= 0) // если указана позиция начала
				out_begin(); // удаляем из начала
			else if (position >= size - 1) // если указана позиция конца
				out_end(); // удаляем из конца
			else { // если указана иная позиция 
				Node<imitator>* current = head; // начинаем с конца 
				for (; position > 1; position--) // пока не дойдём до предстоящего элемента
					current = current->pointer_next; // переходим к другому элементу 
				Node<imitator>* temp = current->pointer_next; // указываем на удаляемый элемент 
				current->pointer_next = temp->pointer_next; // изменяем связь списка 
				delete temp; // удаляем элемент 
				size--; // уменьшение размерности 
			}
		}

		//функциональный блок  
		int get_size() { // получение количества числа элементов в списке
			return this->size; // возврат размерности 
		}
		imitator& operator[](int iterator) { // индексация для списка
			Node<imitator>* current = head; // указатель для поиска элемента 
			for (; iterator > 0; iterator--) // пока не будет пройдено нужное количество шагов
				current = current->pointer_next; // перемещаем указатель на следующий элемент 
			return current->data; // возвращаем данные по адресу, на котором мы остановились
		}

		// конструкторы/деструктор
		arrow() { // создание пустого списка 
			size = 0; // нулевая размерность 
			head = nullptr; // нет элементов 
		}
		~arrow() { // очищаем список 
			while (size > 0) // пока не будут удалены все элементы
				out_begin(); // удаляем элемент из начала 
		}
	};

	//////////////////////////////////////////////////////////////////////////
	/*					кольцевой однонаправленный список					*/
	//////////////////////////////////////////////////////////////////////////

	template <typename imitator> // кольцо - однонаправленный кольцевой список
	class ring
	{
		template <typename imitator> // шаблон контейнера
		class Node // класс контейнера для осблуживания класса односвязного списка 
		{
		public: // поскольку этот класс нужен для обслуживания класса arrow
			imitator data; // данные контейнера списка
			Node* pointer_next; // указатель на следующий контейнер

			Node(imitator data = imitator(), Node* point_next = nullptr) { // предусматривает осутствие / наличие данных или указателя
				this->data = data; // закидывание данных в контейнер 
				this->pointer_next = point_next; // направляем на следующий контейнер 
			}
		};
		int size; // размерность списка
		Node<imitator>* head; // указатель на первый элемент массива 
		Node<imitator>* teil; // указатель на последний элемент массива 

	public:
		// блок добавления
		void to_end(imitator data) { // добавление в конец списка 
			if (teil == nullptr) // если пустое кольцо
				to_begin(data); // добавляем в начало
			else { // если кольцо не пусток 
				teil->pointer_next = new Node<imitator>(data, head); // создаём контейнер в конце
				teil = teil->pointer_next; // восстанавливаем связь
				size++; // увеличиваем размерность 
			}
		}
		void to_begin(imitator data) { // добавление в начало
			head = new Node<imitator>(data, head); // создаём контейнер в начале
			if (teil == nullptr) { // если кольцо пустое 
				teil = head; // указываем, что первый элемент является последним 
				teil->pointer_next = head; // восстанавливаем связь 
			}
			else // если в кольце етсь элементы
				teil->pointer_next = head; // восстанавливаем связь
			size++; // увеличиваем размернсть
		}
		void to_position(imitator data, int position) { // добавление по позиции 
			if (position <= 0) // если указана позиция начала
				to_begin(data); // добавляем в начало
			else if (position >= size - 1) // если указана позиция конца 
				to_end(data); // добовляем в цонец 
			else { // если указана иная позиция 
				Node<imitator>* current = head; // начинаем обход с начала 
				for (; position > 1; position--) // пока не дойдём до предстоящего элемента 
					current = current->pointer_next; // переходим к следующему элементу 
				current->pointer_next = new Node<imitator>(data, current->pointer_next); // создаём новый элемент 
				size++; // увеличиваем размерность 
			}
		}
		
		// блок удаления
		void out_end() { // удаление из конца 
			Node<imitator>* current = head; // обходим с начала для поиска предпоследнего элемента 
			while (current->pointer_next != teil) // пока не дойдём до предпоследнего элемента 
				current = current->pointer_next; // перемещаемся на следующий элемент 
			delete teil; // удаляем последний элемент
			teil = current; // усмещаем teil на предпоследний элемент 
			teil->pointer_next = head; // восстанавливаем связь 
			size--; // уменьшение размерности 
		}
		void out_begin() { // удаление из начала
			Node<imitator>* temp = head; // сохраняем элемент под head
			head = head->pointer_next; // перемещаем head на второй элемент 
			if (head == nullptr) // если был удален единственный элемент
				teil = nullptr; // указываем конец в пустоту 
			else // если после удаления остались элементы
				teil->pointer_next = head; // восстановление связи
			delete temp; // удаляем первый элемент
			size--; // уменьшение размерности 
		}
		void out_position(int position) { // удаление по позиции 
			if (position <= 0) // если указана позиция начала
				out_begin(); // удаляем из начала
			else if (position >= size - 1) // если указана позиция конца
				out_end(); // удаляем из конца
			else { // если указана иная позиция 
				Node<imitator>* current = head; // начинаем с конца 
				for (; position > 1; position--) // пока не дойдём до предстоящего элемента
					current = current->pointer_next; // переходим к другому элементу 
				Node<imitator>* temp = current->pointer_next; // указываем на удаляемый элемент 
				current->pointer_next = temp->pointer_next; // изменяем связь списка 
				delete temp; // удаляем элемент 
				size--; // уменьшение размерности 
			}
		}

		//функциональный блок  
		int get_size() { // получение количества числа элементов в списке
			return this->size; // возврат размерности 
		}
		imitator& operator[](int iterator) { // индексация для списка
			Node<imitator>* current = head; // указатель для поиска элемента 
			for (; iterator > 0; iterator--) // пока не будет пройдено нужное количество шагов
				current = current->pointer_next; // перемещаем указатель на следующий элемент 
			return current->data; // возвращаем данные по адресу, на котором мы остановились
		}

		// конструкторы/деструктор
		ring() { // создаём пустое кольцо
			this->size = 0; // нулевая размерность 
			head = nullptr; // нет элементов в кольце
			teil = nullptr; // нет элементов в кольце
		}
		~ring() { // очищение кольца
			while (size > 0) // пока не закончатся элементы
				out_begin(); // удаляем первые элемент
		}
	};

	//////////////////////////////////////////////////////////////////////////
	/*							двусвязный список							*/
	//////////////////////////////////////////////////////////////////////////

	template <typename imitator> // путь - двусвязный список
	class way 
	{
		template<typename imitator>
		class Node // контейнер двусвязного списка
		{
		public: // т.к. только для обслуживания класса двусвязного списка
			imitator data; // даныне контейнера 
			Node* pointer_next; // указатель на следующий контейнер 
			Node* pointer_previous; // указатель на предыдущий контейнер

			Node(imitator data = imitator(), Node* pointer_next = nullptr, Node* pointer_previous = nullptr) { // создаём контейнер 
				this->data = data; // закидываем данные 
				this->pointer_next = pointer_next; // связываем с другим контейнером
				this->pointer_previous = pointer_previous; // связываем с другим контейнером
			}
		};

		int size; // размерность списка
		Node<imitator>* head; // указатель на первый элемент
		Node<imitator>* teil; // указатель на последний элемент 

	public:
		// блок добавления
		void to_end(imitator data) { // добавляем данные в конец списка
			if (teil == nullptr) { // если пустой список
				teil = new Node<imitator>(data, head, teil); // создаём первый элемент и указываем на него teil
				head = teil; // head указывает на первый элемент
			}
			else { // если есть элементы в списке
				teil = new Node<imitator>(data, nullptr, teil); // создаём новый контейнер и связываем его с предыдущим контейнером 
				teil->pointer_previous->pointer_next = teil; // свзяываем указатель на следующий эдемент предпоследнего контейнра с последним элементом 
			}
			size++; // увеличиваем размерность 
		}
		void to_begin(imitator data) { // добавляем данные в начало списка
			if (head == nullptr) { // если пустой список
				head = new Node<imitator>(data, head, teil); // создаём первый элемент и указываем на него head
				teil = head; // teil указывает на первый элемент
			}
			else { // если есть элементы в списке
				head = new Node<imitator>(data, head, nullptr); // создаём новый контейнер и связываем его со следующим контейнером 
				head->pointer_next->pointer_previous = head; // связываем указатель на предыдущий эдемент второго контейнра с первым элементом 
			}
			size++; // увеличиваем размерность 
		}
		void to_position(imitator data, int position) { // добавление элементов по позиции 
			if (position <= 0) // позиционное приуменьшение 
				to_begin(data); // добавление в начало 
			else if (position >= size - 1) // позиционное приувеличение 
				to_end(data); // добавление в конец 
			else { // если позиция не конечная и не начальная
				if (position > size / 2) { // от teil
					position = size - position - 1; // урезание позиции для обхода с конца
					Node<imitator>* current = teil; // начинаем поиск элемента с конца
					for (; position > 0; position--) // пока не дойдём до послестоящего элемента 
						current = current->pointer_previous; // смещаем указатель на предыдущий контейнер 
					current->pointer_previous = new Node<imitator>(data, current, current->pointer_previous); // создаём новый контейнер 
					current->pointer_previous->pointer_previous->pointer_next = current->pointer_previous; // нормализуем связь
				}
				else { // от head
					Node<imitator>* current = head; // начинаем поиск элементов с начала
					for (; position > 1; position--) // пока не дойдём до предстоящего элемента 
						current = current->pointer_next; // смещаем указатель на следующий элемент 
					current->pointer_next = new Node<imitator>(data, current->pointer_next, current); // создаём контейнер
					current->pointer_next->pointer_next->pointer_previous = current->pointer_next; // восстанавливаем связь
				}
				size++; // увеличиваем размерность 
			}
		}

		// блок удаления
		void out_end() { // удаляем элементы из начала списка 
			Node<imitator>* safe_teil = teil; // сохраняем teil, чтобы потом его удалить 
			teil = teil->pointer_previous; // перемещаем teil на предпоследний элемент 
			if (teil == nullptr) // если в очереди всего один элемент 
				head = nullptr; // указывает head в пустоту 
			else // если есть другие элементы 
				teil->pointer_next = nullptr; // после последнего элемента нет элементов
			delete safe_teil; // удаляем контейнер под head 
			size--; // уменьшаем размерность 
		}
		void out_begin() { // удаляем элементы из начала списка 
			Node<imitator>* safe_teil = head; // сохраняем head, чтобы потом его удалить 
			head = head->pointer_next; // перемещаем head на второй элемент 
			if (head == nullptr) // если в очереди всего один элемент 
				teil = nullptr; // указывает teil в пустоту 
			else // если есть элементы 
				head->pointer_previous = nullptr; // перед первого элементом нет элементов
			delete safe_teil; // удаляем контейнер под head 
			size--; // уменьшаем размерность 
		}
		void out_position(int position) { // удаление по позиции 
			if (position <= 0) // позиционное приуменьшение 
				out_begin(); // добавление в начало 
			else if (position >= size - 1) // позиционное приувеличение 
				out_end(); // добавление в конец 
			else { // если позиция не конечная и не начальная
				if (position - 1 > size / 2) { // от teil
					position = size - position; // урезание позиции для обхода с конца 
					Node<imitator>* current = teil; // начинаем обход с конца
					for (; position > 0; position--) // пока не найдём нужный элемент
						current = current->pointer_previous; // переход к слудующему элементу 
					Node<imitator>* delete_current = current; // сохраняем teil, чтобы потом его удалить 
					Node<imitator>* front_current = current->pointer_next; // указатель на следующий элемент
					current = current->pointer_previous; // перемещаем teil на предпоследний элемент 
					front_current->pointer_previous = current; // обратная связь
					current->pointer_next = front_current; // прямая связь
					delete delete_current; // удаляем контейнер под head
				}
				else { // от head
					Node<imitator>* current = head; // начинаем с начала
					for (; position > 0; position--) // пока не найдём нужным элемент
						current = current->pointer_next; // переходим к слудующему контейнеру
					Node<imitator>* delete_current = current; // сохраняем head, чтобы потом его удалить 
					Node<imitator>* back_current = current->pointer_previous; // указатель на педыдущий элемент 
					current = current->pointer_next; // перемещаем head на второй элемент  
					back_current->pointer_next = current; // прямая связь
					current->pointer_previous = back_current; // обратная связь
					delete delete_current; // удаляем контейнер под head 
				}
				size--; // увеличиваем размерность 
			}
		}

		// функциональный блок 
		int get_size() { // получение количества элементов в списке 
			return this->size; // возврат размерности 
		}
		imitator& operator[](int iterator) { // индексация для списка 
			if (iterator - 1 > size / 2) { // от teil
				iterator = size - iterator - 1; // урезание позиции для обхода с конца
				Node<imitator>* current = teil; // начинаем обход с конца
				for (; iterator > 0; iterator--) // пока не найдём нужный элемент
					current = current->pointer_previous; // переходим к предыдущему элементу
				return current->data; // возвращаем данные по адресу
			}
			else { // от head
				Node<imitator>* current = head; // начинаем обход с начала 
				for (; iterator > 0; iterator--) // пока не найдём нужный элемент
					current = current->pointer_next; // переходим к слудующему элементу 
				return current->data; // возвращаем данные по адресу
			}
		}

		// конструкторы/деструктор
		way() { // создание пустого списка 
			size = 0; // нулевая размерность 
			head = nullptr; // нет контейнеров
			teil = nullptr; // нет контейнеров
		}
		~way() { // полное очищение списка 
			while (size > 0) // пока не кончатся элементы в списке  
				out_begin(); // удаляем первые элементы 
		}
	};

	//////////////////////////////////////////////////////////////////////////
	/*					двунаправленный кольцевой списо						*/
	//////////////////////////////////////////////////////////////////////////

	template <typename imitator> // круг - двунаправленный кольцевой списк
	class lap // двунаправленный кольцевой список - круг - на основе двусвязного списка
	{
		template<typename imitator>
		class Node // контейнер двусвязного списка
		{
		public: // т.к. только для обслуживания класса двусвязного списка
			imitator data; // даныне контейнера 
			Node* pointer_next; // указатель на следующий контейнер 
			Node* pointer_previous; // указатель на предыдущий контейнер

			Node(imitator data = imitator(), Node* pointer_next = nullptr, Node* pointer_previous = nullptr) { // создаём контейнер 
				this->data = data; // закидываем данные 
				this->pointer_next = pointer_next; // связываем с другим контейнером
				this->pointer_previous = pointer_previous; // связываем с другим контейнером
			}
		};

		int size; // размерность списка
		Node<imitator>* head; // указатель на первый элемент
		Node<imitator>* teil; // указатель на последний элемент 

	public:
		// блок добавления
		void to_end(imitator data) { // добавляем данные в конец списка
			if (teil == nullptr) { // если пустой список
				teil = new Node<imitator>(data, head, teil); // создаём первый элемент и указываем на него teil
				teil->pointer_next = head; // восстанавливаем связь
				head->pointer_previous = head; // восстанавливаем связь 
				head = teil; // head указывает на первый элемент
			}
			else { // если есть элементы в списке
				teil = new Node<imitator>(data, nullptr, teil); // создаём новый контейнер и связываем его с предыдущим контейнером 
				head->pointer_previous = teil; // восстановление связи
				teil->pointer_next = head; // восстановление связи
				teil->pointer_previous->pointer_next = teil; // свзяываем указатель на следующий эдемент предпоследнего контейнра с последним элементом 
			}
			size++; // увеличиваем размерность 
		}
		void to_begin(imitator data) { // добавляем данные в начало списка
			if (head == nullptr) { // если пустой список
				head = new Node<imitator>(data, head, teil); // создаём первый элемент и указываем на него head
				head->pointer_next = head; // восстановление связи
				head->pointer_previous = head; // восстановление связи
				teil = head; // teil указывает на первый элемент
			}
			else { // если есть элементы в списке
				head = new Node<imitator>(data, head, teil); // создаём новый контейнер и связываем его со следующим контейнером 
				teil->pointer_next = head; // восстановление связи
				head->pointer_next->pointer_previous = head; // связываем указатель на предыдущий эдемент второго контейнра с первым элементом 
			}
			size++; // увеличиваем размерность 
		}
		void to_position(imitator data, int position) { // добавление элементов по позиции 
			if (position <= 0) // позиционное приуменьшение 
				to_begin(data); // добавление в начало 
			else if (position >= size - 1) // позиционное приувеличение 
				to_end(data); // добавление в конец 
			else { // если позиция не конечная и не начальная
				if (position > size / 2) { // от teil
					position = size - position - 1; // урезание позиции для обхода с конца
					Node<imitator>* current = teil; // начинаем поиск элемента с конца
					for (; position > 0; position--) // пока не дойдём до послестоящего элемента 
						current = current->pointer_previous; // смещаем указатель на предыдущий контейнер 
					current->pointer_previous = new Node<imitator>(data, current, current->pointer_previous); // создаём новый контейнер 
					current->pointer_previous->pointer_previous->pointer_next = current->pointer_previous; // нормализуем связь
				}
				else { // от head
					Node<imitator>* current = head; // начинаем поиск элементов с начала
					for (; position > 1; position--) // пока не дойдём до предстоящего элемента 
						current = current->pointer_next; // смещаем указатель на следующий элемент 
					current->pointer_next = new Node<imitator>(data, current->pointer_next, current); // создаём контейнер
					current->pointer_next->pointer_next->pointer_previous = current->pointer_next; // восстанавливаем связь
				}
				size++; // увеличиваем размерность 
			}
		}

		// блок удаления
		void out_end() { // удаляем элементы из начала списка 
			Node<imitator>* delete_teil = teil; // сохраняем teil, чтобы потом его удалить 
			teil = teil->pointer_previous; // перемещаем teil на предпоследний элемент 
			if (teil == nullptr) // если в очереди всего один элемент 
				head = nullptr; // указывает head в пустоту 
			else { // если есть другие элементы 
				teil->pointer_next = head; // после последнего элемента нет элементов
				head->pointer_previous = teil; // восстанавливаем связь
			}
			delete delete_teil; // удаляем контейнер под head 
			size--; // уменьшаем размерность 
		}
		void out_begin() { // удаляем элементы из начала списка 
			Node<imitator>* delete_head = head; // сохраняем head, чтобы потом его удалить 
			head = head->pointer_next; // перемещаем head на второй элемент 
			if (head == nullptr) // если в очереди всего один элемент 
				teil = nullptr; // указывает teil в пустоту 
			else { // если есть элементы 
				head->pointer_previous = teil; // перед первым элементом нет элементов
				teil->pointer_next = head; // восстанавливаем связь 
			}
			delete delete_head; // удаляем контейнер под head 
			size--; // уменьшаем размерность 
		}
		void out_position(int position) { // удаление по позиции 
			if (position <= 0) // позиционное приуменьшение 
				out_begin(); // добавление в начало 
			else if (position >= size - 1) // позиционное приувеличение 
				out_end(); // добавление в конец 
			else { // если позиция не конечная и не начальная
				if (position - 1 > size / 2) { // от teil
					position = size - position; // урезание позиции для обхода с конца 
					Node<imitator>* current = teil; // начинаем обход с конца
					for (; position > 0; position--) // пока не найдём нужный элемент
						current = current->pointer_previous; // переход к слудующему элементу 
					Node<imitator>* delete_current = current; // сохраняем teil, чтобы потом его удалить 
					Node<imitator>* front_current = current->pointer_next; // указатель на следующий элемент
					current = current->pointer_previous; // перемещаем teil на предпоследний элемент 
					front_current->pointer_previous = current; // обратная связь
					current->pointer_next = front_current; // прямая связь
					delete delete_current; // удаляем контейнер под head
				}
				else { // от head
					Node<imitator>* current = head; // начинаем с начала
					for (; position > 0; position--) // пока не найдём нужным элемент
						current = current->pointer_next; // переходим к слудующему контейнеру
					Node<imitator>* delete_current = current; // сохраняем head, чтобы потом его удалить 
					Node<imitator>* back_current = current->pointer_previous; // указатель на педыдущий элемент 
					current = current->pointer_next; // перемещаем head на второй элемент  
					back_current->pointer_next = current; // прямая связь
					current->pointer_previous = back_current; // обратная связь
					delete delete_current; // удаляем контейнер под head 
				}
				size--; // увеличиваем размерность 
			}
		}

		// функциональный блок 
		int get_size() { // получение количества элементов в списке 
			return this->size; // возврат размерности 
		}
		imitator& operator[](int iterator) { // индексация для списка 
			if (iterator - 1 > size / 2) { // от teil
				iterator = size - iterator - 1; // урезание позиции для обхода с конца
				Node<imitator>* current = teil; // начинаем обход с конца
				for (; iterator > 0; iterator--) // пока не найдём нужный элемент
					current = current->pointer_previous; // переходим к предыдущему элементу
				return current->data; // возвращаем данные по адресу
			}
			else { // от head
				Node<imitator>* current = head; // начинаем обход с начала 
				for (; iterator > 0; iterator--) // пока не найдём нужный элемент
					current = current->pointer_next; // переходим к слудующему элементу 
				return current->data; // возвращаем данные по адресу
			}
		}

		// конструкторы/деструктор
		lap() { // создание пустого списка 
			size = 0; // нулевая размерность 
			head = nullptr; // нет контейнеров
			teil = nullptr; // нет контейнеров
		}
		~lap() { // полное очищение списка 
			while (size > 0) // пока не кончатся элементы в списке  
				out_begin(); // удаляем первые элементы 
		}
	};

	//////////////////////////////////////////////////////////////////////////
	/*									стек								*/
	//////////////////////////////////////////////////////////////////////////

	template <typename imitator> // стек на основе односвязного списка
	class stack 
	{
		template<typename imitator> 
 		class Node // контейнер стека
		{
		public: // т.к. только для обслуживания класса стека
			imitator data; // даныне контейнера 
			Node* pointer_next; // указатель на другой контейнер 

			Node(imitator data = imitator(), Node* pointer_next = nullptr) { // создаём контейнер 
				this->data = data; // закидываем данные 
				this->pointer_next = pointer_next; // связываем с другими контейнерами
			}
		};

		int size; // размерность стека
		Node<imitator>* head; // указатель на первый элемент 

	public:
		//добавление элемента в стэк
		void to_stack(imitator data) { // добавляем элементы в начало стэка 
			head = new Node<imitator>(data, head); // создаём новый контейнер 
			size++; // увеличиваем размерность 
		}

		//удаление элемента из стэка 
		void out_stack() { // удаляем элементы из начала стэка
			Node<imitator>* safe_head = head; // сохраняем head, чтобы потом его удалить 
			head = head->pointer_next; // перемещаем head на втоорой элемент 
			delete safe_head; // удаляем контейнер под head 
			size--; // уменьшаем размерность 
		}

		// функциональный блок 
		int get_size() { // получение количества элементов в стэке
			return this->size; // возврат размерности 
		}

		// конструкторы/деструктор
		stack() { // создаём пустой стек
			size = 0; // нулевая размерность
			head = nullptr; // нет контейнеров
		}
		~stack() { // полная очистка стека
			while (size > 0) // пока есть элементы 
				out_stack(); // удаляем элементы 
		}
	};

	//////////////////////////////////////////////////////////////////////////
	/*									очередь								*/
	//////////////////////////////////////////////////////////////////////////

	template <typename imitator> // очередь - на основе двусвязного списка
	class queue 
	{
		template<typename imitator>
		class Node // контейнер для очереди
		{
		public: // т.к. только для обслуживания класса очереди
			imitator data; // данные контейнера 
			Node* pointer_next; // указатель на следующий контейнер 
			Node* pointer_previous; // указатель на предыдущий контейнер

			Node(imitator data = imitator(), Node* pointer_next = nullptr, Node* pointer_previous = nullptr) { // создаём контейнер 
				this->data = data; // закидываем данные 
				this->pointer_next = pointer_next; // связываем с другим контейнером
				this->pointer_previous = pointer_previous; // связываем с другим контейнером
			}
		};

		int size; // размерность очереди
		Node<imitator>* head; // указатель на первый элемент
		Node<imitator>* teil; // указатель на последний элемент 

	public:
		// добавление элементов в очередь
		void to_queue(imitator data) { // добавляем данные в конец очереди
			if (teil == nullptr) { // если пустая очередь
				teil = new Node<imitator>(data, head, teil); // создаём первый элемент и указываем на него teil
				head = teil; // head указывает на первый элемент
			}
			else { // если есть элементы в очереди
				teil = new Node<imitator>(data, nullptr, teil); // создаём новый контейнер и связываем его с предыдущим контейнером 
				teil->pointer_previous->pointer_next = teil; // свзяываем указатель на следующий эдемент предпоследнего контейнра с последним элементом 
			}
			size++; // увеличиваем размерность 
		}

		// удалеление элементов из очереди
		void out_queue() { // удаляем элементы из начала очереди
			Node<imitator>* safe_teil = head; // сохраняем head, чтобы потом его удалить 
			head = head->pointer_next; // перемещаем head на второй элемент 
			if (head == nullptr)  // если в очереди всего один элемент 
				teil = nullptr; // указывает teil в пустоту 
			else // если есть элементы 
				head->pointer_previous = nullptr; // перед первым элементов нет элементов
			delete safe_teil; // удаляем контейнер под head 
			size--; // уменьшаем размерность 
		}

		// функциональный блок 
		int get_size() { // получение количесва элементов в очереди 
			return size; // возвращаем размерность 
		}

		// конструкторы/деструктор
		queue() { // создаём пустую очередь
			size = 0; // нулевая размерность
			head = nullptr; // нет контейнеров
			teil = nullptr; // нет контейнеров
		}
		~queue() { // полная очистка очереди 
			while (size > 0) // пока есть элементы 
				out_queue(); // удаляем элементы 
		}
	};

	//////////////////////////////////////////////////////////////////////////
	/*									дек									*/
	//////////////////////////////////////////////////////////////////////////

	template <typename imitator> // дек - на основе двусвязного списка
	class deque 
	{
		template<typename imitator>
		class Node // контейнер для дека
		{
		public: // т.к. только для обслуживания класса деки
			imitator data; // даныне контейнера 
			Node* pointer_next; // указатель на следующий контейнер 
			Node* pointer_previous; // указатель на предыдущий контейнер

			Node(imitator data = imitator(), Node* pointer_next = nullptr, Node* pointer_previous = nullptr) { // создаём контейнер 
				this->data = data; // закидываем данные 
				this->pointer_next = pointer_next; // связываем с другим контейнером
				this->pointer_previous = pointer_previous; // связываем с другим контейнером
			}
		};

		int size; // размерность дека
		Node<imitator>* head; // указатель на первый элемент
		Node<imitator>* teil; // указатель на последний элемент

	public:
		// блок добавления
		void to_end(imitator data) { // добавляем данные в конец дека
			if (teil == nullptr) { // если пустой дек
				teil = new Node<imitator>(data, head, teil); // создаём первый элемент и указываем на него teil
				head = teil; // head указывает на первый элемент
			}
			else { // если есть элементы в деке
				teil = new Node<imitator>(data, nullptr, teil); // создаём новый контейнер и связываем его с предыдущим контейнером 
				teil->pointer_previous->pointer_next = teil; // свзяываем указатель на следующий эдемент предпоследнего контейнра с последним элементом 
			}
			size++; // увеличиваем размерность 
		}
		void to_begin(imitator data) { // добавляем данные в начало дека
			if (head == nullptr) { // если пустой дек
				head = new Node<imitator>(data, head, teil); // создаём первый элемент и указываем на него head
				teil = head; // teil указывает на первый элемент
			}
			else { // если есть элементы в деке
				head = new Node<imitator>(data, head, nullptr); // создаём новый контейнер и связываем его со следующим контейнером 
				head->pointer_next->pointer_previous = head; // связываем указатель на предыдущий эдемент второго контейнра с первым элементом 
			}
			size++; // увеличиваем размерность 
		}

		// блок удаления
		void out_end() { // удаляем элементы из конца дека
			Node<imitator>* safe_teil = teil; // сохраняем teil, чтобы потом его удалить 
			teil = teil->pointer_previous; // перемещаем teil на предпоследний элемент 
			if (teil == nullptr) // если в очереди всего один элемент 
				head = nullptr; // указывает head в пустоту 
			else
				teil->pointer_next = nullptr; // после последнего элемента нет элементов
			delete safe_teil; // удаляем контейнер под head 
			size--; // уменьшаем размерность 
		}
		void out_begin() { // удаляем элементы из начала дека 
			Node<imitator>* safe_teil = head; // сохраняем head, чтобы потом его удалить 
			head = head->pointer_next; // перемещаем head на второй элемент 
			if (head == nullptr) // если в очереди всего один элемент 
				teil = nullptr; // указывает teil в пустоту 
			else 
				head->pointer_previous = nullptr; // перед первого элементом нет элементов
			delete safe_teil; // удаляем контейнер под head 
			size--; // уменьшаем размерность 
		}

		// функциональный блок 
		int get_size() { // получение количества элементов в деке
			return size; // возврат размерности 
		}
		
		// конструктор/деструктор
		deque() { // создаём пустой дек
			size = 0; // нулевая размерность
			head = nullptr; // нет контейнеров
			teil = nullptr; // нет контейнеров
		}
		~deque() { // полная очистка дека
			while (size > 0) // пока есть элементы 
				out_begin(); // удаляем элементы 
		}
	};

	//////////////////////////////////////////////////////////////////////////
	/*									кортеж								*/
	//////////////////////////////////////////////////////////////////////////

	template<typename imitator> // кортеж - на основе
	class tuple
	{

	};

	//////////////////////////////////////////////////////////////////////////
	/*									словарь								*/
	//////////////////////////////////////////////////////////////////////////

	template<typename imitator> // словарь - на основе
	class map
	{

	};

	//////////////////////////////////////////////////////////////////////////
	/*								бинарное дерево							*/
	//////////////////////////////////////////////////////////////////////////

	template <typename imitator> // бинарное дерево
	class binary_tree
	{
		template<typename imitator>
		class Node // контейнер бинарного дерева
		{
		public: // т.к. только для обслуживания класса бинарного деврева
			imitator data; // даныне контейнера 
			Node* pointer_left; // указатель на левый контейнер 
			Node* pointer_right; // указатель на правый контейнер
			Node* pointer_parent; 

			Node(imitator data, Node* pointer_left, Node* pointer_right, Node* pointer_parent) { // создаём контейнер 
				this->data = data; // закидываем данные 
				this->pointer_left = pointer_left; // связываем с другим контейнером
				this->pointer_right = pointer_right; // связываем с другим контейнером
				this->pointer_parent = pointer_parent;
			}
		};

		int size; // размерность дерева
		Node<imitator>* head; // указатель на первый элемент

		void delete_data_to_node(Node<imitator>* delete_node) { // удаление по контейнеру 
			if (delete_node == nullptr) // если такого контейнера не существует
				return; // выходим из удаления 
			else if (delete_node->pointer_left != nullptr || delete_node->pointer_right != nullptr) // если не листья
				if (delete_node->pointer_left == nullptr && delete_node->pointer_right != nullptr) { // если левого нет, а правый есть
					delete_node->pointer_left = delete_node->pointer_right->pointer_left; // смещаем левый указатель на левый указатель правого элемента
					delete_node->data = delete_node->pointer_right->data; // забираем данные с правого элемента
					Node<imitator>* temp_delete_node = delete_node->pointer_right; // сохраняем указатель на правый элемент 
					delete_node->pointer_right = delete_node->pointer_right->pointer_right; // смещаем правый указатель на правый указатель правого элемента 
					delete temp_delete_node; // удаляем правый элемент 
				}
				else if (delete_node->pointer_left != nullptr && delete_node->pointer_right == nullptr) { // если правого нет, а левый есть
					delete_node->pointer_right = delete_node->pointer_left->pointer_right; // смещаем правый указатель на правый указатель левого элемента
					delete_node->data = delete_node->pointer_left->data; // забираем данные с левого элемента 
					if (delete_node->pointer_right != nullptr)
						delete_node->pointer_right->pointer_parent = delete_node;
					Node<imitator>* temp_delete_node = delete_node->pointer_left; // сохраняем указатель на левый элемент 
					delete_node->pointer_left = delete_node->pointer_left->pointer_left; // смещаем левый указатель на левый указатель левого элемента 
					if (delete_node->pointer_left != nullptr)
						delete_node->pointer_left->pointer_parent = delete_node;
					delete temp_delete_node; // удаляем левый элемент 
				}
				else { // если и правый элемент, и левый элемент не пустые 
					imitator temp_data = delete_node->pointer_right->data; // сохраняем данные для удаляемого элемента
					delete_data_to_node(delete_node->pointer_right); // удаляем правый элемент 
					delete_node->data = temp_data; // закидываем данные с правого элемента 
				}
			else { // если удаляем листву
				if (delete_node->pointer_parent == nullptr) // если удаляем корень
					delete_node->pointer_parent = head; // указываем вспомогательную ноду на корень
				if (delete_node->data > delete_node->pointer_parent->data) // если удаляемя правый элемент
					delete_node->pointer_parent->pointer_right = nullptr; // затираем правый указатель родителя
				else if (delete_node->data < delete_node->pointer_parent->data) // если удаляем левый элемент
					delete_node->pointer_parent->pointer_left = nullptr; // затираем левый указатель родителя 
				delete delete_node; // удаляем элемент 
			}
		}

		void add_data_ctrl(imitator data, Node<imitator>* current) { // добавление данных 
			if (head == nullptr) // если нет элементов
				head = new Node<imitator>(data, head, head, nullptr); // создаём корень 
			else { // если есть элементы 
				if (data > current->data) // если добавляемые данные больше тех, что содержаться в текущем контейнере
					if (current->pointer_right == nullptr) // если правого элемента не существует
						current->pointer_right = new Node<imitator>(data, nullptr, nullptr, current); // создаём новый правый элемент
					else // если правый элемент уже существует
						add_data_ctrl(data, current->pointer_right); // идём разбиратсья с правым существующим правым элементом 
				else if (data < current->data) // если добавляемые данные меньше тех, что содержаться в текущем контейнере
					if (current->pointer_left == nullptr) // если левого элемента не существует
						current->pointer_left = new Node<imitator>(data, nullptr, nullptr, current); // создаём новый левый элемент 
					else // если левый элемент уже существует 
						add_data_ctrl(data, current->pointer_left); // идём разбирваться с левым существующим элементом 
				else // если такие даныне уже есть
					return; // ничего не добавляем 
			}
		}

		void show_in_line_ctrl(Node<imitator>* current) { // переделать в виде дерева 
			if (current == nullptr)
				return;
			else {
				std::cout << current->data << " { ";
				if (current->pointer_left != nullptr)
					show_in_line_ctrl(current->pointer_left);
				std::cout << " | ";
				if (current->pointer_right != nullptr)
					show_in_line_ctrl(current->pointer_right);
				std::cout << " } ";
				return;
			}
		}

		void clear_ctrl(Node<imitator>* current) { // очищение всего дерева 
			if (current != nullptr) { // если элемент не является листвой
				if (current->pointer_left != nullptr) // если слева есть элементы
					clear_ctrl(current->pointer_left); // чистим левую ветку
				if (current->pointer_right != nullptr) // если справа есть элементы 
					clear_ctrl(current->pointer_right); // чистим правую ветку
			}
			if (current == nullptr) // если дерево уже пустое 
				return; // выходим из удаления 
			if (current->pointer_left == nullptr && current->pointer_right == nullptr) { // если достигли листвы 
				delete_data_to_node(current); // удаляем листву 
			}
		}

		Node<imitator>* find(imitator data) { // ищем контейнер по указанным данным 
			if (head == nullptr) // если нет элементов 
				return nullptr; // возвращаем пустоту 
			else { // если есть элементы 
				Node<imitator>* current = head; // начинаем обход с головы 
				while (current != nullptr) // если указан несуществующий элемент 
					if (data == current->data) // если искомые данные совпадают с данными контейнера
						break; // выходим из цикла 
					else if (data > current->data) // если искомые данные больше данных контейнера
						current = current->pointer_right; // смещаемся вправо 
					else if (data < current->data) // если искомые данные меньше данных контейнера
						current = current->pointer_left; // смещаемся влево 
				if (current == nullptr) // если всё же был указан несуществующий элемент 
					return nullptr; // возвращаем пустоту 
				else // если удалось найти элемент
					return current; // возвращаем контейнер 
			}
		}

	public:
		void add_data(imitator data) { // добавление данных в дерево 
			add_data_ctrl(data, head); // обходим ограничение: нельзя указывать поля класса как параметры по умолчанию
			size++; // увеличиваем размерность 
		}

		bool is_data(imitator data) { // проверка существутования элемента в дереве
			Node<imitator>* temp_node = find(data); // вызываем функцию поиска элемента 
			if (temp_node != nullptr) // если есть контейнер, содержащий искомые данные
				return true; // да, есть такой элемент
			else // если нет контейнера, содержащего искомые данные
				return false; // нет, такого элемента нет
		}

		void delete_data(imitator data) { // удаляем данные из дерева 
			Node<imitator>* delete_node = find(data); // ищем контейнер, содержащий удаляемые данные 
			if (delete_node != nullptr) // если удаляемый контейнер вообще есть 
				size--; // уменьшение разерности 
			delete_data_to_node(delete_node); // удаляем по контейнеру 
			if (size == 0)
				head = nullptr;
		}

		// функциональный блок 
		int get_size() { // для получения количества элементов в дереве
			return this->size; // возвращаем размерность 
		}

		// сахарный блок
		void show_in_line_consolas() { // какой-никакой вывод дерева 
			show_in_line_ctrl(head); // обходим ограничение: нельзя указывать поля класса как параметры по умолчанию
		}

		// конструкторы/деструктор
		binary_tree() { // создаём пустое дерево 
			size = 0; // нет элементов
			head = nullptr; // нет элементов
		}
		~binary_tree() { // очищаем дерево
			clear_ctrl(head); // обходим ограничение: нельзя указывать поля класса как параметры по умолчанию
			size = 0; // обнуляем размерность 
			head = nullptr;
		}
	};

	//////////////////////////////////////////////////////////////////////////
	/*									точки	 							*/
	//////////////////////////////////////////////////////////////////////////

	/////////////////////////////декартова 2D точка///////////////////////////
	
	template <typename imitator>
	class plane_descartes_point
	{
		imitator x; // значение по абсциссе
		imitator y; // значение по ординате 

	public:
		// операционный блок
		// сложение 
		plane_descartes_point operator+(plane_descartes_point point) { // сложение двух точек
			plane_descartes_point temp_point(point.x, point.y); // создание результирующей точки
			temp_point.x += this->x; // складываем абсциссы 
			temp_point.y += this->y; // складываем ординаты 
			return temp_point; // возвращаем результирующую точку
		}
		void operator+=(plane_descartes_point point) { // прибавление точки
			this->x += point.x; // складываем абсциссу
			this->y += point.y; // складываем ординату 
		}
		// уменьшение
		plane_descartes_point operator-(plane_descartes_point point) { // вычитание двух точек
			plane_descartes_point temp_point(point.x, point.y); // создание результирующей точки
			temp_point.x -= this->x; // вычитаем абсциссы 
			temp_point.y -= this->y; // вычитаем ординаты
			return temp_point; // возвращаем результирующую точку
		}
		void operator-=(plane_descartes_point point) {
			this->x -= point.x;
			this->y -= point.y;
		}
		//функциональный блок 
		imitator get_x() { // получение значения по абсцисс
			return this->x; // возврат координаты
		}
		imitator get_y() { // получение значения по ординате 
			return this->y; // возврат координаты
		}

		// конструкторы/деструктор
		plane_descartes_point() { // создание точки на пересечении координат
			this->x = 0; // 0 по абсциссе 
			this->y = 0; // 0 по ординате 
		}
		plane_descartes_point(imitator x, imitator y) { // создание точки по координатам 
			this->x = x; // определение абсциссы
			this->y = y; // определение ординаты
		}
		plane_descartes_point(plane_descartes_point& point) { // копирование другой точки 
			this->x = point.x; // определение абсциссы
			this->y = point.y; // определение ординаты
		}
		~plane_descartes_point() { // удаление точки
			this->x = this->y = NULL; // обнуление точки
		}
	};

	///////////////////////////////полярная точка/////////////////////////////

	template <typename imitator>
	class polar_point
	{
		imitator r;
		imitator fi;

	public:
		//функциональный блок 
		imitator get_r() {
			return this->x;
		}
		imitator get_fi() {
			return this->fi;
		}

		// конструкторы/деструктор
		polar_point() {
			this->r = 0;
			this->fi = 0;
		}
		polar_point(imitator r, imitator fi) {
			this->r = r;
			this->fi = fi;
		}
		polar_point(polar_point& point) {
			this->r = point.r;
			this->fi = point.fi;
		}
		~polar_point() {
			this->r = this->fi = NULL;
		}
	};

	/////////////////////////////декартова 3D точка///////////////////////////

	template <typename imitator>
	class space_descartes_point
	{
		imitator x;
		imitator y;
		imitator z;

	public:
		//функциональный блок 
		imitator get_x() {
			return this->x;
		}
		imitator get_y() {
			return this->y;
		}
		imitator get_z() {
			return this->z;
		}

		// конструкторы/деструктор
		space_descartes_point() {
			this->x = 0;
			this->y = 0;
			this->z = 0;
		}
		space_descartes_point(imitator x, imitator y, imitator z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}
		space_descartes_point(space_descartes_point& point) {
			this->x = point.x;
			this->y = point.y;
			this->z = point.z;
		}
		~space_descartes_point() {
			this->x = this->y = this->z = NULL;
		}
	};

	////////////////////////////цилиндрическая точка//////////////////////////

	template <typename imitator>
	class cylindrical_point
	{
		imitator x;
		imitator y;
		imitator fi;

	public:
		//функциональный блок 
		imitator get_x() {
			return this->x;
		}
		imitator get_y() {
			return this->y;
		}
		imitator get_fi() {
			return this->fi;
		}

		// конструкторы/деструктор
		cylindrical_point() {
			this->r = 0;
			this->fi = 0;
		}
		cylindrical_point(imitator r, imitator fi) {
			this->r = x;
			this->fi = y;
		}
		cylindrical_point(cylindrical_point& point) {
			this->r = point.r;
			this->fi = point.fi;
		}
		~cylindrical_point() {
			this->r = this->fi = NULL;
		}
	};

	/////////////////////////////сферическая точка////////////////////////////

	template <typename imitator>
	class spherical_point
	{
 
	};

	//////////////////////////////////////////////////////////////////////////
	/*							комплексное число 							*/
	//////////////////////////////////////////////////////////////////////////

	template<typename imitator>
	class complex
	{
		imitator Re; // действительная часть 
		imitator Im; // мнимая часть 

	public:
		//функциональный блок 
		imitator get_Re() {
			return this->Re;
		}
		imitator get_Im() {
			return this->Im;
		}
		imitator modul() {
			return this->re * this->re + this->im * this->im;
		}

		// операционный блок 
		// операция сложения 
		complex operator+(complex& C) {
			complex Ctemp(C.Re, C.Im);
			Ctemp.Re += this->Re;
			Ctemp.Im += this->Im;
			return Ctemp;
		}
		complex operator+(imitator Real) {
			complex Ctemp(this->Re, this->Im);
			Ctemp.Re += Real;
			return Ctemp;
		}
		void operator+=(complex& C) {
			this->Re += C.Re;
			this->Im += C.Im;
		}
		void operator+=(imitator Real) {
			this->Re += Real;
		}

		// операция уменьшения
		complex operator-(complex& C) {
			complex Ctemp(C.Re, C.Im);
			Ctemp.Re -= this->Re;
			Ctemp.Im -= this->Im;
			return Ctemp;
		}
		complex operator-(imitator Real) {
			complex Ctemp(this->Re, this->Im);
			Ctemp.Re -= Real;
			return Ctemp;
		}
		void operator-=(complex& C) {
			this->Re -= C.Re;
			this->Im -= C.Im;
		}
		void operator-=(imitator Real) {
			this->Re -= Real;
		}

		// операция умножения
		complex operator*(complex& C) {
			complex Ctemp;
			Ctemp.Re = this->Re * C.Re - this->Im * C.Im;
			Ctemp.Im = this->Im * C.Re + this->Re * C.Im;
			return Ctemp;
		}
		complex operator*=(imitator Real) {
			complex Ctemp(this->Re, this->Im);
			Ctemp.Re *= Real;
			Ctemp.Im *= Real;
			return Ctemp;
		}

		// сахарный блок 
		void show() {
			std::cout << this->Re << " + ( " << this->Im << "i )" << "\n";
		}

		// конструкторы
		complex() {
			this->Re = 0;
			this->Im = 0;
		}
		complex(imitator Im) {
			this->Re = 0;
			this->Im = Im;
		}
		complex(imitator Re, imitator Im) {
			this->Re = Re;
			this->Im = Im;
		}
		complex(complex& C) {
			this->Re = C.Re;
			this->Im = C.Im;
		}
		~complex() {
			this->Re = this->Im = NULL;
		}
	};

}