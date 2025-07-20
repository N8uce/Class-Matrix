#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
using namespace std;

struct MatrixError { // ������� ����� ��� ������
   virtual ~MatrixError() {} // ����������
   virtual const char *what() const=0; // ��������� ��� ������
};
struct Matrixwrongsize: MatrixError {
   const char *what() const {return "������� ������ ������ ���� ���������";} // ��������� ��� ������
};
struct Matrixwrongmult: MatrixError {
   const char *what() const {return "���������� �������� ������ ������� ������ ��������� ���������� ����� ������";} // ��������� ��� ������
};
struct MatrixBadindex: MatrixError {
   const char *what() const {return "����� �� ������� �������� �������";} // ��������� ��� ������
};

class Matrix
{
   int n;//������ �������
   int m;// ������� �������
   double **mat;//��������� ������ �������
   public:
   Matrix(int n, int m);//�����������
   Matrix(const Matrix&);//����������� �����
   ~Matrix();//����������
   Matrix transp() const;//��������������� �������
   //���������� �������� �������� ���� �������
   friend Matrix operator+(const Matrix &,const Matrix &);
   //���������� �������� ��������� ���� �������
   friend Matrix operator-(const Matrix &,const Matrix &);
   //���������� �������� ��������� ���� �������
   Matrix operator*(const Matrix &)const;
   //���������� �������� ������������ ��� ������
   Matrix &operator=(const Matrix &);
   //���������� �������� () ��� �������
   double &operator()(int,int);
   double operator()(int,int)const;
  //���������� �������� ����� �������
   friend istream& operator>>(istream&, Matrix&);
  //���������� �������� ������ �������
   friend ostream& operator<<(ostream&, const Matrix&);
};

#endif
