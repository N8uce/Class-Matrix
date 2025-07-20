#include <iostream>
#include <matrix.hpp>

using namespace std;

int main ()
{
Matrix A(3,4);// ������� ������� ������� 3x4
Matrix E(3,3);// ������� ������� ������� 3x3
try 
{
for(int i=0;i<3;++i)
E(i,i)=1;// E - ������ ��������� �������
   
E=E+E; // �������� ������
cin>>A; // ���� ������� 3x4
Matrix B=A.transp()*E;
cout<<B; // ����� �������
cout<<B(1,2)<<"\n"; // ����� �������� � �������� (1,2)
}
catch (MatrixError &e) 
{
cout<<e.what();
}

return 0;  
}