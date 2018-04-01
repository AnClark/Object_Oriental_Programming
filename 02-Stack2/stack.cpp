#include "stack.hpp"
#include<cstdio>
#include<malloc.h>

STACK::STACK(int m):max(m), elems(new int[m])				//初始化栈：最多m个元素
{   
    // 初始化pos值
    STACK::pos = 0;
}

STACK::STACK(const STACK &s) 	//用栈s拷贝初始化栈
{
    
    
}

int  STACK::size() const				//返回栈的最大元素个数max
{
    
}

int  STACK::howMany ( ) const		//返回栈的实际元素个数pos
{
    
}

int  STACK::getelem (int x) const	//取下标x处的栈元素
{
    
}

STACK &STACK::push(int e) 		//将e入栈,并返回栈
{
    
}

STACK &STACK::pop(int &e) 		//出栈到e,并返回栈
{
    
}

STACK &STACK::assign(const STACK &s) //赋s给栈,并返回被赋值的栈
{
    
}

void STACK::print( ) const			//打印栈
{
    
}

STACK::~STACK( )					//销毁栈
{
    
}


