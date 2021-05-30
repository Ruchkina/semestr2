#include <iostream>
#include <fstream>

#include "matrix.cpp"

int main()
{
    Matrix<int> matrix1(2, 2);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            matrix1.SetVal(i, j, j);
        }
    }
    std::cout << "matrix1:" << std::endl;
    std::cout << matrix1;

    double valueDouble = 4.15;
    Matrix<double> matrix2(2, 2);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            matrix2.SetVal(i, j, valueDouble);
        }
    }
    std::cout << "matrix2:" << std::endl;
    std::cout << matrix2;


    //оператор =
    std::cout << "______matrix_op = matrix1______" << std::endl;
    Matrix<int> matrix_op (2, 2);
    matrix_op = matrix1;
    std::cout << "matrix_op:" << std::endl;
    std::cout << matrix_op << std::endl;
    
    //оператор +=
    std::cout << "______matrix_op += matrix1_______" << std::endl;
    matrix_op += matrix1;
    std::cout << "matrix_op" << std::endl;
    std::cout << matrix_op << std::endl;

    //оператор +
    Matrix<int> matrix_sum(2, 2);

    matrix_sum = matrix1 + matrix_op;

    std::cout << matrix_sum << std::endl;

    //оператор -
    std::cout << "______matrix1 - matrix_op_______" << std::endl;
    std::cout << "matrix1" << std::endl;
    std::cout << matrix1;
    std::cout << "matrix_op" << std::endl;
    std::cout << matrix_op << std::endl;
    Matrix<int> matrix_subtraction(2, 2);
    matrix_subtraction = matrix1 - matrix_op;
    std::cout << matrix_subtraction << std::endl;
    

    //оператор *
    std::cout << "______matrix1 * matrix_op_______" << std::endl;
    std::cout << "matrix1" << std::endl;
    std::cout << matrix1;
    std::cout << "matrix_op" << std::endl;
    std::cout << matrix_op << std::endl;
    Matrix<int> matrix_mult = matrix1 * matrix_op;
    std::cout << matrix_mult << std::endl;

    //оператор + с числом
    std::cout << "______matrix2 + 4,1_______" << std::endl;
    std::cout << "matrix2" << std::endl;
    std::cout << matrix2 << std::endl;
    Matrix<double> matrix_sumN = matrix2 + (4,1);
    std::cout << "matrix_sumN" << std::endl;
    std::cout << matrix_sumN << std::endl;


    //оператор - с числом
    std::cout << "______matrix2 - 4,1_______" << std::endl;
    std::cout << "matrix2" << std::endl;
    std::cout << matrix2;
    Matrix<double> matrixRazn = matrix2 - (4, 1);
    std::cout << "matrixRazn" << std::endl;
    std::cout << matrixRazn << std::endl;


    //оператор * с числом
    std::cout << "______matrix2 * 4,1_______" << std::endl;
    std::cout << "matrix2" << std::endl;
    std::cout << matrix2;
    Matrix<double> matrixMult = matrix2 * (4.1);
    std::cout << "matrixMult" << std::endl;
    std::cout << matrixMult << std::endl;



    /*std::cout << "-------------------" << std::endl;
    
    Iterator<int> it ( matrix1 );
    std::cout << matrix1 << std::endl;
    for (int i = 0; i < (matrix1.get_m() * matrix1.get_n()); i++) {
        std::cout << "MATRIX: ";
        std::cout << it.value() << std::endl;
        it.next();
    }   */ 
    std::cout << "-------------------" << std::endl;

    Matrix<int> matrixIter(3, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int val = i + j % 10;
            matrixIter.SetVal(i, j, val);
        }
    }

    std::cout << matrixIter << std::endl;

    Iterator<int> iter (matrixIter);
    iter = matrixIter.iterator_begin();
    do 
    {
        std::cout << "MATRIX: ";
        std::cout << iter.value() << std::endl;
        iter.next();
    } while (!iter.is_end());

    std::cout << "MATRIX: ";
    std::cout << iter.value() << std::endl;

}