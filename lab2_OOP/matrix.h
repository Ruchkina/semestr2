#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>
#include "iterator.h"

#define N 2

template<typename T>
class Iterator;

template<typename T>
class Matrix
{
private:
    T** data;
    unsigned int row;
    unsigned int column;

public:

    Matrix(unsigned int n, unsigned int m);  // конструктор под матрицу заданного размера
    Matrix(/*const*/ Matrix <T> const& matr); // конструктор копирования
    Matrix(Matrix<T> && matr); //конструктор перемещения
    //bool Matrix<T> operator(Matrix<T> const& matr); //

    Matrix<T>& operator= (Matrix<T> const& matr); // перегрузка оператора присваивания (для 2+ матриц)
    Matrix<T>& operator+=(Matrix<T>& matr); // перегрузка оператора +=
    Matrix<T>& operator-=(Matrix<T>& matr); // перегрузка оператора -=

    template<typename T>
    friend Matrix<T> operator+ (Matrix<T>& matr1, Matrix<T>& matr2);

    template<typename _T>
    friend Matrix<_T> operator-(Matrix<_T>& m1, Matrix<_T>& m2);

    template<typename _T>
    friend Matrix<_T> operator*(Matrix<_T>& m1, Matrix<_T>& m2);

    template<typename _T>
    friend Matrix<_T> operator+(Matrix<_T>& m1, double num);

    template<typename _T>
    friend Matrix<_T> operator- (Matrix<_T>& m1, double num);

    template<typename _T>
    friend Matrix<_T> operator /(Matrix<_T>& m1, double num);

    template<typename _T>
    friend Matrix<_T> operator *(Matrix<_T>& m1, double num);

    template<typename _T>
    friend std::ostream& operator<<(std::ostream& out, Matrix<_T>& matr);

    T& get_elem(unsigned int i, unsigned int j);
    void set_elem(unsigned int i, unsigned int j, T&elem);
    
    bool is_square();
    unsigned int get_n(); //метод получения числа строк матрицы
    unsigned int get_m(); //метод получения числа столбцов матрицы

    Iterator<T> iterator_begin();
    Iterator<T> iterator_end();

    void SetVal(unsigned int row, unsigned int column, T& number) { data[row][column] = number; }
    T GetVal(unsigned int row, unsigned int column) { return data[row][column]; }

    ~Matrix() // деструктор
    {
        for (int i = 0; i < row; i++)
            delete data[i];
        delete[] data;
    }
};



template<typename T1>
class Iterator
{
private:
    unsigned int iRow;
    unsigned int iColumn;

    Matrix<T1>* matrix;

    unsigned int currentRow;
    unsigned int currentColumn;

public:
    Iterator(Matrix<T1>& matr);

    Iterator next();

    T1 value();

    bool is_end();

    Iterator operator++();

    //T& operator*(); //дописать

    bool operator==(Iterator& b);

    bool operator!=(Iterator& b);

};

#endif // MATRIX_H