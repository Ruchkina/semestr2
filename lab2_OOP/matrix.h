#include <iostream>
#include <fstream>

#define N 2

template<typename T>
class Matrix
{
private:
    T** data;
    unsigned int row;
    unsigned int column;

public:
    Matrix(unsigned int n, unsigned int m);  // ����������� ��� ������� ��������� �������
    Matrix(/*const*/ Matrix <T> const& matr); // ����������� �����������
    //Matrix(Matrix<T> && matr); //����������� �����������
   
    //bool Matrix<T> operator(Matrix<T> const& matr); //
    Matrix<T>& operator= (Matrix<T> const& matr); // ���������� ��������� ������������ (��� 2+ ������)
    Matrix<T>& operator+=(Matrix<T>& matr); // ���������� ��������� +=
    Matrix<T>& operator-=(Matrix<T>& matr); // ���������� ��������� -=

    template<typename T>
    friend Matrix<T> operator+ (Matrix<T>& matr1, Matrix<T>& matr2);

    template<typename _T>
    friend Matrix<_T> operator-(Matrix<_T>& m1, Matrix<_T>& m2);

    template<typename _T>
    friend Matrix<_T> operator*(Matrix<_T>& m1, Matrix<_T>& m2);

    template<typename _T>
    friend Matrix<_T> operator+(Matrix<_T>& m1, double num);

    T& get_elem(unsigned int i, unsigned int j);
    void set_elem(unsigned int i, unsigned int j, T&elem);
    bool is_square();
    unsigned int get_n(); //����� ��������� ����� ����� �������
    unsigned int get_m(); //����� ��������� ����� �������� �������


    void SetVal(unsigned int row, unsigned int column, T& number) { data[row][column] = number; }
    T GetVal(unsigned int row, unsigned int column) { return data[row][column]; }
    /*void printMatr() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                printf("matrix[%d][%d]: %d\n", i, j, this->GetVal(i, j));
        }
    }*/

    
    
    
    ////Matrix() // �����������, ������� �� ��� �� �����
    ////{
    ////    row = 0;
    ////    column = 0;
    ////    data = nullptr;
    ////}



    ~Matrix() // ����������
    {
        for (int i = 0; i < row; i++)
            delete data[i];
        delete[] data;
        std::cout << "destructor\n";
    }
};

