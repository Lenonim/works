#pragma once

#include <stdarg.h>

namespace hardstl
{

	//////////////////////////////////////////////////////////////////////////
	/*								������									*/
	//////////////////////////////////////////////////////////////////////////

	class string
	{
		char* symbols;
	public:

	};

	//////////////////////////////////////////////////////////////////////////
	/*					���������� ������������ ������						*/
	//////////////////////////////////////////////////////////////////////////

	template<typename imitator> //  ������ - ���������� ������������ ������ 
	class straight 
	{
		int size; // ����������� �������
		imitator* _array; // ���������������� ��� ������ (��������� �� ��� ������ �������)

		// ���� extension
		void extension(const int position, const int quantity) { // ��������� ������
			imitator* bufer_array = new imitator[size + quantity]; // ������ �������� ������ 
			for (int i = 0; i < size; i++) { // �������� �������� ������ � �������� ������
				if (i >= position) // �������� �������, ����� ������� ����������� ��������� ��������
					bufer_array[i + quantity] = _array[i]; // �������� ������ ��������� ������� � ��������� ��������
				else // ���� �� ����� ��� �� ����������� �������
					bufer_array[i] = _array[i]; // �������� ������ ��������� ������� � ������� ������
			}
			size += quantity; // ���������� ������� ������� �� ��������� ���������� ���������
			delete[] _array; // ������� �� ����������� ������ ������ ��������� �������
			_array = bufer_array; // ������ ��������� � ������������� ������� �� �������� ������
		}

		// ���� reduction 
		void reduction(const int position, const int quantity) { // �������� ���������� ����� ��������� ����� ������� 
			imitator* bufer_array = new imitator[size - quantity]; // ������ �������� ������ 
			for (int i = 0; i < size - quantity; i++) { // �������� �������� ������ � �������� ������
				if (i >= position) // �������� �������, ����� ������� ����������� ������� ��������
					bufer_array[i] = _array[i + quantity]; // �������� ������ ��������� ������� � ��������� ��������
				else // ���� �� ����� ��� �� ����������� �������
					bufer_array[i] = _array[i]; // �������� ������ ��������� ������� � ������� ������
			}
			size -= quantity; // ���������� ������� ������� �� ��������� ���������� ���������
			delete[] _array; // ������� �� ����������� ������ ������ ��������� �������
			_array = bufer_array; // ������ ��������� � ������������� ������� �� �������� ������
		}

	public:

		// ���� extension
		void to_end(imitator value) { // ���������� ������ �������� � ����� �������
			extension(size, 1); // ��������� ������ �� ���� ������� ����� ��������� ������� 
			_array[size - 1] = value; // ��������� ������ �������
		}
		void to_begin(imitator value) { // ���������� ������ �������� � ������ �������
			extension(0, 1); // ��������� ������ �� ���� ������� ����� ��������� ������� 
			_array[0] = value; // ��������� ������ �������
		}
		void to_position(imitator value, int position) { // ���������� ������ �������� � ��������� �������
			extension(position, 1); // ��������� ������ �� ���� ������� ����� ��������� ������� 
			_array[position] = value; // ��������� ������ �������
		}

		// ���� reduction
		void out_end() { // �������� �� ����� 
			reduction(size - 1, 1); // ������� ��������� ������� 
		}
		void out_begin() { // �������� �� ������
			reduction(0, 1); //������� ������ �������
		}
		void out_position(int position) { // �������� �� �������
			reduction(position, 1); // ������� ������� �� ������� 
		}

		// �������������� ����
		int get_size() { // ��������� ����������� �������
			return this->size; // ���������� �����������
		}
		imitator& operator[](int iterator) { // ��������� � ��������� ������� ����� ������ ������
			return _array[iterator]; // ���������� ������� �������
		}

		// �������� ����
		void mirror() { // ������������� ������ 
			for (int i = 0; i < (int)(size / 2); i++) // �������� swap
				std::swap(_array[i], _array[size - 1 - i]); // ������ ������� �������� ��������� �������
		}
		void operator=(const straight<imitator>& Straight) { // ���������� ������� ������� ������
			delete[] this->_array; // ������� ������ 
			this->size = Straight.size; // ���� ����� ����������� 
			_array = new imitator[Straight.size]; // �������� ����� ����� � ������ � ����� ������������
			for (int i = 0; i < Straight.size; i++) // �������� �������� ������ 
				_array[i] = Straight._array[i]; // ������� ������ �� ����������� ������� � ���������� ������
		}

		// ������������ / ����������
		straight(int size = 0) { // �������� ������� ������� � ������� ����������� ��������� 
			this->size = size; // ����� ����������� 
			this->_array = new imitator[size]; // �������� ����� � ������������ ������
		}
		~straight() { // ������� ������ 
			delete[] _array; // ���������������� �������� 
			size = 0; // ����-����������� 
		}
	};

	//////////////////////////////////////////////////////////////////////////
	/*					��������� ������������ ������						*/
	//////////////////////////////////////////////////////////////////////////
	
	template<typename imitator> // ��������� - ��������� ������������ ������
	class plane 
	{
		int rows; // ���������� �����
		int columns; // ���������� ��������
		imitator** _array; // ��� ������ (��������� �� ��������� �� ������ ������� ������� ����)

		// ���� extension
		void vertical_extension(const int row_position, const int quantity) { // ���������� �� �����
			imitator** bufer_array = new imitator * [rows + quantity]; //|
			for (int i = 0; i < rows + quantity; i++)                  //| ������ �������� ��������� ������
				bufer_array[i] = new imitator[columns];                //|
			for (int i = 0; i < rows; i++)         //| �������� �������� ������ � �������� ������
				for (int j = 0; j < columns; j++)  //|
					if (i >= row_position) // �������� �������
						bufer_array[i + quantity][j] = _array[i][j]; // �������� ������ ��������� ������� � ��������� ��������
					else // ���� �� ����������� ������� ��� �� �����
						bufer_array[i][j] = _array[i][j]; // �������� ������ ��������� ������� � ������� ������
			for (int i = 0; i < rows; i++) //|
				delete[] _array[i];        //| ������� �� ����������� ������ ������ ���������	���������� ������� 
			delete[] _array;               //| 
			rows += quantity; // ���������� ���������� ����� ��������� �������
			_array = bufer_array; // ������ ��������� � ������������� ������� �� �������� ������
		}
		void horizontal_extension(const int column_position, const int quantity) { // ���������� �� �������� 
			imitator** bufer_array = new imitator * [rows];        //|
			for (int i = 0; i < rows; i++)                         //| ������ �������� ��������� ������
				bufer_array[i] = new imitator[columns + quantity]; //|
			for (int i = 0; i < rows; i++)        //| �������� �������� ������ � �������� ������
				for (int j = 0; j < columns; j++) //|
					if (j >= column_position)
						bufer_array[i][j + quantity] = _array[i][j]; // �������� ������ ��������� ������� � ��������� ��������
					else // ���� �� ����������� ������� ��� �� �����
						bufer_array[i][j] = _array[i][j]; // �������� ������ ��������� ������� � ������� ������
			for (int i = 0; i < rows; i++) //|
				delete[] _array[i];        //| ������� �� ����������� ������ ������ ���������	���������� ������� 
			delete[] _array;               //| 
			columns += quantity; // ���������� ���������� ����� ��������� �������
			_array = bufer_array; // ������ ��������� � ������������� ������� �� �������� ������
		}
		
		// ���� reduction
		void vertical_reduction(const int row_position, const int quantity) { // ������� �� ����� 
			imitator** bufer_array = new imitator * [rows - quantity];  //|
			for (int i = 0; i < rows - quantity; i++)                   //| ������ �������� ��������� ������
				bufer_array[i] = new imitator[columns];                 //|
			for (int i = 0; i < rows - quantity; i++) //| �������� �������� ������ � �������� ������
				for (int j = 0; j < columns; j++)     //|
					if (i >= row_position) // �������� �������
						bufer_array[i][j] = _array[i + quantity][j]; // �������� ������ ��������� ������� � ��������� ��������
					else // ���� �� ����������� ������� ��� �� �����
						bufer_array[i][j] = _array[i][j]; // �������� ������ ��������� ������� � ������� ������
			for (int i = 0; i < rows; i++) //|
				delete[] _array[i];        //| ������� �� ����������� ������ ������ ��������� ���������� ������� 
			delete[] _array;               //| 
			rows -= quantity; // ���������� ���������� ����� ��������� �������
			_array = bufer_array; // ������ ��������� � ������������� ������� �� �������� ������
		}
		void horizontal_reduction(const int column_position, const int quantity) { // ������� �� ��������
			imitator** bufer_array = new imitator * [rows];        //|
			for (int i = 0; i < rows; i++)                         //| ������ �������� ��������� ������
				bufer_array[i] = new imitator[columns - quantity]; //|
			for (int i = 0; i < rows; i++)                   //| �������� �������� ������ � �������� ������
				for (int j = 0; j < columns - quantity; j++) //|
					if (j >= column_position)
						bufer_array[i][j] = _array[i][j + quantity]; // �������� ������ ��������� ������� � ��������� ��������
					else // ���� �� ����������� ������� ��� �� �����
						bufer_array[i][j] = _array[i][j]; // �������� ������ ��������� ������� � ������� ������
			for (int i = 0; i < rows; i++) //|
				delete[] _array[i];        //| ������� �� ����������� ������ ������ ���������	���������� ������� 
			delete[] _array;               //| 
			columns -= quantity; // ���������� ���������� �������� ��������� �������
			_array = bufer_array; // ������ ��������� � ������������� ������� �� �������� ������
		}

