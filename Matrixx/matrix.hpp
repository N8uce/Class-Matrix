#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
using namespace std;

struct MatrixError { // базовый класс для ошибок
   virtual ~MatrixError() {} // деструктор
   virtual const char *what() const=0; // сообщение для печати
};
struct Matrixwrongsize: MatrixError {
   const char *what() const {return "Размеры матриц должны быть одинаковы";} // сообщение для печати
};
struct Matrixwrongmult: MatrixError {
   const char *what() const {return "Количество столбцов первой матрицы должно равняться количеству строк второй";} // сообщение для печати
};
struct MatrixBadindex: MatrixError {
   const char *what() const {return "Выход за пределы размеров матрицы";} // сообщение для печати
};

class Matrix
{
   int n;//строка матрицы
   int m;// столбец матрицы
   double **mat;//двумерный массив матрицы
   public:
   Matrix(int n, int m);//конструктор
   Matrix(const Matrix&);//конструктор копий
   ~Matrix();//деструктор
   Matrix transp() const;//транспонировать матрицу
   //перегрузка операции сложения двух матрицы
   friend Matrix operator+(const Matrix &,const Matrix &);
   //перегрузка операции вычитания двух матрицы
   friend Matrix operator-(const Matrix &,const Matrix &);
   //перегрузка операции умножения двух матрицы
   Matrix operator*(const Matrix &)const;
   //перегрузка операции присваивания для матриц
   Matrix &operator=(const Matrix &);
   //перегрузка операции () для матрицы
   double &operator()(int,int);
   double operator()(int,int)const;
  //перегрузка операции ввода матрицы
   friend istream& operator>>(istream&, Matrix&);
  //перегрузка операции вывода матрицы
   friend ostream& operator<<(ostream&, const Matrix&);
};

#endif
