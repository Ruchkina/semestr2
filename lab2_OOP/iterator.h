#pragma once

#ifndef ITERATOR_H
#define ITERATOR_H

#include "matrix.h"


//template<typename T1>
//class Iterator
//{
//private:
//    unsigned int iRow;
//    unsigned int iColumn;
//
//    Matrix<int>* matrix;
//
//    unsigned int currentRow;
//    unsigned int currentColumn;
//
//
//public:
//    Iterator(Matrix<T1> & matr)
//    {
//        this->matrix = &matr;
//        this->iRow = matr.get_n();
//        this->iColumn = matr.get_m();
////        this->currentNumber = &matr.get_elem(0, 0);
//
//    }// конструктор, принимающий объект контейнерного класса, который необходимо обойти с помощью данного итератора
//
//    Iterator next()
//    {
//        if (this->currentColumn < this->iColumn && this->currentColumn <= this->iColumn && this->currentRow <= this->iRow)
//            this->currentColumn++;
//        if (this->currentColumn = this->iColumn && this->currentColumn <= this->iColumn && this->currentRow <= this->iRow)
//        {
//            this->currentRow++;
//            this->currentColumn = 0;
//        }
//    }
//
//    T1 value()
//    {
//        return this->matrix->get_elem(this->currentRow, this->currentColumn);
//    }
//   
//
//};

#endif
