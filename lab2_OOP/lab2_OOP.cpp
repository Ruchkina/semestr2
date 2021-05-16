#include <iostream>
#include <fstream>

#include "matrix.cpp"

int main()
{
    int number = 2;
    int q;

    Matrix<int> matrix1(number, number);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            matrix1.SetVal(i, j, j);
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            q = matrix1.GetVal(i, j);
            printf("matrix2: %d\n", q);
        }
    }

    // конструктор копирования
    Matrix<int> matrix2(matrix1);
   
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            q = matrix2.GetVal(i, j);
            printf("matrix2: %d\n", q);
        }
    }
    //оператор =
    Matrix<int> matrix_op(number, number);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            q = matrix_op.GetVal(i, j);
            printf("matrix_op: %d\n", q);
        }
    }
    matrix_op = matrix1;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            q = matrix_op.GetVal(i, j);
            printf("matrix_op: %d\n", q);
        }
    }
    
    //оператор +=
    matrix_op += matrix1;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            q = matrix_op.GetVal(i, j);
            printf("matrix_op: %d\n", q);
        }
    }
    //оператор -=

    Matrix<int> matrix4(number, number);

    int w = 3;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            matrix4.SetVal(i, j, w);
        }
    }

    matrix_op -= matrix4;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            q = matrix_op.GetVal(i, j);
            printf("matrix_op: %d\n", q);
        }
    }

    //оператор +
    Matrix<int> matrix_sum(number, number);

    matrix_sum = matrix1 + matrix2;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            q = matrix_sum.GetVal(i, j);
            printf("matrix_sum: %d\n", q);
        }
    }

    //оператор -
    Matrix<int> matrix_subtraction(number, number);

    matrix_subtraction = matrix4 - matrix2;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            q = matrix_subtraction.GetVal(i, j);
            printf("matrix_subtraction: %d\n", q);
        }
    }

    //оператор *

    Matrix<int> matrix_mult = matrix4 * matrix2;
    //matrix_mult.printMatr();
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            q = matrix_mult.GetVal(i, j);
            printf("matrix_mult[%d][%d]: %d\n", q, i, j);
        }
    }
    //оператор + с числом
    Matrix<double>matrix_n1(2, 3);
    Matrix<double>matrix_sumN = matrix_n1 + (4,1);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("matrix_sum[%d][%d]: %d\n", i, j, matrix_sumN.GetVal(i, j));
        }
    }


}