		// ��������-���� 
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

		// ���� extension
		void row_to_end(int quantity, imitator ...) { // ��������� ���� � �����
			va_list args; // ������ ��� ������ � ���������� ������ ���������� 
			va_start(args, quantity); // �������� ������ � ���������� ������ ����������� � ��������� �� ���������� 
			vertical_extension(rows, 1); // ��������� ��� � �����
			for (int j = 0; j < quantity; j++) // �������� ����������
				_array[rows - 1][j] = va_arg(args, imitator); // ���������� �������� � ���
			va_end(args); // ��������� ������ � ����������� ������ ����������
			extension_ctrl(); // ��� ���������� ����� � �������� 
		} 
		void set_row_to_end(imitator data) { // ���������� ���� � ����������� ���������� � �����
			vertical_extension(rows, 1); // ��������� ��� � �����
			set_row(data, rows - 1); // ��������� ����� ��� ����������� ���������� 
			extension_ctrl(); // ��� ���������� ����� � ��������
		}
		void row_to_begin(int num, ...) { // ���������� ���� � ������ 
			va_list args; // ������ ��� ������ � ���������� ������ ����������
			va_start(args, num); // �������� ������ � ���������� ������ ����������� � ��������� �� ����������
			vertical_extension(0, 1); // ��������� ��� � ������
			for (int j = 0; j < columns; j++) // �������� ����������
				_array[0][j] = va_arg(args, imitator); // ���������� �������� � ���
			va_end(args); // ��������� ������ � ����������� ������ ����������
			extension_ctrl(); // ��� ���������� ����� � ��������
		}
		void set_row_to_begin(imitator data) { // ���������� ���� � ����������� ���������� � ������
			vertical_extension(0, 1); // ��������� ��� � ������
			set_row(data, 0); // ��������� ����� ��� ����������� ���������� 
			extension_ctrl(); // ��� ���������� ����� � ��������
		}
		void row_to_position(int position, int num, ...) { // ���������� ���� �� ������� 
			va_list args; // ������ ��� ������ � ���������� ������ ����������
			va_start(args, num); // �������� ������ � ���������� ������ ����������� � ��������� �� ����������
			vertical_extension(position, 1); // ��������� ��� �� �������
			for (int j = 0; j < columns; j++) // �������� ����������
				_array[position][j] = va_arg(args, imitator); // ���������� �������� � ���
			va_end(args); // ��������� ������ � ����������� ������ ����������
			extension_ctrl(); // ��� ���������� ����� � ��������
		}

		void columns_to_end(int num, ...) { // ���������� ������� � �����
			va_list args; // ������ ��� ������ � ���������� ������ ����������
			va_start(args, num); // �������� ������ � ���������� ������ ����������� � ��������� �� ����������
			horizontal_extension(columns, 1); // ��������� ������ � �����
			for (int i = 0; i < rows; i++) // �������� ����������
				_array[i][columns - 1] = va_arg(args, imitator); // ���������� �������� � �������
			va_end(args); // ��������� ������ � ����������� ������ ���������� 
			extension_ctrl(); // ��� ���������� ����� � ��������
		}
		void columns_to_begin(int num, ...) { // ���������� ������ � ������
			va_list args; // ������ ��� ������ � ���������� ������ ����������
			va_start(args, num); // �������� ������ � ���������� ������ ����������� � ��������� �� ����������
			horizontal_extension(0, 1); // ��������� ������� � ������ 
			for (int i = 0; i < rows; i++) // �������� ����������
				_array[i][0] = va_arg(args, imitator); // ���������� �������� � �������
			va_end(args); // ��������� ������ � ����������� ������ ����������
			extension_ctrl(); // ��� ���������� ����� � ��������
		}
		void columns_to_position(int position, int num, ...) { // ���������� ������ �� �������
			va_list args; // ������ ��� ������ � ���������� ������ ����������
			va_start(args, num); // �������� ������ � ���������� ������ ����������� � ��������� �� ����������
			horizontal_extension(position, 1); // ��������� ������� �� �������
			for (int i = 0; i < rows; i++) // �������� ����������
				_array[i][position] = va_arg(args, imitator); // ���������� �������� � �������
			va_end(args); // ��������� ������ � ����������� ������ ����������
			extension_ctrl(); // ��� ���������� ����� � ��������
		}
		// ���� reduction
		void row_out_end() { // �������� ���� �� �����
			vertical_reduction(rows, 1); // �������� ���� �� ����� �������
			reduction_ctrl(); // ��������� ������ 
		}
		void row_out_begin() { // �������� ���� �� ������ 
			vertical_reduction(0, 1); // �������� ���� �� ������ �������
			reduction_ctrl(); // ��������� ������
		}
		void row_out_position(int position) { // �������� ���� �� �������
			vertical_reduction(position, 1); // �������� ���� �� ������� � �������
			reduction_ctrl(); // ��������� ������
		}

		void column_out_end() { // �������� ������� �� �����
			horizontal_reduction(columns, 1); // �������� ������ �� ����� �������
			reduction_ctrl(); // ��������� ������
		}
		void column_out_begin() { // �������� ������� �� ������ 
			horizontal_reduction(0, 1); // �������� ������� �� ������ ������� 
			reduction_ctrl(); // ��������� ������
		}
		void column_out_position(int position) { // �������� ������ �� �������
			horizontal_reduction(position, 1); // �������� ������� �� ������� � ������� 
			reduction_ctrl(); // ��������� ������
		}

		// �������������� ����
		int get_rows() { // ��������� �������� ���������� �����
			return this->rows; // ������� ���������� �����
		} 
		int get_columns() { // ��������� �������� ���������� ��������
			return this->columns; // ������� ���������� ��������
		}
		imitator* operator[](int iterator) { // ��������� �������� ���������� �������
			return _array[iterator]; // ���������� ��������� �� ���������� ������, ����� ���� �� ����
		} /* ��� ��������� ����������� �����, ��� �������� - ������� ���������� ���������� - array[i][j] */

		// �������� ����
		void horizontal_mirror() { // ����������� �� ����� 
			for (int i = 0; i < (int)(rows / 2); i++)    //| �������� swap 
				for (int j = 0; j < columns; j++)        //|
					std::swap(_array[i][j], _array[rows - 1 - i][j]); // ������ ������� �������� ��������� �������
		}
		void vertical_mirror() { // ���������� �� �������� 
			for (int i = 0; i < rows; i++)                   //| �������� swap 
				for (int j = 0; j < (int)(columns / 2); j++) //|
					std::swap(_array[i][j], _array[i][columns - 1 - j]); // ������ ������� �������� ��������� �������
		}
		void set_row(imitator data, int row_position) { // ���������� ���� ����� ��������� 
			for (int j = 0; j < columns; j++) // �������� ����������
				_array[row_position][j] = data; // ��������� ��������� ������ ������ ������������ ����
		}
		void set_column(imitator data, int column_position) { // ���������� ������� ����� ��������� 
			for (int i = 0; i < rows; i++) // �������� ����������
				_array[i][column_position] = data; // ��������� ��������� ������ ������ ������������ ������� 
		}
		void transposition() { // ���������������� �������
			imitator** buffer_array = new imitator*[columns]; //| ������ �������� ������
			for (int j = 0; j < columns; j++)                 //| � ���������� ������������� 
				buffer_array[j] = new imitator[rows];         //| ����� � ���������
			for (int j = 0; j < columns; j++)          //| ������������ ��������
				for (int i = 0; i < rows; i++)         //| �� ������� �������
					buffer_array[j][i] = _array[i][j]; //| � �����
			for (int i = 0; i < rows; i++) //|
				delete[] _array[i];        //| ������� ������ ������
			delete[] _array;               //|
			std::swap(rows, columns); // ������ ������� �������� ���������� ����� � ��������
			_array = buffer_array; // ������ ��������� �� �������� ������
		}
		void operator=(const plane& Plane) { // ���������� ����� ��������� ������ 
			for (int i = 0; i < rows; i++)	//| 
				delete[] _array[i];			//| ������� ������ ������ 
			delete[] _array;				//|
			this->rows = Plane.rows; // �������� ����������� �����
			this->columns = Plane.columns; // �������� ����������� ��������
			_array = new imitator * [Plane.rows];		//|
			for (int i = 0; i < rows; i++)				//| ���������� ������ ������ � ������ �������������
				_array[i] = new imitator[Plane.columns];//|
			for (int i = 0; i < Plane.rows; i++)		//|
				for (int j = 0; j < Plane.columns; j++)	//| ���������� ������ � ������������� ������
					_array[i][j] = Plane._array[i][j];	//|
		}

