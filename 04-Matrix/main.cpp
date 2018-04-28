#include "matrix.hpp"
#include<iostream>
using namespace std;

#define PRINT(x) cout<<x<<endl
#define NEWSECTION cout<<endl<<endl

int main(int argc, char* argv[])
{
    MAT a(1,2), b(2,2), c(1,2);
    
    
    a[0][0]=1;	//�����Ƶس�ʼ�����������Ԫ��
    a[0][1]=2; 	//�ȼ���*(a.operator[](0)+1)=2;���ȼ���*(a[0]+1)=2;
    PRINT("���� a ������Ϊ��"); 
    a.print( );		//��ʼ������󣬴�ӡ���þ���
    
    
    b[0][0]=3; 	b[0][1]=4; 
    b[1][0]=5; 	b[1][1]=6;
    PRINT("���� b ������Ϊ��"); 
    b.print( );	
    
    
    PRINT("���Ծ���˷����㣬c=a*b");
    c=a*b;		
    PRINT("c ������Ϊ��");
    c.print( );
    
    PRINT("���Ծ���ӷ�����");
    PRINT("a+c ������Ϊ��");
    (a+c).print( );	
    
    
    PRINT("���Ծ���������㣬c=c-a"); 
    c=c-a;		
    PRINT("c ������Ϊ��");
    c.print( );
    
    
    PRINT("���Ծ���+=���㣬c+=a");
    c+=a;	
    PRINT("c ������Ϊ��");	
    c.print( );
    
    PRINT("���Ծ���-=���㣬c-=a");
    c-=a;	
    PRINT("c ������Ϊ��");	
    c.print( );
    
    PRINT("���Ծ���*=���㣬c*=a");
    c*=a;	
    PRINT("c ������Ϊ��");	
    c.print( );
    
    PRINT("���Ծ���*=���㣬a*=b");
    a*=b;	
    PRINT("a ������Ϊ��");	
    a.print( );
    
    
    PRINT("���Ծ���ת������");	
    PRINT("~a ������Ϊ��");	
    (~a).print( );
    PRINT("~b ������Ϊ��");
    (~b).print( );
    
    
   return 0;
}

