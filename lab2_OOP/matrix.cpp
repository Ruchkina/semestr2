#include "matrix.h"
#include "iterator.h"

#include <fstream>
#include <iostream>


template<typename T>

Matrix<T>::Matrix(unsigned int row, unsigned int column) // конструктор иниц
{
    this->column = column;
    this->row = row;
        
    data = new T * [row];
	for (int i = 0; i < row; i++)
		data[i] = new T[column];

    //printf("Constructor\n");
    //std::cout << "Вызван конструктор";
}



template<typename T>
Matrix<T>::Matrix(Matrix <T> const& matr) // Конструктор копирования
{
    this->column = matr.column;
    this->row = matr.row;

    this->data = new T * [matr.row];

    for (int i = 0; i < matr.row; i++) {
        this->data[i] = new T[matr.column];
    }

    for (int i = 0; i < matr.row; i++) {
        for (int j = 0; j < matr.column; j++) {
            this->data[i][j] = matr.data[i][j];
        }
    }

    //std::cout << "Constructor of copy\n";
}

//конструктор перемещения
template<typename T>
Matrix<T>::Matrix(Matrix<T>&& matr)
{
    this->row = matr.get_n();
    this->column = matr.get_m();

    matr.iterator_begin = nullptr;

    this->data = new T * [matr.row];
    for (int i = 0; i < matr.row; i++) {
        this->data[i] = new T[matr.column];
    }

    for (int i = 0; i < matr.row; i++) {
        for (int j = 0; j < matr.column; j++) {
            this->data[i][j] = matr.data[i][j];
        }
    }
}



template<typename T>
Matrix<T>& Matrix<T>::operator=(Matrix<T> const& matr) //перегрузка =
{
    this->row = matr.row;
    this->column = matr.column;

    if (this->data != nullptr)
    {
        for (int i = 0; i < row; i++)
            delete this->data[i];
        delete[] this->data;
    }

    this->data = new T * [matr.row];

    for (int i = 0; i < matr.row; i++) {
        this->data[i] = new T[matr.column];
    }

    for (int i = 0; i < matr.row; i++) {
        for (int j = 0; j < matr.column; j++) {
            this->data[i][j] = matr.data[i][j];
        }
    }

	//astd::cout << "\nOperator =\n";
    return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator+= (Matrix<T>& matr)  //перегрузка +=
{
    for (int i = 0; i < matr.row; i++)
    {
        for (int j = 0; j < matr.column; j++)
        {
            T result = this->data[i][j] + matr.data[i][j];
            this->data[i][j] = result;
        }
    }
    //std::cout << "\nOperator +=\n";
    return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator-= (Matrix<T>& matr) //перегрузка -=
{
    for (int i = 0; i < matr.row; i++)
    {
        for (int j = 0; j < matr.column; j++)
        {
            T result = this->data[i][j] - matr.data[i][j];
            this->data[i][j] = result;
        }
    }
    //std::cout << "\nOperator -=\n";                         
    return *this;
}


template<typename T>
Matrix<T> operator+(Matrix<T>& matr1, Matrix<T>& matr2) //перегрузка +
{
    Matrix<T> temp(matr1);
    temp += matr2;
    return temp;
}

template<typename T>
Matrix<T> operator-(Matrix<T>& matr1, Matrix<T>& matr2) //перегрузка -
{
    Matrix<T> temp(matr1);
    temp -= matr2;
    return temp;
}

template<typename T>
Matrix<T> operator*(Matrix<T>& matr1, Matrix<T>& matr2) //перегрузка * (для матриц)
{
    Matrix<T> result(matr1.row, matr2.column);

    for (int i = 0; i < matr1.row; i++) {
        for (int j = 0; j < matr2.column; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < matr1.column; k++)
                result.data[i][j] += matr1.data[i][k] * matr2.data[k][j];
        }
    }
    return result;
}

template<typename T>
Matrix<T> operator+(Matrix<T>& matr1, double num) //перегрузка + для матрицы и числа
{
    int row = matr1.get_n();
    int column = matr1.get_m();
    T noll = 0;
    double qwe = 5.1;

    Matrix<double> oneMatr(row, column);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (i == j)
                oneMatr.SetVal(i, j, qwe);
            else
                oneMatr.SetVal(i, j, noll);
        }
    }
    Matrix<T> result(row, column);
    result = (oneMatr + matr1);
    return result;
}

