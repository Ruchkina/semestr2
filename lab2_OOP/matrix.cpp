#include "matrix.h"

#include <fstream>
#include <iostream>


template<typename T>

Matrix<T>::Matrix(unsigned int row, unsigned int column)
{
    this->column = column;
    this->row = row;
        
    data = new T * [row];
	for (int i = 0; i < row; i++)
		data[i] = new T[column];

    printf("Constructor\n");
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

    std::cout << "Constructor of copy\n";
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(Matrix<T> const& matr)
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

	std::cout << "\nOperator =\n";
    return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator+= (Matrix<T>& matr)
{
    for (int i = 0; i < matr.row; i++)
    {
        for (int j = 0; j < matr.column; j++)
        {
            T result = this->data[i][j] + matr.data[i][j];
            this->data[i][j] = result;
        }
    }
    std::cout << "\nOperator +=\n";
    return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator-= (Matrix<T>& matr)
{
    for (int i = 0; i < matr.row; i++)
    {
        for (int j = 0; j < matr.column; j++)
        {
            T result = this->data[i][j] - matr.data[i][j];
            this->data[i][j] = result;
        }
    }
    std::cout << "\nOperator -=\n";                         
    return *this;
}

template<typename T>
Matrix<T> operator+(Matrix<T>& matr1, Matrix<T>& matr2)
{
    Matrix<T> temp(matr1);
    temp += matr2;
    return temp;
}

template<typename T>
Matrix<T> operator-(Matrix<T>& matr1, Matrix<T>& matr2)
{
    Matrix<T> temp(matr1);
    temp -= matr2;
    return temp;
}

template<typename T>
Matrix<T> operator*(Matrix<T>& matr1, Matrix<T>& matr2)
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
Matrix<T> operator+(Matrix<T>& matr1, double num)
{
    Matrix<T> result(matr1.row, matr1.column);
    for (int i = 0; i < matr1.row; i++) {
        for (int j = 0; j < matr1.column; j++) {
            result.data[i][j] += num;
        }
    }
    std::cout << "\nOperator + num\n";
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