		// ������������ / ����������
		plane(int rows = 0, int columns = 0) { // �������� ������ ���������
			this->rows = rows; // ��������� �������� ��������� �����
			this->columns = columns; // ��������� �������� ���������� ��������
			//rows_and_columns_ctrl(); 
			_array = new imitator * [rows];		   //| �������� ����� � ������
			for (int i = 0; i < rows; i++)         //| ��� ��������� ������
				_array[i] = new imitator[columns]; //|
		}
		~plane() { // ���������� ������
			for (int i = 0; i < rows; i++)	//| ������� ����� � ������
				delete [] _array[i];		//| ����������
			delete [] _array;				//| ��������� �������� 
			rows = columns = 0; // �������� ����������� 
		}
	};

	//////////////////////////////////////////////////////////////////////////
	/*					��������� ������������ ������						*/
	//////////////////////////////////////////////////////////////////////////

	template<typename imitator> // ������������ - ��������� ������������ ������
	class space 
	{
		int rows; // ���������� �����
		int columns; // ���������� ��������  
		int levels; // ���������� 
		imitator*** _array; // ��� ������ (��������� �� ������ ������� ������� ���� ������� �������)

		// ���� extension


		// ���� reduction


	public:
		// ���� extension


		// ���� reduction


		// �������������� ����
		int get_rows() { // �������� ���������� ����� � ������� 
			return this->rows; // ���������� ����������� ����� 
		}
		int get_columns() { // �������� ���������� ������� � ������� 
			return this->columns; // ���������� ����������� ��������
		}
		int get_levels() { // �������� ���������� ������� � ������� 
			return this->levels; // ���������� ����������� ������� 
		}
		imitator** operator[](int iterator) { // ������� ���������� ��� ��������
			return _array[iterator]; // ���������� ��������� �� ��������� �� ������� 
		} 

		// �������� ���� 


		// ������������ / ����������
		space(int rows = 0, int columns = 0, int levels = 0) { // ������ ��������� ������
			this->rows = rows; // ��������� ���������� �����
			this->columns = columns; // ��������� ���������� ��������
			this->levels = levels; // ��������� ���������� ������� 
			_array = new imitator** [rows]; // ������ ������ ��������� ��������
			for (int i = 0; i < rows; i++) { // �������� �������� ��������� ���������� ��������
				_array[i] = new imitator* [columns]; // ������ ������ ���������� ��������
				for (int j = 0; j < columns; j++) // �������� �������� ����� ��� ���������� ��������
					_array[i][j] = new imitator[levels]; // ������ ������ ��� ����������� ������� 
			}
		}
		~space() { // ������� ��������� ������ 
			for (int i = 0; i < rows; i++) { // �������� ������� ��������� ��������
				for (int j = 0; j < columns; j++) // �������� ������� ���������� ��������
					delete[] _array[i][j]; // ������� ��������� ��������
				delete[] _array[i]; // ������� ��������� ��������
			}
			delete[] _array; // ������� ���������� ������� 
			rows = columns = levels = NULL; // �������� ����������� 
		}
	};

	//////////////////////////////////////////////////////////////////////////
	/*					������������ ������������ ������					*/
	//////////////////////////////////////////////////////////////////////////

	template<typename imitator> // ��������� - ������������ ������������ ������ 
	class continuum
	{
		int rows; // ���������� �����
		int columns; // ���������� ��������  
		int levels; // ���������� �������
		int time; // ������ ������� ��� ������� 
		imitator**** _array; // ��� ������ (��������� �� ������ ������� ������� ���� ������� �������)

		// ���� 


		// ����


	public:
		// ����


		//����


		// �������������� ����
		int get_rows() { // �������� ���������� ����� � ������� 
			return this->rows; // ���������� ����������� ����� 
		}
		int get_columns() { // �������� ���������� ������� � �������
			return this->columns; // ���������� ����������� �������� 
		}
		int get_levels() { // �������� ���������� ������� � �������
			return this->levels; // ���������� ����������� ������� 
		}
		int get_time() { // �������� ���������� �������� � �������
			return this->time; // ���������� ����������� �������� 
		}
		imitator*** operator[](int iterator) { // ��������� ���������� ������� 
			return _array[iterator]; // ��������� ��������� �� ��������� �� ��������� �� ������� 
		}

		// ������������ / ����������
		continuum(int rows = 0, int columns = 0, int levels = 0, int time = 0) { // ������ ��������
			this->rows = rows; // ��������� ���������� �����
			this->columns = columns; // ��������� ���������� ��������
			this->levels = levels; // ��������� ���������� �������
			this->time = time; // ��������� ���������� �������� 
			_array = new imitator***[rows]; // �������� ��������� ��������
			for (int i = 0; i < rows; i++) { // �������� �������� ��������� ��������
				_array[i] = new imitator** [columns]; // �������� ��������� �������� 
				for (int j = 0; j < columns; j++) { // �������� �������� ���������� ��������
					_array[i][j] = new imitator* [levels]; // �������� ���������� ��������
					for (int k = 0; k < levels; k++) // �������� �������� ����� ��� ���������� ��������
						_array[i][j][k] = new imitator [time]; // �������� ����� ��� ���������� ��������
				}
			}
		}
		~continuum() { // ������� �������� 
			for (int i = 0; i < rows; i++) { // �������� ������� ��������� �������� 
				for (int j = 0; j < columns; j++) { // �������� ������� ��������� ��������
					for (int k = 0; k < levels; k++) // �������� ������� ���������� ��������
						delete[] _array[i][j][k]; // ������� ���������� �������
					delete[] _array[i][j]; // ������� ��������� �������
				}
				delete[] _array[i]; // ������� ��������� �������
			}
			delete[] _array; // ������� ������������ ������ 
			rows = columns = levels = time = NULL; // �������� ����������� 
		}
	};

	//////////////////////////////////////////////////////////////////////////
	/*							����������� ������							*/
	//////////////////////////////////////////////////////////////////////////

	template <typename imitator> // ������ - ����������� ������
	class arrow 
	{
		template <typename imitator> // ������ ����������
		class Node // ����� ���������� ��� ������������ ������ ������������ ������ 
		{
		public: // ��������� ���� ����� ����� ��� ������������ ������ arrow
			imitator data; // ������ ���������� ������
			Node* pointer_next; // ��������� �� ��������� ���������

			Node(imitator data = imitator(), Node* point_next = nullptr) { // ��������������� ��������� / ������� ������ ��� ���������
				this->data = data; // ����������� ������ � ��������� 
				this->pointer_next = point_next; // ���������� �� ��������� ��������� 
			}
		};
		int size; // ����������� ������
		Node<imitator>* head; // ��������� �� ������ ������� ������� 

	public:
		// ���� extension 
		void to_end(imitator data) { // ���������� � ����� ������ 
			if (head == nullptr) // ���� ��� ��������� � ������
				head = new Node<imitator>(data, head); // ������ ����� ������� 
			else { // ���� ���� �������� � ������
				Node<imitator>* current = head; // �������� ����� � ������ 
				while (current->pointer_next != nullptr) // ���� �� ����� �� ���������� ��������
					current = current->pointer_next; // ��������� � ���������� �������� 
				current->pointer_next = new Node<imitator>(data, nullptr); // ��������� ������� � ����� 
			}
			size++; // ���������� ����������� 
		}
		void to_begin(imitator data) { // ���������� � ������
			head = new Node<imitator>(data, head); // ������ ����� ������� � ������ 
			size++; // ���������� ����������� 
		}
		void to_position(imitator data, int position) { // ���������� �� ������� 
			if (position <= 0) // ���� ������� ������� ������
				to_begin(data); // ��������� � ������
			else if (position >= size - 1) // ���� ������� ������� ����� 
				to_end(data); // ��������� � ����� 
			else { // ���� ������� ���� ������� 
				Node<imitator>* current = head; // �������� ����� � ������ 
				for (; position > 1; position--) // ���� �� ����� �� ������������ �������� 
					current = current->pointer_next; // ��������� � ���������� �������� 
				current->pointer_next = new Node<imitator>(data, current->pointer_next); // ������ ����� ������� 
				size++; // ����������� ����������� 
			}
		}
		// ���� reduction
		void out_end() { // �������� � �����
			Node<imitator>* current = head; // �������� ����� � ������ 
			while (current->pointer_next->pointer_next != nullptr) // ���� �� ����� �� �������������� ��������
				current = current->pointer_next; // ��������� �� ������������
			delete current->pointer_next->pointer_next; // ������� ��������� ������� 
			current->pointer_next = nullptr; // ������ ������������� ������� ���������� 
			size--; // ���������� �����������
		}
		void out_begin() { // �������� � ������
			Node<imitator>* temp = head; // ��������� ������� ��� head
			head = head->pointer_next; // ���������� head �� ������ ������� 
			delete temp; // ������� ������ �������
			size--; // ���������� ����������� 
		}
		void out_position(int position) { // �������� �� ������� 
			if (position <= 0) // ���� ������� ������� ������
				out_begin(); // ������� �� ������
			else if (position >= size - 1) // ���� ������� ������� �����
				out_end(); // ������� �� �����
			else { // ���� ������� ���� ������� 
				Node<imitator>* current = head; // �������� � ����� 
				for (; position > 1; position--) // ���� �� ����� �� ������������ ��������
					current = current->pointer_next; // ��������� � ������� �������� 
				Node<imitator>* temp = current->pointer_next; // ��������� �� ��������� ������� 
				current->pointer_next = temp->pointer_next; // �������� ����� ������ 
				delete temp; // ������� ������� 
				size--; // ���������� ����������� 
			}
		}

