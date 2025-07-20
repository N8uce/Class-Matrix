#include "matrix.hpp"

istream &operator>>(istream & in, Matrix&a)
{
  for (int i = 0;i<a.n;i++)
   {
   for (int j = 0;j<a.m;j++)
      {
        in>>a.mat[i][j];
      }
   }
   return in;
}

ostream &operator<<(ostream & out, const Matrix&a)
{
  for (int i = 0;i<a.n;i++)
   {
   for (int j = 0;j<a.m;j++)
      {
        out<<a.mat[i][j]<<" ";
      }
      out<<endl;
   }
   return out;
}

Matrix::Matrix(int n1, int m1)
{
   n = n1;
   m = m1;
   mat = new double *[n];
   for (int i = 0; i < n; i++)
   mat[i] = new double[m];
   
   for (int i = 0; i < n;i++)
   {
      for (int j = 0; j < m; j++)
      {
         mat[i][j] = 0;
      }
   }
}

double& Matrix:: operator()(int i, int j)
{
   if(((i+1)>n) || ((j+1)>m) || (i<0 && j<0)) throw MatrixBadindex();
   return mat[i][j];
}
double Matrix:: operator()(int i, int j) const
{
   if(((i+1)>n) ||  ((j+1)>m) || (i<0 && j<0)) throw MatrixBadindex();
   return mat[i][j];
}

Matrix::Matrix(const Matrix& A)
{
      n = A.n;
      m = A.m;
      mat= new double*[n];
      for (int i = 0; i < n; i++)
      mat[i] = new double[m];
   
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < m; j++)
         {
            mat[i][j] = A.mat[i][j];
         }
      }
}

Matrix operator + (const Matrix &A,const Matrix &B)
{
if (A.n == B.n && A.m == B.m)
{
   Matrix X(A.n, A.m);
   for (int i = 0;i<A.n;i++)
   {
   for (int j = 0;j<A.m;j++)
      {
         X.mat[i][j] = A.mat[i][j] + B.mat[i][j];
      }
   }
   return X;
}
   throw Matrixwrongsize();
}

Matrix operator - (const Matrix &A,const Matrix &B)
{
   if (A.n == B.n && A.m == B.m)
   {
   Matrix X(A.n, A.m);
   for (int i = 0;i<A.n;i++)
   {
   for (int j = 0;j<A.m;j++)
      {
         X.mat[i][j] = A.mat[i][j] - B.mat[i][j];
      }
   }
   return X;
   }
  throw Matrixwrongsize();
}

Matrix Matrix:: operator * (const Matrix &A) const
{
 if(m == A.n)
 {
   Matrix X(n, A.m);
   for (int i = 0;i<n;i++)
   {
      for (int j = 0;j<A.m;j++)
      {
       for (int k = 0;k < m;k++)
        {
           X.mat[i][j] +=mat[i][k]* A.mat[k][j];
        }
      } 
   }
   return  X;
 }
throw Matrixwrongmult();
}

Matrix& Matrix:: operator = (const Matrix &A)
{
if (n == A.n && m == A.m)
{
   n = A.n;
   m = A.m;
   for (int i = 0;i<A.n;i++)
   {
   for (int j = 0;j<A.m;j++)
      {
         mat[i][j] = A.mat[i][j];
      }
   }
   return *this;
}
throw Matrixwrongsize();
}

Matrix Matrix:: transp() const
{
   Matrix T (m,n);
   
   for(int i = 0;i<n;i++)
   {
      for (int j = 0;j<m;j++)
      {
       T.mat[j][i] = mat[i][j];
      }
   }
   return T;
}

Matrix:: ~Matrix()
{
   for (int i = 0;i < n; i++)
   delete [] mat[i];
   
   delete [] mat;
}
