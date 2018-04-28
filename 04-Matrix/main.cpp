#include "matrix.hpp"
#include<iostream>
using namespace std;

#define PRINT(x) cout<<x<<endl
#define NEWSECTION cout<<endl<<endl

int main(int argc, char* argv[])
{
    MAT a(1,2), b(2,2), c(1,2);
    
    
    a[0][0]=1;	//请类似地初始化矩阵的所有元素
    a[0][1]=2; 	//等价于*(a.operator[](0)+1)=2;即等价于*(a[0]+1)=2;
    PRINT("矩阵 a 的内容为："); 
    a.print( );		//初始化矩阵后，打印出该矩阵
    
    
    b[0][0]=3; 	b[0][1]=4; 
    b[1][0]=5; 	b[1][1]=6;
    PRINT("矩阵 b 的内容为："); 
    b.print( );	
    
    
    PRINT("测试矩阵乘法运算，c=a*b");
    c=a*b;		
    PRINT("c 的内容为：");
    c.print( );
    
    PRINT("测试矩阵加法运算");
    PRINT("a+c 的内容为：");
    (a+c).print( );	
    
    
    PRINT("测试矩阵减法运算，c=c-a"); 
    c=c-a;		
    PRINT("c 的内容为：");
    c.print( );
    
    
    PRINT("测试矩阵+=运算，c+=a");
    c+=a;	
    PRINT("c 的内容为：");	
    c.print( );
    
    PRINT("测试矩阵-=运算，c-=a");
    c-=a;	
    PRINT("c 的内容为：");	
    c.print( );
    
    PRINT("测试矩阵*=运算，c*=a");
    c*=a;	
    PRINT("c 的内容为：");	
    c.print( );
    
    PRINT("测试矩阵*=运算，a*=b");
    a*=b;	
    PRINT("a 的内容为：");	
    a.print( );
    
    
    PRINT("测试矩阵转置运算");	
    PRINT("~a 的内容为：");	
    (~a).print( );
    PRINT("~b 的内容为：");
    (~b).print( );
    
    
   return 0;
}