		//�������������� ����  
		int get_size() { // ��������� ���������� ����� ��������� � ������
			return this->size; // ������� ����������� 
		}
		imitator& operator[](int iterator) { // ���������� ��� ������
			Node<imitator>* current = head; // ��������� ��� ������ �������� 
			for (; iterator > 0; iterator--) // ���� �� ����� �������� ������ ���������� �����
				current = current->pointer_next; // ���������� ��������� �� ��������� ������� 
			return current->data; // ���������� ������ �� ������, �� ������� �� ������������
		}

		// ������������/����������
		arrow() { // �������� ������� ������ 
			size = 0; // ������� ����������� 
			head = nullptr; // ��� ��������� 
		}
		~arrow() { // ������� ������ 
			while (size > 0) // ���� �� ����� ������� ��� ��������
				out_begin(); // ������� ������� �� ������ 
		}
	};

	//////////////////////////////////////////////////////////////////////////
	/*					��������� ���������������� ������					*/
	//////////////////////////////////////////////////////////////////////////

	template <typename imitator> // ������ - ���������������� ��������� ������
	class ring
	{
		template <typename imitator> // ������ ����������
		class Node // ����� ���������� ��� ������������ ������ ������������ ������ 
		{
		public: // ��������� ���� ����� ����� ��� ������������ ������ arrow
			imitator data; // ������ ���������� ������
			Node* pointer_next; // ��������� �� ��������� ���������

			Node(imitator data = imitator(), Node* point_next = nullptr) { // ��������������� ��������� / ������� ������ ��� ���������
				this->data = data; // ����������� ������ � ��������� 
				this->pointer_next = point_next; // ���������� �� ��������� ��������� 
			}
		};
		int size; // ����������� ������
		Node<imitator>* head; // ��������� �� ������ ������� ������� 
		Node<imitator>* teil; // ��������� �� ��������� ������� ������� 

	public:
		// ���� ����������
		void to_end(imitator data) { // ���������� � ����� ������ 
			if (teil == nullptr) // ���� ������ ������
				to_begin(data); // ��������� � ������
			else { // ���� ������ �� ������ 
				teil->pointer_next = new Node<imitator>(data, head); // ������ ��������� � �����
				teil = teil->pointer_next; // ��������������� �����
				size++; // ����������� ����������� 
			}
		}
		void to_begin(imitator data) { // ���������� � ������
			head = new Node<imitator>(data, head); // ������ ��������� � ������
			if (teil == nullptr) { // ���� ������ ������ 
				teil = head; // ���������, ��� ������ ������� �������� ��������� 
				teil->pointer_next = head; // ��������������� ����� 
			}
			else // ���� � ������ ���� ��������
				teil->pointer_next = head; // ��������������� �����
			size++; // ����������� ����������
		}
		void to_position(imitator data, int position) { // ���������� �� ������� 
			if (position <= 0) // ���� ������� ������� ������
				to_begin(data); // ��������� � ������
			else if (position >= size - 1) // ���� ������� ������� ����� 
				to_end(data); // ��������� � ����� 
			else { // ���� ������� ���� ������� 
				Node<imitator>* current = head; // �������� ����� � ������ 
				for (; position > 1; position--) // ���� �� ����� �� ������������ �������� 
					current = current->pointer_next; // ��������� � ���������� �������� 
				current->pointer_next = new Node<imitator>(data, current->pointer_next); // ������ ����� ������� 
				size++; // ����������� ����������� 
			}
		}
		
		// ���� ��������
		void out_end() { // �������� �� ����� 
			Node<imitator>* current = head; // ������� � ������ ��� ������ �������������� �������� 
			while (current->pointer_next != teil) // ���� �� ����� �� �������������� �������� 
				current = current->pointer_next; // ������������ �� ��������� ������� 
			delete teil; // ������� ��������� �������
			teil = current; // �������� teil �� ������������� ������� 
			teil->pointer_next = head; // ��������������� ����� 
			size--; // ���������� ����������� 
		}
		void out_begin() { // �������� �� ������
			Node<imitator>* temp = head; // ��������� ������� ��� head
			head = head->pointer_next; // ���������� head �� ������ ������� 
			if (head == nullptr) // ���� ��� ������ ������������ �������
				teil = nullptr; // ��������� ����� � ������� 
			else // ���� ����� �������� �������� ��������
				teil->pointer_next = head; // �������������� �����
			delete temp; // ������� ������ �������
			size--; // ���������� ����������� 
		}
		void out_position(int position) { // �������� �� ������� 
			if (position <= 0) // ���� ������� ������� ������
				out_begin(); // ������� �� ������
			else if (position >= size - 1) // ���� ������� ������� �����
				out_end(); // ������� �� �����
			else { // ���� ������� ���� ������� 
				Node<imitator>* current = head; // �������� � ����� 
				for (; position > 1; position--) // ���� �� ����� �� ������������ ��������
					current = current->pointer_next; // ��������� � ������� �������� 
				Node<imitator>* temp = current->pointer_next; // ��������� �� ��������� ������� 
				current->pointer_next = temp->pointer_next; // �������� ����� ������ 
				delete temp; // ������� ������� 
				size--; // ���������� ����������� 
			}
		}

		//�������������� ����  
		int get_size() { // ��������� ���������� ����� ��������� � ������
			return this->size; // ������� ����������� 
		}
		imitator& operator[](int iterator) { // ���������� ��� ������
			Node<imitator>* current = head; // ��������� ��� ������ �������� 
			for (; iterator > 0; iterator--) // ���� �� ����� �������� ������ ���������� �����
				current = current->pointer_next; // ���������� ��������� �� ��������� ������� 
			return current->data; // ���������� ������ �� ������, �� ������� �� ������������
		}

		// ������������/����������
		ring() { // ������ ������ ������
			this->size = 0; // ������� ����������� 
			head = nullptr; // ��� ��������� � ������
			teil = nullptr; // ��� ��������� � ������
		}
		~ring() { // �������� ������
			while (size > 0) // ���� �� ���������� ��������
				out_begin(); // ������� ������ �������
		}
	};

	//////////////////////////////////////////////////////////////////////////
	/*							���������� ������							*/
	//////////////////////////////////////////////////////////////////////////

	template <typename imitator> // ���� - ���������� ������
	class way 
	{
		template<typename imitator>
		class Node // ��������� ����������� ������
		{
		public: // �.�. ������ ��� ������������ ������ ����������� ������
			imitator data; // ������ ���������� 
			Node* pointer_next; // ��������� �� ��������� ��������� 
			Node* pointer_previous; // ��������� �� ���������� ���������

			Node(imitator data = imitator(), Node* pointer_next = nullptr, Node* pointer_previous = nullptr) { // ������ ��������� 
				this->data = data; // ���������� ������ 
				this->pointer_next = pointer_next; // ��������� � ������ �����������
				this->pointer_previous = pointer_previous; // ��������� � ������ �����������
			}
		};

		int size; // ����������� ������
		Node<imitator>* head; // ��������� �� ������ �������
		Node<imitator>* teil; // ��������� �� ��������� ������� 

