#include <iostream>
#include <matrix.hpp>

using namespace std;

int main ()
{
Matrix A(3,4);// Создать нулевую матрицу 3x4
Matrix E(3,3);// Создать нулевую матрицу 3x3
try 
{
for(int i=0;i<3;++i)
E(i,i)=1;// E - теперь единичная матрица
   
E=E+E; // сложение матриц
cin>>A; // ввод матрицы 3x4
Matrix B=A.transp()*E;
cout<<B; // вывод матрицы
cout<<B(1,2)<<"\n"; // вывод элемента с индексом (1,2)
}
catch (MatrixError &e) 
{
cout<<e.what();
}

return 0;  
}