template<typename T>
Matrix<T> operator-(Matrix<T>& matr1, double num) //перегрузка - для матрицы и числа
{
    int row = matr1.get_n();
    int column = matr1.get_m();
    T noll = 0;
    double qwe = 5.1;

    Matrix<double> oneMatr(row, column);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (i == j)
                oneMatr.SetVal(i, j, qwe);
            else
                oneMatr.SetVal(i, j, noll);
        }
    }
    Matrix<T> result(row, column);
    result = (matr1 - oneMatr);
    return result;
}

template<typename T>
unsigned int Matrix<T>::get_n()
{
    return row;
}

template<typename T>
unsigned int Matrix<T>::get_m()
{
    return column;
}

template<typename T>
T& Matrix<T>::get_elem(unsigned int i, unsigned int j)
{
    return data[i][j];
}

template<typename T>
bool Matrix<T>::is_square()
{
    if (row == column)
        return true;
    else
        return false;
}

template<typename T>
void Matrix<T>::set_elem(unsigned int n, unsigned int m, T& elem)
{
    data[n][m] = elem;
}

template<typename _T>
std::ostream& operator << (std::ostream& out, Matrix<_T>& matr)
{
    int row = matr.get_n();
    int column = matr.get_m();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            out << matr.get_elem(i, j) << "   ";
        out << std::endl;
    }
    return out;
}

//template<typename T>
//Iterator<T> Matrix<T>::iterator_begin()
//{
//    Iterator<T> a (*this);
//    return a;
//}

template<typename T>
Matrix<T> operator*(Matrix<T>& matr1, double num)
{
    int row = matr1.get_n();
    int column = matr1.get_m();
    
    Matrix<double> matr2(row, column);
    Matrix<double> result(row, column);
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            matr2.SetVal(i, j, num);
        }
    }
    std::cout << matr2;

    result = matr1 * matr2;

    return result;
}

template<typename T>
Iterator<T> Matrix<T>::iterator_begin()
{
    Iterator<T> it(*this);
    return it;
}

template<typename T>
Iterator<T> Matrix<T>::iterator_end()
{
    Iterator<T> iter(*this);

    for (; !iter.is_end;)
        iter.next();

    return iter;
}


template<typename T>
bool Iterator<T>::is_end()
{
    return (this->currentRow == this->iRow - 1 && this->currentColumn == this->iColumn - 1);
}

template<typename T>
T Iterator<T>::value()
{
    return this->matrix->get_elem(this->currentRow, this->currentColumn);
}

//template<typename T>
template<typename T>
bool Iterator<T>::operator==(Iterator& b)
{
    return this->value() == b.value();
}

template<typename T>
Iterator<T> Iterator<T>::next()
{
    {
        if (this->currentColumn < (this->iColumn - 1) && (!this->is_end()))
            this->currentColumn++;
        else if (this->currentColumn = this->iColumn && (!this->is_end()))
        {
            if (!this->is_end())
            {
                this->currentRow++;
                this->currentColumn = 0;
            }
        }
        return *this;
    }
}

template<typename T>
Iterator<T>::Iterator(Matrix<T>& matr)
{
    this->matrix = &matr;   
    this->iRow = matr.get_n();
    this->iColumn = matr.get_m();   
    this->currentColumn = 0;
    this->currentRow = 0;
}

template<typename T>
Iterator<T> Iterator<T>::operator++()
{
    if (this->currentColumn < (this->iColumn - 1) && (!this->is_end()))
        this->currentColumn++;
    else if (this->currentColumn = this->iColumn && (!this->is_end()))
    {
        if (!this->is_end())
        {
            this->currentRow++;
            this->currentColumn = 0;
        }
    }
    return *this;
}