	public:
		// ���� ����������
		void to_end(imitator data) { // ��������� ������ � ����� ������
			if (teil == nullptr) { // ���� ������ ������
				teil = new Node<imitator>(data, head, teil); // ������ ������ ������� � ��������� �� ���� teil
				head = teil; // head ��������� �� ������ �������
			}
			else { // ���� ���� �������� � ������
				teil = new Node<imitator>(data, nullptr, teil); // ������ ����� ��������� � ��������� ��� � ���������� ����������� 
				teil->pointer_previous->pointer_next = teil; // ��������� ��������� �� ��������� ������� �������������� ��������� � ��������� ��������� 
			}
			size++; // ����������� ����������� 
		}
		void to_begin(imitator data) { // ��������� ������ � ������ ������
			if (head == nullptr) { // ���� ������ ������
				head = new Node<imitator>(data, head, teil); // ������ ������ ������� � ��������� �� ���� head
				teil = head; // teil ��������� �� ������ �������
			}
			else { // ���� ���� �������� � ������
				head = new Node<imitator>(data, head, nullptr); // ������ ����� ��������� � ��������� ��� �� ��������� ����������� 
				head->pointer_next->pointer_previous = head; // ��������� ��������� �� ���������� ������� ������� ��������� � ������ ��������� 
			}
			size++; // ����������� ����������� 
		}
		void to_position(imitator data, int position) { // ���������� ��������� �� ������� 
			if (position <= 0) // ����������� ������������� 
				to_begin(data); // ���������� � ������ 
			else if (position >= size - 1) // ����������� ������������� 
				to_end(data); // ���������� � ����� 
			else { // ���� ������� �� �������� � �� ���������
				if (position > size / 2) { // �� teil
					position = size - position - 1; // �������� ������� ��� ������ � �����
					Node<imitator>* current = teil; // �������� ����� �������� � �����
					for (; position > 0; position--) // ���� �� ����� �� ������������� �������� 
						current = current->pointer_previous; // ������� ��������� �� ���������� ��������� 
					current->pointer_previous = new Node<imitator>(data, current, current->pointer_previous); // ������ ����� ��������� 
					current->pointer_previous->pointer_previous->pointer_next = current->pointer_previous; // ����������� �����
				}
				else { // �� head
					Node<imitator>* current = head; // �������� ����� ��������� � ������
					for (; position > 1; position--) // ���� �� ����� �� ������������ �������� 
						current = current->pointer_next; // ������� ��������� �� ��������� ������� 
					current->pointer_next = new Node<imitator>(data, current->pointer_next, current); // ������ ���������
					current->pointer_next->pointer_next->pointer_previous = current->pointer_next; // ��������������� �����
				}
				size++; // ����������� ����������� 
			}
		}

		// ���� ��������
		void out_end() { // ������� �������� �� ������ ������ 
			Node<imitator>* safe_teil = teil; // ��������� teil, ����� ����� ��� ������� 
			teil = teil->pointer_previous; // ���������� teil �� ������������� ������� 
			if (teil == nullptr) // ���� � ������� ����� ���� ������� 
				head = nullptr; // ��������� head � ������� 
			else // ���� ���� ������ �������� 
				teil->pointer_next = nullptr; // ����� ���������� �������� ��� ���������
			delete safe_teil; // ������� ��������� ��� head 
			size--; // ��������� ����������� 
		}
		void out_begin() { // ������� �������� �� ������ ������ 
			Node<imitator>* safe_teil = head; // ��������� head, ����� ����� ��� ������� 
			head = head->pointer_next; // ���������� head �� ������ ������� 
			if (head == nullptr) // ���� � ������� ����� ���� ������� 
				teil = nullptr; // ��������� teil � ������� 
			else // ���� ���� �������� 
				head->pointer_previous = nullptr; // ����� ������� ��������� ��� ���������
			delete safe_teil; // ������� ��������� ��� head 
			size--; // ��������� ����������� 
		}
		void out_position(int position) { // �������� �� ������� 
			if (position <= 0) // ����������� ������������� 
				out_begin(); // ���������� � ������ 
			else if (position >= size - 1) // ����������� ������������� 
				out_end(); // ���������� � ����� 
			else { // ���� ������� �� �������� � �� ���������
				if (position - 1 > size / 2) { // �� teil
					position = size - position; // �������� ������� ��� ������ � ����� 
					Node<imitator>* current = teil; // �������� ����� � �����
					for (; position > 0; position--) // ���� �� ����� ������ �������
						current = current->pointer_previous; // ������� � ���������� �������� 
					Node<imitator>* delete_current = current; // ��������� teil, ����� ����� ��� ������� 
					Node<imitator>* front_current = current->pointer_next; // ��������� �� ��������� �������
					current = current->pointer_previous; // ���������� teil �� ������������� ������� 
					front_current->pointer_previous = current; // �������� �����
					current->pointer_next = front_current; // ������ �����
					delete delete_current; // ������� ��������� ��� head
				}
				else { // �� head
					Node<imitator>* current = head; // �������� � ������
					for (; position > 0; position--) // ���� �� ����� ������ �������
						current = current->pointer_next; // ��������� � ���������� ����������
					Node<imitator>* delete_current = current; // ��������� head, ����� ����� ��� ������� 
					Node<imitator>* back_current = current->pointer_previous; // ��������� �� ��������� ������� 
					current = current->pointer_next; // ���������� head �� ������ �������  
					back_current->pointer_next = current; // ������ �����
					current->pointer_previous = back_current; // �������� �����
					delete delete_current; // ������� ��������� ��� head 
				}
				size--; // ����������� ����������� 
			}
		}

		// �������������� ���� 
		int get_size() { // ��������� ���������� ��������� � ������ 
			return this->size; // ������� ����������� 
		}
		imitator& operator[](int iterator) { // ���������� ��� ������ 
			if (iterator - 1 > size / 2) { // �� teil
				iterator = size - iterator - 1; // �������� ������� ��� ������ � �����
				Node<imitator>* current = teil; // �������� ����� � �����
				for (; iterator > 0; iterator--) // ���� �� ����� ������ �������
					current = current->pointer_previous; // ��������� � ����������� ��������
				return current->data; // ���������� ������ �� ������
			}
			else { // �� head
				Node<imitator>* current = head; // �������� ����� � ������ 
				for (; iterator > 0; iterator--) // ���� �� ����� ������ �������
					current = current->pointer_next; // ��������� � ���������� �������� 
				return current->data; // ���������� ������ �� ������
			}
		}

		// ������������/����������
		way() { // �������� ������� ������ 
			size = 0; // ������� ����������� 
			head = nullptr; // ��� �����������
			teil = nullptr; // ��� �����������
		}
		~way() { // ������ �������� ������ 
			while (size > 0) // ���� �� �������� �������� � ������  
				out_begin(); // ������� ������ �������� 
		}
	};

	//////////////////////////////////////////////////////////////////////////
	/*					��������������� ��������� �����						*/
	//////////////////////////////////////////////////////////////////////////

	template <typename imitator> // ���� - ��������������� ��������� �����
	class lap // ��������������� ��������� ������ - ���� - �� ������ ����������� ������
	{
		template<typename imitator>
		class Node // ��������� ����������� ������
		{
		public: // �.�. ������ ��� ������������ ������ ����������� ������
			imitator data; // ������ ���������� 
			Node* pointer_next; // ��������� �� ��������� ��������� 
			Node* pointer_previous; // ��������� �� ���������� ���������

			Node(imitator data = imitator(), Node* pointer_next = nullptr, Node* pointer_previous = nullptr) { // ������ ��������� 
				this->data = data; // ���������� ������ 
				this->pointer_next = pointer_next; // ��������� � ������ �����������
				this->pointer_previous = pointer_previous; // ��������� � ������ �����������
			}
		};

		int size; // ����������� ������
		Node<imitator>* head; // ��������� �� ������ �������
		Node<imitator>* teil; // ��������� �� ��������� ������� 

	public:
		// ���� ����������
		void to_end(imitator data) { // ��������� ������ � ����� ������
			if (teil == nullptr) { // ���� ������ ������
				teil = new Node<imitator>(data, head, teil); // ������ ������ ������� � ��������� �� ���� teil
				teil->pointer_next = head; // ��������������� �����
				head->pointer_previous = head; // ��������������� ����� 
				head = teil; // head ��������� �� ������ �������
			}
			else { // ���� ���� �������� � ������
				teil = new Node<imitator>(data, nullptr, teil); // ������ ����� ��������� � ��������� ��� � ���������� ����������� 
				head->pointer_previous = teil; // �������������� �����
				teil->pointer_next = head; // �������������� �����
				teil->pointer_previous->pointer_next = teil; // ��������� ��������� �� ��������� ������� �������������� ��������� � ��������� ��������� 
			}
			size++; // ����������� ����������� 
		}
		void to_begin(imitator data) { // ��������� ������ � ������ ������
			if (head == nullptr) { // ���� ������ ������
				head = new Node<imitator>(data, head, teil); // ������ ������ ������� � ��������� �� ���� head
				head->pointer_next = head; // �������������� �����
				head->pointer_previous = head; // �������������� �����
				teil = head; // teil ��������� �� ������ �������
			}
			else { // ���� ���� �������� � ������
				head = new Node<imitator>(data, head, teil); // ������ ����� ��������� � ��������� ��� �� ��������� ����������� 
				teil->pointer_next = head; // �������������� �����
				head->pointer_next->pointer_previous = head; // ��������� ��������� �� ���������� ������� ������� ��������� � ������ ��������� 
			}
			size++; // ����������� ����������� 
		}
		void to_position(imitator data, int position) { // ���������� ��������� �� ������� 
			if (position <= 0) // ����������� ������������� 
				to_begin(data); // ���������� � ������ 
			else if (position >= size - 1) // ����������� ������������� 
				to_end(data); // ���������� � ����� 
			else { // ���� ������� �� �������� � �� ���������
				if (position > size / 2) { // �� teil
					position = size - position - 1; // �������� ������� ��� ������ � �����
					Node<imitator>* current = teil; // �������� ����� �������� � �����
					for (; position > 0; position--) // ���� �� ����� �� ������������� �������� 
						current = current->pointer_previous; // ������� ��������� �� ���������� ��������� 
					current->pointer_previous = new Node<imitator>(data, current, current->pointer_previous); // ������ ����� ��������� 
					current->pointer_previous->pointer_previous->pointer_next = current->pointer_previous; // ����������� �����
				}
				else { // �� head
					Node<imitator>* current = head; // �������� ����� ��������� � ������
					for (; position > 1; position--) // ���� �� ����� �� ������������ �������� 
						current = current->pointer_next; // ������� ��������� �� ��������� ������� 
					current->pointer_next = new Node<imitator>(data, current->pointer_next, current); // ������ ���������
					current->pointer_next->pointer_next->pointer_previous = current->pointer_next; // ��������������� �����
				}
				size++; // ����������� ����������� 
			}
		}

		// ���� ��������
		void out_end() { // ������� �������� �� ������ ������ 
			Node<imitator>* delete_teil = teil; // ��������� teil, ����� ����� ��� ������� 
			teil = teil->pointer_previous; // ���������� teil �� ������������� ������� 
			if (teil == nullptr) // ���� � ������� ����� ���� ������� 
				head = nullptr; // ��������� head � ������� 
			else { // ���� ���� ������ �������� 
				teil->pointer_next = head; // ����� ���������� �������� ��� ���������
				head->pointer_previous = teil; // ��������������� �����
			}
			delete delete_teil; // ������� ��������� ��� head 
			size--; // ��������� ����������� 
		}
		void out_begin() { // ������� �������� �� ������ ������ 
			Node<imitator>* delete_head = head; // ��������� head, ����� ����� ��� ������� 
			head = head->pointer_next; // ���������� head �� ������ ������� 
			if (head == nullptr) // ���� � ������� ����� ���� ������� 
				teil = nullptr; // ��������� teil � ������� 
			else { // ���� ���� �������� 
				head->pointer_previous = teil; // ����� ������ ��������� ��� ���������
				teil->pointer_next = head; // ��������������� ����� 
			}
			delete delete_head; // ������� ��������� ��� head 
			size--; // ��������� ����������� 
		}
		void out_position(int position) { // �������� �� ������� 
			if (position <= 0) // ����������� ������������� 
				out_begin(); // ���������� � ������ 
			else if (position >= size - 1) // ����������� ������������� 
				out_end(); // ���������� � ����� 
			else { // ���� ������� �� �������� � �� ���������
				if (position - 1 > size / 2) { // �� teil
					position = size - position; // �������� ������� ��� ������ � ����� 
					Node<imitator>* current = teil; // �������� ����� � �����
					for (; position > 0; position--) // ���� �� ����� ������ �������
						current = current->pointer_previous; // ������� � ���������� �������� 
					Node<imitator>* delete_current = current; // ��������� teil, ����� ����� ��� ������� 
					Node<imitator>* front_current = current->pointer_next; // ��������� �� ��������� �������
					current = current->pointer_previous; // ���������� teil �� ������������� ������� 
					front_current->pointer_previous = current; // �������� �����
					current->pointer_next = front_current; // ������ �����
					delete delete_current; // ������� ��������� ��� head
				}
				else { // �� head
					Node<imitator>* current = head; // �������� � ������
					for (; position > 0; position--) // ���� �� ����� ������ �������
						current = current->pointer_next; // ��������� � ���������� ����������
					Node<imitator>* delete_current = current; // ��������� head, ����� ����� ��� ������� 
					Node<imitator>* back_current = current->pointer_previous; // ��������� �� ��������� ������� 
					current = current->pointer_next; // ���������� head �� ������ �������  
					back_current->pointer_next = current; // ������ �����
					current->pointer_previous = back_current; // �������� �����
					delete delete_current; // ������� ��������� ��� head 
				}
				size--; // ����������� ����������� 
			}
		}

		// �������������� ���� 
		int get_size() { // ��������� ���������� ��������� � ������ 
			return this->size; // ������� ����������� 
		}
		imitator& operator[](int iterator) { // ���������� ��� ������ 
			if (iterator - 1 > size / 2) { // �� teil
				iterator = size - iterator - 1; // �������� ������� ��� ������ � �����
				Node<imitator>* current = teil; // �������� ����� � �����
				for (; iterator > 0; iterator--) // ���� �� ����� ������ �������
					current = current->pointer_previous; // ��������� � ����������� ��������
				return current->data; // ���������� ������ �� ������
			}
			else { // �� head
				Node<imitator>* current = head; // �������� ����� � ������ 
				for (; iterator > 0; iterator--) // ���� �� ����� ������ �������
					current = current->pointer_next; // ��������� � ���������� �������� 
				return current->data; // ���������� ������ �� ������
			}
		}

		// ������������/����������
		lap() { // �������� ������� ������ 
			size = 0; // ������� ����������� 
			head = nullptr; // ��� �����������
			teil = nullptr; // ��� �����������
		}
		~lap() { // ������ �������� ������ 
			while (size > 0) // ���� �� �������� �������� � ������  
				out_begin(); // ������� ������ �������� 
		}
	};

	//////////////////////////////////////////////////////////////////////////
	/*									����								*/
	//////////////////////////////////////////////////////////////////////////

	template <typename imitator> // ���� �� ������ ������������ ������
	class stack 
	{
		template<typename imitator> 
 		class Node // ��������� �����
		{
		public: // �.�. ������ ��� ������������ ������ �����
			imitator data; // ������ ���������� 
			Node* pointer_next; // ��������� �� ������ ��������� 

			Node(imitator data = imitator(), Node* pointer_next = nullptr) { // ������ ��������� 
				this->data = data; // ���������� ������ 
				this->pointer_next = pointer_next; // ��������� � ������� ������������
			}
		};

		int size; // ����������� �����
		Node<imitator>* head; // ��������� �� ������ ������� 

	public:
		//���������� �������� � ����
		void to_stack(imitator data) { // ��������� �������� � ������ ����� 
			head = new Node<imitator>(data, head); // ������ ����� ��������� 
			size++; // ����������� ����������� 
		}

		//�������� �������� �� ����� 
		void out_stack() { // ������� �������� �� ������ �����
			Node<imitator>* safe_head = head; // ��������� head, ����� ����� ��� ������� 
			head = head->pointer_next; // ���������� head �� ������� ������� 
			delete safe_head; // ������� ��������� ��� head 
			size--; // ��������� ����������� 
		}

		// �������������� ���� 
		int get_size() { // ��������� ���������� ��������� � �����
			return this->size; // ������� ����������� 
		}

		// ������������/����������
		stack() { // ������ ������ ����
			size = 0; // ������� �����������
			head = nullptr; // ��� �����������
		}
		~stack() { // ������ ������� �����
			while (size > 0) // ���� ���� �������� 
				out_stack(); // ������� �������� 
		}
	};

	//////////////////////////////////////////////////////////////////////////
	/*									�������								*/
	//////////////////////////////////////////////////////////////////////////

	template <typename imitator> // ������� - �� ������ ����������� ������
	class queue 
	{
		template<typename imitator>
		class Node // ��������� ��� �������
		{
		public: // �.�. ������ ��� ������������ ������ �������
			imitator data; // ������ ���������� 
			Node* pointer_next; // ��������� �� ��������� ��������� 
			Node* pointer_previous; // ��������� �� ���������� ���������

			Node(imitator data = imitator(), Node* pointer_next = nullptr, Node* pointer_previous = nullptr) { // ������ ��������� 
				this->data = data; // ���������� ������ 
				this->pointer_next = pointer_next; // ��������� � ������ �����������
				this->pointer_previous = pointer_previous; // ��������� � ������ �����������
			}
		};

		int size; // ����������� �������
		Node<imitator>* head; // ��������� �� ������ �������
		Node<imitator>* teil; // ��������� �� ��������� ������� 

	public:
		// ���������� ��������� � �������
		void to_queue(imitator data) { // ��������� ������ � ����� �������
			if (teil == nullptr) { // ���� ������ �������
				teil = new Node<imitator>(data, head, teil); // ������ ������ ������� � ��������� �� ���� teil
				head = teil; // head ��������� �� ������ �������
			}
			else { // ���� ���� �������� � �������
				teil = new Node<imitator>(data, nullptr, teil); // ������ ����� ��������� � ��������� ��� � ���������� ����������� 
				teil->pointer_previous->pointer_next = teil; // ��������� ��������� �� ��������� ������� �������������� ��������� � ��������� ��������� 
			}
			size++; // ����������� ����������� 
		}

		// ���������� ��������� �� �������
		void out_queue() { // ������� �������� �� ������ �������
			Node<imitator>* safe_teil = head; // ��������� head, ����� ����� ��� ������� 
			head = head->pointer_next; // ���������� head �� ������ ������� 
			if (head == nullptr)  // ���� � ������� ����� ���� ������� 
				teil = nullptr; // ��������� teil � ������� 
			else // ���� ���� �������� 
				head->pointer_previous = nullptr; // ����� ������ ��������� ��� ���������
			delete safe_teil; // ������� ��������� ��� head 
			size--; // ��������� ����������� 
		}

		// �������������� ���� 
		int get_size() { // ��������� ��������� ��������� � ������� 
			return size; // ���������� ����������� 
		}

		// ������������/����������
		queue() { // ������ ������ �������
			size = 0; // ������� �����������
			head = nullptr; // ��� �����������
			teil = nullptr; // ��� �����������
		}
		~queue() { // ������ ������� ������� 
			while (size > 0) // ���� ���� �������� 
				out_queue(); // ������� �������� 
		}
	};

	//////////////////////////////////////////////////////////////////////////
	/*									���									*/
	//////////////////////////////////////////////////////////////////////////

	template <typename imitator> // ��� - �� ������ ����������� ������
	class deque 
	{
		template<typename imitator>
		class Node // ��������� ��� ����
		{
		public: // �.�. ������ ��� ������������ ������ ����
			imitator data; // ������ ���������� 
			Node* pointer_next; // ��������� �� ��������� ��������� 
			Node* pointer_previous; // ��������� �� ���������� ���������

			Node(imitator data = imitator(), Node* pointer_next = nullptr, Node* pointer_previous = nullptr) { // ������ ��������� 
				this->data = data; // ���������� ������ 
				this->pointer_next = pointer_next; // ��������� � ������ �����������
				this->pointer_previous = pointer_previous; // ��������� � ������ �����������
			}
		};

		int size; // ����������� ����
		Node<imitator>* head; // ��������� �� ������ �������
		Node<imitator>* teil; // ��������� �� ��������� �������

	public:
		// ���� ����������
		void to_end(imitator data) { // ��������� ������ � ����� ����
			if (teil == nullptr) { // ���� ������ ���
				teil = new Node<imitator>(data, head, teil); // ������ ������ ������� � ��������� �� ���� teil
				head = teil; // head ��������� �� ������ �������
			}
			else { // ���� ���� �������� � ����
				teil = new Node<imitator>(data, nullptr, teil); // ������ ����� ��������� � ��������� ��� � ���������� ����������� 
				teil->pointer_previous->pointer_next = teil; // ��������� ��������� �� ��������� ������� �������������� ��������� � ��������� ��������� 
			}
			size++; // ����������� ����������� 
		}
		void to_begin(imitator data) { // ��������� ������ � ������ ����
			if (head == nullptr) { // ���� ������ ���
				head = new Node<imitator>(data, head, teil); // ������ ������ ������� � ��������� �� ���� head
				teil = head; // teil ��������� �� ������ �������
			}
			else { // ���� ���� �������� � ����
				head = new Node<imitator>(data, head, nullptr); // ������ ����� ��������� � ��������� ��� �� ��������� ����������� 
				head->pointer_next->pointer_previous = head; // ��������� ��������� �� ���������� ������� ������� ��������� � ������ ��������� 
			}
			size++; // ����������� ����������� 
		}

		// ���� ��������
		void out_end() { // ������� �������� �� ����� ����
			Node<imitator>* safe_teil = teil; // ��������� teil, ����� ����� ��� ������� 
			teil = teil->pointer_previous; // ���������� teil �� ������������� ������� 
			if (teil == nullptr) // ���� � ������� ����� ���� ������� 
				head = nullptr; // ��������� head � ������� 
			else
				teil->pointer_next = nullptr; // ����� ���������� �������� ��� ���������
			delete safe_teil; // ������� ��������� ��� head 
			size--; // ��������� ����������� 
		}
		void out_begin() { // ������� �������� �� ������ ���� 
			Node<imitator>* safe_teil = head; // ��������� head, ����� ����� ��� ������� 
			head = head->pointer_next; // ���������� head �� ������ ������� 
			if (head == nullptr) // ���� � ������� ����� ���� ������� 
				teil = nullptr; // ��������� teil � ������� 
			else 
				head->pointer_previous = nullptr; // ����� ������� ��������� ��� ���������
			delete safe_teil; // ������� ��������� ��� head 
			size--; // ��������� ����������� 
		}

		// �������������� ���� 
		int get_size() { // ��������� ���������� ��������� � ����
			return size; // ������� ����������� 
		}
		
		// �����������/����������
		deque() { // ������ ������ ���
			size = 0; // ������� �����������
			head = nullptr; // ��� �����������
			teil = nullptr; // ��� �����������
		}
		~deque() { // ������ ������� ����
			while (size > 0) // ���� ���� �������� 
				out_begin(); // ������� �������� 
		}
	};

	//////////////////////////////////////////////////////////////////////////
	/*									������								*/
	//////////////////////////////////////////////////////////////////////////

	template<typename imitator> // ������ - �� ������
	class tuple
	{

	};

	//////////////////////////////////////////////////////////////////////////
	/*									�������								*/
	//////////////////////////////////////////////////////////////////////////

	template<typename imitator> // ������� - �� ������
	class map
	{

	};

	//////////////////////////////////////////////////////////////////////////
	/*								�������� ������							*/
	//////////////////////////////////////////////////////////////////////////

	template <typename imitator> // �������� ������
	class binary_tree
	{
		template<typename imitator>
		class Node // ��������� ��������� ������
		{
		public: // �.�. ������ ��� ������������ ������ ��������� �������
			imitator data; // ������ ���������� 
			Node* pointer_left; // ��������� �� ����� ��������� 
			Node* pointer_right; // ��������� �� ������ ���������
			Node* pointer_parent; 

			Node(imitator data, Node* pointer_left, Node* pointer_right, Node* pointer_parent) { // ������ ��������� 
				this->data = data; // ���������� ������ 
				this->pointer_left = pointer_left; // ��������� � ������ �����������
				this->pointer_right = pointer_right; // ��������� � ������ �����������
				this->pointer_parent = pointer_parent;
			}
		};

		int size; // ����������� ������
		Node<imitator>* head; // ��������� �� ������ �������

		void delete_data_to_node(Node<imitator>* delete_node) { // �������� �� ���������� 
			if (delete_node == nullptr) // ���� ������ ���������� �� ����������
				return; // ������� �� �������� 
			else if (delete_node->pointer_left != nullptr || delete_node->pointer_right != nullptr) // ���� �� ������
				if (delete_node->pointer_left == nullptr && delete_node->pointer_right != nullptr) { // ���� ������ ���, � ������ ����
					delete_node->pointer_left = delete_node->pointer_right->pointer_left; // ������� ����� ��������� �� ����� ��������� ������� ��������
					delete_node->data = delete_node->pointer_right->data; // �������� ������ � ������� ��������
					Node<imitator>* temp_delete_node = delete_node->pointer_right; // ��������� ��������� �� ������ ������� 
					delete_node->pointer_right = delete_node->pointer_right->pointer_right; // ������� ������ ��������� �� ������ ��������� ������� �������� 
					delete temp_delete_node; // ������� ������ ������� 
				}
				else if (delete_node->pointer_left != nullptr && delete_node->pointer_right == nullptr) { // ���� ������� ���, � ����� ����
					delete_node->pointer_right = delete_node->pointer_left->pointer_right; // ������� ������ ��������� �� ������ ��������� ������ ��������
					delete_node->data = delete_node->pointer_left->data; // �������� ������ � ������ �������� 
					if (delete_node->pointer_right != nullptr)
						delete_node->pointer_right->pointer_parent = delete_node;
					Node<imitator>* temp_delete_node = delete_node->pointer_left; // ��������� ��������� �� ����� ������� 
					delete_node->pointer_left = delete_node->pointer_left->pointer_left; // ������� ����� ��������� �� ����� ��������� ������ �������� 
					if (delete_node->pointer_left != nullptr)
						delete_node->pointer_left->pointer_parent = delete_node;
					delete temp_delete_node; // ������� ����� ������� 
				}
				else { // ���� � ������ �������, � ����� ������� �� ������ 
					imitator temp_data = delete_node->pointer_right->data; // ��������� ������ ��� ���������� ��������
					delete_data_to_node(delete_node->pointer_right); // ������� ������ ������� 
					delete_node->data = temp_data; // ���������� ������ � ������� �������� 
				}
			else { // ���� ������� ������
				if (delete_node->pointer_parent == nullptr) // ���� ������� ������
					delete_node->pointer_parent = head; // ��������� ��������������� ���� �� ������
				if (delete_node->data > delete_node->pointer_parent->data) // ���� �������� ������ �������
					delete_node->pointer_parent->pointer_right = nullptr; // �������� ������ ��������� ��������
				else if (delete_node->data < delete_node->pointer_parent->data) // ���� ������� ����� �������
					delete_node->pointer_parent->pointer_left = nullptr; // �������� ����� ��������� �������� 
				delete delete_node; // ������� ������� 
			}
		}

		void add_data_ctrl(imitator data, Node<imitator>* current) { // ���������� ������ 
			if (head == nullptr) // ���� ��� ���������
				head = new Node<imitator>(data, head, head, nullptr); // ������ ������ 
			else { // ���� ���� �������� 
				if (data > current->data) // ���� ����������� ������ ������ ���, ��� ����������� � ������� ����������
					if (current->pointer_right == nullptr) // ���� ������� �������� �� ����������
						current->pointer_right = new Node<imitator>(data, nullptr, nullptr, current); // ������ ����� ������ �������
					else // ���� ������ ������� ��� ����������
						add_data_ctrl(data, current->pointer_right); // ��� ����������� � ������ ������������ ������ ��������� 
				else if (data < current->data) // ���� ����������� ������ ������ ���, ��� ����������� � ������� ����������
					if (current->pointer_left == nullptr) // ���� ������ �������� �� ����������
						current->pointer_left = new Node<imitator>(data, nullptr, nullptr, current); // ������ ����� ����� ������� 
					else // ���� ����� ������� ��� ���������� 
						add_data_ctrl(data, current->pointer_left); // ��� ������������ � ����� ������������ ��������� 
				else // ���� ����� ������ ��� ����
					return; // ������ �� ��������� 
			}
		}

		void show_in_line_ctrl(Node<imitator>* current) { // ���������� � ���� ������ 
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

		void clear_ctrl(Node<imitator>* current) { // �������� ����� ������ 
			if (current != nullptr) { // ���� ������� �� �������� �������
				if (current->pointer_left != nullptr) // ���� ����� ���� ��������
					clear_ctrl(current->pointer_left); // ������ ����� �����
				if (current->pointer_right != nullptr) // ���� ������ ���� �������� 
					clear_ctrl(current->pointer_right); // ������ ������ �����
			}
			if (current == nullptr) // ���� ������ ��� ������ 
				return; // ������� �� �������� 
			if (current->pointer_left == nullptr && current->pointer_right == nullptr) { // ���� �������� ������ 
				delete_data_to_node(current); // ������� ������ 
			}
		}

		Node<imitator>* find(imitator data) { // ���� ��������� �� ��������� ������ 
			if (head == nullptr) // ���� ��� ��������� 
				return nullptr; // ���������� ������� 
			else { // ���� ���� �������� 
				Node<imitator>* current = head; // �������� ����� � ������ 
				while (current != nullptr) // ���� ������ �������������� ������� 
					if (data == current->data) // ���� ������� ������ ��������� � ������� ����������
						break; // ������� �� ����� 
					else if (data > current->data) // ���� ������� ������ ������ ������ ����������
						current = current->pointer_right; // ��������� ������ 
					else if (data < current->data) // ���� ������� ������ ������ ������ ����������
						current = current->pointer_left; // ��������� ����� 
				if (current == nullptr) // ���� �� �� ��� ������ �������������� ������� 
					return nullptr; // ���������� ������� 
				else // ���� ������� ����� �������
					return current; // ���������� ��������� 
			}
		}

	public:
		void add_data(imitator data) { // ���������� ������ � ������ 
			add_data_ctrl(data, head); // ������� �����������: ������ ��������� ���� ������ ��� ��������� �� ���������
			size++; // ����������� ����������� 
		}

		bool is_data(imitator data) { // �������� ��������������� �������� � ������
			Node<imitator>* temp_node = find(data); // �������� ������� ������ �������� 
			if (temp_node != nullptr) // ���� ���� ���������, ���������� ������� ������
				return true; // ��, ���� ����� �������
			else // ���� ��� ����������, ����������� ������� ������
				return false; // ���, ������ �������� ���
		}

		void delete_data(imitator data) { // ������� ������ �� ������ 
			Node<imitator>* delete_node = find(data); // ���� ���������, ���������� ��������� ������ 
			if (delete_node != nullptr) // ���� ��������� ��������� ������ ���� 
				size--; // ���������� ���������� 
			delete_data_to_node(delete_node); // ������� �� ���������� 
			if (size == 0)
				head = nullptr;
		}

		// �������������� ���� 
		int get_size() { // ��� ��������� ���������� ��������� � ������
			return this->size; // ���������� ����������� 
		}

		// �������� ����
		void show_in_line_consolas() { // �����-������� ����� ������ 
			show_in_line_ctrl(head); // ������� �����������: ������ ��������� ���� ������ ��� ��������� �� ���������
		}

		// ������������/����������
		binary_tree() { // ������ ������ ������ 
			size = 0; // ��� ���������
			head = nullptr; // ��� ���������
		}
		~binary_tree() { // ������� ������
			clear_ctrl(head); // ������� �����������: ������ ��������� ���� ������ ��� ��������� �� ���������
			size = 0; // �������� ����������� 
			head = nullptr;
		}
	};

	//////////////////////////////////////////////////////////////////////////
	/*									�����	 							*/
	//////////////////////////////////////////////////////////////////////////

	/////////////////////////////��������� 2D �����///////////////////////////
	
	template <typename imitator>
	class plane_descartes_point
	{
		imitator x; // �������� �� ��������
		imitator y; // �������� �� �������� 

	public:
		// ������������ ����
		// �������� 
		plane_descartes_point operator+(plane_descartes_point point) { // �������� ���� �����
			plane_descartes_point temp_point(point.x, point.y); // �������� �������������� �����
			temp_point.x += this->x; // ���������� �������� 
			temp_point.y += this->y; // ���������� �������� 
			return temp_point; // ���������� �������������� �����
		}
		void operator+=(plane_descartes_point point) { // ����������� �����
			this->x += point.x; // ���������� ��������
			this->y += point.y; // ���������� �������� 
		}
		// ����������
		plane_descartes_point operator-(plane_descartes_point point) { // ��������� ���� �����
			plane_descartes_point temp_point(point.x, point.y); // �������� �������������� �����
			temp_point.x -= this->x; // �������� �������� 
			temp_point.y -= this->y; // �������� ��������
			return temp_point; // ���������� �������������� �����
		}
		void operator-=(plane_descartes_point point) {
			this->x -= point.x;
			this->y -= point.y;
		}
		//�������������� ���� 
		imitator get_x() { // ��������� �������� �� �������
			return this->x; // ������� ����������
		}
		imitator get_y() { // ��������� �������� �� �������� 
			return this->y; // ������� ����������
		}

		// ������������/����������
		plane_descartes_point() { // �������� ����� �� ����������� ���������
			this->x = 0; // 0 �� �������� 
			this->y = 0; // 0 �� �������� 
		}
		plane_descartes_point(imitator x, imitator y) { // �������� ����� �� ����������� 
			this->x = x; // ����������� ��������
			this->y = y; // ����������� ��������
		}
		plane_descartes_point(plane_descartes_point& point) { // ����������� ������ ����� 
			this->x = point.x; // ����������� ��������
			this->y = point.y; // ����������� ��������
		}
		~plane_descartes_point() { // �������� �����
			this->x = this->y = NULL; // ��������� �����
		}
	};

	///////////////////////////////�������� �����/////////////////////////////

	template <typename imitator>
	class polar_point
	{
		imitator r;
		imitator fi;

	public:
		//�������������� ���� 
		imitator get_r() {
			return this->x;
		}
		imitator get_fi() {
			return this->fi;
		}

		// ������������/����������
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

	/////////////////////////////��������� 3D �����///////////////////////////

	template <typename imitator>
	class space_descartes_point
	{
		imitator x;
		imitator y;
		imitator z;

	public:
		//�������������� ���� 
		imitator get_x() {
			return this->x;
		}
		imitator get_y() {
			return this->y;
		}
		imitator get_z() {
			return this->z;
		}

		// ������������/����������
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

	////////////////////////////�������������� �����//////////////////////////

	template <typename imitator>
	class cylindrical_point
	{
		imitator x;
		imitator y;
		imitator fi;

	public:
		//�������������� ���� 
		imitator get_x() {
			return this->x;
		}
		imitator get_y() {
			return this->y;
		}
		imitator get_fi() {
			return this->fi;
		}

		// ������������/����������
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

	/////////////////////////////����������� �����////////////////////////////

	template <typename imitator>
	class spherical_point
	{
 
	};

	//////////////////////////////////////////////////////////////////////////
	/*							����������� ����� 							*/
	//////////////////////////////////////////////////////////////////////////

	template<typename imitator>
	class complex
	{
		imitator Re; // �������������� ����� 
		imitator Im; // ������ ����� 

	public:
		//�������������� ���� 
		imitator get_Re() {
			return this->Re;
		}
		imitator get_Im() {
			return this->Im;
		}
		imitator modul() {
			return this->re * this->re + this->im * this->im;
		}

		// ������������ ���� 
		// �������� �������� 
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

		// �������� ����������
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

		// �������� ���������
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

		// �������� ���� 
		void show() {
			std::cout << this->Re << " + ( " << this->Im << "i )" << "\n";
		}

		// ������������
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